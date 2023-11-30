#include "pch.h"
#include "BeginRest.h"
#include "TimerFunction.h"
#define EXIT_THREAD -10

int BeginRest::StartRest(long hd, int minite, int adopt, int cardType, int start, int prior, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long sec = minite * 12; //60��5=12
	Log(_T("׼����Ϣ...\r\n"),game);
	if (adopt) {
		TimerFunction *timerfunction = new TimerFunction;
		Log(_T("��Ϣǰ��ʼ������...\r\n"), game);
		timerfunction->ClockAdopt(hd, adopt, cardType, start, prior, sn, game);
		Log(_T("�����ɣ���ʼ��Ϣ...\r\n"), game);
		delete timerfunction;
		timerfunction = nullptr;
	}
	Log(_T("��Ϣ��...\r\n"), game);
	while (sec > 0) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 5000, 5001) == EXIT_THREAD) { return EXIT_THREAD; }
		sec--;
	}
	Log(_T("��Ϣ����.\r\n"), game);
	//�ָ�ͥԺ(�Զ���ͥ)
	long intX, intY;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(17, 19, 50, 52, _T("��ͥ����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("���ڴ��Զ���ͥ�ָ�...\r\n"), game);
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsInYard(sn, game)) {
			Log(_T("ͥԺ�ѻָ�...\r\n"), game);
			break;
		}
	}
	return 1;
}