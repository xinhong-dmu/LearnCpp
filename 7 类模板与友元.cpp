#include<iostream>
#include<string>
using namespace std;

//��ģ�������Ԫ���������ں�����ʵ�ַ���˽������
//ȫ�ֺ���������ʵ�֡���ֱ��������������Ԫ���ɣ���������
template<class t1,class t2>
class person
{
	//ȫ�ֺ�������ʵ��
	friend void show(person<t1, t2>&p)//ͨ����Ԫ����˽������
	{
		cout << p.name << p.age << endl;
	}
public:
	person(t1 name, t2 age)
	{
		this->name = name;
		this->age = age;
	}
private:
	t1 name;
	t2 age;
};
void test70()
{
	person<string, int>p("Sincereh", 24);
	show(p);
}
void main()
{
	test70();
	system("pause");
}