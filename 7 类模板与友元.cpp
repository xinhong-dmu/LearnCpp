#include<iostream>
#include<string>
using namespace std;

//类模板配合友元函数的类内和类外实现访问私有属性
//全局函数的类内实现——直接在类内声明友元即可！！！！！
template<class t1,class t2>
class person
{
	//全局函数类内实现
	friend void show(person<t1, t2>&p)//通过友元访问私有属性
	{
		cout << p.name << p.age << endl;
	}
public:
	person(t1 name, t2 age)
	{
		this->name = name;
		this->age = age;
	}
private:
	t1 name;
	t2 age;
};
void test70()
{
	person<string, int>p("Sincereh", 24);
	show(p);
}
void main()
{
	test70();
	system("pause");
}