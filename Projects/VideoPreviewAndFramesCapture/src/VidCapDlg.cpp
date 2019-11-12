// VidCapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VidCap.h"
#include "VidCapDlg.h"

#include "capture.h"
#include "samplegrab.h"


#include <stdint.h>
#include "arcsoft_fsdk_face_tracking.h"
#include "arcsoft_fsdk_face_detection.h"
#include "arcsoft_fsdk_face_recognition.h"
#include "merror.h"

#pragma comment(lib,"libarcsoft_fsdk_face_tracking.lib")
#pragma comment(lib,"libarcsoft_fsdk_face_detection.lib")
#pragma comment(lib,"libarcsoft_fsdk_face_recognition.lib")

#define WORKBUF_SIZE        (40*1024*1024)
#define APPID		"778jFQBaFNsKcXNEEC7cJKEGVrhyymea9vdeQUAHWPaQ"			//APPID
#define FTSDKKey		"F24jmL8NfHfvXX8byj58Kzu47iH6mwJ6EN1gdyRq9eMn"			//SDKKey
#define FDSDKKey		"F24jmL8NfHfvXX8byj58KzuBH7YFrCivRATnR2pcQPWV"			//SDKKey
#define FRSDKKey		"F24jmL8NfHfvXX8byj58KzufviaybguE2QLuLxNCkRnF"			//SDKKey
#define INPUT_IMAGE_PATH "sample.bmp"
//#define INPUT_IMAGE1_PATH "sample1.bmp"
//#define INPUT_IMAGE2_PATH "sample2.bmp"


AFR_FSDK_FACEMODEL gFaceModel;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif




bool readBmp24(const char* path, uint8_t **imageData, int *pWidth, int *pHeight)
{
	if (path == NULL || imageData == NULL || pWidth == NULL || pHeight == NULL)
	{
		return false;
	}
	FILE *fp = fopen(path, "rb");
	if (fp == NULL)
	{
		return false;
	}
	fseek(fp, sizeof(BITMAPFILEHEADER), 0);
	BITMAPINFOHEADER head;
	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp);
	*pWidth = head.biWidth;
	*pHeight = head.biHeight;
	int biBitCount = head.biBitCount;
	if (24 == biBitCount)
	{
		int lineByte = ((*pWidth) * biBitCount / 8 + 3) / 4 * 4;
		*imageData = (uint8_t *)malloc(lineByte * (*pHeight));
		uint8_t * data = (uint8_t *)malloc(lineByte * (*pHeight));
		fseek(fp, 54, SEEK_SET);
		fread(data, 1, lineByte * (*pHeight), fp);
		for (int i = 0; i < *pHeight; i++)
		{
			for (int j = 0; j < *pWidth; j++)
			{
				memcpy((*imageData) + i * (*pWidth) * 3 + j * 3, data + (((*pHeight) - 1) - i) * lineByte + j * 3, 3);
			}
		}
		free(data);
	}
	else
	{
		fclose(fp);
		return false;
	}
	fclose(fp);
	return true;
}


// CVidCapDlg dialog


CVidCapDlg::CVidCapDlg(CWnd* pParent /*=NULL*/)
                : CDialog(CVidCapDlg::IDD, pParent)
                , m_nTimer(0), m_nTimerInterval(1000)                                
                , m_TakeSnapshot(false)
                , pBmpEncoder(GUID_NULL)
{
        m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVidCapDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        DDX_Control(pDX, IDC_PRV_STATIC, m_PrvStatic);
        DDX_Control(pDX, IDC_ADAPTORS_COMBO, m_AdapterCombo);
        DDX_Text(pDX, IDC_SAMPLEINTERVAL_EDIT, m_nTimerInterval);
        DDV_MinMaxUInt(pDX, m_nTimerInterval, 10, 10000);
        DDX_Control(pDX, IDC_RUN_BUTTON, m_RunButton);
        DDX_Control(pDX, IDC_CAPIMG_STATIC, m_CapImgStatic);
        DDX_Control(pDX, IDC_VIDINFO_STATIC, m_VideoFormat);                        
}

BEGIN_MESSAGE_MAP(CVidCapDlg, CDialog)
        ON_MESSAGE(WM_GRAPHNOTIFY, OnGraphMessage)
        ON_WM_PAINT()
        ON_WM_QUERYDRAGICON()
        //}}AFX_MSG_MAP
        ON_BN_CLICKED(IDC_ENUMADAPTORS_BUTTON, &CVidCapDlg::OnBnClickedEnumadaptorsButton)
        ON_BN_CLICKED(IDC_RUN_BUTTON, &CVidCapDlg::OnBnClickedRunButton)
        ON_WM_TIMER()
        ON_WM_CLOSE()
        ON_WM_WINDOWPOSCHANGED()        
        ON_STN_DBLCLK(IDC_CAPIMG_STATIC, &CVidCapDlg::OnStnDblclickCapimgStatic)
END_MESSAGE_MAP()


// CVidCapDlg message handlers
LRESULT CVidCapDlg::OnGraphMessage(WPARAM wParam, LPARAM lParam)
{
        HRESULT hr = vcHandleGraphEvent();
        TRACE(L" WM_GRAPH 0x%X\n", hr);
        return 0;
}

BOOL CVidCapDlg::OnInitDialog()
{
        CDialog::OnInitDialog();

        // Set the icon for this dialog.  The framework does this automatically
        //  when the application's main window is not a dialog
        SetIcon(m_hIcon, TRUE);			// Set big icon
        SetIcon(m_hIcon, FALSE);		// Set small icon

        // TODO: Add extra initialization here

        // Initialize COM
        if (FAILED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED))) {
                MessageBox(L"CoInitialize Failed!", L"COM error");
                m_RunButton.EnableWindow(FALSE);
                return TRUE;
        }

        if (GetEncoderClsid(L"image/jpeg", &pBmpEncoder) < 0) {
                MessageBox(L"Failed to get image/jpeg encoder", L"warning");
        }


		// 2. �������(FD) ARCSOFT_FSDK_FACE_DETECTION
		{
			// ��ʼ������ͱ��� 
			MByte *pWorkMem = (MByte *)malloc(WORKBUF_SIZE);
			MRESULT nRet = MERR_UNKNOWN;
			MHandle hEngine;
			MInt32 nScale = 16;
			MInt32 nMaxFace = 10;
			nRet = AFD_FSDK_InitialFaceEngine(APPID, FDSDKKey, pWorkMem, WORKBUF_SIZE, &hEngine, AFD_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);

			// ��ȡ��̬ͼƬ��Ϣ�������浽ASVLOFFSCREEN�ṹ�� ����ASVL_PAF_RGB24_B8G8R8��ʽΪ���� 
			ASVLOFFSCREEN offInput = { 0 };
			offInput.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
			offInput.ppu8Plane[0] = nullptr;
			readBmp24(INPUT_IMAGE_PATH, (uint8_t**)&offInput.ppu8Plane[0], &offInput.i32Width, &offInput.i32Height);
			offInput.pi32Pitch[0] = offInput.i32Width * 3;
			// �������
			LPAFD_FSDK_FACERES	FaceRes = nullptr;
			nRet = AFD_FSDK_StillImageFaceDetection(hEngine, &offInput, &FaceRes);
			// ��ȡͼƬ�м�⵽�ĵ�һ������
			//for (int i = 0; i < FaceRes->nFace; ++i)
			if (FaceRes && FaceRes->nFace > 0)
			{
				// 3. ����ʶ��(FR) ARCSOFT_FSDK_FACE_RECOGNITION
				{
					// ����ʶ������ ��ʼ������ͱ���
					MByte *pFRWorkMem = (MByte *)malloc(WORKBUF_SIZE);
					MRESULT nRet = MERR_UNKNOWN;
					MHandle hFREngine;
					MInt32 nScale = 16;
					MInt32 nMaxFace = 10;
					nRet = AFR_FSDK_InitialEngine(APPID, FRSDKKey, pFRWorkMem, WORKBUF_SIZE, &hFREngine);

					// ��������Ϣͨ��face detection\face tracking���
					AFR_FSDK_FACEINPUT faceInput = {0};
					faceInput.rcFace = FaceRes->rcFace[0];
					faceInput.lOrient = FaceRes->lfaceOrient[0];

					//��ȡ��һ����������
					AFR_FSDK_FACEMODEL LocalFaceModels = { 0 };
					nRet = AFR_FSDK_ExtractFRFeature(hFREngine, &offInput, &faceInput, &LocalFaceModels);

					// ���������������
					// �洢��ȫ�ֱ����� �漰��̬�����ڴ�
					gFaceModel.lFeatureSize = LocalFaceModels.lFeatureSize;
					gFaceModel.pbFeature = (MByte*)malloc(gFaceModel.lFeatureSize);
					memcpy(gFaceModel.pbFeature, LocalFaceModels.pbFeature, gFaceModel.lFeatureSize);

					// �ͷ����� 
					AFR_FSDK_UninitialEngine(hFREngine);
					free(pFRWorkMem);
				}
			}
			// �ͷ�������ڴ�
			nRet = AFD_FSDK_UninitialFaceEngine(hEngine);
			free(offInput.ppu8Plane[0]);
			free(pWorkMem);
		}

        return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVidCapDlg::OnClose()
{
	// �ͷŶ�̬�����ڴ�
	free(gFaceModel.pbFeature);

        // TODO: Add your message handler code here and/or call default
        KillTimer(m_nTimer);
        vcStopCaptureVideo();
        CoUninitialize();        

        CDialog::OnClose();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVidCapDlg::OnPaint()
{
        if (IsIconic()) {
                CPaintDC dc(this); // device context for painting

                SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

                // Center icon in client rectangle
                int cxIcon = GetSystemMetrics(SM_CXICON);
                int cyIcon = GetSystemMetrics(SM_CYICON);
                CRect rect;
                GetClientRect(&rect);
                int x = (rect.Width() - cxIcon + 1) / 2;
                int y = (rect.Height() - cyIcon + 1) / 2;

                // Draw the icon
                dc.DrawIcon(x, y, m_hIcon);
        } else {
                CDialog::OnPaint();
        }
}


int CVidCapDlg::GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
        UINT  num = 0;          // number of image encoders
        UINT  size = 0;         // size of the image encoder array in bytes

        Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;

        Gdiplus::GetImageEncodersSize(&num, &size);
        if (size == 0)
                return -1;  // Failure

        pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
        if (pImageCodecInfo == NULL)
                return -1;  // Failure

        Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);

        for (UINT j = 0; j < num; ++j) {
                if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
                        *pClsid = pImageCodecInfo[j].Clsid;
                        free(pImageCodecInfo);
                        return j;  // Success
                }
        }

        free(pImageCodecInfo);
        return -1;  // Failure
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVidCapDlg::OnQueryDragIcon()
{
        return static_cast<HCURSOR>(m_hIcon);
}


void CVidCapDlg::OnBnClickedEnumadaptorsButton()
{
        //Enum adaptors
        vcGetCaptureDevices(m_AdapterCombo);
}

void CVidCapDlg::OnBnClickedRunButton()
{
        UpdateData();

        HRESULT hr;
        if (m_nTimer == 0) {
                //Run capture
                hr = vcCaptureVideo(m_hWnd, m_PrvStatic.m_hWnd, m_AdapterCombo.GetCurSel() + 1);
                if (hr != S_OK) {
                        vcStopCaptureVideo();
                        return;
                }
                
                CString str;
                str.Format(L"Video output: %dx%d %dbpp", sgGetDataWidth(), sgGetDataHeight(), 8 * sgGetDataChannels()); 
                m_VideoFormat.SetWindowTextW(str);

                //Setup Timer
                m_nTimer = SetTimer(1, m_nTimerInterval, 0);                                        

                m_RunButton.SetWindowTextW(L"Stop");
        } else {
                //Close Timer
                KillTimer(m_nTimer);
                m_nTimer = 0;
                m_RunButton.SetWindowTextW(L"Run");

                m_VideoFormat.SetWindowTextW(L"Video output");
                //Close Capture
                vcStopCaptureVideo();
        }
}

void CVidCapDlg::OnTimer(UINT_PTR nIDEvent)
{
        // TODO: Add your message handler code here and/or call default
        SYSTEMTIME SystemTime;
        GetLocalTime(&SystemTime);
        TRACE(L" %d:%d:%d\n", SystemTime.wHour, SystemTime.wMinute, SystemTime.wSecond);

		unsigned char* pData = sgGrabData();
		if (pData != 0) 
		{
			DrawData(sgGetBitmap());

			// 1. ARCSOFT_FSDK_FACE_TRACKING
			// ��ʼ������ͱ���/
			MByte *pWorkMem = (MByte *)malloc(WORKBUF_SIZE);
			MHandle hEngine = nullptr;
			MInt32 nScale = 16;
			MInt32 nMaxFace = 10;
			MRESULT nRet = AFT_FSDK_InitialFaceEngine(APPID, FTSDKKey, pWorkMem, WORKBUF_SIZE, &hEngine, AFT_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);
			// ��ȡ��Ƶ֡���ݣ������浽ASVLOFFSCREEN�ṹ��/
			// ֱ�ӽ�֡ͼ�����ݣ�λͼ���ݣ��������˷�ת����ģ�ֱ����Ϊ ASVLOFFSCREEN �е�ͼ�����ݡ�
			ASVLOFFSCREEN offInput = { 0 };
			long size = sgGetBufferSize(); 
			unsigned char *pTempBuffer = new unsigned char[size];
			memcpy(pTempBuffer, pData, size);
			offInput.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
			offInput.i32Width = sgGetDataWidth();
			offInput.i32Height = sgGetDataHeight();
			offInput.ppu8Plane[0] = (uint8_t *)pTempBuffer;
			offInput.pi32Pitch[0] = offInput.i32Width * 3;
			// ��������
			LPAFT_FSDK_FACERES	FaceRes = nullptr;
			nRet = AFT_FSDK_FaceFeatureDetect(hEngine, &offInput, &FaceRes);
			// ��ȡ��⵽�ĵ�һ������
			//for (int i = 0; i < FaceRes->nFace; ++i)
			if (FaceRes->nFace > 0)
			{
				// �������ű��������������������
				CRect rc;
				m_CapImgStatic.GetClientRect(rc);
				float xScale = (float)rc.Width() / (float)sgGetDataWidth();
				float yScale = (float)rc.Height() / (float)sgGetDataHeight();
				int left = (int)FaceRes->rcFace[0].left * xScale;
				int right = (int)FaceRes->rcFace[0].right * xScale;
				int top = (int)FaceRes->rcFace[0].top * yScale;
				int bottom = (int)FaceRes->rcFace[0].bottom * yScale;

				// ���ݼ�������Ž��������������
				CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
				CClientDC dc(&m_CapImgStatic);
				dc.SelectObject(pen);
				dc.SelectStockObject(NULL_BRUSH);
				dc.Rectangle(left, top, right, bottom);

				// 3. ����ʶ��(FR) ARCSOFT_FSDK_FACE_RECOGNITION
				{
					// ����ʶ������ ��ʼ������ͱ���
					MByte *pFRWorkMem = (MByte *)malloc(WORKBUF_SIZE);
					MRESULT nRet = MERR_UNKNOWN;
					MHandle hFREngine;
					MInt32 nScale = 16;
					MInt32 nMaxFace = 10;
					nRet = AFR_FSDK_InitialEngine(APPID, FRSDKKey, pFRWorkMem, WORKBUF_SIZE, &hFREngine);

					// ��������Ϣͨ��face detection\face tracking���
					AFR_FSDK_FACEINPUT faceInput = {0};
					faceInput.rcFace = FaceRes->rcFace[0];
					faceInput.lOrient = FaceRes->lfaceOrient;
					//��ȡ�ڶ�����������
					AFR_FSDK_FACEMODEL LocalFaceModels = { 0 };
					nRet = AFR_FSDK_ExtractFRFeature(hFREngine, &offInput, &faceInput, &LocalFaceModels);
					// �Ա�����������������ñȶԽ�� 
					MFloat  fSimilScore = 0.0f;
					nRet = AFR_FSDK_FacePairMatching(hFREngine, &gFaceModel, &LocalFaceModels, &fSimilScore);

					// �ͷ����� 
					AFR_FSDK_UninitialEngine(hFREngine);
					free(pFRWorkMem);

					// ������ʾ�ȶԽ��
					CString strInfor;
					strInfor.Format(L"ƥ���[%.3f]", fSimilScore);
					dc.DrawText(strInfor, &CRect(left, top, right, bottom), DT_TOP | DT_CENTER | DT_NOCLIP);
				}
			}
			// �ͷ�������ڴ�
			nRet = AFT_FSDK_UninitialFaceEngine(hEngine);
			free(offInput.ppu8Plane[0]);
			free(pWorkMem);
		}

        CDialog::OnTimer(nIDEvent);
}


void CVidCapDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
        CDialog::OnWindowPosChanged(lpwndpos);

        // TODO: Add your message handler code here
        vcChangePreviewState(!IsIconic());
}

void CVidCapDlg::DrawData(Gdiplus::Bitmap *pBitmap)
{                
        if (pBitmap == 0)
                return;        

        if (m_TakeSnapshot == true) {
                m_TakeSnapshot = false;
                sndPlaySound(L"snap.wav", SND_ASYNC);
                if (pBmpEncoder != GUID_NULL) {
                        wchar_t FileName[_MAX_PATH] = L"";
                        for (unsigned int i = 1; i < 0xFFFFFFFF; i++) {
                                swprintf_s(FileName, _MAX_PATH, L"Snapshot %04d.jpg", i);
                                FILE* fp = _wfopen(FileName, L"rb");
                                if (fp == 0) {
                                        pBitmap->Save(FileName, &pBmpEncoder);
                                        break;
                                }
                                else
                                        fclose(fp);

                        }                        
                }
        }

        RECT r;
        m_CapImgStatic.GetClientRect(&r);
        Gdiplus::Graphics g(m_CapImgStatic.GetDC()->m_hDC);

        g.DrawImage(pBitmap, Gdiplus::Rect(0, 0, r.right, r.bottom));
        
        UpdateData(FALSE);
}

void CVidCapDlg::OnStnDblclickCapimgStatic()
{
        m_TakeSnapshot = true;

		// 2. �������(FD) ARCSOFT_FSDK_FACE_DETECTION
		//// ����ͼ����ʾ����˫����Ӧ����ʾͼƬ���������
		//{
		//	Gdiplus::Bitmap simpleBitmap(TEXT(INPUT_IMAGE_PATH));
		//	DrawData(&simpleBitmap);

		//	// 2. ARCSOFT_FSDK_FACE_DETECTION
		//	// ��ʼ������ͱ��� 
		//	MRESULT nRet = MERR_UNKNOWN;
		//	MByte *pWorkMem = (MByte *)malloc(WORKBUF_SIZE);
		//	MHandle hEngine = nullptr;
		//	MInt32 nScale = 16;
		//	MInt32 nMaxFace = 10;
		//	nRet = AFD_FSDK_InitialFaceEngine(APPID, SDKKey, pWorkMem, WORKBUF_SIZE, &hEngine, AFD_FSDK_OPF_0_HIGHER_EXT, nScale, nMaxFace);

		//	// ��ȡ��̬ͼƬ��Ϣ�������浽ASVLOFFSCREEN�ṹ�� ����ASVL_PAF_RGB24_B8G8R8��ʽΪ���� 
		//	ASVLOFFSCREEN offInput = { 0 };
		//	offInput.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
		//	offInput.ppu8Plane[0] = nullptr;
		//	readBmp24(INPUT_IMAGE_PATH, (uint8_t**)&offInput.ppu8Plane[0], &offInput.i32Width, &offInput.i32Height);
		//	offInput.pi32Pitch[0] = offInput.i32Width * 3;
		//	// �������
		//	LPAFD_FSDK_FACERES	FaceRes = nullptr;
		//	nRet = AFD_FSDK_StillImageFaceDetection(hEngine, &offInput, &FaceRes);
		//	for (int i = 0; i < FaceRes->nFace; ++i)
		//	{
		//		// �������ű��������������������
		//		CRect rc;
		//		m_CapImgStatic.GetClientRect(rc);
		//		// ȡλͼʵ�ʸߡ���
		//		float xScale = (float)rc.Width() / (float)simpleBitmap.GetWidth();
		//		float yScale = (float)rc.Height() / (float)simpleBitmap.GetHeight();
		//		int left = (int)FaceRes->rcFace[i].left * xScale;
		//		int right = (int)FaceRes->rcFace[i].right * xScale;
		//		int top = (int)FaceRes->rcFace[i].top * yScale;
		//		int bottom = (int)FaceRes->rcFace[i].bottom * yScale;

		//		// ���ݼ�������Ž��������������
		//		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
		//		CClientDC dc(&m_CapImgStatic);
		//		dc.SelectObject(pen);
		//		dc.SelectStockObject(NULL_BRUSH);
		//		dc.Rectangle(left, top, right, bottom);
		//	}
		//	// �ͷ�������ڴ�
		//	nRet = AFD_FSDK_UninitialFaceEngine(hEngine);
		//	free(offInput.ppu8Plane[0]);
		//	free(pWorkMem);
		//}
}

