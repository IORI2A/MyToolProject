#include <DShow.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 调用 CoCreateInstance 来创建 Capture Graph Builder 和 Filter Graph Manager 实例，其分别导出接口 ICaptureGraphBuilder2 和 IGraphBuilder 。
// 并调用 ICaptureGraphBuilder2::SetFiltergraph 使用 IGraphBuilder 来对 Capture Graph Builder 其进行初始化。即使用 Filter Graph Manager 初始化 Capture Graph Builder 。

// About Video Capture in DirectShow > About the Capture Graph Builder
// Start by calling CoCreateInstance to create new instances of the Capture Graph Builder and the Filter Graph Manager. 
// Then initialize the Capture Graph Builder by calling ICaptureGraphBuilder2::SetFiltergraph with a pointer to the Filter Graph Manager's IGraphBuilder interface. 
// The following code shows a helper function to perform these steps: 
HRESULT InitCaptureGraphBuilder(
	IGraphBuilder **ppGraph,  // Receives the pointer.
	ICaptureGraphBuilder2 **ppBuild  // Receives the pointer.
	)
{
	if (!ppGraph || !ppBuild)
	{
		return E_POINTER;
	}
	IGraphBuilder *pGraph = NULL;
	ICaptureGraphBuilder2 *pBuild = NULL;

	// Create the Capture Graph Builder.
	HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, 
		CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, (void**)&pBuild );
	if (SUCCEEDED(hr))
	{
		// Create the Filter Graph Manager.
		hr = CoCreateInstance(CLSID_FilterGraph, 0, CLSCTX_INPROC_SERVER,
			IID_IGraphBuilder, (void**)&pGraph);
		if (SUCCEEDED(hr))
		{
			// Initialize the Capture Graph Builder.
			pBuild->SetFiltergraph(pGraph);

			// Return both interface pointers to the caller.
			*ppBuild = pBuild;
			*ppGraph = pGraph; // The caller must release both interfaces.
			return S_OK;
		}
		else
		{
			pBuild->Release();
		}
	}
	return hr; // Failed
}