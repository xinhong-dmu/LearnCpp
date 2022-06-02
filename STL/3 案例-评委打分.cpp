#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;


//选手类
class xuanshou
{
public:
	xuanshou(string name, double arg_score)
	{
		this->arg_score = arg_score;
		this->name = name;
	}
	string name;
	double arg_score;
};

//选手名单打印
void printv(vector<xuanshou>&v)
{
	for (vector<xuanshou>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << (*i).name << "：" << (*i).arg_score << endl;
	}
}

//老评委给选手打分
void set_score(vector<xuanshou>&v)
{
	for (vector<xuanshou>::iterator i = v.begin(); i != v.end(); i++)
	{
		deque<int>d;
		int score = 0;//rand()%(n+1)——从0-n
		for (int i = 0; i < 10;i++)
		{
			d.push_back(score);
			score++; 
		}
		for (deque<int>::iterator i = d.begin(); i != d.end(); i++)
		{
			cout <<*i<< " " ;
		}
		if (d.empty() == 1)
		{
			cout << "为空" << endl;
		}
		else
		{
			sort(d.begin(), d.end());
			d.pop_back();
			d.pop_front();
			int sum = 0;
			for (deque<int>::iterator i = d.begin(); i != d.end(); i++)
			{
				sum += *i;
			}
			i->arg_score = sum / d.size();
			cout << "选手" << i->name << "的平均得分为：" << i->arg_score << endl;
		}
	}
}



//初始选手分数打印
void printd(deque<int>&d)
{
	for (deque<int>::iterator i = d.begin(); i != d.end(); i++)
	{
		cout << (*i) << " ";
	}
}
//创建选手
void chaungjianxuanshou(vector<xuanshou>&v)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameseed[i];
		double arg_score = 0;
		xuanshou x(name, arg_score);
		v.push_back(x);
	}
}

