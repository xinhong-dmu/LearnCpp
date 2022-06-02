#include<iostream>
#include<string>
using namespace std;

//类模板成员函数的类外实现
template<class t1,class t2>
class person
{
public:
	t1 name;
	t2 age;
};
//构造函数的类外实现
template<class t1,class t2>//加类模板的声明
person<t1,t2>::person(t1 name, t2 age)//加参数列表<>
{
public:
	person();
	void show();
	this->name = name;
	this->age = age;
}
//成员函数的类外实现
template<class t1, class t2>//加类模板的声明
void person<t1, t2>::show()//类名后加参数列表<>
{
	cout << this->name << this->age << endl;
}
