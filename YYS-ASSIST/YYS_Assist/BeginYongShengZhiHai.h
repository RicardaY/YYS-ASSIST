#pragma once
#include "yys_function.h"
class BeginYongShengZhiHai :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//��ˢѡ�����
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//�жϺ����Ƿ����
	int InnerIsEnterTeam(int mateType, int count, snow *sn, Game *game);
	//��������---�������
	int CreatYszhTeamToInviteUpper(int mateType, snow *sn, Game *game);
	int CreatYszhTeamToInviteLower(int mateType, snow *sn, Game *game);
	//Ѱ����
	int FindYongShengZhiHai(snow *sn, Game *game);
	//��������
	int lockTeam(snow *sn, Game *game);
	//���븱��
	int EnterYongShengZhiHai(snow *sn, Game *game);
	//��ʼ
	int SingleYongShengZhiHai(long hd, int round, int layer, CString jc, snow *sn, Game *game);
	//ͥԺ�������ģʽ
	int inviteYongShengZhiHai(long hd, int round, int layer, CString jc, int mateType, snow *sn, Game *game);
	//ͥԺ��������ģʽ
	int BeinvitedYongShengZhiHai(long hd, int round, CString jc, snow *sn, Game *game);
};

