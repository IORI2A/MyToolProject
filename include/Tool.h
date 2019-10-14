#ifndef __TOOL_H__
#define __TOOL_H__

#pragma once

#ifndef _AFXDLL
#include <windows.h>
#else
//#include "afxwin.h"
#endif


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

	void LogNotEndl(const char *file, const char *str);    // �������н�������

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
	static void LOG_NOT_ENDL(const char *file, const char *str);
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
	//static std::string GET_CURRENT_TIME(const char *format);
	static const char * GET_CURRENT_TIME(const char *format);
	static const wchar_t * GET_CURRENT_TIME(const wchar_t *format);
	static const char * GET_LOCAL_CURRENT_TIME();
	static const char * GET_SYSTEM_CURRENT_TIME();

public:
	static int Ping(const wchar_t *strIP);
	static int Ping(const char *strIP);

public:
	// RawDllMain ִ��ʱ��ȫ��/��̬����û��ִ�й��캯�������ר�����һ��������ʽ����־���ߣ�����־������ͬ����û�л������ˡ�
	static void FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char * format, ...);
	static void FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...);
};


#include <string>
namespace Tool // namespace Tool
{
	// ����һ�������¼ִ�к�����Ϣ����־���ߡ� 
	class CMyAutoLogName
	{
	public:
		CMyAutoLogName(const char *file, int line, const char *func, const char *logFie);
		CMyAutoLogName(const char *file, const char *func, const char *logFie);
		~CMyAutoLogName();

	private:
		std::string m_file;
		int m_line;
		std::string m_func;
		std::string m_logFile;
	};
} // namespace Tool

// ʹ�ú궨�壬����ʹ�� __FILE__, __FUNCTION__ �Ⱥ꣬���򻯱�д����
//#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCTION__, "temp.log")
#define TOOL_AUTO_LOG_FUNCTION_INFO() Tool::CMyAutoLogName __myAutoLog(__FILE__, __FUNCSIG__, "temp.log")




#endif /*__TOOL_H__*/