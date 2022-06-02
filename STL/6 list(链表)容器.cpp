#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

//每个节点包含指针域与数据域
//每个节点的指针域既包含上一个节点的地址，也包含下一个节点的地址
//将不连续内存中的数据通过节点的指针域（用于维护下一个节点的地址）进行联系
//最后一个数据的节点的指针域还指向第一个节点位置(循环)，第一节点同时也指向最后一个节点位置(循环)
//链表可以对任意位置进行快速插入或删除元素(包括头尾插删)，其他容器都是尾插或尾删
//链表存储方式不为连续的内存空间，所以不可以跳跃式访问，list的迭代器只支持前移或后移，属于双向迭代器

/*list容器的插入和删除
l.push_front(elem);
l.pop_front(elem);
l.push_back(elem);
l.pop_back(elem);
l.insert(pos,elem);//并返回新元素的位置迭代器(还是pos)，插入单个元素返回新位置，可以作为右值
l.insert(pos,n,elem);//无返回值，插多个元素无返回值
l.insert(pos,位置迭代器1，位置迭代器2);//在pos插入1-2区间的元素无返回值
l.clear();
l.erase(位置迭代器1，位置迭代器2);//删除1-2内元素，无返回值
l.erase(位置迭代器);//是位置迭代器，不是位置数（0123），也不是front（）或back（），返回新位置
l.remove(elem);//删除所有elem
*/

/*list容器的数据存取，不支持随机访问——不支持at()、l[ ]、rand()%n+1
l.front();//返回第一个元素
l.back();//返回最后一个元素
*/

/*list容器的反转和排序，所有不支持随机访问迭代器的容器不支持标准算法——sort()、
不支持随机访问迭代器的容器内部会提供成员函数的算法
l.reverse();//反转链表
l.sort();//链表由小到大排序，前需要有l.  ，其他容器的算法(vector/deque/)可以作全局函数

比较自定义数据类型：
bool func_sort(类名 &对象1，类名 &对象2)   //必须返回布尔类型的数据，为后续调用函数的判断条件
{
	return 想要的对象1与对象2的关系；//加减乘除大小等
}
l.sort(func_sort);

*/

/*list容器
list<数据类型>l;
l.assign(迭代器1，迭代器2)；
l.assign(n,elem);
l1 = l2;
l1.swap(l2);交换
*/

/*
l.size();//返回容器中元素个数
l.empty();
l.resize(n);//重新制定容器v的长度为num，若容器v对象比之前长，则以默认值0重新填充容器v剩余位置
							//若容器v变短，末尾删除
l.resize(n,enem);/重新制定容器v的长度为num，若容器v变长，则以元素重新填充位置
									//若容器v变短，末尾删除
*/




