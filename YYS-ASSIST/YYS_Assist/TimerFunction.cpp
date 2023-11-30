#include "pch.h"
#include "TimerFunction.h"
#define EXIT_THREAD -10
//定时寄养
int TimerFunction::ClockAdopt(long hd, int adopt, int cardType, int star, int prior, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (!adopt) {
		return 1;
	}
	//定义局部变量
	long intX, intY;
	int findout = 0;
	//使用字库
	sn->UseDict(0);

	//判断是否在庭院
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	//判断庭院是否展开,若未展开使之展开
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(361, 482, 469, 522, _T("阴|阳|寮"), _T("C0B7AD-242828"), 0.8, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 13, intY);
			Log(_T("找到阴阳寮...\r\n"), game);
			Log(_T("若卡住，请切换默认结界...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(798, 495, 850, 535, _T("结界"), _T("D0CCB8-282728"), 0.85, &intX, &intY) != -1) {//D0CCB8-282728
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY);
			Log(_T("进入结界...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(403, 165, 565, 302, _T("式"), _T("060402-060402"), 0.75, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 2, intY + 10);
			Log(_T("点击式神育成...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(16, 460, 76, 519, _T("全部.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("成功进入育成界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(792, 52, 835, 118, _T("寄养.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(874, 57, 903, 85, _T("我的寄养.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 20, intY + 30);
				Log(_T("进入寄养界面...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else {
				Log(_T("寄养时间未到，返回庭院...\r\n"), game);
				CardReturnYard(sn, game);
				return 0;
			}
		}
		if (sn->FindStrFast(167, 71, 236, 115, _T("好友选中"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(167, 71, 236, 115, _T("好友未选中"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (prior == 0) {
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(167, 71, 236, 115, _T("好友未选中"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("先检测好友界面...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(167, 71, 236, 115, _T("好友选中"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("同区好友界面没有合适的结界卡...\r\n"), game);
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
			if (sn->FindStrFast(254, 73, 335, 116, _T("跨区未选中"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("检测跨区好友界面...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(254, 73, 335, 116, _T("跨区选中"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (!findout) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("跨区好友界面没有合适的结界卡...\r\n"), game);
				Log(_T("你咋这么穷，连个结界卡都没有！\r\n"), game);
				//返回庭院
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
			if (sn->FindStrFast(254, 73, 335, 116, _T("跨区未选中"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("优先跨区好友...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(254, 73, 335, 116, _T("跨区选中"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("跨区好友界面没有合适的结界卡...\r\n"), game);
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
			if (sn->FindStrFast(167, 71, 236, 115, _T("好友未选中"), _T("412C20-412C21"), 0.9, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 5, intY + 5);
				Log(_T("检测同区好友界面...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(167, 71, 236, 115, _T("好友选中"), _T("3B3329-3C342A"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (!findout) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (!CardTypeSelect(cardType, star, sn, game)) {
				Log(_T("同区好友界面没有合适的结界卡...\r\n"), game);
				Log(_T("你咋这么穷，连个结界卡都没有！\r\n"), game);
				//返回庭院
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
		if (sn->FindStrFast(597, 406, 722, 441, _T("进入结界"), _T("45341F-45341F"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			Log(_T("进入结界...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(740, 41, 915, 85, _T("友"), _T("3C3A34-3C3A35"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(159, 439);
			Log(_T("选择第一个狗粮(素材)当作寄养...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(522, 389, 586, 424, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY + 10);
			Log(_T("确定...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	CardReturnYard(sn, game);
	return 1;
}
//寄养结界卡选择
int TimerFunction::CardTypeSelect(int cardType, int star, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//使用字库
	sn->UseDict(0);
	CString picName[3];
	CString overFourStarTG[3] = { _T("6星太鼓(1).bmp|6星太鼓(2).bmp|6星太鼓(3).bmp|6星太鼓(4).bmp"),_T("5星太鼓(1).bmp|5星太鼓(2).bmp|5星太鼓(3).bmp|5星太鼓(4).bmp") ,_T("4星太鼓(1).bmp|4星太鼓(2).bmp|4星太鼓(3).bmp|4星太鼓(4).bmp") };
	CString overFourStarDY[3] = { _T("6星斗鱼(1).bmp|6星斗鱼(2).bmp|6星斗鱼(3).bmp|6星斗鱼(4).bmp"),_T("5星斗鱼(1).bmp|5星斗鱼(2).bmp|5星斗鱼(3).bmp|5星斗鱼(4).bmp"),_T("4星斗鱼(1).bmp|4星斗鱼(2).bmp|4星斗鱼(3).bmp|4星斗鱼(4).bmp") };
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
				if(cardResult<4){ Log(_T("发现六星太鼓，人品爆棚啊...\r\n"), game); }
				else if((cardResult >= 4)&& (cardResult < 8)) { Log(_T("发现六星斗鱼，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("发现五星太鼓，人品还不错嘛...\r\n"), game); }
				else if ((cardResult >= 12) && (cardResult < 16)) { Log(_T("发现五星斗鱼，人品还不错嘛...\r\n"), game); }
				else if ((cardResult >= 16) && (cardResult < 20)) { Log(_T("发现四星太鼓，人品勉强合格啊...\r\n"), game); }
				else if ((cardResult >= 20) && (cardResult < 24)) { Log(_T("发现四星斗鱼，人品勉强合格啊...\r\n"), game); }
				break; }
			case(1): {
				if (cardResult < 4) { Log(_T("发现六星太鼓，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("发现五星太鼓，人品还不错嘛...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("发现四星太鼓，人品勉强合格啊...\r\n"), game); }
				break; }
			case(2): {
				if (cardResult < 4) { Log(_T("发现六星斗鱼，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("发现五星斗鱼，人品还不错嘛...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("发现四星斗鱼，人品勉强合格啊...\r\n"), game); }
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
				if (cardResult < 4) { Log(_T("发现六星太鼓，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("发现六星斗鱼，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 8) && (cardResult < 12)) { Log(_T("发现五星太鼓，人品还不错嘛...\r\n"), game); }
				else if ((cardResult >= 12) && (cardResult < 16)) { Log(_T("发现五星斗鱼，人品还不错嘛...\r\n"), game); }
				break; }
			case(1): {
				if (cardResult < 4) { Log(_T("发现六星太鼓，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("发现五星太鼓，人品还不错嘛...\r\n"), game); }
				break; }
			case(2): {
				if (cardResult < 4) { Log(_T("发现六星斗鱼，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("发现五星斗鱼，人品还不错嘛...\r\n"), game); }
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
				if (cardResult < 4) { Log(_T("发现六星太鼓，人品爆棚啊...\r\n"), game); }
				else if ((cardResult >= 4) && (cardResult < 8)) { Log(_T("发现六星斗鱼，人品爆棚啊...\r\n"), game); }
				break; }
			case(1): {
				Log(_T("发现六星太鼓，人品爆棚啊...\r\n"), game);
				break; }
			case(2): {
				Log(_T("发现六星斗鱼，人品爆棚啊...\r\n"), game);
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
//返回庭院
int TimerFunction::CardReturnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//使用字库
	sn->UseDict(0);
	while (1) {//返回庭院
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(597, 406, 722, 441, _T("进入结界"), _T("45341F-45341F"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(44, 49);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(2, 5, 63, 61, _T("返回1.bmp|返回5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(2, 5, 63, 61, _T("返回6.bmp|返回7.bmp|返回8.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("成功返回庭院！\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//定时任务开始
int TimerFunction::StartClockTimer(int cardType, int star, int prior, long delayTimeLoop, snow *sn, Game *game) {
	//if (dm == NULL)
	//{
	//	return 0;
	//}
	//CString timeLoop;
	//timeLoop.Format(_T("%d"), delayTimeLoop);
	////delayTimeLoop*60*60/5 = delayTimeLoop*60*12
	//print_log(_T("定时开始("+ timeLoop +"h后寄养一次，之后6h寄养一次)...\r\n"), gameclass);

	//int timeInterval = delayTimeLoop * 60 * 12;
	//while (timeInterval > 0) {
	//	if (random_delay(index, gameclass, dm, 5000, 5002) == EXIT_THREAD) { return EXIT_THREAD; }
	//	timeInterval--;
	//}
	//if (ClockAdopt(hd, dm, cardType, star, prior, gameclass, index) != EXIT_THREAD) {
	//	print_log(_T("寄养成功，等待下次寄养...\r\n"), gameclass);
	//}
	//print_log(_T("预计6h后开始检测...\r\n"), gameclass);
	//while (1) {
	//	int timeInterval = 6 * 60 * 12;
	//	while (timeInterval > 0) {
	//		if (random_delay(index, gameclass, dm, 5000, 5002) == EXIT_THREAD) { return EXIT_THREAD; }
	//		timeInterval--;
	//	}
	//	if (ClockAdopt(hd, dm, cardType, star, prior, gameclass, index) != EXIT_THREAD) {
	//		print_log(_T("寄养成功，等待下次寄养...\r\n"), gameclass);
	//	}
	//	if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//}
	return 1;
}