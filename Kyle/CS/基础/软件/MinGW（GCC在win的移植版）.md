#计算机软件
***
GCC是Unix-like系统的编译器，windows下主要使用GCC的稳定移植版：
1.  MinGW：让GCC的移植版能够使用Win32API来编程；
2.  Cygwin：让 Unix-like 的程序代码能在 windows下被直接编译；

目前的主流是MinGW系列；

### **安装**

1.下载MinGW：到MinGW主页的下载页面 [](https://osdn.net/projects/mingw/releases/)[https://osdn.net/projects/mingw/releases/](https://osdn.net/projects/mingw/releases/) 下载  Download mingw-get-setup.exe 文件；

2.安装MinGW到指定目录；

3.修改环境变量：计算机 -> 属性 -> 高级系统设置 -> 环境变量 -> 选中系统变量的Path -> 编辑 -> 新建（输入MinGW的安装目录下 bin 的路径，例如 D:\Soft\MinGW\bin）

4.win +R 打开运行窗口，输入cmd打开命令行，输入mingw-get，弹出 MinGw installation manager 窗口，说明安装正常。

5.在cmd窗口安装GCC
mingw-get install gcc

6.查看gcc安装结果（看到版本号证明安装成功）
gcc -v

7.如果要安装 g++,gdb
mingw-get install g++
mingw-get install gdb