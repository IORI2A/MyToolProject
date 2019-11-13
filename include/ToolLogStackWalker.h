#ifndef __TOOL_LOG_STACK_WALKER_H__
#define __TOOL_LOG_STACK_WALKER_H__
// 该文件涉及到 引用 StackWalker 工程中相关代码文件，请加载引用这些内容。

#include "LogStackWalker.h"



//////////////////////////////////////////////////////////////////////////////////////////////////////
// 记录调用堆栈。 使用宏定义简化调用。
#define TOOL_LOG_STACK_WALKER() { CLogStackWalker __myStackWalkerToLog; __myStackWalkerToLog.ShowCallstack(); }


//////////////////////////////////////////////////////////////////////////////////////////////////////
namespace Tool // namespace Tool
{
	// 无法从类中分离出方法的声明。

	//class CMyMFCStudyLog
	//{
	//	// 更有效的控制调用堆栈打印。及时判定 m_mfcNotLog 计数，是否需要记录，提高速度。
	//	// 如果使用该方法涉及到 引用 ToolLogStackWalker.h 及 StackWalker 工程中相关代码文件，请加载引用这些内容。
	//	static void LOG_TO_DEFAULT_FILE_STACK_WALKER();
	//};

	//static void CMyMFCStudyLog::LOG_TO_DEFAULT_FILE_STACK_WALKER();
} // namespace Tool



#endif /*__TOOL_LOG_STACK_WALKER_H__*/