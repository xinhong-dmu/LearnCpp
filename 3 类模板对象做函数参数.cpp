#include<iostream>
#include<string>
using namespace std;

//��ģ��ʵ������������������
//�������ִ��뷽ʽ
//1 ָ����������� ���� ֱ����ʾ�������������
//2 ����ģ�廯 ���� �������еĲ�����Ϊģ����д���
//3 ������ģ�廯 ���� ������������ͽ���ģ�廯Ȼ�󴫵�


template<class T1,class T2>
class person
{
public:
	person(T1 name, T2 age)
	{
		this->name = name;
		this->age = age;
	}
	void show()
	{
		cout << this->name <<" "<< this->age << endl;
	}
	T1 name;
	T2 age;
};

//����һ����ģ�������������������������������������������
void print30(person<string, int>&p)//ָ���������ͷ���������ģ��Ķ������÷�ʽ����
{
	p.show();
}
void test30()
{
	person<string, int>p0("Sincereh", 24);
	print30(p0);
}

//������������ģ�廯
template<class T1,class T2>//������ģ�廯������дһ����ģ�������
void print31(person<T1,T2>&p)
{
	p.show();
	cout << "�鿴��������������" << typeid(T1).name() << endl;//typeid(������).name()
}
void test31()
{
	person<string, int>p1("Sincereh", 24);
	print31(p1);
}

//��������������ģ�廯
template<class T>//������ģ�廯������дһ����ģ�������
void print32(T &p)//�����Ĳ���ֻд������������ �� ���ö���
{
	p.show();
	cout << "�鿴��������������" << typeid(T).name() << endl;//type(������).name()
}
void test32()
{
	person<string, int>p3("Sincereh", 24);
	print32(p3);
}



void main()
{
	test30();
	test31();
	test32();
	system("pause");
}