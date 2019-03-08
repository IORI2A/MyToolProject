## DirectShow MSDN中学习了解


```
Win32 and COM Development
Graphics and Multimedia
Audio and Video
DirectShow
Introduction to DirectShow
```

windows 平台的流媒体框架
`an architecture for streaming media on the Microsoft Windows platform`

高效的捕获或回放流媒体
`high-quality capture and playback of multimedia streams.`

支持多种媒体格式

自动使用硬件加速
`automatically detects and uses video and audio acceleration hardware when available`

框架基本COM技术，只有使用C++语言
`based on the Component Object Model (COM). `
`must be written in C++. `

可使用 DirectShow 写播放器、编辑器、转换器、捕获程序、编解码器、数字信号处理器等
`write with DirectShow include file players, TV and DVD players, video editing applications, file format converters, audio-video capture applications, encoders and decoders, digital signal processors, and more. `


```
Win32 and COM Development
Graphics and Multimedia
Audio and Video
DirectShow
Getting Started 
Introduction to DirectShow Application Programming
```

DirectShow 的框架结构解说，有图示表达

介绍 DirectShow 中的基本术语和概念
`basic terminology and concepts that are used in DirectShow.`

- *Filters and Filter Graphs*

filter 视为一种软件组件
`filter is a software component `

filter 接收输入，产生输出
`Filters receive input and produce output.`

串联 filter ，一个输出成为另一个的输入
`connecting chains of filters together, so that the output from one filter becomes the input for another. `

串联 filter ，就是 filter graph
`A set of connected filters is called a filter graph. `

Filter Graph Manager 管控 filters
`the filters are controlled by a high-level component called the Filter Graph Manager`

也可以直接通过底层接口操作 filters
`can access the filters directly through COM interfaces`

Filter Graph Manager 会发送底层相应事件给上层程序
`Filter Graph Manager also passes event notifications to the application. `

Filter Graph Manager 提供操作方法来组合 filters 构建 filter graph
`provides methods for the application to build the filter graph, by connecting the filters together.`

- *Writing a DirectShow Application*

写 DirectShow 程序的主要三步
`there are three tasks that any DirectShow application must perform`

1. 创建 Filter Graph Manager
`The application creates an instance of the Filter Graph Manager. `
2. 使用 Filter Graph Manager 添加 filter 构建 filter graph
`The application uses the Filter Graph Manager to build a filter graph. `
3. 使用 Filter Graph Manager 操作 filter graph，并响应及反馈的事件
`The application uses the Filter Graph Manager to control the filter graph and stream data through the filters. `
`the application will also respond to events from the Filter Graph Manager.` 


```
Win32 and COM Development
Graphics and Multimedia
Audio and Video
DirectShow
Using DirectShow
Basic DirectShow Tasks
Enumerating Devices and Filters
Using the System Device Enumerator
```

1. 调用 CoCreateInstance 创建 system device enumerator ，其导出 ICreateDevEnum 接口。
`Create the system device enumerator by calling CoCreateInstance. The class identifier (CLSID) is CLSID_SystemDeviceEnum. `
2. 使用 ICreateDevEnum::CreateClassEnumerator 创建 enumerator ，其导出接口 IEnumMoniker 。
`Obtain a category enumerator by calling ICreateDevEnum::CreateClassEnumerator with the CLSID of the desired category. `
`This method returns an IEnumMoniker interface pointer. `
`If the category is empty (or does not exist), the method returns S_FALSE rather than an error code. If so, the returned IEnumMoniker pointer is NULL and dereferencing it will cause an exception. Therefore, explicitly test for S_OK when you call CreateClassEnumerator, instead of calling the usual SUCCEEDED macro. `
3. 使用 IEnumMoniker::Next 遍历所有 moniker ，其导出 IMoniker 接口。
`Use the IEnumMoniker::Next method to enumerate each moniker. This method returns an IMoniker interface pointer. `
`When the Next method reaches the end of the enumeration, it also returns S_FALSE, so again check for S_OK. `
4. 使用 IMoniker::BindToStorage 导出 IPropertyBag 接口，从该接口可获取友好名字。
`To retrieve the friendly name of the device (for example, to display in the user interface), call the IMoniker::BindToStorage method. `
5. 使用 IMoniker::BindToObject 创建并初始化代表该设备的 filter ，得到其接口 IBaseFilter 。
`To create and initialize the DirectShow filter that manages the device, call IMoniker::BindToObject on the moniker.`


**杂项**

某种意义上 设备就是 filter
`filters that represent hardware devices`
`The applicationc can treat each device as a separate filter, regardless of the underlying implementation.`

IMoniker (Device Moniker) 对应到 filter
`each moniker represents a filter`


```
Win32 and COM Development
Graphics and Multimedia
Audio and Video
DirectShow
Using DirectShow  
Video Capture 
```

+ About Video Capture in DirectShow

从硬件设备中获取视频
`video capture: video is received from a hardware device.`

摄像头算是一种捕获设备
`Video capture devices include not only cameras`

一些基本概念
`some of the concepts`

- *About the Capture Graph Builder*

> DirectShow_VideoCapture_SelectingACaptureDevice.cpp

capture graph
`A filter graph that performs video or audio capture is called a capture graph. `

Capture Graph Builder 导出 ICaptureGraphBuilder2 接口创建、操作 capture graph
`The Capture Graph Builder exposes the ICaptureGraphBuilder2 interface, which contains methods for building and controlling a capture graph. `

调用 CoCreateInstance 来创建 Capture Graph Builder (ICaptureGraphBuilder2) 和 Filter Graph Manager (IGraphBuilder) 实例
`calling CoCreateInstance to create new instances of the Capture Graph Builder and the Filter Graph Manager. `

使用 Filter Graph Manager 来初始化 Capture Graph Builder
`Then initialize the Capture Graph Builder by calling ICaptureGraphBuilder2::SetFiltergraph with a pointer to the Filter Graph Manager's IGraphBuilder interface. `

原则上优先使用 Capture Graph Builder 创建 capture graph ，也可以直接使用 IGraphBuilder (Filter Graph Manager) 来创建，但那是高阶使用方式。
`it is possible to build capture graphs entirely by using IGraphBuilder methods. This is considered an advanced topic, however, and the Capture Graph Builder methods are preferred. `

InitCaptureGraphBuilder

- *About Video Capture Devices*

两种类型 capture device , VFW 现已经被放弃
`WDM Video Capture filter`
`VFW Capture filter`

- *DirectShow Video Capture Filters*

capture filter 有自己不同与其他 filter 的特性
Capture filters in DirectShow have some features that distinguish them from other kinds of filters.

Pin Categories

A capture filter often has two or more output pins that deliver the same kind of data—for example, a preview pin and a capture pin. 
the pins are distinguished by their functionality, which is identified using a GUID, called the pin category.

ICaptureGraphBuilder2 methods take parameters that specify the pin category
The Capture Graph Builder automatically locates the correct pin.

Preview Pins and Capture Pins

The preview pin is used to render video to the screen, while the capture pin is used to write video to a file.

preview pin 与 capture pin 的一些区别
A preview pin and a capture pin have the following differences:
A preview pin drops frames as needed to maintain throughput on the capture pin.
Each frame from a capture pin is time-stamped with the stream time when the frame was captured. A preview pin does not time stamp the samples it delivers.


捕获时间与预览时间可能有延迟，可能导致显示时丢帧

The pin category for preview pins is PIN_CATEGORY_PREVIEW. The category for capture pins is PIN_CATEGORY_CAPTURE.

Video Port Pins


+ Selecting a Capture Device

> DirectShow_VideoCapture_AboutTheCaptureGraphBuilder.cpp

`A moniker is a COM object that contains information about another object. Monikers enable the application to get information about an object without actually creating the object. Later, the application can use the moniker to create the object. `

+ Previewing Video

> DirectShow_VideoCapture_PreviewingVideo.cpp


```
Docs
Windows  
DirectShow
DirectShow Editing Services
Using DirectShow Editing Services
Using the Sample Grabber 
```

> DirectShow_UsingTheSampleGrabber.cpp

Sample Grabber filter 作为一个中间传输件，可从传输的流中抓取帧
`The Sample Grabber filter is a transform filter that can be used to grab media samples from a stream as they pass through the filter graph.`

+ Create the Filter Graph Manager

+ Add the Sample Grabber to the Filter Graph

+ Set the Media Type

+ Build the Filter Graph


```
Docs
Windows  
DirectShow
Using DirectShow
Basic DirectShow Tasks
General Graph-Building Techniques
Connect Two Filters 
```

> DirectShow_ConnectTwoFilters.cpp

`Output Pin to Filter`
`Filter to Input Pin`
`Filter to Filter`


```
Docs
Windows  
DirectShow
Using DirectShow
Basic DirectShow Tasks
General Graph-Building Techniques
Find an Unconnected Pin on a Filter
```

> DirectShow_FindAnUnconnectedPinOnAFilter.cpp


```
Docs
Windows  
DirectShow
DirectShow Reference
DirectShow Base Classes
Utility Functions
Media Type Functions
FreeMediaType 
```
> DirectShow_FreeMediaType.cpp


```
Win32 and COM Development
Graphics and Multimedia
Audio and Video
DirectShow
DirectShow Reference 
DirectShow Structures
```

**AM_MEDIA_TYPE Structure**

该结构体描述视频帧格式信息
`describes the format of a media sample.`

数据块类型
`formattype`

数据块大小
`cbFormat`

数据块
`pbFormat`

**VIDEOINFOHEADER Structure**

视频帧图像作为位图来描述
`describes the bitmap and color information for a video image. `

帧图像的位图结构信息
`bmiHeader`
`BITMAPINFOHEADER structure that contains color and dimension information for the video image bitmap.`
`If the format block contains a color table or color masks, they immediately follow the bmiHeader member. You can get the first color entry by casting the address of member to a BITMAPINFO pointer. `

```
Win32 and COM Development
Graphics and Multimedia
Audio and Video
DirectShow
DirectShow Reference
DirectShow Base Classes
Utility Functions
Video and Image Functions
```

**SIZE_PREHEADER**

计算 SIZE_PREHEADER 在 VIDEOINFOHEADER 中的位置
`The SIZE_PREHEADER macro calculates the byte offset of the bmiHeader field within a VIDEOINFOHEADER structure. `





