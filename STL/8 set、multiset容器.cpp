#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
/*

set��multiset�����ܹ���Ԫ���Զ��������С������ڹ���ʽ����,�ײ��ú����ʵ��
set����������ظ�Ԫ�أ�����Ԫ��ʱ�᷵��֪��ɹ�
multiset�������ظ�Ԫ��

ֻ��s.insert()���뷽ʽ
�ж�Ԫ���Ƿ����ɹ�
set<int>s;
s.insert(elem);
pair<set��������bool> ret = s.insert(elem);
��ret.second == trueʱ���ɹ���secondʱ�������͡������ظ�����ʱʧ��
multiset<int>m;
m.insert(elem);


pair���鴴�������ɶԳ��ֵ����ݿ������ö��鷵����������
��ʽһ��
pair<type,type> p (value1,value2);
pair<string,int> p (string"name",24);
��ʽ����
paie<type,type>p=make_pair (value1,value2);
pair<string,int>p = make_pair("name",24):
����p.first��p.second����

ע��set��multiset�����ź����
s.clear();
s1=s2;
s.ersaer(λ�õ�����)��//������һ��Ԫ��λ�õĵ�����
s.erase(λ�õ�����1,λ�õ�����2)��//������һ��Ԫ��λ�õĵ�����
s.erase(elem);//ɾ������elemԪ��

set��������������ָ��������С
s.empty();
s,size();
s1.swap(s2);//������������

set�����Ĳ��Һ�ͳ��
s.find(ekey);//����key�����ظü��ĵ��������������ڣ�����set.end();
m.count(key);//multisetͳ��key�ĸ���
s.count(key);//����0��1����Ϊsetû���ظ���



*/