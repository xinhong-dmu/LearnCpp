#include<iostream>
#include<string>
using namespace std;

class person
{
public:
	person()
	{
		cout << "personĬ�Ϲ��캯������" << endl;
	}
	person(int a)
	{
		age = a;
		cout << "person�вι��캯������" << endl;
	}
	person(const person& p)
	{
		age = p.age;
		cout << "person�������캯������" << endl;
	}
	~person()
	{
		cout << "person������������" << endl;
	}
	int age;
};

//1.����һ���Ѿ�������ϵĶ�������ʼ��һ���µĶ���
void test21()
{
	person p1(10);
	person p2(p1);

}
//2.ֵ���ݵķ�ʽ��������ֵ
void zhichunandi(person p){}//����һ��person��Ķ���
void test22()
{
	person p3;
	zhichunandi(p3);
}
//3.ֵ��ʽ���ؾֲ�����
person& fanhuijububianliang()//���õķ�ʽ���ؾֲ�����������
{
	person p4;
	cout << (int)&p4 << endl;
	return p4;//����ֵ�ͺ���Ĳ�һ��
}
void test23()
{
	person p5 = fanhuijububianliang();//����ֵ��ǰ��Ĳ�һ��
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