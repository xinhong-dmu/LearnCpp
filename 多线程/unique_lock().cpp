#include <iostream>
#include <thread>  //多线程头文件
#include <string>
#include <vector>
#include <list>
#include <mutex>  //互斥量头文件

#include <windows.h> //sleep头文件
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
		std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //不用写unlock()了
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
				std::cout << "玩家命令为：" << command << std::endl;
			}
			else {
				std::cout << "玩家消息链表为空" << std::endl;
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

	//uniq_lock取代lock_guard(推荐使用)







	std::cout << "--------主线程执行完毕--------" << std::endl;
	Sleep(60000);
}