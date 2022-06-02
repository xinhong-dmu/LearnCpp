#include<iostream>
#include<string>
using namespace std;
//友元就是别的类或者函数访问另一个类中的私有成员（private）
//友元的三种实现方式：
//1.全局函数作友元
//2.类作友元
//3.成员函数作友元


class building
{
	//方式一的 友元全局函数的声明写在类的第一行即可，该全局函数就可以访问类中的私有成员了
	friend void goodfriend0(building &b);//函数声明
	//方式二的 其他类访问该类中的私有成员
	friend class goodfriend1;//friend class 类名
	//方式二可以代替方式三，之后的写法都一样
	//方式三：将类中的成员函数作为声明
	friend class goodfriend2;
	friend void goodfriend2::visit2();//friend 返回值类型 类名::成员函数名();
public:
	building();//类外写成员函数时，类内要声明
	string m_sittingroom;
private:
	string m_bedroom;
};
//类外写成员函数的方法——类名::函数名（）{ }；
building::building()
{
	m_sittingroom = "客厅";
	m_bedroom = "卧室";
}

//方法一：全局函数
void goodfriend0(building &b)
{
	cout << "全局函数访问类中的公共成员:  " << b.m_sittingroom << endl;
//cout << "全局函数访问类中的私有成员:  " << b.m_bedroom << endl;  没声明的话不可访问私有成员
	cout << "全局函数访问类中的私有成员:  " << b.m_bedroom << endl;
}
void test00()
{
	building b;
	goodfriend0(b);
}


//方式二：类作友元。让一个类访问另一个类的私有成员
class goodfriend1
{
public:
	goodfriend1();
	void visit1();
	building *b;
};
goodfriend1::goodfriend1()
{
	b =new building;//在堆区随便创建一个新指针，类中指针地址变量（不带*） = new 成员名
}
void goodfriend1::visit1()
{
	cout << "类googfriend1 正在访问 类building 中的公共成员: " << b->m_sittingroom << endl;
	cout << "类googfriend1 正在访问 类building 中的私有成员: " << b->m_bedroom << endl;
}
void test01()
{
	goodfriend1 g1;
	g1.visit1();
}


//方式三：成员函数作友元 
class goodfriend2
{
public:
	goodfriend2();
	void visit2();
	building *b;
};
goodfriend2::goodfriend2()
{
	b = new building;
}
void goodfriend2::visit2()
{
	cout << "类googfriend2 正在访问 类building 中的公共成员: " << b->m_sittingroom << endl;
	cout << "类googfriend2 正在访问 类building 中的私有成员: " << b->m_bedroom << endl;
}
void test02()
{
	goodfriend2 g2;
	g2.visit2();
}



int main()
{
	test00();
	test01();
	test02();

	system("pause");
	return 0;
}