#include<iostream>
#include<string>
#include<ctime>/*ʱ��ͷ�ļ�*/
using namespace std;

//�ȴ����ӽṹ��
struct stu
{
	string name;
	int score;
};
//�ڴ������ṹ��
struct teacher
{
	string name;
	struct stu s_array[5];
};

//�����з���Ƕ�׽ṹ�������˳�򣺰���Ƕ�׵�������.��Ƕ�׵�������.����
void score_list(struct teacher t_array[],int num_teacher,int num_stu)/*�����д��ṹ������[]*/
{
	string num_name[5] = { "1", "2","3","4","5" };
	for (int i = 0; i < num_teacher; i++)
	{
		t_array[i].name ="Teacher_";
		t_array[i].name += num_name[i];
		for (int j = 0; j < num_stu; j++)
		{
			t_array[i].s_array[j].name = "Student_";
			t_array[i].s_array[j].name += num_name[j];
			t_array[i].s_array[j].score = rand()%101;/*ȡ0~100�����*/
			cout <<t_array[i].name << " gives " << t_array[i].s_array[j].name
				<<" "<< t_array[i].s_array[j]. score<< "."<<endl;
		}
		cout << endl;
	}
};
int main()
{
	struct teacher t_array[3];
	struct stu s_array[5];
	int num_teacher =sizeof(t_array)/sizeof(t_array[0]);
	int num_stu = sizeof(s_array) / sizeof(s_array[0]);
	score_list(t_array, num_teacher, num_stu);
	srand((unsigned int)time(NULL));/*�����������*/
	system("pause");
	return 0;
}