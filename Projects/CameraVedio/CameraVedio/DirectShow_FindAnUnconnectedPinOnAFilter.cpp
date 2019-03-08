#include <windows.h>
#include <dshow.h>
#include "qedit.h"
#include <assert.h>

template<class T>
void SafeRelease(T **ppT);



// Query whether a pin is connected to another pin.
//
// Note: This function does not return a pointer to the connected pin.

HRESULT IsPinConnected(IPin *pPin, BOOL *pResult)
{
	IPin *pTmp = NULL;
	HRESULT hr = pPin->ConnectedTo(&pTmp);
	if (SUCCEEDED(hr))
	{
		*pResult = TRUE;
	}
	else if (hr == VFW_E_NOT_CONNECTED)
	{
		// The pin is not connected. This is not an error for our purposes.
		*pResult = FALSE;
		hr = S_OK;
	}

	SafeRelease(&pTmp);
	return hr;
}


// Query whether a pin has a specified direction (input / output)
HRESULT IsPinDirection(IPin *pPin, PIN_DIRECTION dir, BOOL *pResult)
{
	PIN_DIRECTION pinDir;
	HRESULT hr = pPin->QueryDirection(&pinDir);
	if (SUCCEEDED(hr))
	{
		*pResult = (pinDir == dir);
	}
	return hr;
}


// Match a pin by pin direction and connection state.
HRESULT MatchPin(IPin *pPin, PIN_DIRECTION direction, BOOL bShouldBeConnected, BOOL *pResult)
{
	assert(pResult != NULL);

	BOOL bMatch = FALSE;
	BOOL bIsConnected = FALSE;

	HRESULT hr = IsPinConnected(pPin, &bIsConnected);
	if (SUCCEEDED(hr))
	{
		if (bIsConnected == bShouldBeConnected)
		{
			hr = IsPinDirection(pPin, direction, &bMatch);
		}
	}

	if (SUCCEEDED(hr))
	{
		*pResult = bMatch;
	}
	return hr;
}


// Return the first unconnected input pin or output pin.
HRESULT FindUnconnectedPin(IBaseFilter *pFilter, PIN_DIRECTION PinDir, IPin **ppPin)
{
	IEnumPins *pEnum = NULL;
	IPin *pPin = NULL;
	BOOL bFound = FALSE;

	HRESULT hr = pFilter->EnumPins(&pEnum);
	if (FAILED(hr))
	{
		goto done;
	}

	while (S_OK == pEnum->Next(1, &pPin, NULL))
	{
		hr = MatchPin(pPin, PinDir, FALSE, &bFound);
		if (FAILED(hr))
		{
			goto done;
		}
		if (bFound)
		{
			*ppPin = pPin;
			(*ppPin)->AddRef();
			break;
		}
		SafeRelease(&pPin);
	}

	if (!bFound)
	{
		hr = VFW_E_NOT_FOUND;
	}

done:
	SafeRelease(&pPin);
	SafeRelease(&pEnum);
	return hr;
}