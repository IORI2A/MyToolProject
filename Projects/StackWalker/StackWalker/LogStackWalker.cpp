#include "LogStackWalker.h"
#include "Tool.h"


CLogStackWalker::CLogStackWalker(void)
	: StackWalker(/*RetrieveSymbol 该参数并不起什么作用一样？？？*/ OptionsAll, NULL, GetCurrentProcessId(), GetCurrentProcess())
{
}


CLogStackWalker::~CLogStackWalker(void)
{
}


void CLogStackWalker::OnOutput(LPCSTR szText)
{
	//CTool::FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR(szText);
	// 改用速度更快的实现。
	Tool::CMyMFCStudyLog::LOG_TO_FILE_FORMAT_STR(false, "temp.log", szText);
	// CMyMFCStudyLog::LOG_TO_DEFAULT_FILE_STACK_WALKER 已经进行是否需要打印日志的判定  // 无法访问 protected 成员
	//Tool::CMyMFCStudyLog::LOG_TO_FILE_STR("temp.log", szText, true);
}

// 为仅记录名称符号
void CLogStackWalker::OnLoadModule(LPCSTR img, LPCSTR mod, DWORD64 baseAddr, DWORD size, DWORD result, LPCSTR symType, LPCSTR pdbName, ULONGLONG fileVersion)
{
	// NULL
}


void CLogStackWalker::OnSymInit(LPCSTR szSearchPath, DWORD symOptions, LPCSTR szUserName)
{
	// NULL
}

void CLogStackWalker::OnDbgHelpErr(LPCSTR szFuncName, DWORD gle, DWORD64 addr)
{
	// NULL
}
