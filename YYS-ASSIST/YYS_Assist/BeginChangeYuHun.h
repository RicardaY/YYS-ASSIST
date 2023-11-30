#pragma once
#include "yys_function.h"
class BeginChangeYuHun : public yys_function
{
public:
	//选择分组
	int SelectGroup(CPoint clickXY, snow *sn, Game *game);
	//预设御魂
	int StartChangeYuHun(long hd, int group, int team, snow *sn, Game *game);
	//预设两组御魂
	int StartChangeYuHunDouble(long hd, int group, int team1, int team2, snow *sn, Game *game);
};

