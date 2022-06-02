#include<iostream>
#include<string>
using namespace std;
//空指针也可以调用成员函数
//但要注意有没有用到this指针。若遇到this则要判断代码的健壮性

class person
{public:
	void showpersonname()
	{
		cout << "He is Jack." << endl;
	}
	void showpersonage()
	{//增强代码健壮性，防止空指针使代码崩溃。若是空指针就采取直接把下面的函数体中的代码也跳过
		if(this == NULL)
		{
			return;
		}
		cout << "He is " <<m_age<< endl;//在属性前默认加了this->m_age
	}
	int m_age;
};
void test10()
{
	person * p0 = NULL;//把指针变空相当于没有创建对象，this指向了一个空的值
	p0->showpersonname();
	p0->showpersonage();
}
int main()
{
	test10();

	system("pause");
	return 0;
}