#include <iostream>
#include <thread>  //���߳�ͷ�ļ�
#include <list>
#include <mutex>  //������ͷ�ļ�

#include <windows.h> //sleepͷ�ļ�                                   


class GameMsg {
public:
	void addRecvList() {
		for (int i = 1; i <= 10000; i++) {
			std::cout << "addRecvlist()ִ�У�����Ԫ��" << i << std::endl;
			std::unique_lock<std::mutex> ulGuard1(mutex1);
			msgRecvList.push_back(i); 
			conVar.notify_one(); //��wait()�߳���������
			ulGuard1.unlock();
		}
	}

	void getRecvList() {
		int command = 0;
		while (true) {
			std::unique_lock<std::mutex> ulGuard1(mutex1);
			//wait()�����ȴ�����һ��������unlock_lock������
			//�ڶ���������false�������������������������ֱ������ĳ���̵߳���notify_one()��Ա����Ϊֹ
			//�ڶ�������Ϊtrue����������ִ��
			//���û�еڶ���������ֱ�Ӷ������������һֱ�ȴ�������ĳ���̵߳���notify_one()��Ա����Ϊֹ
			conVar.wait(ulGuard1, [this] {  //һ��lambda���ʽ����һ���ɵ��ö���
				if (!msgRecvList.empty()) {
					return true;
				}
				else {
					return false;
				}
			});
			command = msgRecvList.front();
			msgRecvList.pop_front();
			ulGuard1.unlock();
			std::cout << "getRecvList()ִ�У�ִ��Ԫ��" << command << std::endl;
		}
	}

private:
	std::list<int> msgRecvList;
	std::mutex mutex1;
	std::mutex mutex2;
	std::condition_variable conVar; //����һ��������������
};



int main() {
	GameMsg gm;
	std::thread getThread(&GameMsg::getRecvList, &gm);
	std::thread addThread(&GameMsg::addRecvList, &gm);
	addThread.join();
	getThread.join();

	// ����������std::condition_variable, wait(), notify_one()
	//�߳�A���ȴ�һ����������
	//�߳�B������Ϣ���з���Ϣ

	//std::condition_variable��һ����������ص��࣬˵���˾��ǵȴ�һ�������Ĵ��
	//condition_variable �뻥�����໥���ʹ�ã�����������������

	//��ٻ��ѣ���Ƶ13��





	Sleep(60000);
	return 0;
}