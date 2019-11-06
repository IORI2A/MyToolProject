#include "stdafx.h"
#include "util.h"




// ʹ�����е�CImage�����ڴ��н���ת��������Ҫ����Ϊ�ļ���Ҳ����Ҫ����������⣨ Libjpeg�� ����
// ʹ��CImage���ڴ��ж�ȡJpeg��ʽ��ͼƬ��ֻ��Ҫ����һ��IStream�ӿڵ�����IStream����ʹ��CreateStreamOnHGlobal���д�����
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
