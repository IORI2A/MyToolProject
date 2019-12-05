#pragma once


// CDialogAboutUserInfo 对话框

class CDialogAboutUserInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogAboutUserInfo)

public:
	CDialogAboutUserInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogAboutUserInfo();

// 对话框数据
	enum { IDD = IDD_DIALOG_ABOUT_USER_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
