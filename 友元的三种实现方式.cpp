#include<iostream>
#include<string>
using namespace std;
//��Ԫ���Ǳ������ߺ���������һ�����е�˽�г�Ա��private��
//��Ԫ������ʵ�ַ�ʽ��
//1.ȫ�ֺ�������Ԫ
//2.������Ԫ
//3.��Ա��������Ԫ


class building
{
	//��ʽһ�� ��Ԫȫ�ֺ���������д����ĵ�һ�м��ɣ���ȫ�ֺ����Ϳ��Է������е�˽�г�Ա��
	friend void goodfriend0(building &b);//��������
	//��ʽ���� ��������ʸ����е�˽�г�Ա
	friend class goodfriend1;//friend class ����
	//��ʽ�����Դ��淽ʽ����֮���д����һ��
	//��ʽ���������еĳ�Ա������Ϊ����
	friend class goodfriend2;
	friend void goodfriend2::visit2();//friend ����ֵ���� ����::��Ա������();
public:
	building();//����д��Ա����ʱ������Ҫ����
	string m_sittingroom;
private:
	string m_bedroom;
};
//����д��Ա�����ķ�����������::����������{ }��
building::building()
{
	m_sittingroom = "����";
	m_bedroom = "����";
}

//����һ��ȫ�ֺ���
void goodfriend0(building &b)
{
	cout << "ȫ�ֺ����������еĹ�����Ա:  " << b.m_sittingroom << endl;
//cout << "ȫ�ֺ����������е�˽�г�Ա:  " << b.m_bedroom << endl;  û�����Ļ����ɷ���˽�г�Ա
	cout << "ȫ�ֺ����������е�˽�г�Ա:  " << b.m_bedroom << endl;
}
void test00()
{
	building b;
	goodfriend0(b);
}


//��ʽ����������Ԫ����һ���������һ�����˽�г�Ա
class goodfriend1
{
public:
	goodfriend1();
	void visit1();
	building *b;
};
goodfriend1::goodfriend1()
{
	b =new building;//�ڶ�����㴴��һ����ָ�룬����ָ���ַ����������*�� = new ��Ա��
}
void goodfriend1::visit1()
{
	cout << "��googfriend1 ���ڷ��� ��building �еĹ�����Ա: " << b->m_sittingroom << endl;
	cout << "��googfriend1 ���ڷ��� ��building �е�˽�г�Ա: " << b->m_bedroom << endl;
}
void test01()
{
	goodfriend1 g1;
	g1.visit1();
}


//��ʽ������Ա��������Ԫ 
class goodfriend2
{
public:
	goodfriend2();
	void visit2();
	building *b;
};
goodfriend2::goodfriend2()
{
	b = new building;
}
void goodfriend2::visit2()
{
	cout << "��googfriend2 ���ڷ��� ��building �еĹ�����Ա: " << b->m_sittingroom << endl;
	cout << "��googfriend2 ���ڷ��� ��building �е�˽�г�Ա: " << b->m_bedroom << endl;
}
void test02()
{
	goodfriend2 g2;
	g2.visit2();
}



int main()
{
	test00();
	test01();
	test02();

	system("pause");
	return 0;
}