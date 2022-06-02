#include<iostream>
#include<string>
using namespace std;
struct hero/*结构体里面是属性（形参）*/
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
				struct hero temp = hero_array[j + 1];/*完成数组中一组元素的交换*/
				hero_array[j + 1]= hero_array[j];
				hero_array[j] =temp;
			}
		}
	}
};

void print_hero(struct hero hero_array[], int num_hero)/*结构体对应数组传入一个函数的方法*/
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
		{"刘备",25},
		{"关羽",24},
		{"张飞",23},
		{"貂蝉",13},
		{"赵云",22},
	};
	int num_hero = sizeof(hero_array) / sizeof(hero_array[0]);
	bubble_sort(hero_array, num_hero);
	print_hero(hero_array, num_hero);

	system("pause");
	return 0;
}