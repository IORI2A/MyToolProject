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