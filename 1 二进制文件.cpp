#include<iostream>
#include<fstream>//�ļ�����ͷ�ļ�
#include<string>
using namespace std;
//�������ļ��򿪷�ʽָ��Ϊios::binary


//д�ļ�ʾ������ostream& write(const char * ָ��,sizeof(����))
//����������Ϊ�Զ���ʱ����ǿתָ�롪��(const char *)&ָ��
//�����ַ�ָ��ָ���ڴ���һ�δ洢�ռ�

//�����ƿ��Բ����Զ������������
class person
{
public:
	void p(char name, int age)
	{
		m_name [64]= name;
		m_age = age;
	}
	char m_name[64];//���ļ�����������C�����е�char�ַ���������string
	//��ʾm_name�ַ��������ڴ��п�ռ64���ַ�
	int m_age;
};

void wr_test1()
{
	ofstream ofs("test1.txt", ios::out | ios::binary);//����ֱ��д������open�ǲ�
	ofs << "���!" << endl;
	//д�Զ����������͵��ļ�
	person p = { "Sincereh",24};
	ofs.write((const char *)&p, sizeof(p));//��ѵ�ַǿתΪconst char *

	ofs.close();
}

//�������ļ�������
//�������� read(char *ָ�� ,sizeof(���ݶ���));
//�����ַ�ָ��ָ���ڴ���һ�δ洢�ռ�

void rd_test1()
{
	ifstream ifs("test1.txt", ios::in|ios::binary );
	if (! ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	person p;
	ifs.read(( char *)&p, sizeof(p));
	cout << p.m_name << p.m_age << endl;
	ifs.close();
}




void main()
{
	wr_test1();
	rd_test1();
	system("pause");
}