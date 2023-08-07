gl_作为GLSL的保留前缀只能用于内部变量；
### 输入的顶点属性
##### gl_Normal
vec3类型，顶点的法线；
### 输出的顶点属性
##### gl_Position
裁剪空间中的顶点位置；
vec4类型，它设置的值会成为顶点着色器的输出；
当顶点被赋值到这个变量后，OpenGL将会自动进行透视除法和裁剪；
### 计算矩阵
模型矩阵
观察矩阵
模型+观察矩阵 gl_ModelViewMatrix
投影矩阵 gl_ProjectionMatrix
***
glsl 140版本之前的内置变量
```
顶点的纹理坐标（第n个）     vec4 gl_MultiTexCoordn
顶点的颜色                vec4 gl_Color
模型空间中的顶点位置       vec4 gl_Vector
MVP矩阵                  mat4 gl_ModelViewProjectionMatrix
```
