#include "notepad.h"
#include <QApplication>


// 程序入口
// the main function that is the entry point for all C and C++ based applications
int main(int argc, char *argv[])
{
    // QApplication 管理程序资源，是运行使用 Qt Widgets 程序必须的。
    // QApplication object manages application-wide resources and is necessary to run any Qt program that uses Qt Widgets.
    QApplication a(argc, argv);
    Notepad w;
    w.show();

    // 运行程序，进入事件（消息）循环。
    // makes the QApplication enter its event loop.
    return a.exec();

    // When a Qt application is running, events are generated and sent to the widgets of the application. Examples of events are mouse presses and key strokes.
}
