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

	CMyAutoLogName::CMyAutoLogName(const char *file, int line, const char *func, const char *logFie)
		: m_pFile(NULL), m_line(line), m_pFunc(NULL), m_pLogFile(NULL)
	{
		m_pFile = new char[128]();
		m_pFunc = new char[128]();
		m_pLogFile = new char[128]();

		strcpy(m_pFile, file);
		strcpy(m_pFunc, func);
		strcpy(m_pLogFile, logFie);

		CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ++++ %s", m_pFile, m_line, m_pFunc);
	}

	//CMyAutoLogName::CMyAutoLogName(const char *file, const char *func, const char *logFie)
	//	: m_file(file), m_line(0), m_func(func), m_logFile(logFie)
	//{
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "[AutoLog] %s: %s", m_file.c_str(), m_func.c_str());
	//	//CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s: %s", m_file.c_str(), m_func.c_str());
	//	CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_logFile.c_str(), "%s: ++++ %s", m_file.c_str(), m_func.c_str());
	//}

	CMyAutoLogName::CMyAutoLogName(const char *file, const char *func, const char *logFie)
		: m_pFile(NULL), m_line(0), m_pFunc(NULL), m_pLogFile(NULL)
	{
		m_pFile = new char[128]();
		//m_pFunc = new char[128](); 出现函数名过长时，空间不够用
		m_pFunc = new char[512]();
		m_pLogFile = new char[128]();

		strcpy(m_pFile, file);
		strcpy(m_pFunc, func);
		strcpy(m_pLogFile, logFie);

		CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ++++ %s", m_pFile, m_pFunc);
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
		if (m_line)
		{
			CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s(%d): ---- %s", m_pFile, m_line, m_pFunc);
		}
		else
		{
			CTool::FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL(m_pLogFile, "%s: ---- %s", m_pFile, m_pFunc);
		}

		delete [] m_pFile;
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
void CMyLog::LogNotEndl(const char *file, const char *str)
{
	EnterCriticalSection(&m_myLogCriticalSection);

	FILE *f = fopen(file, "a");
	fprintf(f, "%s%s\n", CTool::GET_CURRENT_TIME("%Y-%m-%d %H:%M:%S "), str);
	fclose(f);
	// 不带换行结束符。

	LeaveCriticalSection(&m_myLogCriticalSection);
}
#pragma warning(default: 4996)

void CTool::LOG_NOT_ENDL(const char *str)    // 支持直接文本内容。 不带换行结束符。
{
	m_staticMyLog.LogNotEndl("temp.log", str);
}

void CTool::LOG_NOT_ENDL(const char *file, const char *str)
{
	m_staticMyLog.LogEndl(file, str);
}


#pragma warning(disable: 4996)
void CTool::LOG_TO_DEFAULT_FILE_FORMAT_STR(const char * format, ...)    // 不带换行结束符。
{
	char buffer[512];
	va_list args;
	va_start (args, format);
	vsprintf (buffer,format, args);
	CTool::LOG_NOT_ENDL(buffer);
	va_end (args);
}

void CTool::LOG_TO_SPECIFIC_FILE_FORMAT_STR(const char *file, const char * format, ...)
{
	char buffer[512];
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
		InitializeCriticalSection(&m_toolFunLogCriticalSection);
		m_bToolFunLogCriticalSectionInited = false;
	}
}