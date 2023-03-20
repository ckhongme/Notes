### CoordinateSystemNode脚本
##### 只改变位置
世界坐标系转地理坐标系：convertLatLongHeightToXYZ 
```cpp
osg::Vec3d world;
// 椭圆模型节点 (默认是 wgs84)
osg::EllipsoidModel* em = new osg::EllipsoidModel();    
// 经纬度转xyz  (注意纬度在前面)
em->convertLatLongHeightToXYZ(osg::DegressToRadians(y), osg::DegressToRadians(x), z, world.x(), world.y(), world.z());
```

地理坐标系转世界坐标系：converXYZToLatLongHeight
```cpp
// 注意纬度在前面
em->converXYZToLatLongHeight(x, y, z, osg::DegreesToRadians(world->y()), osg::DegreesToRadians(world->x()), world->z());
```


##### 改变位置和姿态
世界坐标系转矩阵：conputeLocalToWorldTransformFromXYZ
```cpp
osg::Matrix matrix;
// osg坐标系节点
osg::ref_ptr<osg::CoordinateSystemNode> csn;
// 注意纬度在前面
csn->getEllipsoidModel()->conputeLocalToWorldTransformFromXYZ(world->y(), world->y(), world->z(), matrix);
```

地理坐标系转矩阵：computeLocalToWorldTransformLatLongHeight
```cpp
// 经纬度转矩阵 (注意纬度在前面)
csn->getEllipsoidModel()->computeLocalToWorldTransformLatLongHeight(osg::DegressToRadians(y),osg::DegressToRadians(x), z, matrix);
```

