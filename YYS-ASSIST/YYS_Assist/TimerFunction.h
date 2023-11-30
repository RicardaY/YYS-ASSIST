#pragma once
#include "yys_function.h"
class TimerFunction : public yys_function
{
public:
	//定时寄养
	int ClockAdopt(long hd, int adopt, int cardType, int star, int prior, snow *sn, Game *game);
	//寄养结界卡选择
	int CardTypeSelect(int cardType, int star, snow *sn, Game *game);
	//返回庭院
	int CardReturnYard(snow *sn, Game *game);
	//定时任务开始
	int StartClockTimer(int cardType, int star, int prior, long delayTimeLoop, snow *sn, Game *game);
};

