#include <DShow.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� CoCreateInstance ������ Capture Graph Builder �� Filter Graph Manager ʵ������ֱ𵼳��ӿ� ICaptureGraphBuilder2 �� IGraphBuilder ��
// ������ ICaptureGraphBuilder2::SetFiltergraph ʹ�� IGraphBuilder ���� Capture Graph Builder ����г�ʼ������ʹ�� Filter Graph Manager ��ʼ�� Capture Graph Builder ��

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