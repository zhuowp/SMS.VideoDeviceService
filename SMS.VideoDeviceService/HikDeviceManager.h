#pragma once

#include <string>
#include <map>
#include "HCNetSDK.h"
#include "NET_DEV_DEF.h"

class HikDeviceManager
{
public:
	HikDeviceManager();
	~HikDeviceManager();

	bool DeviceRegister(std::string ip, int port, std::string userName, std::string password);
	bool DeviceUnregister(std::string ip, int port);

	LONG DeviceLogin(std::string ip, int port, std::string userName, std::string password);

	//void CALLBACK MessageCallback(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser);

private:
	std::map<std::string, LONG> registeredDevices;

	BOOL static CALLBACK MessageCallback_V31(LONG lCommand, NET_DVR_ALARMER* pAlarmer, char* pAlarmInfo, DWORD dwBufLen, void* pUser);
};

