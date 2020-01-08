#ifndef __TOOL_H__
#define __TOOL_H__

#pragma once

#ifdef _WINDOWS //;_USRDLL // WIN32����ʹ��
#include <windows.h>
#else // _WINDOWS

#ifdef _LIB // ��̬��ʹ��
#include <windows.h>
#else // _LIB

#ifndef _AFXDLL // �������
#include <windows.h>
#else // _AFXDLL // DLL��̬��ʹ��
#include "afxwin.h"
#endif // _AFXDLL

#endif // _LIB

#endif // _WINDOWS


//#include <string>
#include <cstdio>    // ʹ���ļ�������


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

	// �����Ƿ���Ҫ �������ʱ�䡣Ĭ�ϲ������Ƿź��档
	void LogNotEndl(const char *file, const char *str, bool bOutputDateTime = true);    // �������н�������
	// ��־���� �ṩ֧���ļ����ĺ��������ӿڡ�
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
	static void LOG_ENDL(const char *str);    // ֧��ֱ���ı����ݡ� �����н�������
	static void LOG_ENDL(const wchar_t *str);
	static void LOG_ENDL(const char *file, const char *str);
	static void LOG_ENDL(const wchar_t *file, const wchar_t *str);
	static void LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char * format, ...);    // ֧�ָ�ʽ���ı��� �����н�������
	static void LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...);
	static void LOG_NOT_ENDL(const char *str);    // ֧��ֱ���ı����ݡ� �������н�������
	static void LOG_NOT_ENDL(const char *file, const char *str, bool bOutputDateTime = true);
	// ��־���� �ṩ֧���ļ����ĺ��������ӿڡ�
	static void LOG_NOT_ENDL(FILE *file, const char *str);
	static void LOG_TO_DEFAULT_FILE_FORMAT_STR(const char * format, ...);    // �������н�������
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
	// struct tm û�к����ֶΡ�����Cϵ�еĺ��������޷���ӡ������Ϣ��
	// SYSTEMTIME st �к����ֶΡ���֧�ֺ��������Windowsϵͳ������
	//static std::string GET_CURRENT_TIME(const char *format);
	static const char * GET_CURRENT_TIME(const char *format);
	static const wchar_t * GET_CURRENT_TIME(const wchar_t *format);
	static const char * GET_LOCAL_CURRENT_TIME();
	static const char * GET_SYSTEM_CURRENT_TIME();
	// ��ȡʱ�亯�� ����֧�� UNICODE �汾
	static const wchar_t * GET_W_LOCAL_CURRENT_TIME();
	static const wchar_t * GET_W_SYSTEM_CURRENT_TIME();

public:
	static int Ping(const wchar_t *strIP);
	static int Ping(const char *strIP);

public:
	// RawDllMain ִ��ʱ��ȫ��/��̬����û��ִ�й��캯�������ר�����һ��������ʽ����־���ߣ�����־������ͬ����û�л������ˡ�
	static void FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char * format, ...);
	static void FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...);

private:
	// Ϊ FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL �� FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL ���ӻ�����
	static CRITICAL_SECTION m_toolFunLogCriticalSection;
	static bool m_bToolFunLogCriticalSectionInited;
public:
	static void INIT_FUN_LOG_CRITICAL_SECTION();
	static void DELE_FUN_LOG_CRITICAL_SECTION();

public:
	// �� FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL �� FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL ��Ӧ�Ĳ������н�����
	static void FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR(const char * format, ...);
	static void FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR(const char *file, const char * format, ...);
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <string>    // Ϊ������� atlmfc ���ʹ�� C ����ʱ�����ݡ�����c++��׼�ⱨ��
#include <time.h> 
namespace Tool // namespace Tool
{
	// ����һ�������¼ִ�к�����Ϣ����־���ߡ� 
	class CMyAutoLogName
	{
	public:
		CMyAutoLogName(const char *file, int line, const char *func, const char *logFie);
		CMyAutoLogName(const char *file, const char *func, const char *logFie);
		// �ṩһ�����Ľ���¼����������Ϣ�Ľӿ�
		CMyAutoLogName(const char *func, const char *logFie);
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

		// ���ļ������������ȹ���ʱ���ռ䲻���ã����ж��쳣д����
		static const unsigned int m_pFuncFileNameLen;
		static const unsigned int m_pFuncLen;
		static const unsigned int m_pLogFileLen;

		// ��¼���������� �� ת��Ϊʱ������������ ��
		clock_t m_startClock;
		clock_t m_finishClock;
	};

	// Ϊ������û������ĳ�ʼ������������ǰ��������  OK��
	class CMyMFCStudyLog;
	//void Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION();
} // namespace Tool

// Ϊ������û������ĳ�ʼ������������ǰ��������  ����������ʽ�Ǵ�ġ�
//class Tool::CMyMFCStudyLog;
//void Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION();

// ʹ�ú궨�壬����ʹ�� __FILE__, __FUNCTION__ �Ⱥ꣬���򻯱�д����
//#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCTION__, "temp.log")
// Ϊ��֤�����ӻ�����֮ǰ�ľɴ���ɲ����ļ������У��ڵ���֮ǰ���л������ĳ�ʼ���� ���⣬��û�к��ʵĵط������Զ��ͷ�ɾ���� 
#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION(); Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCSIG__, "temp.log")
// �ṩһ�����ļ�¼����������Ϣ�Ľӿڡ�
#define TOOL_AUTO_LOG_FUNCTION_INFO_NO_FILE() Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION(); Tool::CMyAutoLogName __myAutoLog(__FUNCTION__, "temp.log")


//////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Tool // namespace Tool
{
	// ���ڵ���MFC�����־����
	// Ϊ�˼ӿ���־��¼�ٶȣ�������־�ļ�������һֱ�򿪡�
	// ͬʱҪ������� ��־���� �ṩ֧���ļ����ĺ��������ӿڡ�
	class CMyMFCStudyLog
	{
	public:
		// DLL STATUS�� MFC DLL ���й����в�ͬʱ���״̬���Լ�������Ҫ�ֶ��趨����Ҫ����ָ�� ���õĲ�ͬЧ�ʵ���־����������
		typedef enum _CMFCDllStatus
		{
			IN_RAW_DLL_MAIN=0
			, IN_GLOBAL_INIT
			, IN_DLL_MAIN
			// ����һ����������־��¼��״̬
			, IN_NOT_LOG_STATUS
		} CMFCDllStatus;

	private:
		static CMFCDllStatus m_mfcDllStatus;
	public:
		// ���� DLL STATUS��
		static CMFCDllStatus SET_MFC_DLL_STATUS(const CMFCDllStatus status
			, const char *file, int line, const char *func, const char *logFie);

	private:
		#define MAX_STATIC_FILE 8
		static char * m_staticFiles[MAX_STATIC_FILE];
		static void * m_staticFilePtres[MAX_STATIC_FILE];
		static int m_currentFiles;
	protected:
		// Ϊ���� SET_NOT_LOG_FOR ʹ������¼ m_mfcNotLog ��ֵ����ôӦ������ m_mfcNotLog ������Ϊ��ֹ�ⲿ���ã�ʹ�� protect ������
		static void LOG_TO_FILE_STR(const char *file, const char *str, bool bOutputDateTime = true);
	public:
		static void LOG_TO_FILE_FORMAT_STR(bool bOutputDateTime, const char *file, const char *format, ...);
		static void LOG_TO_FILE_FORMAT_STR_ENDL(const char *file, const char *format, ...);
		// Ϊ����֮ǰ��־���߼�¼ʵ�֣��ṩ�����Ĭ����־�ļ�
		static void LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char *format, ...);
		// ǿ��������ݡ����� m_mfcNotLog �������ơ�Ŀǰ�ṩ�� CMyAutoLogName ʹ�ã�ǿ�Ƽ�¼ִ�е��õĺ��������Ƿ�������������ö�ջ��
		static void FORCE_LOG_TO_FILE_FORMAT_STR_ENDL(const char *file, const char *format, ...);

		// ר�������ͷ� m_staticFiles �� m_staticFilePtres �е���Դ
		static void FREE();

	private:
		//static bool m_mfcNotLog;
		// ʹ�����ü�����ʽ
		static int m_mfcNotLog;
	public:
		// ���� ����Ҫ������־��¼��״̬�� // �޷����� ���캯�� ��ʼ���б��ִ�С�
		static void SET_NOT_LOG_FOR(const bool notLog);
		// ���Ӽ�¼ �����Ƿ��ӡ״̬�� �ļ����кš��������������ڷ�����־��
		static void SET_NOT_LOG_FOR(const bool notLog, const char *file, int line, const char *func);

	private:
		// ����һ����־��¼����������־��¼��������ʹ��ǰ��Ҫ��ʼ������ʹ�ú���Ҫ�ͷ�����
		static CRITICAL_SECTION m_mfcStudyLogCriticalSection;
		// ��ֹ�ظ���ʼ��������
		static bool m_bMfcStudyLogCriticalSectionInited;
	public:
		static void INIT_MFC_STUDY_LOG_CRITICAL_SECTION();
		static void DELE_MFC_STUDY_LOG_CRITICAL_SECTION();

	public:
		// ����Ч�Ŀ��Ƶ��ö�ջ��ӡ����ʱ�ж� m_mfcNotLog �������Ƿ���Ҫ��¼������ٶȡ�
		// ���ʹ�ø÷����漰�� ���� ToolLogStackWalker.h �� StackWalker ��������ش����ļ��������������Щ���ݡ�
		// �޷������з���������������� �䶨��ʵ���� ToolLogStackWalker.cpp �С�
		static void LOG_TO_DEFAULT_FILE_STACK_WALKER();
	};
} // namespace Tool


// ʹ�ú���ڼ�¼�ļ����кš�����������Ϣ�����ڷ�����־����
#define TOOL_SET_NOT_LOG(notLog)     Tool::CMyMFCStudyLog::SET_NOT_LOG_FOR(notLog, __FILE__, __LINE__, __FUNCTION__) 

#define TOOL_SET_MFC_DLL_STATUS(status)    Tool::CMyMFCStudyLog::SET_MFC_DLL_STATUS(status, __FILE__, __LINE__, __FUNCTION__, "temp.log")


//////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Tool // namespace Tool
{
	// VC++ ʹ�� _bstr_t ����װ BSTR �� comutil.h
	// �ṩ BSTR ����ز�������������ֵ�����ӡ����롢��ȡ���ȡ���ȡ��ַ�ȣ� ���Լ��� wchar_t �� char ֮���ת����
	// _bstr_t ʵ�� BSTR �� wchar_t �� char ֮���ת����ͨ�� _com_util::ConvertBSTRToString ��ʵ�ֵġ�
	// �й�����ο� MSDN �� Compiler COM Support ��

	// BSTR ��һ�ָ�������(composite data type)������ COM ����Զ�������(Automation)���롣
	// �ο� MSDN : Win32 and COM Development > Component Development > Automation > SDK Documentation > Automation Programming Reference 
	// BSTR �����Ҫ�����ͷţ����ס���� SysFreeString �� MSDN : String Manipulation Functions ��
	// BSTR �����β�ַ���(strings are zero-terminated)�����ڲ��� Unicode �ַ� (wide or double-byte characters)�� ���ַָ������ַ������������ݣ����׵�ַ��δβ�н�������two null characters (0x00)��
	// typedef OLECHAR FAR * BSTR;
	// typedef WCHAR  OLECHAR;
	// �����������¿ɱ��������ַ��� (in most cases they can be treated just like OLECHAR* strings)��Ҳ������ֱ��������Ҫ���ַ����ĵط�����
	// �ƶ� BSTR �Ľṹ��
	// | Length prefix(32-bit integer) | Data string | Terminator(two null characters, 0x0000) |
	//                                  ^
	//                                  |
	// |                                BSTR��ַָ��                                           |
	// BSTR ���ݻ����ṹ��ͬ����ʾҲ��ͬ��
	// In 32-bit OLE, BSTRs use Unicode like all other strings in 32-bit OLE. In 16-bit OLE, BSTRs use ANSI. Win32 provides MultiByteToWideChar and WideCharToMultiByte to convert ANSI strings to Unicode, and Unicode strings to ANSI. 
	// the preferred method of passing binary data is to use a SAFEARRAY of VT_UI1. 


	// BSTR��char*��CStringת��
	// https://blog.csdn.net/zeuskaaba/article/details/4082826

	// char/wchar �� CString ת���� ����һ��ʹ�ñȽ϶಻���г���

	// BSTR �� char ת����
	// ����һ��ʹ�� _com_util::ConvertBSTRToString �� _com_util::ConvertStringToBSTR ��
	// ��������ʹ�� _bstr_t ��
	// �����������ṩ char ת���� BSTR ��SysAllocStringByteLen("Test",4); �� SysAllocString(L"Test");  SysAllocStringLen(L"Test",4);  ::
	// �����ģ����ṩ char ת���� BSTR , COleVariant �� _variant_t ��
		//COleVariant strVar("This is a test");
		//_variant_t strVar("This is a test");
		//BSTR bstrText = strVar.bstrVal; 
	// �����ģ�ʹ�� CComBSTR���� ATL ʹ����Խ��٣�

	// BSTR �� wchar ת����
	// ����һ��ʹ�� _bstr_t ��
	// �����������ṩ wchar ת���� BSTR ��SysAllocString(L"Test");  SysAllocStringLen(L"Test",4);  �� 

	// BSTR �� CString ת����
	// CString �ṩ CStringT::AllocSysString (���ס���� SysFreeString �ͷš�) �� CStringT����\��ֵ����(�������� CStringT::CStringT(const XCHAR* pszSrc);) ��ʵ�֡�
		//BSTR bstrText = ::SysAllocString(L"Test");	
		//CString str(bstrText); // CString::CStringT(const XCHAR* pszSrc); BSTR �ڲ��� Unicode �ַ� (wide or double-byte characters)�� ��ֱ��ת����ַΪ whcar* ������������ BSTR ��ַ�봫�κ� XCHAR* ��ַ��ͬ��
		//str = bstrText; 

	// Unicode �� ANSI ת����
	// win32 ϵͳ�ṩʹ�� MultiByteToWideChar �� WideCharToMultiByte ��
	// �ο� MSDN : Win32 and COM Development > User Interface > International > SDK Documentation > International Text Display > Unicode and Character Sets


} // namespace Tool


#endif /*__TOOL_H__*/