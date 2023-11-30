#pragma once
#include "yys_function.h"
class BeginJueXing :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//��ˢѡ�����
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//�����ѡ����ֻ���뷽�����������
	int WhichToSelect(CPoint startXY, CPoint endXY, CString source_font, snow *sn, Game *game);
	//ѡ���ĸ�
	int ChooseMonster(int monster_kind, snow *sn, Game *game);
	//�Ҹ���
	int FindJueXing(snow *sn, Game *game);
	//��������
	int lockTeam(snow *sn, Game *game);
	//���븱��
	int EnterJueXing(snow *sn, Game *game);
	//ͥԺ�������ģʽ
	int inviteJueXing(long hd, int round, int mode,  int layer, CString jc, int mateType, int triple, snow *sn, Game *game);
	//ͥԺ��������ģʽ
	int BeinvitedJueXing(long hd, int round, CString jc, snow *sn, Game *game);
	//��ˢ
	int SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, snow *sn, Game *game);
};

