#pragma once
#include "yys_function.h"
class BeginTuPo :public yys_function
{
public:
	//������
	int FindTuPo(snow *sn, Game *game);
	//ˢ�¸���
	int ReFresh(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game);
	//��������
	int lockTeam(snow *sn, Game *game);
	//��������
	int BeginTuPo::unlockTeam(snow *sn, Game *game);
	//�ж��Ƿ���ͻ��ȯ
	int isHaveTicket(snow *sn, Game *game);
	//�˳�ͻ�Ʋ��������->��ս->����-->ȷ��-->ʧ��
	int ExitDo(int clickx, int clicky, snow *sn, Game *game);
	//����
	int ExitFour(snow *sn, Game *game);
	//����ͻ�ƽ��븱��
	int StartToFinish(int count, int clickx, int clicky, snow *sn, Game *game);
	//�ͻ����---����
	int AttackToFinish(int count, snow *sn, Game *game);
	//��ʼ
	int StartTuPo(long hd, int round, snow *sn, Game *game);
	//���Ĵ��
	int StartTuPoByExitFourAttackNine(long hd, int round, snow *sn, Game *game);
	int TupoReturnYard(snow *sn, Game *game);
	//ʶ�����ͻ��δͻ��ѡ��
	int BeginTuPo::GetGTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game);
	//ʶ���ͻδͻ�Ʒ�Χ
	int GetLTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game);
	//�ͻ
	int TeamBreak(long hd, int coolingEvent, snow *sn, Game *game);
};

