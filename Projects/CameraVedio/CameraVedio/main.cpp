#include <DShow.h>


//// 摄像头视频预览
//extern
//void CameraVedioToPreview();
//
//void main()
//{
//	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
//	if (SUCCEEDED(hr))
//	{
//		// 测试显示视频预览成功。
//		CameraVedioToPreview();
//
//		for (;;)
//		{
//			::Sleep(1000*3);
//		}
//
//		CoUninitialize();
//	}
//}


//// 捕获视频文件的帧图像
//extern
//HRESULT GrabVideoBitmap(PCWSTR pszVideoFile, PCWSTR pszBitmapFile);
//
//void main()
//{
//	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
//	if (SUCCEEDED(hr))
//	{
//		// 测试捕获的图片是全黑色的。不知正确与否。
//		GrabVideoBitmap(L"C:\\Users\\EDZ\\Videos\\Wildlife.wmv", L"D:\\temp\\x.bmp");
//
//		CoUninitialize();
//	}
//}


// 预览视频并捕获帧图片
extern
void PreviewCameraVedioAndCaptureFrame();

void main()
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (SUCCEEDED(hr))
	{
		// 测试预览视频并捕获帧图片。测试OK
		PreviewCameraVedioAndCaptureFrame();

		for (;;)
		{
			::Sleep(1000*3);
		}

		CoUninitialize();
	}
}