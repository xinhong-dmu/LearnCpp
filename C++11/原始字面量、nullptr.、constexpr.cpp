#include <iostream>
#include <string>

using std::string;

void func(const int num) {
	const int count = 10;
	constexpr int sum = count + 1;  //这是一个常量表达式
	int arr1[count];  //正确，静态数组长度必须是常量
	//int arr2[num];  //编译期报错，函数的参数列表中的const修饰表示变量只读，不是常量
	int arr3[sum]; // 正确，constexpr修饰的表达式为常量表达式

}

// constexpr不能修饰结构体或者类，const可以
class A {
public:
	// constexpr修饰构造函数时，函数体必须为空，并采用初始化列表方式为成员赋值
	constexpr A():a(10) {}
private:
	int a;
};


void main() {
	// 普通字符串中的转义字符‘\’会与后续字母结合
	string str1 = "D:\a\t\c.exe";
	std::cout << str1 << std::endl;

	// 没有C++11事，需连续两个转义字符“\\”表示一个转义字符“\”
	string str2 = "F:\\a\\t\\c.exe";
	std::cout << str2 << std::endl;

	// C++11中引入原始字面量，顾名思义原来是什么就是什么。用 R"描述字符串(想要表达的字符串)描述字符串"，描述字符串可省略，描述字符串必须一样，必须用英文
	string str3 = R"11(D:\a\t\c.exe)11";
	std::cout << str3 << std::endl;

	// NULL，C++不能将NULL隐式转化为int
	int *ptr1 = NULL; //查看NULL定义可知，在C++中NULL被定义为int型的0，C中NULL被定义viod*型的0
	double *ptr2 = NULL;
	char *ptr3 = NULL;
	void *ptr4 = NULL;
	int *ptr5 = (int*)ptr4; // 已经定义成NULL的指针变量不能隐式转化为int型，需要强制类型转换
	// nullptr可以自动转化为各种类型的0，建议在C++11中所有的NULL转化为nullptr
	int *ptr6 = nullptr;
	void *ptr7 = nullptr;
	int *ptr8 = (int*)ptr7;// 已经定义成nullptr的指针变量不能隐式转化为int型，需要强制类型转换


	// constexpr用来告诉编译器这是常量表达式（只有常量之间的运算，不能有变量）
	// 常量表达式在编译器出结果，节省时间
	const int num = 10;
	func(num);
	// 和NULL一样，建议能够用constexpr就用constexpr
	// 类和结构体的定义除外，定义类和结构体时加constexpr出错，类、结构体和模板函数可以在创建成员或实例化时加constexpr
	// 定义函数模板时，如果不是常量表达式函数则constexpr无效
	constexpr A s1; //结构体直接赋值用{num}，constexpr修饰的是a成员
	//s1.a = 11; //错误

	// constexptr修饰函数返回值时，函数必须为常量表达式函数，要求如下：
	// 1.函数必须有返回值，且return的返回的表达式必须为常量表达式
	// 2.constexpr函数在调用之前就必须定义，不能 声明-调用-定义
	// 3.constexpr函数体内不能出现非常量表达式以外的语句（可以出现：using用来起别名/typedef/assert/return）

	// constexpr修饰构造函数时，函数体必须为空，并采用初始化列表方式为成员赋值



	system("pause");
}