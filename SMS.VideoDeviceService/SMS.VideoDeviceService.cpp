// SMS.VideoDeviceService.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "HCNetSDK.h"
#include <string>
#include "dev_public_def.h"
using namespace std;

void CALLBACK MessageCallback(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser)
{
	NET_DEV_GIS_INFO gis_info;
	std::string json_gis_info;
	std::string ip_addr;
	videoDevInfo devInfo;
	devInfo.devId = (char*)pAlarmer->sSerialNumber;
	memcpy(&gis_info, pAlarmInfo, sizeof(NET_DEV_GIS_INFO));

	switch (lCommand)
	{
	case COMM_GISINFO_UPLOAD:
	{
		std::cout << "海康深眸更新回调 " << gis_info.struPtzPos.fPanPos << " " << gis_info.struPtzPos.fTiltPos;
		//ip_addr = pDev->m_dvrInfo.ip;
		//pDev->m_dvrInfo.vec_channel_info[pDev->m_dvrInfo.byStartDChan].dev_ar_type = _STD_AR_DEV_;//当有回调函数时，即认为此为设备单通道，默认通道1
		//hc_controler->ConvertGISStruToJson(gis_info, json_gis_info, command_code_notify_gis, ip_addr, pDev->m_dvrInfo.vec_channel_info[pDev->m_dvrInfo.byStartDChan].channel_id,
		//	pDev->m_dvrInfo.devType);
		//CMessageCenter::GetInstance().AddGisInfoToQueue(json_gis_info);//调试网闸时，需要注释此，确保没从设备取
	}
	break;
	default:
		break;
	}
}

BOOL CALLBACK MessageCallback_V31(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser)
{
	MessageCallback(lCommand, pAlarmer, pAlarmInfo, dwBufLen, pUser);
	return TRUE;
}

int main()
{
	std::cout << "Hello World!\n";

	std::cout << "初始化海康SKD";
	bool sdkInitResult = NET_DVR_Init();
	if (!sdkInitResult)
	{
		std::cout << "海康SKD初始化失败";
		return 0;
	}

	std::cout << "登录到海康设备12.130";
	NET_DVR_DEVICEINFO_V30 m_stDeviceInfo;
	string ip = "192.168.28.130";
	string name = "admin";
	string password = "admin888";
	LONG lUserID = NET_DVR_Login_V30((char*)ip.c_str(), 8000, (char*)name.c_str(), (char*)password.c_str(), &m_stDeviceInfo);
	NET_DVR_SetDVRMessageCallBack_V31(MessageCallback_V31, (void*)NULL);

	NET_DVR_SETUPALARM_PARAM struSetupParam = { 0 };
	struSetupParam.dwSize = sizeof(NET_DVR_SETUPALARM_PARAM);

	//上传报警信息类型: 0- 老报警信息(NET_DVR_PLATE_RESULT), 1- 新报警信息(NET_ITS_PLATE_RESULT)
	struSetupParam.byAlarmInfoType = 1;
	//布防等级:二级布防，针对智能交通设备
	struSetupParam.byLevel = 1;

	LONG lHandle = NET_DVR_SetupAlarmChan(lUserID);

	std::cout << "设备登录成功，UserID为：" << lUserID;
	string a;
	cin >> a;

	NET_DVR_Logout_V30(lUserID);
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
