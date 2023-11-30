#pragma once
#include "yys_function.h"
class BeginJueXing :public yys_function
{
public:
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//单刷选择层数
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//抽象出选择哪只麒麟方法，方便调用
	int WhichToSelect(CPoint startXY, CPoint endXY, CString source_font, snow *sn, Game *game);
	//选打哪个
	int ChooseMonster(int monster_kind, snow *sn, Game *game);
	//找副本
	int FindJueXing(snow *sn, Game *game);
	//锁定阵容
	int lockTeam(snow *sn, Game *game);
	//进入副本
	int EnterJueXing(snow *sn, Game *game);
	//庭院邀请好友模式
	int inviteJueXing(long hd, int round, int mode,  int layer, CString jc, int mateType, int triple, snow *sn, Game *game);
	//庭院接受邀请模式
	int BeinvitedJueXing(long hd, int round, CString jc, snow *sn, Game *game);
	//单刷
	int SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, snow *sn, Game *game);
};

