#pragma once
#include "zkemdevice.h"

class CZkemDeviceBW :
	public CZkemDeviceCommon
{
public:
	CZkemDeviceBW(CWnd* pParentWnd, UINT nID);
	CZkemDeviceBW();
	~CZkemDeviceBW(void);

public:
	BOOL SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled);
};
