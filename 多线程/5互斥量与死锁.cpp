#include <iostream>
#include <thread>  //���߳�ͷ�ļ�
#include <string>
#include <vector>
#include <list>
#include <mutex>  //������ͷ�ļ�

#include <windows.h> //sleepͷ�ļ�
using std::string;

class GameMsg {
public:
	void addRecvList() {
		for (int i = 0; i < 10000; i++) {
			//std::lock_guard<std::mutex> msgGuard1(mutex1); //�ԡ�}������return������break���Ƚ�������������������������
														  // mutex1����������ԴmsgRecvList
			// ....
			//std::lock_guard<std::mutex> msgGuard2(mutex2);
			std::lock(mutex1, mutex2); //�൱��ÿ��������mutex��������lock()
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //����дunlock()��
			std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
			msgRecvList.push_back(i);  //ֻ����д����
			// ����˳��Ӱ������
			//mutex1.unlock(); //return����ǰҪ��֤�г���
			//mutex2.unlock();
		}
	}

	bool getMsgLULProc(int &command) {
		// ˫�ؼ�����˫���ж�
		if (!msgRecvList.empty()) {
			//std::lock_guard��ģ���ڹ��캯����ִ����mutex::lock()������������mutex::unlock()
			//std::lock_guard<std::mutex> msgGuard1(mutex1);
			//std::lock_guard<std::mutex> msgGuard2(mutex2); // ��ʱ���mutex2������msgRecvList��Դ������msgRecvList�ȱ���mutex1�������ˣ���������
			std::lock(mutex1, mutex2); //�൱��ÿ��������mutex��������lock()
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //����дunlock()��
			std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
			if (!msgRecvList.empty()) {
				command = msgRecvList.front();
				msgRecvList.pop_front();
				//mutex1.unlock(); //return����ǰҪ��֤�г���
				//mutex2.unlock();
				return true;
			}
			//mutex1.unlock(); //return����ǰҪ��֤�г���
			//mutex2.unlock();
			return false;

		}
	}

	void getRecvList() {
		int command = 0;
		for (int i = 0; i < 10000; i++) {
			if (getMsgLULProc(command)) {
				std::cout << "�������Ϊ��"<< command << std::endl;
			}
			else {
				std::cout << "�����Ϣ����Ϊ��" << std::endl;
			}
		}
		std::cout << "--------�����ִ�����--------" << std::endl;
	}

private:
	std::list<int> msgRecvList; //���ڴ�Ž���������������
	std::mutex mutex1;
	std::mutex mutex2;
};

int main() {

	GameMsg gm;
	std::thread addThread(&GameMsg::addRecvList, &gm); // ��Ա�������߳���ڣ���������ʱ���ò��ܱ�֤�߳��õ���ͬһ�����󣬷�ֹthread�Զ�����һ��
	std::thread getThread(&GameMsg::getRecvList, &gm);
	addThread.join();
	getThread.join();

	// ������mutex��������������һ�������������������̳߳�����lock()��Ա����������ֻ��һ���߳̿��������ɹ����ɹ��ı�־��lock()���������ˣ�
	// ���û���ɹ�����ô��һֱ����ֱ�������ɹ�
	// ֻ������д�����жϡ�ʱ��Ҫ�����ġ����ݡ�
	// lock() �� unlock() ����ɶ�ʹ��
	// std::lock_guard��ģ��ȡ��lock()��unlock()��������Ա��©unlock()��������unlock()����������ָ�루����Ա�����ͷ��ڴ棬�����ͷţ�

	// �����Ĳ����������߳���Ҫ����Դ�������߳��໥����������һ����ԴҲ������
	// ֻҪ��֤����������������˳��һ�¾Ͳ�������

	// std::lock()����ģ�壺�ܹ�һ������std::lock(������1,������n)��������������
	// ÿ��lock()����Ҫ����unlock() ���� ����std::lock_guard <std::mutex> ��(������1,������n,std::adopt_lock)����ֹ�Լ���©unlock()
	// ��ȫ�����ڶ���߳�����Ϊ��ͷ˳�����⵼�µ���������
	// Ҫô��������������ס��Ҫô��û��ס��



	std::cout << "---------���߳�ִ�����---------" << std::endl;

	Sleep(60000);
	return 0;
}