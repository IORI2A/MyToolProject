#ifndef __UTIL_H__
#define __UTIL_H__


// ʹ�����е�CImage�����ڴ��н���ת��������Ҫ����Ϊ�ļ���Ҳ����Ҫ����������⣨ Libjpeg�� ����
void JPEG2BMP_Memory_CImage(char* pUnZipData,unsigned long ulUnZipDataLen, CImage* pImage);


// ��ͼƬ�ļ����Ϊ��һ���ļ����߸�ʽ��
void JPEG2BMP_File_CImage(const wchar_t *inputFileName, const wchar_t *saveFileName);


#endif /*__UTIL_H__*/