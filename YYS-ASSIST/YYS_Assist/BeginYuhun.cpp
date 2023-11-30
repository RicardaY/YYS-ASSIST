#pragma once
#include "pch.h"
#include "BeginYuhun.h"
#include "globalvar.h"

#define EXIT_THREAD -10


//ѡ�����
int BeginYuhun::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString fontLst = _T("Ҽ��|����|����|����|���|½��|���|�Ʋ�|����|ʰ��|����|��");
	CString color_format = _T("4D463D-4D473E");
	// targetTagFont ʰ �� �� CFC8B8-292B28
	double sim = 0.85;
	int dictId = 2;
	//start ѡ���
	Log(_T("ѡ���������...\r\n"), game);
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
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("���"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("½��"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("���"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("�Ʋ�"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("ʰ��"), color_format, sim, dictId, sn, game, _T("findstr"), _T("ʰ|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game, _T("findstr"), _T("��|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	case 11: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("��"), color_format, sim, dictId, sn, game, _T("findstr"), _T("��|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//��ˢѡ�����
int BeginYuhun::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString fontLst = _T("Ҽ��|����|����|����|���|½��|���|�Ʋ�|����|ʰ��|����|��");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start ѡ���
	Log(_T("ѡ���������...\r\n"), game);
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
	case 3: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("���"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("½��"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("���"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("�Ʋ�"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("ʰ��"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 11: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("��"), color_format, sim, dictId, sn, game))
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
int BeginYuhun::FindYuHun(snow *sn, Game *game) {
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
		//���̽����������  114,512,161,537,
		if (sn->FindStrFast(108, 504, 188, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��[��᪴���]D7D2CA-282D25
		if (sn->FindStrFast(36, 149, 93, 189, _T("��"), _T("D7D2CA-282D25"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			Log(_T("�����᪴���...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
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
int BeginYuhun::lockTeam(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����7E6342-3E392A
	long intX, intY;
	Log(_T("����Ƿ���������...\r\n"), game);
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
//���븱�� �귶Χ��335,256,616,497,
int BeginYuhun::EnterYuHun(snow *sn, Game *game) {
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
		if (readyFlag&&(sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("���׼��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }//485 500
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp|��(봽�).bmp|���(봽�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp|��(봽�).bmp|���(봽�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("����ɹ�...\r\n"), game);
			break;
		}
		if (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��սʧ��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ͥԺ�������ģʽ
int BeginYuhun::inviteYuhun(long hd, int round, int layer, CString jc, int mateType, int triple, snow *sn, Game *game) {
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
	//�Զ����ӳ�303,28,327,65,
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 327, endXY.y = 68;
	if (auto_open_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ������
	//��ȡĿ��λ��
	CString fontLst = _T("����|ҵ��|��ת|ˮ��|����|����|����|����|����|����|���|����|ʯ��|���|����|�ع�");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//�ҵ����겢���
	findDestSite(startXY, endXY, fontLst, 5, _T("����"), _T("454039-46413A"), 0.85, 2, sn, game, _T("findstr"), _T("��|CFC8B8-292B28"));
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
		//δ�ҵ�������ѣ�����ͥԺ��رռӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		returnYard(sn, game);
		if (DelayPlus(game, sn, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	else if (resultCreat == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0,stateCode;
	CString count_str;
	while (count<round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����Ѽ�����鲢����ս
		if (IsEnterTeam(sn, game, mateType, triple) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����᪴��߸���
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�����꿪ʼ...\r\n"), game);
		if ((stateCode = InviteEnterEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		if (stateCode == DEFAULT) { DefalutInvite(sn, game); }
		else if (stateCode == FAIL) { FailEvent(sn, game); }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1,waitFlag2);
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (YuHunReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ͥԺ��������ģʽ
int BeginYuhun::BeinvitedYuhun(long hd, int round, CString jc, snow *sn, Game *game) {
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
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	CString count_str;
	Log(_T("�ȴ���������...\r\n"), game);
	while (count < round)
	{
		count_str.Format(_T("%d"), count + 1);
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����᪴��߸���
		int isReadyClick = ReceiveFriendInvite(sn, game);
		if (isReadyClick == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("��") + count_str + _T("�����꿪ʼ...\r\n"), game);
		EnterEvent(sn, game, isReadyClick);
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (YuHunReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ˢ
int BeginYuhun::SingleYuHun(long hd, int round, int layer, CString jc, snow *sn, Game *game) {
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
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��᪴���
	if(FindYuHun(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ����
	startXY.x = 102, startXY.y = 88;
	endXY.x = 361, endXY.y = 468;
	int resultSingleChoose = SingleChooseLayer(layer, startXY, endXY, sn, game);
	if (resultSingleChoose == 0) {
		Log(_T("δ�ҵ�Ŀ��!!!\r\n"), game);
		return 0;
	}else if(resultSingleChoose == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if(lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�������긱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�����꿪ʼ...\r\n"), game);
		if(EnterYuHun(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (YuHunReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//����ͥԺ
int BeginYuhun::YuHunReturnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//�ֿ�
	sn->UseDict(0);
	//��ʼ����
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(9, 2, 76, 65, _T("����(����).bmp|����2.bmp|����3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 2, 76, 65, _T("����1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 1, 65, 59, _T("����4.bmp|����8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 305, 596, 339, _T("ȷ��|ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 429);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if(sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�ɹ�����ͥԺ��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
/**
 *								*********************************************
												   _ooOoo_
												  o8888888o
												  88" . "88
												  (| -_- |)
												  O  =  /O
											   ____/`---'\____
											 .'  \|     |//  `.
											/  \|||  :  |||//  
										   /  _||||| -:- |||||-  
										   |   | \  -  /// |   |
										   | \_|  ''---/''  |   |
											 .-\__  `-`  ___/-. /
										 ___`. .'  /--.--  `. . __
									  ."" '&lt;  `.___\_&lt;|>_/___.'  >'"".
									 | | :  `- \`.;` _ /`;.`/ - ` : | |
										`-.   \_ __ /__ _/   .-` /  /
								======`-.____`-.___\_____/___.-`____.-'======
												   `=---='
								^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
										   ���汣��       ����BUG
 */
