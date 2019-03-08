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
// 假设 ICaptureGraphBuilder2 *pBuild, IBaseFilter *pCap 都已经创建初始化完成
// ICaptureGraphBuilder2::RenderStream 用于创建 video preview graph。

// Previewing Video 
// To build a video preview graph, call the ICaptureGraphBuilder2::RenderStream method as follows:
// pBuild was initialized, as described in About the Capture Graph Builder. 
// pCap was initialized, by creating an instance of the capture filter and adding it to the filter graph, as described in Selecting a Capture Device.
void RenderStreamToPreview(ICaptureGraphBuilder2 *pBuild, IBaseFilter *pCap)
{
	HRESULT hr = pBuild->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video, 
		pCap /*capture filter ，即视频捕获设备，如摄像头*/, NULL /*中间 filter ，目前不指定*/, NULL /*终点 filter ，NULL 即默认代表屏幕*/);

	// pCap: capture filter 源
	// 最后一个 NULL: causes the Capture Graph Builder to select a default renderer for the stream, based on the media type. For video, the Capture Graph Builder always uses the Video Renderer filter as the default renderer. 
}
