#图形/Shader
***
### 什么是 着色器语言？
Shading Language，用于编写着色器代码；

### 着色器语言分类
[[GLSL]]
[[HLSL & Cg]]
基于Cg的[[Shaderlab]]

### 内置变量
自动向着色器传递，不需要重新定义，在着色器中可以直接使用的变量；
1. 输入的顶点属性；
2. 输出的顶点属性；
3. 计算矩阵（MVP）;

[[glsl内置变量]]
[[osg内置变量]]
[[unity内置变量（语义）]]

### 应用场景
在Windows下的图形接口是 DirectX，DirectX使用 HLSL 编写shader；
在Linux下的图形接口是 OpenGL，OpenGL使用 GLSL 编写shader；
NVIDIA和微软合作提供的 Cg，语法跟HLSL非常相像，可以无缝移植成HLSL代码，DirectX和OpenGL都支持；

