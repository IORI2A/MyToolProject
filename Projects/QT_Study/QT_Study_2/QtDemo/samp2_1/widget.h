// 窗体类的头文件

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

// 声明了一个名称为 Ui 的命名空间（namespace），包含一个类 Widget。（前向声明）
// 但是这个类 Widget 并不是本文件里定义的类 Widget，而是 ui_widget.h 文件里定义的类，用于描述界面组件的。（ui_widget.h 由 widget.ui 在编译时自动生成，在编译目录下）
namespace Ui {
class Widget;
}

// 继承自 QWidget
class Widget : public QWidget
{
    // 宏 Q_OBJECT，这是使用 Qt 的信号与槽（signal 和 slot）机制的类都必须加入的一个宏。
    // 必须是定义中的第一个语句？
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // 这个指针是用前面声明的 namespace Ui 里的 Widget 类定义的，所以指针 ui 是指向可视化设计的界面，要访问界面上的组件，都需要通过这个指针 ui。
    Ui::Widget *ui;

    // 窗体类，也就是主界面窗口。 是程序员通过自我定义实现的，可完全直接操控。
    // 但主界面窗口上的组件，即是通过设计后，由工具自动来创建、设置的。工具通过一个 ui 指针来关联这些自动创建的组件，并暴露给程序员，从而使得程序员可以间接的操作各个组件。
};

#endif // WIDGET_H
