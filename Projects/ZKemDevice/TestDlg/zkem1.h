#pragma once

// 计算机生成了由 Microsoft Visual C++ 创建的 IDispatch 包装类

// 注意: 不要修改此文件的内容。如果此类由
//  Microsoft Visual C++ 重新生成，您的修改将被覆盖。

/////////////////////////////////////////////////////////////////////////////
// CZkem1 包装类

class CZkem1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CZkem1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x853A19, 0xBD51, 0x419B, { 0x92, 0x69, 0x2D, 0xAB, 0xE5, 0x7E, 0xB6, 0x1F } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 属性
public:


// 操作
public:

// IZKEM

// Functions
//

	BOOL get_ReadMark()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ReadMark(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_CommPort()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_CommPort(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL ClearAdministrators(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL DeleteEnrollData(long dwMachineNumber, long dwEnrollNumber, long dwEMachineNumber, long dwBackupNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber);
		return result;
	}
	BOOL ReadSuperLogData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL ReadAllSLogData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL ReadGeneralLogData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL ReadAllGLogData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL EnableUser(long dwMachineNumber, long dwEnrollNumber, long dwEMachineNumber, long dwBackupNumber, BOOL bFlag)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BOOL ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber, bFlag);
		return result;
	}
	BOOL EnableDevice(long dwMachineNumber, BOOL bFlag)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BOOL ;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, bFlag);
		return result;
	}
	BOOL GetDeviceStatus(long dwMachineNumber, long dwStatus, long * dwValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwStatus, dwValue);
		return result;
	}
	BOOL GetDeviceInfo(long dwMachineNumber, long dwInfo, long * dwValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwInfo, dwValue);
		return result;
	}
	BOOL SetDeviceInfo(long dwMachineNumber, long dwInfo, long dwValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwInfo, dwValue);
		return result;
	}
	BOOL SetDeviceTime(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	void PowerOnAllDevice()
	{
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL PowerOffDevice(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL ModifyPrivilege(long dwMachineNumber, long dwEnrollNumber, long dwEMachineNumber, long dwBackupNumber, long dwMachinePrivilege)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber, dwMachinePrivilege);
		return result;
	}
	void GetLastError(long * dwErrorCode)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwErrorCode);
	}
	BOOL GetEnrollData(long dwMachineNumber, long dwEnrollNumber, long dwEMachineNumber, long dwBackupNumber, long * dwMachinePrivilege, long * dwEnrollData, long * dwPassWord)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber, dwMachinePrivilege, dwEnrollData, dwPassWord);
		return result;
	}
	BOOL SetEnrollData(long dwMachineNumber, long dwEnrollNumber, long dwEMachineNumber, long dwBackupNumber, long dwMachinePrivilege, long * dwEnrollData, long dwPassWord)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber, dwMachinePrivilege, dwEnrollData, dwPassWord);
		return result;
	}
	BOOL GetDeviceTime(long dwMachineNumber, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x15, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);
		return result;
	}
	BOOL GetGeneralLogData(long dwMachineNumber, long * dwTMachineNumber, long * dwEnrollNumber, long * dwEMachineNumber, long * dwVerifyMode, long * dwInOutMode, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwTMachineNumber, dwEnrollNumber, dwEMachineNumber, dwVerifyMode, dwInOutMode, dwYear, dwMonth, dwDay, dwHour, dwMinute);
		return result;
	}
	BOOL GetSuperLogData(long dwMachineNumber, long * dwTMachineNumber, long * dwSEnrollNumber, long * Params4, long * Params1, long * Params2, long * dwManipulation, long * Params3, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwTMachineNumber, dwSEnrollNumber, Params4, Params1, Params2, dwManipulation, Params3, dwYear, dwMonth, dwDay, dwHour, dwMinute);
		return result;
	}
	BOOL GetAllSLogData(long dwMachineNumber, long * dwTMachineNumber, long * dwSEnrollNumber, long * Params4, long * Params1, long * Params2, long * dwManipulation, long * Params3, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwTMachineNumber, dwSEnrollNumber, Params4, Params1, Params2, dwManipulation, Params3, dwYear, dwMonth, dwDay, dwHour, dwMinute);
		return result;
	}
	BOOL GetAllGLogData(long dwMachineNumber, long * dwTMachineNumber, long * dwEnrollNumber, long * dwEMachineNumber, long * dwVerifyMode, long * dwInOutMode, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwTMachineNumber, dwEnrollNumber, dwEMachineNumber, dwVerifyMode, dwInOutMode, dwYear, dwMonth, dwDay, dwHour, dwMinute);
		return result;
	}
	void ConvertPassword(long dwSrcPSW, long * dwDestPSW, long dwLength)
	{
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwSrcPSW, dwDestPSW, dwLength);
	}
	BOOL ReadAllUserID(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetAllUserID(long dwMachineNumber, long * dwEnrollNumber, long * dwEMachineNumber, long * dwBackupNumber, long * dwMachinePrivilege, long * dwEnable)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber, dwMachinePrivilege, dwEnable);
		return result;
	}
	BOOL GetSerialNumber(long dwMachineNumber, BSTR * dwSerialNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwSerialNumber);
		return result;
	}
	BOOL ClearKeeperData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	long GetBackupNumber(long dwMachineNumber)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetProductCode(long dwMachineNumber, BSTR * lpszProductCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, lpszProductCode);
		return result;
	}
	BOOL GetFirmwareVersion(long dwMachineNumber, BSTR * strVersion)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, strVersion);
		return result;
	}
	BOOL GetSDKVersion(BSTR * strVersion)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strVersion);
		return result;
	}
	BOOL ClearGLog(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x24, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	long GetFPTempLength(unsigned char * dwEnrollData)
	{
		long result;
		static BYTE parms[] = VTS_PUI1 ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, dwEnrollData);
		return result;
	}
	BOOL Connect_Com(long ComPort, long MachineNumber, long BaudRate)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ComPort, MachineNumber, BaudRate);
		return result;
	}
	BOOL Connect_Net(LPCTSTR IPAdd, long Port)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, IPAdd, Port);
		return result;
	}
	void Disconnect()
	{
		InvokeHelper(0x28, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL SetUserInfo(long dwMachineNumber, long dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_BOOL ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	BOOL GetUserInfo(long dwMachineNumber, long dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBOOL ;
		InvokeHelper(0x2a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	BOOL SetDeviceIP(long dwMachineNumber, LPCTSTR IPAddr)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, IPAddr);
		return result;
	}
	BOOL GetDeviceIP(long dwMachineNumber, BSTR * IPAddr)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x2c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, IPAddr);
		return result;
	}
	BOOL GetUserTmp(long dwMachineNumber, long dwEnrollNumber, long dwFingerIndex, unsigned char * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0x2d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData, TmpLength);
		return result;
	}
	BOOL SetUserTmp(long dwMachineNumber, long dwEnrollNumber, long dwFingerIndex, unsigned char * TmpData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PUI1 ;
		InvokeHelper(0x2e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData);
		return result;
	}
	BOOL GetAllUserInfo(long dwMachineNumber, long * dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBOOL ;
		InvokeHelper(0x2f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	BOOL DelUserTmp(long dwMachineNumber, long dwEnrollNumber, long dwFingerIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x30, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex);
		return result;
	}
	BOOL RefreshData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x31, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL FPTempConvert(unsigned char * TmpData1, unsigned char * TmpData2, long * Size)
	{
		BOOL result;
		static BYTE parms[] = VTS_PUI1 VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0x32, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, TmpData1, TmpData2, Size);
		return result;
	}
	BOOL SetCommPassword(long CommKey)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x33, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, CommKey);
		return result;
	}
	BOOL GetUserGroup(long dwMachineNumber, long dwEnrollNumber, long * UserGrp)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x34, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, UserGrp);
		return result;
	}
	BOOL SetUserGroup(long dwMachineNumber, long dwEnrollNumber, long UserGrp)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x35, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, UserGrp);
		return result;
	}
	BOOL GetTZInfo(long dwMachineNumber, long TZIndex, BSTR * TZ)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x36, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TZIndex, TZ);
		return result;
	}
	BOOL SetTZInfo(long dwMachineNumber, long TZIndex, LPCTSTR TZ)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x37, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TZIndex, TZ);
		return result;
	}
	BOOL GetUnlockGroups(long dwMachineNumber, BSTR * Grps)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x38, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Grps);
		return result;
	}
	BOOL SetUnlockGroups(long dwMachineNumber, LPCTSTR Grps)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x39, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Grps);
		return result;
	}
	BOOL GetGroupTZs(long dwMachineNumber, long GroupIndex, long * TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x3a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, GroupIndex, TZs);
		return result;
	}
	BOOL SetGroupTZs(long dwMachineNumber, long GroupIndex, long * TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x3b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, GroupIndex, TZs);
		return result;
	}
	BOOL GetUserTZs(long dwMachineNumber, long dwEnrollNumber, long * TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x3c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, TZs);
		return result;
	}
	BOOL SetUserTZs(long dwMachineNumber, long dwEnrollNumber, long * TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x3d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, TZs);
		return result;
	}
	BOOL ACUnlock(long dwMachineNumber, long Delay)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x3e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Delay);
		return result;
	}
	BOOL GetACFun(long * ACFun)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x3f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ACFun);
		return result;
	}
	long get_ConvertBIG5()
	{
		long result;
		InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ConvertBIG5(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x40, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL GetGeneralLogDataStr(long dwMachineNumber, long * dwEnrollNumber, long * dwVerifyMode, long * dwInOutMode, BSTR * TimeStr)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x41, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwVerifyMode, dwInOutMode, TimeStr);
		return result;
	}
	BOOL GetUserTmpStr(long dwMachineNumber, long dwEnrollNumber, long dwFingerIndex, BSTR * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x42, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData, TmpLength);
		return result;
	}
	BOOL SetUserTmpStr(long dwMachineNumber, long dwEnrollNumber, long dwFingerIndex, LPCTSTR TmpData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x43, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData);
		return result;
	}
	BOOL GetEnrollDataStr(long dwMachineNumber, long dwEnrollNumber, long dwEMachineNumber, long dwBackupNumber, long * dwMachinePrivilege, BSTR * dwEnrollData, long * dwPassWord)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x44, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber, dwMachinePrivilege, dwEnrollData, dwPassWord);
		return result;
	}
	BOOL SetEnrollDataStr(long dwMachineNumber, long dwEnrollNumber, long dwEMachineNumber, long dwBackupNumber, long dwMachinePrivilege, LPCTSTR dwEnrollData, long dwPassWord)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x45, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwEMachineNumber, dwBackupNumber, dwMachinePrivilege, dwEnrollData, dwPassWord);
		return result;
	}
	BOOL GetGroupTZStr(long dwMachineNumber, long GroupIndex, BSTR * TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x46, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, GroupIndex, TZs);
		return result;
	}
	BOOL SetGroupTZStr(long dwMachineNumber, long GroupIndex, LPCTSTR TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x47, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, GroupIndex, TZs);
		return result;
	}
	BOOL GetUserTZStr(long dwMachineNumber, long dwEnrollNumber, BSTR * TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x48, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, TZs);
		return result;
	}
	BOOL SetUserTZStr(long dwMachineNumber, long dwEnrollNumber, LPCTSTR TZs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x49, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, TZs);
		return result;
	}
	BOOL FPTempConvertStr(LPCTSTR TmpData1, BSTR * TmpData2, long * Size)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x4a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, TmpData1, TmpData2, Size);
		return result;
	}
	long GetFPTempLengthStr(LPCTSTR dwEnrollData)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x4b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, dwEnrollData);
		return result;
	}
	long get_BASE64()
	{
		long result;
		InvokeHelper(0x4c, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_BASE64(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	unsigned long get_PIN2()
	{
		unsigned long result;
		InvokeHelper(0x4e, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	void put_PIN2(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(0x4e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_AccGroup()
	{
		long result;
		InvokeHelper(0x4f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_AccGroup(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_AccTimeZones(long Index)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, Index);
		return result;
	}
	void put_AccTimeZones(long Index, long newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x50, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}
	BOOL GetUserInfoByPIN2(long dwMachineNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBOOL ;
		InvokeHelper(0x51, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	BOOL GetUserInfoByCard(long dwMachineNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBOOL ;
		InvokeHelper(0x52, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	long get_CardNumber(long Index)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x53, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, parms, Index);
		return result;
	}
	void put_CardNumber(long Index, long newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x53, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}
	BOOL CaptureImage(BOOL FullImage, long * Width, long * Height, unsigned char * Image, LPCTSTR ImageFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BOOL VTS_PI4 VTS_PI4 VTS_PUI1 VTS_BSTR ;
		InvokeHelper(0x56, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FullImage, Width, Height, Image, ImageFile);
		return result;
	}
	BOOL UpdateFirmware(LPCTSTR FirmwareFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x57, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FirmwareFile);
		return result;
	}
	BOOL StartEnroll(long UserID, long FingerID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x58, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserID, FingerID);
		return result;
	}
	BOOL StartVerify(long UserID, long FingerID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x59, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserID, FingerID);
		return result;
	}
	BOOL StartIdentify()
	{
		BOOL result;
		InvokeHelper(0x5a, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL CancelOperation()
	{
		BOOL result;
		InvokeHelper(0x5b, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL QueryState(long * State)
	{
		BOOL result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x5c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, State);
		return result;
	}
	BOOL BackupData(LPCTSTR DataFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DataFile);
		return result;
	}
	BOOL RestoreData(LPCTSTR DataFile)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x5e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DataFile);
		return result;
	}
	BOOL WriteLCD(long Row, long Col, LPCTSTR Text)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x5f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Row, Col, Text);
		return result;
	}
	BOOL ClearLCD()
	{
		BOOL result;
		InvokeHelper(0x60, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL Beep(long DelayMS)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x61, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, DelayMS);
		return result;
	}
	BOOL PlayVoice(long Position, long Length)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x62, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Position, Length);
		return result;
	}
	BOOL PlayVoiceByIndex(long Index)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x63, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Index);
		return result;
	}
	BOOL EnableClock(long Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x64, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Enabled);
		return result;
	}
	BOOL GetUserIDByPIN2(long PIN2, long * UserID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x65, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, PIN2, UserID);
		return result;
	}
	long get_PINWidth()
	{
		long result;
		InvokeHelper(0x66, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL GetPIN2(long UserID, long * PIN2)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x67, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserID, PIN2);
		return result;
	}
	BOOL FPTempConvertNew(unsigned char * TmpData1, unsigned char * TmpData2, long * Size)
	{
		BOOL result;
		static BYTE parms[] = VTS_PUI1 VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0x68, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, TmpData1, TmpData2, Size);
		return result;
	}
	BOOL FPTempConvertNewStr(LPCTSTR TmpData1, BSTR * TmpData2, long * Size)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x69, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, TmpData1, TmpData2, Size);
		return result;
	}
	BOOL ReadAllTemplate(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL DisableDeviceWithTimeOut(long dwMachineNumber, long TimeOutSec)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x6b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TimeOutSec);
		return result;
	}
	BOOL SetDeviceTime2(long dwMachineNumber, long dwYear, long dwMonth, long dwDay, long dwHour, long dwMinute, long dwSecond)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x6c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);
		return result;
	}
	BOOL ClearSLog(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL RestartDevice(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x6e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetDeviceMAC(long dwMachineNumber, BSTR * sMAC)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, sMAC);
		return result;
	}
	BOOL SetDeviceMAC(long dwMachineNumber, LPCTSTR sMAC)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x70, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, sMAC);
		return result;
	}
	BOOL GetWiegandFmt(long dwMachineNumber, BSTR * sWiegandFmt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x71, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, sWiegandFmt);
		return result;
	}
	BOOL SetWiegandFmt(long dwMachineNumber, LPCTSTR sWiegandFmt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x72, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, sWiegandFmt);
		return result;
	}
	BOOL ClearSMS(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x73, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetSMS(long dwMachineNumber, long ID, long * Tag, long * ValidMinutes, BSTR * StartTime, BSTR * Content)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x74, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, ID, Tag, ValidMinutes, StartTime, Content);
		return result;
	}
	BOOL SetSMS(long dwMachineNumber, long ID, long Tag, long ValidMinutes, LPCTSTR StartTime, LPCTSTR Content)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, ID, Tag, ValidMinutes, StartTime, Content);
		return result;
	}
	BOOL DeleteSMS(long dwMachineNumber, long ID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x76, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, ID);
		return result;
	}
	BOOL SetUserSMS(long dwMachineNumber, long dwEnrollNumber, long SMSID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x77, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, SMSID);
		return result;
	}
	BOOL DeleteUserSMS(long dwMachineNumber, long dwEnrollNumber, long SMSID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x78, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, SMSID);
		return result;
	}
	BOOL GetCardFun(long dwMachineNumber, long * CardFun)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x79, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, CardFun);
		return result;
	}
	BOOL ClearUserSMS(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	long get_MachineNumber()
	{
		long result;
		InvokeHelper(0x7b, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MachineNumber(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL SetDeviceCommPwd(long dwMachineNumber, long CommKey)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x7c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, CommKey);
		return result;
	}
	BOOL GetDoorState(long MachineNumber, long * State)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x80, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, MachineNumber, State);
		return result;
	}
	BOOL GetVendor(BSTR * strVendor)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0x81, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strVendor);
		return result;
	}
	BOOL GetSensorSN(long dwMachineNumber, BSTR * SensorSN)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x82, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, SensorSN);
		return result;
	}
	BOOL ReadCustData(long dwMachineNumber, BSTR * CustData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x83, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, CustData);
		return result;
	}
	BOOL WriteCustData(long dwMachineNumber, LPCTSTR CustData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x84, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, CustData);
		return result;
	}
	BOOL BeginBatchUpdate(long dwMachineNumber, long UpdateFlag)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x85, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, UpdateFlag);
		return result;
	}
	BOOL BatchUpdate(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x86, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL ClearData(long dwMachineNumber, long DataFlag)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x87, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, DataFlag);
		return result;
	}
	BOOL GetDataFile(long dwMachineNumber, long DataFlag, LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0x88, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, DataFlag, FileName);
		return result;
	}
	BOOL WriteCard(long dwMachineNumber, long dwEnrollNumber, long dwFingerIndex1, unsigned char * TmpData1, long dwFingerIndex2, unsigned char * TmpData2, long dwFingerIndex3, unsigned char * TmpData3, long dwFingerIndex4, unsigned char * TmpData4)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PUI1 VTS_I4 VTS_PUI1 VTS_I4 VTS_PUI1 VTS_I4 VTS_PUI1 ;
		InvokeHelper(0x89, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex1, TmpData1, dwFingerIndex2, TmpData2, dwFingerIndex3, TmpData3, dwFingerIndex4, TmpData4);
		return result;
	}
	BOOL GetGeneralExtLogData(long dwMachineNumber, long * dwEnrollNumber, long * dwVerifyMode, long * dwInOutMode, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond, long * dwWorkCode, long * dwReserved)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x8a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwVerifyMode, dwInOutMode, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond, dwWorkCode, dwReserved);
		return result;
	}
	BOOL EmptyCard(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetDeviceStrInfo(long dwMachineNumber, long dwInfo, BSTR * Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x8c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwInfo, Value);
		return result;
	}
	BOOL GetSysOption(long dwMachineNumber, LPCTSTR Option, BSTR * Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x8d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Option, Value);
		return result;
	}
	BOOL SetUserInfoEx(long dwMachineNumber, long dwEnrollNumber, long VerifyStyle, unsigned char * Reserved)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PUI1 ;
		InvokeHelper(0x8e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, VerifyStyle, Reserved);
		return result;
	}
	BOOL GetUserInfoEx(long dwMachineNumber, long dwEnrollNumber, long * VerifyStyle, unsigned char * Reserved)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PUI1 ;
		InvokeHelper(0x8f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, VerifyStyle, Reserved);
		return result;
	}
	BOOL DeleteUserInfoEx(long dwMachineNumber, long dwEnrollNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x90, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber);
		return result;
	}
	BOOL SSR_GetGeneralLogData(long dwMachineNumber, BSTR * dwEnrollNumber, long * dwVerifyMode, long * dwInOutMode, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond, long * dwWorkCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x91, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwVerifyMode, dwInOutMode, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond, dwWorkCode);
		return result;
	}
	BOOL SSR_GetAllUserInfo(long dwMachineNumber, BSTR * dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBOOL ;
		InvokeHelper(0x92, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	BOOL SSR_GetUserInfo(long dwMachineNumber, LPCTSTR dwEnrollNumber, BSTR * Name, BSTR * Password, long * Privilege, BOOL * Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBOOL ;
		InvokeHelper(0x93, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	BOOL SSR_GetUserTmp(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, unsigned char * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0x94, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData, TmpLength);
		return result;
	}
	BOOL SSR_GetUserTmpStr(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, BSTR * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0x95, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData, TmpLength);
		return result;
	}
	BOOL SSR_DeleteEnrollData(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwBackupNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x96, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwBackupNumber);
		return result;
	}
	BOOL SSR_SetUserInfo(long dwMachineNumber, LPCTSTR dwEnrollNumber, LPCTSTR Name, LPCTSTR Password, long Privilege, BOOL Enabled)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_BOOL ;
		InvokeHelper(0x97, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, Name, Password, Privilege, Enabled);
		return result;
	}
	BOOL SSR_SetUserTmp(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, unsigned char * TmpData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PUI1 ;
		InvokeHelper(0x98, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData);
		return result;
	}
	BOOL SSR_SetUserTmpStr(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, LPCTSTR TmpData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0x99, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, TmpData);
		return result;
	}
	BOOL SSR_DelUserTmp(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x9a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex);
		return result;
	}
	CString get_STR_CardNumber(long Index)
	{
		CString result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x9b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms, Index);
		return result;
	}
	void put_STR_CardNumber(long Index, LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x9b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}
	BOOL SetWorkCode(long WorkCodeID, long AWorkCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x9c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, WorkCodeID, AWorkCode);
		return result;
	}
	BOOL GetWorkCode(long WorkCodeID, long * AWorkCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x9d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, WorkCodeID, AWorkCode);
		return result;
	}
	BOOL DeleteWorkCode(long WorkCodeID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x9e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, WorkCodeID);
		return result;
	}
	BOOL ClearWorkCode()
	{
		BOOL result;
		InvokeHelper(0x9f, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL ReadAttRule(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL ReadDPTInfo(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL SaveTheDataToFile(long dwMachineNumber, LPCTSTR TheFilePath, long FileFlag)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0xa2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TheFilePath, FileFlag);
		return result;
	}
	BOOL ReadTurnInfo(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL SSR_OutPutHTMLRep(long dwMachineNumber, LPCTSTR dwEnrollNumber, LPCTSTR AttFile, LPCTSTR UserFile, LPCTSTR DeptFile, LPCTSTR TimeClassFile, LPCTSTR AttruleFile, long BYear, long BMonth, long BDay, long BHour, long BMinute, long BSecond, long EYear, long EMonth, long EDay, long EHour, long EMinute, long ESecond, LPCTSTR TempPath, LPCTSTR OutFileName, long HTMLFlag, long resv1, LPCTSTR resv2)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0xa4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, AttFile, UserFile, DeptFile, TimeClassFile, AttruleFile, BYear, BMonth, BDay, BHour, BMinute, BSecond, EYear, EMonth, EDay, EHour, EMinute, ESecond, TempPath, OutFileName, HTMLFlag, resv1, resv2);
		return result;
	}
	BOOL ReadAOptions(LPCTSTR AOption, BSTR * AValue)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0xa5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AOption, AValue);
		return result;
	}
	BOOL ReadRTLog(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetRTLog(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetHIDEventCardNumAsStr(BSTR * strHIDEventCardNum)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0xa8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, strHIDEventCardNum);
		return result;
	}
	BOOL GetStrCardNumber(BSTR * ACardNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_PBSTR ;
		InvokeHelper(0xa9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ACardNumber);
		return result;
	}
	BOOL SetStrCardNumber(LPCTSTR ACardNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xaa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ACardNumber);
		return result;
	}
	BOOL RegEvent(long dwMachineNumber, long EventMask)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xab, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, EventMask);
		return result;
	}
	BOOL CancelBatchUpdate(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xac, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL SetSysOption(long dwMachineNumber, LPCTSTR Option, LPCTSTR Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xad, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Option, Value);
		return result;
	}
	BOOL Connect_Modem(long ComPort, long MachineNumber, long BaudRate, LPCTSTR Telephone)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0xae, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ComPort, MachineNumber, BaudRate, Telephone);
		return result;
	}
	BOOL UseGroupTimeZone()
	{
		BOOL result;
		InvokeHelper(0xaf, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL SetHoliday(long dwMachineNumber, LPCTSTR Holiday)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xb0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Holiday);
		return result;
	}
	BOOL GetHoliday(long dwMachineNumber, BSTR * Holiday)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xb1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Holiday);
		return result;
	}
	BOOL SetDaylight(long dwMachineNumber, long Support, LPCTSTR BeginTime, LPCTSTR EndTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xb2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Support, BeginTime, EndTime);
		return result;
	}
	BOOL GetDaylight(long dwMachineNumber, long * Support, BSTR * BeginTime, BSTR * EndTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0xb3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Support, BeginTime, EndTime);
		return result;
	}
	BOOL SSR_SetUnLockGroup(long dwMachineNumber, long CombNo, long Group1, long Group2, long Group3, long Group4, long Group5)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xb4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, CombNo, Group1, Group2, Group3, Group4, Group5);
		return result;
	}
	BOOL SSR_GetUnLockGroup(long dwMachineNumber, long CombNo, long * Group1, long * Group2, long * Group3, long * Group4, long * Group5)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, CombNo, Group1, Group2, Group3, Group4, Group5);
		return result;
	}
	BOOL SSR_SetGroupTZ(long dwMachineNumber, long GroupNo, long Tz1, long Tz2, long Tz3, long VaildHoliday, long VerifyStyle)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xb6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, GroupNo, Tz1, Tz2, Tz3, VaildHoliday, VerifyStyle);
		return result;
	}
	BOOL SSR_GetGroupTZ(long dwMachineNumber, long GroupNo, long * Tz1, long * Tz2, long * Tz3, long * VaildHoliday, long * VerifyStyle)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xb7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, GroupNo, Tz1, Tz2, Tz3, VaildHoliday, VerifyStyle);
		return result;
	}
	BOOL SSR_GetHoliday(long dwMachineNumber, long HolidayID, long * BeginMonth, long * BeginDay, long * EndMonth, long * EndDay, long * TimeZoneID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xb8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, HolidayID, BeginMonth, BeginDay, EndMonth, EndDay, TimeZoneID);
		return result;
	}
	BOOL SSR_SetHoliday(long dwMachineNumber, long HolidayID, long BeginMonth, long BeginDay, long EndMonth, long EndDay, long TimeZoneID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xb9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, HolidayID, BeginMonth, BeginDay, EndMonth, EndDay, TimeZoneID);
		return result;
	}
	BOOL GetPlatform(long dwMachineNumber, BSTR * Platform)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xba, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Platform);
		return result;
	}
	BOOL SSR_SetUserSMS(long dwMachineNumber, LPCTSTR dwEnrollNumber, long SMSID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0xbb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, SMSID);
		return result;
	}
	BOOL SSR_DeleteUserSMS(long dwMachineNumber, LPCTSTR dwEnrollNumber, long SMSID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0xbc, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, SMSID);
		return result;
	}
	BOOL IsTFTMachine(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xbd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL SSR_EnableUser(long dwMachineNumber, LPCTSTR dwEnrollNumber, BOOL bFlag)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BOOL ;
		InvokeHelper(0xbe, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, bFlag);
		return result;
	}
	long get_SSRPin()
	{
		long result;
		InvokeHelper(0xbf, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL SendCMDMsg(long dwMachineNumber, long Param1, long Param2)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Param1, Param2);
		return result;
	}
	BOOL SendFile(long dwMachineNumber, LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xc1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName);
		return result;
	}
	BOOL SetLanguageByID(long dwMachineNumber, long LanguageID, LPCTSTR Language)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0xc2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, LanguageID, Language);
		return result;
	}
	BOOL ReadFile(long dwMachineNumber, LPCTSTR FileName, LPCTSTR FilePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xc3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName, FilePath);
		return result;
	}
	BOOL SetLastCount(long count)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xc4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, count);
		return result;
	}
	BOOL SetCustomizeAttState(long dwMachineNumber, long StateID, long NewState)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, StateID, NewState);
		return result;
	}
	BOOL DelCustomizeAttState(long dwMachineNumber, long StateID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xc6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, StateID);
		return result;
	}
	BOOL EnableCustomizeAttState(long dwMachineNumber, long StateID, long Enable)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xc7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, StateID, Enable);
		return result;
	}
	BOOL SetCustomizeVoice(long dwMachineNumber, long VoiceID, LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0xc8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, VoiceID, FileName);
		return result;
	}
	BOOL DelCustomizeVoice(long dwMachineNumber, long VoiceID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0xc9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, VoiceID);
		return result;
	}
	BOOL EnableCustomizeVoice(long dwMachineNumber, long VoiceID, long Enable)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xca, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, VoiceID, Enable);
		return result;
	}
	BOOL StartEnrollEx(LPCTSTR UserID, long FingerID, long Flag)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_I4 VTS_I4 ;
		InvokeHelper(0xcb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, UserID, FingerID, Flag);
		return result;
	}
	BOOL SSR_SetUserTmpExt(long dwMachineNumber, long IsDeleted, LPCTSTR dwEnrollNumber, long dwFingerIndex, unsigned char * TmpData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_PUI1 ;
		InvokeHelper(0xd7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, IsDeleted, dwEnrollNumber, dwFingerIndex, TmpData);
		return result;
	}
	BOOL SSR_DelUserTmpExt(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0xd8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex);
		return result;
	}
	BOOL SSR_DeleteEnrollDataExt(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwBackupNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0xd9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwBackupNumber);
		return result;
	}
	BOOL SSR_GetWorkCode(long AWorkCode, BSTR * Name)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0xda, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AWorkCode, Name);
		return result;
	}
	BOOL SSR_SetWorkCode(long AWorkCode, LPCTSTR Name)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xdb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, AWorkCode, Name);
		return result;
	}
	BOOL SSR_DeleteWorkCode(long PIN)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xdc, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, PIN);
		return result;
	}
	BOOL SSR_ClearWorkCode()
	{
		BOOL result;
		InvokeHelper(0xdd, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL SSR_GetSuperLogData(long MachineNumber, long * Number, BSTR * Admin, BSTR * User, long * Manipulation, BSTR * Time, long * Params1, long * Params2, long * Params3)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xde, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, MachineNumber, Number, Admin, User, Manipulation, Time, Params1, Params2, Params3);
		return result;
	}
	BOOL SSR_SetShortkey(long ShortKeyID, long ShortKeyFun, long StateCode, LPCTSTR StateName, long StateAutoChange, LPCTSTR StateAutoChangeTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0xdf, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ShortKeyID, ShortKeyFun, StateCode, StateName, StateAutoChange, StateAutoChangeTime);
		return result;
	}
	BOOL SSR_GetShortkey(long ShortKeyID, long * ShortKeyFun, long * StateCode, BSTR * StateName, long * AutoChange, BSTR * AutoChangeTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PBSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0xe0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ShortKeyID, ShortKeyFun, StateCode, StateName, AutoChange, AutoChangeTime);
		return result;
	}
	BOOL Connect_USB(long MachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xe1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, MachineNumber);
		return result;
	}
	BOOL GetSuperLogData2(long dwMachineNumber, long * dwTMachineNumber, long * dwSEnrollNumber, long * Params4, long * Params1, long * Params2, long * dwManipulation, long * Params3, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecs)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xe2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwTMachineNumber, dwSEnrollNumber, Params4, Params1, Params2, dwManipulation, Params3, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecs);
		return result;
	}
	BOOL GetUserFace(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFaceIndex, unsigned char * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0xe6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFaceIndex, TmpData, TmpLength);
		return result;
	}
	BOOL SetUserFace(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFaceIndex, unsigned char * TmpData, long TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PUI1 VTS_I4 ;
		InvokeHelper(0xe7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFaceIndex, TmpData, TmpLength);
		return result;
	}
	BOOL DelUserFace(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFaceIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0xe8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFaceIndex);
		return result;
	}
	BOOL GetUserFaceStr(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFaceIndex, BSTR * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xe9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFaceIndex, TmpData, TmpLength);
		return result;
	}
	BOOL SetUserFaceStr(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFaceIndex, LPCTSTR TmpData, long TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0xea, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFaceIndex, TmpData, TmpLength);
		return result;
	}
	BOOL GetUserTmpEx(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, long * Flag, unsigned char * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0xeb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, Flag, TmpData, TmpLength);
		return result;
	}
	BOOL GetUserTmpExStr(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, long * Flag, BSTR * TmpData, long * TmpLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PI4 VTS_PBSTR VTS_PI4 ;
		InvokeHelper(0xec, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, Flag, TmpData, TmpLength);
		return result;
	}
	BOOL SetUserTmpEx(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, long Flag, unsigned char * TmpData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_PUI1 ;
		InvokeHelper(0xed, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, Flag, TmpData);
		return result;
	}
	BOOL SetUserTmpExStr(long dwMachineNumber, LPCTSTR dwEnrollNumber, long dwFingerIndex, long Flag, LPCTSTR TmpData)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR ;
		InvokeHelper(0xee, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwFingerIndex, Flag, TmpData);
		return result;
	}
	BOOL MergeTemplate(unsigned char * * Templates, long FingerCount, unsigned char * TemplateDest, long * FingerSize)
	{
		BOOL result;
		static BYTE parms[] = VTS_UNKNOWN VTS_I4 VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0xef, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Templates, FingerCount, TemplateDest, FingerSize);
		return result;
	}
	BOOL SplitTemplate(unsigned char * Template, unsigned char * * Templates, long * FingerCount, long * FingerSize)
	{
		BOOL result;
		static BYTE parms[] = VTS_PUI1 VTS_UNKNOWN VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xf0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Template, Templates, FingerCount, FingerSize);
		return result;
	}
	long get_PullMode()
	{
		long result;
		InvokeHelper(0xf1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PullMode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL ReadUserAllTemplate(long dwMachineNumber, LPCTSTR dwEnrollNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xf2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber);
		return result;
	}
	BOOL UpdateFile(LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xf3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FileName);
		return result;
	}
	BOOL ReadLastestLogData(long dwMachineNumber, long NewLog, long dwYear, long dwMonth, long dwDay, long dwHour, long dwMinute, long dwSecond)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xf4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, NewLog, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);
		return result;
	}
	BOOL SetOptionCommPwd(long dwMachineNumber, LPCTSTR CommKey)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xf5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, CommKey);
		return result;
	}
	BOOL ReadSuperLogDataEx(long dwMachineNumber, long dwYear_S, long dwMonth_S, long dwDay_S, long dwHour_S, long dwMinute_S, long dwSecond_S, long dwYear_E, long dwMonth_E, long dwDay_E, long dwHour_E, long dwMinute_E, long dwSecond_E, long dwLogIndex)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0xf6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwYear_S, dwMonth_S, dwDay_S, dwHour_S, dwMinute_S, dwSecond_S, dwYear_E, dwMonth_E, dwDay_E, dwHour_E, dwMinute_E, dwSecond_E, dwLogIndex);
		return result;
	}
	BOOL GetSuperLogDataEx(long dwMachineNumber, BSTR * EnrollNumber, long * Params4, long * Params1, long * Params2, long * dwManipulation, long * Params3, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xf7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, EnrollNumber, Params4, Params1, Params2, dwManipulation, Params3, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);
		return result;
	}
	BOOL GetPhotoByName(long dwMachineNumber, LPCTSTR PhotoName, unsigned char * PhotoData, long * PhotoLength)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0xf8, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, PhotoName, PhotoData, PhotoLength);
		return result;
	}
	BOOL GetPhotoNamesByTime(long dwMachineNumber, long iFlag, LPCTSTR sTime, LPCTSTR eTime, BSTR * AllPhotoName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0xf9, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, iFlag, sTime, eTime, AllPhotoName);
		return result;
	}
	BOOL ClearPhotoByTime(long dwMachineNumber, long iFlag, LPCTSTR sTime, LPCTSTR eTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xfa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, iFlag, sTime, eTime);
		return result;
	}
	BOOL GetPhotoCount(long dwMachineNumber, long * count, long iFlag)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_I4 ;
		InvokeHelper(0xfb, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, count, iFlag);
		return result;
	}
	BOOL ClearDataEx(long dwMachineNumber, LPCTSTR TableName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0xfc, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TableName);
		return result;
	}
	BOOL GetDataFileEx(long dwMachineNumber, LPCTSTR SourceFileName, LPCTSTR DestFileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xfd, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, SourceFileName, DestFileName);
		return result;
	}
	BOOL SSR_SetDeviceData(long dwMachineNumber, LPCTSTR TableName, LPCTSTR Datas, LPCTSTR Options)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xfe, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TableName, Datas, Options);
		return result;
	}
	BOOL SSR_GetDeviceData(long dwMachineNumber, BSTR * Buffer, long BufferSize, LPCTSTR TableName, LPCTSTR FiledNames, LPCTSTR Filter, LPCTSTR Options)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xff, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Buffer, BufferSize, TableName, FiledNames, Filter, Options);
		return result;
	}
	BOOL UpdateLogo(long dwMachineNumber, LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x100, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName);
		return result;
	}
	BOOL SetCommuTimeOut(long timeOut)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x101, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, timeOut);
		return result;
	}
	BOOL SendFileByType(long dwMachineNumber, LPCTSTR FileName, long iType)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 ;
		InvokeHelper(0x102, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName, iType);
		return result;
	}
	BOOL SetCommProType(long proType)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x103, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, proType);
		return result;
	}
	BOOL SetCompatOldFirmware(long nCompatOkdFirmware)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nCompatOkdFirmware);
		return result;
	}
	BOOL Connect_P4P(LPCTSTR uid)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x10f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, uid);
		return result;
	}
	BOOL SetDeviceTableData(long dwMachineNumber, LPCTSTR TableName, LPCTSTR Datas, LPCTSTR Options, long * count)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x110, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TableName, Datas, Options, count);
		return result;
	}
	void GetConnectStatus(long * dwErrorCode)
	{
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x111, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dwErrorCode);
	}
	long get_MaxP4PConnect()
	{
		long result;
		InvokeHelper(0x112, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL SetManufacturerData(long dwMachineNumber, LPCTSTR Name, LPCTSTR Value)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x113, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Name, Value);
		return result;
	}
	long GetDeviceStatusEx(long dwMachineNumber)
	{
		long result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x114, DISPATCH_METHOD, VT_I4, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	void CancelByUser()
	{
		InvokeHelper(0x115, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long SSR_GetDeviceDataCount(LPCTSTR TableName, LPCTSTR Filter, LPCTSTR Options)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x116, DISPATCH_METHOD, VT_I4, (void*)&result, parms, TableName, Filter, Options);
		return result;
	}
	BOOL SSR_DeleteDeviceData(long dwMachineNumber, LPCTSTR TableName, LPCTSTR Datas, LPCTSTR Options)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x117, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, TableName, Datas, Options);
		return result;
	}
	BOOL ReadTimeGLogData(long dwMachineNumber, LPCTSTR sTime, LPCTSTR eTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1f4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, sTime, eTime);
		return result;
	}
	BOOL DeleteAttlogBetweenTheDate(long dwMachineNumber, LPCTSTR sTime, LPCTSTR eTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x1f5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, sTime, eTime);
		return result;
	}
	BOOL DeleteAttlogByTime(long dwMachineNumber, LPCTSTR sTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x1f6, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, sTime);
		return result;
	}
	BOOL ReadNewGLogData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1f7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL IsNewFirmwareMachine(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1fa, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL UploadUserPhoto(long dwMachineNumber, LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x208, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName);
		return result;
	}
	BOOL DownloadUserPhoto(long dwMachineNumber, LPCTSTR FileName, LPCTSTR FilePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x209, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName, FilePath);
		return result;
	}
	BOOL DeleteUserPhoto(long dwMachineNumber, LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x20a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName);
		return result;
	}
	BOOL GetAllUserPhoto(long dwMachineNumber, LPCTSTR dlDir)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x20b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dlDir);
		return result;
	}
	BOOL SetBellSchDataEx(long dwMachineNumber, long weekDay, long Index, long Enable, long Hour, long min, long voice, long way, long InerBellDelay, long ExtBellDelay)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x21c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, weekDay, Index, Enable, Hour, min, voice, way, InerBellDelay, ExtBellDelay);
		return result;
	}
	BOOL GetBellSchDataEx(long dwMachineNumber, long weekDay, long Index, long * Enable, long * Hour, long * min, long * voice, long * way, long * InerBellDelay, long * ExtBellDelay)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x21d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, weekDay, Index, Enable, Hour, min, voice, way, InerBellDelay, ExtBellDelay);
		return result;
	}
	BOOL GetDayBellSchCount(long dwMachineNumber, long * DayBellCnt)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x21e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, DayBellCnt);
		return result;
	}
	BOOL GetMaxBellIDInBellSchData(long dwMachineNumber, long * MaxBellID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x21f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, MaxBellID);
		return result;
	}
	BOOL ReadAllBellSchData(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x220, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL GetEachBellInfo(long dwMachineNumber, long * weekDay, long * Index, long * Enable, long * Hour, long * min, long * voice, long * way, long * InerBellDelay, long * ExtBellDelay)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x221, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, weekDay, Index, Enable, Hour, min, voice, way, InerBellDelay, ExtBellDelay);
		return result;
	}
	BOOL SetUserValidDate(long dwMachineNumber, LPCTSTR UserID, long Expires, long ValidCount, LPCTSTR StartDate, LPCTSTR EndDate)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x230, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, UserID, Expires, ValidCount, StartDate, EndDate);
		return result;
	}
	BOOL GetUserValidDate(long dwMachineNumber, LPCTSTR UserID, long * Expires, long * ValidCount, BSTR * StartDate, BSTR * EndDate)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 VTS_PI4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x231, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, UserID, Expires, ValidCount, StartDate, EndDate);
		return result;
	}
	BOOL SetUserValidDateBatch(long dwMachineNumber, LPCTSTR Datas)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x234, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Datas);
		return result;
	}
	BOOL GetUserValidDateBatch(long dwMachineNumber, BSTR * Buffer, long BufferSize)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x235, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Buffer, BufferSize);
		return result;
	}
	BOOL SetUserVerifyStyle(long dwMachineNumber, LPCTSTR dwEnrollNumber, long VerifyStyle, unsigned char * Reserved)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_I4 VTS_PUI1 ;
		InvokeHelper(0x23a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, VerifyStyle, Reserved);
		return result;
	}
	BOOL GetUserVerifyStyle(long dwMachineNumber, LPCTSTR dwEnrollNumber, long * VerifyStyle, unsigned char * Reserved)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 VTS_PUI1 ;
		InvokeHelper(0x23b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, VerifyStyle, Reserved);
		return result;
	}
	BOOL SetUserVerifyStyleBatch(long dwMachineNumber, LPCTSTR Datas, unsigned char * Reserved)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PUI1 ;
		InvokeHelper(0x23e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Datas, Reserved);
		return result;
	}
	BOOL GetUserVerifyStyleBatch(long dwMachineNumber, BSTR * Buffer, long BufferSize, unsigned char * Reserved)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_I4 VTS_PUI1 ;
		InvokeHelper(0x23f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Buffer, BufferSize, Reserved);
		return result;
	}
	BOOL GetDeviceFirmwareVersion(long dwMachineNumber, BSTR * strVersion)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x244, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, strVersion);
		return result;
	}
	BOOL SendFileEx(long dwMachineNumber, LPCTSTR FileName, LPCTSTR FilePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x118, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName, FilePath);
		return result;
	}
	BOOL UploadTheme(long dwMachineNumber, LPCTSTR FileName, LPCTSTR InDevName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x24e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName, InDevName);
		return result;
	}
	BOOL UploadPicture(long dwMachineNumber, LPCTSTR FileName, LPCTSTR InDevName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x24f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName, InDevName);
		return result;
	}
	BOOL DeletePicture(long dwMachineNumber, LPCTSTR FileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x250, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName);
		return result;
	}
	BOOL DownloadPicture(long dwMachineNumber, LPCTSTR FileName, LPCTSTR FilePath)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x251, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, FileName, FilePath);
		return result;
	}
	BOOL TurnOffAlarm(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x253, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL CloseAlarm(long dwMachineNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x254, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber);
		return result;
	}
	BOOL SSR_SetWorkCodeEx(long dwMachineNumber, LPCTSTR WorkCodeNum, LPCTSTR Name)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x258, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, WorkCodeNum, Name);
		return result;
	}
	BOOL SSR_GetWorkCodeEx(long dwMachineNumber, LPCTSTR WorkCodeNum, BSTR * Name)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PBSTR ;
		InvokeHelper(0x259, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, WorkCodeNum, Name);
		return result;
	}
	BOOL SSR_DeleteWorkCodeEx(long dwMachineNumber, LPCTSTR WorkCodeNum)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x25a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, WorkCodeNum);
		return result;
	}
	BOOL SSR_GetGeneralLogDataEx(long dwMachineNumber, BSTR * dwEnrollNumber, long * dwVerifyMode, long * dwInOutMode, long * dwYear, long * dwMonth, long * dwDay, long * dwHour, long * dwMinute, long * dwSecond, BSTR * dwWorkCode)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x25b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, dwEnrollNumber, dwVerifyMode, dwInOutMode, dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond, dwWorkCode);
		return result;
	}
	BOOL SSR_SetWorkCodeExBatch(long dwMachineNumber, LPCTSTR Datas)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x25c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Datas);
		return result;
	}
	BOOL SSR_GetWorkCodeExBatch(long dwMachineNumber, BSTR * Buffer, long BufferSize)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x25d, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Buffer, BufferSize);
		return result;
	}
	BOOL SSR_GetWorkCodeExByID(long dwMachineNumber, long WorkCodeID, BSTR * WorkCodeNum, BSTR * Name)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x25e, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, WorkCodeID, WorkCodeNum, Name);
		return result;
	}
	BOOL SSR_GetWorkCodeIDByName(long dwMachineNumber, LPCTSTR workcodeName, long * WorkCodeID)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PI4 ;
		InvokeHelper(0x25f, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, workcodeName, WorkCodeID);
		return result;
	}
	long get_BatchDataMode()
	{
		long result;
		InvokeHelper(0x262, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_BatchDataMode(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x262, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL SetEventMode(long nType)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x26c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, nType);
		return result;
	}
	BOOL GetAllSFIDName(long dwMachineNumber, BSTR * ShortkeyIDName, long BufferSize1, BSTR * FunctionIDName, long BufferSize2)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_I4 VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x271, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, ShortkeyIDName, BufferSize1, FunctionIDName, BufferSize2);
		return result;
	}
	BOOL SetShortkey(long dwMachineNumber, long ShortKeyID, LPCTSTR ShortKeyName, LPCTSTR FunctionName, long ShortKeyFun, long StateCode, LPCTSTR StateName, LPCTSTR Description, long StateAutoChange, LPCTSTR StateAutoChangeTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR VTS_I4 VTS_BSTR ;
		InvokeHelper(0x272, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, ShortKeyID, ShortKeyName, FunctionName, ShortKeyFun, StateCode, StateName, Description, StateAutoChange, StateAutoChangeTime);
		return result;
	}
	BOOL GetShortkey(long dwMachineNumber, long ShortKeyID, BSTR * ShortKeyName, BSTR * FunctionName, long * ShortKeyFun, long * StateCode, BSTR * StateName, BSTR * Description, long * AutoChange, BSTR * AutoChangeTime)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PI4 VTS_PBSTR VTS_PBSTR VTS_PI4 VTS_PBSTR ;
		InvokeHelper(0x273, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, ShortKeyID, ShortKeyName, FunctionName, ShortKeyFun, StateCode, StateName, Description, AutoChange, AutoChangeTime);
		return result;
	}
	BOOL GetAllAppFun(long dwMachineNumber, BSTR * AppName, BSTR * FunofAppName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR VTS_PBSTR ;
		InvokeHelper(0x276, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, AppName, FunofAppName);
		return result;
	}
	BOOL GetAllRole(long dwMachineNumber, BSTR * RoleName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x277, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, RoleName);
		return result;
	}
	BOOL GetAppOfRole(long dwMachineNumber, long Permission, BSTR * AppName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x278, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Permission, AppName);
		return result;
	}
	BOOL GetFunOfRole(long dwMachineNumber, long Permission, BSTR * FunName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBSTR ;
		InvokeHelper(0x279, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Permission, FunName);
		return result;
	}
	BOOL SetPermOfAppFun(long dwMachineNumber, long Permission, LPCTSTR AppName, LPCTSTR FunName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x27a, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Permission, AppName, FunName);
		return result;
	}
	BOOL DeletePermOfAppFun(long dwMachineNumber, long Permission, LPCTSTR AppName, LPCTSTR FunName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x27b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Permission, AppName, FunName);
		return result;
	}
	BOOL IsUserDefRoleEnable(long dwMachineNumber, long Permission, BOOL * Enable)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PBOOL ;
		InvokeHelper(0x27c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, Permission, Enable);
		return result;
	}
	BOOL SearchDevice(LPCTSTR commType, LPCTSTR address, BSTR * DevBuffer, long DevBufferSize)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_PBSTR VTS_I4 ;
		InvokeHelper(0x119, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, commType, address, DevBuffer, DevBufferSize);
		return result;
	}
	BOOL SetUserIDCardInfo(long dwMachineNumber, LPCTSTR strEnrollNumber, unsigned char * IDCardData, long DataLen)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PUI1 VTS_I4 ;
		InvokeHelper(0x281, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, strEnrollNumber, IDCardData, DataLen);
		return result;
	}
	BOOL GetUserIDCardInfo(long dwMachineNumber, LPCTSTR strEnrollNumber, unsigned char * IDCardData, long * DataLen)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_PUI1 VTS_PI4 ;
		InvokeHelper(0x282, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, strEnrollNumber, IDCardData, DataLen);
		return result;
	}
	BOOL DelUserIDCardInfo(long dwMachineNumber, LPCTSTR strEnrollNumber)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR ;
		InvokeHelper(0x283, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, strEnrollNumber);
		return result;
	}
	BOOL GetPhotoByNameToFile(long dwMachineNumber, LPCTSTR PhotoName, LPCTSTR LocalFileName)
	{
		BOOL result;
		static BYTE parms[] = VTS_I4 VTS_BSTR VTS_BSTR ;
		InvokeHelper(0x284, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, dwMachineNumber, PhotoName, LocalFileName);
		return result;
	}

// Properties
//



};
