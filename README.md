**2019-11-19**

1. 学习使用 Qt Widgets 编程。
- 入门示例 Notepad 源码位置 snippets/widgets-tutorial/notepad 。（D:\Qt\Qt5.8.0\5.8\Src\qtdoc\doc\src\snippets\widgets-tutorial\notepad）
- 参考文档说明 Getting Started Programming with Qt Widgets ，仿写 Notepad 程序(QT_Study\Notepad)。
2. 学习使用 Qt Quick (QML) 编程。
- 入门示例源码位置 examples/quick/tutorials/gettingStartedQml 。(D:\Qt\Qt5.8.0\Examples\Qt-5.8\quick\tutorials\gettingStartedQml)
- 参考文档说明 Getting Started Programming with Qt Quick ，仿写 text editor 程序(QT_Study\GettingStartedQml)。（仅仿写部分QML）
3. 构建一个命令行脚本 del_compile_temp_file.bat 删除不需要归档的文件。如，*.qmlproject.user *.pro.user *.qmlc 

**2019-11-13**

1. 解决 warning: C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
- 参考： https://www.cnblogs.com/markleaf/p/7781127.html 
- 转换Code文件为： UTF-8 带BOM 格式；
- 如果是 Qt Creator，设置【项目编辑器】，【文件编码】为：UTF-8，【UTF-8 BOM】：如果编码是UTF-8则添加。最后随便改动一下出现警告的文件保存，就会保存为：UTF-8 带BOM 格式。
- 如果是 VS IDE，打开有该warning的文件，点击【文件】选【高级保存选项】，改变编码格式为【简体中文（GB2312）- 代码页936】或【Unicode（UTF-8 带签名）-代码页65001】，保存。
- 仅实测：VS IDE，【文件】选【高级保存选项】，改变编码格式为【简体中文（GB2312）- 代码页936】 可行。
2. 将打印函数调用堆栈的功能独立为单独的代码文件，需要使用再加载相关内容。
- 之前引用Tool的工程就可以不用再加载 StackWalker 的相关内容。
3. 编译阶段打印宏内容。
- 定义两个辅助宏。
4. 虹软 SDK 免费使用，是需要一年到期又重新申请下载更新引擎。 



**2019-11-12**

1. 工程 VideoPreviewAndFramesCapture 合入虹软人脸识别功能，调测学习人脸识别认证。
- 人脸追踪(FT) ARCSOFT_FSDK_FACE_TRACKING
- 人脸检测(FD) ARCSOFT_FSDK_FACE_DETECTION
- 人脸识别(FR) ARCSOFT_FSDK_FACE_RECOGNITION



**2019-11-08**

1. 增加使用 DirectShow 进行摄像头视频捕获截取帧图片的工程 CameraVedio 。
- 根据文档说明调测示例代码。
- 根据文档及代码段示例，实现预览摄像头视频。
- 捕获视频文件的帧图像。
- 预览视频并捕获帧图片。
2. 学习网上有关使用 DirectShow 进行摄像头预览及捕获帧图片工程。命名为 VideoPreviewAndFramesCapture 。
- Video Preview and Frames Capture to Memory with SampleGrabber in Buffered Mode
- 转为使用 vs2010 调测。
3. 虹软人脸识开发SDK V1.2 。
- 示例代码太简单，有些不足于运行。



**2019-11-07**

1. 增加调测 VC++ 在内存中将Jpeg转换Bmp图片的工程 JPEG2BMP 。
- 简单使用 CImage 加载图片文件进行直接显示。
- 使用现有的CImage类在内存中进行转换，不需要保存为文件，也不需要引入第三方库（ Libjpeg库 ）。
- CImage 对象加载已经在内存中的图片数据（ IStream 流）。
- 将图片文件另存为另一个文件或者格式。确实应该是 CImage 内部自动将其他格式图片数据转换为了对应的BMP数据。
- 使用 GID+ Image Class 将内存中的JPEG二进制数据转换为BMP位图数据。


**2019-11-06**

1. 增加一个可设定是否不进行日志记录的函数方法。
- 为方便 SET_NOT_LOG_FOR 使用来记录 m_mfcNotLog 的值，那么 LOG_TO_FILE_STR 应当不与 m_mfcNotLog 关联，为防止外部引用，使用 protect 保护。
- 使用引用计数方式，便于日志分析何处进行了增减。
- 无法控制 构造函数 初始化列表的执行。
- 增加记录 设置时的 文件、行号、函数出处，便于分析日志。
- 使用宏简化 SET_NOT_LOG_FOR 的调用， 便于记录文件、行号、函数名等信息，便于分析日志内容
2. 增加一个日志记录互斥锁，日志记录函数方法使用前需要初始化锁，使用后需要释放锁。
-  外围已有互斥锁了，可优化不再调用 CTool::LOG_NOT_ENDL 。
3. 日志打印方法内部应该及时输出缓冲内容到文件。
4. 增加强制输出内容的日志函数 FORCE_LOG_TO_FILE_FORMAT_STR_ENDL 。
- 不受 m_mfcNotLog 计数控制。目前提供给 CMyAutoLogName 使用，强制记录执行调用的函数。顺序调用，不挂起线程，应当不会导致卡顿。（非反向遍历函数调用堆栈）
- 受 SET_MFC_DLL_STATUS 控制， IN_NOT_LOG_STATUS 可控制所有日志记录都没有输出。
5. 修改 SET_MFC_DLL_STATUS ， 目前主要用于设置 IN_NOT_LOG_STATUS 。并实现记录文件、行号、函数名等信息，便于分析日志内容。
- IN_NOT_LOG_STATUS 权限最高的是否记录日志标识。可控制 FORCE_LOG_TO_FILE_FORMAT_STR_ENDL 内部调用的 LOG_TO_FILE_STR 。
- 使用宏简化 SET_NOT_LOG_FOR 的调用， 便于记录文件、行号、函数名等信息，便于分析日志内容
6. 日志工具 CMyMFCStudyLog 内部实现调用堆栈打印，更有效的控制调用堆栈打印。
- 与 m_mfcNotLog 关联，及时判定，提高速度。
7. CMyMFCStudyLog::LOG_TO_DEFAULT_FILE_STACK_WALKER 已经进行是否需要打印日志的判定  且 LOG_TO_FILE_STR 是无法访问的 protected 成员


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







