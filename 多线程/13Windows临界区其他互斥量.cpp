#include <iostream>
#include <list>
#include <thread>  //多线程头文件
#include <mutex>  //互斥量头文件
#include <ctime>  //程序执行计时
#include <atomic>  //原子操作头文件

#include <windows.h> //Sleep头文件     

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
		// 双重加锁，双重判断
		if ( !msgRecvList.empty() ) {
			std::lock(mutex1, mutex2); //相当于每个互斥量mutex都调用了lock()
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //不用写unlock()了
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
				std::cout << "玩家命令为：" << command << std::endl;
			}
			else {
				std::cout << "玩家消息链表为空" << std::endl;
			}
		}
		std::cout << "--------命令处理执行完毕--------" << std::endl;
	}

private:
	std::list<int> msgRecvList;
	std::mutex mutex1;
	std::mutex mutex2;

};



int main() {
	

	GameMsg gm;
	std::thread addThread(&GameMsg::addRecvList, &gm); // 成员函数作线程入口，函数对象时引用才能保证线程用的是同一个对象，防止thread自动复制一份
	std::thread getThread(&GameMsg::getRecvList, &gm);
	addThread.join();
	getThread.join();

	// 线程池：将一堆线程放到一起去统一管理
	// 线程池实现方式：程序启动时，一次性创建好一定数量的线程，当有任务到来时，调用空闲线程
	// 操作很复杂

	// 线程数量上限：2000以内
	// 查官方建议线程数目









	Sleep(60000);
	return 0;
}