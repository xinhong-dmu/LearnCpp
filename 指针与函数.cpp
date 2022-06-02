#include<iostream>
using namespace std;
#include"swap1.h"
#include"swap2.h"
void swap1(int a1, int b1)
{
	int temp = a1;
	a1 = b1;
	b1 = temp;
	cout << "a1=" << a1 << endl;/*形参发生改变*/
	cout << "b1=" << b1 << endl;
}

void swap2(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << "*p1=" << *p1 << endl;/*形参实参都发生改变*/
	cout << "*p2=" << *p2 << endl;
}



int main1()
{
	//值传递，实参不改变，只改变形参
	int num1 = 1;
	int num2 = 2;
	swap1(num1, num2);
	cout << "num1=" << num1 << endl;/*实参不发生改变*/
	cout << "num2=" << num2 << endl;

	//地址传递，改变了形参和实参
	int num3 = 3;
	int num4 = 4;
	swap2(&num3, &num4);
	cout << "num3=" << num3 << endl;/*实参也发生改变*/
	cout << "num4=" << num4 << endl;

	system("pause");
	return 0;
}