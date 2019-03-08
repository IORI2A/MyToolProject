#include <DShow.h>


//ICaptureGraphBuilder2 *pBuild; // Capture Graph Builder
//// Initialize pBuild (not shown).
//
//IBaseFilter *pCap; // Video capture filter.
//
///* Initialize pCap and add it to the filter graph (not shown). */
//
//hr = pBuild->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video, 
//	pCap, NULL, NULL);



////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� ICaptureGraphBuilder2 *pBuild, IBaseFilter *pCap ���Ѿ�������ʼ�����
// ICaptureGraphBuilder2::RenderStream ���ڴ��� video preview graph��

// Previewing Video 
// To build a video preview graph, call the ICaptureGraphBuilder2::RenderStream method as follows:
// pBuild was initialized, as described in About the Capture Graph Builder. 
// pCap was initialized, by creating an instance of the capture filter and adding it to the filter graph, as described in Selecting a Capture Device.
void RenderStreamToPreview(ICaptureGraphBuilder2 *pBuild, IBaseFilter *pCap)
{
	HRESULT hr = pBuild->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video, 
		pCap /*capture filter ������Ƶ�����豸��������ͷ*/, NULL /*�м� filter ��Ŀǰ��ָ��*/, NULL /*�յ� filter ��NULL ��Ĭ�ϴ�����Ļ*/);

	// pCap: capture filter Դ
	// ���һ�� NULL: causes the Capture Graph Builder to select a default renderer for the stream, based on the media type. For video, the Capture Graph Builder always uses the Video Renderer filter as the default renderer. 
}
