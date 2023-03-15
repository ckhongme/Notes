在main函数中实例化GLFW窗口：
1.  初始化GLFW；
2.  配置GLFW；
3.  创建窗口；

### 配置GLFW：glfwWindowHint
```cpp
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
```
第一个参数：选项的枚举值；（[Window hint 所有枚举值](https://www.glfw.org/docs/latest/window.html#window_hints)）
第二个参数：整形数值，用来设置这个选项的值；


### 创建窗口对象：glfwCreateWindow
同时会创建一个上下文；
一般在创建窗口的同时，会创建一个绘制上下文；
```cpp
GLFWwindow* window = glfwCreateWindow(width, height, "XXX", NULL, NULL);
```
前2个参数：长和宽
第3个参数：名字

### 设置为当前上下文：glfwMakeContextCurrent
创建窗口后，需要将对应的上下文设置为当前的上下文；
```cpp
glfwMakeContextCurrent(window);
```


***
### 判断窗口是否已经退出：glfwWindowShouldClose
用于进行**渲染循环**的判断；
所有的渲染操作都会放到渲染循环中；
可以在每次循环的开始前检查一次GLFW是否被要求退出；
```cpp
//在while中进行渲染循环
while(!glfwWindowShouldClose(window))
{
		//TODO...
}
```

### glfwSetWindowShouldClose 关闭窗口
设置为 true，则窗口关闭，程序退出；
```cpp
glfwSetWindowShouldClose(window, true);
```