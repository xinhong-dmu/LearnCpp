#include<iostream>
#include<string>
using namespace std;
struct hero/*�ṹ�����������ԣ��βΣ�*/
{
	string name;
	int age;
};

void bubble_sort(struct hero hero_array[], int num_hero)
{
	for (int i = 0; i < num_hero - 1; i++)
	{
		for (int j = 0; j < num_hero - i - 1; j++)
		{
			if (hero_array[j].age > hero_array[j + 1].age)
			{
				struct hero temp = hero_array[j + 1];/*���������һ��Ԫ�صĽ���*/
				hero_array[j + 1]= hero_array[j];
				hero_array[j] =temp;
			}
		}
	}
};

void print_hero(struct hero hero_array[], int num_hero)/*�ṹ���Ӧ���鴫��һ�������ķ���*/
{
	for (int i = 0; i < num_hero - 1; i++)
	{
		cout <<"name:"<< hero_array[i].name<<"   age:" << hero_array[i].age<<endl;
	}
}


int main()
{
	struct hero hero_array[5] =
	{
		{"����",25},
		{"����",24},
		{"�ŷ�",23},
		{"����",13},
		{"����",22},
	};
	int num_hero = sizeof(hero_array) / sizeof(hero_array[0]);
	bubble_sort(hero_array, num_hero);
	print_hero(hero_array, num_hero);

	system("pause");
	return 0;
}