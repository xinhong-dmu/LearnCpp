#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


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
		v1.push_back(3+i);
		v2.push_back(6+i);
	}
	//将小容器嵌套仅大容器中
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	//遍历大容器
	for (vector<vector<int>>::iterator i = v.begin(); i != v.end(); i++)
	{
		//*i现在是容器,可作为接下来遍历的容器名
		for (vector<int>::iterator j =(*i).begin(); j != (*i).end(); j++)
		{
			cout << *j <<" ";
		}
		cout << endl;
	}
}

void main()
{
	test10();


	system("pause");
}




