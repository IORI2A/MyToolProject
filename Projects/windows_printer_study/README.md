# 学习了解WINDWOS实现调用打印机进行打印的工程。


**2020-01-17 P1**
1. 新建一个 vs2008 对话框程序 SimplePrint 进行学习开发、调测。
- 增加按钮触发打印动作。
- WIN32 方式，通过使用 PRINTDLG 和 PrintDlg 显示打印对话框。
  + MSDN: 
    - Win32 and COM Development
    - User Interface
    - Windows User Experience
    - Windwos Management
    - Windows User Interface
    - User Input
    - Common Dialog Box Library
    - Common Dialog Box Library Overviews
    - Using Common Dialog Boxes 
- 获取默认打印机名称 GetDefaultPrinter 。 
- MSDN: 
  + Win32 and COM Development
  + Graphics and Multimedia
  + GDI
  + Windwos GDI
  + Printing and Print Spooler
  + About Printing
  + Printer Output 
    - 通过打印机名称获取打印机句柄 HANDLE 。
    - 通过 GetPrinter 和 打印机句柄 HANDLE ，获取打印机的驱动和端口信息。
    - 不使用界面交互（打印对话框）。 想实现后台隐藏打印。 使用 CreateDC 来创建打印机的 DC 。







    