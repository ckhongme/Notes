未来代替OpenGL的新一代[[图形API]]的规范；(次世代OpenGL行动)
跨平台、高性能；
没有专门的着色器语言，可以使用[[GLSL]]，然后编译成[[SPIR-V]]作为assets使用；

是桌面的[[OpenGL]]和移动平台的[[OpenGL ES]]的统一;
***
### 性能提升
Vulkan提升的是驱动的性能（运行速度）；
让显卡驱动做更少的事情，以实现更低的开销，更快的性能，更少的延迟；
- [[显式控制(Vulkan)]]
- [[多线程渲染(Vulkan)]]
能在更少的CPU时间内推送更多的命令到GPU；

适用于[[渲染]]流程导致的性能问题，在GPU的使用上和OpenGL没有质的差距；
如果应用的性能瓶颈在于GPU，[[GPU Load]]很重，把OpenGL换成Vulkan也未必有多大的提升；

如果有离屏渲染的需求，Vulkan也可以胜任；
***
[[Vulkan开发]]

凡是支持OpenGL ES 3.1/4.x的都可以支持，而在操作系统方面，它支持Android(版本待定)、Windows XP/7/8/10、SteamOS、Ubuntu、Red Hat、Tizen等等，但是不支持iOS、OS X

2018年3月，Khronos发布Vulkan1.1




