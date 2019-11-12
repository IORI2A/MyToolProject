
#ifndef SAMPLEGRAB_h
#define SAMPLEGRAB_h

#define SAFE_RELEASE(x) { if (x) x->Release(); x = NULL; }

IBaseFilter* sgGetSampleGrabber();
HRESULT sgAddSampleGrabber(IGraphBuilder *pGraph);
HRESULT sgSetSampleGrabberMediaType();
HRESULT sgGetSampleGrabberMediaType();

// ץȡ֡ͼ������ 
// ֡ͼ�����ݣ�ʵ�ʾ��Ѿ���λͼ���ݡ�ֻ�ǲ�ȷ���� DIB �����Ƿ� DIB ��
// ����ģʽ���ӻ���������ȡ��ǰ֡ͼ��
unsigned char* sgGrabData();            //call grab data first
// ����λͼ�ṹ������֡ͼ�����ݣ�λͼ���ݣ���װ�� Bitmap ����
Gdiplus::Bitmap* sgGetBitmap();        //fill bitmap with grabbed data
// ��ȡ֡ͼ�����ݣ�λͼ���ݣ��Ĵ�С
long sgGetBufferSize();

unsigned int sgGetDataWidth();
unsigned int sgGetDataHeight();
unsigned int sgGetDataChannels();

void sgCloseSampleGrabber();

#endif