#include<iostream>
#include<string>
using namespace std;

//类模板实例化出对象，向函数传参
//共有三种传入方式
//1 指定传入的类型 —— 直接显示对象的数据类型
//2 参数模板化 —— 将对象中的参数变为模板进行传递
//3 整个类模板化 —— 将这个对象类型进行模板化然后传递


template<class T1,class T2>
class person
{
public:
	person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	void show()
	{
		cout << this->name <<" "<< this->age << endl;
	}
	T1 name;
	T2 age;
};

//方法一：类模板对象作函数参数！！！！！！！！！！！！！！
void print30(person<string, int>&p)//指定传入类型方法就是类模板的对象引用方式调用
{
	p.show();
}
void test30()
{
	person<string, int>p0("Sincereh", 24);
	print30(p0);
}

//方法二：参数模板化
template<class T1,class T2>//将参数模板化——再写一遍类模板的声明
void print31(person<T1,T2>&p)
{
	p.show();
	cout << "查看参数的数据类型" << typeid(T1).name() << endl;//typeid(对象名).name()
}
void test31()
{
	person<string, int>p1("Sincereh", 24);
	print31(p1);
}

//方法三：整个类模板化
template<class T>//将参数模板化——再写一遍类模板的声明
void print32(T &p)//函数的参数只写虚拟数据类型 加 引用对象
{
	p.show();
	cout << "查看参数的数据类型" << typeid(T).name() << endl;//type(对象名).name()
}
void test32()
{
	person<string, int>p3("Sincereh", 24);
	print32(p3);
}



void main()
{
	test30();
	test31();
	test32();
	system("pause");
}