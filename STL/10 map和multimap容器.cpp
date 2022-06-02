#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


//map中所有元素都是pair
//pair的第一个元素为键值key，起到索引作用，第二个元素为实值value
//所有元素都会根据元素的键值从小到大自动排序
//map/multimap容器都是关联式容器，底层用二叉树实现。map容器不允许重复的key值元素。

/*
map<int,int>m;
m.insert(pair<int,int>(key,value>);//插元素
*/

/*map容器的遍历
for(map<int,int>::iterator i = m.begin();i!=m.end();i++)
	{
		cout<<(*i).first<<i->second;
	}
*/

/*
m.size();
m.empty();
m1.swap(m2);
*/

/*
m.insert(pair<int,int>(key,value));
****m.insert(make_pair(key,value));***
m.clear();
m.erase(位置迭代器）；
m.erase(位置迭代器1,位置迭代器2)
m.erase(key);//删除可以对应的元素
*/

/*
m.find(key);//若有，返回key对应的位置迭代器，若不存在返回m.end();
if(pos!=set.end())
	{
		map<int,int>::iterator pos = m.find(key);//利用pos来接收返回的位置迭代器
		(*pos).first为键值,pos->second为实值
	}
m.count(key);//返回与该key值相同的元素个数int数据类型。map容器由于无重复，所以返回0或1
*/

class mysort
{
public:
	bool operator()(int a, int b)//()运算符重载就是仿函数,返回值为bool，是判断是否满足
	{
		return a > b;
	}
};

void sort()
{
	map<int, int,mysort>m;//mysort为仿函数
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(0, 0));
	for (map<int, int, mysort>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << "key= " << i->first << "  value= " << (*i).second << endl;
	}
}
//void main()
//{
//	sort();
//	system("pause");
//}