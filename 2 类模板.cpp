#include<iostream>
#include<string>
using namespace std;

//类模板的作用：类中成员变量的数据类型可以先不设定，用虚拟的类型代表

//template<class(可以typename替代)   T1，class T2>
//类

//类模板的调用
//类名<数据类型>  对象(默认参数)；//如果有默认参数，对象后加（默认参数）
//对象.成员；

//类模板和函数模板的区别：
//1 类模板没有自动类型推导的使用方式——<必须有数据类型>
//2 类模板在模板参数列表中<>可以有默认参数——template<class 虚拟数据类型1,class 虚拟数据类型2 = int >默认虚拟数据类型为整型
//在调用时，就可以不用写具有默认数据类型的数据类型了——类名<虚拟数据类型1>

//类模板中的成员函数在调用时才去创建
class person0
{
public:
	void show0()
	{
		cout << "类模板person0中的成员函数调用" << endl;

	}
};
class person1
{
public:
	void show1()
	{
		cout << "类模板person1中的成员函数调用" << endl;

	}
};

template <class T>
class person
{
public:
	T obj;//不确定数据类型的对象
	void func0()//目前还没创建成员函数，因为不知道对象obj的类型
	{
		obj.show0();
	}
	void func1()
	{
		obj.show1();
	}
};
void test20()
{
	person<person0>p0;
	p0.func0();//当调用类中的成员函数才去创建类中成员函数
	//p0.func1();//不可以调用<>中以外类的类中成员
	person<person1>p1;
	p1.func0();
	//p1.func1();
}

void main()
{
	test20();


	system("pause");
}