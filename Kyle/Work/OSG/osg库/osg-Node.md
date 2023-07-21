继承自[[osg-Object]]；

### 函数
```cpp
setNodeMask(value)          //设置显隐(当value为0时隐藏，不为0时显示）
setName(string)             //设置名字
```




***
##### 节点回调 NodeCallBack  
```cpp
#include <osg/NodeCallBack> 
class m_Callback : public osg::NodeCallback
{
	public:
		m_Callback();
		~m_Callback();
	void operator(osg::Node* node, osg::NodeVisitor* nv);
}
```

##### 节点访问器 NodeVisitor
快速找到某个节点
```cpp
#include <osg/NodeVisitor>
class m_Visitor : public osg::Visitor
{
	pubilc :
		m_Visitor();
		~m_Visitor();
	void apply(osg::Transform& node);
}
```
