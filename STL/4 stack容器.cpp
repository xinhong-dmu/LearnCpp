#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//stack容器只能从栈顶进出（先入.push()后出.pop()），先进去的放在了栈底；
//只可对栈顶元素操作
//不可遍历，只能从栈头依次弹出查看元素

/*
stack<数据类型>s;
s.push(elem);//入栈
s.empty();//查看是否为空，空返回1
s.top();//查看栈顶
s.pop;//弹出栈顶元素
s.size();//栈中元素个数
*/