#include <iostream>
#include <thread>  //���߳�ͷ�ļ�


//�̵߳��ö�������Ǻ���
void myThread1() {
	std::cout << "�Ҵ����ĺ����߳�1��ʼִ����" << std::endl;

	std::cout << "�Ҵ����ĺ����߳�1ִ�������" << std::endl;
}

//�̵߳��ö����������
class TA {
public:
	int &m_i;
	TA(int &i) :m_i(i) {
		std::cout << "TA�Ĺ��캯����ִ��" << std::endl;
	}
	TA(const TA &ta) :m_i(ta.m_i) {
		std::cout << "TA()�������캯����ִ��" << std::endl;
	}
	~TA() {
		std::cout << "TA()�������캯����ִ��" << std::endl;
	}
	void operator()() {}
};


int main() {
	//���̴߳�main������ʼִ��
	std::cout << "���߳�ִ�п�ʼ" << std::endl;
	//�Լ��������߳�Ҳ��Ҫ��һ����������ʼ��������ʼִ��
	std::thread myThread1(myThread1);//thread�Ǳ�׼��������࣬myThread1��һ���ɵ��ö��󡣴�����һ���̣߳��߳�������ΪmyThread1����ʼִ��
	//ͨ��joinable()�ж��Ƿ�ɹ�ʹ��join()/detach()
	if (myThread1.joinable() == true) {
		std::cout << "myThread1 joinable == true" << std::endl;
	}
	else {
		std::cout << "myThread1 joinable == fasle" << std::endl;
	}
	myThread1.join();//�������̣߳��ȴ����߳�ִ����ϣ������̻߳�ϣ�Ȼ�����̲߳ſ�ʼִ��

	//detach()�����߳�ʧȥ���ƣ�Ӧ�ó���Ϊ�����߳������̻߳������ŵ����
	int i = 6;//iΪ���̵߳ľֲ������������߳�ִ�н���i�ͱ�������
	TA ta(i);//����һ�ζ�����Ҫһ������
	std::thread myThread2(ta);//���������ÿ������캯���������߳�myThread2���߳�������Ҫ����һ��
	if (myThread2.joinable() == true) {
		std::cout << "myThread2 joinable == true" << std::endl;
	}
	else {
		std::cout << "myThread2 joinable == fasle" << std::endl;
	}
	myThread2.detach();//�������̣߳�����ȴ����߳�ִ����ϣ������̷߳��룬���߸��ģ��������߳�ʧȥ��������ʱ���̱߳�c++����ʱ��ӹܣ�����������Դ���ػ��̣߳�
	
	//lambda���ʽ��Ϊ�߳����
	auto myLambdaThread = [] {
		std::cout << "myLambdaThread ��ʼ" << std::endl;

		std::cout << "myLambdaThread ����" << std::endl;
	};
	std::thread myThread3(myLambdaThread);
	myThread3.detach();




	std::cout << "���߳�ִ�����" << std::endl;
	system("pause");

	return 0;
}