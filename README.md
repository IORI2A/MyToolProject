**2019-11-01**

1. 日志工具 增加 与 FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 、 FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL 对应的不带换行结束符的函数方法 。
- 使用 FUN_LOG... 之前可以先在类似全局的地方执行 INIT_FUN_LOG_CRITICAL_SECTION/DELE_FUN_LOG_CRITICAL_SECTION 来初始化一个临界区锁，默认也可以不初始化，此时便无法控制多并发就是了。
2. StackWalker 子类 CLogStackWalker ，实现仅记录名称符号。
- 使用的是 Github 上的 StackWalker-1.0 
3. 为了加快日志记录速度，保持日志文件运行中一直打开。 新实现用于调测MFC库的日志工具
- 内部使用之前的 日志工具，要求之前的 日志工具 提供支持文件符的函数方法接口。不需要函数内部再打开/关闭文件。
- 可根据需要手动设定 MFC DLL 运行过程中不同时点的状态。主要用于指导调用不同效率的日志函数方法。 IN_DLL_MAIN 状态下使用有互斥锁支持的函数方法。
- 目前最多可同时支持打开 #define MAX_STATIC_FILE 8 个文件。
- 增加 FREE 方法 专门用于释放 m_staticFiles 和 m_staticFilePtres 中的资源。 需要手动调用，可在调测结束位置进行调用释放。
- 为兼容之前日志工具记录实现，提供输出到默认日志文件。
4. 日志工具BUG及优化。
- CTool::LOG_NOT_ENDL 错误调用 LogEndl 。
- 部分 char buffer[512] 局部变量未初始化。
- 日志工具 提供支持文件符的函数方法接口。
- 日志工具 LogNotEndl 增加是否需要 输出日期时间 参数。
- 优化 CMyAutoLogName 中相关变量命名。
5. 相关日志记录调用日志方法更改为调用 速度更快的实现方法。
- 经调测速度还是未能提升太多。



**2019-10-30**

1. 增加调测函数调用堆栈的工程项目 StackWalker 。
- 可用于集成到程序中，获取函数的堆栈便于调测程序。
- 扩展 StackWalker 生成子类，使用 CTool 的日志功能，将函数调用堆栈信息也输出到日志文件。
2. 修正 void CMyLog::LogNotEndl(const char *file, const char *str) 输出有换行符问题。
3. Readme.md倒序记录。



**2019-10-28**

1. 增加一个 Projects 目录来保存完整的小型工程。
2. 增加一个截屏的工程项目 GDI_CapturingAnImage ， BITMAP 位图操作。
- captures an image of the entire desktop, scales it down to the current window size and then saves it to a file.
- 全屏截取，并缩放到当前显示窗口大小，同时保存为BMP文件。



**2019-10-25**

1. 增加记录 CMyAutoLogName 对象生命期，即函数调用时长，转换为时钟数及分钟数显示。
2. wsprintf 不支持%f，即不支持浮点数，双精度数格式化。可使用 swprintf 替代， swprintf 多一个长度参数
- _stprintf 根据宽窄字符被定义为  sprintf / swprintf 



**2019-10-22**

1. 为适配调测 atlmfc 变更使用 C 运行时库内容。引用c++标准库报错。
2. 修改日志工具 LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 输出仅时间BUG。
3. 为 FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 、 FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL 增加互斥锁。



**2019-10-16**

1. GET_LOCAL_CURRENT_TIME() 和 GET_SYSTEM_CURRENT_TIME() 格式化输出指定占符宽度。
2. 修改 GET_CURRENT_TIME(const wchar_t *format) 应当使用 format 参数控制格式化输出。
3. 获取时间函数 增加支持 UNICODE 版本。
4.  warning C4996 提示不安全函数。



**2019-10-14**

1. 设计一个函数形式的日志工具，与日志对象类同，但没有互斥锁了。
- RawDllMain 执行时，全局/静态对象还没有执行构造函数。
- 退出程序时 RawDllMain 中调用 ofstream 报错。 改为使用 C 库文件操作函数。
2. 增加一个方便记录执行函数信息的日志工具。 
- 使用宏定义，方便使用 __FILE__, __FUNCTION__ 等宏，并简化编写量。
3. 引入使用名字空间进行管理。
4. 提供支持不带换行符的日志输出。 
- 目前仅支持 ANSI
- 实际使用未达预期，多了日期内容输出。暂不使用。



**2019-10-08**

1. 提供ANSI版本的检测IP地址工具。
2. 提升日志工具的编写便利性。
- 简化日志记录为单条语句。
- 支持变长参数，直接进行格式化输出。



**2019-09-28**

1. 检测目标主机IP地址是否可通工具。
- 使用 windows IP Helper API 发送 ICMP 报文检测目标主机。



**2019-09-26**

1. 调整日志工具。
- 输出日志内容到默认文件，更改为 temp.log 。

2. 提供获取当前时间工具。
- 屏蔽使用 ATL/MFC 控件获取时间，通过 C 库 或者 windows 系统API 获取当前时间。
- 支持ASNI\UNICODE。



**2019-09-25**

1. 提供日志工具。
- 输出日志内容到默认 test.txt 文件。
- 输出日志内容到指定的 文本文件。
- 支持ASNI\UNICODE。







