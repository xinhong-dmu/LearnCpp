#include <iostream>
#include <string>

using std::string;

void func(const int num) {
	const int count = 10;
	constexpr int sum = count + 1;  //����һ���������ʽ
	int arr1[count];  //��ȷ����̬���鳤�ȱ����ǳ���
	//int arr2[num];  //�����ڱ��������Ĳ����б��е�const���α�ʾ����ֻ�������ǳ���
	int arr3[sum]; // ��ȷ��constexpr���εı��ʽΪ�������ʽ

}

// constexpr�������νṹ������࣬const����
class A {
public:
	// constexpr���ι��캯��ʱ�����������Ϊ�գ������ó�ʼ���б�ʽΪ��Ա��ֵ
	constexpr A():a(10) {}
private:
	int a;
};


void main() {
	// ��ͨ�ַ����е�ת���ַ���\�����������ĸ���
	string str1 = "D:\a\t\c.exe";
	std::cout << str1 << std::endl;

	// û��C++11�£�����������ת���ַ���\\����ʾһ��ת���ַ���\��
	string str2 = "F:\\a\\t\\c.exe";
	std::cout << str2 << std::endl;

	// C++11������ԭʼ������������˼��ԭ����ʲô����ʲô���� R"�����ַ���(��Ҫ�����ַ���)�����ַ���"�������ַ�����ʡ�ԣ������ַ�������һ����������Ӣ��
	string str3 = R"11(D:\a\t\c.exe)11";
	std::cout << str3 << std::endl;

	// NULL��C++���ܽ�NULL��ʽת��Ϊint
	int *ptr1 = NULL; //�鿴NULL�����֪����C++��NULL������Ϊint�͵�0��C��NULL������viod*�͵�0
	double *ptr2 = NULL;
	char *ptr3 = NULL;
	void *ptr4 = NULL;
	int *ptr5 = (int*)ptr4; // �Ѿ������NULL��ָ�����������ʽת��Ϊint�ͣ���Ҫǿ������ת��
	// nullptr�����Զ�ת��Ϊ�������͵�0��������C++11�����е�NULLת��Ϊnullptr
	int *ptr6 = nullptr;
	void *ptr7 = nullptr;
	int *ptr8 = (int*)ptr7;// �Ѿ������nullptr��ָ�����������ʽת��Ϊint�ͣ���Ҫǿ������ת��


	// constexpr�������߱��������ǳ������ʽ��ֻ�г���֮������㣬�����б�����
	// �������ʽ�ڱ��������������ʡʱ��
	const int num = 10;
	func(num);
	// ��NULLһ���������ܹ���constexpr����constexpr
	// ��ͽṹ��Ķ�����⣬������ͽṹ��ʱ��constexpr�����ࡢ�ṹ���ģ�庯�������ڴ�����Ա��ʵ����ʱ��constexpr
	// ���庯��ģ��ʱ��������ǳ������ʽ������constexpr��Ч
	constexpr A s1; //�ṹ��ֱ�Ӹ�ֵ��{num}��constexpr���ε���a��Ա
	//s1.a = 11; //����

	// constexptr���κ�������ֵʱ����������Ϊ�������ʽ������Ҫ�����£�
	// 1.���������з���ֵ����return�ķ��صı��ʽ����Ϊ�������ʽ
	// 2.constexpr�����ڵ���֮ǰ�ͱ��붨�壬���� ����-����-����
	// 3.constexpr�������ڲ��ܳ��ַǳ������ʽ�������䣨���Գ��֣�using���������/typedef/assert/return��

	// constexpr���ι��캯��ʱ�����������Ϊ�գ������ó�ʼ���б�ʽΪ��Ա��ֵ



	system("pause");
}