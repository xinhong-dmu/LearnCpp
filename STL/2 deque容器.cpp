#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
//deque是双端数组——既可以头插/删也可以尾插/删
//工作原理，内部有一个中控器，维护每段缓冲区的内容，缓冲区中存放真实数据
//deque容器的迭代器支持随机访问

//deque容器头插头删、尾插尾删
/*
deque<int>d0;
d.push_front(元素);
d.pop_front(元素);
d0.push_back(元素);
d0.pop_back(元素);
*/

//指定位置插入和删除;
//是位置迭代器，不是位置数（0123），也不是front（）或back（）
/*
deque<int>::iterator postion = d.begin();
position  +-=  123456;通过这样可以在任意位置进行元素操作
d.insert(d.位置迭代器,elem);指定位置迭代器()插入元素，并返回新的数据——左边=他——左边等于新的数据
d.insert(d.位置迭代器,n,elem);指定位置插入n个元素，无返回值——左边不能=他
d.insert(d.位置迭代器1,d.位置迭代器2,d.位置迭代器3);将d.位置迭代器23区间内的元素插入得到d.位置迭代器1位置，无返回值——左边不能=他
d.erase(d.位置迭代器);删除d.位置迭代器的元素，返回下一个元素位置——左边=他——左边等于下一个元素位置
									是位置迭代器，不是位置数（0123），也不是front（）或back（）
d.erase(d.位置迭代器1,d.位置迭代器2);删除位置迭代器12之间的元素，返回下一个元素位置——左边=他——左边等于下一个元素位置
;//是位置迭代器，不是位置数（0123），也不是front（）或back（）
d.clear();清空
*/

//deque容器遍历和vector一样
//for(deque<int>::iterator i = d.begin();i!=d.end();i++){}


/*当函数的形参为容器对象且想要只读防止修改时
返回值类型 函数名(const deque<数据类型>&容器对象)
{
函数体中的迭代器要修改为——deque<数据类型>::const_iterator  
}
*/

/*deque容器拷贝操作和vector一样
deque<int>d(10,100);10个100
deque<int>d1<d2>;拷贝1
d1 = d2;拷贝2
d1.assign(d2.begin(),d2.end());拷贝3
d1.assign(10,100);10个100
*/

/*deque容器的大小,区别于vector容器，deque无限扩展无容量
d.empty();//判断容器v是否为空，空返回1
d.size();//容器v中实际元素的个数
d.resize(int num);//重新制定容器v的长度为num，若容器v对象比之前长，则以默认值0重新填充容器v剩余位置
							//若容器v变短，末尾删除
d.resize(int num,元素);//重新制定容器v的长度为num，若容器v变长，则以元素重新填充位置
										//若容器v变短，末尾删除
*/

//deque 容器的数据存取
/*
d[位置]；利用[ ]访问容器元素
d.at(位置)；利用at(位置)访问元素
d.front();获取第一个元素
d.back();获取最后一个元素
*/

//deque从小到大排序
/*
sort(d.位置迭代器1,d.位置迭代器2);对区间内进行排序,前面不加容器对象
*/

//对于支持随机访问的迭代器的容器都可以利用sort算法——vector、deque