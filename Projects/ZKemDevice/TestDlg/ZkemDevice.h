#pragma once

// �����ٽ��з�װ��������һ��û���ٷ�װ�ı�Ҫ���ˡ� 2019-12-03 ֮ǰ��
//class CZkemDevice
//{
//public:
//	CZkemDevice(void);
//	~CZkemDevice(void);
//};


// ZK�豸�ͺŶ��ֶ�������ͬ�豸�Ľӿں���������һ�����졣 
// ��������ʹ�� c++ �ļ̳кͶ�̬�󶨣������֧����������
// 2019-12-03 ��
#include "zkem1.h"


// CZkemDevice ֱ���ṩ���û�ʹ�õĽӿڻ��ࡣ�����ڶ��幫���ӿڡ�

// ʹ����Ϸ�ʽ��������������ʵʵ�֡���Ĺ��ܡ�
class CZkemDevice
{
//private:
protected:
	// �� CZkem1 ͨ�����෽ʽ���ɽ��������Ǽ̳С� ����Ϸ�ʽ��
	CZkem1 m_Zkem1;

//public:
protected:
	CZkemDevice(CWnd* pParentWnd, UINT nID);
public:
	virtual ~CZkemDevice(void);

//private:
protected:
	// �����Ƿ�Ϊ������
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

};

// CZkemDeviceCommon ʵ�� BW,TFT,IFACE �Ȳ�ͬ�豸��ͬ���ƽӿڡ�
class CZkemDeviceCommon : public CZkemDevice
{
protected:
	CZkemDeviceCommon(CWnd* pParentWnd, UINT nID);
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
};