#include "stdafx.h"
#include "util.h"




// 使用现有的CImage类在内存中进行转换，不需要保存为文件，也不需要引入第三方库（ Libjpeg库 ）。
// 使用CImage从内存中读取Jpeg格式的图片，只需要传入一个IStream接口的流，IStream对象使用CreateStreamOnHGlobal进行创建。
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
