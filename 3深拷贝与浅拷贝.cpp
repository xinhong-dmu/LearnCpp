#include<iostream>
#include<string>
using namespace std;
//深拷贝就是将要拷贝的数据在各自的单元中创建一份，互不影响
/*
深拷贝操作步骤:
1.创建成员变量指针——数据类型 *指针；
2.利用有参构造函数给指针地址开辟新的空间并给指针地址赋值——{指针 = new 数据类型(函数变量) ;}//开辟一个新地址给这个数据
3.利用成员函数给指针地址赋值——参数一般为对象的引用{指针 = new 数据类型(*对象.指针)}//开辟一个新的地址并拷贝这个数据给到新地址，这样这个数据就互不影响了
4.析构函数进行堆区的释放——{if(指针！=NULL;{deldte 指针；指针=NULL;})}
 */
class person
{
public:
	person(int age, int height)
	{
		p_age = age;
		//利用new来将局部变量放入堆区，并用指针给变量赋初值
		p_h = new int(height);//p_h接收new开辟的堆区数据，然后调用的话还要解引用加*
	}
	person(const person &p)
	{
		p_age = p.p_age;//浅拷贝
		//编译器默认的是p_h=p.p_h;是错误的
		//改成深拷贝操作
		//深拷贝可以在堆区重新申请内存空间，进行拷贝操作
		p_h = new int(*p.p_h);//
	}
	~person()
	{//在析构函数中，利用delete将堆区开辟的数据做释放
		if (p_h != NULL)
		{
			delete p_h;
			p_h = NULL;//防止野指针，规范化操作
		}
		//浅拷贝会使堆区内存重复释放，深拷贝可解决
	}

	int p_age;
	int *p_h;//创建解引用，通过指针赋初值方式，可以利用new来将局部变量放入堆区
};

void test31()
{
	person p1(18,170);
		cout << "p1的年龄为：" << p1.p_age << " 。   p1的身高为: " <<* p1.p_h << endl;
		person p2(p1);//无需再类中创建拷贝构造函数，系统会默认有一个拷贝构造函数
		cout << "p2的年龄为：" << p2.p_age << " 。   p2的身高为: " <<* p2.p_h << endl;
}


int main()
{
	test31();


	system("pause");
	return 0;
}