#pragma once
#include "pch.h"
#include "BeginYongShengZhiHai.h"
#include "globalvar.h"

#define EXIT_THREAD -10
//慢品人间烟火色，闲观万事岁月长。

//选层
int BeginYongShengZhiHai::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("壹层|贰层|叁层|肆层");
	CString color_format = _T("4D463D-4D473E");
	double sim = 0.85;
	int dictId = 2;
	//start 选择层
	Log(_T("选择永生之海层数...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("壹层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("贰层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("叁层"), color_format, sim, dictId, sn, game, _T("findstr"), _T("叁|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("肆层"), color_format, sim, dictId, sn, game, _T("findstr"), _T("肆|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//单刷选层
int BeginYongShengZhiHai::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("壹层|贰层|叁层|肆层");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start 选择层
	Log(_T("选择永生之海...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("壹层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("贰层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("叁层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("肆层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//创建队伍---点击邀请
int BeginYongShengZhiHai::CreatYszhTeamToInviteUpper(int mateType, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(2);
	//点击创建队伍
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(754, 457, 805, 484, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)//创建队伍
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			Log(_T("创建队伍...\r\n"), game);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(630, 429, 685, 458, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) { //3C2E1C-3C2E1D
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//设置公开权限
	while (1)
	{
		if (sn->FindPic(555, 361, 592, 398, _T("不公开(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("选择权限不公开...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//557,365,591,398,
		if (sn->FindPic(557, 365, 591, 398, _T("不公开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击创建
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(630, 429, 685, 458, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			Log(_T("创建...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(630, 187, 691, 248, _T("永生之海加.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)
		{
			break;
		}
		else if (sn->FindPic(235, 184, 296, 246, _T("永生之海加.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
int BeginYongShengZhiHai::CreatYszhTeamToInviteLower(int mateType, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(2);
	//邀请好友
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(630, 187, 691, 248, _T("永生之海加.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("邀请好友...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 12, intY + 10);
			if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (sn->FindPic(235, 184, 296, 246, _T("永生之海加.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)
		{
			if (sn->FindPic(444, 197, 520, 279, _T("切换位置.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("切换位置...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 12, intY + 10);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if ((mateType == 0) && (sn->FindPic(345, 68, 403, 104, _T("最近(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY + 10);
			Log(_T("选择最近组队好友...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((mateType == 2) && (sn->FindPic(258, 68, 313, 106, _T("好友(未选中).bmp"), _T("151515"), 0.85, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y + 5);
			Log(_T("选择同区好友...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((mateType == 3) && (sn->FindPic(520, 72, 572, 101, _T("跨区(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y + 5);
			Log(_T("选择跨区好友...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((mateType == 0) && (sn->FindPic(345, 68, 403, 104, _T("最近.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			break;
		}
		else if ((mateType == 1) && (sn->FindPic(345, 68, 403, 104, _T("最近.bmp|最近(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("固定好友：请手动选择好友，点击邀请！\r\n"), game);
			if (DelayPlus(game, sn, 800, 802) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("检测邀请中...\r\n"), game);
			break;
		}
		else if ((mateType == 2) && (sn->FindPic(258, 68, 313, 106, _T("好友(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			break;
		}
		else if ((mateType == 3) && (sn->FindPic(520, 72, 572, 101, _T("跨区(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (mateType == 0) {
		//判断是否为最近组队，是则邀请，否则退出
		int combineClock = 0;
		while (1)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(404, 119, 483, 157, _T("最近组队.bmp|最近组队2.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
			{
				Log(_T("邀请...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX - 50, intY + 40);
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(404, 119, 483, 157, _T("最近组队(选中).bmp|最近组队(选中)2.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			combineClock++;
			if (combineClock >= 10) {
				combineClock = -100;
				break;
			}
		}
		//不是最近组队好友，返回庭院
		if (combineClock == -100)
		{
			Log(_T("列表第一位没有最近组队标识，请手动邀请一次...\r\n"), game);
			Log(_T("返回庭院中...\r\n"), game);
			if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		//点击邀请
		while (1)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
			{
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX + 10, intY + 5);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(860, 429, 946, 510, _T("永生之海挑战.bmp|永生之海挑战(灰).bmp"), _T("202020"), 0.98, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1))
			{
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (mateType == 1) {
		while (1)
		{

			if (sn->FindPic(860, 429, 946, 510, _T("永生之海挑战.bmp|永生之海挑战(灰).bmp"), _T("202020"), 0.98, 0, &intX, &intY) != -1) {
				if (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1) {
					Log(_T("恢复自动，请勿继续手动操作...\r\n"), game);
					break;
				}
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (mateType == 2) {
		//判断是否为同区固定队友，是则邀请，否则退出
		int combineClock = 0;
		while (1)
		{
			if (sn->SetPath(_T("config\\imgGame12")) && sn->FindPic(319, 138, 692, 316, sn->MatchPicName(_T("teamer?.bmp")), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 25, pos.y + 8);
				Log(_T("选中列表中同区固定好友...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->SetPath(g_path) && sn->FindPic(419, 118, 701, 312, _T("邀请(选中).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			combineClock++;
			if (combineClock >= 10) {
				combineClock = -100;
				break;
			}
		}
		//未找到同区固定好友
		if (combineClock == -100)
		{
			Log(_T("列表内没有同区固定好友，请检查是否截取过好友图...\r\n"), game);
			Log(_T("返回庭院中...\r\n"), game);
			if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		//点击邀请
		while (1)
		{
			if (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y);
				Log(_T("点击邀请...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(860, 429, 946, 510, _T("永生之海挑战.bmp|永生之海挑战(灰).bmp"), _T("202020"), 0.98, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1))
			{
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (mateType == 3) {
		//判断是否为跨区固定队友，是则邀请，否则退出
		int combineClock = 0;
		while (1)
		{
			if (sn->SetPath(_T("config\\imgGame12")) && sn->FindPic(319, 138, 692, 316, sn->MatchPicName(_T("teamer?.bmp")), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 25, pos.y + 8);
				Log(_T("选中列表中跨区固定好友...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->SetPath(g_path) && sn->FindPic(419, 118, 701, 312, _T("邀请(选中).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			combineClock++;
			if (combineClock >= 10) {
				combineClock = -100;
				break;
			}
		}
		//未找到同区固定好友
		if (combineClock == -100)
		{
			Log(_T("列表内没有跨区固定好友，请检查是否截取过好友图...\r\n"), game);
			Log(_T("返回庭院中...\r\n"), game);
			if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		//点击邀请
		while (1)
		{
			if (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y);
				Log(_T("点击邀请...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(860, 429, 946, 510, _T("永生之海挑战.bmp|永生之海挑战(灰).bmp"), _T("202020"), 0.98, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1))
			{
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}

//检测好友进入队伍点挑战 
int BeginYongShengZhiHai::InnerIsEnterTeam(int mateType, int count, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int timeRecord = 0;
	//检查好友是否进入队伍
	Log(_T("等待好友加入队伍...\r\n"), game);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点挑战
		if (sn->FindPic(860, 429, 946, 510, _T("永生之海挑战.bmp"), _T("202020"), 0.98, 0, &intX, &intY) != -1)
		{
			Log(_T("好友已加入队伍...\r\n"), game);
			//随机偏移坐标防检测
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		Sleep(1500);
		timeRecord++;
		if (timeRecord >= 12) {
			Log(_T("好友未加入，重新邀请好友...\r\n"), game);
			if (CreatYszhTeamToInviteLower(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			timeRecord = 0;
		}
	}
	return 1;
}
//寻副本
int BeginYongShengZhiHai::FindYongShengZhiHai(snow *sn, Game *game) {
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
		//点击御魂
		if (sn->FindStrFast(108, 504, 188, 538, _T("御魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("点击御魂...\r\n"), game);
			sn->MoveClick(intX + 10, intY - 20);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点永生之海D7CFCF-282827
		if (sn->FindStrFast(858, 170, 918, 238, _T("海"), _T("D2CCBF-2D3336"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			Log(_T("点击永生之海...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(793, 119, 819, 141, _T("友"), _T("E9D3D5-162C2A"), 0.85, &intX, &intY) != -1) {
			Log(_T("成功进入界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//锁定阵容
int BeginYongShengZhiHai::lockTeam(snow *sn, Game *game) {
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
			sn->MoveClick(intX + 13, intY + 13);
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
int BeginYongShengZhiHai::EnterYongShengZhiHai(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//字库
	sn->UseDict(0);
	//定义局部变量
	long intX, intY;
	int closingfalg = 0;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(824, 437, 902, 505, _T("单刷永生挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
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
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 20, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			closingfalg = 1;
		}
		if ((closingfalg == 1) && (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
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
//开始单刷
int BeginYongShengZhiHai::SingleYongShengZhiHai(long hd, int round, int layer, CString jc, snow *sn, Game *game) {
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
	//寻永生之海
	if(FindYongShengZhiHai(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层点击
	CPoint startXY, endXY;
	startXY.x = 110, startXY.y = 93;
	endXY.x = 360, endXY.y = 439;
	int resultSingleChoose = SingleChooseLayer(layer, startXY, endXY, sn, game);
	if (resultSingleChoose == 0) {
		Log(_T("未找到目标!!!\r\n"), game);
		return 0;
	}else if(resultSingleChoose == EXIT_THREAD) { return EXIT_THREAD; }
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
		Log(_T("第") + count_str + _T("轮永生之海开始...\r\n"), game);
		if(EnterYongShengZhiHai(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
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
//庭院邀请好友模式
int BeginYongShengZhiHai::inviteYongShengZhiHai(long hd, int round, int layer, CString jc, int mateType, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//等好友事件
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//初始化准备标志
	readyFlag = TRUE;
	//判断是否在庭院
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("很抱歉，未找到组队按钮...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择永生之海
	//获取目标位置
	CString fontLst = _T("困难|业火|风转|水灵|天雷|御魂|日轮|永生|妖气|经验|金币|年兽|石距|结界|对弈|回归");
	CString color_format = _T("454039-46413A");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//找到永生之海并点击
	findDestSite(startXY, endXY, fontLst, 7, _T("永生"), color_format, 0.8, 2, sn, game, _T("findstr"), _T("海|CFC8B8-292B28"));
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("未找到目标层数!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//创建队伍--点击邀请
	if(CreatYszhTeamToInviteUpper(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int resultCreat = CreatYszhTeamToInviteLower(mateType, sn, game);
	if (resultCreat == 0) {
		Log(_T("创建队伍失败!!!\r\n"), game);
		return 0;
	}else if(resultCreat == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0, stateCode;
	CString count_str;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测好友加入队伍并点挑战
		if(InnerIsEnterTeam(mateType, count, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入永生之海副本
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮永生之海开始...\r\n"), game);
		if ((stateCode = InviteEnterEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		if (stateCode == DEFAULT) { DefalutInvite(sn, game); }
		else if (stateCode == FAIL) { FailEvent(sn, game); }
		count++;
	}
	//刷完退出
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//庭院接受邀请模式
int BeginYongShengZhiHai::BeinvitedYongShengZhiHai(long hd, int round, CString jc, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//等好友事件
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//初始化准备标志
	readyFlag = TRUE;
	//判断是否在庭院
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	//开始循环
	int count = 0;
	CString count_str;
	while (count < round)
	{
		count_str.Format(_T("%d"), count + 1);
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入永生之海副本
		Log(_T("等待好友邀请...\r\n"), game);
		int isReadyClick = ReceiveFriendInvite(sn, game);
		if (isReadyClick == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("第")+ count_str + _T("轮永生之海开始...\r\n"), game);
		EnterEvent(sn, game, isReadyClick);
		count++;
	}
	//刷完退出
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
