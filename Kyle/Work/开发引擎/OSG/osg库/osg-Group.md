继承自[[osg-Node]]

派生类包括osg::LOD、osg::Switch
##### traverse
用来实现对场景图中所有节点的递归遍历；
接受一个osg;:NodeVisitor类型的参数；
NodeVisitor是一个抽象类，不能直接实例化，需要创建一个继承自它的子类，并实现其纯虚函数


节点遍历主要分为两种，即深度优先遍历和广度优先遍历；
深度优先遍历是指从根节点开始，递归地遍历每个子节点，直到叶子节点为止，然后回溯到父节点，继续遍历兄弟节点；
广度优先遍历是指从根节点开始，逐层遍历每个节点，直到遍历完整个场景图
