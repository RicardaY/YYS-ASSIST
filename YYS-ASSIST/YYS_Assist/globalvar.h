#pragma once
#include "SavePreSet.h"
#include "YYS_AssistDlg.h"
#include "snow.h"
extern bool waitFlag1 , waitFlag2 ;
extern bool exbonus1 , exbonus2 ;
extern bool exteamer1, exteamer2;
//字库地址
extern CString g_path;
//插件全局保持
extern snow *g_sn;
//版本号
extern CString version;
//是否点击准备标识(锁定阵容判断)
extern bool readyFlag;
//游戏保存的一些文件名
extern std::string fname1, fname2;
extern std::string stoken;
//读取预设文件
extern SavePreSet *sPreset;
//新活动
extern CString activityName;
extern CString activitySubName;
extern CString TiLiName;