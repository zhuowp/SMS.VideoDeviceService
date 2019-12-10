#include "HikDeviceManager.h"
#include <iostream>

HikDeviceManager::HikDeviceManager()
{
}

HikDeviceManager::~HikDeviceManager()
{
}

bool HikDeviceManager::DeviceRegister(string ip, int port, string userName, string password)
{
	return false;
}

bool HikDeviceManager::DeviceUnregister(string ip, int port)
{
	return false;
}

void MessageCallback(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser)
{
	switch (lCommand)
	{
	case COMM_GISINFO_UPLOAD:
	{
		NET_DEV_GIS_INFO gis_info;
		videoDevInfo devInfo;
		devInfo.devId = (char*)pAlarmer->sSerialNumber;
		memcpy(&gis_info, pAlarmInfo, sizeof(NET_DEV_GIS_INFO));

		std::cout << "�����������»ص� " << gis_info.struPtzPos.fPanPos << " " << gis_info.struPtzPos.fTiltPos << "\r\n";
	}
	break;
	default:
		break;
	}
}

LONG HikDeviceManager::DeviceLogin(string ip, int port, string userName, string password)
{
	string devIdentify = ip + "_" + std::to_string(port);
	NET_DVR_DEVICEINFO_V30 deviceInfo;
	LONG userId = NET_DVR_Login_V30((char*)ip.c_str(), port, (char*)userName.c_str(), (char*)password.c_str(), &deviceInfo);
	if (userId >= 0)
	{
		registeredDevices.insert(pair<string, int>(devIdentify, userId));
		std::cout << "�豸" << devIdentify << "��¼�ɹ���UserIDΪ��" << userId << "\n";

		//���ñ����ص�����
		NET_DVR_SetDVRMessageCallBack_V31(MessageCallback_V31, (void*)this);

		NET_DVR_SETUPALARM_PARAM struSetupParam = { 0 };
		struSetupParam.dwSize = sizeof(NET_DVR_SETUPALARM_PARAM);

		//�ϴ�������Ϣ����: 0- �ϱ�����Ϣ(NET_DVR_PLATE_RESULT), 1- �±�����Ϣ(NET_ITS_PLATE_RESULT)
		struSetupParam.byAlarmInfoType = 1;
		//�����ȼ�:����������������ܽ�ͨ�豸
		struSetupParam.byLevel = 1;

		//����
		LONG lHandle = NET_DVR_SetupAlarmChan(userId);
	}
	else
	{
		std::cout << "�豸" << devIdentify << "��¼ʧ��";
	}

	return userId;
}

BOOL HikDeviceManager::MessageCallback_V31(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser)
{
	MessageCallback(lCommand, pAlarmer, pAlarmInfo, dwBufLen, pUser);
	return true;
}



