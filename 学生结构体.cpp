#include<iostream>
using namespace std;
#include<string>/*����ַ���������Ҫ������ͷ�ļ�*/
#include"printstudent1.h"
#include"printstudent2.h"

//1.����һ��ѧ���ṹ��
struct Student
{
	string name;
	int age;
	int score;
}s3;

//�ṹ��Ƕ�׽ṹ��	
struct Teacher
{
	string name;
	int id;
	struct Student s;
};

//�ṹ������������-ֵ���ݷ�
//ֵ����ʱ�������иı�ṹ���ֵ�����˺����е��β��е�ֵ�ı䣬������ʵ�β����ı�
//ֵ���ݵ��βα�������������ʵ�α�������һ��ֵ
//ֵ�����ǽ��������ݿ���һ�ݣ��˷ѿռ�
void printstudent1(Student stu)
{  
	cout << "Student name:" <<stu.name << "   Student age:" << stu.age << "    Student score:" << stu. score << endl;
}
//�ṹ������������-��ַ���ݷ�
//��ַ����ʱ���˺����иı�ṹ���ֵ���βκ�ʵ�ζ��ı�
//��ַ���ݵ��βα�������������ʵ�α�������һ��ֵ
//��ַ����ʱ����ͨ��ȡ��ַ������ȡ���ݣ�ռ�ÿռ�С
void printstudent2( const Student *p)/*constֻ����һ�����޸ĵĲ����ͻᱨ��*/
{	
	cout << "Student name:" << p->name << "   Student age:" << p->age << "    Student score:" << p->score << endl;
}


//2.ͨ��ѧ�����ʹ�������ѧ��
//����һ��struct Student s1
//��������struct Student s2 = { , , , }
//���������ڶ���ṹ��ʱ˳�㴴���ṹ�����

int main()
{
	//����һ
	struct Student s1;
	s1.name = "jack";//ͨ��.�����ʽṹ������е�����
	s1.age = 24;
	s1.score = 81;
	cout <<"Name:" <<s1.name <<"      Age:"<< s1.age <<"     Score"<< s1.score << endl;

	//������
	struct Student s2 = { "peter",24,81 };
	cout << "Name:" << s2.name << "    Age:" << s2.age << "   Score" << s2.score << endl;

	//������(�����飬�����ñ��˷���)

	s3.name = "john";
	s3.age = 13;
	s3.score = 64;
	cout << "Name:" << s3.name << "    Age:" << s3.age << "   Score" << s3.score << endl;

	//�ṹ������
	struct Student stuarray[3] = 
	{
		{"jack",24,81},
		{"peter",24,81},
		{"john",13,64}
	};
	stuarray[2].name = "lucy";//�޸�ֵ
	stuarray[2].age = 15;
	stuarray[2].score = 99;

	for (int i = 0; i < 3; i++)
	{
		cout << "Name:" << stuarray[i].name << "    Age:" << stuarray[i].age << "   Score" 
			<< stuarray[i].score << endl;
	}

	//�����ṹ�����
	struct Student s = { "Andy",36,95 };/*struct��ʡ��*/
	//ͨ��ָ��ָ��ṹ�����
	Student *p = &s;/*struct��ʡ��*/
	//ͨ��ָ��       ->          ���ʽṹ������е�����
	cout << p->name << endl;

	//�Խṹ����Ƕ�׵Ľṹ����в���
	Teacher t1;
	t1.name = "wang";
	t1.id = 65563;
	t1.s.name = "mary";
	t1.s.age = 24;
	t1.s.score = 100;
	cout << "Teacher name:" << t1.name << endl;

	//�ṹ������������
	//�����޸��������е�������ֵ���ݣ���֮�õ�ַ����
	struct Student s4;
	s4.name = "s4";
	s4.age = 40;
	s4.score = 0;
	printstudent1(s4);

	Student s5;
	s5.name = "s5";
	s5.age = 40;
	s5.score = 99;
	printstudent2(&s5);

	//const��ֹ�����
	Student s6 = { "s6",24,98 };
	printstudent2(&s6);

	system("pause");
	return 0;
}