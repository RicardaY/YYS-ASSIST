#pragma once
#include "pch.h"
#include "BeginYuLing.h"
#include "globalvar.h"
#define EXIT_THREAD -10

//选层
int BeginYuLing::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("壹层|贰层|叁层");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start 选择层
	Log(_T("选择御灵层数...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("壹层"), color_format, sim, dictId, sn, game))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("贰层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("叁层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//抽象出选择哪只御灵方法，方便调用
int BeginYuLing::WhichToSelect(CPoint startXY, CPoint endXY, CString source_pic[2], snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	while (1)
	{	
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//开启了
		if (sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[0], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}//未开启
		if (sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[1], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			return 0;
		}
		if (sn->FindPic(824, 437, 902, 505, _T("挑战御灵.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//选打哪个
int BeginYuLing::ChooseMonster(int monster_kind, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int i = 15;
	//定义一些变量
	CPoint startXY, endXY;
	CString source_pic[2];
	switch (monster_kind)
	{
	//神龙
	case 0: {
		startXY.x = 95, startXY.y = 427;
		endXY.x = 140, endXY.y = 484;
		source_pic[0] = _T("暗神龙.bmp"), source_pic[1] = _T("暗神龙(未开启).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("选择暗神龙...\r\n"), game);
			break;
		}else if(resultToSelect == 0){ return 0; }
		else if(resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//白藏主
	case 1: {
		startXY.x = 313, startXY.y = 429;
		endXY.x = 372, endXY.y = 482;
		source_pic[0] = _T("暗白藏主.bmp"), source_pic[1] = _T("暗白藏主(未开启).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("选择暗白藏主...\r\n"), game);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//黑豹 
	case 2: {
		startXY.x = 526, startXY.y = 432;
		endXY.x = 587, endXY.y = 489;
		source_pic[0] = _T("暗黑豹.bmp"), source_pic[1] = _T("暗黑豹(未开启).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("选择暗黑豹...\r\n"), game);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//孔雀  747,430,802,485,
	case 3: {
		startXY.x = 747, startXY.y = 430;
		endXY.x = 802, endXY.y = 485;
		source_pic[0] = _T("暗孔雀.bmp"), source_pic[1] = _T("暗孔雀(未开启).bmp");
		int resultToSelect = WhichToSelect(startXY, endXY, source_pic, sn, game);
		if (resultToSelect == 1)
		{
			Log(_T("选择暗孔雀...\r\n"), game);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}
	default:
		break;
	}
	return 1;
}
//寻副本
int BeginYuLing::FindYuLing(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(1);
	//定义局部变量
	long intX, intY;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点击御灵  253,514,307,538,
		if (sn->FindStrFast(253, 512, 351, 538, _T("御灵"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("点击御灵...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(101, 7, 167, 50, _T("御灵之境.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("成功进入界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//锁定阵容
int BeginYuLing::lockTeam(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(411, 415, 452, 454, _T("御灵解锁阵容.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 13, intY + 13);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(411, 415, 452, 454, _T("御灵阵容锁定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//进入副本
int BeginYuLing::EnterYuLing(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//字库
	sn->UseDict(0);
	//定义局部变量
	long intX, intY;
	int closingflag = 0;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(824, 437, 902, 505, _T("挑战御灵.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("点击挑战...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (readyFlag && (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("点击准备...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("结算成功\r\n"), game);
			break;
		}
		if (sn->FindPic(271, 40, 423, 216, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("挑战失败\r\n"), game);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//开始
int BeginYuLing::StartYuLing(long hd, int round, int monster_kind, int layer, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//初始化准备标志
	readyFlag = TRUE;
	//判断是否在庭院
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	//寻御灵
	if(FindYuLing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选打哪个
	if (!ChooseMonster(monster_kind, sn, game)) {
		Log(_T("此御灵今日可能未开启！\r\n"), game);
		Log(_T("正在返回庭院...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	//选层点击
	CPoint startXY, endXY;
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("未找到目标!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//锁定阵容
	if(lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入御灵副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮御灵开始...\r\n"), game);
		if(EnterYuLing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//刷完退出
	if (count >= round)
	{
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
