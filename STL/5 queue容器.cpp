#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

/*stack容器先入push()先出pop()，新的的元素只能从栈尾部进来，
queue旧的数据只能从栈头部出去——只能对栈头栈尾元素操作
和stack容器一样不可遍历；需要依次将元素从栈头弹出

queue<数据类型>q;
q.push(elem);//压入队尾
q.pop();//将队头元素弹出
q.back();//获取队尾元素
q.front();//获取队头元素
q.empty();
q.size();
*/