#include<iostream>
#include<string>
using namespace std;
static int s = 1;
int a = 1;
const int b = 1;
int& test01()//int&��������ֵ��Ϊ����ֵ������������&����������
{//���õ����������������� &����=Ŀ�������
	int &c = a;//���ú󣬵����õ�ֵ�ı䣬�����õ�ֵҲ���ű䡣�����ı��������˸ı�
	return c;
}
int main()
{
	int & re = test01();//���õ����������������� &����=Ŀ�꺯����()
	re = 1000;//���ÿ���ֱ�Ӹ�ֵ������*ָ��,�൱�ڶ�a��ֵ
	cout << (int)&s << endl;//s�ĵ�ַ
	cout << (int)&a << endl;//a�ĵ�ַ
	cout << re << endl;//1000
	cout << a << endl;//1000
	system("pause");
	return 0;
}