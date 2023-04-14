#图形/Shader
全称OpenGL Shading Language（OpenGL着色器语言），是一门针对GPU的编程语言；

### 基础结构
```c#
#version 版本号 模式          //版本声明
in 数据类型 输入变量名         //定义输入变量 
out 数据类型 输出变量名        //定义输出变量 
uniform 数据类型 全局变量名    //定义全局变量 

void main                    //main函数：所有着色器的入口点 
{
	//处理输入，转化成输出 
}
```

##### 版本声明
每个着色器都起始于一个版本声明；
GLSL版本号和OpenGL的版本是匹配的；
```C#
#version 330 core     //330对应 OpenGL3.3, core表示使用的是核心模式
```

### 标识符
##### 输入和输出 in & out（对内）
定义变量是输入还是输出；
在着色器之间传输；
只要着色器的输出与下一个着色器的输入匹配（类型和名字都一样），OpenGL就会把两个变量链接到一起，它们之间就能发送数据；

##### 全局变量 uniform（对外）
从cpu向gpu发送数据的方式；
着色器只能访问，不能写入；通过 opengl的函数进行写入（[[uniform赋值#glUniformXX]]）；



GLSL