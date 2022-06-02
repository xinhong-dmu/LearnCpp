#include<iostream>
#include<string>
using namespace std;
class phone//被包含的类
{
public:
	phone( string name)
	{
		phone_name=name;

	}
	~phone(){}//后析构子类
	string phone_name;
};

class person//包含其他类的类
{
public:
	person(string name,string phname):person_name(name),ph_name(phname)
	{
	}
	~person() {  }//先析构大的类
	string person_name;
	phone  ph_name;
};

void test05()
{
	person p("Sincereh", "huawei");//创建一个包含其他类的类的对象，就可以调用其他类的成员
	cout << p.person_name << " bought " << p.ph_name.phone_name<< endl;//调用方式——包含其他类的类的对象.其他类的名.成员
}

int main()
{
	test05();
	system("pause");
	return 0;
}