#include<iostream>
#include<string>
using namespace std;

//1.在对象时，对对象属性进行初始化操作——构造函数
class person
{
public:
	person()//无参构造（默认构造)
	{
		cout << "person 默认构造函数的调用" << endl;//不写的话就是系统自动有一个空实现
	}

	//2对象的清理操作——析构函数
	~person()
	{
		cout << "person  析构函数的调用" << endl;//不写的话就是系统自动有一个空实现
	}
};

void test01()
{//由于是在栈区的局部变量，test01执行完后会自动释放（销毁）这个对象，
//即，触发析构函数的调用条件，但只有一次
	person p;//创建对象时就可以自动调用构造函数，或者写person()也可以
}


int main()
{
	//若在main创建类对象，析构函数会在执行完main最后才会释放（销毁）对象，
	//会极短的显示一下就消失了
	//person p;
	//在函数中创建的对象，会随着函数执行完释放（销毁），
	//但还是在main中能够显示
	test01();

	system("pause");
	return 0;
}