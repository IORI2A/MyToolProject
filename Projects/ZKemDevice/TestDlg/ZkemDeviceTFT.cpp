#include "StdAfx.h"
#include "ZkemDeviceTFT.h"

#include "Tool.h"



CZkemDeviceTFT::CZkemDeviceTFT(CWnd* pParentWnd, UINT nID)
    : CZkemDeviceCommon(pParentWnd, nID)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

CZkemDeviceTFT::CZkemDeviceTFT()
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

	return ret;
}

BOOL CZkemDeviceTFT::GetAllUserInfo(long dwMachineNumber, long * dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	CString strEnrollNumber;
	strEnrollNumber.Format(TEXT("%d"), *dwEnrollNumber);
	BSTR bstrEnrollNumber = strEnrollNumber.AllocSysString();	
	BOOL ret = m_Zkem1.SSR_GetAllUserInfo(dwMachineNumber, &bstrEnrollNumber, Name, Password, Privilege, Enabled);

	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("dwEnrollNumber = %d, Name = %s, Password = %s, Privilege = %d, Enabled = %d"
		, *dwEnrollNumber, _com_util::ConvertBSTRToString(*Name), _com_util::ConvertBSTRToString(*Password), *Privilege, *Enabled);

	::SysFreeString(bstrEnrollNumber);

	return ret;
}
