#pragma once
#include "yys_function.h"
class BeginRiLunZhiYun :public yys_function
{
public:
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//单刷选择层数
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//寻副本
	int FindRiLunZhiYun(snow *sn, Game *game);
	//锁定阵容
	int lockTeam(snow *sn, Game *game);
	//进入副本
	int EnterRiLunZhiYun(snow *sn, Game *game);
	//开始
	int SingleRiLunZhiYun(long hd, int round, int layer, CString jc, snow *sn, Game *game);
	//庭院邀请好友模式
	int inviteRiLunZhiYun(long hd, int round, int layer, CString jc, int mateType, int triple, snow *sn, Game *game);
	//庭院接受邀请模式
	int BeinvitedRiLunZhiYun(long hd, int round, CString jc, snow *sn, Game *game);
};

