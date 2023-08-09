### [[顶点着色器]]的内置变量
##### 输入的顶点属性
```
in vec3 osg_Vertex          //对象空间中顶点的位置
in vec3 osg_Normal          //顶点的法线
in vec4 osg_MultiTexCoordn  //n是数字，从0开始，表示输入多个纹理坐标
```
([[纹理坐标UV]])
##### 计算矩阵
```
uniform mat4 osg_ViewMatrix                  //观察矩阵
uniform mat4 osg_ModelViewMatrix             //模型+观察矩阵 
uniform mat4 osg_ProjectionMatrix            //投影矩阵
uniform mat4 osg_ModelViewProjectionMatrix   //MVP矩阵
```

