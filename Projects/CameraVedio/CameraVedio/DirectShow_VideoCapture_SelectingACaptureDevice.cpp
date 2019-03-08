#include <windows.h>
#include <dshow.h>

#pragma comment(lib, "strmiids")

HRESULT EnumerateDevices(REFGUID category, IEnumMoniker **ppEnum)
{
	// Create the System Device Enumerator.
	ICreateDevEnum *pDevEnum;
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,  
		CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDevEnum));

	if (SUCCEEDED(hr))
	{
		// Create an enumerator for the category.
		hr = pDevEnum->CreateClassEnumerator(category, ppEnum, 0);
		if (hr == S_FALSE)
		{
			hr = VFW_E_NOT_FOUND;  // The category is empty. Treat as an error.
		}
		pDevEnum->Release();
	}
	return hr;
}


void DisplayDeviceInformation(IEnumMoniker *pEnum)
{
	IMoniker *pMoniker = NULL;

	while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
	{
		IPropertyBag *pPropBag;
		HRESULT hr = pMoniker->BindToStorage(0, 0, IID_PPV_ARGS(&pPropBag));
		if (FAILED(hr))
		{
			pMoniker->Release();
			continue;  
		} 

		VARIANT var;
		VariantInit(&var);

		// Get description or friendly name.
		hr = pPropBag->Read(L"Description", &var, 0);
		if (FAILED(hr))
		{
			hr = pPropBag->Read(L"FriendlyName", &var, 0);
		}
		if (SUCCEEDED(hr))
		{
			printf("%S\n", var.bstrVal);
			VariantClear(&var); 
		}

		hr = pPropBag->Write(L"FriendlyName", &var);

		// WaveInID applies only to audio capture devices.
		hr = pPropBag->Read(L"WaveInID", &var, 0);
		if (SUCCEEDED(hr))
		{
			printf("WaveIn ID: %d\n", var.lVal);
			VariantClear(&var); 
		}

		hr = pPropBag->Read(L"DevicePath", &var, 0);
		if (SUCCEEDED(hr))
		{
			// The device path is not intended for display.
			printf("Device path: %S\n", var.bstrVal);
			VariantClear(&var); 
		}

		pPropBag->Release();
		pMoniker->Release();
	}
}

//void main()
//{
//	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);
//	if (SUCCEEDED(hr))
//	{
//		IEnumMoniker *pEnum;
//
//		hr = EnumerateDevices(CLSID_VideoInputDeviceCategory, &pEnum);
//		if (SUCCEEDED(hr))
//		{
//			DisplayDeviceInformation(pEnum);
//			pEnum->Release();
//		}
//		hr = EnumerateDevices(CLSID_AudioInputDeviceCategory, &pEnum);
//		if (SUCCEEDED(hr))
//		{
//			DisplayDeviceInformation(pEnum);
//			pEnum->Release();
//		}
//		CoUninitialize();
//	}
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 简单实现选择第一个视频捕获设备（摄像头）为默认设备
IBaseFilter * SelectDefaultCaptureDevice(IGraphBuilder *m_pGraph)
{
	// Selecting a Capture Device
	// The following code creates an enumerator for video capture devices:
	ICreateDevEnum *pDevEnum = NULL;
	IEnumMoniker *pEnum = NULL;

	// Create the System Device Enumerator.
	HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
		CLSCTX_INPROC_SERVER, IID_ICreateDevEnum, 
		reinterpret_cast<void**>(&pDevEnum));
	if (SUCCEEDED(hr))
	{
		// Create an enumerator for the video capture category.
		hr = pDevEnum->CreateClassEnumerator(
			CLSID_VideoInputDeviceCategory,
			&pEnum, 0);
	}

	//// The following code example shows how to populate a list box with the device names: 
	//HWND hList; // Handle to the list box.
	//IMoniker *pMoniker = NULL;
	//while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
	//{
	//	IPropertyBag *pPropBag;
	//	hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag, 
	//		(void**)(&pPropBag));
	//	if (FAILED(hr))
	//	{
	//		pMoniker->Release();
	//		continue;  // Skip this one, maybe the next one will work.
	//	} 
	//	// Find the description or friendly name.
	//	VARIANT varName;
	//	VariantInit(&varName);
	//	hr = pPropBag->Read(L"Description", &varName, 0);
	//	if (FAILED(hr))
	//	{
	//		hr = pPropBag->Read(L"FriendlyName", &varName, 0);
	//	}
	//	if (SUCCEEDED(hr))
	//	{
	//		// Add it to the application's list box.
	//		USES_CONVERSION;
	//		(long)SendMessage(hList, LB_ADDSTRING, 0, 
	//			(LPARAM)OLE2T(varName.bstrVal));
	//		VariantClear(&varName); 
	//	}
	//	pPropBag->Release();
	//	pMoniker->Release();
	//}

	// 直接使用第一个设备
	IMoniker *pMoniker = NULL;
	hr = pEnum->Next(1, &pMoniker, NULL);
	if (FAILED(hr))
	{
		//...
	}

	// When the user selects a device, create the capture filter for the device by calling IMoniker::BindToObject on the moniker. Then call AddFilter to add the filter to the filter graph:
	IBaseFilter *pCap = NULL;
	hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pCap);
	if (SUCCEEDED(hr))
	{
		hr = m_pGraph->AddFilter(pCap, L"Capture Filter");
	}

	return pCap;
}
