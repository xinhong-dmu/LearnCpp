#include<iostream>
#include<string>
using namespace std;

//��ģ������ã����г�Ա�������������Ϳ����Ȳ��趨������������ʹ���

//template<class(����typename���)   T1��class T2>
//��

//��ģ��ĵ���
//����<��������>  ����(Ĭ�ϲ���)��//�����Ĭ�ϲ����������ӣ�Ĭ�ϲ�����
//����.��Ա��

//��ģ��ͺ���ģ�������
//1 ��ģ��û���Զ������Ƶ���ʹ�÷�ʽ����<��������������>
//2 ��ģ����ģ������б���<>������Ĭ�ϲ�������template<class ������������1,class ������������2 = int >Ĭ��������������Ϊ����
//�ڵ���ʱ���Ϳ��Բ���д����Ĭ���������͵����������ˡ�������<������������1>

//��ģ���еĳ�Ա�����ڵ���ʱ��ȥ����
class person0
{
public:
	void show0()
	{
		cout << "��ģ��person0�еĳ�Ա��������" << endl;

	}
};
class person1
{
public:
	void show1()
	{
		cout << "��ģ��person1�еĳ�Ա��������" << endl;

	}
};

template <class T>
class person
{
public:
	T obj;//��ȷ���������͵Ķ���
	void func0()//Ŀǰ��û������Ա��������Ϊ��֪������obj������
	{
		obj.show0();
	}
	void func1()
	{
		obj.show1();
	}
};
void test20()
{
	person<person0>p0;
	p0.func0();//���������еĳ�Ա������ȥ�������г�Ա����
	//p0.func1();//�����Ե���<>������������г�Ա
	person<person1>p1;
	p1.func0();
	//p1.func1();
}

void main()
{
	test20();


	system("pause");
}