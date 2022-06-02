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
			//std::lock_guard<std::mutex> msgGuard1(mutex1); //以“}”、“return”、“break”等结束符结束互斥锁的生命周期
														  // mutex1先锁定了资源msgRecvList
			// ....
			//std::lock_guard<std::mutex> msgGuard2(mutex2);
			std::lock(mutex1, mutex2); //相当于每个互斥量mutex都调用了lock()
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //不用写unlock()了
			std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
			msgRecvList.push_back(i);  //只保护写数据
			// 解锁顺序不影响死锁
			//mutex1.unlock(); //return结束前要保证有出口
			//mutex2.unlock();
		}
	}

	bool getMsgLULProc(int &command) {
		// 双重加锁，双重判断
		if (!msgRecvList.empty()) {
			//std::lock_guard类模板在构造函数里执行了mutex::lock()，在析构函数mutex::unlock()
			//std::lock_guard<std::mutex> msgGuard1(mutex1);
			//std::lock_guard<std::mutex> msgGuard2(mutex2); // 此时如果mutex2先锁定msgRecvList资源，但是msgRecvList先被被mutex1给锁定了，导致死锁
			std::lock(mutex1, mutex2); //相当于每个互斥量mutex都调用了lock()
			std::lock_guard<std::mutex> msgGuard3(mutex1, std::adopt_lock); //不用写unlock()了
			std::lock_guard<std::mutex> msgGuard4(mutex2, std::adopt_lock);
			if (!msgRecvList.empty()) {
				command = msgRecvList.front();
				msgRecvList.pop_front();
				//mutex1.unlock(); //return结束前要保证有出口
				//mutex2.unlock();
				return true;
			}
			//mutex1.unlock(); //return结束前要保证有出口
			//mutex2.unlock();
			return false;

		}
	}

	void getRecvList() {
		int command = 0;
		for (int i = 0; i < 10000; i++) {
			if (getMsgLULProc(command)) {
				std::cout << "玩家命令为："<< command << std::endl;
			}
			else {
				std::cout << "玩家消息链表为空" << std::endl;
			}
		}
		std::cout << "--------命令处理执行完毕--------" << std::endl;
	}

private:
	std::list<int> msgRecvList; //用于存放接收玩家命令的容器
	std::mutex mutex1;
	std::mutex mutex2;
};

int main() {

	GameMsg gm;
	std::thread addThread(&GameMsg::addRecvList, &gm); // 成员函数作线程入口，函数对象时引用才能保证线程用的是同一个对象，防止thread自动复制一份
	std::thread getThread(&GameMsg::getRecvList, &gm);
	addThread.join();
	getThread.join();

	// 互斥量mutex：互斥量本质是一个类对象，理解成锁，多个线程尝试用lock()成员函数加锁，只有一个线程可以锁定成功（成功的标志是lock()函数返回了）
	// 如果没锁成功，那么会一直尝试直到锁定成功
	// 只保护“写”“判断”时需要保护的“数据”
	// lock() 与 unlock() 必须成对使用
	// std::lock_guard类模板取代lock()和unlock()，当程序员遗漏unlock()帮助补充unlock()。类似智能指针（程序员忘记释放内存，帮你释放）

	// 死锁的产生：几个线程索要的资源被其他线程相互锁定，导致一个资源也出不来
	// 只要保证两个互斥锁上锁的顺序一致就不会死锁

	// std::lock()函数模板：能够一次锁定std::lock(互斥量1,互斥量n)至少两个互斥量
	// 每个lock()都需要搭配unlock() 或者 建议std::lock_guard <std::mutex> 名(互斥锁1,互斥锁n,std::adopt_lock)，防止自己遗漏unlock()
	// 完全避免在多个线程中因为锁头顺序问题导致的死锁问题
	// 要么几个互斥量都锁住，要么都没锁住。



	std::cout << "---------主线程执行完毕---------" << std::endl;

	Sleep(60000);
	return 0;
}