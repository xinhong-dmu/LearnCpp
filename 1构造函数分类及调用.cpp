#include<iostream>
#include<string>
using namespace std;

class person
{
public:
	//若提供了有参构造函数，编译器不再自动提供默认构造函数，但提供拷贝构造函数
	//若提供了拷贝构造函数，编译器就不再自动提供其他普通构造函数
	person(int a)
	{
		age = a;
		cout << "person  有参构造函数的调用" << endl;
	}
	person()//无参构造或默认构造函数
	{
		cout << "person  默认(无参）构造函数的调用" << endl;
	}
	~person()
	{
		cout << "person  析构函数的调用" << endl;
	}
	//拷贝构造函数，除此以外的都是普通构造。
	//拷贝构造函数如果没写系统会自动生成，也就是说可以直接进行拷贝操作
	person(const person &p)//防止修改原来的数据，用引用方式
	{
		age = p.age;//将原来类中的成员属性复制给构造函数
		cout << age<<"       person  拷贝构造函数的调用" << endl;
	}

	int age;
};

//构造函数的调用
	//1.括号法，调用默认构造函数不带括号
void test11()
{
	person p1;//调用默认构造函数不带括号。若写了()就跟函数声明一个形式了
	person p2(12);//调用有参构造函数
	person p3(p2);//调用拷贝构造函数
	//因为是执行完整个函数才会释放，所以最后才会3次调用析构函数
	//注意不要写：类名（参数）；这是匿名对象，执行完会被系统立即回收
	cout << "p2 age: " << p2.age << endl;
	cout << "p3 age: " << p3.age << endl;
}
//2.等于号赋值法
void test12()
{
	person p4 = person(20);//调用有参构造函数，把(参数)变成=类名(参数)
	person p5 = person(p4);//调用拷贝构造函数
}
//3.隐式转换法
void test13()
{
	person p6 = 30;//系统会帮你转化成方法2的形式
	person p7 = p6;
}
int main()
{
	test11();
	test12();
	test13();

	system("pause");
	return 0;
}