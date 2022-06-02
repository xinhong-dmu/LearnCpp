#include <iostream>
#include <thread>  //���߳�ͷ�ļ�
#include <string>
#include <vector>
#include <list>
#include <windows.h> //sleepͷ�ļ�
using std::string;


// ȫ�ֹ�������
std::vector <int> gV = { 1,2,3 };

void creatThread1(int num) {
	std::cout << "idΪ��" << std::this_thread::get_id() << "��ӡ��ȫ�ֱ���gV��ֵ=" << gV[0] << gV[1] << gV[2] << std::endl;
}

class GameMsg {
public:
	void addRecvList() {
		for (int i = 0; i < 10; i++) {
			std::cout <<"addRecvMsg��������"<< i << std::endl;
			msgRecvList.push_back(i);
			Sleep(1000);
		}
	}

	void getRecvList() {
		for (int i = 0; i < 10; i++) {
			if (!msgRecvList.empty()) {
				int  command = msgRecvList.front();
				std::cout << "getRecvList��ȡ����" << i << std::endl;
				msgRecvList.pop_front();
				// ��������...
			}
			else {
				std::cout << "�����Ϣ����Ϊ��" << std::endl;
				break;
			}
			Sleep(1000);
		}
		std::cout << "�����ִ�����" << std::endl;
	}

private:
	std::list<int> msgRecvList; //���ڴ�Ž���������������
};

int  main() {
	//vector���������������������߳�
	std::vector <std::thread> vt;
	// ����߳�ִ��˳���������
	for (int i = 1; i <= 5; i++) {
		vt.push_back(std::thread(creatThread1, i));
	}
	for (auto iter = vt.begin(); iter != vt.end(); iter++) {
		(*iter).join();  // �Ƽ�join()
	}

	// ���ݹ���
	// 1.ֻ�����ݵĹ���ʵ��ȫ�ȶ��ģ�ֱ�Ӷ�����
	// 2.�ж���д������ʱ����д��д��ʱ���ܶ�������������ͬʱ�������̶߳�/дͬһ����
	
	// �������ݵı�������
	// ������Ϸ��������һ���߳̽�����ҵ�����ŵ�����һ���̴߳�������ȡ������������
	// list��Ƶ���Ĳ���ɾ��Ч�ʸ�
	GameMsg gm;
	std::thread addThread(&GameMsg::addRecvList, &gm); // ��Ա�������߳���ڣ���������ʱ���ò��ܱ�֤�߳��õ���ͬһ�����󣬷�ֹthread�Զ�����һ��
	std::thread getThread(&GameMsg::getRecvList, &gm);
	addThread.join();
	getThread.join();



	std::cout << "-------�����̽���--------" << std::endl;
	Sleep(20000);
	return 0;
}