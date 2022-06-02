#include<iostream>
#include<string>
using namespace std;
class person
{
public:
	//初始化列表：构造函数(数据类型1，变量1)：成员变量1(变量1),成员变量2(变量2),...{ }
	//用于初始化列表的构造函数，也是构造函数，就没必要写默认构造函数了
	person(int a,int b) :pa(a), pb(b){	}
	~person()	{	}
	//传统初始化操作，利用构造函数
	//person(int a, int b)
	//{
	//	pa = a;
	//	pb = b;
	//}
	
	int pa;
	int pb;
};

void test041()
{
	//person p1(10, 20);传统方法赋初值
	person p1(10,20);
	cout << "pa = " <<p1.pa<< endl;
	cout << "pb = " <<p1.pb <<endl;
}

int main()
{
	test041();




	system("pause");
	return 0;
}