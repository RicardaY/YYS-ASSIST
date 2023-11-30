#pragma once
#include "yys_function.h"
class BeginExplore : public yys_function
{
public:
	//判断是否在探索界面
	int isExplore(snow *sn, Game *game);
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//单刷选择层数
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//选择难度
	int ChooseDiff(int diff, snow *sn, Game *game);
	//点击探索
	int clickExplore(snow *sn, Game *game);
	//进入副本后操作
	//检查自动轮换--以后会实现全自动轮换
	int autoRotate(snow *sn, Game *game);
	//找小怪 speed:刷怪速度
	int findCommonMonster(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//找boss
	int findBossMonster(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//邀请好友
	int InnerCreatTeamToInviteUpper(int preferArea, snow *sn, Game *game);
	int InnerCreatTeamToInviteLower(int preferArea, snow *sn, Game *game);
	//进入副本并开始探索
	int EnterExplore(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//单刷模式进入副本并开始探索
	//int SingleEnterExplore(CString progressBar, CString materialKinds,  int speed, snow *sn, Game *game);
	//退出探索事件
	int ExitExploreEvent(snow *sn, Game *game);
	//领取左侧奖励
	int GetReward(int mode, snow *sn, Game *game);
	//通过庭院判断是否出副本
	int IsOutExploreByYard(snow *sn, Game *game);
	//组队进入副本
	int receiveEnterExplore(int count, snow *sn, Game *game);
	//检测好友进入队伍点挑战 
	int IsEnterTeamRepeat(int preferArea, int count, int collectbox, int mode, snow *sn, Game *game);
	//获取自动轮换状态
	int GetAutoRoTateState(snow *sn, Game *game);
	//判断是否需要换狗粮
	int IsChangeMaterial(snow *sn, int material, int mode, Game *game);
	//选择何种狗粮
	int WhatMaterialToSelect(CString materialKinds, snow *sn, Game *game);
	//狗粮进度条选择
	int SelectProgressBar(CString progress, snow *sn, Game *game);
	//自动换狗粮
	int AutoReplaceMaterial(CString progressBar, CString materialKinds, snow *sn, Game *game);
	//接受邀请
	int ReceiveInvite(int count, int collectbox, int mode, snow *sn, Game *game);
	//组队捡宝箱/换狗粮等待事件
	int CombineWaitRelation(bool &flag1, bool &flag2, snow *sn, Game *game);
	//单刷
	int SingleExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds,  int collectbox, int mode, snow *sn, Game *game);
	//智能探索
	int AIExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds, int collectbox, int mode, snow *sn, Game *game);

	//组队邀请好友
	int inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, int collectbox, int mode, int material, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//组队接受邀请
	int BeinvitedExplore(long hd, int round, CString jc, int collectbox, int mode, snow *sn, Game *game);
	//返回庭院
	int ExploreReturnYard(snow *sn, Game *game);
};
