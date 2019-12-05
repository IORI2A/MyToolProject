// DialogAboutUserInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "TestDlg.h"
#include "DialogAboutUserInfo.h"
#include "afxdialogex.h"


// CDialogAboutUserInfo 对话框

IMPLEMENT_DYNAMIC(CDialogAboutUserInfo, CDialogEx)

CDialogAboutUserInfo::CDialogAboutUserInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogAboutUserInfo::IDD, pParent)
{

}

CDialogAboutUserInfo::~CDialogAboutUserInfo()
{
}

void CDialogAboutUserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogAboutUserInfo, CDialogEx)
END_MESSAGE_MAP()


// CDialogAboutUserInfo 消息处理程序
