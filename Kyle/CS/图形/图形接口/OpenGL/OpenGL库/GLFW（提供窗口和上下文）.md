#图形/opengl 
***
### 什么是GLFW？
专门针对OpenGL的C语言库；
提供了渲染物体的基本接口：
-   创建OpenGL上下文
-   定义窗口参数
-   处理用户输入

##### 为什么会有GLFW？
帮助开发者简化绘制窗口等工作；
解决图像在哪里绘制的问题；

### 编译和链接GLFW库
[GLFW官方下载](https://www.glfw.org/)
有源代码包，也有预编译的二进制版本；
1.下载源代码包，编译生成glfw3.lib；
2.将生成的库文件链接到项目中；
***
### 应用
##### 引入头文件
```cpp
#include <glad/glad.h>       //如果也用到了glad，需要先引入glad
#include <GLFW/glfw3.h>
```
##### 初始化GLFW
```cpp
glfwInit();
```
[[用GLFW创建窗口]]


***
##### glfwTerminate 释放所有资源
在main函数的最后调用函数来正确释放/删除之前的分配的所有资源；

```cpp
glfwTerminate();
```

##### glfwGetTime 获取运行的秒数