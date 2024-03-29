#pragma once
#include "yys_function.h"
class BeginYeYuanHuo :public yys_function
{
public:
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//进副本
	int FindYeYuanHuo(snow *sn, Game *game);
	//锁定阵容
	int lockTeam(snow *sn, Game *game);
	//进入副本
	int EnterYeYuanHuo(snow *sn, Game *game);
	//开始
	int StartYeYuanHuo(long hd, int round, int layer, snow *sn, Game *game);
};

