#include<iostream>
#include<string>
using namespace std;
static int s = 1;
int a = 1;
const int b = 1;
int& test01()//int&：将引用值作为返回值——数据类型&函数名（）
{//引用的声明——数据类型 &别名=目标变量名
	int &c = a;//引用后，当引用的值改变，被引用的值也跟着变。别名改变就是这个人改变
	return c;
}
int main()
{
	int & re = test01();//引用的声明——数据类型 &别名=目标函数名()
	re = 1000;//引用可以直接赋值，无需*指针,相当于对a赋值
	cout << (int)&s << endl;//s的地址
	cout << (int)&a << endl;//a的地址
	cout << re << endl;//1000
	cout << a << endl;//1000
	system("pause");
	return 0;
}