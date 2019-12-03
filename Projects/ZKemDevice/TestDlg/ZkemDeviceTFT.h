#pragma once
#include "zkemdevice.h"

class CZkemDeviceTFT :
	public CZkemDeviceCommon
{
public:
	CZkemDeviceTFT(CWnd* pParentWnd, UINT nID);
	~CZkemDeviceTFT(void);

public:
	BOOL SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled);
};
