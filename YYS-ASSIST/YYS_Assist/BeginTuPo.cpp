#pragma once
#include "pch.h"
#include "BeginTuPo.h"
#include "globalvar.h"
#define EXIT_THREAD -10
//��ɽ��ֹ,������ֹ.�䲻����,������֮��

//Ѱ����
int BeginTuPo::FindTuPo(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(1);
	//����ֲ�����
	long intX, intY;
	Log(_T("Ѱ�ҽ��ͻ��...\r\n"), game);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���ͻ�� 174,512,245,538��
		if (sn->FindStrFast(174, 512, 285, 538, _T("���"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y - 25);
			Log(_T("�ҵ����ͻ��...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(418, 49, 529, 92, _T("��ͻ(������).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�ɹ�������ͻ��...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ˢ�¸���
int BeginTuPo::ReFresh(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(0);
	//����ֲ�����
	long intX, intY;
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(721, 426, 851, 473, _T("ˢ��.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
			Log(_T("���ˢ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x + 10, posXY.y + 10);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x + 10, posXY.y + 10);
			Log(_T("ȷ��ˢ��...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(418, 49, 529, 92, _T("��ͻ(������).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (GetGTPos(rArrString, sn, game) != 0) {
				Log(_T("��ʼ����ͻ����...\r\n"), game);
				break;
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//��������
int BeginTuPo::lockTeam(snow *sn, Game *game) {
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
		if (sn->FindPic(609, 433, 646, 468, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(609, 433, 646, 468, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��������
int BeginTuPo::unlockTeam(snow *sn, Game *game) {
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
		if (sn->FindPic(609, 433, 646, 468, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (sn->FindPic(609, 433, 646, 468, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("��ͻ��������.bmp|��ͻ��������2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//����ͻ�ƽ��븱��
int BeginTuPo::StartToFinish(int count, int clickx, int clicky, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	CString logmsg;
	//�ֿ�
	sn->UseDict(0);
	CString attackimg = _T("");
	if (clicky < 200) {attackimg = _T("����1.bmp|����2.bmp|����3.bmp");}
	else if (clicky >= 200 && clicky < 300) { attackimg = _T("����4.bmp|����5.bmp|����6.bmp"); }
	else{ attackimg = _T("����7.bmp|����8.bmp|����9.bmp"); }
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(418, 49, 529, 92, _T("��ͻ(������).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(clickx, clicky, 2, 5);
			logmsg.Format(_T("%d,%d"), clickx, clicky);
			if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) == -1) {
				Log(_T("�ҵ��ɹ��ƽ��[") + logmsg + _T("]\r\n"), game);
				sn->MoveClick(pos.x - 15, pos.y + 15);
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//604,311,863,535,
		if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("ʶ�𵽽���...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 3000, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		//����Ƿ������ε�һ������
		if (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			Log(_T("����ɹ�...\r\n"), game);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 2500, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			Log(_T("����ɹ�...\r\n"), game);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(271, 40, 423, 216, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("��սʧ�ܣ����ƴ���...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			count--;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(418, 49, 529, 92, _T("��ͻ(������).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return count;
}
//�ͻ����---����
int BeginTuPo::AttackToFinish(int count, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�ֿ�
	sn->UseDict(3);
	//����ֲ�����
	long intX, intY;
	int WinOrFailFlag = 0;
	int BeAttackedFlag = 0;
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(298, 91, 823, 491, _T("����"), _T("3E301D-3F301D"), 0.75, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�������...\r\n"), game);
			BeAttackedFlag++;
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			Log(_T("����ɹ�...\r\n"), game);
			sn->MoveClick(pos.x, pos.y);
			WinOrFailFlag = 1;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(271, 40, 423, 216, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("��սʧ��...\r\n"), game);
			WinOrFailFlag = 0;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((sn->FindPic(902, 264, 950, 349, _T("�ͻ(ѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) && (sn->FindPic(145, 444, 176, 482, _T("�ͻ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			break;
		}
		if (sn->FindStrFast(151, 138, 236, 170, _T("�ѹ���"), _T("D7C95D-282B20"), 0.9, &intX, &intY) != -1) {
			WinOrFailFlag = 1;
			break;
		}
		if (BeAttackedFlag >= 3) {
			Log(_T("�˽������ѱ����ƣ��Ѷ���...\r\n"), game);
			WinOrFailFlag = 0;
			if (sn->FindStrFast(298, 91, 823, 491, _T("����"), _T("3E301D-3F301D"), 0.75, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(158, 237, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return WinOrFailFlag;
}
//�ж��Ƿ���ͻ��ȯ
int BeginTuPo::isHaveTicket(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�ֿ�
	sn->UseDict(3);
	//����ֲ�����
	long intX, intY;
	int i = 3;
	while (i > 0) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((sn->FindStrFast(860, 13, 906, 36, _T("ͻ��ȯ30"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) == -1) && (sn->FindStrFast(860, 13, 906, 36, _T("ͻ��ȯ20"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) == -1) && (sn->FindStrFast(860, 13, 906, 36, _T("ͻ��ȯ10"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) == -1) && (sn->FindStrFast(860, 13, 906, 36, _T("ͻ��ȯ0"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//�˳�ͻ�Ʋ��������->��ս->����-->ȷ��-->ʧ��
int BeginTuPo::ExitDo(int clickx, int clicky, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	CString logmsg;
	CString attackimg = _T("");
	if (clicky < 200) { attackimg = _T("����1.bmp|����2.bmp|����3.bmp"); }
	else if (clicky >= 200 && clicky < 300) { attackimg = _T("����4.bmp|����5.bmp|����6.bmp"); }
	else { attackimg = _T("����7.bmp|����8.bmp|����9.bmp"); }
	//�ֿ�
	sn->UseDict(0);
	int flag = 0;
	//���->��ս
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(418, 49, 529, 92, _T("��ͻ(������).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			logmsg.Format(_T("%d,%d"), clickx, clicky);
			CPoint pos = sn->RandomOffsetPos(clickx, clicky, 2, 5);
			if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) == -1) {
				Log(_T("�ҵ��ɹ��ƽ��[") + logmsg + _T("]\r\n"), game);
				sn->MoveClick(pos.x - 15, pos.y + 15);
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("ʶ�𵽽���...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�˳�λ�� 0, 0, 56, 58
		if ((flag == 0) && (findBackIconSite(sn, game, intX, intY) != -1)) {
			if (DelayPlus(game, sn, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x, posXY.y);
			Log(_T("��ʼ�˳�...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(531, 303, 584, 333, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(posXY.x + 5, posXY.y + 5);
			Log(_T("ȷ���˳�...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			flag = 1;
		}
		if (sn->FindPic(271, 40, 423, 216, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(635, 495, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�˳�����ͻ��...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(635, 495, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�˳�����  418,49,529,92,
		if (sn->FindPic(418, 49, 529, 92, _T("��ͻ(������).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�˳��ɹ�...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//����
int BeginTuPo::ExitFour(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//���궨��
	CPoint startXY, endXY;
	CArray<CPoint, CPoint> rArrString;
	int counter = 4;
	int sum = GetGTPos(rArrString, sn, game);
	if (sum == 9) {
		unlockTeam(sn, game);
	}
	while (sum == 9 && counter) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (!isHaveTicket(sn, game)) {
			break;
		}
		ExitDo(rArrString.GetAt(0).x, rArrString.GetAt(0).y, sn, game);
		counter--;
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (counter <= 0) {
		lockTeam(sn, game);
	}
	return 1;
}
//��ʼ
int BeginTuPo::StartTuPo(long hd, int round, snow *sn, Game *game) {
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
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱͻ��
	if (FindTuPo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if (lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѭ����ʼ
	//����ֲ�����
	CArray<CPoint, CPoint> parray;
	CString count_str;
	int count = 0;
	//��ʼ����ͻ����
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (GetGTPos(parray, sn, game) != 0) {
			break;
		}
		else {
			//ˢ��
			Log(_T("���ˢ�°�ť(��ˢ�°�ť����ȴ�У���ȴ�)...\r\n"), game);
			ReFresh(parray, sn, game);
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�ж��Ƿ���ȯ    ͻ�ƾ�10:858,2,885,37
		int ticket = isHaveTicket(sn, game);
		if (ticket == 0) {
			count = round;
			break;
		}
		else if (ticket == EXIT_THREAD) {
			return EXIT_THREAD;
		}
		//��ʼͻ��
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("��ͻ�ƿ�ʼ...\r\n"), game);
		count = StartToFinish(count, parray.GetAt(0).x, parray.GetAt(0).y, sn, game);
		parray.RemoveAt(0);
		if (parray.GetSize() == 0) {
			if (GetGTPos(parray, sn, game) == 0) {
				//ˢ��
				Log(_T("���ˢ�°�ť(��ˢ�°�ť����ȴ�У���ȴ�)...\r\n"), game);
				ReFresh(parray, sn, game);
			}
		}
		count++;
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	}

	return 1;
}
//���Ĵ��
int BeginTuPo::StartTuPoByExitFourAttackNine(long hd, int round, snow *sn, Game *game) {
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
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱͻ��
	if (FindTuPo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if (lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѭ����ʼ
	//����ֲ�����
	CArray<CPoint, CPoint> parray;
	CString count_str;
	int count = 0;
	//��ʼ����ͻ����
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (GetGTPos(parray, sn, game) != 0) {
			break;
		}
		else {
			//ˢ��
			Log(_T("���ˢ�°�ť(��ˢ�°�ť����ȴ�У���ȴ�)...\r\n"), game);
			ReFresh(parray, sn, game);
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	Log(_T("����Ƿ���Ҫ����...\r\n"), game);
	ExitFour(sn, game);
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//start
		//�ж��Ƿ���ȯ    ͻ�ƾ�10:858,2,885,37
		int ticket = isHaveTicket(sn, game);
		if (ticket == 0) {
			count = round;
			break;
		}
		else if (ticket == EXIT_THREAD) {
			return EXIT_THREAD;
		}
		//��ʼͻ��
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("��ͻ�ƿ�ʼ...\r\n"), game);
		count = StartToFinish(count, parray.GetAt(0).x, parray.GetAt(0).y, sn, game);
		parray.RemoveAt(0);
		if (parray.GetSize() == 0) {
			if (GetGTPos(parray, sn, game) == 0) {
				//ˢ��
				Log(_T("���ˢ�°�ť(��ˢ�°�ť����ȴ�У���ȴ�)...\r\n"), game);
				ReFresh(parray, sn, game);
			}
			//�Ƿ�����
			Log(_T("����Ƿ���Ҫ����...\r\n"), game);
			ExitFour(sn, game);
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//����ͥԺ
int BeginTuPo::TupoReturnYard(snow *sn, Game *game) {
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
		if (sn->FindPic(861, 59, 948, 139, _T("��1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(14, 17, 67, 71, _T("����1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�ɹ�����ͥԺ��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ʶ�����ͻ��δͻ��ѡ��
int BeginTuPo::GetGTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game) {
	rArrString.RemoveAll();
	if (sn == NULL)
	{
		return false;
	}

	CStringArray arrayList, postList, tempList;
	postList.RemoveAll();
	CString poscount = sn->FindPicEx(282, 92, 874, 418, _T("ͻ�Ƶط�.bmp|ͻ�Ƶط�(��̫).bmp"), _T("202020"), 0.95, 0);
	if (poscount.IsEmpty()) {
		return 0;
	}
	if (!poscount.IsEmpty()) {
		//��ȡ����
		int len = sn->SplitString(poscount, _T("|"), arrayList, 0);
		for (int i = 0; i < len; i++) {
			int tempsize = sn->SplitString(arrayList.GetAt(i), _T(","), tempList, 0);
			for (int j = 0; j < tempsize; j++) {
				if (j % 3 != 0) {
					postList.Add(tempList.GetAt(j));
				}
			}
		}
	}
	//��ȡΪCPoint����
	int len = postList.GetSize();
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			rArrString.Add(CPoint(StrToInt(postList.GetAt(i)), StrToInt(postList.GetAt(i + 1))));
		}
	}
	//����
	sn->sortPoints(rArrString);
	return (int)rArrString.GetSize();
}
//ʶ���ͻδͻ�Ʒ�Χ
int BeginTuPo::GetLTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game) {
	rArrString.RemoveAll();
	if (sn == NULL)
	{
		return false;
	}

	CStringArray arrayList, postList, tempList;
	postList.RemoveAll();
	CString poscountL = sn->FindPicEx(527, 84, 564, 493, _T("�ͻ�ط�(��).bmp"), _T("151515"), 0.95, 0);
	CString poscountR = sn->FindPicEx(785, 96, 824, 493, _T("�ͻ�ط�(��).bmp"), _T("151515"), 0.95, 0);
	if (poscountL.IsEmpty() && poscountR.IsEmpty()) {
		return 0;
	}
	if (!poscountL.IsEmpty()) {
		//��ȡ����
		int len = sn->SplitString(poscountL, _T("|"), arrayList, 0);
		for (int i = 0; i < len; i++) {
			int tempsize = sn->SplitString(arrayList.GetAt(i), _T(","), tempList, 0);
			for (int j = 0; j < tempsize; j++) {
				if (j % 3 != 0) {
					postList.Add(tempList.GetAt(j));
				}
			}
		}
	}
	if (!poscountR.IsEmpty()) {
		int len = sn->SplitString(poscountR, _T("|"), arrayList, 0);
		for (int i = 0; i < len; i++) {
			int tempsize = sn->SplitString(arrayList.GetAt(i), _T(","), tempList, 0);
			for (int j = 0; j < tempsize; j++) {
				if (j % 3 != 0) {
					postList.Add(tempList.GetAt(j));
				}
			}
		}
	}
	//��ȡΪCPoint����
	int len = postList.GetSize();
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			rArrString.Add(CPoint(StrToInt(postList.GetAt(i)), StrToInt(postList.GetAt(i + 1))));
		}
	}
	return (int)rArrString.GetSize();
}
//�ͻ
int BeginTuPo::TeamBreak(long hd, int coolingEvent, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	CArray<CPoint, CPoint> parray;
	int i, count;
	CString picName = _T("1�λ���.bmp|2�λ���.bmp|3�λ���.bmp|4�λ���.bmp|5�λ���.bmp|6�λ���.bmp");
	CString logmsg;
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
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱͻ��
	if (FindTuPo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(902, 264, 950, 349, _T("�ͻ(δѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("ѡ���ͻ...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(145, 444, 176, 482, _T("�ͻ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((sn->FindPic(902, 264, 950, 349, _T("�ͻ(ѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) && (sn->FindPic(145, 444, 176, 482, _T("�ͻ����.bmp|�ͻ(����2).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//�ֿ�
	sn->UseDict(3);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(195, 410, 247, 449, _T("0�λ���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (coolingEvent == 0) {
				Log(_T("�����þ����ȴ���ȴ...\r\n"), game);
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(195, 410, 247, 449, picName, _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (DelayPlus(game, sn, 5000, 10000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			else {
				if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}
		if (sn->FindStrFast(151, 138, 236, 170, _T("�ѹ���"), _T("D7C95D-282B20"), 0.9, &intX, &intY) != -1) {
			Log(_T("�ѹ��ƣ�����ͥԺ...\r\n"), game);
			if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			break;

		}
		//D7C95D-282B20 ����
		if ((count = GetLTPos(parray, sn, game)) != 0) {
			for (i = 0; i < count; i++) {
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(195, 410, 247, 449, picName, _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						logmsg.Format(_T("%d,%d"), parray.GetAt(i).x, parray.GetAt(i).y);
						Log(_T("�ҵ�Ŀ����[") + logmsg + _T("]\r\n"), game);
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(parray.GetAt(i).x, parray.GetAt(i).y, 0, 5);
						sn->MoveClick(pos.x - 45, pos.y + 15);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					
					if (sn->FindStrFast(298, 91, 823, 491, _T("����"), _T("3E301D-3F301D"), 0.75, &intX, &intY) != -1) {
						Log(_T("ʶ�𵽽���...\r\n"), game);
						break;
					}
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (AttackToFinish(count, sn, game)) {
					break;
				}
			}
		}
		else {
			//ģ����ʵ���켣
			sn->EnableRealMouse(1, 20, 30);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->DragMouse(540, 420, 540, 380);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			//ģ����ʵ���켣
			sn->EnableRealMouse(3, 20, 30);
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
