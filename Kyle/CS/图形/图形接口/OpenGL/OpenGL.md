#图形/opengl  
***
### 什么是OpenGL？
全称Open Graphics Library，一个包含图形API的规范；只是个**绘图的工具**，用来绘制2D或3D图形；
跨平台，使用最为广泛的图形接口的规范；
使用的Shader语言是[[GLSL]]；
[OpenGL官网](https://opengl.org/)
### OpenGL的作用
应用程序发送命令给OpenGL，然后OpenGL再将命令发送给底层的图形硬件来绘制出预期的图形效果；
在应用程序和底层的图形系统之间提供一个抽象层；
### 工作机制
本质上就是 [[状态机]]，用一系列的状态变量来描述OpenGL此刻应当如何运行；
状态变量设置后就会一直生效，直至再次修改；
##### 上下文 Context
保存了OpenGL各种状态的状态机；
在调用OpenGL的指令前，需要先创建一个OpenGL的上下文；（执行指令的基础）
一个上下文对应一个窗口（同时创建），当上下文被销毁时，窗口所对应的OpenGL渲染工作也将结束；
上下文是相互独立的，有自己的OpenGL对象集，除了容器对象 FBO，VAO等，上下文之间可以共享其他对象集合；
***
### 工作流
[[窗口]]
[[渲染循环]]
[[存储对象]]
[[处理shader（opengl）]]
[[设置管线状态]]
***
[[OpenGL库]]
***
<details>
	<summary>OpenGL的起源</summary>
	<pre>
	1992年，SGI公司看到了<b>可移植性</b>的重要性，将自身拥有的专利性图形API修改成了一种开放标准；
	IRIS GL在跨平台移植过程中变成了OpenGL；
	因为有Quake这样顶级游戏的支持，OpenGL在90年代成为了无可争议的业界标准；
	</pre>
</details>
<details><summary>OpenGL的重要发展史</summary>
	<pre>
	2004年，推出的OpenGL2.0才开始支持高级Shader编程语言；
	2017年，Khronos推出了最新版的OpenGL 4.6；
	2018年，苹果宣布不再支持OpenGL，macOS官方支持的 OpenGL 最新版本只到4.1；
	</pre>
</details>

