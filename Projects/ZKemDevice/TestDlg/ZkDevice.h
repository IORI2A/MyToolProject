#pragma once

#include "zkem1.h"

// CZkDevice

class CZkDevice : public CZkem1
{
	DECLARE_DYNAMIC(CZkDevice)

public:
	CZkDevice();
	virtual ~CZkDevice();

public:
	BOOL Connect_Net(LPCTSTR IPAdd, long Port);
	void Disconnect();
	BOOL PowerOffDevice(long dwMachineNumber);
	BOOL RestartDevice(long dwMachineNumber);
	BOOL PlayVoice(long Position, long Length);
	BOOL GetDeviceInfo(long dwMachineNumber, long dwInfo, long * dwValue);
	BOOL GetDeviceTime(long dwMachineNumber, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond);
	BOOL SetDeviceTime(long dwMachineNumber);
	void GetConnectStatus(long * dwErrorCode);
	BOOL SearchDevice(LPCTSTR commType, LPCTSTR address, BSTR * DevBuffer, long DevBufferSize);
	BOOL GetUserGroup(long dwMachineNumber, long dwEnrollNumber, long * UserGrp);
	BOOL GetDeviceIP(long dwMachineNumber, BSTR * IPAddr);
	BOOL SetUserGroup(long dwMachineNumber, long dwEnrollNumber, long UserGrp);
	void GetLastError(long * dwErrorCode);
	BOOL SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled);

	// 机器是否为彩屏机
	BOOL IsTFTMachine(long dwMachineNumber);
//private:
//	BOOL m_bIsTFT;

protected:
	DECLARE_MESSAGE_MAP()
};


