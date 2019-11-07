#ifndef __UTIL_H__
#define __UTIL_H__



////////////////////// ʹ�� ATL/MFC CImage �� ///////////////////////////////////
// ʹ�����е�CImage�����ڴ��н���ת��������Ҫ����Ϊ�ļ���Ҳ����Ҫ����������⣨ Libjpeg�� ����
void JPEG2BMP_Memory_CImage(char* pUnZipData,unsigned long ulUnZipDataLen, CImage* pImage);
// ʹ�� CImage �ཫͼƬ�ļ����Ϊ��һ���ļ����߸�ʽ��
void JPEG2BMP_File_CImage(const wchar_t *inputFileName, const wchar_t *saveFileName);


////////////////////// ʹ�� GID+ Image Class ///////////////////////////////////
#include <string>
using namespace std;

// ��ȡָ����ͼ���ʽ��������CLSID
// ���أ�-1��ʧ�ܣ� >=0���ɹ�
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
// ���ڴ��е�JPEG����������ת��ΪBMPλͼ���ݣ��洢��ָ���Ļ������С�
// const char *p, [in]    JPEG�Ķ��������ݡ�
// int nBytes, [in]    ���������ݵĳ��ȡ�
// std::string& OutBmpImg, [out]    ת�����BMPλͼ���ݡ�
void JPEG2BMP_Memory_Image(const char *p, int nBytes, std::string& OutBmpImg);



#endif /*__UTIL_H__*/