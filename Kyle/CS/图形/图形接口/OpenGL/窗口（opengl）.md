### 设置视口 glViewport
告诉opengl[[视口]]的尺寸大小；
opengl的视口原点在左下角；（[[坐标系#屏幕坐标系]]）
```cpp
glViewport(0,0,width,height); 
//前两个参数：视口左下角的位置； 
//后两个参数：视口的宽和高；
```

##### [[用GLFW创建窗口]]