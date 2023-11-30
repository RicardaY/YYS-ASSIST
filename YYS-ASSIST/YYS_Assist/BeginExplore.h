#pragma once
#include "yys_function.h"
class BeginExplore : public yys_function
{
public:
	//�ж��Ƿ���̽������
	int isExplore(snow *sn, Game *game);
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//��ˢѡ�����
	int SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//ѡ���Ѷ�
	int ChooseDiff(int diff, snow *sn, Game *game);
	//���̽��
	int clickExplore(snow *sn, Game *game);
	//���븱�������
	//����Զ��ֻ�--�Ժ��ʵ��ȫ�Զ��ֻ�
	int autoRotate(snow *sn, Game *game);
	//��С�� speed:ˢ���ٶ�
	int findCommonMonster(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//��boss
	int findBossMonster(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//�������
	int InnerCreatTeamToInviteUpper(int preferArea, snow *sn, Game *game);
	int InnerCreatTeamToInviteLower(int preferArea, snow *sn, Game *game);
	//���븱������ʼ̽��
	int EnterExplore(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//��ˢģʽ���븱������ʼ̽��
	//int SingleEnterExplore(CString progressBar, CString materialKinds,  int speed, snow *sn, Game *game);
	//�˳�̽���¼�
	int ExitExploreEvent(snow *sn, Game *game);
	//��ȡ��ཱ��
	int GetReward(int mode, snow *sn, Game *game);
	//ͨ��ͥԺ�ж��Ƿ������
	int IsOutExploreByYard(snow *sn, Game *game);
	//��ӽ��븱��
	int receiveEnterExplore(int count, snow *sn, Game *game);
	//�����ѽ���������ս 
	int IsEnterTeamRepeat(int preferArea, int count, int collectbox, int mode, snow *sn, Game *game);
	//��ȡ�Զ��ֻ�״̬
	int GetAutoRoTateState(snow *sn, Game *game);
	//�ж��Ƿ���Ҫ������
	int IsChangeMaterial(snow *sn, int material, int mode, Game *game);
	//ѡ����ֹ���
	int WhatMaterialToSelect(CString materialKinds, snow *sn, Game *game);
	//����������ѡ��
	int SelectProgressBar(CString progress, snow *sn, Game *game);
	//�Զ�������
	int AutoReplaceMaterial(CString progressBar, CString materialKinds, snow *sn, Game *game);
	//��������
	int ReceiveInvite(int count, int collectbox, int mode, snow *sn, Game *game);
	//��Ӽ���/�������ȴ��¼�
	int CombineWaitRelation(bool &flag1, bool &flag2, snow *sn, Game *game);
	//��ˢ
	int SingleExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds,  int collectbox, int mode, snow *sn, Game *game);
	//����̽��
	int AIExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds, int collectbox, int mode, snow *sn, Game *game);

	//����������
	int inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, int collectbox, int mode, int material, CString progressBar, CString materialKinds, snow *sn, Game *game);
	//��ӽ�������
	int BeinvitedExplore(long hd, int round, CString jc, int collectbox, int mode, snow *sn, Game *game);
	//����ͥԺ
	int ExploreReturnYard(snow *sn, Game *game);
};
