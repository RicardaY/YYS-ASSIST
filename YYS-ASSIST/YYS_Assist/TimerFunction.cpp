#include "pch.h"
#include "TimerFunction.h"
#define EXIT_THREAD -10
//��ʱ����
int TimerFunction::ClockAdopt(long hd, int adopt, int cardType, int star, int prior, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (!adopt) {
		return 1;
	}
	//����ֲ�����
	long intX, intY;
	int findout = 0;
	//ʹ���ֿ�
	sn->UseDict(0);

	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(361, 482, 469, 522, _T("��|��|�"), _T("C0B7AD-242828"), 0.8, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 13, intY);
			Log(_T("�ҵ������...\r\n"), game);
			Log(_T("����ס�����л�Ĭ�Ͻ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(798, 495, 850, 535, _T("���"), _T("D0CCB8-282728"), 0.85, &intX, &intY) != -1) {//D0CCB8-282728
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY);
			Log(_T("������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(403, 165, 565, 302, _T("ʽ"), _T("060402-060402"), 0.75, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 2, intY + 10);
			Log(_T("���ʽ������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(16, 460, 76, 519, _T("ȫ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ɹ��������ɽ���...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(792, 52, 835, 118, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(874, 57, 903, 85, _T("�ҵļ���.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 20, intY + 30);
				Log(_T("�����������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else {
				Log(_T("����ʱ��δ��������ͥԺ...\r\n"), game);
				CardReturnYard(sn, game);
				return 0;
			}
		}
		if (sn->FindStrFast(167, 71, 236, 115, _T("����ѡ��"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(167, 71, 236, 115, _T("����δѡ��"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (prior == 0) {
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(167, 71, 236, 115, _T("����δѡ��"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("�ȼ����ѽ���...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(167, 71, 236, 115, _T("����ѡ��"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("ͬ�����ѽ���û�к��ʵĽ�翨...\r\n"), game);
				break;
			}
			else {
				findout = 1;
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (!findout) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(254, 73, 335, 116, _T("����δѡ��"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("���������ѽ���...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(254, 73, 335, 116, _T("����ѡ��"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (!findout) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("�������ѽ���û�к��ʵĽ�翨...\r\n"), game);
				Log(_T("��զ��ô�������翨��û�У�\r\n"), game);
				//����ͥԺ
				CardReturnYard(sn, game);
				return 0;
			}
			else {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (prior == 1) {
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(254, 73, 335, 116, _T("����δѡ��"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("���ȿ�������...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(254, 73, 335, 116, _T("����ѡ��"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("�������ѽ���û�к��ʵĽ�翨...\r\n"), game);
				break;
			}
			else {
				findout = 1;
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (!findout) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(167, 71, 236, 115, _T("����δѡ��"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("���ͬ�����ѽ���...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(167, 71, 236, 115, _T("����ѡ��"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (!findout) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("ͬ�����ѽ���û�к��ʵĽ�翨...\r\n"), game);
				Log(_T("��զ��ô�������翨��û�У�\r\n"), game);
				//����ͥԺ
				CardReturnYard(sn, game);
				return 0;
			}
			else {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(597, 406, 722, 441, _T("������"), _T("45341F-45341F"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			Log(_T("������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(740, 41, 915, 85, _T("��"), _T("3C3A34-3C3A35"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(159, 439);
			Log(_T("ѡ���һ������(�ز�)��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(522, 389, 586, 424, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY + 10);
			Log(_T("ȷ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	CardReturnYard(sn, game);
	return 1;
}
//������翨ѡ��
int TimerFunction::CardTypeSelect(int cardType, int star, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//ʹ���ֿ�
	sn->UseDict(0);
	CString picName[3];
	CString overFourStarTG[3] = { _T("6��̫��(1).bmp|6��̫��(2).bmp|6��̫��(3).bmp|6��̫��(4).bmp"),_T("5��̫��(1).bmp|5��̫��(2).bmp|5��̫��(3).bmp|5��̫��(4).bmp") ,_T("4��̫��(1).bmp|4��̫��(2).bmp|4��̫��(3).bmp|4��̫��(4).bmp") };
	CString overFourStarDY[3] = { _T("6�Ƕ���(1).bmp|6�Ƕ���(2).bmp|6�Ƕ���(3).bmp|6�Ƕ���(4).bmp"),_T("5�Ƕ���(1).bmp|5�Ƕ���(2).bmp|5�Ƕ���(3).bmp|5�Ƕ���(4).bmp"),_T("4�Ƕ���(1).bmp|4�Ƕ���(2).bmp|4�Ƕ���(3).bmp|4�Ƕ���(4).bmp") };
	switch (star)
	{
	case 0: {
		picName[0] = overFourStarTG[0] + _T("|") + overFourStarDY[0] + _T("|") +overFourStarTG[1]+_T("|")+ overFourStarDY[1] + _T("|") + overFourStarTG[2] + _T("|") + overFourStarDY[2];
		picName[1] = overFourStarTG[0] + _T("|") + overFourStarTG[1] + _T("|") + overFourStarTG[2];
		picName[2] = overFourStarDY[0] + _T("|") + overFourStarDY[1] + _T("|") + overFourStarDY[2]; break; }
	case 1: {
		picName[0] = overFourStarTG[0] + _T("|") +  overFourStarDY[0] + _T("|") +overFourStarTG[1] + _T("|") + overFourStarDY[1];
		picName[1] = overFourStarTG[0] + _T("|") + overFourStarTG[1];
		picName[2] = overFourStarDY[0] + _T("|") + overFourStarDY[1]; break; }
	case 2: {
		picName[0] = overFourStarTG[0] + _T("|") + overFourStarDY[0], picName[1] = overFourStarTG[0], picName[2] = overFourStarDY[0]; break; }
	default:
		break;
	}
	int cardResult = sn->FindPic(387, 128, 466, 445, picName[cardType], _T("202020"), 0.7, 0, &intX, &intY);
	if (cardResult != -1) {
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		sn->MoveClick(intX, intY);
		switch (star)
		{
		case 0: {
			switch (cardType)
			{
			case(0): {
				if(cardResult<4){ Log(_T("��������̫�ģ���Ʒ���ﰡ...\r\n"), game); }
				else if((cardResult >= 4)&& (cardResult < 8)) { Log(_T("�������Ƕ��㣬��Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("��������̫�ģ���Ʒ��������...\r\n"), game); }
				else if ((cardResult >= 12) && (cardResult < 16)) { Log(_T("�������Ƕ��㣬��Ʒ��������...\r\n"), game); }
				else if ((cardResult >= 16) && (cardResult < 20)) { Log(_T("��������̫�ģ���Ʒ��ǿ�ϸ�...\r\n"), game); }
				else if ((cardResult >= 20) && (cardResult < 24)) { Log(_T("�������Ƕ��㣬��Ʒ��ǿ�ϸ�...\r\n"), game); }
				break; }
			case(1): {
				if (cardResult < 4) { Log(_T("��������̫�ģ���Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("��������̫�ģ���Ʒ��������...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("��������̫�ģ���Ʒ��ǿ�ϸ�...\r\n"), game); }
				break; }
			case(2): {
				if (cardResult < 4) { Log(_T("�������Ƕ��㣬��Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("�������Ƕ��㣬��Ʒ��������...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("�������Ƕ��㣬��Ʒ��ǿ�ϸ�...\r\n"), game); }
				break; }
			default:
				break;
			}
			break;
		}
		case 1: {
			switch (cardType)
			{
			case(0): {
				if (cardResult < 4) { Log(_T("��������̫�ģ���Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("�������Ƕ��㣬��Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("��������̫�ģ���Ʒ��������...\r\n"), game); }
				else if ((cardResult >= 12) && (cardResult < 16)) { Log(_T("�������Ƕ��㣬��Ʒ��������...\r\n"), game); }
				break; }
			case(1): {
				if (cardResult < 4) { Log(_T("��������̫�ģ���Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("��������̫�ģ���Ʒ��������...\r\n"), game); }
				break; }
			case(2): {
				if (cardResult < 4) { Log(_T("�������Ƕ��㣬��Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("�������Ƕ��㣬��Ʒ��������...\r\n"), game); }
				break; }
			default:
				break;
			}
			break;
		}
		case 2: {
			switch (cardType)
			{
			case(0): {
				if (cardResult < 4) { Log(_T("��������̫�ģ���Ʒ���ﰡ...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("�������Ƕ��㣬��Ʒ���ﰡ...\r\n"), game); }
				break; }
			case(1): {
				Log(_T("��������̫�ģ���Ʒ���ﰡ...\r\n"), game);
				break; }
			case(2): {
				Log(_T("�������Ƕ��㣬��Ʒ���ﰡ...\r\n"), game);
				break; }
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		return 1;
	}
	return 0;
}
//����ͥԺ
int TimerFunction::CardReturnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//ʹ���ֿ�
	sn->UseDict(0);
	while (1) {//����ͥԺ
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(597, 406, 722, 441, _T("������"), _T("45341F-45341F"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(44, 49);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(2, 5, 63, 61, _T("����1.bmp|����5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(2, 5, 63, 61, _T("����6.bmp|����7.bmp|����8.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�ɹ�����ͥԺ��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ʱ����ʼ
int TimerFunction::StartClockTimer(int cardType, int star, int prior, long delayTimeLoop, snow *sn, Game *game) {
	//if (dm == NULL)
	//{
	//	return 0;
	//}
	//CString timeLoop;
	//timeLoop.Format(_T("%d"), delayTimeLoop);
	////delayTimeLoop*60*60/5 = delayTimeLoop*60*12
	//print_log(_T("��ʱ��ʼ("+ timeLoop +"h�����һ�Σ�֮��6h����һ��)...\r\n"), gameclass);

	//int timeInterval = delayTimeLoop * 60 * 12;
	//while (timeInterval > 0) {
	//	if (random_delay(index, gameclass, dm, 5000, 5002) == EXIT_THREAD) { return EXIT_THREAD; }
	//	timeInterval--;
	//}
	//if (ClockAdopt(hd, dm, cardType, star, prior, gameclass, index) != EXIT_THREAD) {
	//	print_log(_T("�����ɹ����ȴ��´μ���...\r\n"), gameclass);
	//}
	//print_log(_T("Ԥ��6h��ʼ���...\r\n"), gameclass);
	//while (1) {
	//	int timeInterval = 6 * 60 * 12;
	//	while (timeInterval > 0) {
	//		if (random_delay(index, gameclass, dm, 5000, 5002) == EXIT_THREAD) { return EXIT_THREAD; }
	//		timeInterval--;
	//	}
	//	if (ClockAdopt(hd, dm, cardType, star, prior, gameclass, index) != EXIT_THREAD) {
	//		print_log(_T("�����ɹ����ȴ��´μ���...\r\n"), gameclass);
	//	}
	//	if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//}
	return 1;
}