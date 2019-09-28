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

// const char *file : �ļ����� ����NULL��������
// const char *str : ��־��Ϣ�� ����NULL��������
void CTool::LOG_ENDL(const char *file, const char *str)
{
	m_staticMyLog.LogEndl(file, str);
}

void CTool::LOG_ENDL(const wchar_t *file, const wchar_t *str)
{
	m_staticMyLog.LogEndl(file, str);
}

// const char *format : ���ڸ�ʽ��ָʾ�ַ����ο� strftime ������
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
	// ����ʱ�� LocalTime ����ʱ�����ݻ������õ�ʱ������ϵͳʱ����е������ʺϱ���ʱ����
	GetLocalTime(&st);
	sprintf(m_staticCharCurrentTimeBuffer, "%d-%d-%d %d:%d:%d.%d ", 
		st.wYear, st.wMonth, st.wDay, 
		st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

	return m_staticCharCurrentTimeBuffer;
}

const char * CTool::GET_SYSTEM_CURRENT_TIME()
{
	/////////////////////// ��ȡϵͳʱ�� ///////////////////////
	// ϵͳʱ�� SystemTime UTC
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

// const char *file : �ļ����� ����NULL��������
// const char *str : ��־��Ϣ�� ����NULL��������
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

//// const char *file : �ļ����� ����NULL��������
//// const char *str : ��־��Ϣ�� ����NULL��������
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

//// const char *file : �ļ����� ����NULL��������
//// const char *str : ��־��Ϣ�� ����NULL��������
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

//// const char *file : �ļ����� ����NULL��������
//// const char *str : ��־��Ϣ�� ����NULL��������
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
//			wsprintf(buffer, L"��ЧIP strIP = 0X%08X)", strIP);
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
//			wsprintf(buffer, L"IP��ַת������ ipaddr = inet_addr('%s');    ipaddr = INADDR_NONE", strIP);
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

// ���ؽ��Ϊ Ŀ���������ص�ICMP����������
// Ϊ 0 ����ΪĿ��������ͨ ����
int CTool::Ping(const wchar_t *strIP)
{
	{
		wchar_t buffer[512] = {};
		wsprintf(buffer, L"int CTool::Ping(const wchar_t *strIP = '%s')", strIP);
		CTool::LOG_ENDL(buffer);
	}

	// Validate the parameters
	if (!strIP)
	{
		{
			wchar_t buffer[512] = {};
			wsprintf(buffer, L"��ЧIP strIP = 0X%08X)", strIP);
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
			wsprintf(buffer, L"IP��ַת������ ipaddr = inet_addr('%s');    ipaddr = INADDR_NONE", strIP);
			CTool::LOG_ENDL(buffer);
		}
		return 0;
	}

	HANDLE hIcmpFile = IcmpCreateFile();
	if (hIcmpFile == INVALID_HANDLE_VALUE)
	{
		{
			wchar_t buffer[512] = {};
			wsprintf(buffer, L"hIcmpFile = IcmpCreateFile();    hIcmpFile = INVALID_HANDLE_VALUE    Unable to open handle. IcmpCreatefile returned error: %ld", GetLastError());
			CTool::LOG_ENDL(buffer);
		}
		return 0;
	}    

	char SendData[] = "Data Buffer";
	DWORD ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
	LPVOID ReplyBuffer = (VOID*) malloc(ReplySize);    // ���̷߳��ʵ�ʱ�� ����ֳ�ͻ�ɣ�
	if (ReplyBuffer == NULL) {
		printf("\tUnable to allocate memory\n");
		{
			wchar_t buffer[512] = {};
			wsprintf(buffer, L"ReplyBuffer = (VOID*) malloc(%d);    ReplyBuffer = 0X%08X    Unable to allocate memory."
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
		wsprintf(buffer, L"dwRetVal = IcmpSendEcho(hIcmpFile = 0X%08X, ipaddr = %ld, SendData = '%s', sizeof(SendData) = %d, NULL, ReplyBuffer = 0X%08X, ReplySize = %d, 1000);    dwRetVal = %d"
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
			wsprintf(buffer, L"Received from '%s' = inet_ntoa( 0X%08X ). Status = %ld, Roundtrip time = %ld milliseconds. pEchoReply =0X%08X "
				, WCReplyAddrBuffer, ReplyAddr, pEchoReply->Status, pEchoReply->RoundTripTime, pEchoReply);
			CTool::LOG_ENDL(buffer);
		}
	}
	else {
		{
			wchar_t buffer[512] = {};
			wsprintf(buffer, L"Call to IcmpSendEcho failed. IcmpSendEcho returned error: %ld", GetLastError());
			CTool::LOG_ENDL(buffer);
		}
		//return 1;
	}
	return dwRetVal;
} 