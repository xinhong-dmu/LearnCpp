#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//Ա���ࡪ������������
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
//��ӡ����0
void print_staff0(multimap<int, staff>&mp)
{
	for (multimap<int, staff>::iterator i = mp.begin(); i != mp.end();i++)
	{
		if (i->first == 0)
		{
			cout << "Ա�����ţ�" << i->first << " Ա��������" << i->second.name << " Ա�����ʣ�" << i->second.gongzi << endl;
		}
	}
}
//��ӡ����1
void print_staff1(multimap<int, staff>&mp)
{
	for (multimap<int, staff>::iterator i = mp.begin(); i != mp.end(); i++)
	{
		if (i->first == 1)
		{
			cout << "Ա�����ţ�" << i->first << " Ա��������" << i->second.name << " Ա�����ʣ�" << i->second.gongzi << endl;
		}
	}
}
//��ӡ����2
void print_staff2(multimap<int, staff>&mp)
{
	for (multimap<int, staff>::iterator i = mp.begin(); i != mp.end(); i++)
	{
		if (i->first ==2)
		{
			cout << "Ա�����ţ�" << i->first << " Ա��������" << i->second.name << " Ա�����ʣ�" << i->second.gongzi << endl;
		}
	}
}
//����Ա������
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
		cout << "Ա����" << s.name <<  " ���ʣ�" << s.gongzi << endl;
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