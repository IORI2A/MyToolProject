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

	// 1.获取全屏幕的 DC ，显示位图的主窗口的 DC ，以及内存 DC (Compatible DC) 。
	// 各种窗口类型的 DC (Window DC) 默认都是有各种 HGDIOBJ 对象的，如 BITMAP 对象。 而兼容 DC (Compatible DC) 默认是没有任何 HGDIOBJ 对象的 ？？？
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

	// 2.截取全屏并复制显示到程序主窗口中。
	// Get the client area for size calculation
	RECT rcClient;
	GetClientRect(hWnd, &rcClient);

	// 设置位图缩放模式。
	// The HALFTONE mode is slower and requires more processing of the source image than the other three modes; but produces higher quality images. 
	// HALFTONE 是不是表示使用，如果像素相同是一比一复制，像素不同，大往小画合并计算均值，小往大画同色与周边渐变分布扩散？？？
	// 可以通过变更参数调测最合适的缩放模式。
	//This is the best stretch mode
	SetStretchBltMode(hdcWindow,HALFTONE);

	// The StretchBlt function copies a bitmap from a source rectangle into a destination rectangle, stretching or compressing the bitmap to fit the dimensions of the destination rectangle, if necessary. 
	// The system stretches or compresses the bitmap according to the stretching mode currently set in the destination device context. 
	// 根据缩放模式，在 DC 间缩放复制 DC 中的位图
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

	// 3.基于主窗口创建 Compatible Bitmap，并绑定到 内存 DC (Compatible DC) ，将主窗口显示内容（主窗口的BITMAP）复制到 Compatible Bitmap 中。
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

	// 4.基于 Compatible Bitmap 获取 BITMAP 结构信息。根据BITMAP信息构造位图 BITMAPINFOHEADER 结构，计算存储位数据所需内存量。
	// Get the BITMAP from the HBITMAP
	GetObject(hbmScreen,sizeof(BITMAP),&bmpScreen);

	// 指定你想存储位图的方式
	BITMAPFILEHEADER   bmfHeader;   
	// BITMAPINFOHEADER结构包含 DIB的尺寸和颜色格式的信息。
	BITMAPINFOHEADER   bi;

	bi.biSize = sizeof(BITMAPINFOHEADER);    
	bi.biWidth = bmpScreen.bmWidth;    
	bi.biHeight = bmpScreen.bmHeight;  
	// 目标设备的平面数。此值必须设置为1。
	bi.biPlanes = 1; 
	// 位图最多具有2 ^ 32种颜色。如果BITMAPINFOHEADER的biCompression成员为BI_RGB，则BITMAPINFO的bmiColors成员为NULL。
	// 位图数组中的每个DWORD代表一个像素的蓝色，绿色和红色的相对强度。蓝色的值的最低有效8位，然后是绿色和红色的8位。不使用每个DWORD中的高字节。
	// 2 ^ 24种颜色就是真彩色了(24位真彩)，已经可以不使用 BITMAPINFO的bmiColors成员了？？？
	bi.biBitCount = 32;    
	// 自底向上的压缩位图的压缩类型（自顶向下的DIB无法压缩）。BI_RGB	未压缩的格式。
	bi.biCompression = BI_RGB;  
	// 图像的大小（以字节为单位）。对于BI_RGB位图，可以将其设置为零。
	// 如果biCompression为BI_JPEG或BI_PNG，则biSizeImage分别指示JPEG或PNG图像缓冲区的大小。
	bi.biSizeImage = 0;  
	// 位图目标设备的水平分辨率，以每米像素为单位。
	bi.biXPelsPerMeter = 0;    
	// 位图目标设备的垂直分辨率，以每米像素为单位。
	bi.biYPelsPerMeter = 0;  
	// 位图实际使用的颜色表中的颜色索引数。如果此值为零，则对于由biCompression指定的压缩模式，位图将使用与biBitCount成员的值对应的最大颜色数。
	bi.biClrUsed = 0;   
	// 显示位图所需的颜色索引数。如果该值为零，则需要所有颜色。
	bi.biClrImportant = 0;

	// 位图的位数组(bitmap bits) = 像素矩阵宽度（位图宽度）*几个位表示一个像素（biBitCount = 32位 = 4字节）*像素矩阵高度（位图高度）
	// 另外，位图存储时，Windows规定一个扫描行所占的字节数必须是4的倍数(即以long为单位),不足的以0填充
	// 位图的位数组 再转化为 字节数便于内存分配。
	DWORD dwBmpSize = ((bmpScreen.bmWidth * bi.biBitCount + 31) / 32) * 4 * bmpScreen.bmHeight;
	//DWORD dwBmpSize2 = bmpScreen.bmWidth  * 4 * bmpScreen.bmHeight; // 经测试 计算值与上相同

	// Starting with 32-bit Windows, GlobalAlloc and LocalAlloc are implemented as wrapper functions that 
	// call HeapAlloc using a handle to the process's default heap. Therefore, GlobalAlloc and LocalAlloc 
	// have greater overhead than HeapAlloc.
	HANDLE hDIB = GlobalAlloc(GHND,dwBmpSize); 
	char *lpbitmap = (char *)GlobalLock(hDIB);    

	// 5.获取位图位数组数据。
	// 直接从主窗口的compatible bitmap (DDB)获取，并转化为DIB数据？？？
	// 是否可通过 GetDIBits 直接得到 compatible bitmap 的 BITMAPINFO 信息？？？
	// Gets the "bits" from the bitmap and copies them into a buffer 
	// which is pointed to by lpbitmap.
	GetDIBits(hdcWindow, hbmScreen /*Handle to the bitmap. This must be a compatible bitmap (DDB). */, 0,
		(UINT)bmpScreen.bmHeight,
		lpbitmap /*receive the bitmap data. If this parameter is NULL, the function passes the dimensions and format of the bitmap to the BITMAPINFO structure*/,
		(BITMAPINFO *)&bi/*Pointer to a BITMAPINFO structure that specifies the desired format for the DIB data*/, DIB_RGB_COLORS);

	// 6.创建位图文件进行保存。
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