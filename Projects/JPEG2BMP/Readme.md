## VC++ 在内存中Jpeg转换Bmp图片

引用参考：
* https://www.cnblogs.com/ym123/p/4137997.html
* MSDN
* Docs  Visual C++  文档  Windows  ATL/MFC 共享类  参考  CImage 类     https://docs.microsoft.com/zh-cn/cpp/atl-mfc-shared/reference/cimage-class?view=vs-2019

1. 简单使用 CImage 加载图片文件进行直接显示。
从指定文件名直接加载图片。

2. 使用现有的CImage类在内存中进行转换，不需要保存为文件，也不需要引入第三方库（ Libjpeg库 ）。
void JPEG2BMP_Memory_CImage(char* pUnZipData,unsigned long ulUnZipDataLen, CImage* pImage);

3. CImage 对象加载已经在内存中的图片数据（ IStream 流）。（自动将JPEG数据转换为了BMP？？？）
先从指定文件提取数据到内存，再在内存上构建IStream流，CImage再加载IStream流（即加载图片数据）。

4. 将图片文件另存为另一个文件或者格式。
void JPEG2BMP_File_CImage(const char* inputFileName, const char* saveFileName);
确实应该是 CImage 内部自动将其他格式图片数据转换为了对应的BMP数据


## CImage 学习

**CImage 对图片操作更强大**
CImage provides enhanced bitmap support, including the ability to load and save images in JPEG, GIF, BMP, and Portable Network Graphics (PNG) formats. 

- CImage 可支持 DIB ，也可支持 非 DIB （部分操作方法受限不可用）。
can use Create or CImage::Load with only DIB sections. 
can attach a non-DIB section bitmap to a CImage object using Attach. (but then you cannot use the CImage methods, which support only DIB section bitmaps)
To determine if an attached bitmap is a DIB section, call IsDibSection. 

**CImage 内部自建有 DC**
CImage cannot be selected into a new CDC. 
CImage creates its own HDC for the image. 
Because an HBITMAP can only be selected into one HDC at a time, the HBITMAP associated with the CImage cannot be selected into another HDC. 
If you need a CDC, retrieve the HDC from the CImage and give it to CDC::FromHandle. 

**CImage 转换得到 CBitmap**
- CImage 可直接当作 HBITMAP 来使用。
CImage::operator HBITMAP 
Use this operator to get the attached Windows GDI handle of the CImage object. This operator is a casting operator, which supports direct use of an HBITMAP object. 

- 从 HBITMAP 构建得到 CBitmap 。
CBitmap::FromHandle 
Returns a pointer to a CBitmap object when given a handle to a Windows GDI bitmap. 
static CBitmap* PASCAL FromHandle(HBITMAP hBitmap);

- 通过转换即可操作图片位数据等信息。
Through CImage, you have access to the actual bits of a DIB section. You can use a CImage object anywhere you previously used a Win32 HBITMAP or DIB section. 

**注意头文件包含关系**
参见文档注项

**官方示例**
SimpleImage Sample: Loads, Resizes, Converts, and Saves Images 

**CImage::Load**
支持从指定文件名或者IStream流加载图片。
HRESULT Load(LPCTSTR pszFileName) throw( );
HRESULT Load(IStream* pStream) throw();









