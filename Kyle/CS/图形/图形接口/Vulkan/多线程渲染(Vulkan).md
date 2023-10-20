对CPU多线程的支持；
在OpenGL中，所有的渲染操作都放在一个线程，其他空闲状态的线程只能围观；
[[Vulkan]]中引入了[[Command Buffer]]的概念，每个线程都可以往`Command Buffer` 提交渲染命令，给开发者提供了充分发挥CPU多核[[多线程]]的优势；





