#include "stdafx.h"
#include "util.h"




// 使用现有的CImage类在内存中进行转换，不需要保存为文件，也不需要引入第三方库（ Libjpeg库 ）。
// char* pUnZipData,    内存中图片二进制数据。
// unsigned long ulUnZipDataLen,    数据长度。
// CImage* pImage    用于加载图片数据的 CImage 对象。
void JPEG2BMP_Memory_CImage(char* pUnZipData, unsigned long ulUnZipDataLen, CImage* pImage)
{
	// 基于 GlobalAlloc 和 CreateStreamOnHGlobal 创建 IStream对象
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, ulUnZipDataLen);  
	// 复制图片数据到内存中，完成操作后需要及时释放锁 GlobalUnlock
	void* pData = GlobalLock(hGlobal);  
	memcpy(pData, pUnZipData, ulUnZipDataLen);  
	// 及时释放锁。如果没有释放，后续 CImage::Load 创建将失败。
	GlobalUnlock(hGlobal);  

	// 使用CImage从内存中读取Jpeg格式的图片数据，只需要传入一个IStream接口的流，IStream对象使用CreateStreamOnHGlobal进行创建。
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


// 将图片文件另存为另一个文件或者格式。
// const char* inputFileName,    指定的输入图片文件名。
// const char* saveFileName,    图片文件另存为的图片文件名。
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

// 获取指定的图像格式编码器的CLSID
// 返回：-1，失败； >=0，成功
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders  
	UINT  size = 0;         // size of the image encoder array in bytes  

	ImageCodecInfo* pImageCodecInfo = NULL;

	// 获取GDI+支持的图像格式编码器种类数以及ImageCodecInfo数组的存放大小  
	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure  

	// 获取所有的图像编码器信息  
	GetImageEncoders(num, size, pImageCodecInfo);

	// 查找符合的图像编码器的Clsid
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success  
		}
	}

	// 释放步骤3分配的内存  
	free(pImageCodecInfo);
	return -1;  // Failure  
}

// 将内存中的JPEG二进制数据转换为BMP位图数据，存储于指定的缓冲区中。
// const char *p, [in]    JPEG的二进制数据。
// int nBytes, [in]    二进制数据的长度。
// std::string& OutBmpImg, [out]    转换后的BMP位图数据。
void JPEG2BMP_Memory_Image(const char *p, int nBytes, std::string& OutBmpImg)
{
	// 使用 Image 涉及到 GDI+ ，需要首先初始化环境
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	gdiplusToken = 0;
	// initializes Microsoft Windows GDI+. 
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	/////////////////////////////////////////////////////////////////////
	// 一、根据二进制数据创建 Image （关联到这些二进制数据）。
	// 1.分配一块内存区
	SIZE_T dwBytes = nBytes; 
	// GHND : Combines GMEM_MOVEABLE and GMEM_ZEROINIT.
	HGLOBAL  hImage = ::GlobalAlloc(GHND, dwBytes);
	if (!hImage)
	{
		return;
	}
	// 2.将二进制数据复制到该内存区
	char *pImage = (char *)GlobalLock(hImage);
	if (!pImage)
	{
		::GlobalFree(hImage);
		return;
	}
	memcpy(pImage, p, dwBytes);
	// GlobalUnlock 锁内存，使用完需要及时释放锁。
	// 此处没有释放导致后续 Image* image = ::new Image(pImageStream); 为 NULL 不成功。
	::GlobalUnlock(hImage);
	pImage = NULL;

	// 3.基于该内存区创建一个流接口
	IStream* pImageStream = NULL;
	if (::CreateStreamOnHGlobal(hImage, FALSE, &pImageStream) != S_OK)
	{
		::GlobalFree(hImage);
		return;
	}

	// 4.基于流接口创建Image
	Image* image = ::new Image(pImageStream);
	if (image == NULL || image->GetLastStatus() != 0)
	{
		pImageStream->Release();
		::GlobalFree(hImage);
		return;
	}

	/////////////////////////////////////////////////////////////////////
	// 二、使用 Iamge 的二进制数据（其它格式）转换为BMP的位图数据，并输出到缓冲区。
	// 1.分配一块输出内存区 （未知输出区域有多大）
	HGLOBAL  hOutImage = ::GlobalAlloc(GHND, 0);
	if (!hOutImage)
	{
		pImageStream->Release();
		::GlobalFree(hImage);
		delete image;
		return;
	}

	// 2.基于输出内存区创建一个输出流接口 （流关联内存区）
	IStream* pOutImageStream = NULL;
	if (::CreateStreamOnHGlobal(hOutImage, FALSE, &pOutImageStream) != S_OK)
	{
		pImageStream->Release();
		::GlobalFree(hImage);
		delete image;
		::GlobalFree(hOutImage);
		return;
	}

	// 3.解码并输出图片数据到输出流 （即输出内存区）
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

	// 4.将图片数据从输出内存区复制出来
	int size = ::GlobalSize(hOutImage);
	OutBmpImg.resize(size);
	char *srcBuffer = (char *)::GlobalLock(hOutImage);
	if (srcBuffer)
	{
		memcpy((void*)OutBmpImg.c_str(), srcBuffer, size);
	}
	::GlobalUnlock(hOutImage);

	// 5.结束，释放资源
	::GlobalFree(hImage);
	::GlobalFree(hOutImage);
	
	pImageStream->Release();
	pOutImageStream->Release();
	//delete image; // delete image 有异常发生。
	

	// cleans up resources used by Microsoft Windows GDI+
	if (gdiplusToken != NULL)
	{
		GdiplusShutdown(gdiplusToken);
	}
}
