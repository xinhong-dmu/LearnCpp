#include<iostream>
#include<string>
using namespace std;

//��ģ�������̳�ʱ��ע�⣺
//1 ������̳еĸ�����һ����ģ��ʱ���������Ҫ��������д��������T����������
//2 �������ָ�������е�T���������ͣ���Ҫ������Ҳģ�廯


template<class T>
class father
{
public:
	T obj;
};

class son1 : public father<int>//����Ҫ֪��������T���������Ͳ��ܼ̳и�����
{
};

//�������ָ�������е�T���������ͣ�����ҲҪ���ģ��
template<class T1, class T2>//ͨ������ʱָ��T1,T2�������͸�����
class son2 :public father<T2>//�ڵ���ʱ��T2�������͸�����
{
public:
	son2()
	{
		cout << "T1����������Ϊ" << typeid(T1).name() << endl;//typeid(������).name()
		cout << "T2����������Ϊ" << typeid(T2).name() << endl;
	}
};

void test40()
{
	son2<string, int>p;
}
void main()
{
	test40();
	system("pause");
}