#include<iostream>
#include<winsock.h>
#include<string>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization();

int main() {
	//���峤�ȱ���
	int send_len = 0;
	int recv_len = 0;
	//���巢�ͻ������ͽ��ܻ�����
	char send_v_buf[100];
	char send_a_buf[100];
	char recv_buf[100];
	//���岢��ʼ���������ݵ�����
	double v_vehicle[] = { 1.0 };
	//memset(v_vehicle, 1.0, sizeof(double)*10);
	double angle_vehicle[] = { 0.0 };
	//memset(angle_vehicle, 2.0, sizeof(double) * 10);
	//���������׽��֣����������׽���
	SOCKET s_server;
	//����˵�ַ�ͻ��˵�ַ
	SOCKADDR_IN server_addr;
	initialization();
	//���������Ϣ
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(1234);

	//�����׽���
	s_server = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(s_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		cout << "����������ʧ�ܣ�" << endl;
		WSACleanup();
	}
	else
	{
		cout << "���������ӳɹ���" << endl;
	}

	cout << "------ �Ƿ�ʼ�������ݣ�������y + enter����ʼ����������ȡ����------" << endl;
	while (1)
	{
		char is_transData;
		cin>> is_transData;
		if (is_transData == 'y' || is_transData == 'Y')
		{
			cout << "�������ٶȣ�" ;
			cin >> v_vehicle[0];
			// send message
			send_len = send(s_server, (char*)&v_vehicle[0], 100, 0);
			if (send_len < 0)
			{
				cout << "��ǰ�����ݽ��д��䣡" << endl;
				continue;
			}
			cout << "������ת��ǣ�";
			cin >> angle_vehicle[0];
			send_len = send(s_server, (char*)&angle_vehicle[0], 100, 0);
			if (send_len < 0)
			{
				cout << "��ǰ�����ݽ��д��䣡" << endl;
				continue;
			}
			
		}
		else
		{
			cout << "�����������ʱ�̰���y����ʼ��������" << endl;
			continue;
		}

		recv(s_server, (char*)&recv_buf, 100, 0);
		if (recv_buf == "-1")
		{
			cout << "��������ʧ�ܣ�" << endl;
			/*break;*/
		}
		else
		{
			cout << "���ݴ���ɹ���" << endl;
		}
	}
	//�ر��׽���
	closesocket(s_server);
	//�ͷ�DLL��Դ
	WSACleanup();
	return 0;
}

void initialization()
{
	//��ʼ���׽��ֿ�
	WORD w_req = MAKEWORD(2, 2);//�汾��
	WSADATA wsadata;
	int err;
	err = WSAStartup(w_req, &wsadata);
	if (err != 0)
	{
		cout << "��ʼ���׽��ֿ�ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "��ʼ���׽��ֿ�ɹ���" << endl;
	}
	//���汾��
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2)
	{
		cout << "�׽��ֿ�汾�Ų�����" << endl;
		WSACleanup();
	}
	else
	{
		cout << "�׽��ֿ�汾��ȷ��" << endl;
	}
}