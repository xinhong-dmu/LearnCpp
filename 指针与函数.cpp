#include<iostream>
using namespace std;
#include"swap1.h"
#include"swap2.h"
void swap1(int a1, int b1)
{
	int temp = a1;
	a1 = b1;
	b1 = temp;
	cout << "a1=" << a1 << endl;/*�βη����ı�*/
	cout << "b1=" << b1 << endl;
}

void swap2(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << "*p1=" << *p1 << endl;/*�β�ʵ�ζ������ı�*/
	cout << "*p2=" << *p2 << endl;
}



int main1()
{
	//ֵ���ݣ�ʵ�β��ı䣬ֻ�ı��β�
	int num1 = 1;
	int num2 = 2;
	swap1(num1, num2);
	cout << "num1=" << num1 << endl;/*ʵ�β������ı�*/
	cout << "num2=" << num2 << endl;

	//��ַ���ݣ��ı����βκ�ʵ��
	int num3 = 3;
	int num4 = 4;
	swap2(&num3, &num4);
	cout << "num3=" << num3 << endl;/*ʵ��Ҳ�����ı�*/
	cout << "num4=" << num4 << endl;

	system("pause");
	return 0;
}