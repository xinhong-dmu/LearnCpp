#include<iostream>
#include<string>
using namespace std;
//��ָ��Ҳ���Ե��ó�Ա����
//��Ҫע����û���õ�thisָ�롣������this��Ҫ�жϴ���Ľ�׳��

class person
{public:
	void showpersonname()
	{
		cout << "He is Jack." << endl;
	}
	void showpersonage()
	{//��ǿ���뽡׳�ԣ���ֹ��ָ��ʹ������������ǿ�ָ��Ͳ�ȡֱ�Ӱ�����ĺ������еĴ���Ҳ����
		if(this == NULL)
		{
			return;
		}
		cout << "He is " <<m_age<< endl;//������ǰĬ�ϼ���this->m_age
	}
	int m_age;
};
void test10()
{
	person * p0 = NULL;//��ָ�����൱��û�д�������thisָ����һ���յ�ֵ
	p0->showpersonname();
	p0->showpersonage();
}
int main()
{
	test10();

	system("pause");
	return 0;
}