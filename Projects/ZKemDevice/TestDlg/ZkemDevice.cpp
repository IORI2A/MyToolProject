#include "StdAfx.h"
#include "ZkemDevice.h"

#include "Tool.h"



/////////////////////////////////// CZkemDevice //////////////////////////////////////////////
CZkemDevice::CZkemDevice(CWnd* pParentWnd, UINT nID)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	LPCTSTR lpszWindowName = TEXT("CZkemDevice_Window");
	// Only a subset of the Windows dwStyle flags are supported for CreateControl: 
	DWORD dwStyle = WS_TABSTOP;
	RECT rect = {7, 7, 7+18, 7+17};

	// Ϊ��ʵ�֣��������������û�ͨ�������ṩ��
	//CWnd* pParentWnd = NULL;
	//UINT nID;

	// ʹ�� Create ������֧�� new ������
	// CZkem1 �� Create �������� CWnd::CreateControl �������ؼ�������鿴 CWnd::CreateControl ������
	m_Zkem1.Create(lpszWindowName, dwStyle, rect, pParentWnd, nID
		/*, CFile* pPersist = NULL, BOOL bStorage = FALSE, BSTR bstrLicKey = NULL*/);
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

CZkemDeviceCommon::~CZkemDeviceCommon(void)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();
}

/////////////////////////// ���� ZKEM �ӿ� /////////////////////////
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



