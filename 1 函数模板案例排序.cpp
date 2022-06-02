#include<iostream>
using namespace std;
//从大到小排序

template<typename T>
//数组是不可以作为函数模板的形参的
void sort0(T array0[],int len)//数组形参必须有[]，才表示数组中的数。
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (array0[j] < array0[j + 1])
			{
				T temp = array0[j + 1];
				array0[j + 1] = array0[j];
				array0[j] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		cout << array0[i] << " " ;
	}
}


void test_char()
{
	char char_array[] = "assdffd";
	int len = sizeof(char_array) / sizeof(char_array[0]);
	sort0<char>(char_array,len);
}

void main()
{
	test_char();


	system("pause");
}