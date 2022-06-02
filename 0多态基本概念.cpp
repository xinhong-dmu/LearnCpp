#include<iostream>
using namespace std;
/*
静态多态：函数重载与运算符重载。复用函数名。函数地址早绑定（编译阶段确定函数地址）
动态多态：派生类（继承的子类）和虚函数（virtual）实现运时多态。函数地址晚绑定（运行阶段确定函数地址）
*/

/*
动态多态满足3项条件：
1.有继承关系
2.子类中重写（除函数体中内容外外一模一样）父类中的重名虚函数，virtual可写可不写
3.在父类中写virtual虚函数
*/

//动态多态的使用——父类的指针（*地址）或引用（&变量）执行子类对象

//父类多了virtual类多了四个字节——虚函数(表)指针vfptr——指向虚函数表vftable(表内记录虚函数地址“&类名::虚函数”)
//子类的虚函数指针vfptr指向vftable(表内原本记录父类的虚函数地址“&父类::虚函数”)——当子类重写时，子类中的虚函数表内部就会将福尔利虚函数地址替换为子类的虚函数地址
class animal
{
public:
	virtual void speak()//在父类中写virtual虚函数,完成地址晚绑定，可以晚点的运行阶段绑定地址
	{
		cout << "动物在叫" << endl;
	}
};
class cat:public animal
{
public:
	void speak()
	{
		cout << "喵喵喵" << endl;
	}
};
class dog :public animal
{
public:
	void speak()
	{
		cout << "汪汪汪"<< endl;
	}
};
//地址早绑定导致在编译阶段就确定了函数的地址,所以执行的是父类animal中的speak成员函数
//若想执行子类中的speak成员函数，需晚绑定，即在运行阶段绑定
void speak(animal & animal)//多态的访问——父类的指针（*地址）或引用（&变量）指向子类对象
{
	animal.speak();//animal类中没有提前确定地址，
	//访问子类对象根据不同的地址，就不会调用父类中的成员函数了，而是调用子类中的成员函数
}

void test00()
{
	cat cat0;
	speak(cat0);//动态多态向函数中传子类对象
	dog dog0;
	speak(dog0);
}

//当父类中的虚函数后面根本不想调用时，可将其改为纯虚函数——virtual 返回值类型 函数名(参数列表)=0；
//当类中有纯虚函数，也可将此类称为抽象类

/*抽象类特点：
1.无法实例化对象——抽象类名 对象；报错——new 抽象类；报错
2.必须在子类中重写纯虚函数，否则该子类也是抽象类了，无法实例化对象——抽象子类名 对象；报错——new 抽象子类；报错
*/


int main()
{
	test00();

	system("pause");
	return 0;
}