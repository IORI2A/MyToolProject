#ifndef __UTIL_H__
#define __UTIL_H__


// 使用现有的CImage类在内存中进行转换，不需要保存为文件，也不需要引入第三方库（ Libjpeg库 ）。
void JPEG2BMP_Memory_CImage(char* pUnZipData,unsigned long ulUnZipDataLen, CImage* pImage);


// 将图片文件另存为另一个文件或者格式。
void JPEG2BMP_File_CImage(const wchar_t *inputFileName, const wchar_t *saveFileName);


#endif /*__UTIL_H__*/