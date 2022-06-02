#include<iostream>
#include<string>
using namespace std;
//成员函数（）后面加const后称为常函数
//常函数不可修改成员属性，在（）后加const
//成员函数声明时在最前面加关键字mutable后，在常函数中依旧可以修改

//常对象：声明对象前加const
//常对象只能调用常函数

class person
{
public:
	void show0(){}
	void show1()const//const修饰的是this指针
	{
		//m_a = 100错;  成员函数（）后面加const就不能修改成员属性，没有mutable时
		//上节说过默认this->m_a,this指针是不可以修改的
		m_b = 10;
		cout << m_b << endl;
	}
	int m_a;
	mutable int m_b;//mutable 数据类型 成员变量； 这种声明就可以常函数中修改这个值
};
void test20()
{
	const person p0;//常对象的表示方法
//	p0.m_a = 100;  常对象没加mutable不可以修改
	p0.m_b = 100;//类中的成员变量前加了mutable就可以修改
	
//常对象只能调用常函数
//	p0.show0(); 不能调用除常函数以外的成员函数
	p0.show1();

}

int main()
{
	

	system("pause");
	return 0;
}