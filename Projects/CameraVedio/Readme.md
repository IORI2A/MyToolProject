## DirectShow MSDN中学习了解

Win32 and COM Development
Graphics and Multimedia
Audio and Video
DirectShow


**Introduction to DirectShow**

windows 平台的流媒体框架 
an architecture for streaming media on the Microsoft Windows platform

高效的捕获或回放流媒体
high-quality capture and playback of multimedia streams.

支持多种媒体格式

自动使用硬件加速
automatically detects and uses video and audio acceleration hardware when available

框架基本COM技术，只有使用C++语言
based on the Component Object Model (COM). 
must be written in C++. 

可使用 DirectShow 写播放器、编辑器、转换器、捕获程序、编解码器、数字信号处理器等
write with DirectShow include file players, TV and DVD players, video editing applications, file format converters, audio-video capture applications, encoders and decoders, digital signal processors, and more. 


**Introduction to DirectShow Application Programming**

DirectShow 的框架结构解说，有图示表达

介绍 DirectShow 中的基本术语和概念
basic terminology and concepts that are used in DirectShow.

*Filters and Filter Graphs*

filter 视为一种软件组件
filter is a software component 

filter 接收输入，产生输出
Filters receive input and produce output.

串联 filter ，一个输出成为另一个的输入
connecting chains of filters together, so that the output from one filter becomes the input for another. 

串联 filter ，就是 filter graph
A set of connected filters is called a filter graph. 

Filter Graph Manager 管控 filters
the filters are controlled by a high-level component called the Filter Graph Manager

也可以直接通过底层接口操作 filters
can access the filters directly through COM interfaces

Filter Graph Manager 会发送底层相应事件给上层程序
Filter Graph Manager also passes event notifications to the application. 


Filter Graph Manager 提供操作方法来组合 filters 构建 filter graph
provides methods for the application to build the filter graph, by connecting the filters together.

*Writing a DirectShow Application*

写 DirectShow 程序的主要三步
there are three tasks that any DirectShow application must perform

1. 创建 Filter Graph Manager
The application creates an instance of the Filter Graph Manager. 
2. 使用 Filter Graph Manager 添加 filter 构建 filter graph
The application uses the Filter Graph Manager to build a filter graph. 
3. 使用 Filter Graph Manager 操作 filter graph，并响应及反馈的事件
The application uses the Filter Graph Manager to control the filter graph and stream data through the filters. 
the application will also respond to events from the Filter Graph Manager. 


**Using the System Device Enumerator**

1. 调用 CoCreateInstance 创建 system device enumerator ，其导出 ICreateDevEnum 接口。
Create the system device enumerator by calling CoCreateInstance. The class identifier (CLSID) is CLSID_SystemDeviceEnum. 
2. 使用 ICreateDevEnum::CreateClassEnumerator 创建 enumerator ，其导出接口 IEnumMoniker 。
Obtain a category enumerator by calling ICreateDevEnum::CreateClassEnumerator with the CLSID of the desired category. 
This method returns an IEnumMoniker interface pointer. 
If the category is empty (or does not exist), the method returns S_FALSE rather than an error code. If so, the returned IEnumMoniker pointer is NULL and dereferencing it will cause an exception. Therefore, explicitly test for S_OK when you call CreateClassEnumerator, instead of calling the usual SUCCEEDED macro. 
3. 使用 IEnumMoniker::Next 遍历所有 moniker ，其导出 IMoniker 接口。
Use the IEnumMoniker::Next method to enumerate each moniker. This method returns an IMoniker interface pointer. 
When the Next method reaches the end of the enumeration, it also returns S_FALSE, so again check for S_OK. 
4. 使用 IMoniker::BindToStorage 导出 IPropertyBag 接口，从该接口可获取友好名字。
To retrieve the friendly name of the device (for example, to display in the user interface), call the IMoniker::BindToStorage method. 
5. 使用 IMoniker::BindToObject 创建并初始化代表该设备的 filter ，得到其接口 IBaseFilter 。
To create and initialize the DirectShow filter that manages the device, call IMoniker::BindToObject on the moniker.


**杂项**

某种意义上 设备就是 filter
filters that represent hardware devices
The applicationc can treat each device as a separate filter, regardless of the underlying implementation.

IMoniker (Device Moniker) 对应到 filter
each moniker represents a filter














