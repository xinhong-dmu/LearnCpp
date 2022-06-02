#include<iostream>
#include<string>
using namespace std;
#define MAX 3//�궨���������

//show menu function
void show_menu()
{
	cout << "  *****  ************  *****  " << endl;
	cout << "  *****  1.�����ϵ��  *****  "<< endl;
	cout << "  *****  2.��ʾ��ϵ��  *****  " << endl;
	cout << "  *****  3.ɾ����ϵ��  *****  " << endl;
	cout << "  *****  4.������ϵ��  *****  " << endl;
	cout << "  *****  5.�޸���ϵ��  *****  " << endl;
	cout << "  *****  6.�����ϵ��  *****  " << endl;
	cout << "  *****  0.�˳�ͨѶ¼  *****  " << endl;
	cout << "  *****  ************  *****  " << endl;
};
//��ϵ�˽ṹ��
struct person
{
	string name;
	int telenumber;
};

//ͨѶ¼�ṹ��
struct address_book
{
	struct person person_array[MAX];//��ϵ�������������
	int num_person;
};

//�����ϵ�˵ĺ���
void add_person(address_book*ab)//������ʹ�ýṹ���ַ����ʱ��������ʱ�ṹ��ָ��
{
	if (ab->num_person > MAX)
	{
		cout << "ͨѶ¼�������޷�������û�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		ab->person_array[ab->num_person].name = name;//��ָ���ַ���δ��ݸ�������������������
		int telenumber;
		cout << "������绰���룺" << endl;
		cin >> telenumber;
		ab->person_array[ab->num_person].telenumber = telenumber;
		ab->num_person++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");//��������
	}
}

//��ʾ��ϵ�˺���
void show_person(address_book*ab)
{
	if (ab->num_person <= 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < ab->num_person; i++)
		{
			cout << "����:  " << ab->person_array[i].name
				<< "\t�绰�� " << ab->person_array[i].telenumber
				<< endl;
		}
	}
	system("pause");
	system("cls");//��������
}
//�����ϵ���Ƿ���ڣ������ڣ�������ϵ�����������е�λ�ã������ڣ�����-1
int exist(string name, address_book*ab)
{
	for (int i = 0; i < ab->num_person; i++)//��ַ���ݵ�forѭ����i���ǵ�ַ
	{
		if (name == ab->person_array[i]. name)
		{
			return i;//�ҵ��Ļ����������±���
		}
	}
	cout << "���޴���" << endl;
	return -1;
}
//ɾ����ϵ��
void del_person(address_book*ab)
{
	cout <<"������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int re = exist(name, ab);
	if (re == -1){}
	else
	{
		for (int j = re; j < ab->num_person - re ; j++)//ɾ���������������Ԫ��ǰ�ƣ���������-1
		{
			ab->person_array[j].name = ab->person_array[j + 1].name;
			ab->person_array[j].telenumber = ab->person_array[j + 1].telenumber;
		}
		ab->num_person -= 1;
		cout <<name<<"�ѱ�ɾ��" << endl;
	}
	system("pause");
	system("cls");//��������
}
//��ѯ��ϵ��
void find_person(address_book*ab)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int re = exist(name, ab);
	if (re== -1) {}
	else
		cout << "����:  " << ab->person_array[re].name
		<< "\t�绰�� " << ab->person_array[re].telenumber
		<< endl;
	system("pause");
	system("cls");//��������
}
//�޸���ϵ��
void change_person(address_book*ab)
{
	cout << "������Ҫ�޸ĵ绰�������ϵ��" << endl;
	string name;
	cin >> name;
	int re = exist(name, ab);
	if (re == -1) {}
	else
	{
		cout << "������Ҫ�޸ĵĵ绰����" << endl;
		int telenumber;
		cin >> telenumber;
		ab->person_array[re].telenumber = telenumber;
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");//��������
}
//�����ϵ��
void clear_person(address_book*ab)
{
	//for (int i = 0; i < ab->num_person; i++)
	//		{
	//			ab->person_array[i].name = "";
	//			ab->person_array[i].telenumber =NULL;
	//		}
	cout << "�Ƿ�ȷ�����ͨѶ¼\n����1��ȷ�����\t���������������ȡ�����" << endl;
	string a;
	cin >> a;
	if (a == "1")
	{
		ab->num_person = 0;//ͨ����������Ԫ�ظ�����մﵽ������յ�Ŀ��
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");//��������
}

int main()
{
	//����ͨѶ¼�ṹ�����
	struct address_book ab;
	//��ʼ��ͨѶ¼��ǰ��Ա����
	ab.num_person = 0;
	while (true)/*ֻ������0�Ż��˳�ѭ��*/
	{
		//call show_menu function
		show_menu();
		//input
		int input;
		cin >> input;
		switch (input)//��ִ������ж���ʱ����{}������������
		{
		case 1: /*�����ϵ�� */
			add_person(&ab);//Ϊ��ͨ���β�����ʵ�Σ���Ҫ�õ�ַ����
			break;
		case 2:/*��ʾ��ϵ�� */
			show_person(&ab);
			break;
		case 3:/*ɾ����ϵ�� */
			del_person(&ab);
			break;
		case 4:/*������ϵ�� */
			find_person(&ab);
			break;
		case 5:/*�޸���ϵ�� */
			change_person(&ab);
			break;
		case 6:/*�����ϵ�� */
			clear_person(&ab);
			break;
		case 0:/*�˳�ͨѶ¼ */
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");//���ִ��ڣ������
			return 0;//�����ֹ
			break;
		default:
			cout << "����������" << endl;
			system("pause");//���ִ��ڣ������
			system("cls");
			break;
		}
	}
}