### [[深度测试]]
```cpp
glEnable(GL_DEPTH_TEST);          //开启深度测试
glDepthFunc(GLenum.GL_ALWAYS);    //设置深度测试的规则
...
glClear(GL_DEPTH_BUFFER_BIT);     //清除深度缓冲
```

##### 深度写入 glDepthMask
```cpp
glDepthMask(GL_TRUE);   //开启
glDepthMask(GL_FALSE);  //关闭
```

### [[模板测试]]
```csharp
glEnable(GL_STENCIL_TEST);   //开启模板测试
glStencilMask(GLuint mask);  //设置模板缓冲区的写入掩码（默认为0xff）
glClearStencil(GLint s);     //清除模板缓冲区的值（默认为0）
glStencilFunc(GLenum func, GLint ref, GLuint mask) //设置模板测试是否通过的规则
```