#include<iostream>
#include<string>
using namespace std;
class v 
{

};
class person
{
	int pa;//只有非静态成员变量属于类的对象上
	
	void fun(){	}//非静态成员函数不属于类的对象上
	static void funcv(){}//静态成员函数不属于类的对象上
	static int pb;//静态成员变量不属于类的对象上
};

void test71()
{//当类中什么也没有的时候
	v p;
	cout << sizeof(p) << endl;//空对象占内存空间1个字节
	//c++给每一个空对象也分配一个字节的空间是为了区分对象占内存的位置
	//每个空对象都应有一个独一无二的内存地址
}
void test72()
{//当给类一个非静态成员变量时
	person p;
	cout << sizeof(p) << endl;

	//非空对象占内存空间4个字节
}

int main()
{
	test71();
	test72();

	system("pause");
	return 0;
}