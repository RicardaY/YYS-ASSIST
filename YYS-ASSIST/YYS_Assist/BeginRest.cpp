#include "pch.h"
#include "BeginRest.h"
#include "TimerFunction.h"
#define EXIT_THREAD -10

int BeginRest::StartRest(long hd, int minite, int adopt, int cardType, int start, int prior, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long sec = minite * 12; //60÷5=12
	Log(_T("准备休息...\r\n"),game);
	if (adopt) {
		TimerFunction *timerfunction = new TimerFunction;
		Log(_T("休息前开始检测寄养...\r\n"), game);
		timerfunction->ClockAdopt(hd, adopt, cardType, start, prior, sn, game);
		Log(_T("检测完成，开始休息...\r\n"), game);
		delete timerfunction;
		timerfunction = nullptr;
	}
	Log(_T("休息中...\r\n"), game);
	while (sec > 0) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 5000, 5001) == EXIT_THREAD) { return EXIT_THREAD; }
		sec--;
	}
	Log(_T("休息结束.\r\n"), game);
	//恢复庭院(自动闲庭)
	long intX, intY;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(17, 19, 50, 52, _T("闲庭返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("正在从自动闲庭恢复...\r\n"), game);
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsInYard(sn, game)) {
			Log(_T("庭院已恢复...\r\n"), game);
			break;
		}
	}
	return 1;
}