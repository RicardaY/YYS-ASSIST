#include "pch.h"
#include "InDependentFunction.h"
#include "Resource.h"
#include "SuperKing.h"
#include "globalvar.h"
#define EXIT_THREAD -10
/*
		��������Ƽ֮ĩ���˳���΢��֮��
*/
//�ٹ�ҹ��
int InDependentFunction::StartBaiGui(int round, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	Log(_T("��������--�ٹ�ҹ��\r\n"), game);
	if (sn->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)
	{
		Log(_T("�����ٹ�ҹ��ҳ��...\r\n"), game);
		return 0;
	}
	Log(_T("Ĭ��1000��Ʊ����ʱ���ɸ���...\r\n"), game);
	int count = 0;
	while (count < round) {
		//�ܾ�����
		AutoRejectXS(sn, game);
		if (sn->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("����ٹ�ҹ��...\r\n"), game);
			sn->MoveClick(intX + 10, intY + 20);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}//416,3,553,59,
		if (sn->FindPic(416, 3, 553, 59, _T("�ٹ�ҹ��.bmp|�ٹ�ҹ��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(442, 69, 521, 441, _T("�ٹ�Ѻ.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("Ѻʽ��...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(477, 314, 1, 4);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(442, 69, 521, 441, _T("�ٹ�Ѻ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(833, 427, 915, 481, _T("�ٹ�ʼ.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					CString count_str;
					count_str.Format(_T("%d"), count + 1);
					Log(_T("��")+count_str+_T("�ְٹ�ҹ�п�ʼ...\r\n"), game);
					sn->MoveClick(intX + 10, intY + 5);
					if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (sn->FindPic(44, 473, 101, 514, _T("�ٹ���.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->DragMouse(305, 496, 459, 496);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��ʼ����...\r\n"), game);
			count++;
			while (1) {
				AutoRejectXS(sn, game);
				CPoint posx = sn->RandomOffsetPos(507, 295, -200, 200);
				CPoint posy = sn->RandomOffsetPos(507, 295, -5, 5);
				sn->MoveClick(posx.x, posy.y);
				int beanRes = sn->FindPic(34, 468, 134, 515, _T("����0��.bmp|����0��.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				int timeRes = sn->FindPic(448, 1, 508, 50,  _T("ʱ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				while ((beanRes != -1) || (timeRes != -1)) {
					if (sn->FindPic(72, 165, 117, 335, _T("�ٹ���Լ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->MoveClick(intX + 10, intY + 5);
						if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= round) {
		Log(_T("��ɰٹ�ҹ��...\r\n"), game);
	}
	return 1;
}
//���������һֻ
int InDependentFunction::SelectWhichReginalKing(CPoint startXY, CPoint endXY, int kindCheck, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	sn->UseDict(4);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(821, 3, 883, 72, _T("ɸѡ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("ѡ��ɸѡ...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((kindCheck == (int)IDC_RADIO_HOT) && (sn->FindPic(890, 129, 926, 208, _T("����(ѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			Log(_T("����...\r\n"), game);
			break;
		}else if ((kindCheck== (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("�ղ�(ѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			Log(_T("�ղ�...\r\n"), game); 
			break;
		}
		if ((kindCheck== (int)IDC_RADIO_HOT) && (sn->FindPic(890, 129, 926, 208, _T("����(δѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((kindCheck== (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("�ղ�(δѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, _T("�ع���ս.bmp|�ع���ս2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
		{
			Log(_T("��ս...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
		if (sn->FindPic(813, 372, 893, 425, _T("�ع�ʼ��ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1){
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(385, 27, 437, 76, _T("�ع���ͨ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�л�Ϊ��ͨģʽ...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(104, 198, 414, 244, _T("�ع������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�������-��ͨ�Ѷ�...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(813, 372, 893, 425, _T("�ع�ʼ��ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			while (sn->FindPic(224, 139, 292, 202, _T("�ع�1��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)
			{
				//������һ��
				if (sn->FindPic(104, 198, 414, 244, _T("�ع������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					if (intX > 112) {
						sn->EnableRealMouse(1, 20, 30);
						Log(_T("����һ��...\r\n"), game);
						if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(intX + 3, intY + 5, 112, intY + 5);
						if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(224, 139, 292, 202, _T("�ع�1��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			sn->EnableRealMouse(3, 20, 30);
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(813, 372, 893, 425, _T("�ع�ʼ��ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("��ʼ��ս...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���������İײ�����ʾ(����)
		if (sn->FindPic(263, 215, 366, 304, _T("С��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("���С��������ʾ...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��׼��
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findManualSite(sn, game, intX, intY) != -1) { //CAD5E4-34291A
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�л�Ϊ�Զ�ģʽ...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while(1){
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//ʤ������
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����ɹ�...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(813, 372, 893, 425, _T("�ع�ʼ��ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(813, 372, 893, 425, _T("�ع�ʼ��ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("���ص����������...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(907, 32);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(821, 3, 883, 72, _T("ɸѡ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("���سɹ�...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//�������
int InDependentFunction::StartReginalKing(long hd, int amount, int kindCheck, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(1);
	//����ֲ�����
	long intX, intY;
	Log(_T("��������--�������\r\n"), game);
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	while (1) {
		//�Զ��ܾ�����  540,511,614,536,
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(540, 511, 690, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("����������...\r\n"), game);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�����������λ��
		if (sn->FindStrFast(465, 508, 537, 534, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("����������...\r\n"), game);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(821, 3, 883, 72, _T("ɸѡ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			break;
		}
		if ((kindCheck == (int)IDC_RADIO_HOT)&&(sn->FindPic(890, 129, 926, 208, _T("����(ѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)){break;}
		else if ((kindCheck == (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("�ղ�(ѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) { break; }
		if ((kindCheck == (int)IDC_RADIO_HOT)&&(sn->FindPic(890, 129, 926, 208, _T("����(δѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((kindCheck== (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("�ղ�(δѡ��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��ֻ
	CPoint c_SXY(803, 162), c_EXY(871, 230);
	SelectWhichReginalKing(c_SXY, c_EXY, kindCheck, sn, game);
	if (amount == 0) {
		//����ͥԺ
		returnYard(sn, game);
		return 1;
	}
	c_SXY.y += 115, c_EXY.y += 115;
	SelectWhichReginalKing(c_SXY, c_EXY, kindCheck, sn, game);
	if (amount == 1) {
		//����ͥԺ
		returnYard(sn, game);
		return 1;
	}
	c_SXY.y += 115, c_EXY.y += 115;
	SelectWhichReginalKing(c_SXY, c_EXY, kindCheck, sn, game);
	if (amount == 2) {
		//����ͥԺ
		returnYard(sn, game);
	}
	return 1;
}
//�Զ�������---����
int InDependentFunction::ClickMonsterToVictory(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	sn->UseDict(4);
	int closingflag = 0;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findManualSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�л�Ϊ�Զ�ģʽ...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 30, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("����ɹ�...\r\n"), game);
			break;
		}
		if (sn->FindPic(281, 68, 430, 218, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��սʧ��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//�Զ�����
int InDependentFunction::AutoPlot(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(4);
	//����ֲ�����
	long intX, intY;
	int findFlag = 0;
	Log(_T("��������--�Զ�����\r\n"), game);
	Log(_T("�������������ͥԺ�о�����ʾʱ����...\r\n"), game);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(446, 41, 856, 368, _T("..."), _T("CDC2C3-323D3C"), 0.9, &intX, &intY) != -1)//CDC2C3-323D3C
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�������...\r\n"), game);
			findFlag = 0;
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(561, 368, 784, 444, _T("����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindPic(70, 19, 103, 42, _T("��Ϣ.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (sn->FindStrFast(1, 47, 955, 502, _T("..."), _T("CDC2C3-323D3C"), 0.9, &intX, &intY) != -1)//CDC2C3-323D3C
			{
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("��ʼ�Ի�...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				findFlag = 0;
			}
		}
		if (sn->FindPic(70, 19, 103, 42, _T("��Ϣ.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (sn->FindStrFast(1, 47, 955, 502, _T("..."), _T("C0B2B4-212526"), 0.9, &intX, &intY) != -1)//CDC2C3-323D3C
			{
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("��ʼ�Ի�...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				findFlag = 0;
			}
		}
		if (sn->FindStrFast(1, 47, 955, 502, _T("?"), _T("BCA9AA-2D2F2F"), 0.8, &intX, &intY) != -1) {//C7B1AE-2E3336
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("��ʼ�Ի�...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindStrFast(1, 47, 955, 502, _T("?"), _T("C7B1AE-2E3336"), 0.8, &intX, &intY) != -1) {//C7B1AE-2E3336
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("��ʼ�Ի�...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		//���ֹ���
		if (sn->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (ClickMonsterToVictory(sn, game) == 0) {
				Log(_T("����սʧ��ֹͣ...\r\n"), game);
				break;
			}
			findFlag = 0;
		}
		if (sn->FindPic(0, 47, 955, 502, _T("�۾�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����þ�...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}//
		if (sn->FindPic(836, 9, 910, 83, _T("���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�����...\r\n"), game);
			if (DelayPlus(game, sn, 2000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindPic(811, 0, 958, 159, _T("�������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindPic(846, 2, 940, 37, _T("�ر�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�ر�...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		findFlag++;
		if (findFlag >= 10) {
			findFlag = 0;
			sn->MoveClick(813, 504);
			Log(_T("������...\r\n"), game);
		}
	}
	return 1;
}
//�Զ�����
int InDependentFunction::AutoPVP(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(0);
	//����ֲ�����
	long intX, intY;
	Log(_T("��������--�Զ�����\r\n"), game);
	Log(_T("��ʼǰ����붷������...\r\n"), game);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(843, 408, 955, 507, _T("ս.bmp|ս(����).bmp|ս(����2).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����ս��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x, posXY.y);
			Log(_T("�˳�...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 303, 587, 332, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("ȷ���˳�...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {//
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��սʧ��...\r\n"), game);
			if (sn->FindStrFast(447, 412, 469, 434, _T("��"), _T("8D1F1D-250305"), 0.85, &intX, &intY) != -1) {//8D1F1D-250305
				CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("�������ѵ�����...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(447, 412, 469, 434, _T("��"), _T("8D1F1D-250305"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("�������ѵ�����...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//�Զ�����(����)
int InDependentFunction::AutoPVPToMingShi(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//ʹ���ֿ�
	sn->UseDict(4);
	Log(_T("��������--�Զ�����\r\n"), game);
	Log(_T("��ʼǰ����붷������...\r\n"), game);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(843, 408, 955, 507, _T("ս.bmp|ս(����).bmp|ս(����2).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����ս��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 93, 68, 149, _T("�Զ�����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�Զ�����...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findManualSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�л�Ϊ�Զ�ģʽ...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			sn->UseDict(4);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(826, 493, 853, 522, _T("��"), _T("BCB2A2-43413E"), 0.9, &intX, &intY) != -1) {//ս������
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�ε�ͷ��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(787, 409, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��սʧ��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����ɹ�...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(428, 269, 472, 291, _T("��λ"), _T("D0CBBA-282826"), 0.85, &intX, &intY) != -1) {//��λ����
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��λ����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(322, 180, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//�»
int InDependentFunction::StartNewEvent(int round, int mode, int flag, int bossflag, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(6);
	//����ֲ�����
	long intX, intY;
	Log(_T("��ʼǰ�����") + activityName + _T("-") + activitySubName + _T("����(�����úö��飬�Լ���������)...\r\n"), game);
	if (mode)
		Log(_T("ģʽ��ʹ��������ս...\r\n"), game);
	else
		Log(_T("ģʽ��ʹ��") + TiLiName + _T("��ս...\r\n"),game);
	int count = 0;
	CString logmsg;
	int markflag = 0, markflag2 = 0;
	//�ж��Ƿ�5��buff   AEA99B-292C2A
	//if (mode == 1) {
	//	while (1) {
	//		//�Զ��ܾ�����
	//		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//		else {
	//			if (sn->FindPic(650, 476, 691, 524, _T("�5��(δѡ).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
	//				if (DelayPlus(game, sn, 100, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//				Log(_T("���5��...\r\n"), game);
	//				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
	//				sn->MoveClick(pos.x, intY);
	//				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//			}
	//			if (sn->FindPic(650, 476, 691, 524, _T("�5��(��ѡ).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
	//				Log(_T("��ѡ��5��...\r\n"), game);
	//				break;
	//			}
	//		}
	//	}
	//}
	while (count < round) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (!mode&&sn->FindPic(510, 17, 573, 39, _T("�0��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count = round;
			Log(TiLiName + _T("�þ�...\r\n"), game);
			break;
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//3C3336-3D3336
			if (sn->FindStrFast(838, 444, 915, 490, _T("���ս"), _T("3C3336-3D3336"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("�����ս...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				logmsg.Format(_T("%d"), count + 1);
				Log(_T("��") + logmsg + _T("��") + activitySubName + _T("��ʼ...\r\n"), game);
				//ʹ���ֿ�
				sn->UseDict(6);
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//���ʽ�� 107,142,215,408,   143,163,220,354,
			if (flag && !markflag && sn->FindPic(31, 143, 125, 373, _T("����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }//198,212,266,323,
				Log(_T("���ʽ��(��1)...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(78, 360, 1, 3);
				sn->MoveClick(78, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (flag && !markflag && sn->FindPic(31, 143, 125, 373, _T("����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("�ѱ���ҷ�ʽ��...\r\n"), game);
				markflag = 1;
			}
			////���boss
			//if (bossflag && !markflag2 && sn->FindPic(456, 30, 514, 89, _T("�boss���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			//	Log(_T("�ѱ��Boss...\r\n"), game);
			//	markflag2 = 1;
			//}
			//else if (bossflag && !markflag2 && sn->FindPic(456, 30, 514, 89, _T("�boss���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
			//	if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//	Log(_T("���Boss...\r\n"), game);
			//	CPoint pos = sn->RandomOffsetPos(480, 198, 1, 3);
			//	sn->MoveClick(480, pos.y);
			//	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			//}
			if (sn->FindPic(294, 84, 439, 204, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("ս��ʤ��...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(400, 490, 5, 10);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//
			if (sn->FindStrFast(412, 86, 540, 213, _T("�ý�"), _T("BDAA6A-373A39"), 0.8, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("��ý���...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("��ȡ����...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(838, 444, 915, 490, _T("���ս"), _T("3C3336-3D3336"), 0.85, &intX, &intY) != -1) {
				markflag = 0;
				//markflag2 = 0;
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= round) {
		Log(_T("��������ɡ�\r\n"), game);
	}
	return 1;
}

//��ѡ����
int InDependentFunction::DIYFunction(int ready, int clearing, int whitecard, int challenge, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	Log(_T("��������--��ѡ����\r\n"), game);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (ready) {
			if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("���׼��...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//ʤ������
		if (clearing) {
			if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("ս��������...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				Log(_T("����ɹ�...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(281, 68, 430, 218, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("��սʧ��...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//���Ʊ
		if (whitecard) {
			if (sn->FindPic(291, 454, 358, 505, _T("��ֽ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("ʮ����ȡ...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(526, 468, 638, 508, _T("�ٴ��ٻ�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("�ٴ��ٻ�...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(294, 3, 349, 36, _T("��Ʊ0.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				Log(_T("��Ʊ�þ�...\r\n"), game);
				break;
			}
		}
		if (challenge) {
			//����ս  
			if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|����֮����ս.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//���ƫ����������
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("ʶ����ս�������ս...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(824, 437, 902, 505, _T("��սҵԭ��.bmp|��ս����.bmp|��ˢ������ս.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("ʶ����ս�������ս...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(833, 412, 906, 458, _T("������ս.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("ʶ����ս�������ս...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}

//������
//1.����Ƿ��й���
int InDependentFunction::CheckSuperGhostKing(int count, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(6);
	//����ֲ�����
	long intX, intY;
	int countflag = 0;
	//���ƣ��ֵ
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((sn->FindPic(817, 413, 899, 488, _T("������ս��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)||(sn->FindStrFast(851, 477, 933, 505, _T("����Ѳ��"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1)) {
			if (sn->FindPic(865, 4, 916, 36, _T("δ��ƣ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("ƣ��ֵδ����������ս...\r\n"), game);
				break;
			}
			if (sn->FindPic(865, 4, 916, 36, _T("��ƣ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("ƣ��ֵ�������ȴ���(5���Ӽ��һ��)...\r\n"), game);
				int i = 100;
				while (i > 0) {
					if (DelayPlus(game, sn, 3000, 3010) == EXIT_THREAD) { return EXIT_THREAD; }
					i--;
				}
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��ⳬ���� �������: return 1, δ���֣��������
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(817, 413, 899, 488, _T("������ս��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (sn->FindPic(821, 488, 862, 526, _T("ƣ��С��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("���ֳ�����...\r\n"), game);
				if (countflag == 1) {
					count++;
					CString count_str;
					count_str.Format(_T("%d"), count);
					Log(_T("��ʼ������") + count_str + _T("ֻ������...\r\n"), game);
					countflag = 0;
				}
				break;
			}
		}
		if (sn->FindPic(84, 110, 144, 179, _T("�޹���.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			//����Ƿ���Ʊ
			if ((sn->FindPic(672, 5, 744, 36, _T("������0Ʊ.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&(sn->FindPic(667, 6, 748, 35, _T("������10Ʊ.bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1)) {
				Log(_T("û�з��ֳ������Ĳ���,���ڽ�������...\r\n"), game);
				return EXIT_THREAD;
			}
			if (sn->FindStrFast(851, 477, 933, 505, _T("����Ѳ��"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1) {
				sn->MoveClick(intX + 40, intY - 20);
				Log(_T("�������Ѳ��...\r\n"), game);
				if (DelayPlus(game, sn, 2500, 4500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return count;
}
//2.����Ǽ�
int InDependentFunction::CheckSuperGhostKingStar(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int star = -1;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//��⼸�ǳ����� return star   ssr--�Ǽ���ɫ D0712B-2F4528  sp C13DC6-3C3B37
		if (sn->FindColor(131, 165, 135, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 5;
			break;
		}
		else if (sn->FindColor(123, 165, 127, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 4;
			break;
		}
		else if (sn->FindColor(116, 165, 120, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 3;
			break;
		}
		else if (sn->FindColor(108, 164, 112, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 2;
			break;
		}
		else if (sn->FindColor(100, 163, 105, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 1;
			break;
		}
		else if (sn->FindColor(91, 163, 97, 170, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 0;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return star;
}
//  2-1 �Ƿ񲥱��������ǹ�����ֹͣ
int InDependentFunction::IsStopAndAlert(int star, int star_stop, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (star_stop != 0) {
		if (star_stop == 1) {
			//5,6 star
			if (star == 4) {
				Log(_T("�ѷ���5�ǳ�����...\r\n"), game);
				sn->Play(_T("5star.mp3")); 
				if (DelayPlus(game, sn, 5000, 6000) == EXIT_THREAD) { return EXIT_THREAD; }
				return EXIT_THREAD;
			}
			else if (star == 5) {
				Log(_T("�ѷ���6�ǳ�����...\r\n"), game);
				sn->Play(_T("6star.mp3")); 
				if (DelayPlus(game, sn, 5000, 6000) == EXIT_THREAD) { return EXIT_THREAD; }
				return EXIT_THREAD;
			}
		}
		else if (star_stop == 2) {
			//6 star
			if (star == 5) {
				Log(_T("�ѷ���6�ǳ�����...\r\n"), game);
				sn->Play(_T("6star.mp3")); 
				if (DelayPlus(game, sn, 5000, 6000) == EXIT_THREAD) { return EXIT_THREAD; }
				return EXIT_THREAD;
			}
		}
	}
	return 0;
}
//  2-2 �������ǹ���
int InDependentFunction::OpenHignStarSuperGhostKing(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(6);
	long intX, intY;
	Log(_T("׼����������...\r\n"), game);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(298, 466, 364, 511, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 413, 426, 453, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���ҵ�����...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(335, 413, 426, 453, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 303, 587, 332, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("ȷ�Ϲ���...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(817, 413, 899, 488, _T("������ս��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ѹ���...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//		2-2-1 �ȴ�����������
int InDependentFunction::WaitSuperGhostKingKilled(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(6);
	long intX, intY;
	Log(_T("�����ѹ������ȴ�������...\r\n"), game);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(851, 477, 933, 505, _T("����Ѳ��"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1) {
			Log(_T("�����ѱ�����...\r\n"), game);
			break;
		}
		if (sn->FindPic(84, 110, 144, 179, _T("�޹���.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("�����ѱ�����...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//3.���Ѫ��
int InDependentFunction::CheckSuperGhostKingBlood(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//���Ѫ�� return blood  ��Ѫ386
	long blood_count = 0;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((blood_count = sn->GetColorNum(75, 170, 155, 188, _T("EC4642-13422F"), 0.95)) > 0) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return blood_count;
}
//4.�����ս(include ǿ׷)
int InDependentFunction::ClickChallenge(int star, int blood, int strenghCheck, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(6);
	//����ֲ�����
	long intX, intY,bldsim;
	double bloodrate = (double)blood / (double)386;
	if (sn->FindPic(821, 488, 862, 526, _T("ƣ��С��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
		//ͨ��Ѫ�����Ǽ��ж��Ƿ���ǿ׷
		if (bloodrate >= 0.95) { bldsim = 100; }
		else bldsim = (int)(bloodrate * 100);
		CString ghost_state;
		ghost_state.Format(_T("%d��%d%%Ѫ������"), star + 1, bldsim);
		Log(_T("�ѷ���") + ghost_state + _T("\r\n"), game);
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (strenghCheck) {
			if (star > 3) {
				if (bloodrate >= 0.7) {
					if (sn->FindPic(675, 451, 703, 480, _T("��ͨ_ǿ������(��).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x + 10, pos.y + 10);
						Log(_T("���ǿ������...\r\n"), game);
						if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(675, 488, 706, 518, _T("��ͨ_ǿ������(��).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
						Log(_T("��ѡ��ǿ������...\r\n"), game);
						break;
					}
				}
			}
		}
		if (!strenghCheck||star<=3|| bloodrate < 0.7) {
			if (sn->FindPic(675, 488, 706, 518, _T("��ͨ_ǿ������(��).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x + 10, pos.y + 10);
				Log(_T("�����ͨ����...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(675, 451, 703, 480, _T("��ͨ_ǿ������(��).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("��ѡ����ͨ����...\r\n"), game);
				break;
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(817, 413, 899, 488, _T("������ս��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x + 18, pos.y + 23);
			Log(_T("���ս��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//7B6F62-585752
		if (sn->FindStrFast(86, 484, 115, 537, _T("��|��"), _T("7B6F62-585752"), 0.85, &intX, &intY) != -1) {
			Log(_T("����ս������...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//�����ս
	return 0;
}
//5.��������
//  5.1ѡ��&��
int InDependentFunction::selectgroup(int group, int team, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	switch (group)
	{
	case 0: {
		while (1) {
			//�Զ��ܾ����� 198
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(103, 189, 116, 212, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ���һ��...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(68, 198);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
		break;
	}
	case 1: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(101, 238, 118, 260, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ��ڶ���...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(71, 247);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 2: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(95, 283, 115, 305, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ�������...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 293);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 3: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(98, 334, 117, 355, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ�������...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 341);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 4: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(98, 384, 117, 401, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ�������...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 390);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 5: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(99, 431, 117, 445, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ�������...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 435);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 6: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(94, 479, 118, 492, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ�������...\r\n"), game);
				break;
			}
			if (sn->FindPic(94,479,118,492, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 483);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	default:
		break;
	}
	switch (team)
	{
	case 0: {
		Log(_T("��Ԥ�赫����Ԥ�裬δ֪����...\r\n"), game);
		break;
	}
	case 1: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 174, 151, 187, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ���һ��...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 192);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 2: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 265, 153, 277, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ��ڶ���...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 282);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 3: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 355, 153, 368, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ�������...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 372);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 4: {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 446, 153, 460, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("��ѡ����Ķ�...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 462);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	default:
		break;
	}
	return 0;
}
//  5.2 ���Ԥ��
int InDependentFunction::ClickPreset(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	sn->UseDict(6);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(86, 484, 115, 537, _T("��|��"), _T("7B6F62-585752"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(45, 510, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("���Ԥ��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("����Ԥ�����...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//  5.3 ��ʼ������
int InDependentFunction::ChangeStaff(int star, int blood, int group[], int team[], int bloodsel[], snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int goattack = 0, not_presetflag = 0;
	//ͨ��Ѫ�����Ǽ��ж�����
	//F5CD86-040D1C
	for (int i = 0; i < 4; i++) {
		if (bloodsel[i] == 0) { bloodsel[i] = 50; }
		else if (bloodsel[i] == 1) { bloodsel[i] = 60; }
		else if (bloodsel[i] == 2) { bloodsel[i] = 70; }
	}
	double bloodrate = (double)blood / 386.0;
	int bloodrateh = (int)(bloodrate * 100);
	if (star < 3) {
		if (bloodrateh >= bloodsel[0]) {
			if (team[0] == 0) {
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[0], team[0], sn, game);
			}
		}
		else {
			if (team[1] == 0) {
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[1], team[1], sn, game);
			}
		}
	}
	else if (star == 3) {
		if (bloodrateh >= bloodsel[1]) {
			if (team[2] == 0) {
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[2], team[2], sn, game);
			}
		}
		else {
			if (team[3] == 0) {
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[3], team[3], sn, game);
			}
		}
	}
	else if (star == 4) {
		if (bloodrateh >= bloodsel[2]) {
			if (team[4] == 0) {
				not_presetflag = 1;
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[4], team[4], sn, game);
			}
		}
		else {
			if (team[5] == 0) {
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[5], team[5], sn, game);
			}
		}
	}
	else if (star == 5) {
		if (bloodrateh >= bloodsel[3]) {
			if (team[6] == 0) {
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[6], team[6], sn, game);
			}
		}
		else {
			if (team[7] == 0) {
				Log(_T("��ѡ��Ԥ��...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[7], team[7], sn, game);
			}
		}
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			goattack = 1;
			Log(_T("�����ս...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((not_presetflag == 1) && (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("����׼������...\r\n"), game);
			not_presetflag = 0;
			break;
		}
		if ((goattack == 1) && (sn->FindPic(267, 480, 362, 514, _T("��������ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
			Log(_T("��ս�ɹ�...\r\n"), game);
			goattack = 0;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��ս��Ӧ����
	return 0;
}
//6.׼��-����
int InDependentFunction::EnterSuperGhostKingSection(int flag_own, int flag_boss, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(6);
	//����ֲ�����
	long intX, intY;
	int markflag = 0, markflag2 = 0;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���ʽ��
		if (flag_own && !markflag && sn->FindPic(154, 197, 252, 274, _T("����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("���ʽ��(��1)...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(205, 312, 1, 3);
			sn->MoveClick(205, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (flag_own && !markflag && sn->FindPic(154, 197, 252, 274, _T("����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�ѱ���ҷ�ʽ��...\r\n"), game);
			markflag = 1;
		}//���boss
		if (flag_boss && !markflag2 && sn->FindPic(421, 60, 525, 161, _T("�boss���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�ѱ��Boss...\r\n"), game);
			markflag2 = 1;
		}
		else if (flag_boss && !markflag2 && sn->FindPic(421, 60, 525, 161, _T("�boss���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("���Boss...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(470, 210, 1, 10);
			sn->MoveClick(470, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(284, 57, 422, 174, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��սʧ��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(295, 45, 430, 160, _T("������ʤ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��ս�ɹ�...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 4000, 4500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(817, 413, 899, 488, _T("������ս��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(851, 477, 933, 505, _T("����Ѳ��"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//7.��ʼ������
int InDependentFunction::StartSuperGhostKing(int round, int strenghCheck, int group[], int team[], int bloodsel[], int flag_own, int flag_boss, int star_stop, int star_public, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	int count = 0, star, blood;
	Log(_T("��ʼǰ�����ú�Ԥ����鲢����������Ѱ(������)����...\r\n"), game);
	while (count < round) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���ֹ���
		if((count = CheckSuperGhostKing(count, sn, game)) == EXIT_THREAD){ return EXIT_THREAD; }
		//ʶ���Ǽ�
		if ((star = CheckSuperGhostKingStar(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Ƿ�ֹͣ
		if(IsStopAndAlert(star, star_stop, sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
		//�Ƿ񹫿�
		if (star_public && star >= 4) {
			//����
			if (OpenHignStarSuperGhostKing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//�ȹ��������ܻ�����
			if (WaitSuperGhostKingKilled(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else {
			//ʶ��Ѫ��
			if ((blood = CheckSuperGhostKingBlood(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//�����ս
			if (ClickChallenge(star, blood, strenghCheck, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//��������
			if (ChangeStaff(star, blood, group, team, bloodsel, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//׼��->����
			if (EnterSuperGhostKingSection(flag_own, flag_boss, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//����
int InDependentFunction::StartMiWen(snow *sn, Game *game, int round) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int count = 0;
	CString logmsg;
	Log(_T("��ʼǰ������Ӧ��ʽ�����(��ȷ�����ú�Ĭ������)...\r\n"), game);
	Log(_T("Ĭ��10��...\r\n"), game);
	while (count < 10) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//����ս  
			if (sn->FindPic(833, 412, 906, 458, _T("������ս.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("ʶ����ս�������ս...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				logmsg.Format(_T("%d"), count + 1);
				Log(_T("��") + logmsg + _T("����ս��ʼ...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//׼��
			if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("���׼��...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//ʤ������
			if (sn->FindPic(282, 25, 430, 140, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("ս��������...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("��ȡ����...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//����ս  
			if (sn->FindPic(833, 412, 906, 458, _T("������ս.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= 10) {
		Log(_T("������ս��������ɡ�\r\n"), game);
	}
	return 1;
}
//��Ⱦ����
int InDependentFunction::StartLingRan(snow *sn, Game *game, int round) {
	if (sn == NULL)
	{
		return 0;
	}
	//�ֿ�
	sn->UseDict(6);
	//����ֲ�����
	long intX, intY;
	int count = 0;
	CString logmsg;
	Log(_T("��ʼǰ�������ս����(����������)...\r\n"), game);
	Log(_T("Ĭ��50��...\r\n"), game);
	while (count < round) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//����ս  2E2D2E-2E2D2E
			if (sn->FindStrFast(849, 438, 931, 484, _T("��Ⱦ��ս"), _T("2E2D2E-2E2D2E"), 0.85, &intX, &intY) != -1) {
				Log(_T("ʶ����ս�������ս...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				logmsg.Format(_T("%d"), count + 1);
				Log(_T("��") + logmsg + _T("����Ⱦ������ʼ...\r\n"), game);
				//ʹ���ֿ�
				sn->UseDict(6);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//ʤ������
			if (sn->FindPic(280, 79, 447, 216, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("ս��������...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}//BDAA6A-373A39
			if (sn->FindStrFast(414, 166, 541, 209, _T("�ý�"), _T("BDAA6A-373A39"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("��ȡ����...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//����ս  
			if (sn->FindStrFast(849, 438, 931, 484, _T("��Ⱦ��ս"), _T("2E2D2E-2E2D2E"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= 50) {
		Log(_T("��Ⱦ������������ɡ�\r\n"), game);
	}
	return 1;
}
/*
					  .::::.
					 .::::::::.
					:::::::::::
				 ..:::::::::::'
			  '::::::::::::'
				.::::::::::
		   '::::::::::::::..
				..::::::::::::.
			  ``::::::::::::::::
			   ::::``:::::::::'        .:::.
			  ::::'   ':::::'       .::::::::.
			.::::'      ::::     .:::::::'::::.
		   .:::'       :::::  .:::::::::' ':::::.
		  .::'        :::::.:::::::::'      ':::::.
		 .::'         ::::::::::::::'         ``::::.
	 ...:::           ::::::::::::'              ``::.
	```` ':.          ':::::::::'                  ::::..
					   '.:::::'                    ':'````..
*/