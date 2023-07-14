全称Bidirectional Reflectance Distribution Function；

### 作用
基于表面材质属性计算光线的反射程度占比
可以近似的求出每束光线对一个给定了材质属性的平面上最终反射出来的光线所作出的贡献程度；

基于表面材质属性来对入射[[辐射率]]进行缩放或者加权；

***
### Cook-Torrance BRDF
其中一种BRDF模拟表面光照的算法，主要在**实时渲染**管线中使用；

漫反射BRDF由一个恒定算式组成：
- 伦勃朗漫反射（Lambertian Diffuse）
    $𝑓lambert=c/π$，c表示表面颜色；

镜面反射BRDF由3个函数（𝐷，𝐹，𝐺）和一个标准化因子构成：

- 法线分布函数 D（NDF）
    全称**Normal Distribution Function，**基于粗糙度用来估算微平面的主要函数；
    在反射率方程中用大写的D表示；
    $NDF(n,h,a) = a^2/π((n*h)^2(a^2-1)+1)^2$
    
- 菲涅尔函数F
    全称**Fresnel equation，**计算表面反射和折射的比值，表示物体表面光线被反射的百分比；
    菲涅尔现象：不同角度有不同强度的反射光
    
- 几何函数G
    **Geometry function，**描述了微平面自成阴影的属性；