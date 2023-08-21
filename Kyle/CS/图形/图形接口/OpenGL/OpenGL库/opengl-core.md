[[OpenGL]]的核心库；
***
### glUniformXX
将uniform变量的值床底给着色器程序；
##### XX后缀表示数据的类型：
- glUniform1i：int类型
- glUniform1f：float类型
- glUniform2f：vec2类型
- glUniform3f：vec3类型
- glUniform4f：vec4类型
- glUniformMatrix2fv：mat2矩阵
- glUniformMatrix3fv：mat3矩阵
- glUniformMatrix4fv：mat4矩阵
##### 传入矩阵 glUniformMatrix4fv 
```cpp
unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
/*
参数1：uniform的位置值；
参数2：要发送的矩阵数量
参数3：是否置换矩阵（交换矩阵的行和列）
参数4：要传入的矩阵数据；
*/
```
* OpenGL使用的内部矩阵布局叫做列主序(Column-major Ordering)布局，而[[GLM（数学运算）]]的默认布局就是列主序，所以并不需要置换矩阵，填GL_FALSE；
###
***
### 着色器
##### glCreateShader
创建着色器对象；
```cpp
//需要用id来引用，如果是片元着色器，类型就是 GL_FRAGMENT_SHADER）
usigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);    
```
##### glShaderSource
附加源码：将着色器源码附加到着色器对象上；
```cpp
glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
/*
第一个参数：着色器对象；
第二个参数：源码字符串数量；
第三个参数：真正的源码
第四个参数：NULL*/
```
##### glCompileShader
编译着色器：要在OpenGL中使用着色器，就需要在运行时动态编译它的源码；
```cpp
glCompileShader(vertexShader);
```
##### glGetShaderiv
判断编译是否成功
```cpp
int  success;
char infoLog[512];
glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);  //检查是否编译成功
if(!success)
{
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);   //获取错误信息
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\\n" << infoLog << std::endl;
}
```
##### glDeleteShader 
删除着色器对象 
```cpp
glDeleteShader(vertexShader);
glDeleteShader(fragmentShader);
```
###
***
### 着色器程序
##### glCreateProgram 
创建程序：返回的是程序对象的ID引用；
```cpp
unsigned int shaderProgram;
shaderProgram = glCreateProgram();    //返回了新创建程序对象的ID引用
```
##### glAttachShader & glLinkProgram 
附加并链接：把着色器附加到了程序，并链接；
```cpp
//先把编译好的着色器附加到程序对象上；
glAttachShader(shaderProgram, vertexShader);  
glAttachShader(shaderProgram, fragmentShader);   
//程序对象着色器
glLinkProgram(shaderProgram);
```
##### glGetProgramiv 
判断链接是否成功
```cpp
glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);   //检查着色器是否成功链接到程序
if(!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);  //获取错误信息
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\\n" << infoLog << std::endl;
}
```
##### glUseProgram
激活程序对象
```cpp
glUseProgram(shaderProgram);
```
##### glDeleteProgram 
删除程序 
```cpp
glDeleteProgram(shaderProgram);
```
###
***
### 缓冲对象
##### glBindBuffer & glBufferData
绑定缓冲对象，复制数据到缓冲的内存
```cpp
//将 VBO 绑定到 目标上
glBindBuffer(GL_ARRAY_BUFFER, VBO);
//把顶点数据复制到缓冲的内存中
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
```
###### 缓冲区数据用途
usage标志有3个枚举值：
- GL_STATIC_DRAW ：数据不会或几乎不会改变。
- GL_DYNAMIC_DRAW：数据会被改变很多。
- GL_STREAM_DRAW ：数据每次绘制时都会改变。
###
***
### 顶点属性
##### glVertexAttribPointer
设置顶点属性指针
```Cpp
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 
/* 
参数1：指定要配置的顶点属性索引值 
参数2：顶点属性的大小 
参数3：数据的类型 
参数4：数据是否需要标准化到（-1，1）之间，需要为GL_TRUE，不需要为GL_FALSE 
参数5：步长，即连续的顶点属性组之间的间隔 
参数6：偏移量，void*类型，表示位置数据在缓冲中起始位置的偏移量 */
```
##### glEnableVertexAttribArray
启用顶点属性
```cpp
glEnableVertexAttribArray(0);  //0是顶点属性索引值
```
glDisableVertexAttribArray
取消顶点属性
```cpp
glDisableVertexAttribArray(0); //0是顶点属性索引值
```
###
***
##### glViewPort
进行[[视口变换]]；
```cpp
glViewPort(x, y, width, height);

//x和y：表示视口左下角在窗口中的坐标
//width和height：表示视口的宽度和高度
```
***




 