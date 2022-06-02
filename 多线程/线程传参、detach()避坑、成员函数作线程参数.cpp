#include <iostream>
#include <thread>  //多线程头文件
#include <string>

#include <windows.h> //sleep头文件
using std::string;

class A {
public:
	int m_i;
	//带一个参数的构造函数
	A(int a) : m_i(a) {
		std::cout << "A::A(int a)构造函数执行" <<this<<"thread_id="<<std::this_thread::get_id()<< std::endl;

	}
	//拷贝构造函数——这里是类型转换构造函数讲一个int转为类对象
	A(const A &a) : m_i(a.m_i) {
		std::cout << "A::A(const A &a)拷贝构造函数执行" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}
	~A(){
		std::cout << "A::~A析构函数执行" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}

	void threadWork(int n) {
		std::cout << "A::threadWork()函数执行" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}

	void operator()(int n) {
		std::cout << "A::()函数执行" << "thread_id=" << std::this_thread::get_id() << this << std::endl;
	}
};

// 如果传递类对象，全部都在创建线程时构建临时对象，并使用显式类型转换——(A)(临时对象), 并且函数参数列表使用引用来接(否则系统会多构造一次对象(一共三次了))
// 使用引用必须加const
void myPrint1(const int i, A &pBuff) { // 不建议线程函数的参数列表使用引用或者指针,字符数组用const string &str代替
	std::cout << "i = "<< i << std::endl; // i不是mVar的引用，而是复制的值传递
	pBuff.m_i = 199;
	std::cout << "子线程myPrint1的参数地址为：" << &pBuff <<"thred_id="<< std::this_thread::get_id() << std::endl;
}

void myPrint2(std::unique_ptr<int> pzn) {
	std::cout << "子线程myPrint2的参数地址为：" << &pzn << "thred_id=" << std::this_thread::get_id() << std::endl;
}


int main() {
	std::cout << "主线程id=" << std::this_thread::get_id() << std::endl;
	// 传递临时对象作为线程参数
	int mVar = 1;
	int mySecondPar = 12;
	// 只要用临时构造的A类对象作为参数传递给线程，那么一定能够在主线程执行完毕前八线程函数的第二个参数构建出来，确保detach()安全运行
	std::thread myThread1(myPrint1, mVar, A(mySecondPar));// 传入函数名和和参数列表是并列的关系,将字符数组显式类型转换为string能够保证线程安全，单个变量也同意通过类中的类型转换——mySecondPar
	myThread1.join(); // 采用复制的值，在detach()中都是安全的

	//总结detach()的坑
	/*
	1.若是简单数据类型int，建议值传递不要用引用，防止不同编译器节外生枝
	2.如果传递类对象，全部都在创建线程时构建临时对象，并使用显式类型转换——(A)(临时对象),并且函数参数列表使用引用来接(否则系统会多构造一次对象(一共三次了))
****3.****建议不使用detach()
	*/

	// 线程ID通过 std::this_thread::get_id(线程对象)  获得

	// 传递类对象作为线程参数 —— std::ref 函数
	A a(10);
	std::thread myThread2(myPrint1, mVar, std::ref(a));  // std::ref(a) 将a的引用传递到线程中，线程函数参数列表就不用const了
	myThread2.join();

	// 传递独占型智能指针作为线程参数 —— std::move 函数
	std::unique_ptr<int> myPtr(new int(100)); //创建独占型指针
	//std::thread myThread3(myPrint2, myPtr);不能直接传独占型智能指针为参数
	std::thread myThread3(myPrint2, std::move(myPtr)); // 独占型指针需要move传递进线程函数参数列表
	myThread3.join();// 独占型智能指针不能使用detach()

	// 成员函数指针作线程函数
	A a2(10);
	std::thread myThread4(&A::threadWork,a2,22);
	myThread4.join();

	// operator()仿函数作为线程函数入口
	A a3(33);
	std::thread myThread5(&A::operator(),a3, 333);
	myThread5.join();


	std::cout << "主线程执行完毕" << std::endl;
	Sleep(60000);

	return 0;
}