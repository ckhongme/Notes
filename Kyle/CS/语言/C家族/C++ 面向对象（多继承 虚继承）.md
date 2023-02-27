#语言/cpp #面向对象 
***
[[继承]]的定义
***
### 继承的语法
```cpp
class 子类：继承方式 父类
```
###### 继承方式
-   公共继承：保留父类所有能继承的成员的访问权限；
-   保护继承：从父类继承的成员，访问权限都改成protected；
-   私有继承：从父类继承的成员，访问权限都改成private；

### 继承中的构造和析构
子类会调用父类的构造和析构函数；
顺序：先构造父类，再构造子类；先析构子类，再析构父类；

### 继承中的同名成员
当出现同名成员时，子类的同名成员会隐藏掉父类中所有的同名成员；（包括重载的函数）
访问父类的同名成员，需要**加作用域**；
在变量和函数前加 **父类名::**

-   继承的基类，子类和调用
    ```cpp
    class Base //基类
    {
		void Base()
		{
			m_A = 10;
		}
		void func();
		static void func2();
		int m_A;
	}
	
	class Son //子类
	{
		void Son()
		{
			m_A = 10;
		}
		void func();
		static void func2();
		int m_A;
	}
	
	void test() //调用
	{
		Son s;
		cout << "Son中的m_A" << s.m_A << endl;
		cout << "Base中的m_A" << s.Base::m_A << endl;
		
		s.func();        //调用Son中的func函数；
		s.Base::func();  //调用Base中的func函数；
		Son::Base::func2()  //通过类名访问父类的同名静态函数；
	}
	```
---
### 多继承
一个类可以有多个父类，继承了多个父类的特性；
通过逗号隔开；
```cpp
class C: public A, public B
```

### 虚继承
[[C++ 虚继承]]
