#ifndef __TOOL_LOG_STACK_WALKER_H__
#define __TOOL_LOG_STACK_WALKER_H__
// ���ļ��漰�� ���� StackWalker ��������ش����ļ��������������Щ���ݡ�

#include "LogStackWalker.h"



//////////////////////////////////////////////////////////////////////////////////////////////////////
// ��¼���ö�ջ�� ʹ�ú궨��򻯵��á�
#define TOOL_LOG_STACK_WALKER() { CLogStackWalker __myStackWalkerToLog; __myStackWalkerToLog.ShowCallstack(); }


//////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Tool // namespace Tool
{
	// �޷������з����������������

	//class CMyMFCStudyLog
	//{
	//	// ����Ч�Ŀ��Ƶ��ö�ջ��ӡ����ʱ�ж� m_mfcNotLog �������Ƿ���Ҫ��¼������ٶȡ�
	//	// ���ʹ�ø÷����漰�� ���� ToolLogStackWalker.h �� StackWalker ��������ش����ļ��������������Щ���ݡ�
	//	static void LOG_TO_DEFAULT_FILE_STACK_WALKER();
	//};

	//static void CMyMFCStudyLog::LOG_TO_DEFAULT_FILE_STACK_WALKER();
} // namespace Tool



#endif /*__TOOL_LOG_STACK_WALKER_H__*/