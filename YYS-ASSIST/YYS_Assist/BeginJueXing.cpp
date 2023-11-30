#pragma once
#include "pch.h"
#include "BeginJueXing.h"
#include "globalvar.h"
#define EXIT_THREAD -10

//选层
int BeginJueXing::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("壹层|贰层|叁层|肆层|伍层|陆层|柒层|捌层|玖层|拾层");
	CString color_format = _T("4D463D-4D473E");
	double sim = 0.85;
	int dictId = 2;
	//start 选择层
	Log(_T("选择觉醒层数...\r\n"), game);
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
	case 4: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("伍层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("陆层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("柒层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("捌层"), color_format, sim, dictId, sn, game, _T("findstr")))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("玖层"), color_format, sim, dictId, sn, game, _T("findstr"), _T("玖|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("拾层"), color_format, sim, dictId, sn, game, _T("findstr"), _T("拾|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//单刷选择层数
int BeginJueXing::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("壹层|贰层|叁层|肆层|伍层|陆层|柒层|捌层|玖层|拾层");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start 选择层
	Log(_T("选择觉醒层数...\r\n"), game);
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
	case 3: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("肆层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("伍层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("陆层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("柒层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("捌层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("玖层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("拾层"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//抽象出选择哪只麒麟方法，方便调用
int BeginJueXing::WhichToSelect(CPoint startXY, CPoint endXY, CString source_font, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	//使用字库
	sn->UseDict(3);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//开启了
		if (sn->FindStrFast(startXY.x, startXY.y, endXY.x, endXY.y, source_font, _T("AC9B91-282724"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(416, 308, 443, 337, _T("友"), _T("E9D3D5-162C2A"), 0.85, &intX, &intY) != -1) {
			Log(_T("成功进入界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//选打哪个
int BeginJueXing::ChooseMonster(int monster_kind, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int i = 15;
	//定义一些变量
	CPoint startXY, endXY;
	CString source_font;
	switch (monster_kind)
	{
		//火  AC9B91-282724, 
	case 0: {
		startXY.x = 115, startXY.y = 443;
		endXY.x = 204, endXY.y = 473;
		source_font = _T("业火轮");
		Log(_T("选择火麒麟...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1){ break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//风 279,281,329,396,
	case 1: {
		startXY.x = 342, startXY.y = 443;
		endXY.x = 418, endXY.y = 473;
		source_font = _T("风转符");
		Log(_T("选择风麒麟...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//水  501,279,552,394,
	case 2: {
		startXY.x = 562, startXY.y = 443;
		endXY.x = 647, endXY.y = 473;
		source_font = _T("水灵鲤");
		Log(_T("选择水麒麟...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//雷 728,269,770,390,
	case 3: {
		startXY.x = 788, startXY.y = 443;
		endXY.x = 877, endXY.y = 473;
		source_font = _T("天雷鼓");
		Log(_T("选择雷麒麟...\r\n"), game);
		int resultSelect = WhichToSelect(startXY, endXY, source_font, sn, game);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}
	default:
		break;
	}
	return 1;
}
//寻副本
int BeginJueXing::FindJueXing(snow *sn, Game *game) {
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
		//点击觉醒材料  28,509,101,537,
		if (sn->FindStrFast(9, 506, 130, 538, _T("觉醒"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			Log(_T("点击觉醒材料...\r\n"), game);
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(117, 4, 182, 61, _T("觉醒之塔.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("成功进入界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//锁定阵容
int BeginJueXing::lockTeam(snow *sn, Game *game) {
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
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(411, 415, 452, 454, _T("阵容锁定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//进入副本
int BeginJueXing::EnterJueXing(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
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
			if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
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
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//庭院邀请好友模式
int BeginJueXing::inviteJueXing(long hd, int round, int mode, int layer, CString jc, int mateType, int triple, snow *sn, Game *game) {
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
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("觉醒"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("很抱歉，未找到组队按钮...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择御魂
	//获取目标位置
	CString fontLst = _T("困难|业火|风转|水灵|天雷|御魂|日轮|永生|妖气|经验|金币|年兽|石距|结界|对弈|回归");
	CString color_format = _T("454039-46413A");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//找到觉醒并点击
	CString mode_str, targetTagFont;
	if (mode==0)
	{
		mode_str = _T("业火");
		targetTagFont = _T("火|CFC8B8-292B28");
	}else if (mode == 1) {
		mode_str = _T("风转");
		targetTagFont = _T("风|CFC8B8-292B28");
	}
	else if (mode == 2) {
		mode_str = _T("水灵");
		targetTagFont = _T("水|CFC8B8-292B28");
	}
	else if (mode == 3) {
		mode_str = _T("天雷");
		targetTagFont = _T("雷|CFC8B8-292B28");
	}
	findDestSite(startXY, endXY, fontLst, mode+1, mode_str, color_format, 0.8, 2, sn, game, _T("findstr"), targetTagFont);
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("未找到目标层数!!!\r\n"), game);
		return 0;
	}
	else if (resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//创建队伍--点击邀请
	if(CreatTeamToInviteUpper(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int resultCreat = CreatTeamToInviteLower(mateType, sn, game);
	if (resultCreat == 0) {
		Log(_T("创建队伍失败!!!\r\n"), game);
		//未找到最近好友，返回庭院后关闭加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		returnYard(sn, game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(_T("觉醒"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}else if(resultCreat == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0, stateCode;
	CString count_str;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测好友加入队伍并点挑战
		if (IsEnterTeam(sn, game, mateType, triple) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入觉醒副本
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮觉醒开始...\r\n"), game);
		if ((stateCode = InviteEnterEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
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
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("觉醒"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//庭院接受邀请模式
int BeginJueXing::BeinvitedJueXing(long hd, int round, CString jc, snow *sn, Game *game) {
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
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("觉醒"), jc, startXY, endXY, sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
	//开始循环
	int count = 0;
	CString count_str;
	while (count < round)
	{
		count_str.Format(_T("%d"), count + 1);
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("等待好友邀请...\r\n"), game);
		int isReadyClick = ReceiveFriendInvite(sn, game);
		if (isReadyClick == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("第") + count_str + _T("轮觉醒开始...\r\n"), game);
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
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("觉醒"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//开始单刷
int BeginJueXing::SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, snow *sn, Game *game) {
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
	//自动开加成
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("觉醒"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻觉醒
	if(FindJueXing(sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	//选打哪个
	int resultChooseMonster = ChooseMonster(monster_kind, sn, game);
	if(resultChooseMonster == EXIT_THREAD) { return EXIT_THREAD; }
	//选层点击 
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultSingleChoose = SingleChooseLayer(layer, startXY, endXY, sn, game);
	if (resultSingleChoose == 0) {
		Log(_T("未找到目标!!!\r\n"), game);
		return 0;
	}
	else if (resultSingleChoose == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//锁定阵容
	if(lockTeam(sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入觉醒副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮觉醒开始...\r\n"), game);
		if (EnterJueXing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//刷完退出
	if (count >= round)
	{
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("觉醒"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
