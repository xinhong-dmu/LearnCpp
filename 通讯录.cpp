#include<iostream>
#include<string>
using namespace std;
#define MAX 3//宏定义最大人数

//show menu function
void show_menu()
{
	cout << "  *****  ************  *****  " << endl;
	cout << "  *****  1.添加联系人  *****  "<< endl;
	cout << "  *****  2.显示联系人  *****  " << endl;
	cout << "  *****  3.删除联系人  *****  " << endl;
	cout << "  *****  4.查找联系人  *****  " << endl;
	cout << "  *****  5.修改联系人  *****  " << endl;
	cout << "  *****  6.清空联系人  *****  " << endl;
	cout << "  *****  0.退出通讯录  *****  " << endl;
	cout << "  *****  ************  *****  " << endl;
};
//联系人结构体
struct person
{
	string name;
	int telenumber;
};

//通讯录结构体
struct address_book
{
	struct person person_array[MAX];//联系人数组最多人数
	int num_person;
};

//添加联系人的函数
void add_person(address_book*ab)//函数中使用结构体地址传递时，（）里时结构体指针
{
	if (ab->num_person > MAX)
	{
		cout << "通讯录已满，无法添加新用户" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		ab->person_array[ab->num_person].name = name;//将指针地址依次传递给人数，正好依次增加
		int telenumber;
		cout << "请输入电话号码：" << endl;
		cin >> telenumber;
		ab->person_array[ab->num_person].telenumber = telenumber;
		ab->num_person++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");//清屏操作
	}
}

//显示联系人函数
void show_person(address_book*ab)
{
	if (ab->num_person <= 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < ab->num_person; i++)
		{
			cout << "姓名:  " << ab->person_array[i].name
				<< "\t电话： " << ab->person_array[i].telenumber
				<< endl;
		}
	}
	system("pause");
	system("cls");//清屏操作
}
//检测联系人是否存在，若存在，返回联系人所在数组中的位置；不存在，返回-1
int exist(string name, address_book*ab)
{
	for (int i = 0; i < ab->num_person; i++)//地址传递的for循环，i就是地址
	{
		if (name == ab->person_array[i]. name)
		{
			return i;//找到的话就是数组下标编号
		}
	}
	cout << "查无此人" << endl;
	return -1;
}
//删除联系人
void del_person(address_book*ab)
{
	cout <<"请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int re = exist(name, ab);
	if (re == -1){}
	else
	{
		for (int j = re; j < ab->num_person - re ; j++)//删除操作：将后面的元素前移，并把数量-1
		{
			ab->person_array[j].name = ab->person_array[j + 1].name;
			ab->person_array[j].telenumber = ab->person_array[j + 1].telenumber;
		}
		ab->num_person -= 1;
		cout <<name<<"已被删除" << endl;
	}
	system("pause");
	system("cls");//清屏操作
}
//查询联系人
void find_person(address_book*ab)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int re = exist(name, ab);
	if (re== -1) {}
	else
		cout << "姓名:  " << ab->person_array[re].name
		<< "\t电话： " << ab->person_array[re].telenumber
		<< endl;
	system("pause");
	system("cls");//清屏操作
}
//修改联系人
void change_person(address_book*ab)
{
	cout << "请输入要修改电话号码的联系人" << endl;
	string name;
	cin >> name;
	int re = exist(name, ab);
	if (re == -1) {}
	else
	{
		cout << "请输入要修改的电话号码" << endl;
		int telenumber;
		cin >> telenumber;
		ab->person_array[re].telenumber = telenumber;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");//清屏操作
}
//清空联系人
void clear_person(address_book*ab)
{
	//for (int i = 0; i < ab->num_person; i++)
	//		{
	//			ab->person_array[i].name = "";
	//			ab->person_array[i].telenumber =NULL;
	//		}
	cout << "是否确定清空通讯录\n按“1”确定清空\t按“其他任意键”取消清空" << endl;
	string a;
	cin >> a;
	if (a == "1")
	{
		ab->num_person = 0;//通过把数组中元素个数清空达到数组清空的目的
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");//清屏操作
}

int main()
{
	//创建通讯录结构体变量
	struct address_book ab;
	//初始化通讯录当前人员个数
	ab.num_person = 0;
	while (true)/*只有输入0才会退出循环*/
	{
		//call show_menu function
		show_menu();
		//input
		int input;
		cin >> input;
		switch (input)//当执行语句有多行时，用{}把他们括起来
		{
		case 1: /*添加联系人 */
			add_person(&ab);//为了通过形参修饰实参，需要用地址传递
			break;
		case 2:/*显示联系人 */
			show_person(&ab);
			break;
		case 3:/*删除联系人 */
			del_person(&ab);
			break;
		case 4:/*查找联系人 */
			find_person(&ab);
			break;
		case 5:/*修改联系人 */
			change_person(&ab);
			break;
		case 6:/*清空联系人 */
			clear_person(&ab);
			break;
		case 0:/*退出通讯录 */
			cout << "欢迎下次使用" << endl;
			system("pause");//保持窗口，看输出
			return 0;//程序截止
			break;
		default:
			cout << "请认真输入" << endl;
			system("pause");//保持窗口，看输出
			system("cls");
			break;
		}
	}
}