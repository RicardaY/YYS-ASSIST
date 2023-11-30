#pragma once
#include "pch.h"
#include "BeginRiLunZhiYun.h"
#include "globalvar.h"
#define EXIT_THREAD -10


//ѡ��
int BeginRiLunZhiYun::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString fontLst = _T("Ҽ��|����|����");
	CString color_format = _T("4D463D-4D473E");
	double sim = 0.85;
	int dictId = 2;
	//start ѡ���
	Log(_T("ѡ������֮�ɲ���...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("Ҽ��"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game, _T("findstr"), _T("��|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//��ˢѡ��
int BeginRiLunZhiYun::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString fontLst = _T("Ҽ��|����|����");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start ѡ���
	Log(_T("ѡ������֮��...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("Ҽ��"), color_format, sim, dictId, sn, game))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//Ѱ����
int BeginRiLunZhiYun::FindRiLunZhiYun(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(1);
	//����ֲ�����
	long intX, intY;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�������
		if (sn->FindStrFast(108, 504, 188, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//������֮�� D4CFBC-2B3030
		if (sn->FindStrFast(585, 75, 644, 128, _T("��"), _T("D2CCBF-2D3336"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			Log(_T("�������֮��...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(793, 119, 819, 141, _T("��"), _T("E9D3D5-162C2A"), 0.85, &intX, &intY) != -1) {
			Log(_T("�ɹ��������...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��������
int BeginRiLunZhiYun::lockTeam(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(411, 415, 452, 454, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 13, intY + 13);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(411, 415, 452, 454, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//���븱��
int BeginRiLunZhiYun::EnterRiLunZhiYun(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(0);
	//����ֲ�����
	long intX, intY;
	int closingflag = 0;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(824, 437, 902, 505, _T("��սҵԭ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�����ս...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (readyFlag && (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("���׼��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("����ɹ�...\r\n"), game);
			break;
		}
		if (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��սʧ��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ʼ��ˢ
int BeginRiLunZhiYun::SingleRiLunZhiYun(long hd, int round, int layer, CString jc, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//��ʼ��׼����־
	readyFlag = TRUE;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ����֮��
	if (FindRiLunZhiYun(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ����
	CPoint startXY, endXY;
	startXY.x = 110, startXY.y = 93;
	endXY.x = 360, endXY.y = 439;
	int resultSingleChoose = SingleChooseLayer(layer, startXY, endXY, sn, game);
	if (resultSingleChoose == 0) {
		Log(_T("δ�ҵ�Ŀ��!!!\r\n"), game);
		return 0;
	}else if(resultSingleChoose == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if (lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//����ҵԭ�𸱱�
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("������֮�ɿ�ʼ...\r\n"), game);
		if (EnterRiLunZhiYun(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ͥԺ�������ģʽ
int BeginRiLunZhiYun::inviteRiLunZhiYun(long hd, int round, int layer, CString jc, int mateType, int triple, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Ⱥ����¼�
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼ��׼����־
	readyFlag = TRUE;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ������֮��
	//��ȡĿ��λ��
	CString fontLst = _T("����|ҵ��|��ת|ˮ��|����|����|����|����|����|����|���|����|ʯ��|���|����|�ع�");
	CString color_format = _T("454039-46413A");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//�ҵ�����֮�ɲ����
	findDestSite(startXY, endXY, fontLst, 6, _T("����"), color_format,0.8,2, sn, game, _T("findstr"), _T("��|CFC8B8-292B28"));
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("δ�ҵ�Ŀ�����!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������--�������
	if (CreatTeamToInviteUpper(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int resultCreat = CreatTeamToInviteLower(mateType, sn, game);
	if (resultCreat == 0) {
		Log(_T("��������ʧ��!!!\r\n"), game);
		if (DelayPlus(game, sn, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}else if (resultCreat == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0, stateCode;
	CString count_str;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����Ѽ�����鲢����ս
		if (IsEnterTeam(sn, game, mateType, triple) == EXIT_THREAD) { return EXIT_THREAD; }
		//��������֮�ɸ���
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("������֮�ɿ�ʼ...\r\n"), game);
		if ((stateCode = InviteEnterEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		if (stateCode == DEFAULT) { DefalutInvite(sn, game); }
		else if (stateCode == FAIL) { FailEvent(sn, game); }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ͥԺ��������ģʽ
int BeginRiLunZhiYun::BeinvitedRiLunZhiYun(long hd, int round, CString jc, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Ⱥ����¼�
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼ��׼����־
	readyFlag = TRUE;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	//��ʼѭ��
	int count = 0;
	CString count_str;
	while (count < round)
	{
		count_str.Format(_T("%d"), count + 1);
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//��������֮�ɸ���
		Log(_T("�ȴ���������...\r\n"), game);
		int isReadyClick = ReceiveFriendInvite(sn, game);
		if (isReadyClick == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("��") + count_str +_T( "������֮�ɿ�ʼ...\r\n"), game);
		EnterEvent(sn, game, isReadyClick);
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}