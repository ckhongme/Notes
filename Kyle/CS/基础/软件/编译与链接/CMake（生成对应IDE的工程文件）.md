#计算机软件 
***
### **为什么会有 CMake？**
根据开发用的IDE，每次都需要花时间从源码的 .c/.cpp 和 .h/.hpp 文件来建立对应的工程文件/解决方案；
为了帮开发者节省这个时间，所以有了CMake；

### 什么是工程 ？
工程用于管理源码，通过工程可以组织多个源代码文件和构建参数；

### 什么是 CMake？
全称 Cross Platform Make，是一个**工程文件生成工具**；
适合于C、C++或者java等编译语言的项目；
官网链接：[](https://cmake.org/download/)[https://cmake.org/download/](https://cmake.org/download/)

### CMake的使用
CMake需要一个**源代码目录**和一个存放编译结果的**目标文件目录**；
1.  在bin文件夹下找到 cmake-gui.exe；
2.  通过Configure（设置）按键，进行工程文件生成器的选择；（选择 VS的版本 和 系统的位数）
3.  最后点击 Generate 按键生成工程文件；

-   相关配置
    CMAKE_INSTALL_PREFIX：工程在执行install目标时，安装的路径前缀；


### CMakeLists.txt
CMake的所有操作都是在CMakeLists.txt里面完成的
```bash
# 增加子目录app
add_subdirectory(app);
```