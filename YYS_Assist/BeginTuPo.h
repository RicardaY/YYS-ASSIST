#pragma once
#include "yys_function.h"
class BeginTuPo :public yys_function
{
public:
	//进副本
	int FindTuPo(snow *sn, Game *game);
	//刷新副本
	int ReFresh(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game);
	//锁定阵容
	int lockTeam(snow *sn, Game *game);
	//解锁阵容
	int BeginTuPo::unlockTeam(snow *sn, Game *game);
	//判断是否有突破券
	int isHaveTicket(snow *sn, Game *game);
	//退出突破操作：点击->挑战->返回-->确定-->失败
	int ExitDo(int clickx, int clicky, snow *sn, Game *game);
	//退四
	int ExitFour(snow *sn, Game *game);
	//个人突破进入副本
	int StartToFinish(int count, int clickx, int clicky, snow *sn, Game *game);
	//寮突进攻---结算
	int AttackToFinish(int count, snow *sn, Game *game);
	//开始
	int StartTuPo(long hd, int round, snow *sn, Game *game);
	//退四打九
	int StartTuPoByExitFourAttackNine(long hd, int round, snow *sn, Game *game);
	int TupoReturnYard(snow *sn, Game *game);
	//识别个人突破未突破选项
	int BeginTuPo::GetGTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game);
	//识别寮突未突破范围
	int GetLTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game);
	//寮突
	int TeamBreak(long hd, int coolingEvent, snow *sn, Game *game);
};

