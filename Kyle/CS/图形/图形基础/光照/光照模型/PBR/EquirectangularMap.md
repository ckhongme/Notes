等距柱状投影图；
图像非常扭曲，因为是从球体投影到平面上；

***
转换为[[CubeMap]]进行采样，性能更好；
### 转换过程
需要渲染一个（单位）立方体，从内部将等距柱状图投影到立方体的每个面，并将立方体的六个面的图像构造成立方体贴图；

此立方体的**顶点着色器**：
按原样渲染立方体，并将其局部坐标作为3D采样向量传递给片段着色器
```
#version 330 core 
layout (location = 0) in vec3 aPos; 
out vec3 localPos; 

uniform mat4 projection; 
uniform mat4 view; 

void main() 
{ 
	localPos = aPos; 
	gl_Position = projection * view * vec4(localPos, 1.0); 
}
```

此立方体的**片元着色器**：
为立方体的每个部分着色；
从立方体的局部坐标进行插值获取片段的采样方向，然后对等距柱状投影图进行采样，再将结果存储到立方体每个面的片段中；
```
#version 330 core 
out vec4 FragColor; 
in vec3 localPos; 

uniform sampler2D equirectangularMap; 

const vec2 invAtan = vec2(0.1591, 0.3183); 
vec2 SampleSphericalMap(vec3 v) 
{
	vec2 uv = vec2(atan(v.z, v.x), asin(v.y)); 
	uv *= invAtan; 
	uv += 0.5; 
	return uv; 
} 

void main() 
{ 
	vec2 uv = SampleSphericalMap(normalize(localPos));
	vec3 color = texture(equirectangularMap, uv).rgb; 
	FragColor = vec4(color, 1.0); 
}
```

要将HDR图像转换为立方体贴图纹理，必须对立方体渲染六次，每次面对立方体的一个面，并用[[帧缓冲对象FBO]]记录其结果；

具体过程：面向立方体六个面设置六个不同的视图矩阵，给定投影矩阵的 fov 为 90 度以捕捉整个面，并渲染立方体六次，将结果存储在浮点帧缓冲中