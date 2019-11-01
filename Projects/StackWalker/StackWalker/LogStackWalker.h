#pragma once

#include "StackWalker.h"


// �̳�ʵ��Ϊ����¼���Ʒ���
class CLogStackWalker : public StackWalker
{
public:
	CLogStackWalker(void);
	~CLogStackWalker(void);

protected:
	virtual void OnOutput(LPCSTR szText);
	virtual void OnLoadModule(LPCSTR img, LPCSTR mod, DWORD64 baseAddr, DWORD size, DWORD result, LPCSTR symType, LPCSTR pdbName, ULONGLONG fileVersion);
	virtual void OnSymInit(LPCSTR szSearchPath, DWORD symOptions, LPCSTR szUserName);
	virtual void OnDbgHelpErr(LPCSTR szFuncName, DWORD gle, DWORD64 addr);
};

