#include "StdAfx.h"
#include "ZkemDevice.h"

#include "Tool.h"



/////////////////////////////////// CZkemDevice //////////////////////////////////////////////
CZkemDevice::CZkemDevice(CWnd* pParentWnd, UINT nID)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	LPCTSTR lpszWindowName = TEXT("CZkemDevice_Window_Manual");
	// Only a subset of the Windows dwStyle flags are supported for CreateControl: 
	DWORD dwStyle = WS_TABSTOP;
	RECT rect = {7, 7, 7+18, 7+17};

	// 为简化实现，这两个参数由用户通过参数提供。
	//CWnd* pParentWnd = NULL;
	//UINT nID;

	// 使用 Create 创建可支持 new 创建。
	// CZkem1 的 Create 方法调用 CWnd::CreateControl 来创建控件。详情查看 CWnd::CreateControl 帮助。
	m_Zkem1.Create(lpszWindowName, dwStyle, rect, pParentWnd, nID
		/*, CFile* pPersist = NULL, BOOL bStorage = FALSE, BSTR bstrLicKey = NULL*/);
}

// 提供自动增长分配控件ID。
// 粗略查看 winuser.h 中定义最大ID是 #define     OBJID_SYSMENU       ((LONG)0xFFFFFFFF)
// Resource.h 中一般是以 1000 开始。 为避免冲突自动增长基数初步设定为 0XFFFF (65535)。
UINT CZkemDevice::m_nStaticAutoID = 0XFFFF;
// 提供支持默认构造，简化后续使用代码的编写。 默认构造父窗口即为主窗口，控件ID自动增长分配。
CZkemDevice::CZkemDevice()
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	LPCTSTR lpszWindowName = TEXT("CZkemDevice_Window_Auto");
	DWORD dwStyle = WS_TABSTOP;
	RECT rect = {7, 7, 7+18, 7+17};
	CWnd* pParentWnd = ::AfxGetMainWnd();
	UINT nID = ++m_nStaticAutoID;
	m_Zkem1.Create(lpszWindowName, dwStyle, rect, pParentWnd, nID);

	// 进行记录标记，方便用于分析区别。
	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("LPCTSTR lpszWindowName = %s, CWnd* pParentWnd = %08X , UINT nID = %d"
		, "CZkemDevice_Window_Auto", pParentWnd, nID);
}

CZkemDevice::~CZkemDevice(void)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}


/////////////////////////////////// CZkemDeviceCommon //////////////////////////////////////////////
CZkemDeviceCommon::CZkemDeviceCommon(CWnd* pParentWnd, UINT nID)
    : CZkemDevice(pParentWnd, nID)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

CZkemDeviceCommon::CZkemDeviceCommon()
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

CZkemDeviceCommon::~CZkemDeviceCommon(void)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

/////////////////////////// 调用 ZKEM 接口 /////////////////////////
BOOL CZkemDeviceCommon::IsTFTMachine(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.IsTFTMachine(dwMachineNumber);

	return ret;
}

BOOL CZkemDeviceCommon::Connect_Net(LPCTSTR IPAdd, long Port)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.Connect_Net(IPAdd, Port);

	return ret;
}

void CZkemDeviceCommon::Disconnect()
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	m_Zkem1.Disconnect();
}

BOOL CZkemDeviceCommon::PowerOffDevice(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.PowerOffDevice(dwMachineNumber);

	return ret;
}

BOOL CZkemDeviceCommon::RestartDevice(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.RestartDevice(dwMachineNumber);

	return ret;
}

BOOL CZkemDeviceCommon::PlayVoice(long Position, long Length)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.PlayVoice(Position, Length);

	return ret;
}

BOOL CZkemDeviceCommon::GetDeviceInfo(long dwMachineNumber, long dwInfo, long * dwValue)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.GetDeviceInfo(dwMachineNumber, dwInfo, dwValue);

	return ret;
}

BOOL CZkemDeviceCommon::GetDeviceTime(long dwMachineNumber, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.GetDeviceTime(dwMachineNumber, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);

	return ret;
}

BOOL CZkemDeviceCommon::SetDeviceTime(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.SetDeviceTime(dwMachineNumber);

	return ret;
}

void CZkemDeviceCommon::GetConnectStatus(long * dwErrorCode)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	m_Zkem1.GetConnectStatus(dwErrorCode);
}

BOOL CZkemDeviceCommon::SearchDevice(LPCTSTR commType, LPCTSTR address, BSTR * DevBuffer, long DevBufferSize)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.SearchDevice(commType, address, DevBuffer, DevBufferSize);

	return ret;
}

BOOL CZkemDeviceCommon::GetUserGroup(long dwMachineNumber, long dwEnrollNumber, long * UserGrp)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.GetUserGroup(dwMachineNumber, dwEnrollNumber, UserGrp);

	return ret;
}

BOOL CZkemDeviceCommon::GetDeviceIP(long dwMachineNumber, BSTR * IPAddr)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.GetDeviceIP(dwMachineNumber, IPAddr);

	return ret;
}

BOOL CZkemDeviceCommon::SetUserGroup(long dwMachineNumber, long dwEnrollNumber, long UserGrp)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.SetUserGroup(dwMachineNumber, dwEnrollNumber, UserGrp);

	return ret;
}

void CZkemDeviceCommon::GetLastError(long * dwErrorCode)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	m_Zkem1.GetLastError(dwErrorCode);
}

BOOL CZkemDeviceCommon::SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = FALSE;

	// 该方法接口对于各种设备类型不一致，该类不实现，由具体子类实现。
	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("SetUserInfo 方法接口对于各种设备类型不一致，该类不实现，由子类实现。");
	ASSERT(false);

	return ret;
}

BOOL CZkemDeviceCommon::ClearKeeperData(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.ClearKeeperData(dwMachineNumber);

	return ret;
}

BOOL CZkemDeviceCommon::RefreshData(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.RefreshData(dwMachineNumber);

	return ret;
}

BOOL CZkemDeviceCommon::SetStrCardNumber(LPCTSTR ACardNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.SetStrCardNumber(ACardNumber);

	return ret;
}

BOOL CZkemDeviceCommon::EnableDevice(long dwMachineNumber, BOOL bFlag)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.EnableDevice(dwMachineNumber, bFlag);

	return ret;
}

BOOL CZkemDeviceCommon::ReadAllUserID(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = m_Zkem1.ReadAllUserID(dwMachineNumber);

	return ret;
}

BOOL CZkemDeviceCommon::GetAllUserInfo(long dwMachineNumber, long * dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = FALSE;

	// 该方法接口对于各种设备类型不一致，该类不实现，由具体子类实现。
	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("GetAllUserInfo 方法接口对于各种设备类型不一致，该类不实现，由子类实现。");
	ASSERT(false);

	return ret;
}