#include <iostream>
#include <thread>  //���߳�ͷ�ļ�
#include <string>
#include <vector>
#include <list>
#include <mutex>  //������ͷ�ļ�

#include <windows.h> //sleepͷ�ļ�
using std::string;

// ������ֻ������Ŀ�д���һ�������
class MyCAS {
private:
	//˽�л����캯��
	MyCAS() {}
	static MyCAS *myInstance; //��̬��Ա����ָ��
public:
	static MyCAS *getInstance() {
		// ֻ�е�һ�δ���ʱ(��̬ȫ��ָ��Ϊ��)�Żᴴ���¶����Ժ�̬ȫ��ָ��Ͳ�Ϊ����
		if (myInstance == nullptr) {
			myInstance = new MyCAS();
			static LaJiHuiShou ljhs; // ��㴴��һ���������ն����ڸö�������ʱ��new���ڴ�delete
		}
		return myInstance;
	}

	// ��������,�����ͷŶ���
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

// �����ʼ����̬��Ա����
MyCAS *MyCAS::myInstance = nullptr;

void main() {
	// ֻ��ͨ���������нӿڴ�������
	//MyCAS a; //����
	MyCAS *p1 = MyCAS::getInstance();
	p1->func();
	MyCAS::getInstance()->func();

	// ����ģʽ���ݹ���




	Sleep(60000);
}