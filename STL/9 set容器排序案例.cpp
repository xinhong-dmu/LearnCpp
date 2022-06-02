#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

//利用拥有仿函数的类可以改变排序规则

//案例1 ：set容器存放内置数据类型
class mysort1
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
void sort1()
{//制订排序规则为从大到小
	set<int, mysort1>s;//通过排序类制订排序规则
	//需要在生成set容器之前就写好规则
	s.insert(1);
	s.insert(2);
	s.insert(0);
	for (set<int, mysort1>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << (*i) << " ";
	}
}

//案例2——存放自定义数据类型
class person
{
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
class mysort2
{
public:
	bool operator()(const person &p1,const person &p2)//交换数据时防止篡改数据
	{
		return p1.age > p2.age;
	}
};
void sort2()
{
	set<person, mysort2>s;
	//需要在生成set容器之前就写好规则
	person p1("p1", 25);
	person p2("p2", 22);
	person p3("p3", 23);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	for (set<person, mysort2>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << i->name << " " <<i->age << " ";
	}
}
//void main()
//{
//	sort1();
//	sort2();
//	system("pause");
//}