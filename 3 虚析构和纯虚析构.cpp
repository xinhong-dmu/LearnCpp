#include<iostream>
#include<string>
using namespace std;
//����������г�Ա���ٵ��˶�������ô����ָ�����ͷ�ʱ�޷�ʹ���������������,�����б���д������
//������������������е�����������дΪ��������������ʵ�������󣩻������������������࣬����ʵ��������
//����ֻ����һ��
//���߶���Ҫ����ʵ��

class animal
{
public:
	virtual void speak() = 0;
	//�����н�����������Ϊ����������ֹ�����г��ֶ�ȡ���ݣ������ڴ�й©
	//���������ͷ���������ǲ��ɾ�������
	virtual ~animal() {}
	//��������
	//virtual ~animal() = 0;����ʵ����ȫ�ֺ�����д
};
/*
animal::~animal()
{
	���дһ��
}
*/
class cat :public animal
{
public:
	cat(string name)
	{
		m_name = new string(name);//ָ�� = new ָ����������ͣ���������ָ��= �����¿��ٵ�ָ��
	}
	void speak()
	{
		cout <<*m_name<< "��������" << endl;
	}
	~cat() 
	{
		if (m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
		}
	}
	//����ָ��������ʱ������������е�������������������������ж������ݣ��ͻ��ڴ�й¶
	//����������������ൽ������������Ϊ������������ǰ��+virtual
	string *m_name;//������������Ϊ�ַ�����ָ��
};
//��̬��ָ����÷���һ
void test30()
{
	animal*cat0 = new cat("Tom");//������*ָ�� = new ���๹�캯��(��Ա����)������Ĭ�Ϲ��캯��ʱ����Ҫ��Ĭ�ϲ���
	cat0->speak();//ָ��->�����Ա
	delete cat0;//deleteָ��
}
//��̬��ָ����÷�����
void speak(animal*a)//��дһ������Ϊ����ָ���ȫ�ֺ���
{
	a->speak();//ָ��ָ�������Ա����
	delete a;//ɾ��ָ��
}
void test31()
{
	speak(new cat("��è"));//����ָ���̬ȫ�ֺ����ķ���Ϊ����ȫ�ֺ�����(new �������)
}


int main()
{
	test30();
	test31();
	system("pause");
	return 0;
}