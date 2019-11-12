
#ifndef SAMPLEGRAB_h
#define SAMPLEGRAB_h

#define SAFE_RELEASE(x) { if (x) x->Release(); x = NULL; }

IBaseFilter* sgGetSampleGrabber();
HRESULT sgAddSampleGrabber(IGraphBuilder *pGraph);
HRESULT sgSetSampleGrabberMediaType();
HRESULT sgGetSampleGrabberMediaType();

// 抓取帧图像数据 
// 帧图像数据，实际就已经是位图数据。只是不确定是 DIB ，还是非 DIB 。
// 缓冲模式，从缓冲区中提取当前帧图像。
unsigned char* sgGrabData();            //call grab data first
// 构造位图结构，并将帧图像数据（位图数据）封装成 Bitmap 对象。
Gdiplus::Bitmap* sgGetBitmap();        //fill bitmap with grabbed data
// 获取帧图像数据（位图数据）的大小
long sgGetBufferSize();

unsigned int sgGetDataWidth();
unsigned int sgGetDataHeight();
unsigned int sgGetDataChannels();

void sgCloseSampleGrabber();

#endif