#ifndef __TOOL_H__
#define __TOOL_H__

#pragma once

#ifdef _WINDOWS //;_USRDLL // WIN32程序使用
#include <windows.h>
#else // _WINDOWS

#ifdef _LIB // 静态库使用
#include <windows.h>
#else // _LIB

#ifndef _AFXDLL // 其它情况
#include <windows.h>
#else // _AFXDLL // DLL动态库使用
#include "afxwin.h"
#endif // _AFXDLL

#endif // _LIB

#endif // _WINDOWS


//#include <string>


//////////////////////////////////////////////////////////////////////////////////////////////////////
class CMyLog
{
	friend class CTool;
private:
	CRITICAL_SECTION m_myLogCriticalSection;
	//bool m_bLogCriticalSectionInited;

//public:
	CMyLog(void);
	~CMyLog(void);

	//void LogEndl(const CString &str);
	void LogEndl(const char *file, const char *str);
	void LogEndl(const wchar_t *file, const wchar_t *str);

	void LogNotEndl(const char *file, const char *str);    // 不带换行结束符。

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
	static void LOG_ENDL(const char *str);    // 支持直接文本内容。 带换行结束符。
	static void LOG_ENDL(const wchar_t *str);
	static void LOG_ENDL(const char *file, const char *str);
	static void LOG_ENDL(const wchar_t *file, const wchar_t *str);
	static void LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char * format, ...);    // 支持格式化文本。 带换行结束符。
	static void LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...);
	static void LOG_NOT_ENDL(const char *str);    // 支持直接文本内容。 不带换行结束符。
	static void LOG_NOT_ENDL(const char *file, const char *str);
	static void LOG_TO_DEFAULT_FILE_FORMAT_STR(const char * format, ...);    // 不带换行结束符。
	static void LOG_TO_SPECIFIC_FILE_FORMAT_STR(const char *file, const char * format, ...);

	//
	//private:
	//
	//#ifdef UNICODE
	//	static void __LOG_STR_ENDL(const wchar_t *file, const wchar_t *str);
	//#else
	//	static void __LOG_STR_ENDL(const char *file, const char *str);
	//#endif

private:
	static char m_staticCharCurrentTimeBuffer[128];
	static wchar_t m_staticWCharCurrentTimeBuffer[128];
public:
	//static std::string GET_CURRENT_TIME(const char *format);
	static const char * GET_CURRENT_TIME(const char *format);
	static const wchar_t * GET_CURRENT_TIME(const wchar_t *format);
	static const char * GET_LOCAL_CURRENT_TIME();
	static const char * GET_SYSTEM_CURRENT_TIME();
	// 获取时间函数 增加支持 UNICODE 版本
	static const wchar_t * GET_W_LOCAL_CURRENT_TIME();
	static const wchar_t * GET_W_SYSTEM_CURRENT_TIME();

public:
	static int Ping(const wchar_t *strIP);
	static int Ping(const char *strIP);

public:
	// RawDllMain 执行时，全局/静态对象还没有执行构造函数。因此专门设计一个函数形式的日志工具，与日志对象类同，但没有互斥锁了。
	static void FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char * format, ...);
	static void FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...);

private:
	// 为 FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 、 FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL 增加互斥锁
	static CRITICAL_SECTION m_toolFunLogCriticalSection;
	static bool m_bToolFunLogCriticalSectionInited;
public:
	static void INIT_FUN_LOG_CRITICAL_SECTION();
	static void DELE_FUN_LOG_CRITICAL_SECTION();
};


//#include <string>    // 为适配调测 atlmfc 变更使用 C 运行时库内容。引用c++标准库报错。
namespace Tool // namespace Tool
{
	// 增加一个方便记录执行函数信息的日志工具。 
	class CMyAutoLogName
	{
	public:
		CMyAutoLogName(const char *file, int line, const char *func, const char *logFie);
		CMyAutoLogName(const char *file, const char *func, const char *logFie);
		~CMyAutoLogName();

	private:
		//std::string m_file;
		//int m_line;
		//std::string m_func;
		//std::string m_logFile;
		char * m_pFile;
		int m_line;
		char * m_pFunc;
		char * m_pLogFile;
	};
} // namespace Tool

// 使用宏定义，方便使用 __FILE__, __FUNCTION__ 等宏，并简化编写量。
//#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCTION__, "temp.log")
#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCSIG__, "temp.log")




#endif /*__TOOL_H__*/