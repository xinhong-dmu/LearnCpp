#include <iostream>
#include <thread>  //多线程头文件
#include <mutex>  //互斥量头文件
#include <ctime>  //程序执行计时
#include <atomic>  //原子操作头文件

#include <windows.h> //Sleep头文件     

//static int gCount = 0;
static std::atomic<int> gCount = 0;  //利用原子操作封装了一个int的全局静态变量
static std::mutex gMutex1;
static std::atomic<bool> isEnd = false;  //子线程退出标记

void addCount() {
	for ( int i = 0;i < 10000;i++ ) {
		if ( isEnd == true ) {
			break;
		}
		//gMutex1.lock(); // 执行时间350ms
		gCount++;  //原子操作执行时间120ms ≈ 1/3 互斥锁
		//gMutex1.unlock();
		std::cout << "Thread id: " << std::this_thread::get_id() << "  gCount = "<<gCount << std::endl;
	}
	std::cout << "-----Thread id: " << std::this_thread::get_id() << "退出-----" << std::endl;
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
	// 原子操作std::atomic类模板用来来封装某个类型的值
	// 多个线程对同一变量写操作是不稳定的
	// 互斥量：通过锁和开锁，在多线程保护共享数据，但是每次都要锁和解锁，速度慢
	// 原子操作是 不需要互斥量的无锁 多线程并发

	// 原子操作是在多线程中 不会被打断 的 一个变量 的读写
	// 原子操作只针对一个变量，即“最小的不可分割的操作”，要么完成要么没完成
	// 原子操作针对++，--，+=，&=，|=，^=，其他表达式不一定支持，慎用
	//gCount = gCount + 1;  //不是原子操作，结果不对

	std::cout << atom1;// 这行不是原子操作，atom会变

	// 原子操作之间不允许直接复制、拷贝 atom2 = atom1 ;//errow
	std::atomic<int> atom2(atom1.load());  //原子操作的复制用 原子对象.load()装载

	//以原子操作写：.score() , 重载后的=
	atom2.store(2);
	atom2 = 3;






	std::thread myThread1(addCount);
	std::thread myThread2(addCount);
	std::thread myThread3(cinEnd);
	myThread1.join();
	myThread2.join();
	myThread3.join();















	std::cout <<"gCount="<< gCount << std::endl;

	std::cout <<"执行时间：" <<clock() - stateTime<<"ms" << std::endl;
	Sleep(60000);
	return 0;
}