### glUniformXX
后缀是XX的glUniform函数；
XX后缀表示数据的类型；
设置uniform，需要在当前激活的着色器程序中设置uniform的值；（[[着色器程序对象#激活程序对象 glUseProgram]]）

##### glUniform4f


##### 传入矩阵 glUniformMatrix4fv 
后缀是Matrix4fv的glUniform函数；
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
OpenGL使用的内部矩阵布局叫做列主序(Column-major Ordering)布局，而GLM的默认布局就是列主序，所以并不需要置换矩阵，填GL_FALSE；