#include<iostream>
#include<string>
using namespace std;

/*��̬���ŵ㣺
1.������֯�ṹ����
2.�ɶ���ǿ
3.����ǰ�ںͺ��ڵ���չ��ά��*/
//��ʵ�������ᳫ����ԭ�򡪡�����չ���п��ţ����޸Ľ��йر�


//��ͨд��
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
	cout << "�������һ���������س�" << endl;
	cin >>a;
	cout << "����������������س�" << endl;
	cin >> oper;
	cout << "������ڶ����������س���ȡ���" << endl;
	cin >> b;
	calculator0 ca;
	ca.m_num1 = a;
	ca.m_num2 = b;
	ca.oper = oper;
	cout<<ca.m_num1<<ca.oper<<ca.m_num2<<" = "<<ca.result(ca.oper)<<endl;
}

//��̬д��
//1.ʵ�ּ������ĳ�����
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
//2.��������Ӽ��˳�����
class add:public abstract_caculator1//�̳�
{
public:
	virtual double result()
	{
		return m_n1 + m_n2;
	}
};
class minus1:public abstract_caculator1//�̳�
{
public:
	virtual double result()
	{
		return m_n1 - m_n2;
	}
};
class multi :public abstract_caculator1//�̳�
{
public:
	virtual double result()
	{
		return m_n1 * m_n2;
	}
};
class division :public abstract_caculator1//�̳�
{
public:
	virtual double result()
	{
		return m_n1 / m_n2;
	}
};
//��������չ�������㷽ʽ



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
{//��̬����ָ�����������ࡪ������ * ָ�� = new ���ࣻ
	abstract_caculator1 * p0 = new add;//����ָ��ָ���������
	abstract_caculator1 * p1 = new minus1;
	abstract_caculator1 * p2 = new multi ;
	abstract_caculator1 * p3 = new division;
	double  a;
	double  b;
	string oper;
	cout << "�������һ���������س�" << endl;
	cin >> a;
	cout << "����������������س�" << endl;
	cin >> oper;
	cout << "������ڶ����������س���ȡ���" << endl;
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
	cout << " ������������������������������" << endl;
	cout << "|  ��ӭʹ��Sincereh'Caculator   |" << endl;
	cout << " ������������������������������" << endl<<endl;
	test02();

	system("pause");
	return 0;
}