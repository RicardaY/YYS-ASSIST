#pragma once
#include "yys_function.h"
class BeginYuLing :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//�����ѡ����ֻ���鷽�����������
	int WhichToSelect(CPoint startXY, CPoint endXY, CString source_pic[2], snow *sn, Game *game);
	//ѡ���ĸ�
	int ChooseMonster(int monster_kind, snow *sn, Game *game);
	//�Ҹ���
	int FindYuLing(snow *sn, Game *game);
	//��������
	int lockTeam(snow *sn, Game *game);
	//���븱��
	int EnterYuLing(snow *sn, Game *game);
	//��ʼ
	int StartYuLing(long hd, int round, int monster_kind, int layer, snow *sn, Game *game);
};

