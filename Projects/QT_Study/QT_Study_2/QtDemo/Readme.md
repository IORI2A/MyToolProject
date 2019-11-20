# Demo

一个“Hello World”程序。仅是简单的创建一个窗口程序工程项目，拖放一个控件，进行简单的属性设置。编译运行。（类名 MainWindow ，选择 QMainWindow 作为基类。）

主要是了解如何创建项目(Qt Widgets Application)，项目的文件组成和管理，以及项目的编译、调试与运行。

[编写第一个Qt程序](http://c.biancheng.net/view/1817.html)

# samp2_1

也是一个类“Hello World”程序。增加了按钮，通过 Qt Creator 中的 Qt Designer 使用信号与槽（signal 和 slot）机制。无任何代码编写。（类名 widget ，选择 QWidget 作为窗体基类。）

主要是了解分析项目内各个文件内容，及其功能作用。可视化设计的UI文件是如何被转换为 C++ 的类定义，并自动创建界面的。

主要涉及：
- 工程文件 Qt 模块的引用。
- 通过 UI 设计器设计界面，使用信号与槽机制。
- 窗体类的定义，以及界面功能的实现原理。
- 编译 .ui 文件生成的源码文件(.h)的解析。

自我理解：
窗体类，也就是主界面窗口。 是程序员通过自我定义实现的，可完全直接操控。
但主界面窗口上的组件，即是通过设计后，由工具自动来创建、设置的。工具通过一个 ui 指针来关联这些自动创建的组件，并暴露给程序员，从而使得程序员可以间接的操作各个组件。
	

[Qt项目管理文件（.pro）及其作用详解](http://c.biancheng.net/view/1819.html)
[Qt项目界面文件（.ui）及其作用（超详细）](http://c.biancheng.net/view/1820.html)
[Qt项目中main主函数及其作用](http://c.biancheng.net/view/1821.html)



