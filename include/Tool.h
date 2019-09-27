#ifndef __TOOL_H__
#define __TOOL_H__

#pragma once

#include <windows.h>
//#include "afxwin.h"

//#include <string>


//////////////////////////////////////////////////////////////////////////////////////////////////////
class CMyLog
{
	friend class CTool;
private:
	CRITICAL_SECTION m_criticalSection;

//public:
	CMyLog(void);
	~CMyLog(void);

	//void LogEndl(const CString &str);
	void LogEndl(const char *file, const char *str);
	void LogEndl(const wchar_t *file, const wchar_t *str);

//private:

//#ifdef UNICODE
//	void __LogStrEndl(const wchar_t *file, const wchar_t *str);
//#else
//	void __LogStrEndl(const char *file, const char *str);
//#endif

	//void __LogStrEndl(const wchar_t *file, const wchar_t *str);
	//void __LogStrEndl(const char *file, const char *str);
};


//////////////////////////////////////////////////////////////////////////////////////////////////////
class CTool
{
public:
//	CTool(void);
//	~CTool(void);


private:
	static CMyLog m_staticMyLog;
public:
	//static void LOG_ENDL(const CString &str);
	static void LOG_ENDL(const char *str);
	static void LOG_ENDL(const wchar_t *str);
	static void LOG_ENDL(const char *file, const char *str);
	static void LOG_ENDL(const wchar_t *file, const wchar_t *str);

private:
	static char m_staticCharCurrentTimeBuffer[128];
	static wchar_t m_staticWCharCurrentTimeBuffer[128];
public:
	//static std::string GET_CURRENT_TIME(const char *format);
	static const char * GET_CURRENT_TIME(const char *format);
	static const wchar_t * GET_CURRENT_TIME(const wchar_t *format);
	static const char * GET_LOCAL_CURRENT_TIME();
	static const char * GET_SYSTEM_CURRENT_TIME();
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