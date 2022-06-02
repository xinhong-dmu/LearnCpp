#include<iostream>
#include<string>
using namespace std;

class cpu
{
public:
	virtual void caculate() = 0;
};
class graphics_card
{
public:
	virtual void display() = 0;
};
//������
class computer
{
public:
	computer(cpu* cpu, graphics_card* gra)
	{
		this->cpu_name = cpu;
		this->graphics_name = gra;
	}
	void work()//�������������
	{
		cpu_name->caculate();
		graphics_name->display();
	}
	~computer()//��֮���õ��ı����еĶ������ݣ����ڴ�����public�е����������ͷ�
	{
		if (cpu_name!=NULL) 
		{
			delete cpu_name;
			cpu_name = NULL;
		}
		if (graphics_name != NULL)
		{
			delete graphics_name;
			graphics_name = NULL;
		}
	}
private:
	cpu *cpu_name;
	graphics_card *graphics_name;
};
//�������
class Inter_cpu :public cpu
{
public:
	void caculate()
	{
		cout << "Inter'CPU " << endl;
	}
};
class Inter_graphics :public graphics_card
{
public:
	void display()
	{
		cout << "Inter'graphics card " << endl;
	}
};
class AMD_cpu :public cpu
{
public:
	void caculate()
	{
		cout << "AMD'CPU " << endl;
	}
};
class AMD_graphics_card :public graphics_card
{
public:
	void display()
	{
		cout << "AMD'graphics card " << endl;
	}
};

//��װ����
void assembly()
{//��һ̨�������
	cpu *c = new Inter_cpu;
	graphics_card *gc = new AMD_graphics_card;
	//��һ̨���Թ���
	cout << "��һ̨���Թ���" << endl;
	computer *com0 = new computer(c,gc);
	com0->work();
	//delete com0;//����̫low����computer�������������ͷ�
	//delete c;//�����ظ� �ͷ�
	//delete gc;

	//�ڶ�̨������װ+����
	cout << "�ڶ�̨���Թ���" << endl;
	computer *com1 = new computer(new Inter_cpu, new AMD_graphics_card);//ֱ����ָ������д���ָ�룬һ����λ
	com1->work();
	delete com1;
}

int main()
{
	assembly();

	system("pause");
	return 0;
}