#include "StdAfx.h"
#include "ZkemDeviceBW.h"

#include "Tool.h"



CZkemDeviceBW::CZkemDeviceBW(CWnd* pParentWnd, UINT nID)
    : CZkemDeviceCommon(pParentWnd, nID)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

CZkemDeviceBW::CZkemDeviceBW()
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

CZkemDeviceBW::~CZkemDeviceBW(void)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

BOOL CZkemDeviceBW::SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.SetUserInfo(dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);

	return ret;
}
