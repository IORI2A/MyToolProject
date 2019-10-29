// GDI_CapturingAnImage.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "GDI_CapturingAnImage.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                        // current instance
TCHAR szTitle[MAX_LOADSTRING];          // The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];    // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GDI_CAPTURINGANIMAGE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GDI_CAPTURINGANIMAGE));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style            = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra        = 0;
	wcex.cbWndExtra        = 0;
	wcex.hInstance        = hInstance;
	wcex.hIcon            = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GDI_CAPTURINGANIMAGE));
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground    = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName    = MAKEINTRESOURCE(IDC_GDI_CAPTURINGANIMAGE);
	wcex.lpszClassName    = szWindowClass;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

//
//   FUNCTION: CaptureAnImage(HWND hWnd)
//
//   PURPOSE: Captures a screenshot into a window and then saves it in a .bmp file.
//
//   COMMENTS: 
//
//      Note: This sample will attempt to create a file called captureqwsx.bmp 
//        



int CaptureAnImage(HWND hWnd)
{
	HDC hdcScreen;
	HDC hdcWindow;
	HDC hdcMemDC = NULL;
	HBITMAP hbmScreen = NULL;
	BITMAP bmpScreen;

	// 1.��ȡȫ��Ļ�� DC ����ʾλͼ�������ڵ� DC ���Լ��ڴ� DC (Compatible DC) ��
	// ���ִ������͵� DC (Window DC) Ĭ�϶����и��� HGDIOBJ ����ģ��� BITMAP ���� ������ DC (Compatible DC) Ĭ����û���κ� HGDIOBJ ����� ������
	// Retrieve the handle to a display device context for the client 
	// area of the window. 
	hdcScreen = GetDC(NULL);
	hdcWindow = GetDC(hWnd);

	// Create a compatible DC which is used in a BitBlt from the window DC
	hdcMemDC = CreateCompatibleDC(hdcWindow); 

	if(!hdcMemDC)
	{
		MessageBox(hWnd, L"CreateCompatibleDC has failed",L"Failed", MB_OK);
		goto done;
	}

	// 2.��ȡȫ����������ʾ�������������С�
	// Get the client area for size calculation
	RECT rcClient;
	GetClientRect(hWnd, &rcClient);

	// ����λͼ����ģʽ��
	// The HALFTONE mode is slower and requires more processing of the source image than the other three modes; but produces higher quality images. 
	// HALFTONE �ǲ��Ǳ�ʾʹ�ã����������ͬ��һ��һ���ƣ����ز�ͬ������С���ϲ������ֵ��С����ͬɫ���ܱ߽���ֲ���ɢ������
	// ����ͨ�����������������ʵ�����ģʽ��
	//This is the best stretch mode
	SetStretchBltMode(hdcWindow,HALFTONE);

	// The StretchBlt function copies a bitmap from a source rectangle into a destination rectangle, stretching or compressing the bitmap to fit the dimensions of the destination rectangle, if necessary. 
	// The system stretches or compresses the bitmap according to the stretching mode currently set in the destination device context. 
	// ��������ģʽ���� DC �����Ÿ��� DC �е�λͼ
	//The source DC is the entire screen and the destination DC is the current window (HWND)
	if(!StretchBlt(hdcWindow, 
		0,0, 
		rcClient.right, rcClient.bottom, 
		hdcScreen, 
		0,0,
		GetSystemMetrics (SM_CXSCREEN),
		GetSystemMetrics (SM_CYSCREEN),
		SRCCOPY))
	{
		MessageBox(hWnd, L"StretchBlt has failed",L"Failed", MB_OK);
		goto done;
	}

	// 3.���������ڴ��� Compatible Bitmap�����󶨵� �ڴ� DC (Compatible DC) ������������ʾ���ݣ������ڵ�BITMAP�����Ƶ� Compatible Bitmap �С�
	// Create a compatible bitmap from the Window DC
	hbmScreen = CreateCompatibleBitmap(hdcWindow, rcClient.right-rcClient.left, rcClient.bottom-rcClient.top);

	if(!hbmScreen)
	{
		MessageBox(hWnd, L"CreateCompatibleBitmap Failed",L"Failed", MB_OK);
		goto done;
	}

	// Select the compatible bitmap into the compatible memory DC.
	SelectObject(hdcMemDC,hbmScreen);

	// Bit block transfer into our compatible memory DC.
	if(!BitBlt(hdcMemDC, 
		0,0, 
		rcClient.right-rcClient.left, rcClient.bottom-rcClient.top, 
		hdcWindow, 
		0,0,
		SRCCOPY))
	{
		MessageBox(hWnd, L"BitBlt has failed", L"Failed", MB_OK);
		goto done;
	}

	// 4.���� Compatible Bitmap ��ȡ BITMAP �ṹ��Ϣ������BITMAP��Ϣ����λͼ BITMAPINFOHEADER �ṹ������洢λ���������ڴ�����
	// Get the BITMAP from the HBITMAP
	GetObject(hbmScreen,sizeof(BITMAP),&bmpScreen);

	// ָ������洢λͼ�ķ�ʽ
	BITMAPFILEHEADER   bmfHeader;   
	// BITMAPINFOHEADER�ṹ���� DIB�ĳߴ����ɫ��ʽ����Ϣ��
	BITMAPINFOHEADER   bi;

	bi.biSize = sizeof(BITMAPINFOHEADER);    
	bi.biWidth = bmpScreen.bmWidth;    
	bi.biHeight = bmpScreen.bmHeight;  
	// Ŀ���豸��ƽ��������ֵ��������Ϊ1��
	bi.biPlanes = 1; 
	// λͼ������2 ^ 32����ɫ�����BITMAPINFOHEADER��biCompression��ԱΪBI_RGB����BITMAPINFO��bmiColors��ԱΪNULL��
	// λͼ�����е�ÿ��DWORD����һ�����ص���ɫ����ɫ�ͺ�ɫ�����ǿ�ȡ���ɫ��ֵ�������Ч8λ��Ȼ������ɫ�ͺ�ɫ��8λ����ʹ��ÿ��DWORD�еĸ��ֽڡ�
	// 2 ^ 24����ɫ�������ɫ��(24λ���)���Ѿ����Բ�ʹ�� BITMAPINFO��bmiColors��Ա�ˣ�����
	bi.biBitCount = 32;    
	// �Ե����ϵ�ѹ��λͼ��ѹ�����ͣ��Զ����µ�DIB�޷�ѹ������BI_RGB	δѹ���ĸ�ʽ��
	bi.biCompression = BI_RGB;  
	// ͼ��Ĵ�С�����ֽ�Ϊ��λ��������BI_RGBλͼ�����Խ�������Ϊ�㡣
	// ���biCompressionΪBI_JPEG��BI_PNG����biSizeImage�ֱ�ָʾJPEG��PNGͼ�񻺳����Ĵ�С��
	bi.biSizeImage = 0;  
	// λͼĿ���豸��ˮƽ�ֱ��ʣ���ÿ������Ϊ��λ��
	bi.biXPelsPerMeter = 0;    
	// λͼĿ���豸�Ĵ�ֱ�ֱ��ʣ���ÿ������Ϊ��λ��
	bi.biYPelsPerMeter = 0;  
	// λͼʵ��ʹ�õ���ɫ���е���ɫ�������������ֵΪ�㣬�������biCompressionָ����ѹ��ģʽ��λͼ��ʹ����biBitCount��Ա��ֵ��Ӧ�������ɫ����
	bi.biClrUsed = 0;   
	// ��ʾλͼ�������ɫ�������������ֵΪ�㣬����Ҫ������ɫ��
	bi.biClrImportant = 0;

	// λͼ��λ����(bitmap bits) = ���ؾ����ȣ�λͼ��ȣ�*����λ��ʾһ�����أ�biBitCount = 32λ = 4�ֽڣ�*���ؾ���߶ȣ�λͼ�߶ȣ�
	// ���⣬λͼ�洢ʱ��Windows�涨һ��ɨ������ռ���ֽ���������4�ı���(����longΪ��λ),�������0���
	// λͼ��λ���� ��ת��Ϊ �ֽ��������ڴ���䡣
	DWORD dwBmpSize = ((bmpScreen.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmpScreen.bmHeight;
	//DWORD dwBmpSize2 = bmpScreen.bmWidth  * 4 * bmpScreen.bmHeight; // ������ ����ֵ������ͬ

	// Starting with 32-bit Windows, GlobalAlloc and LocalAlloc are implemented as wrapper functions that 
	// call HeapAlloc using a handle to the process's default heap. Therefore, GlobalAlloc and LocalAlloc 
	// have greater overhead than HeapAlloc.
	HANDLE hDIB = GlobalAlloc(GHND,dwBmpSize); 
	char *lpbitmap = (char *)GlobalLock(hDIB);    

	// 5.��ȡλͼλ�������ݡ�
	// ֱ�Ӵ������ڵ�compatible bitmap (DDB)��ȡ����ת��ΪDIB���ݣ�����
	// �Ƿ��ͨ�� GetDIBits ֱ�ӵõ� compatible bitmap �� BITMAPINFO ��Ϣ������
	// Gets the "bits" from the bitmap and copies them into a buffer 
	// which is pointed to by lpbitmap.
	GetDIBits(hdcWindow, hbmScreen /*Handle to the bitmap. This must be a compatible bitmap (DDB). */, 0,
		(UINT)bmpScreen.bmHeight,
		lpbitmap /*receive the bitmap data. If this parameter is NULL, the function passes the dimensions and format of the bitmap to the BITMAPINFO structure*/,
		(BITMAPINFO *)&bi/*Pointer to a BITMAPINFO structure that specifies the desired format for the DIB data*/, DIB_RGB_COLORS);

	// 6.����λͼ�ļ����б��档
	// A file is created, this is where we will save the screen capture.
	HANDLE hFile = CreateFile(L"captureqwsx.bmp",
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);   

	// Add the size of the headers to the size of the bitmap to get the total file size
	DWORD dwSizeofDIB = dwBmpSize + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	//Offset to where the actual bitmap bits start.
	bmfHeader.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER); 

	//Size of the file
	bmfHeader.bfSize = dwSizeofDIB; 

	//bfType must always be BM for Bitmaps
	bmfHeader.bfType = 0x4D42; //BM   

	DWORD dwBytesWritten = 0;
	WriteFile(hFile, (LPSTR)&bmfHeader, sizeof(BITMAPFILEHEADER), &dwBytesWritten, NULL);
	WriteFile(hFile, (LPSTR)&bi, sizeof(BITMAPINFOHEADER), &dwBytesWritten, NULL);
	WriteFile(hFile, (LPSTR)lpbitmap, dwBmpSize, &dwBytesWritten, NULL);

	//Unlock and Free the DIB from the heap
	GlobalUnlock(hDIB);    
	GlobalFree(hDIB);

	//Close the handle for the file that was created
	CloseHandle(hFile);

	//Clean up
done:
	DeleteObject(hbmScreen);
	DeleteObject(hdcMemDC);
	ReleaseDC(NULL,hdcScreen);
	ReleaseDC(hWnd,hdcWindow);

	return 0;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND    - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY    - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		{
			break;
		}
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_MOVE:

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		CaptureAnImage(hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}