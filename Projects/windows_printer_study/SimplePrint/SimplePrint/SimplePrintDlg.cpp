
// SimplePrintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SimplePrint.h"
#include "SimplePrintDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CSimplePrintDlg dialog




CSimplePrintDlg::CSimplePrintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSimplePrintDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimplePrintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSimplePrintDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CSimplePrintDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSimplePrintDlg message handlers

BOOL CSimplePrintDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSimplePrintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSimplePrintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSimplePrintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// GetDefaultPrinter
#include <Winspool.h>

void CSimplePrintDlg::OnBnClickedButton1()
{
	//// WIN32 方式，通过使用 PRINTDLG 和 PrintDlg 显示打印对话框。

	//// MSDN: 
	//// Win32 and COM Development
	//// User Interface
	//// Windows User Experience
	//// Windwos Management
	//// Windows User Interface
	//// User Input
	//// Common Dialog Box Library
	//// Common Dialog Box Library Overviews
	//// Using Common Dialog Boxes 

	//PRINTDLG pd;
	//HWND hwnd;

	//// Initialize PRINTDLG
	//ZeroMemory(&pd, sizeof(pd));
	//pd.lStructSize = sizeof(pd);
	////pd.hwndOwner   = hwnd;
	//pd.hwndOwner   = GetSafeHwnd();
	//pd.hDevMode    = NULL;     // Don't forget to free or store hDevMode
	//pd.hDevNames   = NULL;     // Don't forget to free or store hDevNames
	//pd.Flags       = PD_USEDEVMODECOPIESANDCOLLATE | PD_RETURNDC; 
	//pd.nCopies     = 1;
	//pd.nFromPage   = 0xFFFF; 
	//pd.nToPage     = 0xFFFF; 
	//pd.nMinPage    = 1; 
	//pd.nMaxPage    = 0xFFFF; 

	//BOOL bRet = PrintDlg(&pd);
	//CString strDebugInfor;
	//strDebugInfor.Format(TEXT("bRet = %d"), bRet);
	//::AfxMessageBox(strDebugInfor);
	////if (PrintDlg(&pd)==TRUE) 
	//if(TRUE == bRet)
	//{
	//	// GDI calls to render output. 

	//	// Delete DC when done.
	//	DeleteDC(pd.hDC);
	//}

	// 获取默认打印机名称 GetDefaultPrinter 。

	// GetDefaultPrinter
	const DWORD BufferLen = 256;
	TCHAR Buffer[BufferLen] = {};
	DWORD RecievBufferLen = 256;
	BOOL bGetDefaultPrinter = GetDefaultPrinter(Buffer, &RecievBufferLen);
	{
		CString strDebugInfor;
		strDebugInfor.Format(TEXT("bGetDefaultPrinter = %d, Buffer[%d] = %s")
			, bGetDefaultPrinter, RecievBufferLen, Buffer);
		::AfxMessageBox(strDebugInfor);
	}

	// 通过打印机名称获取打印机句柄 HANDLE 。

	// MSDN: 
	// Win32 and COM Development
	// Graphics and Multimedia
	// GDI
	// Windwos GDI
	// Printing and Print Spooler
	// About Printing
	// Printer Output

	// If you call the CreateDC function, you must supply a driver and port name. To retrieve these names, call the GetPrinter or EnumPrinters function. 

	LPTSTR pPrinterName = Buffer;
	HANDLE hPrinter = NULL;
	PRINTER_DEFAULTS stPrinterDefault;
	ZeroMemory(&stPrinterDefault, sizeof(stPrinterDefault));
	BOOL bOpenPrinter = OpenPrinter(pPrinterName, &hPrinter, &stPrinterDefault);
	{
		CString strDebugInfor;
		strDebugInfor.Format(TEXT("bOpenPrinter = %d, pPrinterName = %s, hPrinter = 0X%08X") \
			TEXT(", PRINTER_DEFAULTS stPrinterDefault {pDatatype = 0X%08X, pDevMode = %s, DesiredAccess = 0X%08X}") 
			, bOpenPrinter, pPrinterName, hPrinter
			, stPrinterDefault.pDatatype, stPrinterDefault.pDevMode, stPrinterDefault.DesiredAccess);
		::AfxMessageBox(strDebugInfor);
	}

	// 通过 GetPrinter 和 打印机句柄 HANDLE ，获取打印机的驱动和端口信息。(level = 2, A PRINTER_INFO_2 structure containing detailed information about the printer.)
	
	// 获取需要的缓冲区长度
	BYTE TempPrinterInfor[1] = {};
	DWORD cbBuf = 0;
	DWORD cbNeeded = 0;
	BOOL bGetPrinter = GetPrinter(hPrinter, 2, TempPrinterInfor, cbBuf, &cbNeeded);
	{
		CString strDebugInfor;
		strDebugInfor.Format(TEXT("bGetPrinter = %d, hPrinter = 0X%08X") \
			TEXT(", PrinterInfor = 0X%08X, cbBuf = %d, cbNeeded = %d") 
			, bGetPrinter, hPrinter
			, TempPrinterInfor, cbBuf, cbNeeded);
		::AfxMessageBox(strDebugInfor);
	}

	cbBuf = cbNeeded;
	LPBYTE pPrinterInfor = new BYTE[cbBuf]();
	bGetPrinter = GetPrinter(hPrinter, 2, pPrinterInfor, cbBuf, &cbNeeded);
	{
		CString strDebugInfor;
		strDebugInfor.Format(TEXT("bGetPrinter = %d, hPrinter = 0X%08X") \
			TEXT(", PrinterInfor = 0X%08X, cbBuf = %d, cbNeeded = %d") 
			, bGetPrinter, hPrinter
			, pPrinterInfor, cbBuf, cbNeeded);
		::AfxMessageBox(strDebugInfor);
	}

	//typedef struct _PRINTER_INFO_2 {
	//	LPTSTR    pServerName;
	//	LPTSTR    pPrinterName;
	//	LPTSTR    pShareName;
	//	LPTSTR    pPortName;
	//	LPTSTR    pDriverName;
	//	LPTSTR    pComment;
	//	LPTSTR    pLocation;
	//	LPDEVMODE pDevMode;
	//	LPTSTR    pSepFile;
	//	LPTSTR    pPrintProcessor;
	//	LPTSTR    pDatatype;
	//	LPTSTR    pParameters;
	//	PSECURITY_DESCRIPTOR pSecurityDescriptor;
	//	DWORD     Attributes;
	//	DWORD     Priority;
	//	DWORD     DefaultPriority;
	//	DWORD     StartTime;
	//	DWORD     UntilTime;
	//	DWORD     Status;
	//	DWORD     cJobs;
	//	DWORD     AveragePPM;
	//} PRINTER_INFO_2, *PPRINTER_INFO_2; 

	PPRINTER_INFO_2 p = (PPRINTER_INFO_2)pPrinterInfor;
	{
		CString strDebugInfor;
		strDebugInfor.Format(TEXT("PRINTER_INFO_2 {pDriverName = %s, pPortName = %s}")
			, p->pDriverName, p->pPortName);
		::AfxMessageBox(strDebugInfor);
	}

	// 不使用界面交互（打印对话框）。 想实现后台隐藏打印。 使用 CreateDC 来创建打印机的 DC 。

	LPCTSTR lpszDriver = p->pDriverName;
	LPCTSTR lpszDevice = pPrinterName;
	LPCTSTR lpszOutput = p->pPortName;
	CONST DEVMODE* lpInitData = NULL;
	HDC hPrinterDC = CreateDC(lpszDriver, lpszDevice, lpszOutput, lpInitData);
	{
		CString strDebugInfor;
		strDebugInfor.Format(TEXT("hPrinterDC = 0X%08X, lpszDriver= %s, lpszDevice = %s, lpszOutput = %s, lpInitData = 0X%08X")
			, hPrinterDC, lpszDriver, lpszDevice, lpszOutput, lpInitData);
		::AfxMessageBox(strDebugInfor);
	}


	// MSDN: 
	// Win32 and COM Development
	// Graphics and Multimedia
	// GDI
	// Windwos GDI
	// Printing and Print Spooler
	// Using the Printing Functions
	// Printing a Document

	DOCINFO di;
	PRINTDLG pd;
	ZeroMemory(&pd, sizeof(pd));
	pd.hDC = hPrinterDC; 
	CString strTextOut;

	// Zero and then initialize the members of a DOCINFO structure. 

	memset( &di, 0, sizeof(DOCINFO) );
	di.cbSize = sizeof(DOCINFO); 
	di.lpszDocName = (LPCTSTR)TEXT("Bitmap Printing Test"); 
	di.lpszOutput = (LPTSTR) NULL; 
	di.lpszDatatype = (LPTSTR) NULL; 
	di.fwType = 0; 

	// Begin a print job by calling the StartDoc function. 

	int nError = StartDoc(pd.hDC, &di); 
	if (nError == SP_ERROR) 
	{ 
		//errhandler((LPCTSTR)TEXT("StartDoc"), hWnd); 
		::AfxMessageBox(TEXT("1111"));
		goto Error; 
	} 

	// Inform the driver that the application is about to begin 
	// sending data. 

	nError = StartPage(pd.hDC); 
	if (nError <= 0) 
	{ 
		//errhandler((LPCTSTR)TEXT("StartPage"), hWnd); 
		::AfxMessageBox(TEXT("2222"));
		goto Error; 
	} 

	//// Retrieve the number of pixels-per-logical-inch in the 
	//// horizontal and vertical directions for the display upon which 
	//// the bitmap was created. These are likely the same as for 
	//// the present display, so we use those values here. 

	////hWinDC = GetDC(hWnd);
	//HDC hWinDC = GetDC(GetSafeHwnd());
	//float fLogPelsX1 = (float) GetDeviceCaps(hWinDC, LOGPIXELSX); 
	//float fLogPelsY1 = (float) GetDeviceCaps(hWinDC, LOGPIXELSY); 

	//// Retrieve the number of pixels-per-logical-inch in the 
	//// horizontal and vertical directions for the printer upon which 
	//// the bitmap will be printed. 

	//float fLogPelsX2 = (float) GetDeviceCaps(pd.hDC, LOGPIXELSX); 
	//float fLogPelsY2 = (float) GetDeviceCaps(pd.hDC, LOGPIXELSY); 

	//// Determine the scaling factors required to print the bitmap and 
	//// retain its original proportions. 

	//float fScaleX;
	//float fScaleY;
	//if (fLogPelsX1 > fLogPelsX2) 
	//	fScaleX = (fLogPelsX1 / fLogPelsX2); 
	//else fScaleX = (fLogPelsX2 / fLogPelsX1); 

	//if (fLogPelsY1 > fLogPelsY2) 
	//	fScaleY = (fLogPelsY1 / fLogPelsY2); 
	//else fScaleY = (fLogPelsY2 / fLogPelsY1); 

	//// Compute the coordinates of the upper left corner of the 
	//// centered bitmap. 

	//int cWidthPels = GetDeviceCaps(pd.hDC, HORZRES); 
	//float xLeft = ((cWidthPels / 2) - ((int) (((float) bmih.biWidth) 
	//	* fScaleX)) / 2); 
	//int cHeightPels = GetDeviceCaps(pd.hDC, VERTRES); 
	//float yTop = ((cHeightPels / 2) - ((int) (((float) bmih.biHeight) 
	//	* fScaleY)) / 2); 

	//// Use StretchDIBits to scale the bitmap and maintain 
	//// its original proportions (that is, if the bitmap was square 
	//// when it appeared in the application's client area, it should 
	//// also appear square on the page). 

	//if (StretchDIBits(pd.hDC, xLeft, yTop, (int) ((float) bmih.biWidth 
	//	* fScaleX), (int) ((float) bmih.biHeight * fScaleY), 0, 0, 
	//	bmih.biWidth, bmih.biHeight, lpBits, lpBitsInfo, iUsage, 
	//	SRCCOPY) == GDI_ERROR) 
	//{
	//	errhandler((LPCTSTR)TEXT("StretchDIBits Failed"), hWnd); 
	//}


	//// Retrieve the width of the string that specifies the full path 
	//// and filename for the file that contains the bitmap. 

	//GetTextExtentPoint32W(pd.hDC, ofn.lpstrFile, 
	//	ofn.nFileExtension + 3, &szMetric); 

	//// Compute the starting point for the text-output operation. The 
	//// string will be centered horizontally and positioned three lines 
	//// down from the top of the page. 

	//xLeft = ((cWidthPels / 2) - (szMetric.cx / 2)); 
	//yTop = (szMetric.cy * 3); 

	//// Print the path and filename for the bitmap, centered at the top 
	//// of the page. 

	//TextOut(pd.hDC, xLeft, yTop, ofn.lpstrFile, 
	//	ofn.nFileExtension + 3); 
	strTextOut = TEXT("Compute the starting point for the text-output operation. ");
	TextOut(pd.hDC, 10, 10, strTextOut, strTextOut.GetLength()); 

	//// Determine whether the user has pressed the Cancel button in the 
	//// AbortPrintJob dialog box; if the button has been pressed, call 
	//// the AbortDoc function. Otherwise, inform the spooler that the 
	//// page is complete. 

	nError = EndPage(pd.hDC); 

	if (nError <= 0) 
	{ 
		//errhandler((LPCTSTR)TEXT("EndPage"), hWnd);
		::AfxMessageBox(TEXT("3333"));
		goto Error; 
	} 

	// Inform the driver that document has ended. 

	nError = EndDoc(pd.hDC); 
	if (nError <= 0) 
		//errhandler((LPCTSTR)TEXT("EndDoc"), hWnd); 
		::AfxMessageBox(TEXT("4444"));

Error: 
	//// Enable the application's window. 

	//EnableWindow(hWnd, TRUE); 

	//// Remove the AbortPrintJob dialog box. 

	//DestroyWindow(hdlgCancel); 

	// Delete the printer DC. 

	DeleteDC(pd.hDC); 
}
