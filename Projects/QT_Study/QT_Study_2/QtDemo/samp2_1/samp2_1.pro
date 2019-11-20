#-------------------------------------------------
#
# Project created by QtCreator 2019-11-18T15:12:09
#
#-------------------------------------------------

# 项目管理文件用于记录项目的一些设置，以及项目包含文件的组织管理。文件名就是项目的名称，如本项目中的 samp2_1.pro。


# 表示项目中加入 core gui 模块。 core gui 是 Qt 用于 GUI 设计的类库模块。
# Qt 类库以模块的形式组织各种功能的类，根据项目涉及的功能需求，在项目中添加适当的类库模块支持。
QT       += core gui

# 这是个条件语句，表示当 Qt 主版本大于 4 时，才加入 widgets 模块。
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 表示生成的目标可执行文件的名称，即编译后生成的可执行文件是 samp2_1.exe。
TARGET = samp2_1
# 表示项目使用的模板是 app，是一般的应用程序。
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Qt 官方在编译 Qt5 库的时候都是开启 C++11 特性的
CONFIG += c++11

# 后面的 SOURCES、HEADERS、FORMS 记录了项目中包含的源程序文件、头文件和窗体文件（.ui 文件）的名称。
# 这些文件列表是 Qt Creator 自动添加到项目管理文件里面的，用户不需要手动修改。当添加一个文件到项目，或从项目里删除一个文件时，项目管理文件里的条目会自动修改。
SOURCES += \
        main.cpp \
        widget.cpp

HEADERS += \
        widget.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
