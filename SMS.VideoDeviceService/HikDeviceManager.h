#pragma once

#include <string>
#include <map>
#include "HCNetSDK.h"
#include "NET_DEV_DEF.h"
using namespace std;

class HikDeviceManager
{
public:
	HikDeviceManager();
	~HikDeviceManager();

	bool DeviceRegister(string ip, int port, string userName, string password);
	bool DeviceUnregister(string ip, int port);

	LONG DeviceLogin(string ip, int port, string userName, string password);

	//void CALLBACK MessageCallback(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser);

private:
	map<string, LONG> registeredDevices;

	BOOL static CALLBACK MessageCallback_V31(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser);
};

