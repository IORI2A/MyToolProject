#include <DShow.h>


extern 
HRESULT InitCaptureGraphBuilder(
	IGraphBuilder **ppGraph,  // Receives the pointer.
	ICaptureGraphBuilder2 **ppBuild  // Receives the pointer.
	);

extern
void RenderStreamToPreview(ICaptureGraphBuilder2 *pBuild, IBaseFilter *pCap);

extern
IBaseFilter * SelectDefaultCaptureDevice(IGraphBuilder *m_pGraph);

// Ԥ������ͷ��Ƶ
void CameraVedioToPreview()
{
	// 1.
	// ���� IGraphBuilder �� ICaptureGraphBuilder2����ͨ������ SetFiltergraph ʹ�� IGraphBuilder ����ʼ�� ICaptureGraphBuilder2 ��
	// ��ͬ�� ICaptureGraphBuilder2 �󶨵� IGraphBuilder �� IGraphBuilder �ϵ��κβ�����Ӱ�� ICaptureGraphBuilder2 ��
	IGraphBuilder *pGraphBuilder = NULL;
	ICaptureGraphBuilder2 *pCaptureGraphBuilder = NULL;
	InitCaptureGraphBuilder(&pGraphBuilder, &pCaptureGraphBuilder);

	// 2.
	// ѡ������ͷ�豸
	// ���ش����豸 filter
	IBaseFilter *pCap = SelectDefaultCaptureDevice(pGraphBuilder);

	// 3.
	// ָ��������ͷ(�豸 filter)��Ƶ������� Ĭ�ϵ�Ԥ������
	RenderStreamToPreview(pCaptureGraphBuilder, pCap);

	// 4.
	// �������� Graph ��ʼ����
	// Obtain interfaces for media control
	IMediaControl * g_pMC = NULL;
	HRESULT hr = pGraphBuilder->QueryInterface(IID_IMediaControl, (LPVOID *) & g_pMC);
	if (FAILED(hr))
	{
		//...
	}

	// Start previewing video data
	hr = g_pMC->Run();
	if (FAILED(hr))
	{
		//...
	}
}



#include "qedit.h"
// Ԥ������ͷ��Ƶ������֡ͼƬ
void PreviewCameraVedioAndCaptureFrame()
{
	// 1.
	ICaptureGraphBuilder2 *pCaptureGraphBuilder = NULL;
	// Create the Capture Graph Builder.
	HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, CLSCTX_INPROC_SERVER
		, IID_ICaptureGraphBuilder2, (void**)&pCaptureGraphBuilder );
	IGraphBuilder *pGraphBuilder = NULL;
	// Create the Filter Graph Manager.
	hr = CoCreateInstance(CLSID_FilterGraph, 0, CLSCTX_INPROC_SERVER
		, IID_IGraphBuilder, (void**)&pGraphBuilder);
	// Initialize the Capture Graph Builder.
	pCaptureGraphBuilder->SetFiltergraph(pGraphBuilder);

	// 2.
	ICreateDevEnum *pDevEnum = NULL;
	// Create the System Device Enumerator.
	hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL, CLSCTX_INPROC_SERVER
		, IID_ICreateDevEnum, reinterpret_cast<void**>(&pDevEnum));
	IEnumMoniker *pEnum = NULL;
	// Create an enumerator for the video capture category.
	hr = pDevEnum->CreateClassEnumerator(CLSID_VideoInputDeviceCategory, &pEnum, 0);
	IMoniker *pMoniker = NULL;
	hr = pEnum->Next(1, &pMoniker, NULL);
	IBaseFilter *pCaptureFilter = NULL;
	hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pCaptureFilter);
	hr = pGraphBuilder->AddFilter(pCaptureFilter, L"Capture Filter");

	// ++++
	// ���� Sample Grabber filter 
	IBaseFilter *pGrabberFilter = NULL;
	// Create the Sample Grabber.
	hr = CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER
		, IID_IBaseFilter, (void**) & pGrabberFilter);
	hr = pGraphBuilder->AddFilter(pGrabberFilter, L"Sample Grabber");

	// +++
	// ���� Sample Grabber filter ���������ݵ����ͺͷ�ʽ
	ISampleGrabber *pSampleGrabber = NULL;
	pGrabberFilter->QueryInterface(IID_ISampleGrabber, (void**)&pSampleGrabber);
	AM_MEDIA_TYPE mt;
	ZeroMemory(&mt, sizeof(AM_MEDIA_TYPE));
	mt.majortype = MEDIATYPE_Video;
	mt.subtype = MEDIASUBTYPE_RGB24;
	hr = pSampleGrabber->SetMediaType(&mt);
	hr = pSampleGrabber->SetOneShot(FALSE);
	hr = pSampleGrabber->SetBufferSamples(TRUE);

	// 3.
	// �м���� Sample Grabber filter
	hr = pCaptureGraphBuilder->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video, pCaptureFilter, pGrabberFilter, NULL);

	// 4.
	IMediaControl * pMediaControl = NULL;
	hr = pGraphBuilder->QueryInterface(IID_IMediaControl, (LPVOID *) &pMediaControl);
	hr = pMediaControl->Run();

	// +++
	// ��ʼ��ĳ�ַ�ʽ����֡����
	for (;;)
	{
		::Sleep(1000*3);

		// ����ģʽ ��ȡ�������еĵ�ǰ֡�� ��λͼ���ݿ� (bits block)
		long cbBuffer;
		hr = pSampleGrabber->GetCurrentBuffer(&cbBuffer, NULL);
		BYTE* pBuffer = (BYTE*)CoTaskMemAlloc(cbBuffer);
		hr = pSampleGrabber->GetCurrentBuffer(&cbBuffer, (long*)pBuffer);

		// ������ǰ֡ͼ����Ϣ�� ����λͼ���ݿ�Ľṹ��Ϣ BITMAPINFOHEADER ��
		hr = pSampleGrabber->GetConnectedMediaType(&mt);
		if ((mt.formattype == FORMAT_VideoInfo) && 
			(mt.cbFormat >= sizeof(VIDEOINFOHEADER)) &&
			(mt.pbFormat != NULL)) 
		{
			HANDLE hFile = CreateFile(L"D:\\temp\\x.bmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
			// ���� λͼ�ļ�ͷ �ṹ BITMAPFILEHEADER
			BITMAPFILEHEADER bmf = { };
			bmf.bfType = (WORD) (('M' << 8) | 'B');
			bmf.bfSize = sizeof(bmf)+(mt.cbFormat - SIZE_PREHEADER)+ cbBuffer; 
			bmf.bfOffBits = sizeof(bmf) + (mt.cbFormat - SIZE_PREHEADER); 
			DWORD cbWritten = 0;
			// ���� BITMAPFILEHEADER
			BOOL result = WriteFile(hFile, &bmf, sizeof(bmf), &cbWritten, NULL);
			// ���� BITMAPINFOHEADER
			result = WriteFile(hFile, &( ((VIDEOINFOHEADER*)(mt.pbFormat))->bmiHeader ), (mt.cbFormat - SIZE_PREHEADER), &cbWritten, NULL);
			// ���� bits block
			result = WriteFile(hFile, pBuffer, cbBuffer, &cbWritten, NULL);
			CloseHandle(hFile);
		}

		if (mt.cbFormat != 0)
		{
			CoTaskMemFree((PVOID)mt.pbFormat);
			mt.cbFormat = 0;
			mt.pbFormat = NULL;
		}
		if (mt.pUnk != NULL)
		{
			mt.pUnk->Release();
			mt.pUnk = NULL;
		}
		CoTaskMemFree(pBuffer);
	}
}