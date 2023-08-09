gl_作为GLSL的保留前缀只能用于内部变量；


### [[顶点着色器]]的内置变量
##### 输入的顶点属性
- gl_Vertex：vec3类型，对象空间中顶点的位置；
- gl_Normal：vec3类型，顶点的法线；
- gl_Color：顶点的颜色；
- gl_MultiTexCoordx：x是数字，从0开始，表示输入多个[[纹理坐标UV]]；
##### 输出的顶点属性
- gl_Position：vec4类型，表示裁剪空间中的顶点位置，是顶点着色器的输出；
（当这个变量被赋值后，OpenGL将会自动进行[[透视除法]]和裁剪）
##### 计算矩阵
- gl_NormalMatrix：法线矩阵
- gl_ModelViewMatrix：模型+观察矩阵 
- gl_ModelViewProjectionMatrix：MVP矩阵
***
glsl 140版本之前的内置变量
```
顶点的纹理坐标（第n个）     vec4 gl_MultiTexCoordn
顶点的颜色                vec4 gl_Color
模型空间中的顶点位置       vec4 gl_Vector
MVP矩阵                  mat4 gl_ModelViewProjectionMatrix
```
