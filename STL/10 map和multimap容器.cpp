#include<iostream>
#include<map>
#include<algorithm>
using namespace std;


//map������Ԫ�ض���pair
//pair�ĵ�һ��Ԫ��Ϊ��ֵkey�����������ã��ڶ���Ԫ��Ϊʵֵvalue
//����Ԫ�ض������Ԫ�صļ�ֵ��С�����Զ�����
//map/multimap�������ǹ���ʽ�������ײ��ö�����ʵ�֡�map�����������ظ���keyֵԪ�ء�

/*
map<int,int>m;
m.insert(pair<int,int>(key,value>);//��Ԫ��
*/

/*map�����ı���
for(map<int,int>::iterator i = m.begin();i!=m.end();i++)
	{
		cout<<(*i).first<<i->second;
	}
*/

/*
m.size();
m.empty();
m1.swap(m2);
*/

/*
m.insert(pair<int,int>(key,value));
****m.insert(make_pair(key,value));***
m.clear();
m.erase(λ�õ���������
m.erase(λ�õ�����1,λ�õ�����2)
m.erase(key);//ɾ�����Զ�Ӧ��Ԫ��
*/

/*
m.find(key);//���У�����key��Ӧ��λ�õ��������������ڷ���m.end();
if(pos!=set.end())
	{
		map<int,int>::iterator pos = m.find(key);//����pos�����շ��ص�λ�õ�����
		(*pos).firstΪ��ֵ,pos->secondΪʵֵ
	}
m.count(key);//�������keyֵ��ͬ��Ԫ�ظ���int�������͡�map�����������ظ������Է���0��1
*/

class mysort
{
public:
	bool operator()(int a, int b)//()��������ؾ��Ƿº���,����ֵΪbool�����ж��Ƿ�����
	{
		return a > b;
	}
};

void sort()
{
	map<int, int,mysort>m;//mysortΪ�º���
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(0, 0));
	for (map<int, int, mysort>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << "key= " << i->first << "  value= " << (*i).second << endl;
	}
}
//void main()
//{
//	sort();
//	system("pause");
//}