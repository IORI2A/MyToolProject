
// TestDlgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestDlg.h"
#include "TestDlgDlg.h"


#include "Tool.h"
#include "ZkemDeviceBW.h"
#include "ZkemDeviceTFT.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestDlgDlg 对话框




CTestDlgDlg::CTestDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlgDlg::IDD, pParent)
	, m_pZkemDevice(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CTestDlgDlg::~CTestDlgDlg()
{
	// 释放动态分配的资源。
	delete m_pZkemDevice;
	m_pZkemDevice = NULL;
}

void CTestDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_ZKEM1, m_Zkem);
	DDX_Control(pDX, IDC_EDIT_MSG, m_EditMsg);
}

BEGIN_MESSAGE_MAP(CTestDlgDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CONNECT_NET, &CTestDlgDlg::OnBnClickedButtonConnectNet)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CTestDlgDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_POWER_OFF_DEVICE, &CTestDlgDlg::OnBnClickedButtonPowerOffDevice)
	ON_BN_CLICKED(IDC_BUTTON_RESTART_DEVICE, &CTestDlgDlg::OnBnClickedButtonRestartDevice)
	ON_BN_CLICKED(IDC_BUTTON_PLAY_VOICE, &CTestDlgDlg::OnBnClickedButtonPlayVoice)
	ON_BN_CLICKED(IDC_BUTTON_GET_DEVICE_INFO, &CTestDlgDlg::OnBnClickedButtonGetDeviceInfo)
	ON_BN_CLICKED(IDC_BUTTON_GET_DEVICE_TIME, &CTestDlgDlg::OnBnClickedButtonGetDeviceTime)
	ON_BN_CLICKED(IDC_BUTTON_SET_DEVICE_TIME, &CTestDlgDlg::OnBnClickedButtonSetDeviceTime)
	ON_BN_CLICKED(IDC_BUTTON_GET_CONNECT_STATUS, &CTestDlgDlg::OnBnClickedButtonGetConnectStatus)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_DEVICE, &CTestDlgDlg::OnBnClickedButtonSearchDevice)
	ON_BN_CLICKED(IDC_BUTTON_GET_USER_GROUP, &CTestDlgDlg::OnBnClickedButtonGetUserGroup)
	ON_BN_CLICKED(IDC_BUTTON_GET_DEVICE_IP, &CTestDlgDlg::OnBnClickedButtonGetDeviceIp)
	ON_BN_CLICKED(IDC_BUTTON_SET_USER_GROUP, &CTestDlgDlg::OnBnClickedButtonSetUserGroup)
	ON_BN_CLICKED(IDC_BUTTON_SET_USER_INFO, &CTestDlgDlg::OnBnClickedButtonSetUserInfo)
END_MESSAGE_MAP()


// CTestDlgDlg 消息处理程序

BOOL CTestDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	// 使用新的运用继承和动态绑定的ZK设备类体系。
	// BW 设备
	m_pZkemDevice = new CZkemDeviceBW(this, 1810001);
	//// TFT 设备
	//m_pZkemDevice = new CZkemDeviceTFT(this, 1810002);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestDlgDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 使用新的运用继承和动态绑定的ZK设备类体系。

void CTestDlgDlg::OnBnClickedButtonConnectNet()
{
	// TODO: 在此添加控件通知处理程序代码
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始连接设备！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		//m_EditMsg.SetWindowText(buffer);
		m_EditMsg.ReplaceSel(buffer);
	}

	clock_t start = clock();

	BOOL res = m_pZkemDevice->Connect_Net(TEXT("192.168.100.10"), 4370);
	DisplayLastErrorInfor();

	clock_t finish = clock();
	clock_t durationTick = finish - start;
	double durationSec = (double)(finish - start) / CLOCKS_PER_SEC;

	{
		wchar_t buffer[512] = {};
		//wsprintf(buffer,  TEXT("%s 连接设备完成，返回 BOOL res = %d ！ [%d clock ticks, %d seconds]\r\n")
		//	, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s 连接设备完成，返回 BOOL res = %d ！ [%d clock ticks, %f seconds]\r\n")
			, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonDisconnect()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始断开设备！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	m_pZkemDevice->Disconnect();
	DisplayLastErrorInfor();

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 断开设备完成，无返回结果！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonPowerOffDevice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 关机 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->PowerOffDevice(1);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 关机 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonRestartDevice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 重启 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->RestartDevice(1);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 重启 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonPlayVoice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 播放语音 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->PlayVoice(11,12);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 播放语音 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonGetDeviceInfo()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 获取机器相关信息 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwInfo, dwValue;

	dwInfo = 1;
	dwValue = 0;
	BOOL res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.最大管理员数，总是返回500. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 2;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.机器号. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 4; // 4.空闲时长(分钟)，即空闲该段时间后机器进入待机或关机。
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.空闲时长(分钟)，即空闲该段时间后机器进入待机或关机. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	// 13.网络功能是否启用，返回值：1为启用，0为禁用。
	dwInfo = 13;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.网络功能是否启用，返回值：1为启用，0为禁用. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	// 18.空闲方式，即空间时间后进入的状态，返回值：87为关机，88休眠。
	dwInfo = 18;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.空闲方式，即空间时间后进入的状态，返回值：87为关机，88休眠. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//19.自动关机时间点，默认值为255，即不自动关机。
	dwInfo = 19;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动关机时间点，默认值为255，即不自动关机. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//20.自动开机时间点，默认值为 55，即不自动开机。
	dwInfo = 20;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动开机时间点，默认值为 55，即不自动开机. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//21.自动休眠时间点，默认值为255，即不自动休眠。
	dwInfo = 21;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动休眠时间点，默认值为255，即不自动休眠. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//22.自动响铃时间点1，默认值为65535，即不自动响铃。
	dwInfo = 22;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动响铃时间点1，默认值为65535，即不自动响铃. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//36—40.自动响铃时间点2、3、4、5、6 ，默认值都为65535，即不自动响铃。
	dwInfo = 36;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动响铃时间点2、3、4、5、6 ，默认值都为65535，即不自动响铃. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 37;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动响铃时间点2、3、4、5、6 ，默认值都为65535，即不自动响铃. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 38;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动响铃时间点2、3、4、5、6 ，默认值都为65535，即不自动响铃. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 39;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动响铃时间点2、3、4、5、6 ，默认值都为65535，即不自动响铃. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 40;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动响铃时间点2、3、4、5、6 ，默认值都为65535，即不自动响铃. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//41—56.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换。
	dwInfo = 41;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 42;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 43;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 44;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 45;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 46;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 47;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 48;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 49;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 50;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 51;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 52;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 53;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 54;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 55;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 56;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取机器相关信息 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.自动状态转换时间点1—16，默认值都为－1，即不会自动状态转换. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}



}

void CTestDlgDlg::OnBnClickedButtonGetDeviceTime()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 获取设备时间 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond;
	BOOL res = m_pZkemDevice->GetDeviceTime(1, &dwYear, &dwMonth, &dwDay, &dwHour, &dwMinute, &dwSecond);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取设备时间 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 设备时间：%04d-%02d-%02d %02d:%02d:%02d \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonSetDeviceTime()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 把机器时间设置为和本地电脑时间一样 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->SetDeviceTime(1);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 把机器时间设置为和本地电脑时间一样 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonGetConnectStatus()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 获取socket连接状态，目前仅对TCP有效 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwErrorCode;
	m_pZkemDevice->GetConnectStatus(&dwErrorCode);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取socket连接状态，目前仅对TCP有效 操作完成，无返回！ \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwErrorCode = %d. 0成功，-10004~-11000为SOCKET异常，软件无需再重试，可直接重连设备。 \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwErrorCode);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonSearchDevice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 使用网络搜索设备 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	LPCTSTR commType = TEXT("UDP");
	LPCTSTR address  = TEXT("255.255.255.255");
	//BSTR * DevBuffer = NULL;
	BSTR DevBuffer = SysAllocString(L"                                                                                                                                                        ");//SysAllocStringLen(L"xyz", 512);
	long DevBufferSize = 0;
	BOOL res = m_pZkemDevice->SearchDevice(commType, address, &DevBuffer, DevBufferSize);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 使用网络搜索设备 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s DevBuffer = 0X%08X, DevBufferSize = %d \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, DevBuffer, DevBufferSize);
		m_EditMsg.ReplaceSel(buffer);
	}
	SysFreeString(DevBuffer);
}

void CTestDlgDlg::OnBnClickedButtonGetUserGroup()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 获取指定用户所属组号 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwEnrollNumber = 11;
	long UserGrp = 0;
	BOOL res = m_pZkemDevice->GetUserGroup(1, dwEnrollNumber, &UserGrp);
	DisplayLastErrorInfor();

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取指定用户所属组号 操作完成，返回 BOOL res = %d ！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwEnrollNumber = %d, UserGrp = %d \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwEnrollNumber, UserGrp);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonGetDeviceIp()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 获取机器IP地址 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BSTR IPAddr = SysAllocStringLen(NULL, 32);

	clock_t start = clock();

	BOOL res = m_pZkemDevice->GetDeviceIP(1, &IPAddr);
	DisplayLastErrorInfor();

	clock_t finish = clock();
	clock_t durationTick = finish - start;
	double durationSec = (double)(finish - start) / CLOCKS_PER_SEC;

	{
		wchar_t buffer[512] = {};
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s 获取机器IP地址 操作完成，返回 BOOL res = %d ！ [%d clock ticks, %f seconds]\r\n")
			, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s IPAddr = %s \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, IPAddr);
		m_EditMsg.ReplaceSel(buffer);
	}
	SysFreeString(IPAddr);
}

void CTestDlgDlg::OnBnClickedButtonSetUserGroup()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 设置指定用户所属组 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwEnrollNumber = 11;
	static long UserGrp;
	if (1 == UserGrp)
	{
		UserGrp = 2;
	}
	else
	{
		UserGrp = 1;
	}

	clock_t start = clock();

	BOOL res = m_pZkemDevice->SetUserGroup(1, dwEnrollNumber, UserGrp);
	DisplayLastErrorInfor();

	clock_t finish = clock();
	clock_t durationTick = finish - start;
	double durationSec = (double)(finish - start) / CLOCKS_PER_SEC;

	{
		wchar_t buffer[512] = {};
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s 设置指定用户所属组 操作完成，返回 BOOL res = %d ！ [%d clock ticks, %f seconds]\r\n")
			, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwEnrollNumber = %d, UserGrp = %d \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwEnrollNumber, UserGrp);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::DisplayLastErrorInfor()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 获取最后一次错误信息 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	/*
	该参数返回错误码，其含义如下：
	1.在连接过程中，返回错误码为：
	0 连接成功
	-1 调用接口失败
	-2 初始化失败
	-3 初始化参数失败
	-5 读取数据模式错误
	-6 密码错误
	-7 回复错误
	-8 接收超时
	-307 连接超时
	其它接口(包括模板一体化接口)调用中，返回错误码为：
	-201 设备繁忙
	-199 新模式
	-103 设备返回面部模板版本错误
	-102 面部模板数据版本错误(软件上传7.0-8.0dev,8.0-7.0dev) -101 malloc申请分配内存失败
	-100 不支持或数据不存在
	-10 传输的数据长度不对
	-5 数据已经存在
	-4 空间不足
	-3 错误的大小
	-2 文件读写错误
	-1 SDK未初始化，需要重新连接
	0 找不到数据或重复数据
	1 操作正确
	4 参数错误
	101 分配缓冲区错误
	102 重复调用 2.一些底层错误码：
	-12001 创建socket超时(连接超时)
	-12002 内存不足
	-12003 socket版本错误
	-12004 非TCP协议
	-12005 等待超时
	-12006 发送数据超时
	-12007 读取数据超时
	-12008 SOCKET不可读
	-13009 等待信号量错误
	-13010 超过重试次数
	-13011 REPLYID错误
	-13012 校验和错误
	-13013 等待信号量超时
	-13014 DIRTY_DATA
	-13015 buffer size过小
	-13016 读取数据的长度错误
	-13017 无效的读数据1
	-13018 无效的读数据2
	-13019 无效的读数据3
	-13020 丢失数据
	-13021 内存初始化错误
	-15001 调用SetShortkey接口下发状态值重复
	-15002 调用SetShortkey接口下发描述重复
	-15003 二级菜单在设备中未打开，不需要下发
	3.getdevicedata与setdevicedata接口调用错误码
	-15100 获取表结构错误
	-15101 表结构中 条件字段不存在
	-15102 字段总数不一致
	-15103 字段排序不一致
	-15104 内存分配错误
	-15105 解析数据时数据错误
	-15106 下发数据超出4M 数据溢出
	-15108 无效OPTIONS选项
	-15113 解析数据时数据错误,表ID找不到
	-15114 字段数小于等于0，返回数据异常
	-15115 表字段总数和数据本身所指定的字段总数不一致，数据异常
	4.一些固件返回错误
	2000 Return OK to execute
	-2001 Return Fail to execute command
	-2002 Return Data
	-2003 Regstered event occorred
	-2004 Return REPEAT Command
	-2005 Return UNAUTH Command
	0xffff Return Unknown Command
	-4999 读取设备参数错误
	-4998 写入设备参数错误
	-4997 软件发给设备的数据长度错误
	-4996 软件发给设备的参数错误
	-4995 数据库添加操作失败
	-4994 数据库更新操作失败
	-4993 数据库读取操作失败
	-4992 数据库删除操作失败
	-4991 数据库不存在相关数据
	-4990 数据库的数据量已达到设备限制
	-4989 会话分配内存失败
	-4988 会话分配内存空间不足
	-4987 会话分配内存溢出
	-4986 文件不存在
	-4985 文件读取失败
	-4984 文件写入失败
	-4983 哈希值计算失败
	-4982 内存分配失败
	*/
	long dwErrorCode = 0;
	m_pZkemDevice->GetLastError(&dwErrorCode);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 获取最后一次错误信息 操作完成，无返回结果！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwErrorCode = %d \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwErrorCode);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonSetUserInfo()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s 开始对设备进行 设置指定用户的用户信息，若机器内没用该用户，则会创建该用户 操作！\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwMachineNumber = 1;
	long dwEnrollNumber = 11;
	LPCTSTR Name  = TEXT("张世雅典娜");
	LPCTSTR Password  = TEXT("");
	long Privilege = 3;
	BOOL Enabled = 1;

	clock_t start = clock();

	// Privilege
	// 旧架构：0为普通用户，1为登记员，2为管理员，3为超级管理员。
	// 新架构：0为普通用户，1，2,4为自定义用户角色，3超级管理员。
	// Enable参数代表用户是否启用，1为启用，0为禁用。 
	BOOL res = m_pZkemDevice->SetUserInfo(dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
	DisplayLastErrorInfor();

	clock_t finish = clock();
	clock_t durationTick = finish - start;
	double durationSec = (double)(finish - start) / CLOCKS_PER_SEC;

	{
		wchar_t buffer[512] = {};
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s 设置指定用户的用户信息 操作完成，返回 BOOL res = %d ！ [%d clock ticks, %f seconds]\r\n")
			, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwEnrollNumber = %d, Name = %s, Password = %s, Privilege = %d, Enabled = %d \r\n")
			, CTool::GET_W_LOCAL_CURRENT_TIME(), dwEnrollNumber, Name, Password, Privilege, Enabled);
		m_EditMsg.ReplaceSel(buffer);
	}
}
