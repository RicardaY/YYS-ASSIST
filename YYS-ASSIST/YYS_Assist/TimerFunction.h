#pragma once
#include "yys_function.h"
class TimerFunction : public yys_function
{
public:
	//��ʱ����
	int ClockAdopt(long hd, int adopt, int cardType, int star, int prior, snow *sn, Game *game);
	//������翨ѡ��
	int CardTypeSelect(int cardType, int star, snow *sn, Game *game);
	//����ͥԺ
	int CardReturnYard(snow *sn, Game *game);
	//��ʱ����ʼ
	int StartClockTimer(int cardType, int star, int prior, long delayTimeLoop, snow *sn, Game *game);
};

