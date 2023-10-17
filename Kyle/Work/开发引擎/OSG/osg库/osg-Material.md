材质，继承自[[osg-StateAttribute]]；


##### 接受光照
```cpp
osg::ref_ptr<osg::Material> rpMat = new osg::Material;
//漫反射
rpMat->setDiffuse(osg::Material::FRONT, osg::Vec4(1.0,0.0,0.0,1.0));
//镜面反射
rpMat->setSpecular(osg::Material::FRONT, osg::Vec4(1.0,0.0, 0.0, 1.0));
//环境光
rpMat->setAmbient(osg::Material::Front_AND_BACK, osg::Vec4(1.0, 0.0, 0.0, 1.0)):

//打开材质球的属性
rpGeometry->getOrCreateStateSet()->setAttributeAndModes(rpMat.get(), osg::StateAttribute::ON | sog::StateAttribute::OVERRIDE);
```