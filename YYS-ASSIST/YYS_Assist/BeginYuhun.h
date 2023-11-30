#pragma once
#include "yys_function.h"
class BeginYuhun :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//��ˢѡ�����
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//Ѱ����
	int FindYuHun(snow *sn, Game *game);
	//��������
	int lockTeam(snow *sn, Game *game);
	//���븱��
	int EnterYuHun(snow *sn, Game *game);
	//ͥԺ�������ģʽ
	int inviteYuhun(long hd, int round, int layer, CString jc, int mateType, int triple, snow *sn, Game *game);
	//ͥԺ��������ģʽ
	int BeinvitedYuhun(long hd, int round, CString jc, snow *sn, Game *game);
	//��ˢ
	int SingleYuHun(long hd, int round, int layer, CString jc, snow *sn, Game *game);
	//����ͥԺ
	int YuHunReturnYard(snow *sn, Game *game);
};

