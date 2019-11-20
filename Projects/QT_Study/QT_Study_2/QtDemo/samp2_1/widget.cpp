// 窗体类的实现文件

// 窗体类，也就是主界面窗口。 程序员 基本可完全直接操控 窗体类。

#include "widget.h"
// 这个就是 Qt 编译生成的与 UI 文件 widget.ui 对应的类定义文件。
#include "ui_widget.h"

// 其意义是：执行父类 QWidget 的构造函数，new 创建一个 Ui::Widget 类的对象初始化指针 ui。
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    // Ui::Widget 类的 setupUi() 函数。这个函数实现窗口的生成与各种属性的设置、信号与槽的关联。
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
