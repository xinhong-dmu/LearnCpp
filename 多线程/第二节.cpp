#include <iostream>
#include <thread>  //多线程头文件


//线程调用对象可以是函数
void myThread1() {
	std::cout << "我创建的函数线程1开始执行了" << std::endl;

	std::cout << "我创建的函数线程1执行完毕了" << std::endl;
}

//线程调用对象可以是类
class TA {
public:
	int &m_i;
	TA(int &i) :m_i(i) {
		std::cout << "TA的构造函数被执行" << std::endl;
	}
	TA(const TA &ta) :m_i(ta.m_i) {
		std::cout << "TA()拷贝构造函数被执行" << std::endl;
	}
	~TA() {
		std::cout << "TA()析构构造函数被执行" << std::endl;
	}
	void operator()() {}
};


int main() {
	//主线程从main（）开始执行
	std::cout << "主线程执行开始" << std::endl;
	//自己创建的线程也需要从一个函数（初始函数）开始执行
	std::thread myThread1(myThread1);//thread是标准库里面的类，myThread1是一个可调用对象。创建了一个线程，线程入口起点为myThread1，开始执行
	//通过joinable()判断是否成功使用join()/detach()
	if (myThread1.joinable() == true) {
		std::cout << "myThread1 joinable == true" << std::endl;
	}
	else {
		std::cout << "myThread1 joinable == fasle" << std::endl;
	}
	myThread1.join();//阻塞主线程，等待子线程执行完毕，与主线程汇合，然后主线程才开始执行

	//detach()导致线程失去控制，应用场景为：主线程与子线程互不干扰的情况
	int i = 6;//i为主线程的局部变量，当主线程执行结束i就被销毁了
	TA ta(i);//创建一次对象，需要一次析构
	std::thread myThread2(ta);//将对象利用拷贝构造函数拷贝给线程myThread2，线程中又需要析构一次
	if (myThread2.joinable() == true) {
		std::cout << "myThread2 joinable == true" << std::endl;
	}
	else {
		std::cout << "myThread2 joinable == fasle" << std::endl;
	}
	myThread2.detach();//非阻塞线程，无需等待子线程执行完毕，与主线程分离，各走各的，并与主线程失去关联。此时子线程被c++运行时库接管，由他清理资源（守护线程）
	
	//lambda表达式作为线程入口
	auto myLambdaThread = [] {
		std::cout << "myLambdaThread 开始" << std::endl;

		std::cout << "myLambdaThread 结束" << std::endl;
	};
	std::thread myThread3(myLambdaThread);
	myThread3.detach();




	std::cout << "主线程执行完毕" << std::endl;
	system("pause");

	return 0;
}