
#include "ToolLogStackWalker.h"

#include "Tool.h"
#include "LogStackWalker.h"



// ����Ч�Ŀ��Ƶ��ö�ջ��ӡ����ʱ�ж� CMyMFCStudyLog::m_mfcNotLog �������Ƿ���Ҫ��¼��������ٶȡ�
// ���ʹ�ø÷����漰�� ���� StackWalker ��������ش����ļ��������������Щ���ݡ�
void Tool::CMyMFCStudyLog::LOG_TO_DEFAULT_FILE_STACK_WALKER()
{
	EnterCriticalSection(&m_mfcStudyLogCriticalSection);

	// ��ʱ�ж�������Ч�ı������ö�ջ
	if (0 < m_mfcNotLog)
	{
		LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
		return;
	}

	CLogStackWalker __myStackWalkerToLog;
	__myStackWalkerToLog.ShowCallstack();

	LeaveCriticalSection(&m_mfcStudyLogCriticalSection);
}