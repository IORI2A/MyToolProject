# Qt教程，Qt5编程入门教程（非常详细）
http://c.biancheng.net/qt/

## Qt是什么？Qt简介（非常全面）
http://c.biancheng.net/view/1792.html

Qt 还存在 Python、Ruby、Perl 等脚本语言的绑定， 也就是说可以使用脚本语言开发基于 Qt 的程序。
派生扩展。

### Qt 可以做什么？

Qt 是应用程序开发的一站式解决方案。（基本上）
Qt 本身包含的模块也日益丰富， 一直有新模块和第三方模块加入进来。 

大部分应用程序都可以使用 Qt 实现，除了与计算机底层结合特别紧密的，例如驱动开发，它直接使用硬件提供的编程接口，而不能使用操作系统自带的函数库。

Qt 虽然也支持手机操作系统，但是由于 Android 本身已经有 Java 和 Kotlin，iOS 本身已经有 Objective-C 和 Swift，所以 Qt 在移动端的市场份额几乎可以忽略。
总起来说，Qt 主要用于桌面程序开发和嵌入式开发。

## Qt和其它GUI库的对比
http://c.biancheng.net/view/3876.html

### Windows 下的 GUI 库

Windows 下的 GUI 解决方案比较多：
基于 C++ 的有 Qt、MFC、WTL、wxWidgets、DirectUI、Htmlayout；
基于 C# 的有 WinForm、WPF；
基于 Java 的有 AWT、Swing；
基于 Pascal 的 有Delphi；
基于Go语言的有 walk 和 electron；
还有国内初露头角的 aardio；
Visual Basic 曾经很流行，现在逐渐失去了色彩；
如果你有 Web 开发经验，也可以基于 Webkit 或 Chromium 将网页转换为桌面程序。

没有哪一种方案能够独霸 Windows，使用比较多的编程语言是 C++、C#、Java。

### Linux 下的 GUI 库

Linux 下常用的 GUI 库有基于 C++ 的 Qt、GTK+、wxWidgets，以及基于 Java 的 AWT 和 Swing。
其中最著名的就是 Qt 和 GTK+：KDE 桌面系统已经将 Qt 作为默认的 GUI 库，Gnome 桌面系统也将 GTK+ 作为默认的 GUI 库。

## 学习QML还是C++？
http://c.biancheng.net/view/3877.html

为了适应手机移动应用开发， Qt5 将 QML 脚本编程提到与传统 C++ 部件编程相同的高度，力推 QML 界面编程，当然 QML 主要用于手机移动应用程序。 

QML 包含大量使用手机移动设备的功能模块，比如基本部件（QtQuick 模块）、GPS 定位、渲染特效、蓝牙、NFC、WebkKit 等等。

QML 类似于网页设计的 HTML，是一种标记语言，我们可以借助 CSS 对它进行美化，也可以借助 JavaScript 进行交互。有 Web 开发经验的读者学习 QML 将非常轻松。

使用 QML 开发界面主要有以下几个优点：
QML 非常灵活，可以做出非常炫酷的效果，例如 QQ、360、迅雷等都不在话下。
QML 是标记语言，见名知意，非常容易编写和阅读，大大提高了开发和维护效率。
QML 界面简洁大气，有很多动画，适合移动端。
不同平台下的 QML 使用相同的渲染机制，界面效果一致，不会随操作系统的不同而变化。

QML 只能用来进行界面设计和人机交互，也就是只能胜任 UI 部分，在底层仍然需要调用 C++ 编写的组件来完善功能，比如访问数据库、网络通信、多线程多进程、文件读写、图像处理、音频视频处理等都离不开 C++。

学习 QML 成本还是比较高的，不但要习惯 QML 这种标记性语言，还要学习 CSS 和 JavaScript。（涉及到）

## Qt下载（多种下载通道+所有版本）
http://c.biancheng.net/view/3851.html

### Qt 官方下载（非常慢）

地址是：http://download.qt.io/

archive	各种 Qt 开发工具安装包，新旧都有（可以下载 Qt 开发环境和源代码）。 
（归档目录）

qt	这是 Qt 开发环境的下载目录 （Qt的各个版本，包括大安装包及完整源码）

single qt的完整源码包。

形如 qt-opensource-windows-x86-5.9.0.exe ，官方编译发布的基于某平台、某种架构的大安装包。

### Qt 国内镜像站下载（较快）

Details 链接。
点击 Details 链接可以进入详情页，在该页面可以看到文件的大小、校验和以及世界各地镜像下载链接（这才是重点）。

这里给大家推荐几个国内著名的 Qt 镜像网站，主要是各个高校的：
中国科学技术大学：http://mirrors.ustc.edu.cn/qtproject/
清华大学：https://mirrors.tuna.tsinghua.edu.cn/qt/
北京理工大学：http://mirror.bit.edu.cn/qtproject/
中国互联网络信息中心：https://mirrors.cnnic.cn/qt/

### 扩展阅读

Qt wiki 网站，地址为：https://wiki.qt.io/Main

## 图解Qt安装（Windows平台）
http://c.biancheng.net/view/3858.html

## 图解Qt安装（Linux平台）
http://c.biancheng.net/view/3886.html

## 解密Qt安装目录的结构
http://c.biancheng.net/view/3866.html

## 认识一下Qt用到的开发工具
http://c.biancheng.net/view/3868.html

## Qt编程涉及的术语和名词
http://c.biancheng.net/view/3871.html

### Project

### Makefile

生成脚本 

为了规范程序的编译生成过程，产生了规范化的生成脚本，就是 Makefile，生成器 make 可以依据规范的 Makefile 自动生成目标程序或库文件。
（调用编译器编译程序）

简单的说，就是定义好 Makefile ，让程序员只需要去关注如何编写代码，而生成程序过程中的脏活累活都交给 make 程序。

现在 Makefile 通常都有工具自动生成，如 qmake 工具， 这样就大量减轻了程序员的负担。

### Debug 和 Release

### C++11 标准

### Dynamic Link 和 Static Link

### Explicit Linking 和 Implicit Linking

## Qt Creator的初步使用
http://c.biancheng.net/view/1804.html

## 编写第一个Qt程序
http://c.biancheng.net/view/1817.html

### 新建一个项目

Qt Creator 可以创建多种项目，在最左侧的列表框中单击“Application”，中间的列表框中列出了可以创建的应用程序的模板，各类应用程序如下： 
Qt Widgets Application，支持桌面平台的有图形用户界面（Graphic User Interface，GUI） 界面的应用程序。GUI 的设计完全基于 C++ 语言，采用 Qt 提供的一套 C++ 类库。
Qt Console Application，控制台应用程序，无 GUI 界面，一般用于学习 C/C++ 语言，只需要简单的输入输出操作时可创建此类项目。
Qt Quick Application，创建可部署的 Qt Quick 2 应用程序。Qt Quick 是 Qt 支持的一套 GUI 开发架构，其界面设计采用 QML 语言，程序架构采用 C++ 语言。利用 Qt Quick 可以设计非常炫的用户界面，一般用于移动设备或嵌入式设备上无边框的应用程序的设计。
Qt Quick Controls 2 Application，创建基于 Qt Quick Controls 2 组件的可部署的 Qt Quick 2 应用程序。Qt Quick Controls 2 组件只有 Qt 5.7 及以后版本才有。
Qt Canvas 3D Application，创建 Qt Canvas 3D QML 项目，也是基于 QML 语言的界面设计，支持 3D 画布。

选择项目类型为 Qt Widgets Application 。
**项目名称为 Demo 。**
最终，项目路径 “~\QtDemo\Demo\”

选择需要创建界面的基类（base class）。有 3 种基类可以选择：
QMainWindow 是主窗口类，主窗口具有主菜单栏、工具栏和状态栏，类似于一般的应用程序的主窗口；
QWidget 是所有具有可视界面类的基类，选择 QWidget 创建的界面对各种界面组件都可以 支持；
QDialog 是对话框类，可建立一个基于对话框的界面；

类名 MainWindow ，选择 QMainWindow 作为基类，自动更改的各个文件名不用手动去修改。

勾选“创建界面”复选框。这个选项如果勾选，就会由 Qt Creator 创建用户界面文件，否则，需要自己编程手工创建界面。
初始学习，为了了解 Qt Creator 的设计功能，勾选此选项。

### 项目的文件组成和管理

只有一个活动项目，活动项目的项目名称节点用粗体字体表示。

文件及分组分别为以下几项：
.pro 是项目管理文件，包括一些对项目的设置项。
Headers 分组，该节点下是项目内的所有头文件（.h）。
Sources 分组：该节点下是项目内的所有 C++源文件（.cpp）。main.cpp 是主函数文件，也是应用程序的入口。
Forms 分组：该节点下是项目内的所有界面文件（.ui）。界面文件是文本文件，使用 XML 语言描述界面的组成。

双击 .ui，出现窗体设计界面。
 Qt Creator 中集成的 Qt Designer。 （可视化的方式设计）

### 项目的编译、调试与运行

在 Build 设置界面上，有一个“Shadow build” 复选框。
如果勾选此项，编译后将在项目的同级目录下建立一个编译后的文件目录，目录名称包含编译器信息，这种方式一般用于使用不同编译器创建不同版本的可执行文件。
如果不勾选此项，编译后将在项目的目录下建立“Debug”和“Release”子目录用于存放编译后的文件。

## VS中使用Qt方法详解
http://c.biancheng.net/view/1818.html

要在 Visual Studio 中使用 Qt，需要安装一个 Visual Studio 的 Qt 插件，这个插件程序由 Qt 公司提供。

安装完成后，在 Visual Studio 的主菜单栏上增加了一个菜单组“Qt VS Tools”，在新建项目向导里增加了可创建 Qt 项目的项目模板。

在首次使用 Visual Studio 编译 Qt 项目之前，必须先进行一些设置，否则会提示没有设置 Qt 版本，无法编译项目。

## Qt项目管理文件（.pro）及其作用详解
http://c.biancheng.net/view/1819.html

选择项目类型为 Qt Widgets Application 。
**项目名称为 samp2_1 。**
最终，项目路径 “~\QtDemo\samp2_1\”

类名 Widget ，选择 QWidget 作为窗体基类。

项目管理文件（.pro文件）
文件名就是项目的名称。
项目管理文件用于记录项目的一些设置，以及项目包含文件的组织管理。

Qt 类库以模块的形式组织各种功能的类，根据项目涉及的功能需求，在项目中添加适当的类库模块支持。

## Qt项目界面文件（.ui）及其作用（超详细）
http://c.biancheng.net/view/1820.html

**示例项目 samp2_1 。**

UI 设计器有以下一些功能区域：（集成在 Qt Creator 中的 Qt Designer ）
[左]组件面板：分为多个组，如Layouts、Buttons、Display Widgets等，界面设计的常见组件都可以在组件面板里找到。
[中]待设计的窗体。如果要将某个组件放置到窗体上时，从组件面板上拖放一个组件到窗体上即可。
[下] Signals 和 Slots 编辑器与 Action 编辑器这两个编辑器。Signals 和Slots 编辑器用于可视化地进行信号与槽的关联，Action 编辑器用于可视化设计 Action。
[上]布局和界面设计工具栏：工具栏上的按钮主要实现布局和界面设计。
[右上]对象浏览器（Object Inspector）：用树状视图显示窗体上各组件之间的布局包含关系，视图有两列，显示每个组件的对象名称（ObjectName）和类名称。
[右下]属性编辑器（Property Editor）：属性编辑器显示某个选中的组件或窗体的各种属性及其取值，可以在属性编辑器里修改这些属性的值。

属性编辑器的内容分为两列，分别为属性的名称和属性的值。属性又分为多个组，实际上表示了类的继承关系。

objectName 表示组件的对象名称，界面上的每个组件都需要一个唯一的对象名称，以便被引用。
界面上的组件的命名应该遵循一定的法则，具体使用什么样的命名法则根据个人习惯而定，主要目的是便于区分和记忆，也要便于与普通变量相区分。

在信号与槽编辑器的工具栏上单击“Add”按钮，设计信号与槽的关联。

标签的文字内容和字体被修改了，窗口标题也显示为所设置的标题，而我们并没有编写一行程序语句，Qt 是怎么实现这些功能的呢？

**搞清楚窗体类的定义，以及界面功能的实现原理**

编译时会根据 widget.ui 中描述的界面（窗体和组件及其属性、信号与槽的关联等）自动生成的一个类的定义文件 ui_widget.h （在编译目录下），类的名称是Ui_Widget

### widget.h 文件

宏 Q_OBJECT，这是使用 Qt 的信号与槽（signal 和 slot）机制的类都必须加入的一个宏。

指针 ui 是指向可视化设计的界面，后面会看到要访问界面上的组件，都需要通过这个指针 ui。（构造函数 创建一个 Ui::Widget 类的对象）

### widget.cpp 文件

### widget.ui 文件

widget.ui 是窗体界面定义文件，是一个 XML 文件，定义了窗口上的所有组件的属性设置、布局，及其信号与槽函数的关联等。
用UI设计器可视化设计的界面都由 Qt 自动解析，并以 XML 文件的形式保存下来。在设计界面时，只需在 UI 设计器里进行可视化设计即可，而不用管 widget.ui 文件是怎么生成的。

### ui_widget.h 文件

自动生成
ui_widget.h 是在对 widget.ui 文件编译后生成的一个文件。
ui_widget.h 会出现在编译后的目录下，或与 widget.ui 同目录（与项目的 shadow build 编译设置有关）。

文件 ui_widget.h 并不会出现在 Qt Creator 的项目文件目录树里。

对 ui_widget.h 手工进行修改没有什么意义，所有涉及界面的修改都应该直接在UI 设计器里进行。

**ui_widget.h 的主要内容：**
- 定义了一个类 Ui_Widget，用于封装可视化设计的界面。
- 自动生成了界面各个组件的类成员变量定义。在 public 部分为界面上每个组件定义了一个指针变量，变量的名称就是设置的 objectName。
- 定义了 setupUi() 函数，这个函数用于创建各个界面组件，并设置其位置、大小、文字内容、字体等属性，设置信号与槽的关联。
  + setupUi() 函数体的第一部分是根据可视化设计的界面内容，用 C++ 代码创建界面上各组件，并设置其属性。
  + 接下来，setupUi() 调用了函数 retranslateUi(Widget)，用来设置界面各组件的文字内容属性，如标签的文字、按键的文字、窗体的标题等。**将界面上的文字设置的内容独立出来作为一个函数 retranslateUi()，在设计多语言界面时会用到这个函数。**
  + setupUi() 函数的第三部分是设置信号与槽的关联。
    - 调用 connect() 函数，将在 UI 设计器里设置的信号与槽的关联转换为语句。
	- 设置槽函数的关联方式，用于将 UI 设计器自动生成的组件信号的槽函数与组件信号相关联。
- 定义 namespace Ui，并定义一个从Ui_Widget 继承的类Widget。


提示：
ui_widget.h 文件里实现界面功能的类是 Ui_Widget。
再定义一个类 Widget 从 Ui_Widget 继承而来，并定义在 namespace Ui 里，这样 Ui:: Widget 与 widget.h 里的类 Widget 同名，但是用 namespace 区分开来。
所以，界面的 Ui:: Widget 类与文件 widget.h 里定义的 Widget 类实际上是两个类，但是 Qt 的处理让用户感觉不到 Ui:: Widget 类的存在，只需要知道在 Widget 类里用 ui 指针可以访问可视化设计的界面组件就可以了。

自我理解：
窗体类，也就是主界面窗口。 是程序员通过自我定义实现的，可完全直接操控。
但主界面窗口上的组件，即是通过设计后，由工具自动来创建、设置的。工具通过一个 ui 指针来关联这些自动创建的组件，并暴露给程序员，从而使得程序员可以间接的操作各个组件。
	
## Qt项目中main主函数及其作用
http://c.biancheng.net/view/1821.html

**示例项目 samp2_1 。**

main() 函数是应用程序的入口。它的主要功能是创建应用程序，创建窗口，显示窗口，并运行应用程序，开始应用程序的消息循环和事件处理。

## Qt界面布局管理详解
http://c.biancheng.net/view/1822.html

讲解设计 GUI 的常见功能，包括界面设计时布局的管理，以及程序里如何访问界面组件。

### 实例程序功能

samp2_2

通过 Go to slot... 生成的槽函数都是在窗体类中进行声明定义。
（通过 UI 设计器中的Signals 和 Slots 编辑器似乎可以指定接收者？？？）

界面上各组件产生的交互信号，都联动到界面主体（窗体类），并触发窗体类中定义的相应的关联槽函数，槽函数内容由程序员自行编写，在其中可以通过 ui 指针访问各个组件，进行操作设置。

## Qt信号与槽机制详解
http://c.biancheng.net/view/1823.html






































