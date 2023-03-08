
在OpenGL或其他渲染API中，状态指定了一些渲染参数，例如材质、光照、深度测试和纹理等；
状态集（StateSet）则是一个包含一组状态的对象，它可以被应用于场景中的几何体上，从而影响其渲染；


##### getOrCreateStateSet
获取一个 StateSet 对象，如果该对象不存在，则创建一个新的 StateSet 对象并返回；
通常用于确保在渲染应用程序中使用的状态集是唯一的，并且可以在多个场景中共享使用；

##### setRenderingHint
设置渲染提示，以便优化场景的渲染效果；
渲染提示是一些参数，用于告诉OSG渲染引擎如何处理场景图中的几何体；

```cpp
//启用多边形平滑和多边形偏移
geode->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
```

TRANSPARENT_BIN是一个常量，表示将几何体添加到透明渲染队列中，以便正确地进行混合