#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

//����ӵ�зº���������Ըı��������

//����1 ��set�������������������
class mysort1
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
void sort1()
{//�ƶ��������Ϊ�Ӵ�С
	set<int, mysort1>s;//ͨ���������ƶ��������
	//��Ҫ������set����֮ǰ��д�ù���
	s.insert(1);
	s.insert(2);
	s.insert(0);
	for (set<int, mysort1>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << (*i) << " ";
	}
}

//����2��������Զ�����������
class person
{
public:
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
class mysort2
{
public:
	bool operator()(const person &p1,const person &p2)//��������ʱ��ֹ�۸�����
	{
		return p1.age > p2.age;
	}
};
void sort2()
{
	set<person, mysort2>s;
	//��Ҫ������set����֮ǰ��д�ù���
	person p1("p1", 25);
	person p2("p2", 22);
	person p3("p3", 23);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	for (set<person, mysort2>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << i->name << " " <<i->age << " ";
	}
}
//void main()
//{
//	sort1();
//	sort2();
//	system("pause");
//}