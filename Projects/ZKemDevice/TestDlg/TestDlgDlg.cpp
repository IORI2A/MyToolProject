
// TestDlgDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTestDlgDlg �Ի���




CTestDlgDlg::CTestDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlgDlg::IDD, pParent)
	, m_pZkemDevice(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CTestDlgDlg::~CTestDlgDlg()
{
	// �ͷŶ�̬�������Դ��
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


// CTestDlgDlg ��Ϣ�������

BOOL CTestDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	// ʹ���µ����ü̳кͶ�̬�󶨵�ZK�豸����ϵ��
	// BW �豸
	m_pZkemDevice = new CZkemDeviceBW(this, 1810001);
	//// TFT �豸
	//m_pZkemDevice = new CZkemDeviceTFT(this, 1810002);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestDlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ʹ���µ����ü̳кͶ�̬�󶨵�ZK�豸����ϵ��

void CTestDlgDlg::OnBnClickedButtonConnectNet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ�����豸��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
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
		//wsprintf(buffer,  TEXT("%s �����豸��ɣ����� BOOL res = %d �� [%d clock ticks, %d seconds]\r\n")
		//	, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s �����豸��ɣ����� BOOL res = %d �� [%d clock ticks, %f seconds]\r\n")
			, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonDisconnect()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ�Ͽ��豸��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	m_pZkemDevice->Disconnect();
	DisplayLastErrorInfor();

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s �Ͽ��豸��ɣ��޷��ؽ����\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonPowerOffDevice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� �ػ� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->PowerOffDevice(1);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s �ػ� ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonRestartDevice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ���� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->RestartDevice(1);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ���� ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonPlayVoice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� �������� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->PlayVoice(11,12);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s �������� ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonGetDeviceInfo()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ��ȡ���������Ϣ ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwInfo, dwValue;

	dwInfo = 1;
	dwValue = 0;
	BOOL res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.������Ա�������Ƿ���500. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 2;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.������. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 4; // 4.����ʱ��(����)�������иö�ʱ���������������ػ���
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.����ʱ��(����)�������иö�ʱ���������������ػ�. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	// 13.���繦���Ƿ����ã�����ֵ��1Ϊ���ã�0Ϊ���á�
	dwInfo = 13;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.���繦���Ƿ����ã�����ֵ��1Ϊ���ã�0Ϊ����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	// 18.���з�ʽ�����ռ�ʱ�������״̬������ֵ��87Ϊ�ػ���88���ߡ�
	dwInfo = 18;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.���з�ʽ�����ռ�ʱ�������״̬������ֵ��87Ϊ�ػ���88����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//19.�Զ��ػ�ʱ��㣬Ĭ��ֵΪ255�������Զ��ػ���
	dwInfo = 19;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ��ػ�ʱ��㣬Ĭ��ֵΪ255�������Զ��ػ�. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//20.�Զ�����ʱ��㣬Ĭ��ֵΪ 55�������Զ�������
	dwInfo = 20;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ��㣬Ĭ��ֵΪ 55�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//21.�Զ�����ʱ��㣬Ĭ��ֵΪ255�������Զ����ߡ�
	dwInfo = 21;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ��㣬Ĭ��ֵΪ255�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//22.�Զ�����ʱ���1��Ĭ��ֵΪ65535�������Զ����塣
	dwInfo = 22;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ���1��Ĭ��ֵΪ65535�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//36��40.�Զ�����ʱ���2��3��4��5��6 ��Ĭ��ֵ��Ϊ65535�������Զ����塣
	dwInfo = 36;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ���2��3��4��5��6 ��Ĭ��ֵ��Ϊ65535�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 37;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ���2��3��4��5��6 ��Ĭ��ֵ��Ϊ65535�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 38;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ���2��3��4��5��6 ��Ĭ��ֵ��Ϊ65535�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 39;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ���2��3��4��5��6 ��Ĭ��ֵ��Ϊ65535�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 40;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�����ʱ���2��3��4��5��6 ��Ĭ��ֵ��Ϊ65535�������Զ�����. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	//41��56.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת����
	dwInfo = 41;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 42;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 43;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 44;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 45;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 46;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 47;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 48;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 49;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 50;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 51;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 52;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 53;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 54;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 55;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}

	dwInfo = 56;
	dwValue = 0;
	res = m_pZkemDevice->GetDeviceInfo(1,dwInfo, &dwValue);
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���������Ϣ ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwInfo = %d, dwValue = %d.�Զ�״̬ת��ʱ���1��16��Ĭ��ֵ��Ϊ��1���������Զ�״̬ת��. \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwInfo, dwValue);
		m_EditMsg.ReplaceSel(buffer);
	}



}

void CTestDlgDlg::OnBnClickedButtonGetDeviceTime()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ��ȡ�豸ʱ�� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond;
	BOOL res = m_pZkemDevice->GetDeviceTime(1, &dwYear, &dwMonth, &dwDay, &dwHour, &dwMinute, &dwSecond);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ�豸ʱ�� ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s �豸ʱ�䣺%04d-%02d-%02d %02d:%02d:%02d \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonSetDeviceTime()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� �ѻ���ʱ������Ϊ�ͱ��ص���ʱ��һ�� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	BOOL res = m_pZkemDevice->SetDeviceTime(1);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s �ѻ���ʱ������Ϊ�ͱ��ص���ʱ��һ�� ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonGetConnectStatus()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ��ȡsocket����״̬��Ŀǰ����TCP��Ч ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwErrorCode;
	m_pZkemDevice->GetConnectStatus(&dwErrorCode);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡsocket����״̬��Ŀǰ����TCP��Ч ������ɣ��޷��أ� \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s dwErrorCode = %d. 0�ɹ���-10004~-11000ΪSOCKET�쳣��������������ԣ���ֱ�������豸�� \r\n"), CTool::GET_W_LOCAL_CURRENT_TIME()
			, dwErrorCode);
		m_EditMsg.ReplaceSel(buffer);
	}
}

void CTestDlgDlg::OnBnClickedButtonSearchDevice()
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ʹ�����������豸 ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
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
		wsprintf(buffer,  TEXT("%s ʹ�����������豸 ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
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
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ��ȡָ���û�������� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwEnrollNumber = 11;
	long UserGrp = 0;
	BOOL res = m_pZkemDevice->GetUserGroup(1, dwEnrollNumber, &UserGrp);
	DisplayLastErrorInfor();

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡָ���û�������� ������ɣ����� BOOL res = %d ��\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME(), res);
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
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ��ȡ����IP��ַ ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
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
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s ��ȡ����IP��ַ ������ɣ����� BOOL res = %d �� [%d clock ticks, %f seconds]\r\n")
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
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ����ָ���û������� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
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
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s ����ָ���û������� ������ɣ����� BOOL res = %d �� [%d clock ticks, %f seconds]\r\n")
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
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ��ȡ���һ�δ�����Ϣ ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	/*
	�ò������ش����룬�京�����£�
	1.�����ӹ����У����ش�����Ϊ��
	0 ���ӳɹ�
	-1 ���ýӿ�ʧ��
	-2 ��ʼ��ʧ��
	-3 ��ʼ������ʧ��
	-5 ��ȡ����ģʽ����
	-6 �������
	-7 �ظ�����
	-8 ���ճ�ʱ
	-307 ���ӳ�ʱ
	�����ӿ�(����ģ��һ�廯�ӿ�)�����У����ش�����Ϊ��
	-201 �豸��æ
	-199 ��ģʽ
	-103 �豸�����沿ģ��汾����
	-102 �沿ģ�����ݰ汾����(����ϴ�7.0-8.0dev,8.0-7.0dev) -101 malloc��������ڴ�ʧ��
	-100 ��֧�ֻ����ݲ�����
	-10 ��������ݳ��Ȳ���
	-5 �����Ѿ�����
	-4 �ռ䲻��
	-3 ����Ĵ�С
	-2 �ļ���д����
	-1 SDKδ��ʼ������Ҫ��������
	0 �Ҳ������ݻ��ظ�����
	1 ������ȷ
	4 ��������
	101 ���仺��������
	102 �ظ����� 2.һЩ�ײ�����룺
	-12001 ����socket��ʱ(���ӳ�ʱ)
	-12002 �ڴ治��
	-12003 socket�汾����
	-12004 ��TCPЭ��
	-12005 �ȴ���ʱ
	-12006 �������ݳ�ʱ
	-12007 ��ȡ���ݳ�ʱ
	-12008 SOCKET���ɶ�
	-13009 �ȴ��ź�������
	-13010 �������Դ���
	-13011 REPLYID����
	-13012 У��ʹ���
	-13013 �ȴ��ź�����ʱ
	-13014 DIRTY_DATA
	-13015 buffer size��С
	-13016 ��ȡ���ݵĳ��ȴ���
	-13017 ��Ч�Ķ�����1
	-13018 ��Ч�Ķ�����2
	-13019 ��Ч�Ķ�����3
	-13020 ��ʧ����
	-13021 �ڴ��ʼ������
	-15001 ����SetShortkey�ӿ��·�״ֵ̬�ظ�
	-15002 ����SetShortkey�ӿ��·������ظ�
	-15003 �����˵����豸��δ�򿪣�����Ҫ�·�
	3.getdevicedata��setdevicedata�ӿڵ��ô�����
	-15100 ��ȡ��ṹ����
	-15101 ��ṹ�� �����ֶβ�����
	-15102 �ֶ�������һ��
	-15103 �ֶ�����һ��
	-15104 �ڴ�������
	-15105 ��������ʱ���ݴ���
	-15106 �·����ݳ���4M �������
	-15108 ��ЧOPTIONSѡ��
	-15113 ��������ʱ���ݴ���,��ID�Ҳ���
	-15114 �ֶ���С�ڵ���0�����������쳣
	-15115 ���ֶ����������ݱ�����ָ�����ֶ�������һ�£������쳣
	4.һЩ�̼����ش���
	2000 Return OK to execute
	-2001 Return Fail to execute command
	-2002 Return Data
	-2003 Regstered event occorred
	-2004 Return REPEAT Command
	-2005 Return UNAUTH Command
	0xffff Return Unknown Command
	-4999 ��ȡ�豸��������
	-4998 д���豸��������
	-4997 ��������豸�����ݳ��ȴ���
	-4996 ��������豸�Ĳ�������
	-4995 ���ݿ���Ӳ���ʧ��
	-4994 ���ݿ���²���ʧ��
	-4993 ���ݿ��ȡ����ʧ��
	-4992 ���ݿ�ɾ������ʧ��
	-4991 ���ݿⲻ�����������
	-4990 ���ݿ���������Ѵﵽ�豸����
	-4989 �Ự�����ڴ�ʧ��
	-4988 �Ự�����ڴ�ռ䲻��
	-4987 �Ự�����ڴ����
	-4986 �ļ�������
	-4985 �ļ���ȡʧ��
	-4984 �ļ�д��ʧ��
	-4983 ��ϣֵ����ʧ��
	-4982 �ڴ����ʧ��
	*/
	long dwErrorCode = 0;
	m_pZkemDevice->GetLastError(&dwErrorCode);

	{
		wchar_t buffer[512] = {};
		wsprintf(buffer,  TEXT("%s ��ȡ���һ�δ�����Ϣ ������ɣ��޷��ؽ����\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
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
		wsprintf(buffer,  TEXT("%s ��ʼ���豸���� ����ָ���û����û���Ϣ����������û�ø��û�����ᴴ�����û� ������\r\n"), CTool::GET_W_LOCAL_CURRENT_TIME());
		m_EditMsg.ReplaceSel(buffer);
	}

	long dwMachineNumber = 1;
	long dwEnrollNumber = 11;
	LPCTSTR Name  = TEXT("�����ŵ���");
	LPCTSTR Password  = TEXT("");
	long Privilege = 3;
	BOOL Enabled = 1;

	clock_t start = clock();

	// Privilege
	// �ɼܹ���0Ϊ��ͨ�û���1Ϊ�Ǽ�Ա��2Ϊ����Ա��3Ϊ��������Ա��
	// �¼ܹ���0Ϊ��ͨ�û���1��2,4Ϊ�Զ����û���ɫ��3��������Ա��
	// Enable���������û��Ƿ����ã�1Ϊ���ã�0Ϊ���á� 
	BOOL res = m_pZkemDevice->SetUserInfo(dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
	DisplayLastErrorInfor();

	clock_t finish = clock();
	clock_t durationTick = finish - start;
	double durationSec = (double)(finish - start) / CLOCKS_PER_SEC;

	{
		wchar_t buffer[512] = {};
		swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s ����ָ���û����û���Ϣ ������ɣ����� BOOL res = %d �� [%d clock ticks, %f seconds]\r\n")
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
