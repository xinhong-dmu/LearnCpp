#include<iostream>
#include<winsock.h>
#include<string>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization();

int main() {
	//定义长度变量
	int send_len = 0;
	int recv_len = 0;
	//定义发送缓冲区和接受缓冲区
	char send_v_buf[100];
	char send_a_buf[100];
	char recv_buf[100];
	//定义并初始化传输数据的数组
	double v_vehicle[] = { 1.0 };
	//memset(v_vehicle, 1.0, sizeof(double)*10);
	double angle_vehicle[] = { 0.0 };
	//memset(angle_vehicle, 2.0, sizeof(double) * 10);
	//定义服务端套接字，接受请求套接字
	SOCKET s_server;
	//服务端地址客户端地址
	SOCKADDR_IN server_addr;
	initialization();
	//填充服务端信息
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	server_addr.sin_port = htons(1234);

	//创建套接字
	s_server = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(s_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		cout << "服务器连接失败！" << endl;
		WSACleanup();
	}
	else
	{
		cout << "服务器连接成功！" << endl;
	}

	cout << "------ 是否开始传输数据？（按“y + enter”开始，按其他键取消）------" << endl;
	while (1)
	{
		char is_transData;
		cin>> is_transData;
		if (is_transData == 'y' || is_transData == 'Y')
		{
			cout << "请输入速度：" ;
			cin >> v_vehicle[0];
			// send message
			send_len = send(s_server, (char*)&v_vehicle[0], 100, 0);
			if (send_len < 0)
			{
				cout << "当前无数据进行传输！" << endl;
				continue;
			}
			cout << "请输入转向角：";
			cin >> angle_vehicle[0];
			send_len = send(s_server, (char*)&angle_vehicle[0], 100, 0);
			if (send_len < 0)
			{
				cout << "当前无数据进行传输！" << endl;
				continue;
			}
			
		}
		else
		{
			cout << "你可以在任意时刻按“y”开始传输数据" << endl;
			continue;
		}

		recv(s_server, (char*)&recv_buf, 100, 0);
		if (recv_buf == "-1")
		{
			cout << "发送数据失败！" << endl;
			/*break;*/
		}
		else
		{
			cout << "数据传输成功！" << endl;
		}
	}
	//关闭套接字
	closesocket(s_server);
	//释放DLL资源
	WSACleanup();
	return 0;
}

void initialization()
{
	//初始化套接字库
	WORD w_req = MAKEWORD(2, 2);//版本号
	WSADATA wsadata;
	int err;
	err = WSAStartup(w_req, &wsadata);
	if (err != 0)
	{
		cout << "初始化套接字库失败！" << endl;
	}
	else
	{
		cout << "初始化套接字库成功！" << endl;
	}
	//检测版本号
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2)
	{
		cout << "套接字库版本号不符！" << endl;
		WSACleanup();
	}
	else
	{
		cout << "套接字库版本正确！" << endl;
	}
}