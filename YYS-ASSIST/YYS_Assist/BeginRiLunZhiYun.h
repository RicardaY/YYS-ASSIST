#pragma once
#include "yys_function.h"
class BeginRiLunZhiYun :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//��ˢѡ�����
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//Ѱ����
	int FindRiLunZhiYun(snow *sn, Game *game);
	//��������
	int lockTeam(snow *sn, Game *game);
	//���븱��
	int EnterRiLunZhiYun(snow *sn, Game *game);
	//��ʼ
	int SingleRiLunZhiYun(long hd, int round, int layer, CString jc, snow *sn, Game *game);
	//ͥԺ�������ģʽ
	int inviteRiLunZhiYun(long hd, int round, int layer, CString jc, int mateType, int triple, snow *sn, Game *game);
	//ͥԺ��������ģʽ
	int BeinvitedRiLunZhiYun(long hd, int round, CString jc, snow *sn, Game *game);
};

