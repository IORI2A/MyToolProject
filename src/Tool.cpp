#include "../include/Tool.h"

//#include <fstream>
#include <stdio.h>




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


#include <ctime>

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

	wcsftime(m_staticWCharCurrentTimeBuffer, 128, /*L"%Y-%m-%d %H:%M:%S "*/format, &today );

	return m_staticWCharCurrentTimeBuffer;
}

const char * CTool::GET_LOCAL_CURRENT_TIME()
{
	SYSTEMTIME st;
	// 本地时间 LocalTime 本地时间会根据机器设置的时区，将系统时间进行调整以适合本地时区。
	GetLocalTime(&st);
	sprintf(m_staticCharCurrentTimeBuffer, "%04d-%02d-%02d %02d:%02d:%02d.%03d ", 
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
	sprintf(m_staticCharCurrentTimeBuffer, "%04d-%02d-%02d %02d:%02d:%02d.%03d ", 
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
	//: m_bLogCriticalSectionInited(false)
{
	//if (!m_bLogCriticalSectionInited)
	//{
		InitializeCriticalSection(&m_myLogCriticalSection);
	//	m_bLogCriticalSectionInited = true;
	//}
}


CMyLog::~CMyLog(void)
{
	DeleteCriticalSection(&m_myLogCriticalSection);
}


//void CMyLog::LogEndl(const CString &str)
//{
//	//#ifdef _DEBUG
//
//	//EnterCriticalSection(&m_myLogCriticalSection);
//
//	//std::ofstream of(TEXT("\\NandFlash\\test.txt"), std::ios_base::out | std::ios_base::app );
//	//of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
//	//of << str.GetString();
//	//of << std::endl;
//	__LogStrEndl("test.txt", str);
//
//	//LeaveCriticalSection(&m_myLogCriticalSection);
//
//	//#endif
//}

// const char *file : 文件名。 须有NULL结束符。
// const char *str : 日志信息。 须有NULL结束符。
#pragma warning(disable: 4996)
//void CMyLog::LogEndl(const char *file, const char *str)
//{
//	EnterCriticalSection(&m_myLogCriticalSection);
//
//	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
//	//of << CTime::GetCurrentTime().Format("%Y-%m-%d %H:%M:%S ").GetString();
//	of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
//	of << str;
//	of << std::endl;
//
//	//__LogStrEndl(file, str);
//
//	LeaveCriticalSection(&m_myLogCriticalSection);
//}

void CMyLog::LogEndl(const char *file, const char *str)
{
	EnterCriticalSection(&m_myLogCriticalSection);

	FILE *f = fopen(file, "a");
	fprintf(f, "%s%s\n", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), str);
	fclose(f);

	LeaveCriticalSection(&m_myLogCriticalSection);
}

//void CMyLog::LogEndl(const wchar_t *file, const wchar_t *str)
//{
//	//__LogStrEndl(file, str);
//
//	EnterCriticalSection(&m_myLogCriticalSection);
//
//	std::wofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME(L"%Y-%m-%d %H:%M:%S ");
//	of << str;
//	of << std::endl;
//
//	LeaveCriticalSection(&m_myLogCriticalSection);
//}

void CMyLog::LogEndl(const wchar_t *file, const wchar_t *str)
{
	EnterCriticalSection(&m_myLogCriticalSection);

	FILE *f = _wfopen(file, L"a");
	fwprintf(f, L"%s%s\n", CTool::GET_CURRENT_TIME(L"%Y-%m-%d %H:%M:%S "), str);
	fclose(f);

	LeaveCriticalSection(&m_myLogCriticalSection);
}
#pragma warning(default: 4996)

//// const char *file : 文件名。 须有NULL结束符。
//// const char *str : 日志信息。 须有NULL结束符。
//#ifdef UNICODE
//	void CMyLog::__LogStrEndl(const wchar_t *file, const wchar_t *str)
//#else
//	void CMyLog::__LogStrEndl(const char *file, const char *str)
//#endif
//{
//	EnterCriticalSection(&m_myLogCriticalSection);
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
//	LeaveCriticalSection(&m_myLogCriticalSection);
//}

//// const char *file : 文件名。 须有NULL结束符。
//// const char *str : 日志信息。 须有NULL结束符。
//#ifdef UNICODE
//void CMyLog::__LogStrEndl(const wchar_t *file, const wchar_t *str)
//#else
//void CMyLog::__LogStrEndl(const char *file, const char *str)
//#endif
//{
//	EnterCriticalSection(&m_myLogCriticalSection);
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
//	LeaveCriticalSection(&m_myLogCriticalSection);
//}

//// const char *file : 文件名。 须有NULL结束符。
//// const char *str : 日志信息。 须有NULL结束符。
//void CMyLog::__LogStrEndl(const char *file, const char *str)
//{
//	EnterCriticalSection(&m_myLogCriticalSection);
//
//	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
//	of << str;
//	of << std::endl;
//
//	LeaveCriticalSection(&m_myLogCriticalSection);
//}
//
//void CMyLog::__LogStrEndl(const wchar_t *file, const wchar_t *str)
//{
//	EnterCriticalSection(&m_myLogCriticalSection);
//
//	std::wofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME(L"%Y-%m-%d %H:%M:%S ");
//	of << str;
//	of << std::endl;
//
//	LeaveCriticalSection(&m_myLogCriticalSection);
//}



//#include <winsock2.h>
//#include <iphlpapi.h>
//#include <icmpapi.h>
//#include <stdio.h>
//
//#pragma comment(lib, "Iphlpapi.lib")
//#pragma comment(lib, "Ws2_32.lib")
//
//
//int Check(const wchar_t *strIP)
//{
//	{
//		wchar_t buffer[512] = {};
//		wsprintf(buffer, L"int Check(const char *strIP = '%s')", strIP);
//		CTool::LOG_ENDL(buffer);
//	}
//
//	// Declare and initialize variables
//
//	HANDLE hIcmpFile;
//	unsigned long ipaddr = INADDR_NONE;
//	DWORD dwRetVal = 0;
//	char SendData[] = "Data Buffer";
//	LPVOID ReplyBuffer = NULL;
//	DWORD ReplySize = 0;
//
//	// Validate the parameters
//	if (!strIP)
//	{
//		{
//			wchar_t buffer[512] = {};
//			wsprintf(buffer, L"无效IP strIP = 0X%08X)", strIP);
//			CTool::LOG_ENDL(buffer);
//		}
//		return 1;
//	}
//
//	char MBBuffer[200] = {};
//	size_t count = wcstombs(MBBuffer, strIP, 200 ); // C4996
//	ipaddr = inet_addr(MBBuffer);
//	if (ipaddr == INADDR_NONE)
//	{
//		{
//			wchar_t buffer[512] = {};
//			wsprintf(buffer, L"IP地址转换错误 ipaddr = inet_addr('%s');    ipaddr = INADDR_NONE", strIP);
//			CTool::LOG_ENDL(buffer);
//		}
//		return 1;
//	}
//
//	hIcmpFile = IcmpCreateFile();
//	if (hIcmpFile == INVALID_HANDLE_VALUE)
//	{
//		{
//			wchar_t buffer[512] = {};
//			wsprintf(buffer, L"hIcmpFile = IcmpCreateFile();    hIcmpFile = INVALID_HANDLE_VALUE    Unable to open handle. IcmpCreatefile returned error: %ld", GetLastError());
//			CTool::LOG_ENDL(buffer);
//		}
//		return 1;
//	}    
//
//	ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
//	ReplyBuffer = (VOID*) malloc(ReplySize);
//	if (ReplyBuffer == NULL) {
//		printf("\tUnable to allocate memory\n");
//		{
//			wchar_t buffer[512] = {};
//			wsprintf(buffer, L"ReplyBuffer = (VOID*) malloc(%d);    ReplyBuffer = 0X%08X    Unable to allocate memory."
//				, ReplySize, ReplyBuffer);
//			CTool::LOG_ENDL(buffer);
//		}
//		return 1;
//	}    
//
//	wchar_t WCBuffer[200] = {};
//	count = mbstowcs(WCBuffer, SendData, 200 ); // C4996
//	dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData), 
//		NULL, ReplyBuffer, ReplySize, 1000);
//	{
//		wchar_t buffer[512] = {};
//		wsprintf(buffer, L"dwRetVal = IcmpSendEcho(hIcmpFile = 0X%08X, ipaddr = %ld, SendData = '%s', sizeof(SendData) = %d, NULL, ReplyBuffer = 0X%08X, ReplySize = %d, 1000);    dwRetVal = %d"
//			, hIcmpFile, ipaddr, WCBuffer/*SendData*/, sizeof(SendData), ReplyBuffer, ReplySize, dwRetVal);
//		CTool::LOG_ENDL(buffer);
//	}
//	if (dwRetVal != 0) {
//		PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
//		struct in_addr ReplyAddr;
//		ReplyAddr.S_un.S_addr = pEchoReply->Address;
//		//printf("\tSent icmp message to %s\n", strIP);
///*		if (dwRetVal > 1) {
//			printf("\tReceived %ld icmp message responses\n", dwRetVal);
//			printf("\tInformation from the first response:\n"); 
//		}    
//		else {    
//			printf("\tReceived %ld icmp message response\n", dwRetVal);
//			printf("\tInformation from this response:\n"); 
//		}   */ 
//
//		wchar_t WCReplyAddrBuffer[200] = {};
//		count = mbstowcs(WCReplyAddrBuffer, inet_ntoa( ReplyAddr ), 200 ); // C4996
//
//		{
//			wchar_t buffer[512] = {};
//			wsprintf(buffer, L"Received from '%s' = inet_ntoa( 0X%08X ). Status = %ld, Roundtrip time = %ld milliseconds. pEchoReply =0X%08X "
//				, WCReplyAddrBuffer, ReplyAddr, pEchoReply->Status, pEchoReply->RoundTripTime, pEchoReply);
//			CTool::LOG_ENDL(buffer);
//		}
//	}
//	else {
//		{
//			wchar_t buffer[512] = {};
//			wsprintf(buffer, L"Call to IcmpSendEcho failed. IcmpSendEcho returned error: %ld", GetLastError());
//			CTool::LOG_ENDL(buffer);
//		}
//		return 1;
//	}
//	return 0;
//} 


//#include <stdlib.h>
//#include <stdio.h>
//
//#define BUFFER_SIZE 100
//
//int main( void ) // Converts a sequence of wide characters to a corresponding sequence of multibyte characters.
//{
//	size_t  count;
//	char    *pMBBuffer = (char *)malloc( BUFFER_SIZE );
//	wchar_t *pWCBuffer = L"Hello, world.";
//
//	printf("Convert wide-character string:\n" );
//
//	count = wcstombs(pMBBuffer, pWCBuffer, BUFFER_SIZE ); // C4996
//	// Note: wcstombs is deprecated; consider using wcstombs_s instead
//	printf("   Characters converted: %u\n",
//		count );
//	printf("    Multibyte character: %s\n\n",
//		pMBBuffer );
//
//	free(pMBBuffer);
//}


//#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
//#include <stdio.h>

#pragma comment(lib, "Iphlpapi.lib")
#pragma comment(lib, "Ws2_32.lib")

// 返回结果为 目标主机返回的ICMP报文数量。
// 为 0 可视为目标主机不通 ！？
#pragma warning(disable: 4996)
int CTool::Ping(const wchar_t *strIP)
{
	{
		wchar_t buffer[512] = {};
		//wsprintf(buffer, L"int CTool::Ping(const wchar_t *strIP = '%s')", strIP);
		wsprintfW(buffer, L"int CTool::Ping(const wchar_t *strIP = '%s')", strIP);
		CTool::LOG_ENDL(buffer);
	}

	// Validate the parameters
	if (!strIP)
	{
		{
			wchar_t buffer[512] = {};
			wsprintfW(buffer, L"无效IP strIP = 0X%08X", strIP);
			CTool::LOG_ENDL(buffer);
		}
		return 0;
	}

	char MBBuffer[200] = {};
	size_t count = wcstombs(MBBuffer, strIP, 200 ); // C4996
	unsigned long ipaddr = inet_addr(MBBuffer);
	if (ipaddr == INADDR_NONE)
	{
		{
			wchar_t buffer[512] = {};
			wsprintfW(buffer, L"IP地址转换错误 ipaddr = inet_addr('%s');    ipaddr = INADDR_NONE", strIP);
			CTool::LOG_ENDL(buffer);
		}
		return 0;
	}

	HANDLE hIcmpFile = IcmpCreateFile();
	if (hIcmpFile == INVALID_HANDLE_VALUE)
	{
		{
			wchar_t buffer[512] = {};
			wsprintfW(buffer, L"hIcmpFile = IcmpCreateFile();    hIcmpFile = INVALID_HANDLE_VALUE    Unable to open handle. IcmpCreatefile returned error: %ld", GetLastError());
			CTool::LOG_ENDL(buffer);
		}
		return 0;
	}    

	char SendData[] = "Data Buffer";
	DWORD ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
	LPVOID ReplyBuffer = (VOID*) malloc(ReplySize);    // 多线程访问的时候 会出现冲突吧？
	if (ReplyBuffer == NULL) {
		{
			wchar_t buffer[512] = {};
			wsprintfW(buffer, L"ReplyBuffer = (VOID*) malloc(%d);    ReplyBuffer = 0X%08X    Unable to allocate memory."
				, ReplySize, ReplyBuffer);
			CTool::LOG_ENDL(buffer);
		}
		return 0;
	}    

	wchar_t WCBuffer[200] = {};
	count = mbstowcs(WCBuffer, SendData, 200 ); // C4996
	DWORD dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData), 
		NULL, ReplyBuffer, ReplySize, 1000);
	{
		wchar_t buffer[512] = {};
		wsprintfW(buffer, L"dwRetVal = IcmpSendEcho(hIcmpFile = 0X%08X, ipaddr = %ld, SendData = '%s', sizeof(SendData) = %d, NULL, ReplyBuffer = 0X%08X, ReplySize = %d, 1000);    dwRetVal = %d"
			, hIcmpFile, ipaddr, WCBuffer/*SendData*/, sizeof(SendData), ReplyBuffer, ReplySize, dwRetVal);
		CTool::LOG_ENDL(buffer);
	}
	if (dwRetVal != 0) {
		PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
		struct in_addr ReplyAddr;
		ReplyAddr.S_un.S_addr = pEchoReply->Address;

		wchar_t WCReplyAddrBuffer[200] = {};
		count = mbstowcs(WCReplyAddrBuffer, inet_ntoa( ReplyAddr ), 200 ); // C4996

		{
			wchar_t buffer[512] = {};
			wsprintfW(buffer, L"Received from '%s' = inet_ntoa( 0X%08X ). Status = %ld, Roundtrip time = %ld milliseconds. pEchoReply =0X%08X "
				, WCReplyAddrBuffer, ReplyAddr, pEchoReply->Status, pEchoReply->RoundTripTime, pEchoReply);
			CTool::LOG_ENDL(buffer);
		}
	}
	else {
		{
			wchar_t buffer[512] = {};
			wsprintfW(buffer, L"Call to IcmpSendEcho failed. IcmpSendEcho returned error: %ld", GetLastError());
			CTool::LOG_ENDL(buffer);
		}
		//return 1;
	}
	return dwRetVal;
}
#pragma warning(default: 4996)

int CTool::Ping(const char *strIP)
{
	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("int CTool::Ping(const wchar_t *strIP = '%s')", strIP);

	if (!strIP)
	{
		CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("无效IP strIP = 0X%08X", strIP);
		return 0;
	}

	unsigned long ipaddr = inet_addr(strIP);
	if (ipaddr == INADDR_NONE)
	{
		CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("IP地址转换错误 ipaddr = inet_addr('%s');    ipaddr = INADDR_NONE", strIP);
		return 0;
	}

	HANDLE hIcmpFile = IcmpCreateFile();
	if (hIcmpFile == INVALID_HANDLE_VALUE)
	{
		CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("hIcmpFile = IcmpCreateFile();    hIcmpFile = INVALID_HANDLE_VALUE    Unable to open handle. IcmpCreatefile returned error: %ld", GetLastError());
		return 0;
	}    

	char SendData[] = "Data Buffer";
	DWORD ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
	LPVOID ReplyBuffer = (VOID*) malloc(ReplySize);    // 多线程访问的时候 会出现冲突吧？
	if (ReplyBuffer == NULL) {
		CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("ReplyBuffer = (VOID*) malloc(%d);    ReplyBuffer = 0X%08X    Unable to allocate memory."
			, ReplySize, ReplyBuffer);
		return 0;
	}    

	DWORD dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData), 
		NULL, ReplyBuffer, ReplySize, 1000);
	CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("dwRetVal = IcmpSendEcho(hIcmpFile = 0X%08X, ipaddr = %ld, SendData = '%s', sizeof(SendData) = %d, NULL, ReplyBuffer = 0X%08X, ReplySize = %d, 1000);    dwRetVal = %d"
		, hIcmpFile, ipaddr, SendData, sizeof(SendData), ReplyBuffer, ReplySize, dwRetVal);
	if (dwRetVal != 0) {
		PICMP_ECHO_REPLY pEchoReply = (PICMP_ECHO_REPLY)ReplyBuffer;
		struct in_addr ReplyAddr;
		ReplyAddr.S_un.S_addr = pEchoReply->Address;
		CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("Received from '%s' = inet_ntoa( 0X%08X ). Status = %ld, Roundtrip time = %ld milliseconds. pEchoReply =0X%08X "
			, inet_ntoa( ReplyAddr ), ReplyAddr, pEchoReply->Status, pEchoReply->RoundTripTime, pEchoReply);
	}
	else {
		CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL("Call to IcmpSendEcho failed. IcmpSendEcho returned error: %ld", GetLastError());
	}
	return dwRetVal;
} 


#include <stdio.h>    // 头文件就近引用
#include <stdarg.h>

#pragma warning(disable: 4996)
void CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char * format, ...)
{
	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);
	CTool::LOG_ENDL(buffer);
	va_end (args);
}

void CTool::LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...)
{
	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);
	CTool::LOG_ENDL(file, buffer);
	va_end (args);
}


// RawDllMain 执行时，全局/静态对象还没有执行构造函数。因此专门设计一个函数形式的日志工具，与日志对象类同，但没有互斥锁了。
void CTool::FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char * format, ...)
{
	if (m_bToolFunLogCriticalSectionInited)
	{
		EnterCriticalSection(&m_toolFunLogCriticalSection);
	}

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);

	//std::ofstream of("temp.log", std::ios_base::out | std::ios_base::app );  // 退出程序时 RawDllMain 中调用执行到此处有错误。 改为使用 C 库函数。
	//of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
	//of << buffer;
	//of << std::endl;
	FILE *f = fopen("temp.log", "a");
	fprintf(f, "%s%s\n", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), buffer);
	fclose(f);

	va_end (args);

	if (m_bToolFunLogCriticalSectionInited)
	{
		LeaveCriticalSection(&m_toolFunLogCriticalSection);
	}
}

void CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...)
{
	if (m_bToolFunLogCriticalSectionInited)
	{
		EnterCriticalSection(&m_toolFunLogCriticalSection);
	}

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);

	//std::ofstream of(file, std::ios_base::out | std::ios_base::app );
	//of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
	//of << buffer;
	//of << std::endl;
	FILE *f = fopen(file, "a");
	fprintf(f, "%s%s\n", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), buffer);
	fclose(f);

	va_end (args);

	if (m_bToolFunLogCriticalSectionInited)
	{
		LeaveCriticalSection(&m_toolFunLogCriticalSection);
	}
}
#pragma warning(default: 4996)



//////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Tool
{
#pragma warning(disable: 4996)
	//CMyAutoLogName::CMyAutoLogName(const char *file, int line, const char *func, const char *logFie)
	//	: m_file(file), m_line(line), m_func(func), m_logFile(logFie)
	//{
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL("temp.log", "%s (%d) %s", __FILE__, __LINE__, __FUNCTION__);
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL("temp.log", "%s (%d) %s", __FILE__, __LINE__, __FUNCDNAME__);
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL("temp.log", "%s (%d) %s", __FILE__, __LINE__, __FUNCSIG__);
	//	///*
	//	//2019-10-11 10:31:01 e:\lz\work\doortotalcontrolv10\test\test.cpp (34) wWinMain
	//	//2019-10-11 10:31:01 e:\lz\work\doortotalcontrolv10\test\test.cpp (35) _wWinMain@16
	//	//2019-10-11 10:31:01 e:\lz\work\doortotalcontrolv10\test\test.cpp (36) int __stdcall wWinMain(struct HINSTANCE__ *,struct HINSTANCE__ *,wchar_t *,int)
	//	//*/

	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "[AutoLog] %s(%d): %s", m_file.c_str(), m_line, m_func.c_str());
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s(%d): %s", m_file.c_str(), m_line, m_func.c_str());
	//	CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s(%d): ++++ %s", m_file.c_str(), m_line, m_func.c_str());
	//}

	CMyAutoLogName::CMyAutoLogName(const char *funcFileName, int funcLine, const char *func, const char *logFie)
		: m_pFuncFileName(NULL), m_line(funcLine), m_pFunc(NULL), m_pLogFile(NULL)
		  , m_startClock(0), m_finishClock(0)
	{
		m_startClock = clock();  // 记录开始时的时钟

		m_pFuncFileName = new char[128]();
		m_pFunc = new char[128]();
		m_pLogFile = new char[128]();

		strcpy(m_pFuncFileName, funcFileName);
		strcpy(m_pFunc, func);
		strcpy(m_pLogFile, logFie);

		//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ++++ %s", m_pFuncFileName, m_line, m_pFunc);
		// 改用速度更快的实现。
		//Tool::CMyMFCStudyLog::LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ++++ %s", m_pFuncFileName, m_line, m_pFunc);
		// 强制记录执行调用的函数。顺序调用，不挂起线程，应当不会导致卡顿。
		Tool::CMyMFCStudyLog::FORCE_LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ++++ %s", m_pFuncFileName, m_line, m_pFunc);
	}

	//CMyAutoLogName::CMyAutoLogName(const char *file, const char *func, const char *logFie)
	//	: m_file(file), m_line(0), m_func(func), m_logFile(logFie)
	//{
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "[AutoLog] %s: %s", m_file.c_str(), m_func.c_str());
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s: %s", m_file.c_str(), m_func.c_str());
	//	CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s: ++++ %s", m_file.c_str(), m_func.c_str());
	//}

	CMyAutoLogName::CMyAutoLogName(const char *file, const char *func, const char *logFie)
		: m_pFuncFileName(NULL), m_line(0), m_pFunc(NULL), m_pLogFile(NULL)
		  , m_startClock(0), m_finishClock(0)
	{
		m_startClock = clock();  // 记录开始时的时钟

		m_pFuncFileName = new char[128]();
		//m_pFunc = new char[128](); 出现函数名过长时，空间不够用
		m_pFunc = new char[512]();
		m_pLogFile = new char[128]();

		strcpy(m_pFuncFileName, file);
		strcpy(m_pFunc, func);
		strcpy(m_pLogFile, logFie);

		//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ++++ %s", m_pFuncFileName, m_pFunc);
		// 改用速度更快的实现。
		//Tool::CMyMFCStudyLog::LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ++++ %s", m_pFuncFileName, m_pFunc);
		// 强制记录执行调用的函数。顺序调用，不挂起线程，应当不会导致卡顿。
		Tool::CMyMFCStudyLog::FORCE_LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ++++ %s", m_pFuncFileName, m_pFunc);
		// Tool::CMyMFCStudyLog 的内部资源需要手动进行释放，避免泄漏。
	}
#pragma warning(default: 4996)


	//CMyAutoLogName::~CMyAutoLogName()
	//{
	//	if (m_line)
	//	{
	//		//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "[~AutoLog] %s(%d): %s", m_file.c_str(), m_line, m_func.c_str());
	//		//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s(%d): ~ %s", m_file.c_str(), m_line, m_func.c_str());
	//		CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s(%d): ---- %s", m_file.c_str(), m_line, m_func.c_str());
	//	}
	//	else
	//	{
	//		//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "[~AutoLog] %s: %s", m_file.c_str(), m_func.c_str());
	//		//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s: ~ %s", m_file.c_str(), m_func.c_str());
	//		CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s: ---- %s", m_file.c_str(), m_func.c_str());
	//	}
	//}

	CMyAutoLogName::~CMyAutoLogName()
	{
		m_finishClock = clock();  // 记录释放时的时钟
		clock_t durationTick = m_finishClock - m_startClock; // 对象生命期 时钟数
		double durationSec = (double)(m_finishClock - m_startClock) / CLOCKS_PER_SEC; // 对象生命期 秒数

		if (m_line)
		{
			//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ---- %s [%d clock ticks, %2.1f seconds]"
			//	, m_pFuncFileName, m_line, m_pFunc, durationTick, durationSec);
			// 改用速度更快的实现。
			//Tool::CMyMFCStudyLog::LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ---- %s [%d clock ticks, %2.1f seconds]"
			//	, m_pFuncFileName, m_line, m_pFunc, durationTick, durationSec);
			// 强制记录执行调用的函数。顺序调用，不挂起线程，应当不会导致卡顿。
			Tool::CMyMFCStudyLog::FORCE_LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ---- %s [%d clock ticks, %2.1f seconds]"
				, m_pFuncFileName, m_line, m_pFunc, durationTick, durationSec);
		}
		else
		{
			//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ---- %s [%d clock ticks, %2.1f seconds]"
			//	, m_pFuncFileName, m_pFunc, durationTick, durationSec);
			//Tool::CMyMFCStudyLog::LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ---- %s [%d clock ticks, %2.1f seconds]"
			//	, m_pFuncFileName, m_pFunc, durationTick, durationSec);
			Tool::CMyMFCStudyLog::FORCE_LOG_TO_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ---- %s [%d clock ticks, %2.1f seconds]"
				, m_pFuncFileName, m_pFunc, durationTick, durationSec);
		}
		// 该类使用 Tool::CMyMFCStudyLog ，可以考虑？？？在析构函数中对 Tool::CMyMFCStudyLog 的内部资源需要手动进行释放，避免泄漏。
		//Tool::CMyMFCStudyLog::FREE();

		delete [] m_pFuncFileName;
		delete [] m_pFunc;
		delete [] m_pLogFile;
	}
}


// 提供支持不带换行符的日志输出。 目前仅支持 ANSI
//void CMyLog::LogNotEndl(const char *file, const char *str)
//{
//	EnterCriticalSection(&m_myLogCriticalSection);
//
//	std::ofstream of(file, std::ios_base::out | std::ios_base::app );
//	of << CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S ");
//	of << str;
//	// 不带换行结束符。
//
//	LeaveCriticalSection(&m_myLogCriticalSection);
//}

#pragma warning(disable: 4996)
void CMyLog::LogNotEndl(const char *file, const char *str, bool bOutputDateTime)
{
	EnterCriticalSection(&m_myLogCriticalSection);

	FILE *f = fopen(file, "a");
	if (bOutputDateTime)
	{
		fprintf(f, "%s%s", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), str);
	}
	else
	{
		fprintf(f, "%s", str);
	}
	fclose(f);
	// 不带换行结束符。

	LeaveCriticalSection(&m_myLogCriticalSection);
}
#pragma warning(default: 4996)

void CTool::LOG_NOT_ENDL(const char *str)    // 支持直接文本内容。 不带换行结束符。
{
	m_staticMyLog.LogNotEndl("temp.log", str);
}

void CTool::LOG_NOT_ENDL(const char *file, const char *str, bool bOutputDateTime)
{
	m_staticMyLog.LogNotEndl(file, str, bOutputDateTime);
}


#pragma warning(disable: 4996)
void CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR(const char * format, ...)    // 不带换行结束符。
{
	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);
	CTool::LOG_NOT_ENDL(buffer);
	va_end (args);
}

void CTool::LOG_TO_SPECIFIC_FILE_FORMAT_STR(const char *file, const char * format, ...)
{
	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);
	CTool::LOG_NOT_ENDL(file, buffer);
	va_end (args);
}
#pragma warning(default: 4996)


// 支持 UNICODE 版本
const wchar_t * CTool::GET_W_LOCAL_CURRENT_TIME()
{
	SYSTEMTIME st;
	// 本地时间 LocalTime 本地时间会根据机器设置的时区，将系统时间进行调整以适合本地时区。
	GetLocalTime(&st);
	swprintf_s(m_staticWCharCurrentTimeBuffer, L"%04d-%02d-%02d %02d:%02d:%02d.%03d ", 
		st.wYear, st.wMonth, st.wDay, 
		st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	return m_staticWCharCurrentTimeBuffer;
}

const wchar_t * CTool::GET_W_SYSTEM_CURRENT_TIME()
{
	/////////////////////// 获取系统时间 ///////////////////////
	// 系统时间 SystemTime UTC
	SYSTEMTIME st;
	GetSystemTime(&st);
	swprintf_s(m_staticWCharCurrentTimeBuffer, L"%04d-%02d-%02d %02d:%02d:%02d.%03d ", 
		st.wYear, st.wMonth, st.wDay, 
		st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	return m_staticWCharCurrentTimeBuffer;
}


CRITICAL_SECTION CTool::m_toolFunLogCriticalSection;
bool CTool::m_bToolFunLogCriticalSectionInited = false;
void CTool::INIT_FUN_LOG_CRITICAL_SECTION()
{
	if (!m_bToolFunLogCriticalSectionInited)
	{
		InitializeCriticalSection(&m_toolFunLogCriticalSection);
		m_bToolFunLogCriticalSectionInited = true;
	}
}

void CTool::DELE_FUN_LOG_CRITICAL_SECTION()
{
	if (m_bToolFunLogCriticalSectionInited)
	{
		DeleteCriticalSection(&m_toolFunLogCriticalSection);
		m_bToolFunLogCriticalSectionInited = false;
	}
}


// 注：
// wsprintf 不支持%f，即不支持浮点数，双精度数格式化。
// 可使用 swprintf 替代， swprintf 多一个长度参数，且 swprintf 没有安全函数 "_s"
//wsprintf(buffer,  TEXT("%s 连接设备完成，返回 BOOL res = %d ！ [%d clock ticks, %d seconds]\r\n")
//	, CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
//swprintf(buffer, sizeof(buffer)/sizeof(wchar_t),  TEXT("%s 连接设备完成，返回 BOOL res = %d ！ [%d clock ticks, %f seconds]\r\n")
//  , CTool::GET_W_LOCAL_CURRENT_TIME(), res, durationTick, durationSec);
//_stprintf 根据宽窄字符被定义为  sprintf / swprintf 


#pragma warning(disable: 4996)
// 与 FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 、 FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL 对应的不带换行结束符
// 使用 FUN_LOG... 之前可以先在类似全局的地方执行 INIT_FUN_LOG_CRITICAL_SECTION/DELE_FUN_LOG_CRITICAL_SECTION 来初始化一个临界区锁，默认也可以不初始化，此时便无法控制多并发就是了
void CTool::FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR(const char * format, ...)
{
	if (m_bToolFunLogCriticalSectionInited)
	{
		EnterCriticalSection(&m_toolFunLogCriticalSection);
	}

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);

	FILE *f = fopen("temp.log", "a");
	fprintf(f, "%s%s", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), buffer);
	fclose(f);

	va_end (args);

	if (m_bToolFunLogCriticalSectionInited)
	{
		LeaveCriticalSection(&m_toolFunLogCriticalSection);
	}
}

void CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR(const char *file, const char * format, ...)
{
	if (m_bToolFunLogCriticalSectionInited)
	{
		EnterCriticalSection(&m_toolFunLogCriticalSection);
	}

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);

	FILE *f = fopen(file, "a");
	fprintf(f, "%s%s", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), buffer);
	fclose(f);

	va_end (args);

	if (m_bToolFunLogCriticalSectionInited)
	{
		LeaveCriticalSection(&m_toolFunLogCriticalSection);
	}
}
#pragma warning(default: 4996)




#include <assert.h> 

// warning C4482: 使用了非标准扩展: 限定名中使用了枚举“Tool::CMyMFCStudyLog::_CMFCDllStatus”
//Tool::CMyMFCStudyLog::CMFCDllStatus m_mfcDllStatus = Tool::CMyMFCStudyLog::CMFCDllStatus::IN_RAW_DLL_MAIN; 
Tool::CMyMFCStudyLog::CMFCDllStatus Tool::CMyMFCStudyLog::m_mfcDllStatus = Tool::CMyMFCStudyLog::IN_RAW_DLL_MAIN; 
#pragma warning(disable: 4996)
Tool::CMyMFCStudyLog::CMFCDllStatus Tool::CMyMFCStudyLog::SET_MFC_DLL_STATUS(const CMFCDllStatus status
	, const char *file, int line, const char *func, const char *logFie)
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);
	char buffer[512] = {};
	switch(status)
	{
	case IN_RAW_DLL_MAIN:
		sprintf (buffer, "%s(%d): SET_MFC_DLL_STATUS [IN_RAW_DLL_MAIN] %s\n", file, line, func);
		break;
	case IN_GLOBAL_INIT:
		sprintf (buffer, "%s(%d): SET_MFC_DLL_STATUS [IN_GLOBAL_INIT] %s\n", file, line, func);
		break;
	case IN_DLL_MAIN:
		sprintf (buffer, "%s(%d): SET_MFC_DLL_STATUS [IN_DLL_MAIN] %s\n", file, line, func);
		break;
	case IN_NOT_LOG_STATUS:
		sprintf (buffer, "%s(%d): SET_MFC_DLL_STATUS [IN_NOT_LOG_STATUS] %s\n", file, line, func);
		break;
	default:
		sprintf (buffer, "%s(%d): SET_MFC_DLL_STATUS [UNKNOWN] %s\n", file, line, func);
		break;
	}
	LOG_TO_FILE_STR(logFie, buffer);

	m_mfcDllStatus = status;
	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);

	return m_mfcDllStatus;
}

char * Tool::CMyMFCStudyLog::m_staticFiles[MAX_STATIC_FILE] = {};
void * Tool::CMyMFCStudyLog::m_staticFilePtres[MAX_STATIC_FILE] = {};
int Tool::CMyMFCStudyLog::m_currentFiles = 0;
// 调用日志记录函数前最好检查设定一下 DLL STATUS （ 函数 SET_MFC_DLL_STATUS ）。
// 不同状态调用的日志函数方法不同，执行效率也就不一样。
void Tool::CMyMFCStudyLog::LOG_TO_FILE_STR(const char *file, const char *str, bool bOutputDateTime)
{
	// IN_NOT_LOG_STATUS 权限最高的是否记录日志标识
	if( IN_NOT_LOG_STATUS == m_mfcDllStatus )
	{
		return;
	}
	//if (0 < m_mfcNotLog)
	//{
	//	return;
	//}
	// 为方便 SET_NOT_LOG_FOR 使用来记录 m_mfcNotLog 的值，那么应当不与 m_mfcNotLog 关联，为防止外部引用，使用 protect 保护。
	// 其他加锁方法使用，可不加锁限制

	// 1.为了加快日志记录速度，保持日志文件运行中一直打开。
	// 遍历判定是否已经打开过该文件
	FILE *f = NULL;
	for (int i = 0; i < min(m_currentFiles, MAX_STATIC_FILE); ++i)
	{
		char *p = m_staticFiles[i];
		if ( p && (0 == strcmp(p, file)) )
		{
			f = (FILE *)(m_staticFilePtres[i]);
			break;
		}
	}

	// 如果没有，则打开该文件，并将该文件符及文件名保存到各自的数组中。
	if (!f)
	{
		if (m_currentFiles < MAX_STATIC_FILE)
		{
			// 保存 文件符
			FILE *oldF = (FILE *)(m_staticFilePtres[m_currentFiles]);
			if (oldF)
			{
				fclose(oldF);
			}
			f = fopen(file, "a");
			m_staticFilePtres[m_currentFiles] = f;

			// 保存 文件名
			char *oldFileName = m_staticFiles[m_currentFiles];
			if (oldFileName)
			{
				delete oldFileName;
			}
			char *newFileName = new char[128]();
			strcpy(newFileName, file);
			m_staticFiles[m_currentFiles] = newFileName;

			++m_currentFiles;
		}
		else
		{
			// 超出文件数组范围。
			assert(0);
		}
	}

	// 2.进行日志记录。 // 外围已有互斥锁了
	//if( IN_DLL_MAIN == m_mfcDllStatus )
	//{
	//	// 有互斥锁
	//	CTool::LOG_NOT_ENDL(file, str, bOutputDateTime);
	//}
	//else
	{
		if (bOutputDateTime)
		{
			fprintf(f, "%s%s", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), str);
		}
		else
		{
			fprintf(f, "%s", str);
		}
		fflush(f);
	}
}


void CTool::LOG_NOT_ENDL(FILE *f, const char *str)
{
	m_staticMyLog.LogNotEndl(f, str);
}


void CMyLog::LogNotEndl(FILE *file, const char *str, bool bOutputDateTime)
{
	EnterCriticalSection(&m_myLogCriticalSection);

	if (bOutputDateTime)
	{
		fprintf(file, "%s%s", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), str);
	}
	else
	{
		fprintf(file, "%s", str);
	}
	fflush(file);

	LeaveCriticalSection(&m_myLogCriticalSection);
}


void Tool::CMyMFCStudyLog::LOG_TO_FILE_FORMAT_STR(bool bOutputDateTime, const char *file, const char * format, ...)
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	if (0 < m_mfcNotLog)
	{
		LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
		return;
	}

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	// 有可能超出数组范围。暂时不管。
	vsprintf (buffer,format, args);
	va_end (args);

	LOG_TO_FILE_STR(file, buffer, bOutputDateTime);

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}


void Tool::CMyMFCStudyLog::LOG_TO_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...)
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	if (0 < m_mfcNotLog)
	{
		LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
		return;
	}

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	int n = vsprintf (buffer,format, args);
	va_end (args);

	memset(buffer+n, '\n', 1);
	//memset(buffer+n+1, '\0', 1);
	//strcat(buffer, "\n");
	LOG_TO_FILE_STR(file, buffer, true);

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}


// 为兼容之前日志工具记录实现，提供输出到默认日志文件
void Tool::CMyMFCStudyLog::LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL(const char *format, ...)
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	if (0 < m_mfcNotLog)
	{
		LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
		return;
	}

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	int n = vsprintf (buffer,format, args);
	va_end (args);

	memset(buffer+n, '\n', 1);
	LOG_TO_FILE_STR("temp.log", buffer, true);

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}
#pragma warning(default: 4996)


// 专门用于释放 m_staticFiles 和 m_staticFilePtres 中的资源
void Tool::CMyMFCStudyLog::FREE()
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	m_currentFiles = 0;
	for (int i = 0; i < MAX_STATIC_FILE; ++i)
	{
		if (m_staticFiles[i])
		{
			delete m_staticFiles[i];
			m_staticFiles[i] = NULL;
		}

		if (m_staticFilePtres[i])
		{
			fclose( (FILE *)(m_staticFilePtres[i]) );
			m_staticFilePtres[i] = NULL;
		}
	}

	m_mfcNotLog = false;

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}


// 设置某种状态下不进行日志记录，该设置仅生效一次。不记录操作完成后，置该状态为0。
int Tool::CMyMFCStudyLog::m_mfcNotLog = 0; 
#pragma warning(disable: 4996)
void Tool::CMyMFCStudyLog::SET_NOT_LOG_FOR(const bool notLog)
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	//m_mfcNotLog = notLog;
	if (notLog)
	{
		++m_mfcNotLog;
	}
	else
	{
		//if (m_mfcNotLog > 0)
		//{
		//	--m_mfcNotLog;
		//}
		//else
		//{
		//	--m_mfcNotLog = 0;
		//}
		--m_mfcNotLog;
	}

	// 记录 m_mfcNotLog 的值
	char buffer[512] = {};
	if (notLog)
	{
		sprintf (buffer, "++++ MFC_NOT_LOG [%d]\n", m_mfcNotLog);
	}
	else
	{
		sprintf (buffer, "---- MFC_NOT_LOG [%d]\n", m_mfcNotLog);
	}

	LOG_TO_FILE_STR("temp.log", buffer);

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}
#pragma warning(default: 4996)


// 增加一个日志记录互斥锁
CRITICAL_SECTION Tool::CMyMFCStudyLog::m_mfcStudyLogCriticalSection;
bool Tool::CMyMFCStudyLog::m_bMfcStudyLogCriticalSectionInited = false;
void Tool::CMyMFCStudyLog::INIT_MFC_STUDY_LOG_CRITICAL_SECTION()
{
	if (!m_bMfcStudyLogCriticalSectionInited)
	{
		InitializeCriticalSection(&m_mfcStudyLogCriticalSection);
		m_bMfcStudyLogCriticalSectionInited = true;
	}
}

void Tool::CMyMFCStudyLog::DELE_MFC_STUDY_LOG_CRITICAL_SECTION()
{
	if (m_bMfcStudyLogCriticalSectionInited)
	{
		DeleteCriticalSection(&m_mfcStudyLogCriticalSection);
		m_bMfcStudyLogCriticalSectionInited = false;
	}
	
}


// 增加记录 设置是否打印状态的 文件、行号、函数出处，便于分析日志。
#pragma warning(disable: 4996)
void Tool::CMyMFCStudyLog::SET_NOT_LOG_FOR(const bool notLog, const char *file, int line, const char *func)
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	//m_mfcNotLog = notLog;
	if (notLog)
	{
		++m_mfcNotLog;
	}
	else
	{
		--m_mfcNotLog;
	}

	// 记录 m_mfcNotLog 的值
	char buffer[512] = {};
	if (notLog)
	{
		sprintf (buffer, "%s(%d): [MFC_NOT_LOG = %d +] %s\n", file, line, m_mfcNotLog, func);
	}
	else
	{
		sprintf (buffer, "%s(%d): [MFC_NOT_LOG = %d -] %s\n", file, line, m_mfcNotLog, func);
	}

	LOG_TO_FILE_STR("temp.log", buffer);

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}


// 强制输出内容。不受 m_mfcNotLog 计数控制。目前提供给 CMyAutoLogName 使用，强制记录执行调用的函数。（非反向遍历函数调用堆栈）
void Tool::CMyMFCStudyLog::FORCE_LOG_TO_FILE_FORMAT_STR_ENDL(const char *file, const char * format, ...)
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	char buffer[512] = {};
	va_list args;
	va_start (args, format);
	int n = vsprintf (buffer,format, args);
	va_end (args);

	memset(buffer+n, '\n', 1);
	//memset(buffer+n+1, '\0', 1);
	//strcat(buffer, "\n");
	LOG_TO_FILE_STR(file, buffer, true);

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}
#pragma warning(default: 4996)
