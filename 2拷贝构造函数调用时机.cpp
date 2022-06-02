#include<iostream>
#include<string>
using namespace std;

class person
{
public:
	person()
	{
		cout << "person默认构造函数调用" << endl;
	}
	person(int a)
	{
		age = a;
		cout << "person有参构造函数调用" << endl;
	}
	person(const person& p)
	{
		age = p.age;
		cout << "person拷贝构造函数调用" << endl;
	}
	~person()
	{
		cout << "person析构函数调用" << endl;
	}
	int age;
};

//1.利用一个已经创建完毕的对象来初始化一个新的对象
void test21()
{
	person p1(10);
	person p2(p1);

}
//2.值传递的方式给参数传值
void zhichunandi(person p){}//传入一个person类的对象
void test22()
{
	person p3;
	zhichunandi(p3);
}
//3.值方式返回局部变量
person& fanhuijububianliang()//引用的方式返回局部变量（对象）
{
	person p4;
	cout << (int)&p4 << endl;
	return p4;//返回值和后面的不一样
}
void test23()
{
	person p5 = fanhuijububianliang();//返回值和前面的不一样
	cout << (int)&p5 << endl;
}
int main()
{
	test21();
	test22();
	test23();
	
	system("pause");
	return 0;
}