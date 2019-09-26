#ifndef __TOOL_H__
#define __TOOL_H__

#pragma once

//#include <windows.h>
#include "afxwin.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////
class CMyLog
{
private:
	CRITICAL_SECTION m_criticalSection;

public:
	CMyLog(void);
	~CMyLog(void);

	void LogEndl(const CString &str);
	void LogEndl(const char *file, const char *str);

private:

#ifdef UNICODE
	void __LogStrEndl(const wchar_t *file, const wchar_t *str);
#else
	void __LogStrEndl(const char *file, const char *str);
#endif

};


//////////////////////////////////////////////////////////////////////////////////////////////////////
class CTool
{
private:
	static CMyLog m_staticMyLog;

public:
//	CTool(void);
//	~CTool(void);


	static void LOG_ENDL(const CString &str);
	static void LOG_ENDL(const char *file, const char *str);
//
//private:
//
//#ifdef UNICODE
//	static void __LOG_STR_ENDL(const wchar_t *file, const wchar_t *str);
//#else
//	static void __LOG_STR_ENDL(const char *file, const char *str);
//#endif

};



#endif /*__TOOL_H__*/