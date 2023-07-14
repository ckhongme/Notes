### 什么是PBR？
全称 Physicallly-Based-Rendering，基于物理的渲染；
是现代写实渲染的基本；
通过“金属度”实现了塑料像塑料，金属像金属；
通过“金属度值”整合了2个shader（1个非金属，一个金属）；

### PBR模型相关的纹理
[[Albedo Map]]（存放着金属的反射颜色和非金属的漫反射颜色）
[[Normal Map]]
[[Metallic Map]]
[[Roughness Map]]
[[AO Map]]

### PBR光照相关的纹理
[[Cubic Map]]

### PBR的条件
条件1：[[微平面模型]]
条件2：[[光的能量守恒]]
条件3：[[双向反射分布函数BRDF]]

### 渲染方程
[[反射率方程]]


### 处理光照


***
PBR要求所有的输入都是线性的；
PBR渲染管线非常重要的两点：
1. 在[[Linear]]空间中计算光照
2. [[HDR]]图像






