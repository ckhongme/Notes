从Vulkan程序工作流程看，步骤如下
1. 创建窗口
2. 实例化Vulkan Instance - 一个程序可以有多个
3. 创建 Surface
4. 查找物理驱动
5. 查找逻辑驱动
6. 创建管线缓存
7. 生成swap chain
8. 创建image view
9. 生成render pass
10. Frame Buffers
11. Command Pool
12. Command Buffer
13. 创建同步对象
14. 创建管线


渲染过程中的流程是
1. 重新创建管线 - 条件执行
2. 同步Fence - vkWaitForFences
3. 获取交换链图像 - vkAcquireNextImageKHR
4. resetFence inFlightFences - 如何翻译?
5. 提交command - vkQueueSubmit
6. vkQueuePresentKHR -请求当前图像
7. 更新当前帧索引