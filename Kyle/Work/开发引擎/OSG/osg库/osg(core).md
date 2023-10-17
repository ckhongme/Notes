是[[OSG#核心库]]之一，包含了构建和管理3D场景的基本类和功能；
***
[[智能指针 ref_prt]]
[[观察指针 observer_ptr]]

### 基础
[[osg-Referenced]]
[[osg-Object]]：osg的基类

### 节点
[[osg-Node]]：基础节点
[[osg-Group]]：可以包含多个子节点
[[osg-Geode]]：可渲染的几何体节点
[[osg-Transform]]

### 绘制类
[[osg-Drawable]]：绘制对象的基类（纯虚类）
[[osg-Geometry]]：几何体类
[[osg-ShapeDrawable]]：预定义几何体类

### 渲染相关
[[osg-StateSet]]：状态集
[[osg-StateAttribute]]：渲染状态属性的抽象基类
[[osg-Texture]]：纹理属性
[[osg-Material]]：材质属性
[[osg-Light]]：光照属性
[[osg-Uniform]]：着色器中的uniform变量
[[osg-GraphicsContext]]：图形上下文

### 函数
```cpp
osg::DegreesToRadians(45.0)； //角度转弧度
```
### 调试
设置日志输出级别为调试信息级别
```cpp
osg::setNotifyLevel(osg::DEBUG_INFO);
```











