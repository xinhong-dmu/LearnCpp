#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//vector�����������Ǿ�̬�ռ䣬��vector���Զ�̬��չ������������ԭ�пռ������¿ռ䣬���ǽ�ԭ���ݿ������¿ռ䣬�ͷ�Դ�ռ�
//vector�ĵ�������֧��������ʵĵ���������vector<��������>::iterator

//��������õ�����Ϊvector���������Ϊ����
//����vector��������������ͣ�
//��������vector
//�㷨����for_each  �����㷨
//����������vector<int>::itreator

void my_print(int a)
{
	cout << a << endl;
}

void test00()
{
	//������һ��vector����������
	vector<int> v;
	//�������в�������
	v.push_back(333);//push_back()Ϊ�Դ����������в���ĺ���
	v.push_back(444);
	v.push_back(555);
	//��һ�ֱ�����ʽ
	//ͨ�����������������е�����
	vector<int>::iterator it_begin = v.begin();//begin()Ϊ��ʼ��������ָ�������еĵ�һ��Ԫ��
	vector<int>::iterator it_end = v.end();//end()������������ָ���������һ��Ԫ�ص���һ��λ��
										   //����������ָ��v.begin()��v.end()
	while (it_begin != it_end)
	{
		cout << *it_begin << endl;//����ʱ������������ָ��ʹ��
		it_begin++;
	}
	//!!!!!!!!!!�ڶ��ֱ�����ʽ!!!!!!!!!!!!!!!!
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;//*it���������ͺ�<>���һ��,����������ָ��v.begin()��v.end()
	}
	//�����ֱ�����ʽ��������STL�ṩ�����㷨����for_each
	for_each(v.begin(), v.end(), my_print);//for_each(��ʼ�����������������������õĺ���)
}


//vector����Զ�����������
class person
{
public:
	person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}
	string name;
	int age;
};
void test01()
{
	person p1("aaa", 1);
	person p2("bbb", 2);
	person p3("ccc", 3);
	vector<person>v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	for (vector<person>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << (*i).name << i->age << endl;//(*i)����������Ϊ<>�е�
											//i���ǵ���������ָ�룬ָ�뷽ʽ����->��Ա
	}
}

//����Զ�����������Ϊָ��
void test02()
{
	person p1("aaa", 1);
	person p2("bbb", 2);
	person p3("ccc", 3);
	vector<person*>v;//��ŵ���������Ϊָ��
	v.push_back(&p1);//ͨ��ȡָ���ַ��ȡ����
	v.push_back(&p2);
	v.push_back(&p3);
	for (vector<person*>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << (**i).name << (*i)->age << endl;//(*i)��personָ�룬(**i)��personָ��*i�Ľ�����
	}

}

/*
vector������Ĭ�Ϲ��캯��
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector<��������>(v.begin(),v.end());//��ǰ�պ󿪵�������Ԫ�ؿ�����������Ϊend()ָ������������һλ�ĺ�һλ������������0����v�����⴮������
vector<��������>(n, Ԫ��);//��n��Ԫ�ؿ���������
vector<��������>(����);//����
*/
void print0(vector<int>&v)
{
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << (*i) << " ";
	}
}

//vector��ֵ����
void test30()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	print0(v1);
	//���Ƹ�ֵ1
	vector<int>v2;
	v2 = v1;
	//assign��ֵ2
	vector<int>v3;
	v3.assign(v1.begin(), v1.end());
	//n��Ԫ�ظ�ֵ����������v4
	vector<int>v4;
	v4.assign(5, 10);//5��10
}

/*vector�����������ʹ�С
v.empty();//�ж�����v�Ƿ�Ϊ�գ��շ���1
v.capacity();//����v����������������Ԫ�ظ������������������ᶯ̬��չһ���µĸ��������
v.size();//����v��ʵ��Ԫ�صĸ���
v.resize(int num);//�����ƶ�����v�ĳ���Ϊnum��������v�����֮ǰ��������Ĭ��ֵ0�����������vʣ��λ��
							//������v��̣�ĩβɾ��
v.resize(int num,Ԫ��);//�����ƶ�����v�ĳ���Ϊnum��������v�䳤������Ԫ���������λ��
									//������v��̣�ĩβɾ��
*/

//vector�Ĳ����ɾ��
/*
v.push_back(Ԫ��);//β��
v.pop_back(Ԫ��);//βɾ
v.insert(v.λ�õ�����,Ԫ��);//ָ��λ�ò���Ԫ�ء�v.rend(),v.begin(),v.rbegin(),v.end();//��λ�õ�����������λ������0123����Ҳ����front������back����
v.insert(v.λ�õ�����,n,Ԫ��);//ָ��λ�ò���n��Ԫ��
v.erase(v.λ�õ�����);//ɾ��ָ��λ��Ԫ��;//��λ�õ�����������λ������0123����Ҳ����front������back����
v.erase(v.λ�õ�������v.λ�õ�����);//ɾ����������Ԫ��
v.clear();//ȫɾ
*/

//vector ���������ݴ�ȡ
/*
v[λ��]������[ ]��������Ԫ��
v.at(λ��)������at(λ��)����Ԫ��
v.front();��ȡ��һ��Ԫ��
v.back();��ȡ���һ��Ԫ��
*/

//begin()��end()�ǵ�������front()��back()�����ø�λ�õ�Ԫ��

//ʵ�����������е�Ԫ�ػ���
/*
v1.swap(v2);
//��;:
1.����swap���������ڴ�ռ�
*/

//vectorԤ���ռ䡪����ǰԤ���ռ䣬����vector�ڶ�̬��չʱ����չ����
/*
v1.reserve(����);//Ԥ�����ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ���
*/

//vector����Ƕ������
void test10()
{
	vector<vector<int>>v;
	//�ȴ���С����
	vector<int>v0;
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 3; i++)
	{
		v0.push_back(i);
		v1.push_back(3 + i);
		v2.push_back(6 + i);
	}
	//��С����Ƕ�׽���������
	v.push_back(v0);
	v.push_back(v1);
	v.push_back(v2);
	//����������
	for (vector<vector<int>>::iterator i = v.begin(); i != v.end(); i++)
	{
		//*i����������,����Ϊ������������������
		for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}