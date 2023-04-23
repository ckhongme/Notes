#图形/Shader
全称OpenGL Shading Language（OpenGL着色器语言），是一门针对GPU的编程语言；

## 基础结构
```glsl
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
```glsl
#version 330 core     //330对应 OpenGL3.3, core表示使用的是核心模式
```
***
## 标识符
##### 输入和输出 in & out（对内）
定义变量是输入还是输出；
在着色器之间传输；
只要着色器的输出与下一个着色器的输入匹配（类型和名字都一样），OpenGL就会把两个变量链接到一起，它们之间就能发送数据；
<details><summary>GLSL版本130之前使用 varying 和 attribute</summary>
	<pre>
	变化 varying
	限定变量只能在Shader之间传递；
	是顶点着色器的输出，片元着色器的输入；
	需在2个着色器中同时声明，且保证类型，名称相同；
	在光栅化时，会跟着一起被光栅插值；
	</pre>
	<pre>
	属性 attribute
	只能在顶点着色器中使用；只读，且不能为array或struct；
	</pre>
</details>

##### 全局变量 uniform（对外）
从cpu向gpu发送数据的方式；
着色器只能访问，不能写入；通过 opengl的函数进行写入（[[uniform赋值#glUniformXX]]）；
***
## 数据类型
基础数据类型：int、float、double、uint 和 bool；
特殊数据类型：
1. [[glsl聚合类型（向量&矩阵）]]
2. [[glsl采样器类型]]

数组：
```glsl
float[3] array1;
float array1[3]
```






##### 元数据 location 和 标识 layout
为了定义顶点数据该如何管理，需要使用location指定输入变量，这样才可以在CPU上配置顶点属性；
顶点着色器需要为它的输入提供一个额外的layout标识，这样才能把它链接到顶点数据；
指定顶点属性对应哪个位置值，后面可以通过位置值来配置顶点属性；
```glsl
layout(location = 0) int vec3 mPos;    // 位置变量的属性位置值为 0， 也就是设定了输入变量的位置值(location)
layout(location = 1) int vec3 mColor;  // 颜色变量的属性位置值为 1
```