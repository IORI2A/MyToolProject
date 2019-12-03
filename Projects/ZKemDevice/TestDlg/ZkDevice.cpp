// ZkDevice.cpp : 实现文件
//

#include "stdafx.h"
#include "TestDlg.h"
#include "ZkDevice.h"


#include "Tool.h"



// CZkDevice

IMPLEMENT_DYNAMIC(CZkDevice, CZkem1)

CZkDevice::CZkDevice()
//    : m_bIsTFT(FALSE)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	// 在构造实体控件之前调用控件方法 异常。
	//long dwMachineNumber = 1;
	//m_bIsTFT = IsTFTMachine(dwMachineNumber);
}

CZkDevice::~CZkDevice()
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}


BEGIN_MESSAGE_MAP(CZkDevice, CZkem1)
END_MESSAGE_MAP()



// CZkDevice 消息处理程序


/////////////////////////// 调用 ZKEM 接口 /////////////////////////
BOOL CZkDevice::Connect_Net(LPCTSTR IPAdd, long Port)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::Connect_Net(IPAdd, Port);

	return ret;
}

void CZkDevice::Disconnect()
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	CZkem1::Disconnect();
}

BOOL CZkDevice::PowerOffDevice(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::PowerOffDevice(dwMachineNumber);

	return ret;
}

BOOL CZkDevice::RestartDevice(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::RestartDevice(dwMachineNumber);

	return ret;
}

BOOL CZkDevice::PlayVoice(long Position, long Length)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::PlayVoice(Position, Length);

	return ret;
}

BOOL CZkDevice::GetDeviceInfo(long dwMachineNumber, long dwInfo, long * dwValue)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::GetDeviceInfo(dwMachineNumber, dwInfo, dwValue);

	return ret;
}

BOOL CZkDevice::GetDeviceTime(long dwMachineNumber, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::GetDeviceTime(dwMachineNumber, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);

	return ret;
}

BOOL CZkDevice::SetDeviceTime(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::SetDeviceTime(dwMachineNumber);

	return ret;
}

void CZkDevice::GetConnectStatus(long * dwErrorCode)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	CZkem1::GetConnectStatus(dwErrorCode);
}

BOOL CZkDevice::SearchDevice(LPCTSTR commType, LPCTSTR address, BSTR * DevBuffer, long DevBufferSize)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::SearchDevice(commType, address, DevBuffer, DevBufferSize);

	return ret;
}

BOOL CZkDevice::GetUserGroup(long dwMachineNumber, long dwEnrollNumber, long * UserGrp)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::GetUserGroup(dwMachineNumber, dwEnrollNumber, UserGrp);

	return ret;
}

BOOL CZkDevice::GetDeviceIP(long dwMachineNumber, BSTR * IPAddr)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::GetDeviceIP(dwMachineNumber, IPAddr);

	return ret;
}

BOOL CZkDevice::SetUserGroup(long dwMachineNumber, long dwEnrollNumber, long UserGrp)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::SetUserGroup(dwMachineNumber, dwEnrollNumber, UserGrp);

	return ret;
}

void CZkDevice::GetLastError(long * dwErrorCode)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	CZkem1::GetLastError(dwErrorCode);
}

BOOL CZkDevice::SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = FALSE;

	BOOL isTFT = IsTFTMachine(dwMachineNumber);
	if (isTFT)
	{
		CString strEnrollNumber;
		strEnrollNumber.Format(TEXT("%d"), dwEnrollNumber);
		ret = CZkem1::SSR_SetUserInfo(dwMachineNumber, strEnrollNumber, Name, Password, Privilege, Enabled);
	} 
	else
	{
		ret = CZkem1::SetUserInfo(dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
	}

	return ret;
}

BOOL CZkDevice::IsTFTMachine(long dwMachineNumber)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = CZkem1::IsTFTMachine(dwMachineNumber);

	return ret;
}

