## Video Preview and Frames Capture to Memory with SampleGrabber in Buffered Mode

+ 来源 https://www.codeproject.com/Articles/21048/Video-Preview-and-Frames-Capture-to-Memory-with-Sa

**配置VS中引用dll目录**
```
https://blog.csdn.net/yangpan011/article/details/78615779

配置属性->调试->环境：输入path=包含dll文件的文件夹路径，
注意是包含dll文件的文件夹的路径，而不是dll文件的路径
注意path(空格)=路径、path=(空格)路径、path(空格)=(空格)路径等写法都会导致dll引用失败。
注意 不要有空格、最后一定要以半角分号结束。

PATH=E:\LZ\test\MyToolProject\Projects\ArcSoft_ArcFace_Windows_V1.2_Medium\ARCSOFT_FSDK_FACE_TRACKING_1.2.0.726_VS2013_WIN32_10212019\lib\;
```

## 合入虹软人脸识别功能，调测学习人脸识别认证。

**人脸追踪(FT) ARCSOFT_FSDK_FACE_TRACKING**

- 该库主要支持根据输入的图像检测人脸，一般用于视频检测，多帧方式。
- 视频帧图像就是位图数据，可直接作为 ASVLOFFSCREEN 中的图像数据？
- 视频帧图像数据虽是位图数据在直接显示是倒转的，需要反转处理。只有反转处理后人脸检测才能检测到人脸。
- 问题：绘制的人脸框闪烁，且越快频率越高。如何处理？

**人脸检测(FD) ARCSOFT_FSDK_FACE_DETECTION**

- 该库经调测也可直接使用帧图像数据，进行人脸检测。
- 调测使用静态图片进行人脸检测。

**人脸识别(FR) ARCSOFT_FSDK_FACE_RECOGNITION**

- 为简化调测仅取图片（工程中需要提供一张图片）中第一个人的人脸。
- 为完整调测功能，每次都是初始化引擎，使用完成又释放引擎。
- 初始化加载图片提取人脸特征，保存一全局变更中作为比较基准。后续从视频中提取人脸与基准进行比对。绘制显示人脸框及比对数值。


