几何体类，指定绘制几何体的顶点及对数据的解析；
设置顶点、法线、颜色、纹理坐标等数据，设置绑定方式，数据解析，最后加入到叶节点[[osg-Geode]]绘制并渲染；


##### 绘制正方形
```cpp
// 实例化几何体节点 
osg::ref_ptr<osg::Geometry> rpGeometry = new osg::Geometry; 

// 定义顶点数组 
osg::ref_ptr<osg::Vec3dArray> v = new osg::Vec3dArray; 
v->push_back( osg::Vec3d( -1.f, 0.f, -1.f ) ); 
v->push_back( osg::Vec3d( 1.f, 0.f, -1.f ) ); 
v->push_back( osg::Vec3d( 1.f, 0.f, 1.f ) ); 
v->push_back( osg::Vec3d( -1.f, 0.f, 1.f ) ); 
rpGeometry->setVertexArray( v.get() ); 

// 定义颜色数组 
osg::ref_ptr<osg::Vec4dArray> c = new os g::Vec4dArray; 
c->push_back( osg::Vec4d( 1.f, 0.f, 0.f, 1.f )); 
c->push_back( osg::Vec4d( 0.f, 1.f, 0.f, 1.f )); 
c->push_back( osg::Vec4d( 0.f, 0.f, 1.f, 1.f )); 
c->push_back( osg::Vec4d( 1.f, 1.f, 1.f, 1.f )); 
rpGeometry->setColorArray( c.get() );
rpGeometry->setColorBinding( osg::Geometry::BIND_PER_VERTEX ); 

// 定义法线 
osg::ref_ptr<osg::Vec3dArray> n = new osg::Vec3dArray; 
n->push_back( osg::Vec3d( 0.f, -1.f, 0.f)); 
rpGeometry->setNormalArray( n.get()); 
rpGeometry->setNormalBinding( osg::Geometry::BIND_OVERALL ); 

//设置顶点关联方式 
rpGeometry->addPrimitiveSet( new osg::DrawArrays ( osg::PrimitiveSet::QUADS, 0, 4)); 
//几何组结点 
osg::ref_ptr<osg::Geode> geode = new osg::Geode;geode->addDrawable(rpGeometry.get());
```