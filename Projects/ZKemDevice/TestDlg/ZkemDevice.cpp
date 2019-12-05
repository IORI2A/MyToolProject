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

	// Ϊ��ʵ�֣��������������û�ͨ�������ṩ��
	//CWnd* pParentWnd = NULL;
	//UINT nID;

	// ʹ�� Create ������֧�� new ������
	// CZkem1 �� Create �������� CWnd::CreateControl �������ؼ�������鿴 CWnd::CreateControl ������
	m_Zkem1.Create(lpszWindowName, dwStyle, rect, pParentWnd, nID
		/*, CFile* pPersist = NULL, BOOL bStorage = FALSE, BSTR bstrLicKey = NULL*/);
}

// �ṩ�Զ���������ؼ�ID��
// ���Բ鿴 winuser.h �ж������ID�� #define     OBJID_SYSMENU       ((LONG)0xFFFFFFFF)
// Resource.h ��һ������ 1000 ��ʼ�� Ϊ�����ͻ�Զ��������������趨Ϊ 0XFFFF (65535)��
UINT CZkemDevice::m_nStaticAutoID = 0XFFFF;
// �ṩ֧��Ĭ�Ϲ��죬�򻯺���ʹ�ô���ı�д�� Ĭ�Ϲ��츸���ڼ�Ϊ�����ڣ��ؼ�ID�Զ��������䡣
CZkemDevice::CZkemDevice()
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	LPCTSTR lpszWindowName = TEXT("CZkemDevice_Window_Auto");
	DWORD dwStyle = WS_TABSTOP;
	RECT rect = {7, 7, 7+18, 7+17};
	CWnd* pParentWnd = ::AfxGetMainWnd();
	UINT nID = ++m_nStaticAutoID;
	m_Zkem1.Create(lpszWindowName, dwStyle, rect, pParentWnd, nID);

	// ���м�¼��ǣ��������ڷ�������
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

BOOL CZkemDeviceCommon::SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled)
{
	TOOL_AUTO_LOG_FUNCTION_INFO();

	BOOL ret = FALSE;

	// �÷����ӿڶ��ڸ����豸���Ͳ�һ�£����಻ʵ�֣��ɾ�������ʵ�֡�
	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("SetUserInfo �����ӿڶ��ڸ����豸���Ͳ�һ�£����಻ʵ�֣�������ʵ�֡�");
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

	// �÷����ӿڶ��ڸ����豸���Ͳ�һ�£����಻ʵ�֣��ɾ�������ʵ�֡�
	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("GetAllUserInfo �����ӿڶ��ڸ����豸���Ͳ�һ�£����಻ʵ�֣�������ʵ�֡�");
	ASSERT(false);

	return ret;
}