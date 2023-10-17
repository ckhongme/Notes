```
// 创建一个图形上下文 
osg::ref_ptr<osg::GraphicsContext> graphicsContext = osg::GraphicsContext::createGraphicsContext(); 
// 获取图形上下文的渲染状态 
osg::ref_ptr<osg::GraphicsContextState> contextState = graphicsContext->getState();
```

启用uniform：允许渲染管道中的模型视图和投影矩阵被统一变量传递到着色器程序中
```
camera->getGraphicsContext()->getState()->setUseModelViewAndProjectionUniforms(true);
```

允许在渲染管道中对顶点属性使用别名
```
camera->getGraphicsContext()->getState()->setUseVertexAttributeAliasing(true);
```
