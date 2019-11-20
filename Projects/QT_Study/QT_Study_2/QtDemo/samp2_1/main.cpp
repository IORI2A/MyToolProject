#include "widget.h"
#include <QApplication>

// main() 函数是应用程序的入口。它的主要功能是创建应用程序，创建窗口，显示窗口，并运行应用程序，开始应用程序的消息循环和事件处理。
int main(int argc, char *argv[])
{
    // QApplication 是 Qt 的标准应用程序类
    // 定义并创建应用程序对象
    QApplication a(argc, argv);
    // 定义并创建窗口
    Widget w;
    // 显示窗口
    w.show();

    // 启动应用程序的执行，开始应用程序的消息循环和事件处理。
    return a.exec();
}
