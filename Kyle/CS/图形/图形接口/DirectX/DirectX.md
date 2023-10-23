全称 Direct eXtension（简称DX），微软旗下的一些列API的统称；
- [[D3D]]
- [[Direct2D]]
- [[DirectCompute]]
***
### 多线程渲染
##### DX9，DX10
封装了一层渲染状态，然后使用多线程收集指令，最后再用主线程去调用图形API；
因为图形API不支持多线程，CPU要等一帧渲染完了，才能执行下一帧的逻辑；
这个时期多线程渲染性能提升不大；
##### DX11
开始引入deferred context；
单线程和多线程的混合版本；
在硬件提供了"Driver Concurrent Creates"和"Driver Command Lists"这两个技术，就是驱动层支持在多线程中创建资源以及在多线程中提交指令(deferred context直接向驱动层提交指令)；
##### DX12
不同的线程可以往不同的Command List中提交指令；
最大的改善是CPU不会被阻塞了；