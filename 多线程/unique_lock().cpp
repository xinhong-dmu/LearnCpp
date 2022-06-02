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
			std::lock(mutex1, mutex2); 
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); 
			std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
			msgRecvList.push_back(i);
		}
	}

	bool getMsgLULProc(int &command) {
		std::lock(mutex1, mutex2); 
		std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //����дunlock()��
		std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
		if (!msgRecvList.empty()) {
			command = msgRecvList.front();
			msgRecvList.pop_front();
			return true;
		}
		return false;
	}

	void getRecvList() {
		int command = 0;
		for (int i = 0; i < 10000; i++) {
			if (getMsgLULProc(command)) {
				std::cout << "�������Ϊ��" << command << std::endl;
			}
			else {
				std::cout << "�����Ϣ����Ϊ��" << std::endl;
			}
		}
	}

private:
	std::list<int> msgRecvList;
	std::mutex mutex1;
	std::mutex mutex2;
};





void main() {

	GameMsg gm;
	std::thread addThread(&GameMsg::addRecvList, &gm);
	std::thread getThread(&GameMsg::getRecvList, &gm);
	addThread.join();
	getThread.join();

	//uniq_lockȡ��lock_guard(�Ƽ�ʹ��)







	std::cout << "--------���߳�ִ�����--------" << std::endl;
	Sleep(60000);
}