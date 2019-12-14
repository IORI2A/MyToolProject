**构建一个命令行脚本 删除不需要归档的文件。**

**搜索： bat 清理工程项目**
- [如何用.bat文件清理工程目录](http://www.voidcn.com/article/p-moxwkywz-vo.html)
  + **搜索： bat for**
    - [bat(续七)-for语句(循环结构)](https://www.cnblogs.com/lm002003/archive/2012/05/15/2502439.html)



**一个用于调测ZK不同型号门禁设备的DEMO示例。**
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
- BUG 修复
  + CZkemDeviceBW::SetUserInfo 和 CZkemDeviceTFT::SetUserInfo 返回值一直为 0 问题。
  + 彩屏门禁机F20PLUS，人员名字如"abcdefghijklmnopqrstuvwxyz"则截取到 "abcdefghijklmnopqrstuvw"
  + 黑白屏门禁机MA300，人员名字如"1234567890"则截取到 "12345678"
- 调测涉及机型有黑白屏门禁机 MA300 ，彩屏门禁机 F20PLUS 。
- 调测 ClearKeeperData 方法。
- 调测 RefreshData 方法。
- 调测 SetStrCardNumber 方法。
- 调测 EnableDevice 方法。
  + 针对彩屏门禁机 F20PLUS 其使用 TRUE （启用设备）有类似恢复、清空错误状态的效果。
  + 调测程序：连接设备》设置超长用户信息（成功，该动作反复重复都成功，其实内部状态已经错误）， 官方调测程序：已经保持在连接设备》设置正常用户信息（失败，该动作反复重复都失败，即使 EnableDevice TRUE 也无法清空错误状态），调测程序：EnableDevice TRUE （应该是清空了错误状态）， 官方调测程序：已经保持在连接设备》设置正常用户信息（成功，反复都成功）
  + 调测程序：保持在连接设备》设置超长用户信息（成功，该动作反复重复都成功，其实内部状态已经错误）， 官方调测程序：已经保持在连接设备》设置正常用户信息（失败，该动作反复重复都失败，即使 EnableDevice TRUE 也无法清空错误状态），调测程序：断开连接， 官方调测程序：已经保持在连接设备》设置正常用户信息（初次失败，后续成功，再反复都成功，应该是 EnableDevice TRUE 清空了错误状态）
  + 官方调测程序 Card Management ，其设置用户信息时，前后会调用 EnableDevice 禁用、重用机器。
  + 建议设备进行操作，最好在操作前后禁用、重用机器，或者每次操作都重建、断开连接。
- CZkemDevice 类体系中基类实现默认构造函数。简化后续使用代码的编写。
  + 默认构造父窗口即为程序主窗口，控件ID自动增长分配。
- 扩展 CZkemDevice 类体系，派生具体机型子类。
- 一个对话窗口难以容下所有调测，新增一个对话框窗口用于调测。
  + ReadAllUserID 、 GetAllUserInfo  待后续调测验证。


**一些分析记录**
1. 分析代码得到相关内容：
- 初始化设备
- 照片
- 用户
- 用户组
- 用户时间段
- 用户指纹
- 组
- 组时间段
- 语音

2. 文档提到：
- 考勤记录
- 用户
- 卡
- 指纹
- 门禁规则
- 机器基础配置
- 事件
- 短消息
- 提示音
- 指纹算法
- 高速缓冲区
- 时间段
- 组
- 开锁组合
- 操作记录
