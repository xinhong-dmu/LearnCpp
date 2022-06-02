#include<iostream>
#include<string>
using namespace std;
class computer
{
public:
	virtual void brand() = 0;
	virtual ~computer(){	}
};
class cpu :public computer
{
public:
	cpu(string cpu_name)
	{
		this->cpu_name = new string(cpu_name);
	}
	void brand()
	{
		cout << "CPU品牌为：" << *cpu_name << endl;
	}
	~cpu()
	{
		if (cpu_name != NULL)
		{
			delete cpu_name;
			cpu_name = NULL;
		}
	}
	string *cpu_name;
};
class graphicscard :public computer
{
public:
	graphicscard(string g_name)
	{
		this->graphicscard_name = new string(g_name);
	}
	void brand()
	{
		cout << "显卡品牌为：" << *graphicscard_name << endl;
	}
	~graphicscard()
	{
		if (graphicscard_name != NULL)
		{
			delete graphicscard_name;
			graphicscard_name = 0;
		}
	}
	string  *graphicscard_name;
};
void brand()
{
	computer *cpu0 = new cpu("Inter");
	cpu0->brand();
	delete cpu0;
	computer *gra = new graphicscard("3060");
	gra->brand();
	delete gra;
}


int main()
{
	brand();

	system("pause");
	return 0;
}