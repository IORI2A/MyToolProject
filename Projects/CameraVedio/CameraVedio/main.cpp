#include <DShow.h>


//// ����ͷ��ƵԤ��
//extern
//void CameraVedioToPreview();
//
//void main()
//{
//	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
//	if (SUCCEEDED(hr))
//	{
//		// ������ʾ��ƵԤ���ɹ���
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


//// ������Ƶ�ļ���֡ͼ��
//extern
//HRESULT GrabVideoBitmap(PCWSTR pszVideoFile, PCWSTR pszBitmapFile);
//
//void main()
//{
//	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
//	if (SUCCEEDED(hr))
//	{
//		// ���Բ����ͼƬ��ȫ��ɫ�ġ���֪��ȷ���
//		GrabVideoBitmap(L"C:\\Users\\EDZ\\Videos\\Wildlife.wmv", L"D:\\temp\\x.bmp");
//
//		CoUninitialize();
//	}
//}


// Ԥ����Ƶ������֡ͼƬ
extern
void PreviewCameraVedioAndCaptureFrame();

void main()
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	if (SUCCEEDED(hr))
	{
		// ����Ԥ����Ƶ������֡ͼƬ������OK
		PreviewCameraVedioAndCaptureFrame();

		for (;;)
		{
			::Sleep(1000*3);
		}

		CoUninitialize();
	}
}