#pragma once
#include "yys_function.h"
class BeginChangeYuHun : public yys_function
{
public:
	//ѡ�����
	int SelectGroup(CPoint clickXY, snow *sn, Game *game);
	//Ԥ������
	int StartChangeYuHun(long hd, int group, int team, snow *sn, Game *game);
	//Ԥ����������
	int StartChangeYuHunDouble(long hd, int group, int team1, int team2, snow *sn, Game *game);
};

