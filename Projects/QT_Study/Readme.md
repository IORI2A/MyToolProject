```
该目录(QT_Study)下的示例文档是参考官方资料进行学习产生的。
但为了方便整合QT方面的学习资料放到一起，新建子级目录以 QT_Study_X 命名，说明是其他网络、书籍方面的资料（非官方）。

QT_Study_2 
学习[Qt教程，Qt5编程入门教程（非常详细）](http://c.biancheng.net/qt/) 时生成的内容。
```



# Getting Started with Qt 


**Getting Started Programming with Qt Widgets**

- Notepad 示例程序演示使用 C++ 语言和 Qt Widgets。
- 主要使用 Qt Creator 和 Qt Designer 来实现开发设计。
- Notepad 示例源码位置。（D:\Qt\Qt5.8.0\5.8\Src\qtdoc\doc\src\snippets\widgets-tutorial\notepad）
- 参考文档说明仿写 Notepad 程序(QT_Study\Notepad)。


**Getting Started Programming with Qt Quick**

- 利用QML和QtC++，可以有效地将接口逻辑与应用程序逻辑分离。
- 示例源码位置。(D:\Qt\Qt5.8.0\Examples\Qt-5.8\quick\tutorials\gettingStartedQml)
- 参考文档说明仿写 text editor 程序(QT_Study\GettingStartedQml)。（仅仿写部分QML）
- 分析示例 gettingStartedQml 中 C++ 实现插件(plugin)部分的源码内容。
  + QT Creator 中提供项目集管理概念， 类似 VS 中解决方案。
  + 如何定义实现供 QML 使用的 C++ 扩展插件(plugin)。
  + 项目文件配置 qml 程序使用 C++ 扩展插件(plugin)。
  + 通过项目文件配置插件(plugin)的放置位置。
  + 插件(plugin)如何定义可被 QML 使用的属性及函数。
  + 涉及有文件目录定位、创建；文件创建、开关；结合流进行读写等着操作。
- 分析示例 gettingStartedQml 中 QML 部分的源码内容。
  + 感觉 QT 中模块名就是对应到同名的目录名。
- 参考示例调测自己缩写的同名工程。
  + 分析 QML 中元素的坐标体系及区域分割。
  + 分析 QML 中元素的颜色及渐变色。

**构建一个命令行脚本 del_compile_temp_file.bat 删除不需要归档的文件。**如，*.qmlproject.user *.pro.user *.qmlc 

**方便整合QT方面的学习资料集中到一起，新建子级目录以 QT_Study_X 命名，说明是其他网络、书籍方面的资料（非官方）。**
- 直接在 QT_Study 目录下的示例文档一般是参考官方资料进行学习产生的。
