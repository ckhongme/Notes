
```cpp
//shader程序对象
osg::ref_ptr<osg::Program> program = new osg::Program;  
//顶点着色器
program->addShader( osgDB::readRefShaderFile(osg::Shader::VERTEX,"Shaders/xxx.vert.glsl"));  
//几何着色器
program->addShader( osgDB::readRefShaderFile(osg::Shader::GEOMETRY,"Shaders/xxx.geom.glsl"));  
//片元着色器
program->addShader( osgDB::readRefShaderFile(osg::Shader::FRAGMENT,"Shaders/xxx.frag.glsl"));
```


