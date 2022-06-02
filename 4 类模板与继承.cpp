#include<iostream>
#include<string>
using namespace std;

//类模板遇到继承时需注意：
//1 当子类继承的父类是一个类模板时，子类必须要在声明中写出父类中T的数据类型
//2 若想灵活指定父类中的T的数据类型，需要把子类也模板化


template<class T>
class father
{
public:
	T obj;
};

class son1 : public father<int>//必须要知道父类中T的数据类型才能继承给子类
{
};

//若想灵活指定父类中的T的数据类型，子类也要变成模板
template<class T1, class T2>//通过调用时指定T1,T2数据类型给父类
class son2 :public father<T2>//在调用时的T2数据类型给父类
{
public:
	son2()
	{
		cout << "T1的数据类型为" << typeid(T1).name() << endl;//typeid(对象名).name()
		cout << "T2的数据类型为" << typeid(T2).name() << endl;
	}
};

void test40()
{
	son2<string, int>p;
}
void main()
{
	test40();
	system("pause");
}