#include "../include/Tool.h"

#include <fstream>
#include <ctime>



CMyLog CTool::m_staticMyLog;


//CTool::CTool(void)
//{
//}
//
//
//CTool::~CTool(void)
//{
//}


//void CTool::LOG_ENDL(const CString &str)
//{
//	m_staticMyLog.LogEndl(str);
//}

void CTool::LOG_ENDL(const char *str)
{
	m_staticMyLog.LogEndl("temp.log", str);
}

void CTool::LOG_ENDL(const wchar_t *str)
{
	m_staticMyLog.LogEndl(L"temp.log", str);
}

// const char *file : 文件名。 须有NULL结束符。
// const char *str : 日志信息。 须有NULL结束符。
void CTool::LOG_ENDL(const char *file, const char *str)
{
	m_staticMyLog.LogEndl(file, str);
}

void CTool::LOG_ENDL(const wchar_t *file, const wchar_t *str)
{
	m_staticMyLog.LogEndl(file, str);
}

// const char *format : 日期格式化指示字符。参考 strftime 函数。
//std::string CTool::GET_CURRENT_TIME(const char *format)
//{
//	time_t rawtime;
//	struct tm * timeinfo;
//	char buffer[128] = {};
//
//	time (&rawtime);
//	timeinfo = localtime (&rawtime);
//	strftime(buffer, 128, format/*"%Y-%m-%d %H:%M:%S "*/, timeinfo);
//
//	return buffer;
//}

#pragma warning(disable: 4996)
char CTool::m_staticCharCurrentTimeBuffer[128] = {};
const char * CTool::GET_CURRENT_TIME(const char *format)
{
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime(m_staticCharCurrentTimeBuffer, 128, format, timeinfo);

	return m_staticCharCurrentTimeBuffer;
}

wchar_t CTool::m_staticWCharCurrentTimeBuffer[128] = {};
const wchar_t * CTool::GET_CURRENT_TIME(const wchar_t *format)
{
	struct tm today;
	time_t ltime;
	time( &ltime );
	errno_t err = _localtime64_s( &today, &ltime );
	if (err)
	{
		swprintf_s(m_staticWCharCurrentTimeBuffer, 128, L"1900-01-01 00:00:00 ");
	}

	wcsftime(m_staticWCharCurrentTimeBuffer, 128, L"%Y-%m-%d %H:%M:%S ", &today );

	return m_staticWCharCurrentTimeBuffer;
}

const char * CTool::GET_LOCAL_CURRENT_TIME()
{
	SYSTEMTIME st;
	// 本地时间 LocalTime 本地时间会根据机器设置的时区，将系统时间进行调整以适合本地时区。
	GetLocalTime(&st);
	sprintf(m_staticCharCurrentTimeBuffer, "%d-%d-%d %d:%d:%d.%d ", 
		st.wYear, st.wMonth, st.wDay, 
		st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	return m_staticCharCurrentTimeBuffer;
}

const char * CTool::GET_SYSTEM_CURRENT_TIME()
{
	/////////////////////// 获取系统时间 ///////////////////////
	// 系统时间 SystemTime UTC
	SYSTEMTIME st;
	GetSystemTime(&st);
	sprintf(m_staticCharCurrentTimeBuffer, "%d-%d-%d %d:%d:%d.%d ", 
		st.wYear, st.wMonth, st.wDay, 
		st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	//TRACE("\n.......[%d-%d-%d %d:%d:%d.%d].......", 
	//	st.wYear, st.wMonth, st.wDay, 
	//	st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//TRACE("\n.......[%d-%d-%d %d:%d:%d.%d].......", 
	//	st.wYear, st.wMonth, st.wDay, 
	//	(st.wHour+8)%24, st.wMinute, st.wSecond, st.wMilliseconds);

	return m_staticCharCurrentTimeBuffer;
}
#pragma warning(default: 4996)



//////////////////////////////////////////////////////////////////////////////////////////////////////

CMyLog::CMyLog(void)
{
	InitializeCriticalSection(&m_criticalSection);
}


CMyLog::~CMyLog(void)
{
	DeleteCriticalSection(&m_criticalSection);
}


//void CMyLog::LogEndl(const CString &str)
//{
//	//#ifdef _DEBUG
//
//	//EnterCriticalSection(&m_criticalSection);
//
//	//std::ofstream of(TEXT("\\NandFlash\\test.txt"), std::ios_base::out | std::ios_base::app );
//	//of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
//	//of << str.GetString();
//	//of << std::endl;
//	__LogStrEndl("test.txt", str);
//
//	//LeaveCriticalSection(&m_criticalSection);
//
//	//#endif
//}

// const char *file : 文件名。 须有NULL结束符。
// const char *str : 日志信息。 须有NULL结束符。
void CMyLog::LogEndl(const char *file, const char *str)
{
	EnterCriticalSection(&m_criticalSection);

	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
	//of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
	of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
	of << str;
	of << std::endl;

	//__LogStrEndl(file, str);

	LeaveCriticalSection(&m_criticalSection);
}

void CMyLog::LogEndl(const wchar_t *file, const wchar_t *str)
{
	//__LogStrEndl(file, str);

	EnterCriticalSection(&m_criticalSection);

	std::wofstream of(file, std::ios_base::out | std::ios_base::app );
	of << CTool::GET_CURRENT_TIME(L"%Y-%m-%d %H:%M:%S ");
	of << str;
	of << std::endl;

	LeaveCriticalSection(&m_criticalSection);
}

//// const char *file : 文件名。 须有NULL结束符。
//// const char *str : 日志信息。 须有NULL结束符。
//#ifdef UNICODE
//	void CMyLog::__LogStrEndl(const wchar_t *file, const wchar_t *str)
//#else
//	void CMyLog::__LogStrEndl(const char *file, const char *str)
//#endif
//{
//	EnterCriticalSection(&m_criticalSection);
//
//#ifdef UNICODE
//	std::wofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTime::GetCurrentTime().Format(L"%Y-%m-%d %H:%M:%S ").GetString();
//#else
//	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
//#endif
//
//	of << str;
//	of << std::endl;
//
//	LeaveCriticalSection(&m_criticalSection);
//}

//// const char *file : 文件名。 须有NULL结束符。
//// const char *str : 日志信息。 须有NULL结束符。
//#ifdef UNICODE
//void CMyLog::__LogStrEndl(const wchar_t *file, const wchar_t *str)
//#else
//void CMyLog::__LogStrEndl(const char *file, const char *str)
//#endif
//{
//	EnterCriticalSection(&m_criticalSection);
//
//#ifdef UNICODE
//	std::wofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME(L"%Y-%m-%d %H:%M:%S ");
//#else
//	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
//#endif
//
//	of << str;
//	of << std::endl;
//
//	LeaveCriticalSection(&m_criticalSection);
//}

//// const char *file : 文件名。 须有NULL结束符。
//// const char *str : 日志信息。 须有NULL结束符。
//void CMyLog::__LogStrEndl(const char *file, const char *str)
//{
//	EnterCriticalSection(&m_criticalSection);
//
//	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
//	of << str;
//	of << std::endl;
//
//	LeaveCriticalSection(&m_criticalSection);
//}
//
//void CMyLog::__LogStrEndl(const wchar_t *file, const wchar_t *str)
//{
//	EnterCriticalSection(&m_criticalSection);
//
//	std::wofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME(L"%Y-%m-%d %H:%M:%S ");
//	of << str;
//	of << std::endl;
//
//	LeaveCriticalSection(&m_criticalSection);
//}


