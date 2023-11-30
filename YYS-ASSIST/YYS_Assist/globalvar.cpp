#pragma once
#include "pch.h"
#include "globalvar.h"
#include<iostream>

bool waitFlag1 = true, waitFlag2 = true;
bool exbonus1 = true, exbonus2 = true;
bool exteamer1 = true, exteamer2 = true;
//字库地址
CString g_path = _T("resource");
//版本号
CString version = _T("版本号2.4.7");
//是否点击准备标识(锁定阵容判断)
bool readyFlag = TRUE;
//游戏保存的一些文件名
std::string fname1 = "config/game1.json", fname2 = "config/game2.json";
std::string stoken =  "config/token.json";
//新活动
CString activityName = _T("红狐之邀");
CString activitySubName = _T("花境试炼");
CString TiLiName = _T("花见贴");