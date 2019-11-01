## StackWalker - Walking the callstack

引用参考：
* https://github.com/JochenKalmbach/StackWalker
* http://www.codeproject.com/KB/threads/StackWalker.aspx


** 使用的是 Github 上的 StackWalker-1.0 **


1. 直接简单使用 StackWalker 。

扩展 StackWalker 生成子类，使用 CTool 的日志功能，将函数调用堆栈信息也输出到日志文件。
class StackWalkerToLogFile : public StackWalker


2. StackWalker 子类，实现仅记录名称符号。

class CLogStackWalker : public StackWalker
