#include "dialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , serialPortLabel(new QLabel(tr("Serial port:")))
    , serialPortComboBox(new QComboBox())
    , waitResponseLabel(new QLabel(tr("Wait response, msec:")))
    , waitResponseSpinBox(new QSpinBox())
    , requestLabel(new QLabel(tr("Request:")))
    , requestLineEdit(new QLineEdit(tr("Who are you?")))
    , trafficLabel(new QLabel(tr("No traffic.")))
    , statusLabel(new QLabel(tr("Status: Not running.")))
    , runButton(new QPushButton(tr("Start")))
{
    //    const auto infos = QSerialPortInfo::availablePorts();
    //    for (const QSerialPortInfo &info : infos)
    //        serialPortComboBox->addItem(info.portName());

    //    waitResponseSpinBox->setRange(0, 10000);
    //    waitResponseSpinBox->setValue(1000);

        // 直接使用代码来布局。
        // MFC 中一般是使用坐标值通过指定控件位置的函数方法来布局。
        // QT 中提供了更加多的布局方式，如下:
        // 以单元格(grid)的方式布局。
        auto mainLayout = new QGridLayout;
        mainLayout->addWidget(serialPortLabel, 0, 0);
        mainLayout->addWidget(serialPortComboBox, 0, 1);
        mainLayout->addWidget(waitResponseLabel, 1, 0);
        mainLayout->addWidget(waitResponseSpinBox, 1, 1);
        // 指定一个控件占多个单元格。相当于 OFFICE 中的合并单元格。
        mainLayout->addWidget(runButton, 0, 2, 2, 1);
        mainLayout->addWidget(requestLabel, 2, 0);
        mainLayout->addWidget(requestLineEdit, 2, 1, 1, 3);
        mainLayout->addWidget(trafficLabel, 3, 0, 1, 4);
        mainLayout->addWidget(statusLabel, 4, 0, 1, 5);
        setLayout(mainLayout);

        setWindowTitle(tr("Blocking Master"));
        serialPortComboBox->setFocus();

    //    connect(runButton, &QPushButton::clicked, this, &Dialog::transaction);
    //    connect(&thread, &MasterThread::response, this, &Dialog::showResponse);
    //    connect(&thread, &MasterThread::error, this, &Dialog::processError);
    //    connect(&thread, &MasterThread::timeout, this, &Dialog::processTimeout);
}

Dialog::~Dialog()
{

}
