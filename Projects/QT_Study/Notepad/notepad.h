#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>


// 编译时 User Interface Compiler (uic) 将 .ui 编译为相应的 C++ 头文件。
// Ui 名称空间是 QT 的一个标准名称空间，.ui 生成的类都位于其中。
// Ui namespace, which is the standard namespace for the UI classes generated from .ui files by the uic tool:
namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    // Q_OBJECT 宏必须是类定义的第一句，声明该类是一个 QObject 。 QObject 描述了许多基础功能特性。
    // Q_OBJECT macro. It must come first in the class definition, and declares our class as a QObject. A QObject adds several abilities to a normal C++ class.
    // Notably, the class name and slot names can be queried at run-time. It is also possible to query a slot's parameter types and invoke it.
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

private slots:
    void on_quitButton_clicked();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
