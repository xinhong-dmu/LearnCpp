#include<iostream>
#include<string>
using namespace std;
class person
{
public:
	//��ʼ���б����캯��(��������1������1)����Ա����1(����1),��Ա����2(����2),...{ }
	//���ڳ�ʼ���б�Ĺ��캯����Ҳ�ǹ��캯������û��ҪдĬ�Ϲ��캯����
	person(int a,int b) :pa(a), pb(b){	}
	~person()	{	}
	//��ͳ��ʼ�����������ù��캯��
	//person(int a, int b)
	//{
	//	pa = a;
	//	pb = b;
	//}
	
	int pa;
	int pb;
};

void test041()
{
	//person p1(10, 20);��ͳ��������ֵ
	person p1(10,20);
	cout << "pa = " <<p1.pa<< endl;
	cout << "pb = " <<p1.pb <<endl;
}

int main()
{
	test041();




	system("pause");
	return 0;
}