#pragma once
#include "yys_function.h"
class InDependentFunction :public yys_function
{
public:
	//�ٹ�ҹ��
	int StartBaiGui(int round, snow *sn, Game *game);
	//���������һֻ
	int SelectWhichReginalKing(CPoint startXY, CPoint endXY, int kindCheck, snow *sn, Game *game);
	//�������
	int StartReginalKing(long hd, int amount,int kindCheck, snow *sn, Game *game);
	//�Զ�������---����
	int ClickMonsterToVictory(snow *sn, Game *game);
	//�Զ�����
	int AutoPlot(snow *sn, Game *game);
	//�Զ�����
	int AutoPVP(snow *sn, Game *game);
	int AutoPVPToMingShi(snow *sn, Game *game);
	//�»
	int StartNewEvent(int round, int mode, int flag, int bossflag, snow *sn, Game *game);
	//��ѡ����
	int DIYFunction(int ready, int clearing, int whitecard, int challenge, snow *sn, Game *game);

	//������
	//1.����Ƿ��й���
	int CheckSuperGhostKing(int count, snow *sn, Game *game);
	//2.����Ǽ�
	int CheckSuperGhostKingStar(snow *sn, Game *game);
	//	2-1 �Ƿ񲥱��������ǹ�����ֹͣ
	int IsStopAndAlert(int star, int star_stop, snow *sn, Game *game);
	//	2-2 �������ǹ���
	int OpenHignStarSuperGhostKing(snow *sn, Game *game);
	//		2-2-1 �ȴ�����������
	int WaitSuperGhostKingKilled(snow *sn, Game *game);
	//3.���Ѫ��
	int CheckSuperGhostKingBlood(snow *sn, Game *game);
	//4.�����ս(include ǿ׷)
	int inline ClickChallenge(int star, int blood, int strenghCheck, snow *sn, Game *game);
	//5.��������
	//	5.1ѡ��&��
	int selectgroup(int group, int team, snow *sn, Game *game);
	//	5.2 ���Ԥ��
	int ClickPreset(snow *sn, Game *game);
	//	5.3 ��ʼ������
	int ChangeStaff(int star, int blood, int group[], int team[], int bloodsel[], snow *sn, Game *game);
	//6.׼��-����
	int EnterSuperGhostKingSection(int flag_own, int flag_boss, snow *sn, Game *game);
	//7.��ʼ������
	int StartSuperGhostKing(int round, int strenghCheck, int group[], int team[], int bloodsel[], int flag_own, int flag_boss, int star_stop, int star_public, snow *sn, Game *game);
	//����
	int StartMiWen(snow *sn, Game *game, int round = 10);
	//��������
	int StartLingRan(snow *sn, Game *game, int round = 50);
};

