#pragma once
#include <vector>
#include <string>
#include "HCNetSDK.h"
#include <map>

#pragma pack(push)//保存对齐状态
#pragma pack(4)  //设置为4字节对齐

//基础数据长度
#define MAX_DEVID_LEN_EX 128
#define MAX_NAME_LEN_EX 64
#define MAX_PWD_LEN  64
#define MAX_IP_LEN	  16
#define MAX_PATH_LEN  260
#define MAX_GUID_LEN  37
#define MAX_WARM_DES  256  //报警描述信息长度 
#define MAX_STR_LEN   128
#define MAX_TIME_LEN  32
#define MAX_TIME_SEC  4
#define MAX_DATE_SEC  7
#define MAX_TEL_LEN	  16
#define MAX_URL_LEN   128
#define MAX_CHANNEL_NUM  16
#define MAX_ZOOM_STEP 720

#define MAX_NET_DATA   1024

#define MAX_GB_CODE_LENGTH 20
#define MIN_GB_CODE_LENGTH 13
#define INIT_CHAN_NUM 8
//--------------------------错误类型----------------------//

#define YP_RET_OK 						0	 //操作成功完成


#define YP_RET_ERROR 					-1  //未知错误
#define YP_RET_URL_EMPTY 				-2  //URL为空 
#define YP_RET_CREAT_THREAD_FAILD		-3  //启动线程失败
#define YP_RET_NEED_REBOOT 				-4  //服务器必须重新启动 

#define YP_RET_OBSOLETE_COMMAND 		-6  //指令已经过时 
#define YP_RET_NOT_IMPLEMENTED 			-7  //指令没有实现 
#define YP_RET_NO_INTERFACE 			-11  //对象不支持接口 
#define YP_RET_MODULE_LIMITED 			-15  //该功能限制使用 
#define YP_RET_NO_DEVICE_TYPE		-16//无此设备类型

#define YP_RET_SET_TIME 				-21  //设置系统时间失败 
#define YP_RET_SET_IP 					-22  //设置服务器ip失败 
#define YP_RET_GET_IP 					-23  //取得服务器ip失败 
#define YP_RET_UPDATE_SYSTEM_FILE 		-24  //更新系统文件失败 

#define YP_RET_IO_TIMEOUT 				-29  //IO操作超时 
#define YP_RET_IO_CANCEL 				-30  //IO操作被取消 
#define YP_RET_CONNECTING 				-31  //连接正在进行中 


#define YP_RET_LIST_USER 				-81  //列出用户信息失败 
#define YP_RET_ADD_USER 				-82  //加入用户失败 
#define YP_RET_DEL_USER 				-83  //删除用户失败 
#define YP_RET_NO_USER 					-84  //没有此用户 
#define YP_RET_SAVE_USER 				-85  //保存用户失败 
#define YP_RET_USER_NUM 				-86  //用户数超出限制 
#define YP_RET_NO_FUNC 					-87  //没有请求的功能 
#define YP_RET_NO_PRIVILEGE 			-88  //没有权限访问 
#define YP_RET_NAME_PASSWORD 			-89  //用户名或密码不正确 
#define YP_RET_LEVEL_LOWER 				-90  //用户级别太低 
#define YP_RET_ALREADY_LOGIN 			-91  //已经有用户登录 
#define YP_RET_ALREADY_LOGIN_BY_SELF 	-92  //本用户已经登录 
#define YP_RET_INVALID_USER          	-93  //用户没有启用或者无效
#define YP_RET_WRONG_IP					-94  //用户关联的ip不匹配
#define YP_RET_LOGIN_FAILED 			-95  //登录失败 

#define YP_RET_DEVICE_BROKEN 			-200  //设备处于断线状态 
#define YP_RET_ALLOC_LOCAL_ADDR 		-201  //分配本地地址或端口失败 
#define YP_RET_START_TRANSFER 			-202  //请求传输失败 
#define YP_RET_START_RECV 				-203  //请求接收数据失败 
#define YP_RET_NO_OBJECT 				-204  //对象不存在 
#define YP_RET_OBJECT_EXISTS 			-205  //对象已经存在 
#define YP_RET_SET_PROPERTY 			-206  //对象属性设置错误 
#define YP_RET_INVALID_PROPERTY_PARAM 	-207  //属性值为空或非法 
#define YP_RET_RESOURCE_ROBBED 			-208  //资源被抢占 
#define YP_RET_PORT_IN_USE 				-209  //UDP或TCP端口已经被占用  
#define YP_RET_CONNECT_TO_DEVICE 		-210  //连接设备失败 


#define YP_RET_INVALID_PARAM 			-501  //函数或参数格式不正确
#define YP_RET_CONNECT_SERVER 			-502  //连接服务器失败
#define YP_RET_CLIENT_NOT_SUPPORTED 	-503  //客户端功能未实现
#define YP_RET_NOT_CONNECTED 			-506  //尚未连接服务器
#define YP_RET_SEND 					-507  //发送失败
#define YP_RET_RECV 					-508  //接收失败

#define YP_RET_ALREADY_CONNECTED 		-513  //已经连接了服务器 
#define YP_RET_BAD_IP_OR_HOST_NAME 		-514  //不正确的IP地址或主机名称 
#define YP_RET_BAD_MAC 		            -515  //不正确的MAC地址

#define YP_RET_SERVER_OFFLINE 			-516  //服务器不在线 
#define YP_RET_SERVER_WAS_DIED 			-517  //服务器没有响应 
#define YP_RET_UNEXPECTED_REPLY 		-518  //收到无法处理的应答 
#define YP_RET_TRANSFER_HAS_START 		-519  //传输已经发起 
#define YP_RET_NOT_SET_PROTOCOL 		-520  //摄像机没有设置传输协议 
#define YP_RET_INVALID_PROTOCOL			-521  //摄像机的传输协议目前不支持 
#define YP_RET_NOT_LOGIN				-522  //用户没有登录 
#define YP_RET_RECV_TIME_OUT			-523  //网络接收超时
#define YP_RET_PING						-524  //网络地址PING不通
#define YP_RET_INVALID_NET_PORT			-525  //服务器TCP端口错误
#define YP_RET_PEER_CLOSED				-526  //对方已经关闭连接
#define YP_RET_TOO_MANY_LOGIN			-527  //用户登录次数太多
#define YP_RET_NO_USER_DATA				-530  //不存在用户相关的数据
#define YP_RET_PARAM_LEN_ERROR			-540  //参数长度不对
#define YP_RET_PARAM_EMPTY_ERROR		-550  //传入参数为空值或者非法
#define YP_RET_PARAM_CAN_NOT_HANDLE		-551  //无法处理该类型数据

#define YP_RET_DIR_GUID_ERROR			-560  //GUID值不匹配
#define YP_RET_NO_USE_INTERFACE			-561  //接口未实现
#define YP_RET_CONNECT_DB_FAILED		-562  //连接数据库失败
#define YP_RET_NO_RELATED_DATA			-563  //没有相关的数据



#define DEV_STATUS_ONLINE				0x01	//设备在线
#define DEV_STAUTS_OFFLINE				0x00	//设备离线

//--------------------------错误类型----------------------//

//--------------------------国标类型编码----------------------//
#define GB_CODE_DVR_TYPE 111
#define GB_CODE_NVR_TYPE 118
#define GB_CODE_IPC_TYPE 132 
#define GB_CODE_COM_IPC_TYPE 131
#define GB_CODE_ALARM_DEV_TYPE 134 

//
//struct UnifiedIdentifier
//{
//	char entity_id[MAX_GUID_LEN];	//内部ID号
//};
//typedef UnifiedIdentifier UNIFIED_ID;
//
//struct EntityID
//{
//	UNIFIED_ID id;
//	int nType;
//	char url[MAX_URL_LEN];
//};
//struct orgInfo
//{
//	int id;
//	char name[128];
//	int parentID;
//	char charge_name[64];
//	char mobile_phone[15];
//	char telephone[15];
//	char position[128];
//	
//};
//



struct ptzPointInfo
{
	char dvrId[MAX_NAME_LEN_EX];
	int channelNo;
	char name[MAX_STR_LEN];
	int presetIndex;
	int presetId[MAX_NAME_LEN_EX];
};

typedef struct tagGroupInfo {
	int id;
	char name[MAX_STR_LEN];
	char reserver[MAX_STR_LEN];
}GroupInfo, * PGroupInfo;

typedef struct tagGroupChannelInfo {
	int id;
	int GroupId;
	char  chId[MAX_GUID_LEN];
}GroupChannelInfo, * PGroupChannelInfo;

//typedef struct tagOrgInfo
//{
//	TCHAR		parentOrgID[GUID_LEN];			//父组织机构ID
//	TCHAR		orgID[GUID_LEN];					//父组织机构ID
//	TCHAR		szName[MAX_NAME_LEN_EX];			//组织机构名称
//}ORG_INFO,*PORG_INFO;
//
//
////组内设备信息，显示
//typedef struct tagGroupDevInfo{
//	TCHAR       parentID[GUID_LEN];		//对象父ID
//	TCHAR		orgID[GUID_LEN];			//组织机构ID
//	EntityID	id;						//对象ID
//	TCHAR		szName[MAX_NAME_LEN_EX];	//设备名
//}GROUP_DEV_INFO,*PGROUP_DEV_INFO;




typedef enum
{
	// Up, Down, Left, Right
	PTZ_UP_START = 0,
	PTZ_UP_STOP,
	PTZ_DOWN_START,
	PTZ_DOWN_STOP,
	PTZ_LEFT_START,
	PTZ_LEFT_STOP,
	PTZ_RIGHT_START,
	PTZ_RIGHT_STOP,
	// (Optional) : LeftUp, LeftDown, RightUp, RightDown
	PTZ_LEFT_UP_START,
	PTZ_LEFT_UP_STOP,
	PTZ_LEFT_DOWN_START,
	PTZ_LEFT_DOWN_STOP,
	PTZ_RIGHT_UP_START,
	PTZ_RIGHT_UP_STOP,
	PTZ_RIGHT_DOWN_START,
	PTZ_RIGHT_DOWN_STOP,

	// Focus, Zoom, Iris
	PTZ_FOCUS_FAR_START = 20,
	PTZ_FOCUS_FAR_STOP,
	PTZ_FOCUS_NEAR_START,
	PTZ_FOCUS_NEAR_STOP,
	PTZ_ZOOM_TELE_START,
	PTZ_ZOOM_TELE_STOP,
	PTZ_ZOOM_WIDE_START,
	PTZ_ZOOM_WIDE_STOP,
	PTZ_IRIS_CLOSE_START,
	PTZ_IRIS_CLOSE_STOP,
	PTZ_IRIS_OPEN_START,
	PTZ_IRIS_OPEN_STOP,

	// Rotation, Light, Rain, Track, IO
	PTZ_ROTATION_START = 40,
	PTZ_ROTATION_STOP,
	PTZ_LIGHT_START,
	PTZ_LIGHT_STOP,
	PTZ_RAIN_START,
	PTZ_RAIN_STOP,
	PTZ_TRACK_START,
	PTZ_TRACK_STOP,
	PTZ_IO_START,
	PTZ_IO_STOP,

	// PTZ Point
	PTZ_SET_POINT = 60,
	PTZ_SET_POINT_ROTATION,
	PTZ_GOTO_POINT,
	PTZ_CLEAR_POINT,
	PTZ_SET_POINT_LEFT,
	PTZ_GOTO_POINT_LEFT,
	PTZ_SET_POINT_RIGHT,
	PTZ_GOTO_POINT_RIGHT,

}enPtzAction;
enPtzAction ConvertPtzMoveToPtzAction(std::string& ptz_action, int ptz_ctrl);



typedef struct tagPtzActParam
{
	enPtzAction actionCmd;
	BYTE byChanNum;
	BYTE bySpeed;
	BYTE Param1; // 1) To Set/Get point, this means point value, range: 0 ~ 255

	BYTE Param2;// 2) To move Left/Up/Right/Down, this means speed, range: 1 ~ 10
	BYTE Reserved[8];
}PTZACT_PARAM, * PPTZACT_PARAM;

enum em_playback_con
{
	PLAYSTART = 1,// 开始播放 
	PLAYPAUSE = 2,// 暂停播放 
	PLAYRESTART = 3,// 恢复播放（在暂停后调用将恢复暂停前的速度播放） 
	PLAYFAST = 4,// 快放 
	PLAYSLOW = 5,// 慢放 
	PLAYNORMAL = 6,// 正常速度播放（快放或者慢放时调用将恢复单倍速度播放） 
	PLAYFRAME = 7,// 单帧放（恢复正常回放使用NET_DVR_PLAYNORMAL命令） 
	PLAYSTARTAUDIO = 8,// 打开声音 
	PLAYSTOPAUDIO = 9,// 关闭声音 
	PLAYAUDIOVOLUME = 10,//调节音量，取值范围[0,0xffff] 
	PLAYSETPOS = 11,// 改变文件回放的进度 
	PLAYGETPOS = 12,//  获取按文件或者按时间回放的进度 
	PLAYSTOP = 13,//停止播放 
};


/*------------------借用hk结构体当中的gis信息结构，后面普通球机的ptz和水平垂直视场角也按此结构体填充------------------------*/
typedef struct
{
	char    sIpV4[16];
	BYTE    byIPv6[128];
}NET_DEV_IPADDR, * LPNET_DEV_IPADDR;

typedef struct tagNET_DEV_INFO
{
	NET_DEV_IPADDR  struDevIP;
	WORD wPort;
	BYTE byChannel;
	BYTE byIvmsChannel;
}NET_DEV_INFO, * LPNET_DEV_INFO;

typedef struct tagNET_DEV_LLI_PARAM
{
	float fSec;
	BYTE byDegree;
	BYTE byMinute;
	BYTE byRes[6];
}NET_DEV_LLI_PARAM, * LPNET_DEV_LLI_PARAM;

typedef struct tagNET_DEV_SENSOR_PARAM
{
	BYTE        bySensorType;
	BYTE        byRes[31];
	float       fHorWidth;
	float       fVerWidth;
	float       fFold;
}NET_DEV_SENSOR_PARAM, * LPNET_DEV_SENSOR_PARAM;

typedef struct
{
	float   fPanPos;
	float   fTiltPos;
	float   fZoomPos;
	BYTE    byRes[16];
}NET_DEV_PTZPOS_PARAM, * LPNET_DEV_PTZPOS_PARAM;

typedef struct tagNET_DEV_GIS_INFO
{
	DWORD   dwSize;
	DWORD     dwRelativeTime;
	DWORD    dwAbsTime;
	NET_DEV_INFO    struDevInfo;
	float   fAzimuth;
	BYTE    byLatitudeType;
	BYTE    byLongitudeType;
	BYTE    byRes1[2];
	NET_DEV_LLI_PARAM    struLatitude;
	NET_DEV_LLI_PARAM    struLongitude;
	float   fHorizontalValue;//need
	float   fVerticalValue;//need
	float   fVisibleRadius;
	float   fMaxViewRadius;
	NET_DEV_SENSOR_PARAM  struSensorParam;
	NET_DEV_PTZPOS_PARAM  struPtzPos;//need
									 //BYTE  byRes[256];
}NET_DEV_GIS_INFO, * LPNET_DEV_GIS_INFO;
/*-----------------------------END----------------------------------*/
enum enDevArType
{
	_COM_DEV_ = 0,
	_AR_DEV_ = 1,
	_STD_AR_DEV_ = 2,
	_NVR_DEV = 3,
};//普通设备/能回调上传相关云台信息设备

  //---------------------------------------------------------------------------------------------
struct channleInfo
{
	std::string channel_id;
	std::string title;
	int chNo;
	int max_zoom;
	int is_shared; //表示此通道是需要透传的
	std::string gb_code;
	//HorVerValue hvv_;//视场角信息
	enDevArType dev_ar_type;
	std::string camera_type;
	NET_DEV_GIS_INFO pre_gis_info;
	//short zoom_backvalue[MAX_ZOOM_STEP];
	std::map<int, int> zoom_backvalue;
	channleInfo()
	{
		memset(&pre_gis_info, 0, sizeof(pre_gis_info));
		is_shared = 0;
		dev_ar_type = _COM_DEV_;
		chNo = 1;//通道表中从1开始（已做通道0的填充）
		max_zoom = 0;

	}
	channleInfo& operator=(const channleInfo& channel_info)
	{
		channel_id = channel_info.channel_id;
		title = channel_info.title;
		gb_code = channel_info.gb_code;
		camera_type = channel_info.camera_type;
		memcpy(&pre_gis_info, &channel_info.pre_gis_info, sizeof(channel_info.pre_gis_info));
		zoom_backvalue = channel_info.zoom_backvalue;
		chNo = channel_info.chNo;
		dev_ar_type = channel_info.dev_ar_type;
		max_zoom = channel_info.max_zoom;
		is_shared = channel_info.is_shared;
		return *this;
	}

};
bool CompareChannelNum(const struct channleInfo& info1, const struct channleInfo& info2);

enum enVideoDevType
{
	enUnknown = 0,//
	enHik = 1,//海康
	enDH = 2,//大华
	enGHR = 3,//高普乐重载，heavy rifle
	enSZKD = 4,//苏州科达
	enHuaWei = 5,//华为
	enYuShiIPC = 6,//宇视IPC
	enHePuIPC = 7,
	enXinYuanIPC = 8,
#ifdef TEST_QUERY_GIS
	enTestDev = 6
#endif
};
static std::vector<std::string> video_dev_type = {
	//"AUDIO_DATA",
	//"VIDEO_DATA",
	"UnKnown",
	"HaiKang",
	"DaHua",
	"HaiKang",
	"SZKDIPC",
	"HuaWei",
	"YuShiIPC",
	"HePuIPC",
	"XinYuanIPC"
};
enum enWndMode
{
	en_real_play = 1,
	en_playback = 2,
};

enum enOnSatus
{
	offline = 0,
	online = 1,
	unknow = 2,
};

struct videoDevInfo
{
	std::string devId;
	std::string title;
	std::string ip;
	std::string control_ip;
	int port;
	int control_port;
	std::string name;
	std::string passw;
	int chCount;//表示通道表中有chConut-1个通道，
	int startChNo;//起始通道号
	int byStartDChan;
	int devType;
	std::string strExtendInfo;
	std::string model_num;
	int nFocusLength;//高普乐重载云台镜头焦距区分倍率步长
	std::string  camera_type;//摄像机类型,枪机，球机，全景
							 //enOnSatus onlineState;
	std::vector<struct channleInfo>vec_channel_info;
	enDevArType dev_ar_type;
	std::string get_ptz_mode;// SDK/GB

	videoDevInfo()
	{
		startChNo = byStartDChan = 0;
		dev_ar_type = _COM_DEV_;
		chCount = devType = 0;
		for (int i = 0; i < INIT_CHAN_NUM; i++) {
			struct channleInfo info;//加一个零通道，做填充位
			info.chNo = i;
			vec_channel_info.push_back(info);
		}

		chCount = INIT_CHAN_NUM;
		nFocusLength = 500;//高普乐重载云台现场默认使用500毫秒的镜头焦距
		get_ptz_mode = "SDK";
		model_num = "";
	}
	videoDevInfo& operator=(videoDevInfo& dev_info)
	{
		devId = dev_info.devId;
		title = dev_info.title;
		ip = dev_info.ip;
		control_ip = dev_info.control_ip;
		name = dev_info.name;
		passw = dev_info.passw;
		camera_type = dev_info.camera_type;

		port = dev_info.port;
		control_port = dev_info.control_port;
		chCount = dev_info.chCount;
		byStartDChan = dev_info.byStartDChan;
		startChNo = dev_info.startChNo;
		devType = dev_info.devType;
		vec_channel_info.swap(dev_info.vec_channel_info);
		dev_ar_type = dev_info.dev_ar_type;
		nFocusLength = dev_info.nFocusLength;
		strExtendInfo = dev_info.strExtendInfo;
		model_num = dev_info.model_num;
		return *this;
	}
	bool operator==(const videoDevInfo& dev_info)
	{
		if (dev_info.ip.compare(ip) == 0) {
			for (int i = 0; i < vec_channel_info.size(); i++) {
				for (int j = 0; j < dev_info.vec_channel_info.size(); j++) {

					if (dev_info.vec_channel_info[j].channel_id.compare(vec_channel_info[i].channel_id) == 0)
						return true;
					else
						continue;
				}
			}
		}
		return false;
	}
};
struct devStatusInfo
{
	videoDevInfo devInfo;
	int nStatus;
};


class Videobase
{
public:
	//初始化设备状态
	Videobase()
	{
		//memset(&m_dvrInfo, 0, sizeof(m_dvrInfo));
		m_status = offline;
		m_login_id = -1;
	}
	//当查询设备信息失败的时候，设置连接状态失败，尝试重连
	virtual void SetConnectStatus(bool bConnectStatus)
	{
		if (false == bConnectStatus)
		{
			Logout();
			m_status = offline;
		}
	}
	bool IsLoginOnLine()
	{
		return (m_status == online) ? true : false;
	}
	bool IsRifileCamear(int channel_no)
	{
		if (m_dvrInfo.vec_channel_info[channel_no].camera_type.compare("QiangJi") == 0 || m_dvrInfo.vec_channel_info[channel_no].camera_type.compare("QuanJing") == 0)
			return true;
		else
			return false;
	}
	virtual long SetDetDeviceInfo(videoDevInfo* devInfo) = 0;
	virtual long GetDetDeviceInfo(videoDevInfo* devInfo) = 0;
	virtual long GetDetDeviceStatus(enOnSatus* devStatus) = 0;
	virtual long GetDevChannelList(std::vector<channleInfo>& vctCh) { return  -1; }
	virtual bool GetChanNoByChanId(std::string channel_id, int* channel_no)
	{
		if (channel_id.size() == 0)
			return false;
		for (int i = 0; i < m_dvrInfo.chCount; i++) {
			if (channel_id.compare(m_dvrInfo.vec_channel_info[i].channel_id) == 0) {
				*channel_no = i;
				return true;
			}
		}
		return false;
	}

	virtual bool QueryGisInfo(NET_DEV_GIS_INFO* gis_info, int channel_no) = 0;
	virtual bool QueryGisInfoByChno(NET_DEV_GIS_INFO* gis_info, int chno = 1) { return false; };
	virtual bool QueryGisInfoAllCh(std::vector<NET_DEV_GIS_INFO>& vct_gis_info) { return false; };
	virtual long Login() = 0;
	virtual long Logout() = 0;
	///***********************************************
	// * brief 云台控制接口
	// * @time 	2018/10/10 10:04
	// * @param move_type：云台的移动类型，包括上下左右等8个方向，其中包括停止指令
	// * @param speed：移动速度 0-100
	// * @param channel_no：通道号
	// * @return true:控制成功，false：控制失败
	//***********************************************
	virtual 	bool DevPTZControl(enPtzAction move_type, int  speed, int channel_no) { return true; }
	virtual bool Set3DZoomIn(int nScreenWidth, int nScreenHeight, int nStartPosX, int nStartPosY, int nZoomInWidth, int nZoomInHeight, int channel_no) = 0;
	virtual bool SetPTZPos(double dPanPos, double dTiltPos, double dZoomPos, int channel_no) = 0;
	virtual bool SetMasterSlaveControl(int nScreenWidth, int nScreenHeight, int nStartPosX, int nStartPosY, int nZoomInWidth, int nZoomInHeight, int channel_no) { return false; }

	virtual long CapturePicNoPreview(int& chno, char* sPicFileName) { return  -1; };

	videoDevInfo m_dvrInfo;
	enOnSatus m_status;
	long m_login_id;
};

#pragma pack(pop)//恢复对齐状态