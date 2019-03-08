#include <dshow.h>

extern
HRESULT FindUnconnectedPin(IBaseFilter *pFilter, PIN_DIRECTION PinDir, IPin **ppPin);



// Connect output pin to filter.

HRESULT ConnectFilters(
	IGraphBuilder *pGraph, // Filter Graph Manager.
	IPin *pOut,            // Output pin on the upstream filter.
	IBaseFilter *pDest)    // Downstream filter.
{
	IPin *pIn = NULL;

	// Find an input pin on the downstream filter.
	HRESULT hr = FindUnconnectedPin(pDest, PINDIR_INPUT, &pIn);
	if (SUCCEEDED(hr))
	{
		// Try to connect them.
		hr = pGraph->Connect(pOut, pIn);
		pIn->Release();
	}
	return hr;
}


// Connect filter to input pin.

HRESULT ConnectFilters(IGraphBuilder *pGraph, IBaseFilter *pSrc, IPin *pIn)
{
	IPin *pOut = NULL;

	// Find an output pin on the upstream filter.
	HRESULT hr = FindUnconnectedPin(pSrc, PINDIR_OUTPUT, &pOut);
	if (SUCCEEDED(hr))
	{
		// Try to connect them.
		hr = pGraph->Connect(pOut, pIn);
		pOut->Release();
	}
	return hr;
}


// Connect filter to filter

HRESULT ConnectFilters(IGraphBuilder *pGraph, IBaseFilter *pSrc, IBaseFilter *pDest)
{
	IPin *pOut = NULL;

	// Find an output pin on the first filter.
	HRESULT hr = FindUnconnectedPin(pSrc, PINDIR_OUTPUT, &pOut);
	if (SUCCEEDED(hr))
	{
		hr = ConnectFilters(pGraph, pOut, pDest);
		pOut->Release();
	}
	return hr;
}