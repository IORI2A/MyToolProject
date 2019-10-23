2019-09-25

1.提供日志工具。
-- 输出日志内容到默认 test.txt 文件。
-- 输出日志内容到指定的 文本文件。
-- 支持ASNI\UNICODE。



2019-09-26

1.调整日志工具。
-- 输出日志内容到默认文件，更改为 temp.log 。

2.提供获取当前时间工具。
-- 屏蔽使用 ATL/MFC 控件获取时间，通过 C 库 或者 windows 系统API 获取当前时间。
-- 支持ASNI\UNICODE。



2019-09-28

1.检测目标主机IP地址是否可通工具。
-- 使用 windows IP Helper API 发送 ICMP 报文检测目标主机。



2019-10-08

1.提供ANSI版本的检测IP地址工具。
2.提升日志工具的编写便利性。
-- 简化日志记录为单条语句。
-- 支持变长参数，直接进行格式化输出。



2019-10-14

1.设计一个函数形式的日志工具，与日志对象类同，但没有互斥锁了。
-- RawDllMain 执行时，全局/静态对象还没有执行构造函数。
-- 退出程序时 RawDllMain 中调用 ofstream 报错。 改为使用 C 库文件操作函数。
2.增加一个方便记录执行函数信息的日志工具。 
-- 使用宏定义，方便使用 __FILE__, __FUNCTION__ 等宏，并简化编写量。
3.引入使用名字空间进行管理。
4.提供支持不带换行符的日志输出。 
-- 目前仅支持 ANSI
-- 实际使用未达预期，多了日期内容输出。暂不使用。



2019-10-16

1.GET_LOCAL_CURRENT_TIME() 和 GET_SYSTEM_CURRENT_TIME() 格式化输出指定占符宽度。
2.修改 GET_CURRENT_TIME(const wchar_t *format) 应当使用 format 参数控制格式化输出。
3.获取时间函数 增加支持 UNICODE 版本。
4. warning C4996 提示不安全函数。



2019-10-22

1.为适配调测 atlmfc 变更使用 C 运行时库内容。引用c++标准库报错。
2.修改日志工具 LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 输出仅时间BUG。
3.为 FUN_LOG_TO_DEFAULT_FILE_FORMAT_STR_ENDL 、 FUN_LOG_TO_SPECIFIC_FILE_FORMAT_STR_ENDL 增加互斥锁。