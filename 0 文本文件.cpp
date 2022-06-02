#include<iostream>
#include<fstream>//文件操作头文件
#include<string>
using namespace std;
//通过文件操作让数据持久化

//文件类型分为两种：
//1.文本文件——文件以文本的ASSII码的形式存储在计算机中
//2.二进制文件——文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂他们

//操作文件的三大类：
//1.ofsream：写操作
//2.ifstream：读操作
//3.fstream：读写操作

//写文件的步骤：
//#include<fstream>---创建流对象ofstream ofs;---打开文件ofs.open("文件路径"，打开方式如下);---
//---写数据ofs<<"要写入的数据";---关闭文件ofs.close();

//打开方式：可配合使用，中间用|隔开
//ios::in ——为读文件而打开文件；ios::out——为写文件而打开文件；ios::ate——初始位置为文件尾
//ios::app——追加方式写文件；ios::trunc——如果文件存在先删除再创建；ios::binary——二进制方式


//写文件示例
void wr_test0()
{
	ofstream ofs;
	ofs.open("test0.txt",ios::out);//致谢文件名，默认在和程序的同目录下
	ofs << "Hello World" << endl;
	ofs.close();
}

//读文件步骤：
//#include<fstream>---创建流对象ifstream ifs;---打开文件ifs.opren("文件路径"，打开方式)
//---判断文件是否打开成功if(! ifs.is_open){cout<<"文件打开失败"<<endl;return;}
//---读数据（四种方式读取）---关闭文件ifs.close()

//读文件示例
void rd_test0()
{
	ifstream ifs;
	ifs.open("test0.txt", ios::in);
	if ( ! ifs.is_open())//判断文件是否打开成功，fs.is_open()=true成功
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读文件的四种方式
	//方式1      ifs>>buf
	char buf[1024] = { 0 };//初始化字符数组
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	//方式2       ifs.getline(buf,sizeof(buf))
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}
	//%%%%%方法3%%%%%       string buf;while(getline(ifs,buf))
	string buf0;
	while (getline(ifs,buf0))
	{
		cout << buf0 << endl;
	}
	//方式4
	char c;
	while ((c = ifs.get()) != EOF)//是否读到文件尾
	{
		cout << c;
	}

	ifs.close();
}


void main()
{
	wr_test0();
	rd_test0();
	system("pause");
}