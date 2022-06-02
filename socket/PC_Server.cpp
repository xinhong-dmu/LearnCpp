#include<iostream>
#include<winsock.h>
#include<sstream> //char* 转化为 double

#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization();
int main()
{
	//定义长度变量
	int send_len = 0;
	int recv_len = 0;
	int len = 0;
	//定义发送缓冲区和接受缓冲区
	char send_buf[100];
	char recv_v_buf[100];
	memset(recv_v_buf, 200.0, sizeof(double) * 100);
	char recv_a_buf[100] ;
	//定义并初始化传输数据的数组
	double v_vehicle[10];
	memset(v_vehicle, 200.0, sizeof(double)*10);
	double angle_vehicle[10];
	memset(angle_vehicle, 0, sizeof(double) * 10);
	//定义服务端套接字，接受请求套接字
	SOCKET s_server;  //套接字在Linux下为SOCKET型，Windows下为int型，保存客户端端口号和IP地址
	SOCKET s_accept;  //套接字Linux下为SOCKET型，Windows下为int型，保存客户端端口号和IP地址
					  //服务端地址客户端地址
	SOCKADDR_IN server_addr;  //保存客户端端口号和IP地址
	SOCKADDR_IN accept_addr;  //保存客户端端口号和IP地址
	initialization();
	//填充服务端信息
	server_addr.sin_family = AF_INET;    //地址簇为IPv4协议
	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);  /*将long类型数据(IP地址)从主机字节序转换为网络字节序。INADDR_ANY泛指本机所有IP地址*/
	server_addr.sin_port = htons(1234);  //将short类型数据(端号口)从主机字节序转换为网络字节序

										 //创建套接字
	s_server = socket(AF_INET, SOCK_STREAM, 0);  //地址族, 数据传输类型, 协议(TCP or UDP)
	if (bind(s_server, (SOCKADDR *)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		cout << "套接字绑定失败！" << endl;
		WSACleanup();
	}
	else
	{
		cout << "套接字绑定成功！" << endl;
	}

	//设置套接字为监听状态
	// listen (进行监听的套接字，最大请求队列长度)。监听状态错误返回-1
	if (listen(s_server, SOMAXCONN) == -1) //listen()返回值为int，SOMAXCONN由系统决定请求队列长度
	{
		cout << "设置监听状态失败！" << endl;
		WSACleanup(); //中止了Windows Sockets在所有线程上的操作.
	}
	else
	{
		cout << "设置监听状态成功！" << endl;
	}
	cout << "服务端正在监听连接，请稍候...." << endl;

	//接受连接请求，accept() 会阻塞程序执行（后面代码不能被执行），直到有新的请求到来。
	len = sizeof(SOCKADDR);
	s_accept = accept(s_server, (SOCKADDR *)&accept_addr, &len);
	if (s_accept == SOCKET_ERROR)
	{
		cout << "连接失败！" << endl;
		WSACleanup();
		return 0; //连接失败，直接返回结束
	}
	cout << "连接建立，准备接受数据" << endl;

	//用返回的套接字和客户端进行通信，接收数据
	while (1)
	{   //recv(接收端套接字，用于存放收到数据的缓冲区，buf长度，一般置0)
		int recv_v_len = recv(s_accept, (char*)&recv_v_buf, 100, 0);
		int recv_a_len = recv(s_accept, (char*)&recv_a_buf, 100, 0);
		if (recv_v_len <= 0 || recv_a_len <= 0) //正常返回实际copy的字节数，直到没有可返回的数据
		{
			cout << "接收失败！" << endl;
			int recv_flag = -1;
			send(s_accept, (char*)&recv_flag, 100, 0);
			break;
		}
		else
		{
			cout  <<"速度："<<atof(recv_v_buf) << "   转向角：" << atof(recv_a_buf) << endl;
		}
		recv_v_len = 0;
		recv_a_len = 0;
		// 返回是否接收到数据
		send_len = send(s_accept, send_buf, 100, 0);
		if (send_len < 0)
		{
			cout << "发送失败！" << endl;
			continue;
		}
		else
		{
			cout << "接收数据成功，继续接收请按“y”，退出传输请按其他键" << endl;
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
	//关闭套接字
	closesocket(s_server);
	closesocket(s_accept);
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
	err = WSAStartup(w_req, &wsadata); //使用Socket的程序在使用Socket之前必须调用WSAStartup函数
									   // WSAStartup()执行成功后返回0
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