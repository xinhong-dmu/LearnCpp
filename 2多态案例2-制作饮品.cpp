#include<iostream>
#include<string>
using namespace std;

class abstract_drinking//必要步骤
{public:
	virtual void boil() = 0;	//煮水
	virtual void brew() = 0;	//冲泡
	virtual void pour() = 0;//倒入杯中
	virtual void put_sth() = 0;//添加辅料
	 void make_drink()
	{
		boil();
		brew();
		pour();
		put_sth();
	}
};
//制作茶叶
class tea:public abstract_drinking
{public:
	void boil() 
	{
		cout << "煮十分钟" << endl;
	};
	void brew()
	{
		cout << "冲茶叶" << endl;
	};
	void pour()
	{
		cout << "到茶杯里" << endl;
	};
	void put_sth()
	{
		cout << "加茶叶" << endl;
	};
	void make_drink()
	{
		boil(); 
		brew(); 
		pour(); 
		put_sth();
	}
};
//制作咖啡
class coffee:public abstract_drinking
{
public:
	void boil()
	{
		cout << "煮20分钟" << endl;
	};
	void brew()
	{
		cout << "煮咖啡豆" << endl;
	};
	void pour()
	{
		cout << "到咖啡杯里" << endl;
	};
	void put_sth()
	{
		cout << "加糖" << endl;
	};
	void make_drink()
	{
		boil();
		brew();
		pour();
		put_sth();
	}
};
//引用方式 访问多态
void make_tea(abstract_drinking & drink)
{
	drink.make_drink();
}
void test20()
{
	cout << " —————————————————" << endl;
	tea t0;
	make_tea(t0);
}
//指针方式 访问多态
void make_coffee(abstract_drinking*d)//父类的指针指向子类成员对象
{
	d->make_drink();
	delete d;//实际上是在这个全局函数中使用的new堆区指针
}
void test21()
{
	cout << " —————————————————" << endl;
	make_coffee(new coffee);//父类的指针指向新开辟new的子类对象
	//delete coffee;实际上不在全局函数中使用的new堆区指针，而且需要删除的是堆区指针，coffee是对象
}

int main()
{
	cout << " —————————————————" << endl;
	cout << "|  欢迎光临Sincereh'Beverage Shop   |" << endl;
	cout << " —————————————————" << endl << endl;
	test20();
	test21();

	system("pause");
	return 0;
}