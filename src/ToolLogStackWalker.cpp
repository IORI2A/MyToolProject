
#include "ToolLogStackWalker.h"

#include "Tool.h"
#include "LogStackWalker.h"



// 更有效的控制调用堆栈打印。及时判定 CMyMFCStudyLog::m_mfcNotLog 计数（是否需要记录），提高速度。
// 如果使用该方法涉及到 引用 StackWalker 工程中相关代码文件，请加载引用这些内容。
void Tool::CMyMFCStudyLog::LOG_TO_DEFAULT_FILE_STACK_WALKER()
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	// 及时判定以免无效的遍历调用堆栈
	if (0 < m_mfcNotLog)
	{
		LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
		return;
	}

	CLogStackWalker __myStackWalkerToLog;
	__myStackWalkerToLog.ShowCallstack();

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}