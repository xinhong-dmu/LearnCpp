#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



//string��������һ����
//char*��ָ��
//string���з�װ��char*����������ַ�������һ��char*�͵�����
//string�ڲ���װ�˺ܶ��Ա����������find,copy,delete,insert...

//string���캯�� ��ʼ��
void test20()
{
	string s0;//Ĭ�Ϲ���
	const char* str = "hello world";//����һ���ַ���
	string s2(str);//����һ���ַ������󲢸�Ĭ��ֵ
	string s3(s2);//��������
	string s4(10,'q');//10��q���ַ������ַ�˫���Ų��о��ǵ�����
}

//string��ֵ����
void test21()
{
	string s0;  s0 = "s0";
	string s1("s1");
	string s2(s1);
	string s3;   s3.assign("s3");
	string s4;   s3.assign("012345",5);//���ǰ����ַ�
	string s5;   s5.assign(5, 'c');
}

//string�ַ���ĩβƴ���ַ��� ����  +=
void test22()
{
	string s0("I LIKE");
	s0 += "game";
	//��һһ�о���
}

//string���Һ��滻
void test23()
{
	string s0("0123456789");
	s0.find("23");//�����׸���23����Ӧ�׸��ַ���2�����±�λ��(��������)����û�з���-1
	s0.rfind("23");//�����׸���23����Ӧ�׸��ַ���2�����±�λ��(��������)����û�з���-1
	
	s0.replace(2,5,"000");//����3���ַ����n���ַ�����Ϊ000��010003456789
	//���м�n���ַ���Ϊ�����е��ַ�
}

//string�ַ����Ƚ�
void test24()
{
	string s0("123");
	string s1("456");
	s0.compare(s1);//��ȷ���0���Ƚ�ASCII�룬s0>s1����1��s0<s1����-1
}

//string�ַ���ȡ
void test25()
{
	string s0("123");
	s0[0] = '12';//����[]�����ַ����е�����д
	s0.at(1)='00';//����at()������д
}

//string�����ɾ��
void test26()
{
	string s0("0123");
	cout << s0.insert(1, "0") << endl;	//�ӵ�2���ַ�ǰ��ʼ�����ַ�������˵�ӵ�1���ַ���
	cout << s0.erase(1, 2) << endl;//�ӵ�2���ַ���ɾ��2��Ԫ��
}

//string�Ӵ��������ַ����л�ȡ��Ҫ���Ӵ���Ϊ����ֵ
void test27()
{
	string s0("0123456789");
	s0.substr(0,3);//���شӵ�һ��Ԫ�ؿ�ʼ������Ԫ��
}





void main()
{


	system("pause");
}