#include<iostream>
#include<string>
using namespace std;
//ͨ��thisָ�������ֵ������ĸ�������õķǾ�̬��Ա����
//thisָ��ָ�򱻵��õĳ�Ա���������Ķ��� 
//thisָ�����;��
//1.���βκͳ�Ա����ͬ��ʱ����thisָ��������
//2.����ķǾ�̬��Ա�����з��ض�������return *this���˺�������ֵΪ�ࡪ������& ������(){}
class person
{public:
	person(int age)
	{
		this->age = age;//ͨ��this->�����ͬ������
	}
	int age;
	person& personaddperson(person &p)//�����õķ�ʽ����һ�����ú͵��ã�����һֱ�����������
		//������ص��Ǹ�ֵ�����൱���½���һ�����󣬺�֮ǰ�����û��ϵ
	{
		this->age += p.age;//�����������������������
		//thisָ����Ƕ����ָ�룬*thisָ����Ƕ���ı���
		return *this;//���Է�������ĵ��Ӳ������Ա�����Ըú����Ĳ��ϵ���
	}
};
void test00()
{
	person p1(18);
	cout << p1.age << endl;
}
void test01()
{
	person p2(20);
	person p3(30);
	//��ʽ���˼������������ֵ�Ǳ���ʱ���������÷�ʽ���أ����ɶԺ�������������
	p3.personaddperson(p2).personaddperson(p2).personaddperson(p2);
	cout <<"���������p3�����䣺"<<p3.age << endl;
}
int main()
{
	test00();
	test01();
	system("pause");
	return 0;
}