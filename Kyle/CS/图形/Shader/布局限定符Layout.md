### layout（location = x）
指定输入输出变量的属性位置值；
##### 顶点着色器
使用location指定变量的位置索引后，**可以通过索引值来配置指定的[[顶点属性]]**；
```glsl
layout(location = 0) in vec3 mPos;    // 位置变量的属性位置值为 0， 也就是设定了输入变量的位置值(location)
layout(location = 1) in vec3 mColor;  // 颜色变量的属性位置值为 1
```

占用多个位置时：（结构体 & 数组）
```glsl
layout(location = 2) in vec3 values[4];  // values将按顺序依次获取属性位置2，3，4，5处的值
```
输入和输出变量的位置索引互不影响
```glsl
layout(location = 0) in vec3 mPos; 
layout(location = 0) out vec4 mColor; 
```
##### 变量传递
顶点着色器的输出
```glsl
layout(location = 0) out vec3 normal; 
```
片元着色器的输入
```glsl
layout(location = 0) in vec3 cameraSpaceNormal;    //变量名可以不同
```




