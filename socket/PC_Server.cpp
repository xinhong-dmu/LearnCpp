#include<iostream>
#include<winsock.h>
#include<sstream> //char* ת��Ϊ double

#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization();
int main()
{
	//���峤�ȱ���
	int send_len = 0;
	int recv_len = 0;
	int len = 0;
	//���巢�ͻ������ͽ��ܻ�����
	char send_buf[100];
	char recv_v_buf[100];
	memset(recv_v_buf, 200.0, sizeof(double) * 100);
	char recv_a_buf[100] ;
	//���岢��ʼ���������ݵ�����
	double v_vehicle[10];
	memset(v_vehicle, 200.0, sizeof(double)*10);
	double angle_vehicle[10];
	memset(angle_vehicle, 0, sizeof(double) * 10);
	//���������׽��֣����������׽���
	SOCKET s_server;  //�׽�����Linux��ΪSOCKET�ͣ�Windows��Ϊint�ͣ�����ͻ��˶˿ںź�IP��ַ
	SOCKET s_accept;  //�׽���Linux��ΪSOCKET�ͣ�Windows��Ϊint�ͣ�����ͻ��˶˿ںź�IP��ַ
					  //����˵�ַ�ͻ��˵�ַ
	SOCKADDR_IN server_addr;  //����ͻ��˶˿ںź�IP��ַ
	SOCKADDR_IN accept_addr;  //����ͻ��˶˿ںź�IP��ַ
	initialization();
	//���������Ϣ
	server_addr.sin_family = AF_INET;    //��ַ��ΪIPv4Э��
	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);  /*��long��������(IP��ַ)�������ֽ���ת��Ϊ�����ֽ���INADDR_ANY��ָ��������IP��ַ*/
	server_addr.sin_port = htons(1234);  //��short��������(�˺ſ�)�������ֽ���ת��Ϊ�����ֽ���

										 //�����׽���
	s_server = socket(AF_INET, SOCK_STREAM, 0);  //��ַ��, ���ݴ�������, Э��(TCP or UDP)
	if (bind(s_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		cout << "�׽��ְ�ʧ�ܣ�" << endl;
		WSACleanup();
	}
	else
	{
		cout << "�׽��ְ󶨳ɹ���" << endl;
	}

	//�����׽���Ϊ����״̬
	// listen (���м������׽��֣����������г���)������״̬���󷵻�-1
	if (listen(s_server, SOMAXCONN) == -1) //listen()����ֵΪint��SOMAXCONN��ϵͳ����������г���
	{
		cout << "���ü���״̬ʧ�ܣ�" << endl;
		WSACleanup(); //��ֹ��Windows Sockets�������߳��ϵĲ���.
	}
	else
	{
		cout << "���ü���״̬�ɹ���" << endl;
	}
	cout << "��������ڼ������ӣ����Ժ�...." << endl;

	//������������accept() ����������ִ�У�������벻�ܱ�ִ�У���ֱ�����µ���������
	len = sizeof(SOCKADDR);
	s_accept = accept(s_server, (SOCKADDR *)&accept_addr, &len);
	if (s_accept == SOCKET_ERROR)
	{
		cout << "����ʧ�ܣ�" << endl;
		WSACleanup();
		return 0; //����ʧ�ܣ�ֱ�ӷ��ؽ���
	}
	cout << "���ӽ�����׼����������" << endl;

	//�÷��ص��׽��ֺͿͻ��˽���ͨ�ţ���������
	while (1)
	{   //recv(���ն��׽��֣����ڴ���յ����ݵĻ�������buf���ȣ�һ����0)
		int recv_v_len = recv(s_accept, (char*)&recv_v_buf, 100, 0);
		int recv_a_len = recv(s_accept, (char*)&recv_a_buf, 100, 0);
		if (recv_v_len <= 0 || recv_a_len <= 0) //��������ʵ��copy���ֽ�����ֱ��û�пɷ��ص�����
		{
			cout << "����ʧ�ܣ�" << endl;
			int recv_flag = -1;
			send(s_accept, (char*)&recv_flag, 100, 0);
			break;
		}
		else
		{
			cout  <<"�ٶȣ�"<<atof(recv_v_buf) << "   ת��ǣ�" << atof(recv_a_buf) << endl;
		}
		recv_v_len = 0;
		recv_a_len = 0;
		// �����Ƿ���յ�����
		send_len = send(s_accept, send_buf, 100, 0);
		if (send_len < 0)
		{
			cout << "����ʧ�ܣ�" << endl;
			continue;
		}
		else
		{
			cout << "�������ݳɹ������������밴��y�����˳������밴������" << endl;
			char goonOrexit;
			cin >> goonOrexit;
			if (goonOrexit == 'y' || goonOrexit == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	//�ر��׽���
	closesocket(s_server);
	closesocket(s_accept);
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
	err = WSAStartup(w_req, &wsadata); //ʹ��Socket�ĳ�����ʹ��Socket֮ǰ�������WSAStartup����
									   // WSAStartup()ִ�гɹ��󷵻�0
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