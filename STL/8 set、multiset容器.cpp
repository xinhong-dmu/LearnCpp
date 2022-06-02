#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
/*

set、multiset容器能够将元素自动升序排列——属于关联式容器,底层用红黑树实现
set不允许插入重复元素，插入元素时会返回知否成功
multiset允许有重复元素

只有s.insert()插入方式
判断元素是否插入成功
set<int>s;
s.insert(elem);
pair<set迭代器，bool> ret = s.insert(elem);
当ret.second == true时，成功，second时布尔类型。插入重复数据时失败
multiset<int>m;
m.insert(elem);


pair对组创建——成对出现的数据可以利用对组返回两个数据
方式一：
pair<type,type> p (value1,value2);
pair<string,int> p (string"name",24);
方式二：
paie<type,type>p=make_pair (value1,value2);
pair<string,int>p = make_pair("name",24):
利用p.first和p.second调用

注意set和multiset都是排好序的
s.clear();
s1=s2;
s.ersaer(位置迭代器)；//返回下一个元素位置的迭代器
s.erase(位置迭代器1,位置迭代器2)；//返回下一个元素位置的迭代器
s.erase(elem);//删除所有elem元素

set容器不允许重新指定容器大小
s.empty();
s,size();
s1.swap(s2);//交换两个容器

set容器的查找和统计
s.find(ekey);//若有key，返回该键的迭代器；若不存在，返回set.end();
m.count(key);//multiset统计key的个数
s.count(key);//返回0或1，因为set没有重复的



*/