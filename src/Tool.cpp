#include "../include/Tool.h"

#include <fstream>



CMyLog CTool::m_staticMyLog;


//CTool::CTool(void)
//{
//}
//
//
//CTool::~CTool(void)
//{
//}


void CTool::LOG_ENDL(const CString &str)
{
	m_staticMyLog.LogEndl(str);
}

// const char *file : 文件名。 须有NULL结束符。
// const char *str : 日志信息。 须有NULL结束符。
void CTool::LOG_ENDL(const char *file, const char *str)
{
	m_staticMyLog.LogEndl(file, str);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

CMyLog::CMyLog(void)
{
	InitializeCriticalSection(&m_criticalSection);
}


CMyLog::~CMyLog(void)
{
	DeleteCriticalSection(&m_criticalSection);
}


void CMyLog::LogEndl(const CString &str)
{
	//#ifdef _DEBUG

	//EnterCriticalSection(&m_criticalSection);

	//std::ofstream of(TEXT("\\NandFlash\\test.txt"), std::ios_base::out | std::ios_base::app );
	//of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
	//of << str.GetString();
	//of << std::endl;
	__LogStrEndl("test.txt", str);

	//LeaveCriticalSection(&m_criticalSection);

	//#endif
}

// const char *file : 文件名。 须有NULL结束符。
// const char *str : 日志信息。 须有NULL结束符。
void CMyLog::LogEndl(const char *file, const char *str)
{
	//EnterCriticalSection(&m_criticalSection);

	//std::ofstream of(file, std::ios_base::out | std::ios_base::app );
	//of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
	//of << str;
	//of << std::endl;
	__LogStrEndl(file, str);

	//LeaveCriticalSection(&m_criticalSection);
}

// const char *file : 文件名。 须有NULL结束符。
// const char *str : 日志信息。 须有NULL结束符。
#ifdef UNICODE
	void CMyLog::__LogStrEndl(const wchar_t *file, const wchar_t *str)
#else
	void CMyLog::__LogStrEndl(const char *file, const char *str)
#endif
{
	EnterCriticalSection(&m_criticalSection);

#ifdef UNICODE
	std::wofstream of(file, std::ios_base::out | std::ios_base::app );
	of << CTime::GetCurrentTime().Format(L"%Y-%m-%d %H:%M:%S ").GetString();
#else
	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
	of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
#endif

	of << str;
	of << std::endl;

	LeaveCriticalSection(&m_criticalSection);
}


