#include<iostream>
#include<string>
using namespace std;

/*多态的优点：
1.代码组织结构清晰
2.可读性强
3.利于前期和后期的扩展和维护*/
//真实开发中提倡开闭原则——对扩展进行开放，对修改进行关闭


//普通写法
class calculator0
{
public:
	double result(string oper)
		{
			oper = this->oper;
			if (oper == "+")
				return m_num1 + m_num2;
			else if (oper == "-")
				return m_num1 - m_num2;
			else if (oper == "*")
				return m_num1 * m_num2;
			else if (oper == "/")
				return m_num1 / m_num2;
		}
	double m_num1;
	double m_num2;
	string oper;
};
void test00()
{
	int a;
	int b;
	string oper;
	cout << "请输入第一个数，并回车" << endl;
	cin >>a;
	cout << "请输入运算符，并回车" << endl;
	cin >> oper;
	cout << "请输入第二个数，并回车获取结果" << endl;
	cin >> b;
	calculator0 ca;
	ca.m_num1 = a;
	ca.m_num2 = b;
	ca.oper = oper;
	cout<<ca.m_num1<<ca.oper<<ca.m_num2<<" = "<<ca.result(ca.oper)<<endl;
}

//多态写法
//1.实现计算器的抽象类
class abstract_caculator1
{
public:
	virtual double result()
	{
		return 0;
	}
	double m_n1;
	double m_n2;
};
//2.创建子类加减乘除运算
class add:public abstract_caculator1//继承
{
public:
	virtual double result()
	{
		return m_n1 + m_n2;
	}
};
class minus1:public abstract_caculator1//继承
{
public:
	virtual double result()
	{
		return m_n1 - m_n2;
	}
};
class multi :public abstract_caculator1//继承
{
public:
	virtual double result()
	{
		return m_n1 * m_n2;
	}
};
class division :public abstract_caculator1//继承
{
public:
	virtual double result()
	{
		return m_n1 / m_n2;
	}
};
//还可以扩展其他运算方式



//abstract_caculator1 test01(string op)
//{
//	string oper =op;
//	add add;
//	minus1 min;
//	multi mul;
//	division div;
//	if (oper == "+")
//		return add.result;
//	else if (oper == "-")
//		return min.result;
//	else if (oper == "*")
//		return mul.result;
//	else if (oper == "/")
//		return div.result;
//}
void test02()
{//多态利用指针来访问子类——父类 * 指针 = new 子类；
	abstract_caculator1 * p0 = new add;//父类指针指向子类对象
	abstract_caculator1 * p1 = new minus1;
	abstract_caculator1 * p2 = new multi ;
	abstract_caculator1 * p3 = new division;
	double  a;
	double  b;
	string oper;
	cout << "请输入第一个数，并回车" << endl;
	cin >> a;
	cout << "请输入运算符，并回车" << endl;
	cin >> oper;
	cout << "请输入第二个数，并回车获取结果" << endl;
	cin >> b;
	p0->m_n1 = a;
	p0->m_n2 = b;
	p1->m_n1 = a;
	p1->m_n2 = b;
	p2->m_n1 = a;
	p2->m_n2 = b;
	p3->m_n1 = a;
	p3->m_n2 = b;
	//test01(oper);
	if (oper == "+")
	{
		cout << p0->m_n1 << oper << p0->m_n2 << " = " << p0->result() << endl;
		delete p0;
	}
	else if (oper == "-")
	{
		cout << p1->m_n1 << oper << p1->m_n2 << " = " << p1->result() << endl;
		delete p1;
	}
	else if (oper == "*")
	{
		cout << p2->m_n1 << oper << p2->m_n2 << " = " << p2->result() << endl;
		delete p2;
	}
	else if (oper == "/")
	{
		cout << p3->m_n1 << oper << p3->m_n2 << " = " << p3->result() << endl;
		delete p3;
	}
	
}

int main()
{
	cout << " ———————————————" << endl;
	cout << "|  欢迎使用Sincereh'Caculator   |" << endl;
	cout << " ———————————————" << endl<<endl;
	test02();

	system("pause");
	return 0;
}