#include<iostream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;
//按年龄升序；年龄一样，按身高降序

class person
{
public:
	person(string name, int age, double height)
	{
		this->age = age;
		this->height = height;
		this->name = name;
	}
	string name;
	int age;
	double height;
};

bool sort_age(person &p1, person &p2)
{
	if (p1.age == p2.age)//多重条件判断时，把特殊情况放前
	{
			return p1.height > p2.height;
	}
	else
	{
		return p1.age < p2.age;
	}
}

void main()
{
	person p0("p0", 25, 170);
	person p1("p1", 22, 172);
	person p2("p2", 22, 173);
	person p3("p3", 22, 171);
	list<person>l;
	l.insert(l.begin(), p0);
	l.push_back(p0);
	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	cout << "排序前"<<endl;
	for (list<person>::iterator i = l.begin(); i != l.end(); i++)
	{
		cout << (*i).name << " " << (*i).age << " " << (*i).height << endl;
	}
	cout << endl;
	cout << "排序后" << endl;
	l.sort(sort_age);
	for (list<person>::iterator i = l.begin(); i != l.end(); i++)
	{
		cout << (*i).name <<" "<< (*i).age << " " << (*i).height << endl;
	}
	system("pause");
}