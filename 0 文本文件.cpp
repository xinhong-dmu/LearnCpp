#include<iostream>
#include<fstream>//�ļ�����ͷ�ļ�
#include<string>
using namespace std;
//ͨ���ļ����������ݳ־û�

//�ļ����ͷ�Ϊ���֣�
//1.�ı��ļ������ļ����ı���ASSII�����ʽ�洢�ڼ������
//2.�������ļ������ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������

//�����ļ��������ࣺ
//1.ofsream��д����
//2.ifstream��������
//3.fstream����д����

//д�ļ��Ĳ��裺
//#include<fstream>---����������ofstream ofs;---���ļ�ofs.open("�ļ�·��"���򿪷�ʽ����);---
//---д����ofs<<"Ҫд�������";---�ر��ļ�ofs.close();

//�򿪷�ʽ�������ʹ�ã��м���|����
//ios::in ����Ϊ���ļ������ļ���ios::out����Ϊд�ļ������ļ���ios::ate������ʼλ��Ϊ�ļ�β
//ios::app����׷�ӷ�ʽд�ļ���ios::trunc��������ļ�������ɾ���ٴ�����ios::binary���������Ʒ�ʽ


//д�ļ�ʾ��
void wr_test0()
{
	ofstream ofs;
	ofs.open("test0.txt",ios::out);//��л�ļ�����Ĭ���ںͳ����ͬĿ¼��
	ofs << "Hello World" << endl;
	ofs.close();
}

//���ļ����裺
//#include<fstream>---����������ifstream ifs;---���ļ�ifs.opren("�ļ�·��"���򿪷�ʽ)
//---�ж��ļ��Ƿ�򿪳ɹ�if(! ifs.is_open){cout<<"�ļ���ʧ��"<<endl;return;}
//---�����ݣ����ַ�ʽ��ȡ��---�ر��ļ�ifs.close()

//���ļ�ʾ��
void rd_test0()
{
	ifstream ifs;
	ifs.open("test0.txt", ios::in);
	if ( ! ifs.is_open())//�ж��ļ��Ƿ�򿪳ɹ���fs.is_open()=true�ɹ�
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//���ļ������ַ�ʽ
	//��ʽ1      ifs>>buf
	char buf[1024] = { 0 };//��ʼ���ַ�����
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	//��ʽ2       ifs.getline(buf,sizeof(buf))
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}
	//%%%%%����3%%%%%       string buf;while(getline(ifs,buf))
	string buf0;
	while (getline(ifs,buf0))
	{
		cout << buf0 << endl;
	}
	//��ʽ4
	char c;
	while ((c = ifs.get()) != EOF)//�Ƿ�����ļ�β
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