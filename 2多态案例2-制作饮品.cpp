#include<iostream>
#include<string>
using namespace std;

class abstract_drinking//��Ҫ����
{public:
	virtual void boil() = 0;	//��ˮ
	virtual void brew() = 0;	//����
	virtual void pour() = 0;//���뱭��
	virtual void put_sth() = 0;//��Ӹ���
	 void make_drink()
	{
		boil();
		brew();
		pour();
		put_sth();
	}
};
//������Ҷ
class tea:public abstract_drinking
{public:
	void boil() 
	{
		cout << "��ʮ����" << endl;
	};
	void brew()
	{
		cout << "���Ҷ" << endl;
	};
	void pour()
	{
		cout << "���豭��" << endl;
	};
	void put_sth()
	{
		cout << "�Ӳ�Ҷ" << endl;
	};
	void make_drink()
	{
		boil(); 
		brew(); 
		pour(); 
		put_sth();
	}
};
//��������
class coffee:public abstract_drinking
{
public:
	void boil()
	{
		cout << "��20����" << endl;
	};
	void brew()
	{
		cout << "�󿧷ȶ�" << endl;
	};
	void pour()
	{
		cout << "�����ȱ���" << endl;
	};
	void put_sth()
	{
		cout << "����" << endl;
	};
	void make_drink()
	{
		boil();
		brew();
		pour();
		put_sth();
	}
};
//���÷�ʽ ���ʶ�̬
void make_tea(abstract_drinking & drink)
{
	drink.make_drink();
}
void test20()
{
	cout << " ����������������������������������" << endl;
	tea t0;
	make_tea(t0);
}
//ָ�뷽ʽ ���ʶ�̬
void make_coffee(abstract_drinking*d)//�����ָ��ָ�������Ա����
{
	d->make_drink();
	delete d;//ʵ�����������ȫ�ֺ�����ʹ�õ�new����ָ��
}
void test21()
{
	cout << " ����������������������������������" << endl;
	make_coffee(new coffee);//�����ָ��ָ���¿���new���������
	//delete coffee;ʵ���ϲ���ȫ�ֺ�����ʹ�õ�new����ָ�룬������Ҫɾ�����Ƕ���ָ�룬coffee�Ƕ���
}

int main()
{
	cout << " ����������������������������������" << endl;
	cout << "|  ��ӭ����Sincereh'Beverage Shop   |" << endl;
	cout << " ����������������������������������" << endl << endl;
	test20();
	test21();

	system("pause");
	return 0;
}