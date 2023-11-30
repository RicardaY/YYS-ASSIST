#pragma once
#include "yys_function.h"
class BeginYongShengZhiHai :public yys_function
{
public:
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//单刷选择层数
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//判断好友是否进入
	int InnerIsEnterTeam(int mateType, int count, snow *sn, Game *game);
	//创建队伍---点击邀请
	int CreatYszhTeamToInviteUpper(int mateType, snow *sn, Game *game);
	int CreatYszhTeamToInviteLower(int mateType, snow *sn, Game *game);
	//寻副本
	int FindYongShengZhiHai(snow *sn, Game *game);
	//锁定阵容
	int lockTeam(snow *sn, Game *game);
	//进入副本
	int EnterYongShengZhiHai(snow *sn, Game *game);
	//开始
	int SingleYongShengZhiHai(long hd, int round, int layer, CString jc, snow *sn, Game *game);
	//庭院邀请好友模式
	int inviteYongShengZhiHai(long hd, int round, int layer, CString jc, int mateType, snow *sn, Game *game);
	//庭院接受邀请模式
	int BeinvitedYongShengZhiHai(long hd, int round, CString jc, snow *sn, Game *game);
};

