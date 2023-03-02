不支持[[GC 垃圾回收机制]]

### new
在C++中，通过new关键字在堆区开辟内存；
利用new创建的数据，会返回该数据类型的指针；
```cpp
int * func()
{
	int * p = new int(10);     //在堆区开辟数据；
	return p;                  //可以返回局部变量的地址的情况：堆区的数据
}
...
int main()
{
	int *p = func();
}
```

### delete
通过delete可以释放内存；
```cpp
int * a = 10;
delete a;
int * arr[10] = new int[10];
delete[] arr;   //如果释放的是数组，还需要加个中括号
```

### 常见的内存问题
[[堆栈 Stack & Heap#1.访问被释放的栈区内存]]
[[堆栈 Stack & Heap#2.堆区内存重复释放]]（[[深拷贝&浅拷贝#为什么要有深拷贝？]]）