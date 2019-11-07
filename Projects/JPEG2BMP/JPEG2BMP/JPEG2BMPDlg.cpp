
// JPEG2BMPDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JPEG2BMP.h"
#include "JPEG2BMPDlg.h"
#include "afxdialogex.h"

#include "util.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CJPEG2BMPDlg 对话框




CJPEG2BMPDlg::CJPEG2BMPDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJPEG2BMPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJPEG2BMPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CJPEG2BMPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CJPEG2BMPDlg 消息处理程序

BOOL CJPEG2BMPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 打开图片文件
	FILE *imgFile = fopen("D:\\Photo\\27.jpg","rb");
	if(imgFile)
	{
		fseek(imgFile, 0, SEEK_END);
		long filesize = ftell(imgFile);
		fseek(imgFile, 0, SEEK_SET);

		// 分配足够内存，读取文件数据
		HGLOBAL hFileData=GlobalAlloc(GMEM_MOVEABLE, filesize); 
		if(hFileData) 
		{
			char *pFile =(char *)GlobalLock(hFileData);
			int fsize = fread(pFile, sizeof(char), filesize, imgFile);
			// 读取完成，及时关闭文件
			fclose(imgFile);

			//// 3. CImage 对象加载已经在内存中的图片数据（ IStream 流）。
			//// 指定内存数据，在内存上构建IStream流，CImage再加载IStream流（即加载图片数据）。
			//JPEG2BMP_Memory_CImage(pFile, fsize, &m_image);

			// 5. 使用 GID+ Image Class 将内存中的JPEG二进制数据转换为BMP位图数据。测试OK
			std::string strOutBmp;
			JPEG2BMP_Memory_Image(pFile, fsize, strOutBmp);

			// 再将转换后数据保存为文件，验证转换是否正确。测试OK
			FILE *bmpSaveFile = fopen("D:\\Photo\\27.bmp","wb");
			if(bmpSaveFile)
			{
				int writeSize = fwrite(strOutBmp.c_str(), sizeof(char), strOutBmp.size(), bmpSaveFile);
				fclose(bmpSaveFile);
			}
		} 
	}

	//// 4. 将图片文件另存为另一个文件或者格式。测试OK
	//JPEG2BMP_File_CImage(L"D:\\Photo\\27.jpg", L"D:\\Photo\\27.bmp");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CJPEG2BMPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CJPEG2BMPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//// 1. 简单使用 CImage 加载图片文件进行直接显示。 显示OK
		//CImage backgroudImage;
		//backgroudImage.Load(TEXT("D:\\Photo\\7.jpg"));
		//CRect wndClientRect;
		//this->GetClientRect(&wndClientRect);
		// Draw 会自动拉伸缩放
		//backgroudImage.Draw(this->GetDC()->GetSafeHdc(), wndClientRect);

		//// 通过加载 IStream 流的 CImage 进行显示。 显示OK
		//CRect wndClientRect;
		//this->GetClientRect(&wndClientRect);
		//m_image.Draw(this->GetDC()->GetSafeHdc(), wndClientRect);

		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CJPEG2BMPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

