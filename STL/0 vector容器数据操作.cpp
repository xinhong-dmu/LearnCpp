#include<iostream>
#include<string>
#include<vector>//STL每个数据类型都要包含头文件
#include<algorithm>

using namespace std;

//容器中最常用的容器为vector，可以理解为数组
//利用vector存放内置数据类型：
//容器——vector
//算法——for_each  遍历算法
//迭代器——vector<int>::itreator

void my_print(int a)
{
	cout << a << endl;
}

void test00()
{
	//创建了一个vector容器，数组
	vector<int> v;
	//向容器中插入数据
	v.push_back(333);//push_back()为自带的向容器中插入的函数
	v.push_back(444);
	v.push_back(555);
	//第一种遍历方式
	//通过迭代器访问容器中的数据
	vector<int>::iterator it_begin = v.begin();//begin()为起始迭代器，指向容器中的第一个元素
	vector<int>::iterator it_end = v.end();//end()结束迭代器，指向容器最后一个元素的下一个位置
	//迭代器就是指针v.begin()、v.end()
	while (it_begin != it_end)
	{
		cout << *it_begin << endl;//可暂时将迭代器当做指针使用
		it_begin++;
	}
	//!!!!!!!!!!第二种遍历方式!!!!!!!!!!!!!!!!
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;//*it的数据类型和<>里的一样,迭代器就是指针v.begin()、v.end()
	}
	//第三种遍历方式——利用STL提供便利算法——for_each
	for_each(v.begin(), v.end(),my_print);//for_each(起始迭代器，结束迭代器，调用的函数)
}


//vector存放自定义数据类型
class person
{public:
	person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}
	string name;
	int age;
};
void test01()
{
	person p1("aaa", 1);
	person p2("bbb", 2);
	person p3("ccc", 3);
	vector<person>v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	for (vector<person>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout <<(*i).name<<i->age << endl;//(*i)的数据类型为<>中的
		//i就是迭代器就是指针，指针方式调用->成员
	}
}

//存放自定义数据类型为指针
void test02()
{
	person p1("aaa", 1);
	person p2("bbb", 2);
	person p3("ccc", 3);
	vector<person*>v;//存放的数据类型为指针
	v.push_back(&p1);//通过取指针地址获取对象
	v.push_back(&p2);
	v.push_back(&p3);
	for (vector<person*>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout <<(**i).name << (*i)->age << endl;//(*i)是person指针，(**i)是person指针*i的解引用
	}

}

void main()
{
	test00();
	test01();
	test02();

	system("pause");
}