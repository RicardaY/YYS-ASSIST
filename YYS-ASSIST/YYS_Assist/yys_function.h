#pragma once
#include "snow.h"
#include "Game.h"
#define NOMAL 500
#define FAIL 404
#define DEFAULT 501
#define NULL_LIST -1
#define ERR_CODE -2

class yys_function
{
public:
	//��ʾ
	int Tips(Game *game);
	//����ͥԺ��ʾ��Ϣ
	int NotInYardTips(long hd, snow *sn, Game *game);
	//��ͥԺ��δ�ҵ�̽��������ʾ��Ϣ
	int InYardNoExploreLanternTips(Game *game);
	//���ļ�
	int ReadFile(CString filePath, int loff, CStringArray& ListArray);
	//д�ļ�
	int WriteFile(CString filePath, int loff, CStringArray& ListArray);
	//�༭���β׷������
	void Log(CString logMsg, Game *game);
	//����ӳٵ������ֹ��Ϸ��Ҽ��
	int DelayPlus(Game *game, snow *sn, int minms = 1000, int maxms = 2500);
	//�ж��Ƿ���ͥԺ
	bool IsInYard(snow *sn, Game *game);
	//�ж�ͥԺ�Ƿ�չ��
	bool IsShowYard(snow *sn, Game *game);
	//չ��ͥԺ
	int showYard(snow *sn, Game *game);
	//Ѱ��̽�����������
	int FindExploreLanTernAndClick(snow *sn, Game *game);
	//������
	int CombineTeamAction(snow *sn, Game *game);
	//��ȡ��ǰλ��
	long findCurrentSite(CPoint startXY, CPoint endXY, CString picFontLst, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode = _T("findstr"));
	//Ѱ�ҷ���ͼ��λ��
	long findBackIconSite(snow *sn, Game *game, long &intX, long &intY);
	//Ѱ���ֶ�ͼ��λ��
	long findManualSite(snow *sn, Game *game, long &intX, long &intY);
	//Ѱ��Ŀ��λ�ò����   targetTagFont: ̽|color_format
	int findDestSite(CPoint startXY, CPoint endXY, CString picFontLst, long targetSite, CString tartgetPicFont, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode = _T("findstr"), CString targetTagFont = nullptr);
	//��������
	int CreatTeamToInviteUpper(int mateType, snow *sn, Game *game);
	int CreatTeamToInviteLower(int mateType, snow *sn, Game *game);
	//��ӹ�ϵ
	int TeamRelation(bool &flag1, bool &flag2, snow *sn, Game *game);
	//�����Ƿ�������
	int IsEnterTeam(snow *sn, Game *game, int mateType, int triple);
	//������븱��
	int InviteEnterEvent(snow *sn, Game *game);
	//��������
	int ReceiveFriendInvite(snow *sn, Game *game);
	//���븱��
	int EnterEvent(snow *sn, Game *game, bool isReadyClick);
	//Ĭ���������
	int DefalutInvite(snow *sn, Game *game);
	//ʧ���¼�
	int FailEvent(snow *sn, Game *game);
	//�Զ����ӳ�
	int auto_open_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game);
	//�Զ��ؼӳ�
	int auto_close_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game);
	//�Զ��ܾ����ͷ�ӡ
	int AutoRejectXS(snow *sn, Game *game);
	//����ͥԺ
	int returnYard(snow *sn, Game *game);
	//΢������
	int PushPlus(CString token, int pushstate, CString tips, Game *game);
};
