#pragma once
#include "pch.h"
#include "BeginYuLing.h"
#include "globalvar.h"
#define EXIT_THREAD -10

//ѡ��
int BeginYuLing::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
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
	default:
		return 0;
	}
	return 1;
}
//�����ѡ����ֻ���鷽�����������
int BeginYuLing::WhichToSelect(CPoint startXY, CPoint endXY, CString source_pic[2], snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	while (1)
	{	
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//������
		if (sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[0], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}//δ����
		if (sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[1], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			return 0;
		}
		if (sn->FindPic(824, 437, 902, 505, _T("��ս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ѡ���ĸ�
int BeginYuLing::ChooseMonster(int monster_kind, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int i = 15;
	//����һЩ����
	CPoint startXY, endXY;
	CString source_pic[2];
	switch (monster_kind)
	{
	//����
	case 0: {
		startXY.x = 95, startXY.y = 427;
		endXY.x = 140, endXY.y = 484;
		source_pic[0] = _T("������.bmp"), source_pic[1] = _T("������(δ����).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("ѡ������...\r\n"), game);
			break;
		}else if(resultToSelect == 0){ return 0; }
		else if(resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//�ײ���
	case 1: {
		startXY.x = 313, startXY.y = 429;
		endXY.x = 372, endXY.y = 482;
		source_pic[0] = _T("���ײ���.bmp"), source_pic[1] = _T("���ײ���(δ����).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("ѡ�񰵰ײ���...\r\n"), game);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//�ڱ� 
	case 2: {
		startXY.x = 526, startXY.y = 432;
		endXY.x = 587, endXY.y = 489;
		source_pic[0] = _T("���ڱ�.bmp"), source_pic[1] = _T("���ڱ�(δ����).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("ѡ�񰵺ڱ�...\r\n"), game);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//��ȸ  747,430,802,485,
	case 3: {
		startXY.x = 747, startXY.y = 430;
		endXY.x = 802, endXY.y = 485;
		source_pic[0] = _T("����ȸ.bmp"), source_pic[1] = _T("����ȸ(δ����).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("ѡ�񰵿�ȸ...\r\n"), game);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}
	default:
		break;
	}
	return 1;
}
//Ѱ����
int BeginYuLing::FindYuLing(snow *sn, Game *game) {
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
		//�������  253,514,307,538,
		if (sn->FindStrFast(253, 512, 351, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(101, 7, 167, 50, _T("����֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("�ɹ��������...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��������
int BeginYuLing::lockTeam(snow *sn, Game *game) {
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
		if (sn->FindPic(411, 415, 452, 454, _T("�����������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 13, intY + 13);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(411, 415, 452, 454, _T("������������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//���븱��
int BeginYuLing::EnterYuLing(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�ֿ�
	sn->UseDict(0);
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
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
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
			Log(_T("����ɹ�\r\n"), game);
			break;
		}
		if (sn->FindPic(271, 40, 423, 216, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("��սʧ��\r\n"), game);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
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
//��ʼ
int BeginYuLing::StartYuLing(long hd, int round, int monster_kind, int layer, snow *sn, Game *game) {
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
	//Ѱ����
	if(FindYuLing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ���ĸ�
	if (!ChooseMonster(monster_kind, sn, game)) {
		Log(_T("��������տ���δ������\r\n"), game);
		Log(_T("���ڷ���ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	//ѡ����
	CPoint startXY, endXY;
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("δ�ҵ�Ŀ��!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if(lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�������鸱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�����鿪ʼ...\r\n"), game);
		if(EnterYuLing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
