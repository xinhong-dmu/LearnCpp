#include<iostream>
using namespace std;
//�Ӵ�С����

template<typename T>
//�����ǲ�������Ϊ����ģ����βε�
void sort0(T array0[],int len)//�����βα�����[]���ű�ʾ�����е�����
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