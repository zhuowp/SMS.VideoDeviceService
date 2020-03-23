// SMS.VideoDeviceService.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HCNetSDK.h"
#include <string>
#include "NET_DEV_DEF.h"
#include "HikDeviceManager.h"
using namespace std;

int main()
{
	std::cout << "初始化海康SKD\n";
	bool sdkInitResult = NET_DVR_Init();
	if (!sdkInitResult)
	{
		std::cout << "海康SKD初始化失败\n";
		return 0;
	}

	std::cout << "登录到海康设备12.130\n";
	NET_DVR_DEVICEINFO_V30 m_stDeviceInfo;
	string ip = "192.168.28.130";
	int port = 8000;
	string name = "admin";
	string password = "admin888";

	HikDeviceManager hikDevManager;
	LONG lUserID = hikDevManager.DeviceLogin(ip, port, name, password);

	std::getchar();

	NET_DVR_Logout_V30(lUserID);
}
