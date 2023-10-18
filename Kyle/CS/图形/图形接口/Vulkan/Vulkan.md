未来代替OpenGL的新一代[[图形API]]的规范；(次世代OpenGL行动)
跨平台、高性能；
没有专门的着色器语言，可以使用[[GLSL]]，然后编译成.spv字节码作为assets使用；

是桌面的OpenGL和移动平台的[[OpenGL ES]]的统一;
***
### 减少了对[[驱动]]的依耐性
需要开发者在程序方面做以往驱动做的事情，因此Vulkan的代码量会比传统的图形API多很多，学习起来也相对的困难一点；

每一个细节都需要从头设置，包括初始帧缓冲区的创建与缓存，纹理内存的管理等；一个不小心就会导致crash或者花屏；

API验证、内存管理、多线程管理等工作都交由开发者负责；
增加了API使用的复杂度和困难度，但换来的是性能上巨大的提升。单单是在驱动中去掉API验证操作，就把性能提升了9倍；
![[Vulkan的对比.png]]
### 对CPU多线程的支持
在OpenGL中，所有的渲染操作都放在一个线程，其他空闲状态的线程只能围观；
Vulkan中引入了 `Command Buffer` 的概念，每个线程都可以往`Command Buffer` 提交渲染命令，给开发者提供了充分发挥CPU多核多线程的优势；

***
Vulkan提升的是驱动的性能，改变的是渲染实现方式，适用于[[渲染]]流程导致的性能问题；

Vulkan和OpenGL在GPU的使用上没有质的差距。如果你应用的性能瓶颈在于GPU，GPU loading很重，把OpenGL换成Vulkan也未必有多大的提升；

如果有离屏渲染的需求，Vulkan也可以胜任；



凡是支持OpenGL ES 3.1/4.x的都可以支持，而在操作系统方面，它支持Android(版本待定)、Windows XP/7/8/10、SteamOS、Ubuntu、Red Hat、Tizen等等，但是不支持iOS、OS X

2018年3月，Khronos发布Vulkan1.1




