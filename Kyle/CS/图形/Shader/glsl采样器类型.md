### 采样器类型
glsl中一个供纹理对象使用的内建数据类型，以纹理类型作为后缀；
例如 sampler1D，sampler2D，sampler3D
```glsl
uniform sampler2D tex1;
uniform sampler2D tex2;
```

### texture函数：采样颜色
使用之前设置的纹理参数对相应的颜色值进行采样；
```cpp
texture(ourTexture, TexCoord);
/*
参数1：纹理采样器
参数2：对应的纹理坐标
*/
```

