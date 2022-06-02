#include<iostream>
#include<string>
using namespace std;
//如果子类中有成员开辟到了堆区，那么父类指针在释放时无法使用子类的析构代码,父类中必须写虚析构
//解决方法——将父类中的析构函数改写为虚析构函数（可实例化对象）或纯虚析构函数（抽象类，不可实例化对象）
//二者只能有一个
//二者都需要代码实现

class animal
{
public:
	virtual void speak() = 0;
	//父类中将析构函数改为虚析构，防止子类中出现堆取数据，导致内存泄漏
	//即，父类释放子类对象是不干净的问题
	virtual ~animal() {}
	//纯虚析构
	//virtual ~animal() = 0;代码实现在全局函数中写
};
/*
animal::~animal()
{
	随便写一个
}
*/
class cat :public animal
{
public:
	cat(string name)
	{
		m_name = new string(name);//指针 = new 指针的数据类型（变量）；指针= 堆区新开辟的指针
	}
	void speak()
	{
		cout <<*m_name<< "在喵喵喵" << endl;
	}
	~cat() 
	{
		if (m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
		}
	}
	//父类指针在析构时不会调用子类中的析构函数，导致子类中如果有堆区数据，就会内存泄露
	//解决方法——将父类到的析构函数改为虚析构函数，前面+virtual
	string *m_name;//创建数据类型为字符串的指针
};
//多态的指针调用方法一
void test30()
{
	animal*cat0 = new cat("Tom");//父类名*指针 = new 子类构造函数(成员变量)，不是默认构造函数时可能要加默认参数
	cat0->speak();//指针->子类成员
	delete cat0;//delete指针
}
//多态的指针调用方法二
void speak(animal*a)//先写一个变量为父类指针的全局函数
{
	a->speak();//指针指向所需成员函数
	delete a;//删除指针
}
void test31()
{
	speak(new cat("蓝猫"));//调用指针多态全局函数的方法为——全局函数名(new 子类对象)
}


int main()
{
	test30();
	test31();
	system("pause");
	return 0;
}