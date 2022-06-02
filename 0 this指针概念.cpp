#include<iostream>
#include<string>
using namespace std;
//通过this指针来区分到底是哪个对象调用的非静态成员函数
//this指针指向被调用的成员函数所属的对象 
//this指针的用途：
//1.当形参和成员变量同名时，用this指针来区分
//2.在类的非静态成员函数中返回对象本身，用return *this。此函数返回值为类——类名& 函数名(){}
class person
{public:
	person(int age)
	{
		this->age = age;//通过this->来解决同名问题
	}
	int age;
	person& personaddperson(person &p)//用引用的方式返回一个引用和调用，才是一直返回这个对象
		//如果返回的是个值，就相当于新建了一个对象，和之前对象的没关系
	{
		this->age += p.age;//将对象的年龄加上自身的年龄
		//this指向的是对象的指针，*this指向的是对象的本体
		return *this;//可以返回年龄的叠加操作，以便后续对该函数的不断调用
	}
};
void test00()
{
	person p1(18);
	cout << p1.age << endl;
}
void test01()
{
	person p2(20);
	person p3(30);
	//链式编程思，当函数返回值是本身时（采用引用方式返回），可对函数的连续调用
	p3.personaddperson(p2).personaddperson(p2).personaddperson(p2);
	cout <<"叠加年龄后p3的年龄："<<p3.age << endl;
}
int main()
{
	test00();
	test01();
	system("pause");
	return 0;
}