#include "dialog.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    // 全局上定义的宏。用于在程序调测输出窗口输出内容。
    // 在 windows 系统中，默认情况下，如果是控制台程序，直接输出到窗口；如果是其他程序，输出到调试器窗口。
    // 如果包含有头文件 <QDebug> ，则可以便利的使用输出操作符来输出。
    qDebug() << "Dialog to show.";

    return a.exec();
}
