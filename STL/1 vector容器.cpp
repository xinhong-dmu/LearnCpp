#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//vector区别于数组是静态空间，而vector可以动态扩展。但并不是在原有空间续接新空间，而是将原数据拷贝到新空间，释放源空间
//vector的迭代器是支持随机访问的迭代器——vector<数据类型>::iterator

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
	for_each(v.begin(), v.end(), my_print);//for_each(起始迭代器，结束迭代器，调用的函数)
}


//vector存放自定义数据类型
class person
{
public:
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
		cout << (*i).name << i->age << endl;//(*i)的数据类型为<>中的
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
		cout << (**i).name << (*i)->age << endl;//(*i)是person指针，(**i)是person指针*i的解引用
	}

}

/*
vector容器的默认构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector<数据类型>(v.begin(),v.end());//将前闭后开的区间中元素拷贝给本身，因为end()指向的是数组最后一位的后一位——现在容器0对象v就是这串数组了
vector<数据类型>(n, 元素);//将n个元素拷贝给本身
vector<数据类型>(对象);//拷贝
*/
void print0(vector<int>&v)
{
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << (*i) << " ";
	}
}

//vector赋值操作
void test30()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print0(v1);
	//复制赋值1
	vector<int>v2;
	v2 = v1;
	//assign赋值2
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	//n个元素赋值给容器对象v4
	vector<int>v4;
	v4.assign(5, 10);//5个10
}

/*vector容器的容量和大小
v.empty();//判断容器v是否为空，空返回1
v.capacity();//容器v的容量，最大可容纳元素个数，若超出容量，会动态扩展一个新的更大的区间
v.size();//容器v中实际元素的个数
v.resize(int num);//重新制定容器v的长度为num，若容器v对象比之前长，则以默认值0重新填充容器v剩余位置
							//若容器v变短，末尾删除
v.resize(int num,元素);//重新制定容器v的长度为num，若容器v变长，则以元素重新填充位置
									//若容器v变短，末尾删除
*/

//vector的插入和删除
/*
v.push_back(元素);//尾插
v.pop_back(元素);//尾删
v.insert(v.位置迭代器,元素);//指定位置插入元素。v.rend(),v.begin(),v.rbegin(),v.end();//是位置迭代器，不是位置数（0123），也不是front（）或back（）
v.insert(v.位置迭代器,n,元素);//指定位置插入n个元素
v.erase(v.位置迭代器);//删除指定位置元素;//是位置迭代器，不是位置数（0123），也不是front（）或back（）
v.erase(v.位置迭代器，v.位置迭代器);//删除闭区间内元素
v.clear();//全删
*/

//vector 容器的数据存取
/*
v[位置]；利用[ ]访问容器元素
v.at(位置)；利用at(位置)访问元素
v.front();获取第一个元素
v.back();获取最后一个元素
*/

//begin()和end()是迭代器，front()和back()是引用该位置的元素

//实现两个容器中的元素互换
/*
v1.swap(v2);
//用途:
1.巧用swap可以收缩内存空间
*/

//vector预留空间——提前预留空间，减少vector在动态扩展时的扩展次数
/*
v1.reserve(长度);//预留长度，预留位置不初始化，元素不可访问
*/

//vector容器嵌套容器
void test10()
{
	vector<vector<int>>v;
	//先创建小容器
	vector<int>v0;
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 3; i++)
	{
		v0.push_back(i);
		v1.push_back(3 + i);
		v2.push_back(6 + i);
	}
	//将小容器嵌套仅大容器中
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	//遍历大容器
	for (vector<vector<int>>::iterator i = v.begin(); i != v.end(); i++)
	{
		//*i现在是容器,可作为接下来遍历的容器名
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}