#pragma once

// 本想再进行封装，但分析一下没有再封装的必要性了。 2019-12-03 之前。
//class CZkemDevice
//{
//public:
//	CZkemDevice(void);
//	~CZkemDevice(void);
//};


// ZK设备型号多种多样，不同设备的接口函数方法有一定差异。 
// 考虑运用使用 c++ 的继承和动态绑定，来设计支持这种现象。
// 2019-12-03 起。
#include "zkem1.h"


// CZkemDevice 直接提供给用户使用的接口基类。仅用于定义公共接口。

// 使用组合方式来集成其他“真实实现”类的功能。
class CZkemDevice
{
//private:
protected:
	// 将 CZkem1 通过子类方式集成进来，而非继承。 （组合方式）
	CZkem1 m_Zkem1;

//public:
protected:
	CZkemDevice(CWnd* pParentWnd, UINT nID);
public:
	virtual ~CZkemDevice(void);

protected:
	// 提供自动增长分配控件ID。
	static UINT m_nStaticAutoID;
	// 提供支持默认构造，简化后续使用代码的编写。 默认构造父窗口即为主窗口，控件ID自动增长分配。
	CZkemDevice();

//private:
protected:
	// 机器是否为彩屏机
	BOOL m_bIsTFT;
public:
	virtual BOOL IsTFTMachine(long dwMachineNumber) = 0;

public:
	virtual BOOL Connect_Net(LPCTSTR IPAdd, long Port) = 0;
	virtual void Disconnect() = 0;
	virtual BOOL PowerOffDevice(long dwMachineNumber) = 0;
	virtual BOOL RestartDevice(long dwMachineNumber) = 0;
	virtual BOOL PlayVoice(long Position, long Length) = 0;
	virtual BOOL GetDeviceInfo(long dwMachineNumber, long dwInfo, long * dwValue) = 0;
	virtual BOOL GetDeviceTime(long dwMachineNumber, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond) = 0;
	virtual BOOL SetDeviceTime(long dwMachineNumber) = 0;
	virtual void GetConnectStatus(long * dwErrorCode) = 0;
	virtual BOOL SearchDevice(LPCTSTR commType, LPCTSTR address, BSTR * DevBuffer, long DevBufferSize) = 0;
	virtual BOOL GetUserGroup(long dwMachineNumber, long dwEnrollNumber, long * UserGrp) = 0;
	virtual BOOL GetDeviceIP(long dwMachineNumber, BSTR * IPAddr) = 0;
	virtual BOOL SetUserGroup(long dwMachineNumber, long dwEnrollNumber, long UserGrp) = 0;
	virtual void GetLastError(long * dwErrorCode) = 0;
	virtual BOOL SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled) = 0;
	virtual BOOL ClearKeeperData(long dwMachineNumber) = 0;
	virtual BOOL RefreshData(long dwMachineNumber) = 0;
	virtual BOOL SetStrCardNumber(LPCTSTR ACardNumber) = 0;
	virtual BOOL EnableDevice(long dwMachineNumber, BOOL bFlag) = 0;
	virtual BOOL ReadAllUserID(long dwMachineNumber) = 0;
	virtual BOOL GetAllUserInfo(long dwMachineNumber, long * dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled) = 0;
};

// CZkemDeviceCommon 实现 BW,TFT,IFACE 等不同设备的同名称接口。
class CZkemDeviceCommon : public CZkemDevice
{
protected:
	CZkemDeviceCommon(CWnd* pParentWnd, UINT nID);
	CZkemDeviceCommon();
	~CZkemDeviceCommon(void);

public:
	BOOL IsTFTMachine(long dwMachineNumber);
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
	BOOL ClearKeeperData(long dwMachineNumber);
	BOOL RefreshData(long dwMachineNumber);
	BOOL SetStrCardNumber(LPCTSTR ACardNumber);
	BOOL EnableDevice(long dwMachineNumber, BOOL bFlag);
	BOOL ReadAllUserID(long dwMachineNumber);
	BOOL GetAllUserInfo(long dwMachineNumber, long * dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled);
};