#pragma once
#include "yys_function.h"
class BeginYuLing :public yys_function
{
public:
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//抽象出选择哪只御灵方法，方便调用
	int WhichToSelect(CPoint startXY, CPoint endXY, CString source_pic[2], snow *sn, Game *game);
	//选打哪个
	int ChooseMonster(int monster_kind, snow *sn, Game *game);
	//找副本
	int FindYuLing(snow *sn, Game *game);
	//锁定阵容
	int lockTeam(snow *sn, Game *game);
	//进入副本
	int EnterYuLing(snow *sn, Game *game);
	//开始
	int StartYuLing(long hd, int round, int monster_kind, int layer, snow *sn, Game *game);
};

