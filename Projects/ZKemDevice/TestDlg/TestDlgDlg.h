
// TestDlgDlg.h : ͷ�ļ�
//

#pragma once
//#include "zkem1.h"
//#include "ZkDevice.h"
#include "afxwin.h"

#include "ZkemDevice.h"


// CTestDlgDlg �Ի���
class CTestDlgDlg : public CDialog
{
// ����
public:
	CTestDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��
	// ��Ҫ�ͷŶ�̬�������Դ��
	~CTestDlgDlg();

// �Ի�������
	enum { IDD = IDD_TESTDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
