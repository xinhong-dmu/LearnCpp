#include <iostream>
#include <list>
#include <thread>  //���߳�ͷ�ļ�
#include <mutex>  //������ͷ�ļ�
#include <ctime>  //����ִ�м�ʱ
#include <atomic>  //ԭ�Ӳ���ͷ�ļ�

#include <windows.h> //Sleepͷ�ļ�     

class GameMsg {
public:
	void addRecvList() {
		for ( int i = 0; i < 10000; i++ ) {
			std::lock(mutex1, mutex2);
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock);
			std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
			msgRecvList.push_back(i);
		}
	}

	bool getMsgLULProc(int &command) {
		// ˫�ؼ�����˫���ж�
		if ( !msgRecvList.empty() ) {
			std::lock(mutex1, mutex2); //�൱��ÿ��������mutex��������lock()
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //����дunlock()��
			std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
			if ( !msgRecvList.empty() ) {
				command = msgRecvList.front();
				msgRecvList.pop_front();
				return true;
			}
			return false;
		}
	}

	void getRecvList() {
		int command = 0;
		for ( int i = 0; i < 10000; i++ ) {
			if ( getMsgLULProc(command) ) {
				std::cout << "�������Ϊ��" << command << std::endl;
			}
			else {
				std::cout << "�����Ϣ����Ϊ��" << std::endl;
			}
		}
		std::cout << "--------�����ִ�����--------" << std::endl;
	}

private:
	std::list<int> msgRecvList;
	std::mutex mutex1;
	std::mutex mutex2;

};



int main() {
	

	GameMsg gm;
	std::thread addThread(&GameMsg::addRecvList, &gm); // ��Ա�������߳���ڣ���������ʱ���ò��ܱ�֤�߳��õ���ͬһ�����󣬷�ֹthread�Զ�����һ��
	std::thread getThread(&GameMsg::getRecvList, &gm);
	addThread.join();
	getThread.join();

	// �̳߳أ���һ���̷߳ŵ�һ��ȥͳһ����
	// �̳߳�ʵ�ַ�ʽ����������ʱ��һ���Դ�����һ���������̣߳�����������ʱ�����ÿ����߳�
	// �����ܸ���

	// �߳��������ޣ�2000����
	// ��ٷ������߳���Ŀ









	Sleep(60000);
	return 0;
}