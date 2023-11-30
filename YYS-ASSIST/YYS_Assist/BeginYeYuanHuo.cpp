#pragma once
#include "pch.h"
#include "BeginYeYuanHuo.h"
#include "globalvar.h"
#define EXIT_THREAD -10
//春风得意马蹄疾，一日看尽长安花。
//选层
int BeginYeYuanHuo::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("贪|嗔|痴");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start 选择层
	Log(_T("选择业原火贪|嗔|痴...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("贪"), color_format, sim, dictId, sn, game))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("嗔"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("痴"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//寻副本
int BeginYeYuanHuo::FindYeYuanHuo(snow *sn, Game *game) {
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
		//点击自动匹配
		if (sn->FindStrFast(108, 504, 188, 538, _T("御魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("点击御魂...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点业原火D2CCBF-2D3336
		if (sn->FindStrFast(310, 166, 381, 226, _T("火"), _T("D2CCBF-2D3336"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			Log(_T("点击业原火...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(793, 119, 819, 141, _T("友"), _T("E9D3D5-162C2A"), 0.85, &intX, &intY) != -1) {
			Log(_T("成功进入界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//锁定阵容
int BeginYeYuanHuo::lockTeam(snow *sn, Game *game) {
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
		if (sn->FindPic(411, 415, 452, 454, _T("解锁阵容.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX+13, intY+13);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(411, 415, 452, 454, _T("阵容锁定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//进入副本
int BeginYeYuanHuo::EnterYeYuanHuo(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(0);
	//定义局部变量
	long intX, intY;
	int closingflag = 0;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(824, 437, 902, 505, _T("挑战业原火.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
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
			Log(_T("结算成功...\r\n"), game);
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
int BeginYeYuanHuo::StartYeYuanHuo(long hd, int round, int layer, snow *sn, Game *game) {
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
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻业原火
	if(FindYeYuanHuo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层点击
	CPoint startXY, endXY;
	startXY.x = 110, startXY.y = 93;
	endXY.x = 360, endXY.y = 439;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("未找到目标!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//锁定阵容
	if(lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入业原火副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮业原火开始...\r\n"), game);
		if(EnterYeYuanHuo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
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
