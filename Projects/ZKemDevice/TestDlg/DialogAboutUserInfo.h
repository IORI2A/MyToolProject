#pragma once


// CDialogAboutUserInfo �Ի���

class CDialogAboutUserInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogAboutUserInfo)

public:
	CDialogAboutUserInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogAboutUserInfo();

// �Ի�������
	enum { IDD = IDD_DIALOG_ABOUT_USER_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
