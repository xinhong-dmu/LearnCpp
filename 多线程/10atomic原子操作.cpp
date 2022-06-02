#include <iostream>
#include <thread>  //���߳�ͷ�ļ�
#include <mutex>  //������ͷ�ļ�
#include <ctime>  //����ִ�м�ʱ
#include <atomic>  //ԭ�Ӳ���ͷ�ļ�

#include <windows.h> //Sleepͷ�ļ�     

//static int gCount = 0;
static std::atomic<int> gCount = 0;  //����ԭ�Ӳ�����װ��һ��int��ȫ�־�̬����
static std::mutex gMutex1;
static std::atomic<bool> isEnd = false;  //���߳��˳����

void addCount() {
	for ( int i = 0;i < 10000;i++ ) {
		if ( isEnd == true ) {
			break;
		}
		//gMutex1.lock(); // ִ��ʱ��350ms
		gCount++;  //ԭ�Ӳ���ִ��ʱ��120ms �� 1/3 ������
		//gMutex1.unlock();
		std::cout << "Thread id: " << std::this_thread::get_id() << "  gCount = "<<gCount << std::endl;
	}
	std::cout << "-----Thread id: " << std::this_thread::get_id() << "�˳�-----" << std::endl;
}
void cinEnd() {
	char putin = 'n';
	std::cin >> putin;
	if ( putin == 'y' ) {
		isEnd = true;
	}
}

int main() {
	double stateTime = clock();
	std::atomic<int> atom1;
	// ԭ�Ӳ���std::atomic��ģ����������װĳ�����͵�ֵ
	// ����̶߳�ͬһ����д�����ǲ��ȶ���
	// ��������ͨ�����Ϳ������ڶ��̱߳����������ݣ�����ÿ�ζ�Ҫ���ͽ������ٶ���
	// ԭ�Ӳ����� ����Ҫ������������ ���̲߳���

	// ԭ�Ӳ������ڶ��߳��� ���ᱻ��� �� һ������ �Ķ�д
	// ԭ�Ӳ���ֻ���һ��������������С�Ĳ��ɷָ�Ĳ�������Ҫô���Ҫôû���
	// ԭ�Ӳ������++��--��+=��&=��|=��^=���������ʽ��һ��֧�֣�����
	//gCount = gCount + 1;  //����ԭ�Ӳ������������

	std::cout << atom1;// ���в���ԭ�Ӳ�����atom���

	// ԭ�Ӳ���֮�䲻����ֱ�Ӹ��ơ����� atom2 = atom1 ;//errow
	std::atomic<int> atom2(atom1.load());  //ԭ�Ӳ����ĸ����� ԭ�Ӷ���.load()װ��

	//��ԭ�Ӳ���д��.score() , ���غ��=
	atom2.store(2);
	atom2 = 3;






	std::thread myThread1(addCount);
	std::thread myThread2(addCount);
	std::thread myThread3(cinEnd);
	myThread1.join();
	myThread2.join();
	myThread3.join();















	std::cout <<"gCount="<< gCount << std::endl;

	std::cout <<"ִ��ʱ�䣺" <<clock() - stateTime<<"ms" << std::endl;
	Sleep(60000);
	return 0;
}