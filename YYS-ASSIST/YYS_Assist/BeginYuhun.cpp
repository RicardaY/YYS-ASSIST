#pragma once
#include "pch.h"
#include "BeginYuhun.h"
#include "globalvar.h"

#define EXIT_THREAD -10


//选择层数
int BeginYuhun::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("壹层|贰层|叁层|肆层|伍层|陆层|柒层|捌层|玖层|拾层|悲鸣|神罚");
	CString color_format = _T("4D463D-4D473E");
	// targetTagFont 拾 悲 神 CFC8B8-292B28
	double sim = 0.85;
	int dictId = 2;
	//start 选择层
	Log(_T("选择御魂层数...\r\n"), game);
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
		if (findDestSite(startXY, endXY, fontLst, layer, _T("玖层"), color_format, sim, dictId, sn, game, _T("findstr")))
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
	case 10: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("悲鸣"), color_format, sim, dictId, sn, game, _T("findstr"), _T("悲|CFC8B8-292B28")))
			break;
		else
			return 0;
	}
	case 11: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("神罚"), color_format, sim, dictId, sn, game, _T("findstr"), _T("神|CFC8B8-292B28")))
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
int BeginYuhun::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString fontLst = _T("壹层|贰层|叁层|肆层|伍层|陆层|柒层|捌层|玖层|拾层|悲鸣|神罚");
	CString color_format = _T("424243-434243");
	double sim = 0.85;
	int dictId = 3;
	//start 选择层
	Log(_T("选择御魂层数...\r\n"), game);
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
	case 10: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("悲鸣"), color_format, sim, dictId, sn, game))
			break;
		else
			return 0;
	}
	case 11: {
		if (findDestSite(startXY, endXY, fontLst, layer, _T("神罚"), color_format, sim, dictId, sn, game))
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
int BeginYuhun::FindYuHun(snow *sn, Game *game) {
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
		//点击探索界面御魂  114,512,161,537,
		if (sn->FindStrFast(108, 504, 188, 538, _T("御魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("点击御魂...\r\n"), game);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点[八岐大蛇]D7D2CA-282D25
		if (sn->FindStrFast(36, 149, 93, 189, _T("大"), _T("D7D2CA-282D25"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			Log(_T("点击八岐大蛇...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
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
int BeginYuhun::lockTeam(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量7E6342-3E392A
	long intX, intY;
	Log(_T("检查是否锁定阵容...\r\n"), game);
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
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//进入副本 魂范围：335,256,616,497,
int BeginYuhun::EnterYuHun(snow *sn, Game *game) {
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
		if (readyFlag&&(sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("点击准备...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }//485 500
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp|魂(氪金).bmp|魂底(氪金).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp|魂(氪金).bmp|魂底(氪金).bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//庭院邀请好友模式
int BeginYuhun::inviteYuhun(long hd, int round, int layer, CString jc, int mateType, int triple, snow *sn, Game *game) {
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
	//自动开加成303,28,327,65,
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 327, endXY.y = 68;
	if (auto_open_jc(_T("御魂"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("很抱歉，未找到组队按钮...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择御魂
	//获取目标位置
	CString fontLst = _T("困难|业火|风转|水灵|天雷|御魂|日轮|永生|妖气|经验|金币|年兽|石距|结界|对弈|回归");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//找到御魂并点击
	findDestSite(startXY, endXY, fontLst, 5, _T("御魂"), _T("454039-46413A"), 0.85, 2, sn, game, _T("findstr"), _T("魂|CFC8B8-292B28"));
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(layer, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("未找到目标层数!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//创建队伍--点击邀请
	if (CreatTeamToInviteUpper(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int resultCreat = CreatTeamToInviteLower(mateType, sn, game);
	if (resultCreat == 0) {
		Log(_T("创建队伍失败!!!\r\n"), game);
		//未找到最近好友，返回庭院后关闭加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		returnYard(sn, game);
		if (DelayPlus(game, sn, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(_T("御魂"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	else if (resultCreat == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0,stateCode;
	CString count_str;
	while (count<round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测好友加入队伍并点挑战
		if (IsEnterTeam(sn, game, mateType, triple) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入八岐大蛇副本
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮御魂开始...\r\n"), game);
		if ((stateCode = InviteEnterEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		if (stateCode == DEFAULT) { DefalutInvite(sn, game); }
		else if (stateCode == FAIL) { FailEvent(sn, game); }
		count++;
	}
	//刷完退出
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1,waitFlag2);
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (YuHunReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("御魂"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//庭院接受邀请模式
int BeginYuhun::BeinvitedYuhun(long hd, int round, CString jc, snow *sn, Game *game) {
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
	if (auto_open_jc(_T("御魂"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	CString count_str;
	Log(_T("等待好友邀请...\r\n"), game);
	while (count < round)
	{
		count_str.Format(_T("%d"), count + 1);
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入八岐大蛇副本
		int isReadyClick = ReceiveFriendInvite(sn, game);
		if (isReadyClick == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("第") + count_str + _T("轮御魂开始...\r\n"), game);
		EnterEvent(sn, game, isReadyClick);
		count++;
	}
	//刷完退出
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (YuHunReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("御魂"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//单刷
int BeginYuhun::SingleYuHun(long hd, int round, int layer, CString jc, snow *sn, Game *game) {
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
	if (auto_open_jc(_T("御魂"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	//寻八岐大蛇
	if(FindYuHun(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层点击
	startXY.x = 102, startXY.y = 88;
	endXY.x = 361, endXY.y = 468;
	int resultSingleChoose = SingleChooseLayer(layer, startXY, endXY, sn, game);
	if (resultSingleChoose == 0) {
		Log(_T("未找到目标!!!\r\n"), game);
		return 0;
	}else if(resultSingleChoose == EXIT_THREAD){ return EXIT_THREAD; }
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
		//进入御魂副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮御魂开始...\r\n"), game);
		if(EnterYuHun(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//刷完退出
	if (count >= round)
	{
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (YuHunReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("御魂"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//返回庭院
int BeginYuhun::YuHunReturnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//字库
	sn->UseDict(0);
	//开始返回
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(9, 2, 76, 65, _T("返回(队伍).bmp|返回2.bmp|返回3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 2, 76, 65, _T("返回1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 1, 65, 59, _T("返回4.bmp|返回8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 305, 596, 339, _T("确定|确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 429);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if(sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("成功返回庭院！\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
/**
 *								*********************************************
												   _ooOoo_
												  o8888888o
												  88" . "88
												  (| -_- |)
												  O  =  /O
											   ____/`---'\____
											 .'  \|     |//  `.
											/  \|||  :  |||//  
										   /  _||||| -:- |||||-  
										   |   | \  -  /// |   |
										   | \_|  ''---/''  |   |
											 .-\__  `-`  ___/-. /
										 ___`. .'  /--.--  `. . __
									  ."" '&lt;  `.___\_&lt;|>_/___.'  >'"".
									 | | :  `- \`.;` _ /`;.`/ - ` : | |
										`-.   \_ __ /__ _/   .-` /  /
								======`-.____`-.___\_____/___.-`____.-'======
												   `=---='
								^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
										   佛祖保佑       永无BUG
 */
