#include<iostream>
#include<string>
using namespace std;
/*
Ҫ��
1 ���Զ��Զ���������������͵����ݽ��д洢
2 �������е����ݴ洢������
3 ���캯���п��Դ������������
4 �ṩ�������������Լ�operate=��ֹǳ��������
5 �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
6 ����ͨ���±�ķ�ʽ���������е�Ԫ��
7 ���Ի�ȡ�����е�ǰԪ�ظ��������������
*/

template<class t>
class array_inputed
{
public:
	array_inputed(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		this->position= new t[this->capacity];//��t���͵�ָ����տ��ٵ�t���͵����ݣ�Ȼ��ָ�뱣�洫�������µ�����
		cout << "��������Ϊ"<< capacity<< endl;
	}
	//��ֹǳ�����Ŀ������캯��
	array_inputed(const array_inputed&arr)
	{
		this->capacity = arr.capacity;
		this->size = arr.size;
		//this->position = arr.position;ǳ����ʹ���ظ��ͷŶ�������
		this->position = new t[arr.capacity];//������������ڶ����������ݵ��ڴ�ռ䣬[]��д����Ԫ�ظ���������������һλ
		//��ԭ����������ݿ������µ��ڴ�ռ���
		for (int i = 0; i < arr.capacity; i++)
		{
			this->position[i] = arr.position[i];
		}
	}
	//��Ҫ����operator=��ֹǳ�����Ĳ���
	array_inputed& operator=(const array_inputed&arr)
	{
		//���ж�ԭ�������Ƿ������ݣ�����Ҫ���ͷ�
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
	//β�巨
	void add_data(const t &data)
	{
		//�ж������Ƿ���ڴ�С�������ھ�д����ȥ��
		if (this->capacity == this->size)
		{
			return;
		}
		else
		{
			this->position[this->size] = data;//β��
			this->size++;//��������Ԫ�ظ���
		}
	}
	//βɾ��
	void del_data()
	{
		//���û����ʲ������һ��Ԫ��
		//�ж������Ƿ���Ԫ��
		if (this->size == 0)
		{
			return;
		}
		else
		{
			this->size--;
		}
	}
	//ͨ���±���������е�Ԫ��,��ΪԪ�ص��������Ͳ���ȷ��������[]������������
	t &operator[](int index)//����&����t���ɽ������ķ���ֵ��Ϊ��ֵ������ֻ����Ϊ��ֵ
	{
		return position[index];
	}
	//��������Ԫ�ظ���
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
	t * position;//position���ڴ洢����
	int capacity;//��Ҫ������ٸ�����
	int size;//�Ѿ��ж��ٸ�����
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