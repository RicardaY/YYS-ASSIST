#pragma once
#include "yys_function.h"
class BeginYeYuanHuo :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//������
	int FindYeYuanHuo(snow *sn, Game *game);
	//��������
	int lockTeam(snow *sn, Game *game);
	//���븱��
	int EnterYeYuanHuo(snow *sn, Game *game);
	//��ʼ
	int StartYeYuanHuo(long hd, int round, int layer, snow *sn, Game *game);
};

