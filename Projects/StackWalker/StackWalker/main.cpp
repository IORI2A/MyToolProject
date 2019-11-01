#include <windows.h>
#include "StackWalker.h"

void Func5() { StackWalker sw; sw.ShowCallstack(); }
void Func4() { Func5(); }
void Func3() { Func4(); }
void Func2() { Func3(); }
void Func1() { Func2(); }


#include "Tool.h"
class StackWalkerToLogFile : public StackWalker
{
public:
	StackWalkerToLogFile() : StackWalker() {}
protected:
	virtual void OnOutput(LPCSTR szText)
	{
		CTool::LOG_NOT_ENDL(szText);
		StackWalker::OnOutput(szText);
	}
};

#include "LogStackWalker.h"

void MyFunc5() { /*StackWalkerToLogFile*/ CLogStackWalker swToLog; swToLog.ShowCallstack(); }
void MyFunc4() { MyFunc5(); }
void MyFunc3() { MyFunc4(); }
void MyFunc2() { MyFunc3(); }
void MyFunc1() { MyFunc2(); }


int main()
{
	Func1();
	MyFunc5();
	return 0;
}