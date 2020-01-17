


**2020-01-17 P1**
1. 学习了解WINDWOS实现调用打印机进行打印的工程 windows_printer_study 。
- 新建一个 vs2008 对话框程序 SimplePrint 进行学习开发、调测。
- WIN32 方式，通过使用 PRINTDLG 和 PrintDlg 显示打印对话框。
- 不使用界面交互（打印对话框）。 想实现后台隐藏打印。 使用 CreateDC 来创建打印机的 DC 进行输出打印。



**2020-01-09 P1**
1. Tool 工具中增加获取windows的函数调用失败后，产生的系统错误（原因）码。可通过该错误码获取到对应的错误描述信息。
- 以字符串返回，同时返回错误码 支持ASNI 和 UNICODE 。DWORD GetLastErrorCodeAndText(LPVOID lpText, DWORD nSize);
- Error 消息框 显示。 void ErrorCodeOfFunctionDisplayOnMessageBox(LPTSTR lpszFunction);
- Error handling 控制台 输出。 void DispalyErrorInfor(LPTSTR lpszFunction);
2. 修复 BUG ，CMyLog::LogEndl 出现该输出 wchar_t 中文时为 ？ 串。
- MSDN : Encodings Used Based on Flag and BOM
- 优化该函数，在 _wfopen 创建文件时同时指定编码方式。


**2020-01-08 P2**
1. 提供一个简版的仅记录函数名称信息的接口 TOOL_AUTO_LOG_FUNCTION_INFO_NO_FILE() 。
- CMyAutoLogName 同步实现一个简版的构造函数。
- 相应的析构函数进行修改调整。


**2020-01-08 P1**
1. TOOL 自动记录函数名信息功能中，当文件名、函数名等过长时，空间不够用，会有堆异常写报错。
- 使用静态常量定义堆分配的存储长度。方便后续报错时调整。


**2019-12-25**
1. 暂时结束学习使用 Xamarin 开发 Android 。
- 调测使用 IDE 配置出的安卓仿真机器可以成功运行示例。 （高版本， Android 8.0 ）
  + 根据说明配置加速。但仍感觉慢，好像加速未配置成功的样子。
- 使用小米手机可成功运行该示例。
  + 小米手机是  Android 4.4 ，需要对应配置低版本。
  + 小米手机需要设备上设置很多有关开发的选项。
  + 是通过 IDE 直接连接部署安装的。
  
**2019-12-14**
1. 学习使用 Xamarin 开发 Android 。
- Xamarin.Android 开发学习，官方示例 Phoneword 。
- 官方参考 [Xamarin.Android](https://docs.microsoft.com/en-us/xamarin/android/)
2. 分析时间函数是否支持毫秒。
- struct tm 没有毫秒字段。所以C系列的函数操作无法打印毫秒信息。
- SYSTEMTIME st 有毫秒字段。可支持毫秒输出。Windows系统函数。

**2019-12-09**
1. QT 技术暂时停用，研究到目前暂停学习。
- Books 示例。演示 Qt SQL 类与 QT model/view 框架结合使用。数据库 SQLITE 。
- ConToMysql_Console 探索 QT 连接访问 MSSQL 。

**2019-12-05**
1. BUG 修复
- CZkemDeviceBW::SetUserInfo 和 CZkemDeviceTFT::SetUserInfo 返回值一直为 0 问题。
- 门禁机人员名字有限制，过长将自动截断，并有可能导致操作返回失败并将机器置为错误状态。不同机型，效果有差异。
2. 调测涉及机型有黑白屏门禁机 MA300 ，彩屏门禁机 F20PLUS 。
3. 新增部分方法进行调测。
- 调测 ClearKeeperData 方法。
- 调测 RefreshData 方法。
- 调测 SetStrCardNumber 方法。
- 调测 EnableDevice 方法。
  + 针对彩屏门禁机 F20PLUS 其使用 TRUE （启用设备）有类似恢复、清空错误状态的效果。
  + 调测程序：连接设备》设置超长用户信息（成功，该动作反复重复都成功，其实内部状态已经错误）， 官方调测程序：已经保持在连接设备》设置正常用户信息（失败，该动作反复重复都失败，即使 EnableDevice TRUE 也无法清空错误状态），调测程序：EnableDevice TRUE （应该是清空了错误状态）， 官方调测程序：已经保持在连接设备》设置正常用户信息（成功，反复都成功）
  + 调测程序：保持在连接设备》设置超长用户信息（成功，该动作反复重复都成功，其实内部状态已经错误）， 官方调测程序：已经保持在连接设备》设置正常用户信息（失败，该动作反复重复都失败，即使 EnableDevice TRUE 也无法清空错误状态），调测程序：断开连接， 官方调测程序：已经保持在连接设备》设置正常用户信息（初次失败，后续成功，再反复都成功，应该是 EnableDevice TRUE 清空了错误状态）
  + 官方调测程序 Card Management ，其设置用户信息时，前后会调用 EnableDevice 禁用、重用机器。
  + 建议设备进行操作，最好在操作前后禁用、重用机器，或者每次操作都重建、断开连接。
4. CZkemDevice 类体系中基类实现默认构造函数。简化后续使用代码的编写。
- 默认构造父窗口即为程序主窗口，控件ID自动增长分配。
5. 扩展 CZkemDevice 类体系，派生具体机型子类。
6. 一个对话窗口难以容下所有调测，新增一个对话框窗口用于调测。
- ReadAllUserID 、 GetAllUserInfo  待后续调测验证。
7. Tool 记录描述有关 BSTR 、 _bstr_t 、 char 、 wchar 、 CString 、 Unicode 、 ANSI 间的转换。

**2019-12-03**
1. 一个用于调测ZK不同型号门禁设备的DEMO示例。
- 中控ZKEM控件自动生成 CZkem1 源码。
- 在中控ZKEM控件上进行一层封装，方便后续扩展添加内容。
- 想再在 ZkDevice 上进行封装  目前未使用  后续有使用再说。
- 添加部分控件 调测中控SDK。
- 调测中控SDK GetDeviceIP \ SetUserGroup 。
- 调测中控SDK GetLastError  多个操作检测返回错误码。
- 增加计算函数调用时长 （时钟、时间）。
- 增加调测函数运行时钟时长。
- 调测中控SDK SetUserInfo ，该函数根据设备类型不同接口名称有变，因此同时调测  IsTFTMachine 函数。
  + 类统一接口为 SetUserInfo 内部根据 IsTFTMachine 判定类型调用实际接口。
- ZK设备型号多种多样，不同设备的接口函数方法有一定差异。考虑运用使用 c++ 的继承和动态绑定，来设计支持这种现象。
  + 使用新的运用继承和动态绑定的ZK设备类体系。

**2019-12-01**

1. 针对 TOOL_AUTO_LOG_FUNCTION_INFO() 宏方法，使用到 CMyAutoLogName ，其使用到 Tool::CMyMFCStudyLog ，其新增了互斥锁限制。
- 为保证在增加互斥锁功能之前的旧代码可不更改即可运行，在该宏内实现在调用之前进行互斥锁的初始化。
- 问题，但没有合适的地方进行自动释放删除？ 
- 为方便调用互斥锁的初始化方法，需要进行前向声明。
2. 使用 Tool::CMyMFCStudyLog 会涉及到内部的资源动态分配。
- 目前 Tool::CMyMFCStudyLog 提供的方式是，对内部资源需要手动进行释放，避免泄漏。
- 释放方法， Tool::CMyMFCStudyLog::FREE() 。
3. 修复部分互斥锁（临界区）释放方法内部错误调用成初始化了 ，更改为 DeleteCriticalSection 进行释放。

**2019-11-26**

1. 想要研究一下 QT 多线程编程，Welcome 页面示例中搜索到示例 Blocking Master Example 。
- 示例程序位置（D:\Qt\Qt5.8.0\Examples\Qt-5.8\serialport\blockingmaster）。
- 分析代码相关内容：
  + 获取串口信息，及串口简单操作。
  + 直接手动编码创建控件并布局。
  + 连接源/信号 到 目的地/槽，及信号触发。
  + 线程的创建运行，及重写实现部分方法。
  + QT 中字符串的格式化输出方式。
  + 互斥量（互斥锁）/ 事件的简单使用。
  + 字节与字符串间的转换。
- 同时建立一个 BlockingMaster 工程仿写、调测分析。
  + 全局宏 qDebug 。用于在程序调测输出窗口输出内容。

**2019-11-24**

1. 主要结合帮助文档 Getting Started Programming with Qt Quick 分析示例 gettingStartedQml 源码内容。
- C++ 实现插件(plugin)部分的源码内容。
  + QT Creator 中提供项目集管理概念， 类似 VS 中解决方案。
  + 如何定义实现供 QML 使用的 C++ 扩展插件(plugin)。
  + 项目文件配置 qml 程序使用 C++ 扩展插件(plugin)。
  + 通过项目文件配置插件(plugin)的放置位置。
  + 插件(plugin)如何定义可被 QML 使用的属性及函数。
  + 涉及有文件目录定位、创建；文件创建、开关；结合流进行读写等着操作。
- QML 部分的源码内容。
  + 感觉 QT 中模块名就是对应到同名的目录名。
2. 参考示例 gettingStartedQml 源码调测自己缩写的同名工程。
  + 分析 QML 中元素的坐标体系及区域分割。
  + 分析 QML 中元素的颜色及渐变色。

**2019-11-20**

1. 方便整合QT方面的学习资料集中到一起，新建子级目录以 QT_Study_X 命名，说明是其他网络、书籍方面的资料（非官方）。
- 直接在 QT_Study 目录下的示例文档一般是参考官方资料进行学习产生的。

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







