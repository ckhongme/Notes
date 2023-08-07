### 什么是 OSG？
全称 open scene graph；一个开源的实时[[三维渲染引擎]]；
基于[[C++#标准模板库 STL]]，不依赖任何与操作系统有关的中间件，支持所有操作系统平台；

[[坐标系#世界坐标的朝向]]
空间参考系（Spatial Reference System，SRS）
### OSG的作用
由一系列图形学相关的功能模块组成，为图形图像应用程序的开发提供2个主要功能：场景管理 和 图形渲染优化；

#### 场景管理
将3D场景定义为空间中一系列连续的对象，使用逻辑组来构建[[场景树]]，以进行三维世界的管理；

#### 图形渲染优化
支持所有的[[OpenGL]]扩展；（OpenGL1.0~4.2以及OpenGL ES 1.1 ~2.0）
[[OSG图形]]
***
### OSG相关库
##### 核心库
[[osg(core)]]
[[osgDB]]
[[osgUtil]]

##### 节点扩展库
[[osgViewer]]：渲染器，窗口系统功能
[[osgGA]]：事件处理
[[osgParticle]]：粒子系统，用于模拟天气和自然现象（推荐使用Spark粒子系统）
[[osgText]]：文字处理与显示
[[osgFX]]：特效
[[osgShadow]]：阴影
[[osgSim]]：虚拟仿真效果
[[osgAnimation]]：动画
[[osgTerrain]]：地形渲染（针对地形，推荐使用VPB或osgEarth）
[[osgManipulator]]：对模型的局部操作器
[[osgVolume]]：音效

##### 节点扩展库（三维地形展示系统）
[[osgEarth]]：地球，地形
[[osgOcean]]：海洋仿真

