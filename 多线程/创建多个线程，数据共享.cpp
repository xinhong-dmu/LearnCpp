#include <iostream>
#include <thread>  //多线程头文件
#include <string>
#include <vector>
#include <list>
#include <windows.h> //sleep头文件
using std::string;


// 全局共享数据
std::vector <int> gV = { 1,2,3 };

void creatThread1(int num) {
	std::cout << "id为：" << std::this_thread::get_id() << "打印的全局变量gV的值=" << gV[0] << gV[1] << gV[2] << std::endl;
}

class GameMsg {
public:
	void addRecvList() {
		for (int i = 0; i < 10; i++) {
			std::cout <<"addRecvMsg插入命令"<< i << std::endl;
			msgRecvList.push_back(i);
			Sleep(1000);
		}
	}

	void getRecvList() {
		for (int i = 0; i < 10; i++) {
			if (!msgRecvList.empty()) {
				int  command = msgRecvList.front();
				std::cout << "getRecvList获取命令" << i << std::endl;
				msgRecvList.pop_front();
				// 处理命令...
			}
			else {
				std::cout << "玩家消息链表为空" << std::endl;
				break;
			}
			Sleep(1000);
		}
		std::cout << "命令处理执行完毕" << std::endl;
	}

private:
	std::list<int> msgRecvList; //用于存放接收玩家命令的容器
};

int  main() {
	//vector容器方便管理大量创建的线程
	std::vector <std::thread> vt;
	// 多个线程执行顺序是随机的
	for (int i = 1; i <= 5; i++) {
		vt.push_back(std::thread(creatThread1, i));
	}
	for (auto iter = vt.begin(); iter != vt.end(); iter++) {
		(*iter).join();  // 推荐join()
	}

	// 数据共享
	// 1.只读数据的共享实安全稳定的，直接读就行
	// 2.有读有写：读的时候不能写，写的时候不能读————不能同时有两个线程读/写同一数据
	
	// 共享数据的保护案例
	// 需求：游戏服务器，一个线程接收玩家的命令放到链表，一个线程从链表中取出玩家命令并解析
	// list在频繁的插入删除效率高
	GameMsg gm;
	std::thread addThread(&GameMsg::addRecvList, &gm); // 成员函数作线程入口，函数对象时引用才能保证线程用的是同一个对象，防止thread自动复制一份
	std::thread getThread(&GameMsg::getRecvList, &gm);
	addThread.join();
	getThread.join();



	std::cout << "-------主进程结束--------" << std::endl;
	Sleep(20000);
	return 0;
}