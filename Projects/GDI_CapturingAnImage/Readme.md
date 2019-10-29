## MSDN 原文

Docs  Windows  Windows GDI  Bitmaps  Using Bitmaps  Capturing an Image 


Capturing an Image
‎05‎/‎31‎/‎2018

  
You can use a bitmap to capture an image, and you can store the captured image in memory, display it at a different location in your application's window, or display it in another window.
In some cases, you may want your application to capture images and store them only temporarily. For example, when you scale or zoom a picture created in a drawing application, the application must temporarily save the normal view of the image and display the zoomed view. Later, when the user selects the normal view, the application must replace the zoomed image with a copy of the normal view that it temporarily saved.
To store an image temporarily, your application must call CreateCompatibleDC to create a DC that is compatible with the current window DC. After you create a compatible DC, you create a bitmap with the appropriate dimensions by calling the CreateCompatibleBitmap function and then select it into this device context by calling the SelectObject function.
After the compatible device context is created and the appropriate bitmap has been selected into it, you can capture the image. The BitBlt function captures images. This function performs a bit block transfer that is, it copies data from a source bitmap into a destination bitmap. However, the two arguments to this function are not bitmap handles. Instead, BitBlt receives handles that identify two device contexts and copies the bitmap data from a bitmap selected into the source DC into a bitmap selected into the target DC. In this case, the target DC is the compatible DC, so when BitBlt completes the transfer, the image has been stored in memory. To redisplay the image, call BitBlt a second time, specifying the compatible DC as the source DC and a window (or printer) DC as the target DC.
The following example code is from an application that captures an image of the entire desktop, scales it down to the current window size and then saves it to a file.

译文理解：
截取图像，并在内存中保存该图像

一、准备保存图像内存。
需要 Compatible DC 及 Compatible Bitmap ，两者通过 SelectObject 绑定。
在进行一些位图操作时，无法直接使用在进行一些位图操作时，无法直接使用 Compatible Bitmap ，而是由 Compatible DC 来代表 Compatible Bitmap 。
核心还是要有 Compatible Bitmap 。

二、进行截屏。
BitBlt 函数指定两个 DC 来代表 Bitmap 。这个两个 DC 需要已经包含有 Bitmap 对象 。（ SelectObject 来包含 ）


## 程序 CaptureAnImage 函数分析：

1.获取全屏幕的 DC ，显示位图的主窗口的 DC ，以及内存 DC (Compatible DC) 。
各种窗口类型的 DC (Window DC) 默认都是有各种 HGDIOBJ 对象的，如 BITMAP 对象。 而兼容 DC (Compatible DC) 默认是没有任何 HGDIOBJ 对象的 ？？？
GetDC
CreateCompatibleDC

2.截取全屏并复制显示到程序主窗口中。
设置位图缩放模式。HALFTONE 是不是表示使用，如果像素相同是一比一复制，像素不同，大往小画合并计算均值，小往大画同色与周边渐变分布扩散？？？可以通过变更参数调测最合适的缩放模式。
根据缩放模式，在 DC 间缩放复制 DC 中的位图
SetStretchBltMode
StretchBlt

3.基于主窗口创建 Compatible Bitmap，并绑定到 内存 DC (Compatible DC) ，将主窗口显示内容（主窗口的BITMAP）复制到 Compatible Bitmap 中。
CreateCompatibleBitmap
SelectObject
BitBlt

4.基于 Compatible Bitmap 获取 BITMAP 结构信息。根据BITMAP信息构造位图 BITMAPINFOHEADER 结构，计算存储位数据所需内存量。
BITMAPINFOHEADER结构包含 DIB的尺寸和颜色格式的信息。
位图的位数组(bitmap bits) = 像素矩阵宽度（位图宽度）*几个位表示一个像素（biBitCount = 32位 = 4字节）*像素矩阵高度（位图高度）
另外，位图存储时，Windows规定一个扫描行所占的字节数必须是4的倍数(即以long为单位),不足的以0填充
位图的位数组 再转化为 字节数便于内存分配。
GetObject
BITMAPFILEHEADER
BITMAPINFOHEADER

5.获取位图位数组数据。
直接从主窗口的compatible bitmap (DDB)获取，并转化为DIB数据？？？
是否可通过 GetDIBits 直接得到 compatible bitmap 的 BITMAPINFO 信息？？？
GetDIBits

6.创建位图文件进行保存。


## Bitmap MSDN中学习了解

Windows GDI

Win32 and COM Development
Graphics and Multimedia
GDI
Windows GDI
Bitmaps


bitmap consists : 
1.header: A header that describes the resolution of the device on which the rectangle of pixels was created, the dimensions of the rectangle, the size of the array of bits, and so on. 
2.palette: A logical palette. 
3.array: An array of bits that defines the relationship between pixels in the bitmapped image and entries in the logical palette. 


monochrome or color

each pixel corresponds to one or more bits 

bit per pixel (bpp) 
像素位

位图主要有三个部分。
1.头说明。
2.调色板。用于说明位图的颜色表达范围，也即一个像素可以显示的颜色数量。
3.位图具体的图像数据。实质是一个字节数组，存储所有像素，根据调色板颜色数量确定每个像素占用的位数（bpp）。像素值对应调色板上的对应颜色。

图像数据 的字节数组如何解析，需要根据 头说明 和 调色板 的值来确定。
如，调色板是16色的，由于每一个bit仅可表示两个信息（0，1），则需要4个bit来表示（16=<2^4=16）一个像素。（这时候像素的值代表的是调色板中的颜色索引，即色号？？？）



类推，调色板是24色的，由于每一个bit仅可表示两个信息（0，1），则需要5个bit来表示（24=<2^5=32）一个像素。

2^4 16
2^5 32

每像素的位数，必须是以下值之一
0、1、4、8、16、24、32
24位后就是真彩色了，可以不使用调色板颜色数据，而直接使用像素的位数据表示三元色（RGB，3个字节即可表示完全）？？？


两种位图分类：
Device-independent bitmaps (DIB)
Device-dependent bitmaps (DDB)  （后续基本弃用）


monochrome： black or white


四种头类型：
BITMAPCOREHEADER 
BITMAPINFOHEADER 
BITMAPV4HEADER 
BITMAPV5HEADER 

The BITMAPCOREHEADER and BITMAPV4HEADER formats have been superseded by BITMAPINFOHEADER and BITMAPV5HEADER formats, respectively. 


format for a DIB (for more information, see Bitmap Storage): 
1.a BITMAPFILEHEADER structure 
2.either a BITMAPCOREHEADER, a BITMAPINFOHEADER, a BITMAPV4HEADER, or a BITMAPV5HEADER structure. 
3.an optional color table, which is either a set of RGBQUAD structures or a set of RGBTRIPLE structures. 
4.the bitmap data 
5.optional Profile data 