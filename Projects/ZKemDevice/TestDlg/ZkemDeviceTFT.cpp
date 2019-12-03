#include "StdAfx.h"
#include "ZkemDeviceTFT.h"

#include "Tool.h"



CZkemDeviceTFT::CZkemDeviceTFT(CWnd* pParentWnd, UINT nID)
    : CZkemDeviceCommon(pParentWnd, nID)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

CZkemDeviceTFT::~CZkemDeviceTFT(void)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

BOOL CZkemDeviceTFT::SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	CString strEnrollNumber;
	strEnrollNumber.Format(TEXT("%d"), dwEnrollNumber);
	BOOL ret = m_Zkem1.SSR_SetUserInfo(dwMachineNumber, strEnrollNumber, Name, Password, Privilege, Enabled);

	return FALSE;
}
