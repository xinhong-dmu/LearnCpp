#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//员工类——姓名、工资
class staff
{
public:
	staff(string name,int gongzi )
	{
		this->gongzi = gongzi;
		this->name = name;
	}
	string name;
	int gongzi;
};
//打印部门0
void print_staff0(multimap<int, staff>&mp)
{
	for (multimap<int, staff>::iterator i = mp.begin(); i != mp.end();i++)
	{
		if (i->first == 0)
		{
			cout << "员工部门：" << i->first << " 员工姓名：" << i->second.name << " 员工工资：" << i->second.gongzi << endl;
		}
	}
}
//打印部门1
void print_staff1(multimap<int, staff>&mp)
{
	for (multimap<int, staff>::iterator i = mp.begin(); i != mp.end(); i++)
	{
		if (i->first == 1)
		{
			cout << "员工部门：" << i->first << " 员工姓名：" << i->second.name << " 员工工资：" << i->second.gongzi << endl;
		}
	}
}
//打印部门2
void print_staff2(multimap<int, staff>&mp)
{
	for (multimap<int, staff>::iterator i = mp.begin(); i != mp.end(); i++)
	{
		if (i->first ==2)
		{
			cout << "员工部门：" << i->first << " 员工姓名：" << i->second.name << " 员工工资：" << i->second.gongzi << endl;
		}
	}
}
//创建员工对象
void set_staff()
{
	multimap<int, staff>m;
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "staff";
		name += nameseed[i];
		int gongzi = rand() % 5000;
		staff s(name, gongzi);
		cout << "员工：" << s.name <<  " 工资：" << s.gongzi << endl;
		int bumen = rand() % 3;
		m.insert(make_pair(bumen, s));
	}
	print_staff0(m);
	print_staff1(m);
	print_staff2(m);
}

//
//void main()
//{
//	set_staff();
//
//
//	system("pause");
//}