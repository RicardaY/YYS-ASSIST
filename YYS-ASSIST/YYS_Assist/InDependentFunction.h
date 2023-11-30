#pragma once
#include "yys_function.h"
class InDependentFunction :public yys_function
{
public:
	//百鬼夜行
	int StartBaiGui(int round, snow *sn, Game *game);
	//地域鬼王打一只
	int SelectWhichReginalKing(CPoint startXY, CPoint endXY, int kindCheck, snow *sn, Game *game);
	//地域鬼王
	int StartReginalKing(long hd, int amount,int kindCheck, snow *sn, Game *game);
	//自动剧情点怪---结算
	int ClickMonsterToVictory(snow *sn, Game *game);
	//自动剧情
	int AutoPlot(snow *sn, Game *game);
	//自动斗技
	int AutoPVP(snow *sn, Game *game);
	int AutoPVPToMingShi(snow *sn, Game *game);
	//新活动
	int StartNewEvent(int round, int mode, int flag, int bossflag, snow *sn, Game *game);
	//自选功能
	int DIYFunction(int ready, int clearing, int whitecard, int challenge, snow *sn, Game *game);

	//超鬼王
	//1.检测是否有鬼王
	int CheckSuperGhostKing(int count, snow *sn, Game *game);
	//2.检测星级
	int CheckSuperGhostKingStar(snow *sn, Game *game);
	//	2-1 是否播报遇到高星鬼王并停止
	int IsStopAndAlert(int star, int star_stop, snow *sn, Game *game);
	//	2-2 公开高星鬼王
	int OpenHignStarSuperGhostKing(snow *sn, Game *game);
	//		2-2-1 等待鬼王被击败
	int WaitSuperGhostKingKilled(snow *sn, Game *game);
	//3.检测血量
	int CheckSuperGhostKingBlood(snow *sn, Game *game);
	//4.点击挑战(include 强追)
	int inline ClickChallenge(int star, int blood, int strenghCheck, snow *sn, Game *game);
	//5.更换阵容
	//	5.1选组&队
	int selectgroup(int group, int team, snow *sn, Game *game);
	//	5.2 点击预设
	int ClickPreset(snow *sn, Game *game);
	//	5.3 开始换阵容
	int ChangeStaff(int star, int blood, int group[], int team[], int bloodsel[], snow *sn, Game *game);
	//6.准备-结算
	int EnterSuperGhostKingSection(int flag_own, int flag_boss, snow *sn, Game *game);
	//7.开始超鬼王
	int StartSuperGhostKing(int round, int strenghCheck, int group[], int team[], int bloodsel[], int flag_own, int flag_boss, int star_stop, int star_public, snow *sn, Game *game);
	//秘闻
	int StartMiWen(snow *sn, Game *game, int round = 10);
	//灵柒试炼
	int StartLingRan(snow *sn, Game *game, int round = 50);
};

