REM 构建一个命令行脚本 删除不需要归档的文件。

REM @echo Off

REM del /?
REM 删除一个或多个文件。
REM 
REM DEL [/P] [/F] [/S] [/Q] [/A[[:]attributes]] names
REM ERASE [/P] [/F] [/S] [/Q] [/A[[:]attributes]] names
REM 
REM   names         指定一个或多个文件或者目录列表。
REM                 通配符可用来删除多个文件。
REM                 如果指定了一个目录，该目录中的所
REM                 有文件都会被删除。
REM 
REM   /P            删除每一个文件之前提示确认。
REM   /F            强制删除只读文件。
REM   /S            删除所有子目录中的指定的文件。
REM   /Q            安静模式。删除全局通配符时，不要求确认
REM   /A            根据属性选择要删除的文件
REM   属性          R  只读文件            S  系统文件
REM                 H  隐藏文件            A  准备存档的文件
REM                 I  无内容索引文件      L  重新分析点
REM                 O  脱机文件            -  表示“否”的前缀
REM 
REM 如果命令扩展被启用，DEL 和 ERASE 更改如下:
REM 
REM /S 开关的显示句法会颠倒，即只显示已经
REM 删除的文件，而不显示找不到的文件。


REM del /S /A:H .vs
REM rd /S /Q .\Xamarin_Android___Phoneword\.vs
REM rd /S /Q .\Xamarin_Android___Phoneword\Phoneword\Assets
REM rd /S /Q .\Xamarin_Android___Phoneword\Phoneword\bin
REM rd /S /Q .\Xamarin_Android___Phoneword\Phoneword\obj
REM del /S *.user
REM del /S *.designer.cs




REM **搜索： bat 清理工程项目**
REM - [如何用.bat文件清理工程目录](http://www.voidcn.com/article/p-moxwkywz-vo.html)
REM   + **搜索： bat for**
REM     - [bat(续七)-for语句(循环结构)](https://www.cnblogs.com/lm002003/archive/2012/05/15/2502439.html)


REM 注：
REM del 命令的 /s  参数删除所有子目录中的指定的文件。 
REM FOR /R . %%d IN (.) DO rd /s /q "%%d\Debug"  删除所有文件夹名称为Debug的文件夹 
REM 2>nul 不输出错误提示信息

REM del /s /a *.exe *.suo *.ncb *.user *.pdb *.netmodule *.aps *.ilk *.sdf 2>nul
REM FOR /R . %%d IN (.) DO rd /s /q "%%d\Debug" 2>nul
REM FOR /R . %%d IN (.) DO rd /s /q "%%d\Release" 2>nul

rem 如果Properties文件夹为空，则删除它
rem FOR /R . %%d in (.) do rd /q "%%d\Properties" 2> nul



FOR /R . %%d IN (.) DO rd /s /q "%%d\Debug"
FOR /R . %%d IN (.) DO rd /s /q "%%d\Release" 
FOR /R . %%d IN (.) DO rd /s /q "%%d\ipch" 
REM FOR /R . %%d IN (.) DO rd /s /q "%%d\.svn" 
FOR /R . %%d IN (.) DO rd /s /q "%%d\_UpgradeReport_Files" 

DEL /S /A /Q *.suo
DEL /S /A /Q *.sdf
DEL /S /A /Q *.opensdf
DEL /S /A /Q *.old
DEL /S /A /Q *.sbr
DEL /S /A /Q *.htm
DEL /S /A /Q *.html
DEL /S /A /Q *.aps
DEL /S /A /Q *.user
DEL /S /A /Q *.exe
DEL /S /A /Q *.clw
DEL /S /A /Q *.opt
DEL /S /A /Q *.plg
DEL /S /A /Q *.dsw
REM DEL /S /A /Q *.sln
DEL /S /A /Q *.ncb
DEL /S /A /Q *.log

DEL /S /A /Q UpgradeLog*.XML

DEL /S /A /Q *.DLL.manifest
DEL /S /A /Q *.pdb
DEL /S /A /Q *.DLL

DEL /S /A /Q *.lib

REM 删除生成的中间结果和最终结果。
FOR /R . %%d IN (.) DO rd /s /q "%%d\obj"
FOR /R . %%d IN (.) DO rd /s /q "%%d\bin"
FOR /R . %%d IN (.) DO rd /s /q "%%d\.vs"


REM 删除以下的文件， VS 2017 仍可以正常编译运行。
REM DEL /S /A /Q .clang-format
REM DEL /S /A /Q .editorconfig
REM DEL /S /A /Q .gitmodules
REM DEL /S /A /Q *.yml
REM DEL /S /A /Q *.build*



REM pause


