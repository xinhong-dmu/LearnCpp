#include<iostream>
#include<string>
using namespace std;

//��ģ���Ա����������ʵ��
template<class t1,class t2>
class person
{
public:
	t1 name;
	t2 age;
};
//���캯��������ʵ��
template<class t1,class t2>//����ģ�������
person<t1,t2>::person(t1 name, t2 age)//�Ӳ����б�<>
{
public:
	person();
	void show();
	this->name = name;
	this->age = age;
}
//��Ա����������ʵ��
template<class t1, class t2>//����ģ�������
void person<t1, t2>::show()//������Ӳ����б�<>
{
	cout << this->name << this->age << endl;
}
