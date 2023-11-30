#pragma once
#include "yys_function.h"
class BeginYuhun :public yys_function
{
public:
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//单刷选择层数
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//寻副本
	int FindYuHun(snow *sn, Game *game);
	//锁定阵容
	int lockTeam(snow *sn, Game *game);
	//进入副本
	int EnterYuHun(snow *sn, Game *game);
	//庭院邀请好友模式
	int inviteYuhun(long hd, int round, int layer, CString jc, int mateType, int triple, snow *sn, Game *game);
	//庭院接受邀请模式
	int BeinvitedYuhun(long hd, int round, CString jc, snow *sn, Game *game);
	//单刷
	int SingleYuHun(long hd, int round, int layer, CString jc, snow *sn, Game *game);
	//返回庭院
	int YuHunReturnYard(snow *sn, Game *game);
};

