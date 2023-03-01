#语言/cpp 
***
[[运算符]]
#### dynamic_cast 运算符
将操作数 expression 转换为 type-id 类型的对象
```cpp
dynamic_cast <type-id> ( expression )
```

### 运算符重载 operator
本质是函数重载，实现多态；
作用：实现两个自定义数据类型的运算；（编译器只知道内置的数据类型如何运算）
```cpp
返回类型 operator 要重载的运算符(参数列表)
{
	函数体;
}
```

##### 重载方式
-   成员函数重载
-   全局函数重载
```cpp
class Person
{
public:
	Person operator+(Person &p) //成员函数 重载+号运算符
	{
		Person temp;
	  temp.m_a = this->m_a + p.m_a;
		return temp;
	}
	int m_a;
}

//全局函数 重载-号运算符
Person operator-(Person &p1, Person &p2)  
{
	Person temp；
	temp.m_a = p1.m_a-p2.m_a;
	return temp;
}
ostream & operator<<(ostream &cout, Person &p);  //重载 << 运算符

void test()
{
	Person p1;
	p1.m_a = 10;
	Person p2;
	p2.m_a = 5;
	Person p3 = p1 + p2;  //Person类的加法运算 
	Person p4 = p1 - p2;  //Person类的减法运算
	cout<<p<<endl;        //Person类的 << 运算，可以实现直接输出 Person类
}
```

##### 重载左移运算符 <<
可以输出自定义数据类型：
```cpp
//不会使用成员变量来重载<< ; (无法实现 cout 在左侧)
ostream & operator<<(ostream &cout, Person &p)    // 可以简化成 cout << p
{
	cout << "m_a = " << p.m_A;
}
```

##### 重载递增运算符++
可以实现自定义的整形数据：
- 重载前置++, 返回引用是为了一直对一个数据进行递增操作
```cpp
MyInteger & operator++()  
{
	m_Num++;
	returm *this;
}
```
- 重载后置++, 其中int表示[[C++ 函数#占位参数]]，用于区别前置++，返回一个值数据是因为temp在调用完后就会被释放；
```cpp
MyInteger operator++(int)  
{
	MyInteger temp = *this;
	m_Num++;
	return temp;
}
```

##### 重载赋值运算符 =
编译器提供的是浅拷贝，因此需要重写一个深拷贝构造函数；([[深拷贝&浅拷贝]])
```cpp
class Person
{
public：
	Person(int age)
	{
		m_Age = new int(age);  //将年龄开辟到堆区；
	}
	//重写深拷贝构造函数
	Person& operator=(Person &p)
	{
		if(m_Age != NULL)
		{	
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;   //为了能够进行链式赋值；
	}
	int* m_Age;
}
```
_链式赋值：([[函数（方法）#函数重载]]) 

##### 重载函数调用运算符 ()
```cpp
void operator()()
{...}
```
