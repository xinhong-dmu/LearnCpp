#include<iostream>
#include<fstream>//文件操作头文件
#include<string>
using namespace std;
//二进制文件打开方式指定为ios::binary


//写文件示例——ostream& write(const char * 指针,sizeof(对象))
//当数据类型为自定义时，需强转指针——(const char *)&指针
//利用字符指针指向内存中一段存储空间

//二进制可以操作自定义的数据类型
class person
{
public:
	void p(char name, int age)
	{
		m_name [64]= name;
		m_age = age;
	}
	char m_name[64];//对文件操作尽量用C语言中的char字符串，不用string
	//表示m_name字符数组在内存中可占64个字符
	int m_age;
};

void wr_test1()
{
	ofstream ofs("test1.txt", ios::out | ios::binary);//可以直接写，不用open那步
	ofs << "你好!" << endl;
	//写自定义数据类型的文件
	person p = { "Sincereh",24};
	ofs.write((const char *)&p, sizeof(p));//需把地址强转为const char *

	ofs.close();
}

//二进制文件读操作
//流对象名 read(char *指针 ,sizeof(数据对象));
//利用字符指针指向内存中一段存储空间

void rd_test1()
{
	ifstream ifs("test1.txt", ios::in|ios::binary );
	if (! ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	person p;
	ifs.read(( char *)&p, sizeof(p));
	cout << p.m_name << p.m_age << endl;
	ifs.close();
}




void main()
{
	wr_test1();
	rd_test1();
	system("pause");
}