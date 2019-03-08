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

// 预览摄像头视频
void CameraVedioToPreview()
{
	// 1.
	// 创建 IGraphBuilder 及 ICaptureGraphBuilder2，并通过函数 SetFiltergraph 使用 IGraphBuilder 来初始化 ICaptureGraphBuilder2 。
	// 等同于 ICaptureGraphBuilder2 绑定到 IGraphBuilder ， IGraphBuilder 上的任何操作都影响 ICaptureGraphBuilder2 。
	IGraphBuilder *pGraphBuilder = NULL;
	ICaptureGraphBuilder2 *pCaptureGraphBuilder = NULL;
	InitCaptureGraphBuilder(&pGraphBuilder, &pCaptureGraphBuilder);

	// 2.
	// 选择摄像头设备
	// 返回代表设备 filter
	IBaseFilter *pCap = SelectDefaultCaptureDevice(pGraphBuilder);

	// 3.
	// 指定将摄像头(设备 filter)视频流输出到 默认的预览窗口
	RenderStreamToPreview(pCaptureGraphBuilder, pCap);

	// 4.
	// 控制整个 Graph 开始运行
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
// 预览摄像头视频并捕获帧图片
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
	// 创建 Sample Grabber filter 
	IBaseFilter *pGrabberFilter = NULL;
	// Create the Sample Grabber.
	hr = CoCreateInstance(CLSID_SampleGrabber, NULL, CLSCTX_INPROC_SERVER
		, IID_IBaseFilter, (void**) & pGrabberFilter);
	hr = pGraphBuilder->AddFilter(pGrabberFilter, L"Sample Grabber");

	// +++
	// 设置 Sample Grabber filter 捕获流数据的类型和方式
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
	// 中间加入 Sample Grabber filter
	hr = pCaptureGraphBuilder->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video, pCaptureFilter, pGrabberFilter, NULL);

	// 4.
	IMediaControl * pMediaControl = NULL;
	hr = pGraphBuilder->QueryInterface(IID_IMediaControl, (LPVOID *) &pMediaControl);
	hr = pMediaControl->Run();

	// +++
	// 开始以某种方式进行帧捕获
	for (;;)
	{
		::Sleep(1000*3);

		// 缓冲模式 提取缓冲区中的当前帧。 是位图数据块 (bits block)
		long cbBuffer;
		hr = pSampleGrabber->GetCurrentBuffer(&cbBuffer, NULL);
		BYTE* pBuffer = (BYTE*)CoTaskMemAlloc(cbBuffer);
		hr = pSampleGrabber->GetCurrentBuffer(&cbBuffer, (long*)pBuffer);

		// 解析当前帧图像信息。 包含位图数据块的结构信息 BITMAPINFOHEADER 。
		hr = pSampleGrabber->GetConnectedMediaType(&mt);
		if ((mt.formattype == FORMAT_VideoInfo) && 
			(mt.cbFormat >= sizeof(VIDEOINFOHEADER)) &&
			(mt.pbFormat != NULL)) 
		{
			HANDLE hFile = CreateFile(L"D:\\temp\\x.bmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
			// 构建 位图文件头 结构 BITMAPFILEHEADER
			BITMAPFILEHEADER bmf = { };
			bmf.bfType = (WORD) (('M' << 8) | 'B');
			bmf.bfSize = sizeof(bmf)+(mt.cbFormat - SIZE_PREHEADER)+ cbBuffer; 
			bmf.bfOffBits = sizeof(bmf) + (mt.cbFormat - SIZE_PREHEADER); 
			DWORD cbWritten = 0;
			// 保存 BITMAPFILEHEADER
			BOOL result = WriteFile(hFile, &bmf, sizeof(bmf), &cbWritten, NULL);
			// 保存 BITMAPINFOHEADER
			result = WriteFile(hFile, &( ((VIDEOINFOHEADER*)(mt.pbFormat))->bmiHeader ), (mt.cbFormat - SIZE_PREHEADER), &cbWritten, NULL);
			// 保存 bits block
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