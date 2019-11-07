#ifndef __UTIL_H__
#define __UTIL_H__



////////////////////// 使用 ATL/MFC CImage 类 ///////////////////////////////////
// 使用现有的CImage类在内存中进行转换，不需要保存为文件，也不需要引入第三方库（ Libjpeg库 ）。
void JPEG2BMP_Memory_CImage(char* pUnZipData,unsigned long ulUnZipDataLen, CImage* pImage);
// 使用 CImage 类将图片文件另存为另一个文件或者格式。
void JPEG2BMP_File_CImage(const wchar_t *inputFileName, const wchar_t *saveFileName);


////////////////////// 使用 GID+ Image Class ///////////////////////////////////
#include <string>
using namespace std;

// 获取指定的图像格式编码器的CLSID
// 返回：-1，失败； >=0，成功
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
// 将内存中的JPEG二进制数据转换为BMP位图数据，存储于指定的缓冲区中。
// const char *p, [in]    JPEG的二进制数据。
// int nBytes, [in]    二进制数据的长度。
// std::string& OutBmpImg, [out]    转换后的BMP位图数据。
void JPEG2BMP_Memory_Image(const char *p, int nBytes, std::string& OutBmpImg);



#endif /*__UTIL_H__*/