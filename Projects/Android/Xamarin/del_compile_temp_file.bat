REM 构建一个命令行脚本 删除不需要归档的文件。

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
rd /S /Q .\Xamarin_Android___Phoneword\.vs
rd /S /Q .\Xamarin_Android___Phoneword\Phoneword\Assets
rd /S /Q .\Xamarin_Android___Phoneword\Phoneword\bin
rd /S /Q .\Xamarin_Android___Phoneword\Phoneword\obj
del /S *.user
del /S *.designer.cs

