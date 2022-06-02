#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



//string本质上是一个类
//char*是指针
//string类中封装了char*，管理这个字符串，是一个char*型的容器
//string内部封装了很多成员方法，例如find,copy,delete,insert...

//string构造函数 初始化
void test20()
{
	string s0;//默认构造
	const char* str = "hello world";//创建一个字符串
	string s2(str);//创建一个字符串对象并给默认值
	string s3(s2);//拷贝构造
	string s4(10,'q');//10个q的字符串，字符双引号不行就是单引号
}

//string赋值操作
void test21()
{
	string s0;  s0 = "s0";
	string s1("s1");
	string s2(s1);
	string s3;   s3.assign("s3");
	string s4;   s3.assign("012345",5);//输出前五个字符
	string s5;   s5.assign(5, 'c');
}

//string字符串末尾拼接字符串 ——  +=
void test22()
{
	string s0("I LIKE");
	s0 += "game";
	//不一一列举了
}

//string查找和替换
void test23()
{
	string s0("0123456789");
	s0.find("23");//返回首个“23”对应首个字符“2”的下标位置(从左往右)，若没有返回-1
	s0.rfind("23");//返回首个“23”对应首个字符“2”的下标位置(从右往左)，若没有返回-1
	
	s0.replace(2,5,"000");//将第3个字符起的n个字符串变为000。010003456789
	//把中间n个字符换为“”中的字符
}

//string字符串比较
void test24()
{
	string s0("123");
	string s1("456");
	s0.compare(s1);//相等返回0，比较ASCII码，s0>s1返回1，s0<s1返回-1
}

//string字符存取
void test25()
{
	string s0("123");
	s0[0] = '12';//利用[]调用字符串中的数读写
	s0.at(1)='00';//调用at()函数读写
}

//string插入和删除
void test26()
{
	string s0("0123");
	cout << s0.insert(1, "0") << endl;	//从第2个字符前开始插入字符，或者说从第1个字符后
	cout << s0.erase(1, 2) << endl;//从第2个字符起删除2个元素
}

//string子串——从字符串中获取想要的子串作为返回值
void test27()
{
	string s0("0123456789");
	s0.substr(0,3);//返回从第一个元素开始的三个元素
}





void main()
{


	system("pause");
}