#pragma once
#include "pch.h"
#include "BeginJueXing.h"
#include "globalvar.h"
#define EXIT_THREAD -10

//ѡ��
int BeginJueXing::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString fontLst = _T("Ҽ��|����|����|����|���|½��|���|�Ʋ�|����|ʰ��");
	CString color_format = _T("4D463D-4D473E");
	double sim = 0.85;
	int dictId = 2;
	//start ѡ���
	Log(_T("ѡ����Ѳ���...\r\n"), game);
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
		if (findDestSite(startXY, endXY, fontLst, layer, _T("����"), color_format, sim, dictId, sn, game, _T("findstr"), _T("��|CFC8B8-292B28")))
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
	default:
		return 0;
	}
	return 1;
}
//��ˢѡ�����
int BeginJueXing::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString fontLst = _T("Ҽ��|����|����|����|���|½��|���|�Ʋ�|����|ʰ��");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start ѡ���
	Log(_T("ѡ����Ѳ���...\r\n"), game);
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
	default:
		return 0;
	}
	return 1;
}
//�����ѡ����ֻ���뷽�����������
int BeginJueXing::WhichToSelect(CPoint startXY, CPoint endXY, CString source_font, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	//ʹ���ֿ�
	sn->UseDict(3);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//������
		if (sn->FindStrFast(startXY.x, startXY.y, endXY.x, endXY.y, source_font, _T("AC9B91-282724"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(416, 308, 443, 337, _T("��"), _T("E9D3D5-162C2A"), 0.85, &intX, &intY) != -1) {
			Log(_T("�ɹ��������...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ѡ���ĸ�
int BeginJueXing::ChooseMonster(int monster_kind, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int i = 15;
	//����һЩ����
	CPoint startXY, endXY;
	CString source_font;
	switch (monster_kind)
	{
		//��  AC9B91-282724, 
	case 0: {
		startXY.x = 115, startXY.y = 443;
		endXY.x = 204, endXY.y = 473;
		source_font = _T("ҵ����");
		Log(_T("ѡ�������...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1){ break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//�� 279,281,329,396,
	case 1: {
		startXY.x = 342, startXY.y = 443;
		endXY.x = 418, endXY.y = 473;
		source_font = _T("��ת��");
		Log(_T("ѡ�������...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//ˮ  501,279,552,394,
	case 2: {
		startXY.x = 562, startXY.y = 443;
		endXY.x = 647, endXY.y = 473;
		source_font = _T("ˮ����");
		Log(_T("ѡ��ˮ����...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//�� 728,269,770,390,
	case 3: {
		startXY.x = 788, startXY.y = 443;
		endXY.x = 877, endXY.y = 473;
		source_font = _T("���׹�");
		Log(_T("ѡ��������...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}
	default:
		break;
	}
	return 1;
}
//Ѱ����
int BeginJueXing::FindJueXing(snow *sn, Game *game) {
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
		//������Ѳ���  28,509,101,537,
		if (sn->FindStrFast(9, 506, 130, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			Log(_T("������Ѳ���...\r\n"), game);
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(117, 4, 182, 61, _T("����֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("�ɹ��������...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��������
int BeginJueXing::lockTeam(snow *sn, Game *game) {
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
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
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
int BeginJueXing::EnterJueXing(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int closingflag = 0;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(824, 437, 902, 505, _T("��ս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�����ս...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (readyFlag && (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("���׼��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
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
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ͥԺ�������ģʽ
int BeginJueXing::inviteJueXing(long hd, int round, int mode, int layer, CString jc, int mateType, int triple, snow *sn, Game *game) {
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
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ������
	//��ȡĿ��λ��
	CString fontLst = _T("����|ҵ��|��ת|ˮ��|����|����|����|����|����|����|���|����|ʯ��|���|����|�ع�");
	CString color_format = _T("454039-46413A");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//�ҵ����Ѳ����
	CString mode_str, targetTagFont;
	if (mode==0)
	{
		mode_str = _T("ҵ��");
		targetTagFont = _T("��|CFC8B8-292B28");
	}else if (mode == 1) {
		mode_str = _T("��ת");
		targetTagFont = _T("��|CFC8B8-292B28");
	}
	else if (mode == 2) {
		mode_str = _T("ˮ��");
		targetTagFont = _T("ˮ|CFC8B8-292B28");
	}
	else if (mode == 3) {
		mode_str = _T("����");
		targetTagFont = _T("��|CFC8B8-292B28");
	}
	findDestSite(startXY, endXY, fontLst, mode+1, mode_str, color_format, 0.8, 2, sn, game, _T("findstr"), targetTagFont);
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("δ�ҵ�Ŀ�����!!!\r\n"), game);
		return 0;
	}
	else if (resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������--�������
	if(CreatTeamToInviteUpper(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int resultCreat = CreatTeamToInviteLower(mateType, sn, game);
	if (resultCreat == 0) {
		Log(_T("��������ʧ��!!!\r\n"), game);
		//δ�ҵ�������ѣ�����ͥԺ��رռӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		returnYard(sn, game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}else if(resultCreat == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0, stateCode;
	CString count_str;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����Ѽ�����鲢����ս
		if (IsEnterTeam(sn, game, mateType, triple) == EXIT_THREAD) { return EXIT_THREAD; }
		//������Ѹ���
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�־��ѿ�ʼ...\r\n"), game);
		if ((stateCode = InviteEnterEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
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
int BeginJueXing::BeinvitedJueXing(long hd, int round, CString jc, snow *sn, Game *game) {
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
	if (auto_open_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	CString count_str;
	while (count < round)
	{
		count_str.Format(_T("%d"), count + 1);
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("�ȴ���������...\r\n"), game);
		int isReadyClick = ReceiveFriendInvite(sn, game);
		if (isReadyClick == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("��") + count_str + _T("�־��ѿ�ʼ...\r\n"), game);
		EnterEvent(sn, game, isReadyClick);
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ʼ��ˢ
int BeginJueXing::SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, snow *sn, Game *game) {
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
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ����
	if(FindJueXing(sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ���ĸ�
	int resultChooseMonster = ChooseMonster(monster_kind, sn, game);
	if(resultChooseMonster == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ���� 
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultSingleChoose = SingleChooseLayer(layer, startXY, endXY, sn, game);
	if (resultSingleChoose == 0) {
		Log(_T("δ�ҵ�Ŀ��!!!\r\n"), game);
		return 0;
	}
	else if (resultSingleChoose == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if(lockTeam(sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//������Ѹ���
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�־��ѿ�ʼ...\r\n"), game);
		if (EnterJueXing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("����"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
