#include <iostream>
#include <thread>  //���߳�ͷ�ļ�
#include <string>

#include <windows.h> //sleepͷ�ļ�
using std::string;

class A {
public:
	int m_i;
	//��һ�������Ĺ��캯��
	A(int a) : m_i(a) {
		std::cout << "A::A(int a)���캯��ִ��" <<this<<"thread_id="<<std::this_thread::get_id()<< std::endl;

	}
	//�������캯����������������ת�����캯����һ��intתΪ�����
	A(const A &a) : m_i(a.m_i) {
		std::cout << "A::A(const A &a)�������캯��ִ��" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}
	~A(){
		std::cout << "A::~A��������ִ��" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}

	void threadWork(int n) {
		std::cout << "A::threadWork()����ִ��" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}

	void operator()(int n) {
		std::cout << "A::()����ִ��" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}
};

// ������������ȫ�����ڴ����߳�ʱ������ʱ���󣬲�ʹ����ʽ����ת������(A)(��ʱ����), ���Һ��������б�ʹ����������(����ϵͳ��๹��һ�ζ���(һ��������))
// ʹ�����ñ����const
void myPrint1(const int i, A &pBuff) { // �������̺߳����Ĳ����б�ʹ�����û���ָ��,�ַ�������const string &str����
	std::cout << "i = "<< i << std::endl; // i����mVar�����ã����Ǹ��Ƶ�ֵ����
	pBuff.m_i = 199;
	std::cout << "���߳�myPrint1�Ĳ�����ַΪ��" << &pBuff <<"thred_id="<< std::this_thread::get_id() << std::endl;
}

void myPrint2(std::unique_ptr<int> pzn) {
	std::cout << "���߳�myPrint2�Ĳ�����ַΪ��" << &pzn << "thred_id=" << std::this_thread::get_id() << std::endl;
}


int main() {
	std::cout << "���߳�id=" << std::this_thread::get_id() << std::endl;
	// ������ʱ������Ϊ�̲߳���
	int mVar = 1;
	int mySecondPar = 12;
	// ֻҪ����ʱ�����A�������Ϊ�������ݸ��̣߳���ôһ���ܹ������߳�ִ�����ǰ���̺߳����ĵڶ�����������������ȷ��detach()��ȫ����
	std::thread myThread1(myPrint1, mVar, A(mySecondPar));// ���뺯�����ͺͲ����б��ǲ��еĹ�ϵ,���ַ�������ʽ����ת��Ϊstring�ܹ���֤�̰߳�ȫ����������Ҳͬ��ͨ�����е�����ת������mySecondPar
	myThread1.join(); // ���ø��Ƶ�ֵ����detach()�ж��ǰ�ȫ��

	//�ܽ�detach()�Ŀ�
	/*
	1.���Ǽ���������int������ֵ���ݲ�Ҫ�����ã���ֹ��ͬ������������֦
	2.������������ȫ�����ڴ����߳�ʱ������ʱ���󣬲�ʹ����ʽ����ת������(A)(��ʱ����),���Һ��������б�ʹ����������(����ϵͳ��๹��һ�ζ���(һ��������))
****3.****���鲻ʹ��detach()
	*/

	// �߳�IDͨ�� std::this_thread::get_id(�̶߳���)  ���

	// �����������Ϊ�̲߳��� ���� std::ref ����
	A a(10);
	std::thread myThread2(myPrint1, mVar, std::ref(a));  // std::ref(a) ��a�����ô��ݵ��߳��У��̺߳��������б�Ͳ���const��
	myThread2.join();

	// ���ݶ�ռ������ָ����Ϊ�̲߳��� ���� std::move ����
	std::unique_ptr<int> myPtr(new int(100)); //������ռ��ָ��
	//std::thread myThread3(myPrint2, myPtr);����ֱ�Ӵ���ռ������ָ��Ϊ����
	std::thread myThread3(myPrint2, std::move(myPtr)); // ��ռ��ָ����Ҫmove���ݽ��̺߳��������б�
	myThread3.join();// ��ռ������ָ�벻��ʹ��detach()

	// ��Ա����ָ�����̺߳���
	A a2(10);
	std::thread myThread4(&A::threadWork,a2,22);
	myThread4.join();

	// operator()�º�����Ϊ�̺߳������
	A a3(33);
	std::thread myThread5(&A::operator(),a3, 333);
	myThread5.join();


	std::cout << "���߳�ִ�����" << std::endl;
	Sleep(60000);

	return 0;
}