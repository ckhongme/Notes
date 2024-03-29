存储顶点数据
***
全称Vertex Buffer Object，是一个能在[[显存]]中存储大量顶点数据的对象；
一个VBO可以表示一个物体的顶点数据，多个物体就需要多个VBO；
### 为什么要有VBO？
输入时，需要将顶点数据发送到GPU上，并在GPU上创建内存用于存储；
从CPU发送数据到GPU比较慢，所以不能频繁发送；
通过VBO来 **存储和传送顶点数据**，可以提高数据传输的效率；
当顶点数据存储在显存后，可以通过VBO来读取数据；
### VBO的使用
[[Shader]]可以通过VBO从现存中获得[[顶点属性]]的数据；
VBO可以供Shader使用，而且一个Shader可以使用多个VBO；
***
[[OpenGL]]确保至少有 **16** 个包含4分量的[[顶点属性]]可用；
##### 设置顶点属性指针
相当于：
1. 将当前绑定的VBO与顶点属性链接起来；
2. 告诉OpenGL顶点数据的格式：指定输入数据的哪一个部分对应顶点着色器的哪一个顶点属性
[[opengl-core#glVertexAttribPointer]]
***

