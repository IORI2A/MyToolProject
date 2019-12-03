
// TestDlgDlg.h : 头文件
//

#pragma once
//#include "zkem1.h"
//#include "ZkDevice.h"
#include "afxwin.h"

#include "ZkemDevice.h"


// CTestDlgDlg 对话框
class CTestDlgDlg : public CDialog
{
// 构造
public:
	CTestDlgDlg(CWnd* pParent = NULL);	// 标准构造函数
	// 需要释放动态分配的资源。
	~CTestDlgDlg();

// 对话框数据
	enum { IDD = IDD_TESTDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//CZkDevice m_Zkem;
	CZkemDevice *m_pZkemDevice;
	afx_msg void OnBnClickedButtonConnectNet();
	afx_msg void OnBnClickedButtonDisconnect();
	afx_msg void OnBnClickedButtonPowerOffDevice();
	afx_msg void OnBnClickedButtonRestartDevice();
	afx_msg void OnBnClickedButtonPlayVoice();
	CEdit m_EditMsg;
	afx_msg void OnBnClickedButtonGetDeviceInfo();
	afx_msg void OnBnClickedButtonGetDeviceTime();
	afx_msg void OnBnClickedButtonSetDeviceTime();
	afx_msg void OnBnClickedButtonGetConnectStatus();
	afx_msg void OnBnClickedButtonSearchDevice();
	afx_msg void OnBnClickedButtonGetUserGroup();
	afx_msg void OnBnClickedButtonGetDeviceIp();
	afx_msg void OnBnClickedButtonSetUserGroup();

	void DisplayLastErrorInfor();
	afx_msg void OnBnClickedButtonSetUserInfo();
};
