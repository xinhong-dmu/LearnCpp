#include <iostream>
#include <thread>  //多线程头文件
#include <string>
#include <vector>
#include <list>
#include <mutex>  //互斥量头文件

#include <windows.h> //sleep头文件
using std::string;

// 单例类只能在项目中创建一个类对象
class MyCAS {
private:
	//私有化构造函数
	MyCAS() {}
	static MyCAS *myInstance; //静态成员变量指针
public:
	static MyCAS *getInstance() {
		// 只有第一次创建时(静态全局指针为空)才会创建新对象，以后静态全局指针就不为空了
		if (myInstance == nullptr) {
			myInstance = new MyCAS();
			static LaJiHuiShou ljhs; // 随便创建一个垃圾回收对象，在该对象析构时将new的内存delete
		}
		return myInstance;
	}

	// 类中套类,用来释放对象
	class LaJiHuiShou {
	public:
		~LaJiHuiShou() {
			if (MyCAS::myInstance != nullptr) {
				delete MyCAS::myInstance;
				MyCAS::myInstance = nullptr;
			}
		}
	};

	void func() {
		std::cout << "test" << std::endl;
	}


};

// 必须初始化静态成员变量
MyCAS *MyCAS::myInstance = nullptr;

void main() {
	// 只能通过调用类中接口创建对象
	//MyCAS a; //错误
	MyCAS *p1 = MyCAS::getInstance();
	p1->func();
	MyCAS::getInstance()->func();

	// 单例模式数据共享




	Sleep(60000);
}