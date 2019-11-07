#include "stdafx.h"
#include "util.h"




// ʹ�����е�CImage�����ڴ��н���ת��������Ҫ����Ϊ�ļ���Ҳ����Ҫ����������⣨ Libjpeg�� ����
// char* pUnZipData,    �ڴ���ͼƬ���������ݡ�
// unsigned long ulUnZipDataLen,    ���ݳ��ȡ�
// CImage* pImage    ���ڼ���ͼƬ���ݵ� CImage ����
void JPEG2BMP_Memory_CImage(char* pUnZipData, unsigned long ulUnZipDataLen, CImage* pImage)
{
	// ���� GlobalAlloc �� CreateStreamOnHGlobal ���� IStream����
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, ulUnZipDataLen);  
	// ����ͼƬ���ݵ��ڴ��У���ɲ�������Ҫ��ʱ�ͷ��� GlobalUnlock
	void* pData = GlobalLock(hGlobal);  
	memcpy(pData, pUnZipData, ulUnZipDataLen);  
	// ��ʱ�ͷ��������û���ͷţ����� CImage::Load ������ʧ�ܡ�
	GlobalUnlock(hGlobal);  

	// ʹ��CImage���ڴ��ж�ȡJpeg��ʽ��ͼƬ���ݣ�ֻ��Ҫ����һ��IStream�ӿڵ�����IStream����ʹ��CreateStreamOnHGlobal���д�����
	IStream* pStream = NULL;  
	if(CreateStreamOnHGlobal(hGlobal, TRUE,  & pStream) == S_OK)  
	{
		CImage image;  
		if (SUCCEEDED(pImage->Load(pStream)))  
		{

		}   
		pStream -> Release();       
	}   
	GlobalFree(hGlobal);  
}


// ��ͼƬ�ļ����Ϊ��һ���ļ����߸�ʽ��
// const char* inputFileName,    ָ��������ͼƬ�ļ�����
// const char* saveFileName,    ͼƬ�ļ����Ϊ��ͼƬ�ļ�����
void JPEG2BMP_File_CImage(const wchar_t *inputFileName, const wchar_t *saveFileName)
{
	CImage image;
	HRESULT result = S_FALSE;
	result = image.Load(inputFileName);
	result = image.Save(saveFileName);
}


//#include <Objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

#pragma comment(lib,"gdiplus")

// ��ȡָ����ͼ���ʽ��������CLSID
// ���أ�-1��ʧ�ܣ� >=0���ɹ�
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders  
	UINT  size = 0;         // size of the image encoder array in bytes  

	ImageCodecInfo* pImageCodecInfo = NULL;

	// ��ȡGDI+֧�ֵ�ͼ���ʽ�������������Լ�ImageCodecInfo����Ĵ�Ŵ�С  
	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure  

	// ��ȡ���е�ͼ���������Ϣ  
	GetImageEncoders(num, size, pImageCodecInfo);

	// ���ҷ��ϵ�ͼ���������Clsid
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success  
		}
	}

	// �ͷŲ���3������ڴ�  
	free(pImageCodecInfo);
	return -1;  // Failure  
}

// ���ڴ��е�JPEG����������ת��ΪBMPλͼ���ݣ��洢��ָ���Ļ������С�
// const char *p, [in]    JPEG�Ķ��������ݡ�
// int nBytes, [in]    ���������ݵĳ��ȡ�
// std::string& OutBmpImg, [out]    ת�����BMPλͼ���ݡ�
void JPEG2BMP_Memory_Image(const char *p, int nBytes, std::string& OutBmpImg)
{
	// ʹ�� Image �漰�� GDI+ ����Ҫ���ȳ�ʼ������
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	gdiplusToken = 0;
	// initializes Microsoft Windows GDI+. 
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	/////////////////////////////////////////////////////////////////////
	// һ�����ݶ��������ݴ��� Image ����������Щ���������ݣ���
	// 1.����һ���ڴ���
	SIZE_T dwBytes = nBytes; 
	// GHND : Combines GMEM_MOVEABLE and GMEM_ZEROINIT.
	HGLOBAL  hImage = ::GlobalAlloc(GHND, dwBytes);
	if (!hImage)
	{
		return;
	}
	// 2.�����������ݸ��Ƶ����ڴ���
	char *pImage = (char *)GlobalLock(hImage);
	if (!pImage)
	{
		::GlobalFree(hImage);
		return;
	}
	memcpy(pImage, p, dwBytes);
	// GlobalUnlock ���ڴ棬ʹ������Ҫ��ʱ�ͷ�����
	// �˴�û���ͷŵ��º��� Image* image = ::new Image(pImageStream); Ϊ NULL ���ɹ���
	::GlobalUnlock(hImage);
	pImage = NULL;

	// 3.���ڸ��ڴ�������һ�����ӿ�
	IStream* pImageStream = NULL;
	if (::CreateStreamOnHGlobal(hImage, FALSE, &pImageStream) != S_OK)
	{
		::GlobalFree(hImage);
		return;
	}

	// 4.�������ӿڴ���Image
	Image* image = ::new Image(pImageStream);
	if (image == NULL || image->GetLastStatus() != 0)
	{
		pImageStream->Release();
		::GlobalFree(hImage);
		return;
	}

	/////////////////////////////////////////////////////////////////////
	// ����ʹ�� Iamge �Ķ��������ݣ�������ʽ��ת��ΪBMP��λͼ���ݣ����������������
	// 1.����һ������ڴ��� ��δ֪��������ж��
	HGLOBAL  hOutImage = ::GlobalAlloc(GHND, 0);
	if (!hOutImage)
	{
		pImageStream->Release();
		::GlobalFree(hImage);
		delete image;
		return;
	}

	// 2.��������ڴ�������һ��������ӿ� ���������ڴ�����
	IStream* pOutImageStream = NULL;
	if (::CreateStreamOnHGlobal(hOutImage, FALSE, &pOutImageStream) != S_OK)
	{
		pImageStream->Release();
		::GlobalFree(hImage);
		delete image;
		::GlobalFree(hOutImage);
		return;
	}

	// 3.���벢���ͼƬ���ݵ������ ��������ڴ�����
	// Get the CLSID of the PNG encoder.  
	CLSID   encoderClsid;
	if (GetEncoderClsid(L"image/bmp", &encoderClsid) == -1)
	{
		pImageStream->Release();
		::GlobalFree(hImage);
		delete image;
		pOutImageStream->Release();
		::GlobalFree(hOutImage);
		return;
	}
	image->Save(pOutImageStream, &encoderClsid);

	// 4.��ͼƬ���ݴ�����ڴ������Ƴ���
	int size = ::GlobalSize(hOutImage);
	OutBmpImg.resize(size);
	char *srcBuffer = (char *)::GlobalLock(hOutImage);
	if (srcBuffer)
	{
		memcpy((void*)OutBmpImg.c_str(), srcBuffer, size);
	}
	::GlobalUnlock(hOutImage);

	// 5.�������ͷ���Դ
	::GlobalFree(hImage);
	::GlobalFree(hOutImage);
	
	pImageStream->Release();
	pOutImageStream->Release();
	//delete image; // delete image ���쳣������
	

	// cleans up resources used by Microsoft Windows GDI+
	if (gdiplusToken != NULL)
	{
		GdiplusShutdown(gdiplusToken);
	}
}
