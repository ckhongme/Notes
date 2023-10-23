### 初始化Shader
1. 创建着色器对象；（附加源码，编译着色器）
2. 创建[[着色器程序]]对象；（添加着色器，链接着色器）
3. 删除着色器对象；
***
### 调用Shader
1. 在[[渲染循环]]中激活着色器程序对象
2. 给[[uniform]]赋值；
***
### 相关的opengl函数

##### 着色器对象
- 创建对象：[[opengl-core#glCreateShader]]
- 附加源码：[[opengl-core#glShaderSource]]
- 编译着色器：[[opengl-core#glCompileShader]]
- 判断编译是否成功：[[opengl-core#glGetShaderiv]]
- 删除着色器对象：[[opengl-core#glDeleteShader]]
##### 着色器程序对象
- 创建程序：[[opengl-core#glCreateProgram]]
- 附加并链接：[[opengl-core#glAttachShader & glLinkProgram]]
- 判断链接是否成功：[[opengl-core#glGetProgramiv]]
- 激活程序对象：[[opengl-core#glUseProgram]]
- 删除程序：[[opengl-core#glDeleteProgram]]

视口变换：[[opengl-core#glViewPort]]
