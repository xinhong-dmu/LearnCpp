#include<iostream>
#include<string>
#include<vector>//STLÿ���������Ͷ�Ҫ����ͷ�ļ�
#include<algorithm>

using namespace std;

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
	for_each(v.begin(), v.end(),my_print);//for_each(��ʼ�����������������������õĺ���)
}


//vector����Զ�����������
class person
{public:
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
		cout <<(*i).name<<i->age << endl;//(*i)����������Ϊ<>�е�
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
		cout <<(**i).name << (*i)->age << endl;//(*i)��personָ�룬(**i)��personָ��*i�Ľ�����
	}

}

void main()
{
	test00();
	test01();
	test02();

	system("pause");
}