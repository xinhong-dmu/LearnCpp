#include<iostream>
using namespace std;
#include<string>/*输出字符串变量需要包含的头文件*/
#include"printstudent1.h"
#include"printstudent2.h"

//1.创建一个学生结构体
struct Student
{
	string name;
	int age;
	int score;
}s3;

//结构体嵌套结构体	
struct Teacher
{
	string name;
	int id;
	struct Student s;
};

//结构体做函数参数-值传递法
//值传递时，函数中改变结构体的值，仅此函数中的形参中的值改变，主函数实参并不改变
//值传递的形参变量和主函数的实参变量不是一个值
//值传递是将所有数据拷贝一份，浪费空间
void printstudent1(Student stu)
{  
	cout << "Student name:" <<stu.name << "   Student age:" << stu.age << "    Student score:" << stu. score << endl;
}
//结构体做函数参数-地址传递法
//地址传递时，此函数中改变结构体的值，形参和实参都改变
//地址传递的形参变量和主函数的实参变量都是一个值
//地址传递时，仅通过取地址符来提取数据，占用空间小
void printstudent2( const Student *p)/*const只读，一旦有修改的操作就会报错*/
{	
	cout << "Student name:" << p->name << "   Student age:" << p->age << "    Student score:" << p->score << endl;
}


//2.通过学生类型创建具体学生
//方法一：struct Student s1
//方法二：struct Student s2 = { , , , }
//方法三：在定义结构体时顺便创建结构体变量

int main()
{
	//方法一
	struct Student s1;
	s1.name = "jack";//通过.来访问结构体变量中的属性
	s1.age = 24;
	s1.score = 81;
	cout <<"Name:" <<s1.name <<"      Age:"<< s1.age <<"     Score"<< s1.score << endl;

	//方法二
	struct Student s2 = { "peter",24,81 };
	cout << "Name:" << s2.name << "    Age:" << s2.age << "   Score" << s2.score << endl;

	//方法三(不建议，不好让别人发现)

	s3.name = "john";
	s3.age = 13;
	s3.score = 64;
	cout << "Name:" << s3.name << "    Age:" << s3.age << "   Score" << s3.score << endl;

	//结构体数组
	struct Student stuarray[3] = 
	{
		{"jack",24,81},
		{"peter",24,81},
		{"john",13,64}
	};
	stuarray[2].name = "lucy";//修改值
	stuarray[2].age = 15;
	stuarray[2].score = 99;

	for (int i = 0; i < 3; i++)
	{
		cout << "Name:" << stuarray[i].name << "    Age:" << stuarray[i].age << "   Score" 
			<< stuarray[i].score << endl;
	}

	//创建结构体变量
	struct Student s = { "Andy",36,95 };/*struct可省略*/
	//通过指针指向结构体变量
	Student *p = &s;/*struct可省略*/
	//通过指针       ->          访问结构体变量中的数据
	cout << p->name << endl;

	//对结构体中嵌套的结构体进行操作
	Teacher t1;
	t1.name = "wang";
	t1.id = 65563;
	t1.s.name = "mary";
	t1.s.age = 24;
	t1.s.score = 100;
	cout << "Teacher name:" << t1.name << endl;

	//结构体做函数参数
	//不想修改主函数中的数据用值传递，反之用地址传递
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

	//const防止误操作
	Student s6 = { "s6",24,98 };
	printstudent2(&s6);

	system("pause");
	return 0;
}