#include<iostream>
#include<string>
using namespace std;
//��Ա�������������const���Ϊ������
//�����������޸ĳ�Ա���ԣ��ڣ������const
//��Ա��������ʱ����ǰ��ӹؼ���mutable���ڳ����������ɿ����޸�

//��������������ǰ��const
//������ֻ�ܵ��ó�����

class person
{
public:
	void show0(){}
	void show1()const//const���ε���thisָ��
	{
		//m_a = 100��;  ��Ա�������������const�Ͳ����޸ĳ�Ա���ԣ�û��mutableʱ
		//�Ͻ�˵��Ĭ��this->m_a,thisָ���ǲ������޸ĵ�
		m_b = 10;
		cout << m_b << endl;
	}
	int m_a;
	mutable int m_b;//mutable �������� ��Ա������ ���������Ϳ��Գ��������޸����ֵ
};
void test20()
{
	const person p0;//������ı�ʾ����
//	p0.m_a = 100;  ������û��mutable�������޸�
	p0.m_b = 100;//���еĳ�Ա����ǰ����mutable�Ϳ����޸�
	
//������ֻ�ܵ��ó�����
//	p0.show0(); ���ܵ��ó�����������ĳ�Ա����
	p0.show1();

}

int main()
{
	

	system("pause");
	return 0;
}