// DialogAboutUserInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestDlg.h"
#include "DialogAboutUserInfo.h"
#include "afxdialogex.h"


// CDialogAboutUserInfo �Ի���

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


// CDialogAboutUserInfo ��Ϣ�������
