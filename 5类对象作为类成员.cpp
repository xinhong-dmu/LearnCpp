#include<iostream>
#include<string>
using namespace std;
class phone//����������
{
public:
	phone( string name)
	{
		phone_name=name;

	}
	~phone(){}//����������
	string phone_name;
};

class person//�������������
{
public:
	person(string name,string phname):person_name(name),ph_name(phname)
	{
	}
	~person() {  }//�����������
	string person_name;
	phone  ph_name;
};

void test05()
{
	person p("Sincereh", "huawei");//����һ���������������Ķ��󣬾Ϳ��Ե���������ĳ�Ա
	cout << p.person_name << " bought " << p.ph_name.phone_name<< endl;//���÷�ʽ�����������������Ķ���.���������.��Ա
}

int main()
{
	test05();
	system("pause");
	return 0;
}