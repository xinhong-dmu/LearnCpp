#include<iostream>
#include<string>
using namespace std;
class v 
{

};
class person
{
	int pa;//ֻ�зǾ�̬��Ա����������Ķ�����
	
	void fun(){	}//�Ǿ�̬��Ա������������Ķ�����
	static void funcv(){}//��̬��Ա������������Ķ�����
	static int pb;//��̬��Ա������������Ķ�����
};

void test71()
{//������ʲôҲû�е�ʱ��
	v p;
	cout << sizeof(p) << endl;//�ն���ռ�ڴ�ռ�1���ֽ�
	//c++��ÿһ���ն���Ҳ����һ���ֽڵĿռ���Ϊ�����ֶ���ռ�ڴ��λ��
	//ÿ���ն���Ӧ��һ����һ�޶����ڴ��ַ
}
void test72()
{//������һ���Ǿ�̬��Ա����ʱ
	person p;
	cout << sizeof(p) << endl;

	//�ǿն���ռ�ڴ�ռ�4���ֽ�
}

int main()
{
	test71();
	test72();

	system("pause");
	return 0;
}