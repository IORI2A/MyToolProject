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
#include <cstdio>    // 使用文件描述符


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

	// 增加是否需要 输出日期时间。默认参数都是放后面。
	void LogNotEndl(const char *file, const char *str, bool bOutputDateTime = true);    // 不带换行结束符。
	// 日志工具 提供支持文件符的函数方法接口。
	void LogNotEndl(FILE *file, const char *str, bool bOutputDateTime = true);

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
	static void LOG_NOT_ENDL(const char *file, const char *str, bool bOutputDateTime = true);
	// 日志工具 提供支持文件符的函数方法接口。
	static void LOG_NOT_ENDL(FILE *file, const char *str);
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

public:
	// 与 FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 、 FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL 对应的不带换行结束符
	static void FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR(const char * format, ...);
	static void FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR(const char *file, const char * format, ...);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <string>    // 为适配调测 atlmfc 变更使用 C 运行时库内容。引用c++标准库报错。
#include <time.h> 
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
		char * m_pFuncFileName;
		int m_line;
		char * m_pFunc;
		char * m_pLogFile;

		// 记录对象生命期 （ 转换为时钟数及分钟数 ）
		clock_t m_startClock;
		clock_t m_finishClock;
	};

	// 为方便调用互斥锁的初始化方法，进行前向声明。  OK。
	class CMyMFCStudyLog;
	//void Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION();
} // namespace Tool

// 为方便调用互斥锁的初始化方法，进行前向声明。  这种声明方式是错的。
//class Tool::CMyMFCStudyLog;
//void Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION();

// 使用宏定义，方便使用 __FILE__, __FUNCTION__ 等宏，并简化编写量。
//#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCTION__, "temp.log")
// 为保证在增加互斥锁之前的旧代码可不更改即可运行，在调用之前进行互斥锁的初始化。 问题，但没有合适的地方进行自动释放删除？ 
#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION(); Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCSIG__, "temp.log")


//////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Tool // namespace Tool
{
	// 用于调测MFC库的日志工具
	// 为了加快日志记录速度，保持日志文件运行中一直打开。
	// 同时要求上面的 日志工具 提供支持文件符的函数方法接口。
	class CMyMFCStudyLog
	{
	public:
		// DLL STATUS。 MFC DLL 运行过程中不同时点的状态，自己根据需要手动设定。主要用于指导 调用的不同效率的日志函数方法。
		typedef enum _CMFCDllStatus
		{
			IN_RAW_DLL_MAIN=0
			, IN_GLOBAL_INIT
			, IN_DLL_MAIN
			// 增加一个不进行日志记录的状态
			, IN_NOT_LOG_STATUS
		} CMFCDllStatus;

	private:
		static CMFCDllStatus m_mfcDllStatus;
	public:
		// 设置 DLL STATUS。
		static CMFCDllStatus SET_MFC_DLL_STATUS(const CMFCDllStatus status
			, const char *file, int line, const char *func, const char *logFie);

	private:
		#define MAX_STATIC_FILE 8
		static char * m_staticFiles[MAX_STATIC_FILE];
		static void * m_staticFilePtres[MAX_STATIC_FILE];
		static int m_currentFiles;
	protected:
		// 为方便 SET_NOT_LOG_FOR 使用来记录 m_mfcNotLog 的值，那么应当不与 m_mfcNotLog 关联，为防止外部引用，使用 protect 保护。
		static void LOG_TO_FILE_STR(const char *file, const char *str, bool bOutputDateTime = true);
	public:
		static void LOG_TO_FILE_FORMAT_STR(bool bOutputDateTime, const char *file, const char *format, ...);
		static void LOG_TO_FILE_FORMAT_STR_ENDL(const char *file, const char *format, ...);
		// 为兼容之前日志工具记录实现，提供输出到默认日志文件
		static void LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char *format, ...);
		// 强制输出内容。不受 m_mfcNotLog 计数控制。目前提供给 CMyAutoLogName 使用，强制记录执行调用的函数。（非反向遍历函数调用堆栈）
		static void FORCE_LOG_TO_FILE_FORMAT_STR_ENDL(const char *file, const char *format, ...);

		// 专门用于释放 m_staticFiles 和 m_staticFilePtres 中的资源
		static void FREE();

	private:
		//static bool m_mfcNotLog;
		// 使用引用计数方式
		static int m_mfcNotLog;
	public:
		// 设置 不需要进行日志记录的状态。 // 无法控制 构造函数 初始化列表的执行。
		static void SET_NOT_LOG_FOR(const bool notLog);
		// 增加记录 设置是否打印状态的 文件、行号、函数出处，便于分析日志。
		static void SET_NOT_LOG_FOR(const bool notLog, const char *file, int line, const char *func);

	private:
		// 增加一个日志记录互斥锁，日志记录函数方法使用前需要初始化锁，使用后需要释放锁。
		static CRITICAL_SECTION m_mfcStudyLogCriticalSection;
		// 防止重复初始化互斥锁
		static bool m_bMfcStudyLogCriticalSectionInited;
	public:
		static void INIT_MFC_STUDY_LOG_CRITICAL_SECTION();
		static void DELE_MFC_STUDY_LOG_CRITICAL_SECTION();

	public:
		// 更有效的控制调用堆栈打印。及时判定 m_mfcNotLog 计数，是否需要记录，提高速度。
		// 如果使用该方法涉及到 引用 ToolLogStackWalker.h 及 StackWalker 工程中相关代码文件，请加载引用这些内容。
		// 无法从类中分离出方法的声明。 其定义实现于 ToolLogStackWalker.cpp 中。
		static void LOG_TO_DEFAULT_FILE_STACK_WALKER();
	};
} // namespace Tool


// 使用宏便于记录文件、行号、函数名等信息，便于分析日志内容
#define TOOL_SET_NOT_LOG(notLog)     Tool::CMyMFCStudyLog::SET_NOT_LOG_FOR(notLog, __FILE__, __LINE__, __FUNCTION__) 

#define TOOL_SET_MFC_DLL_STATUS(status)    Tool::CMyMFCStudyLog::SET_MFC_DLL_STATUS(status, __FILE__, __LINE__, __FUNCTION__, "temp.log")


//////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Tool // namespace Tool
{
	// VC++ 使用 _bstr_t 来封装 BSTR 。 comutil.h
	// 提供 BSTR 的相关操作（构建、赋值、附加、脱离、提取长度、提取地址等） ，以及与 wchar_t 及 char 之间的转换。
	// _bstr_t 实现 BSTR 与 wchar_t 及 char 之间的转换是通过 _com_util::ConvertBSTRToString 来实现的。
	// 有关详情参考 MSDN 中 Compiler COM Support 。

	// BSTR 是一种复合类型(composite data type)，属于 COM 组件自动化技术(Automation)范畴。
	// 参考 MSDN : Win32 and COM Development > Component Development > Automation > SDK Documentation > Automation Programming Reference 
	// BSTR 如果需要己方释放，请记住调用 SysFreeString 。 MSDN : String Manipulation Functions 。
	// BSTR 是零结尾字符串(strings are zero-terminated)，但内部是 Unicode 字符 (wide or double-byte characters)。 其地址指向就是字符（二进制数据）的首地址，未尾有结束符（two null characters (0x00)）
	// typedef OLECHAR FAR * BSTR;
	// typedef WCHAR  OLECHAR;
	// 大多数据情况下可被视作宽字符串 (in most cases they can be treated just like OLECHAR* strings)。也即可以直接用于需要宽字符串的地方！？
	// 推断 BSTR 的结构：
	// | Length prefix(32-bit integer) | Data string | Terminator(two null characters, 0x0000) |
	//                                  ^
	//                                  |
	// |                                BSTR地址指向                                           |
	// BSTR 根据机器结构不同，表示也不同。
	// In 32-bit OLE, BSTRs use Unicode like all other strings in 32-bit OLE. In 16-bit OLE, BSTRs use ANSI. Win32 provides MultiByteToWideChar and WideCharToMultiByte to convert ANSI strings to Unicode, and Unicode strings to ANSI. 
	// the preferred method of passing binary data is to use a SAFEARRAY of VT_UI1. 


	// BSTR、char*和CString转换
	// https://blog.csdn.net/zeuskaaba/article/details/4082826

	// char/wchar 与 CString 转换。 （这一个使用比较多不再列出）

	// BSTR 与 char 转换。
	// 方法一，使用 _com_util::ConvertBSTRToString 、 _com_util::ConvertStringToBSTR 。
	// 方法二，使用 _bstr_t 。
	// 方法三，仅提供 char 转换成 BSTR ，SysAllocStringByteLen("Test",4); 。 SysAllocString(L"Test");  SysAllocStringLen(L"Test",4);  ::
	// 方法四，仅提供 char 转换成 BSTR , COleVariant 或 _variant_t 。
		//COleVariant strVar("This is a test");
		//_variant_t strVar("This is a test");
		//BSTR bstrText = strVar.bstrVal; 
	// 方法四，使用 CComBSTR。（ ATL 使用相对较少）

	// BSTR 与 wchar 转换。
	// 方法一，使用 _bstr_t 。
	// 方法二，仅提供 wchar 转换成 BSTR ，SysAllocString(L"Test");  SysAllocStringLen(L"Test",4);  。 

	// BSTR 与 CString 转换。
	// CString 提供 CStringT::AllocSysString (请记住调用 SysFreeString 释放。) 、 CStringT构造\赋值函数(经调测是 CStringT::CStringT(const XCHAR* pszSrc);) 来实现。
		//BSTR bstrText = ::SysAllocString(L"Test");	
		//CString str(bstrText); // CString::CStringT(const XCHAR* pszSrc); BSTR 内部是 Unicode 字符 (wide or double-byte characters)。 可直接转换地址为 whcar* ？？？经调测 BSTR 地址与传参后 XCHAR* 地址相同。
		//str = bstrText; 

	// Unicode 与 ANSI 转换。
	// win32 系统提供使用 MultiByteToWideChar 、 WideCharToMultiByte 。
	// 参考 MSDN : Win32 and COM Development > User Interface > International > SDK Documentation > International Text Display > Unicode and Character Sets


} // namespace Tool


#endif /*__TOOL_H__*/