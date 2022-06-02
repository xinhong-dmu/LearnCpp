#include<iostream>
#include<string>
using namespace std;
/*
要求：
1 可以对自定义或内置数据类型的数据进行存储
2 将数组中的数据存储到堆区
3 构造函数中可以传入数组的容量
4 提供拷贝函数构造以及operate=防止浅拷贝问题
5 提供尾插法和尾删法对数组中的数据进行增加和删除
6 可以通过下标的方式访问数组中的元素
7 可以获取数组中当前元素个数和数组的容量
*/

template<class t>
class array_inputed
{
public:
	array_inputed(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		this->position= new t[this->capacity];//用t类型的指针接收开辟的t类型的数据，然后指针保存传给数组新的数据
		cout << "数组容量为"<< capacity<< endl;
	}
	//防止浅拷贝的拷贝构造函数
	array_inputed(const array_inputed&arr)
	{
		this->capacity = arr.capacity;
		this->size = arr.size;
		//this->position = arr.position;浅拷贝使得重复释放堆区数据
		this->position = new t[arr.capacity];//深拷贝——重新在堆区开辟数据的内存空间，[]里写数组元素个数就是数组的最后一位
		//将原来数组的数据拷贝到新的内存空间中
		for (int i = 0; i < arr.capacity; i++)
		{
			this->position[i] = arr.position[i];
		}
	}
	//还要利用operator=防止浅拷贝的操作
	array_inputed& operator=(const array_inputed&arr)
	{
		//先判断原来堆区是否有数据，若有要先释放
		if (this->position != NULL)
		{
			delete[] this->position;
			this->position = NULL;
			this->capacity = 0;
			this->size = 0;
		}
		this->capacity = arr.capacity;
		this->size = arr.size;
		this->position = new t[arr.capacity];
		for (int i = 0; i < arr.capacity; i++)
		{
			this->position[i] = arr.position[i];
		}
		return *this;
	}
	//尾插法
	void add_data(const t &data)
	{
		//判断容量是否等于大小，若等于就写不进去了
		if (this->capacity == this->size)
		{
			return;
		}
		else
		{
			this->position[this->size] = data;//尾插
			this->size++;//更新已有元素个数
		}
	}
	//尾删法
	void del_data()
	{
		//让用户访问不到最后一个元素
		//判断数组是否有元素
		if (this->size == 0)
		{
			return;
		}
		else
		{
			this->size--;
		}
	}
	//通过下标访问数组中的元素,因为元素的数据类型不明确，数组名[]不能正常访问
	t &operator[](int index)//加了&引用t，可将函数的返回值作为左值。否则只能作为右值
	{
		return position[index];
	}
	//返回数组元素个数
	int get_size()
	{
		return this->size;
	}

	~array_inputed()
	{
		if (position != NULL)
		{
			delete[] position;
			position = NULL;
		}
	}

private:
	t * position;//position用于存储数据
	int capacity;//将要加入多少个数据
	int size;//已经有多少个数据
};

class person
{
public:
	person() {};
	person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};






void print70(array_inputed<int>&a)
{
	for (int i = 0; i < a.get_size(); i++)
	{
		cout << a[i] << endl;
	}
}

void test70()
{
	array_inputed<int>a0(5);
	//array_inputed<int>a1(a0);
	//array_inputed<int>a2(100);
	//a2 = a0;

	for (int i = 0; i < 5; i++)
	{
		a0.add_data(i);
	}
	print70(a0);
	a0.del_data();
	cout << a0[0] << endl;

}

void print71(array_inputed<person>&a)
{
	for (int i = 0; i < a.get_size(); i++)
	{
		cout << a[i].name <<a[i].age<< endl;
	}
}
void test71()
{
	array_inputed<person>a0(3);
	person p1("q", 11);
	person p2("w", 22);
	person p3("e", 33);
		a0.add_data(p1);
		a0.add_data(p2);
		a0.add_data(p3);
	print71(a0);
	a0.del_data();
	cout << a0[0].name << endl;
}
void main()
{
	test70();
	test71();

	system("pause");
}