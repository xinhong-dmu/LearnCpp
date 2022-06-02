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
//电脑类
class computer
{
public:
	computer(cpu* cpu, graphics_card* gra)
	{
		this->cpu_name = cpu;
		this->graphics_name = gra;
	}
	void work()//让零件工作起来
	{
		cpu_name->caculate();
		graphics_name->display();
	}
	~computer()//在之后用到的本类中的堆区数据，可在此类中public中的析构函数释放
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
//零件厂商
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

//组装电脑
void assembly()
{//第一台电脑零件
	cpu *c = new Inter_cpu;
	graphics_card *gc = new AMD_graphics_card;
	//第一台电脑工作
	cout << "第一台电脑工作" << endl;
	computer *com0 = new computer(c,gc);
	com0->work();
	//delete com0;//这种太low，在computer的析构函数中释放
	//delete c;//不能重复 释放
	//delete gc;

	//第二台电脑组装+工作
	cout << "第二台电脑工作" << endl;
	computer *com1 = new computer(new Inter_cpu, new AMD_graphics_card);//直接在指针变量中创建指针，一步到位
	com1->work();
	delete com1;
}

int main()
{
	assembly();

	system("pause");
	return 0;
}