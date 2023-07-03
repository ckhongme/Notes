#图形/Shader/GLSL 
***
主要使用的shader语言是[[GLSL]]；
主要在[[片元着色器]]实现效果，完成像素坐标到颜色的变换；
计算屏幕分辨率区域内的所有像素；
***
### ShaderToy的基础
网站：[ShaderToy](https://www.shadertoy.com/)

##### 主函数：mainImage
当前窗口的每个像素坐标都要经过这个主函数的处理以决定其颜色；
输入的是像素的坐标向量，输出的是像素的颜色向量；
```glsl
void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
	// Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;
    // Time varying pixel color
    vec3 col = 0.5 + 0.5*cos(iTime + uv.xyx+vec3(0,2,4));
    // Output to screen
    fragColor = vec4(col,1.0);
}
```
---
### ShaderToy的开发
##### 常见bug
- float类型的数值没有加**小数点**；
- 三角函数计算时，**弧度值和角度值**的换算问题；
- 找不到函数：看传入的**参数类型**是否正确；

***
##### VsCode的插件：ShaderToy
打开shader文件后，右键 → Shader Toy : Show GLSL Preview，可以进行实时效果预览；

