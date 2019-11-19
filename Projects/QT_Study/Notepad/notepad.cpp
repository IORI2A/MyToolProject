#include "notepad.h"
#include "ui_notepad.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>


Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::on_quitButton_clicked()
{
    // 调用程序的退出方法。
    // to have the quit() slot of QApplication exit Notepad
    QCoreApplication::quit();
}

void Notepad::on_actionOpen_triggered()
{
    // 多语言支持
    // the function tr() around strings. to provide your application in more than one language (for example, English and Chinese).
    // Qt Linguist

    // 使用文件对话框提示用户选择文件。
    // QFileDialog, which is a dialog from which the user can select a file.
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void Notepad::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
            tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}
