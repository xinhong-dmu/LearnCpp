#include <iostream>
#include <thread>  //多线程头文件
#include <list>
#include <mutex>  //互斥量头文件

#include <windows.h> //sleep头文件                                   


class GameMsg {
public:
	void addRecvList() {
		for (int i = 1; i <= 10000; i++) {
			std::cout << "addRecvlist()执行，插入元素" << i << std::endl;
			std::unique_lock<std::mutex> ulGuard1(mutex1);
			msgRecvList.push_back(i); 
			conVar.notify_one(); //把wait()线程立即唤醒
			ulGuard1.unlock();
		}
	}

	void getRecvList() {
		int command = 0;
		while (true) {
			std::unique_lock<std::mutex> ulGuard1(mutex1);
			//wait()用来等待。第一个参数是unlock_lock容器，
			//第二个参数是false解锁互斥量并堵塞到本行命令，直至其他某个线程调用notify_one()成员函数为止
			//第二个参数为true，继续往下执行
			//如果没有第二个参数，直接堵塞至本行命令，一直等待至其他某个线程调用notify_one()成员函数为止
			conVar.wait(ulGuard1, [this] {  //一个lambda表达式就是一个可调用对象
				if (!msgRecvList.empty()) {
					return true;
				}
				else {
					return false;
				}
			});
			command = msgRecvList.front();
			msgRecvList.pop_front();
			ulGuard1.unlock();
			std::cout << "getRecvList()执行，执行元素" << command << std::endl;
		}
	}

private:
	std::list<int> msgRecvList;
	std::mutex mutex1;
	std::mutex mutex2;
	std::condition_variable conVar; //生成一个条件变量对象
};



int main() {
	GameMsg gm;
	std::thread getThread(&GameMsg::getRecvList, &gm);
	std::thread addThread(&GameMsg::addRecvList, &gm);
	addThread.join();
	getThread.join();

	// 条件变量：std::condition_variable, wait(), notify_one()
	//线程A：等待一个条件满足
	//线程B：往消息队列放消息

	//std::condition_variable是一个和条件相关的类，说白了就是等待一个条件的达成
	//condition_variable 与互斥量相互配合使用，用来生成这个类对象

	//虚假唤醒，视频13节





	Sleep(60000);
	return 0;
}