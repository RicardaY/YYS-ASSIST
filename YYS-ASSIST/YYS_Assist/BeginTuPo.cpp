#pragma once
#include "pch.h"
#include "BeginTuPo.h"
#include "globalvar.h"
#define EXIT_THREAD -10
//高山仰止,景行行止.虽不能至,心向往之。

//寻副本
int BeginTuPo::FindTuPo(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(1);
	//定义局部变量
	long intX, intY;
	Log(_T("寻找结界突破...\r\n"), game);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//结界突破 174,512,245,538，
		if (sn->FindStrFast(174, 512, 285, 538, _T("结界"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y - 25);
			Log(_T("找到结界突破...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(418, 49, 529, 92, _T("结突(副本内).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("成功进入结界突破...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//刷新副本
int BeginTuPo::ReFresh(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(0);
	//定义局部变量
	long intX, intY;
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(721, 426, 851, 473, _T("刷新.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
			Log(_T("点击刷新...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x + 10, posXY.y + 10);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x + 10, posXY.y + 10);
			Log(_T("确定刷新...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(418, 49, 529, 92, _T("结突(副本内).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (GetGTPos(rArrString, sn, game) != 0) {
				Log(_T("初始化可突破项...\r\n"), game);
				break;
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//锁定阵容
int BeginTuPo::lockTeam(snow *sn, Game *game) {
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
		if (sn->FindPic(609, 433, 646, 468, _T("结突解锁阵容.bmp|结突解锁阵容2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("结突解锁阵容.bmp|结突解锁阵容2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(609, 433, 646, 468, _T("结突阵容锁定.bmp|结突阵容锁定2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("结突阵容锁定.bmp|结突阵容锁定2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//解锁阵容
int BeginTuPo::unlockTeam(snow *sn, Game *game) {
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
		if (sn->FindPic(609, 433, 646, 468, _T("结突解锁阵容.bmp|结突解锁阵容2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("结突解锁阵容.bmp|结突解锁阵容2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}
		if (sn->FindPic(609, 433, 646, 468, _T("结突阵容锁定.bmp|结突阵容锁定2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("解锁阵容...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(744, 479, 778, 517, _T("结突阵容锁定.bmp|结突阵容锁定2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("解锁阵容...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 8, pos.y + 8);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//个人突破进入副本
int BeginTuPo::StartToFinish(int count, int clickx, int clicky, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	CString logmsg;
	//字库
	sn->UseDict(0);
	CString attackimg = _T("");
	if (clicky < 200) {attackimg = _T("进攻1.bmp|进攻2.bmp|进攻3.bmp");}
	else if (clicky >= 200 && clicky < 300) { attackimg = _T("进攻4.bmp|进攻5.bmp|进攻6.bmp"); }
	else{ attackimg = _T("进攻7.bmp|进攻8.bmp|进攻9.bmp"); }
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(418, 49, 529, 92, _T("结突(副本内).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(clickx, clicky, 2, 5);
			logmsg.Format(_T("%d,%d"), clickx, clicky);
			if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) == -1) {
				Log(_T("找到可攻破结界[") + logmsg + _T("]\r\n"), game);
				sn->MoveClick(pos.x - 15, pos.y + 15);
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//604,311,863,535,
		if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("识别到进攻...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("点击进攻...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 3000, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		//检测是否有三次的一个宝箱
		if (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			Log(_T("结算成功...\r\n"), game);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 2500, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			Log(_T("结算成功...\r\n"), game);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(271, 40, 423, 216, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("挑战失败，不计次数...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			count--;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(418, 49, 529, 92, _T("结突(副本内).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return count;
}
//寮突进攻---结算
int BeginTuPo::AttackToFinish(int count, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//字库
	sn->UseDict(3);
	//定义局部变量
	long intX, intY;
	int WinOrFailFlag = 0;
	int BeAttackedFlag = 0;
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(298, 91, 823, 491, _T("进攻"), _T("3E301D-3F301D"), 0.75, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("点击进攻...\r\n"), game);
			BeAttackedFlag++;
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			Log(_T("结算成功...\r\n"), game);
			sn->MoveClick(pos.x, pos.y);
			WinOrFailFlag = 1;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(271, 40, 423, 216, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("挑战失败...\r\n"), game);
			WinOrFailFlag = 0;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((sn->FindPic(902, 264, 950, 349, _T("寮突(选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) && (sn->FindPic(145, 444, 176, 482, _T("寮突锁定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			break;
		}
		if (sn->FindStrFast(151, 138, 236, 170, _T("已攻破"), _T("D7C95D-282B20"), 0.9, &intX, &intY) != -1) {
			WinOrFailFlag = 1;
			break;
		}
		if (BeAttackedFlag >= 3) {
			Log(_T("此结界可能已被攻破，已丢弃...\r\n"), game);
			WinOrFailFlag = 0;
			if (sn->FindStrFast(298, 91, 823, 491, _T("进攻"), _T("3E301D-3F301D"), 0.75, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(158, 237, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return WinOrFailFlag;
}
//判断是否有突破券
int BeginTuPo::isHaveTicket(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//字库
	sn->UseDict(3);
	//定义局部变量
	long intX, intY;
	int i = 3;
	while (i > 0) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((sn->FindStrFast(860, 13, 906, 36, _T("突破券30"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) == -1) && (sn->FindStrFast(860, 13, 906, 36, _T("突破券20"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) == -1) && (sn->FindStrFast(860, 13, 906, 36, _T("突破券10"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) == -1) && (sn->FindStrFast(860, 13, 906, 36, _T("突破券0"), _T("A29A8F-4F524A"), 0.9, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//退出突破操作：点击->挑战->返回-->确定-->失败
int BeginTuPo::ExitDo(int clickx, int clicky, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	CString logmsg;
	CString attackimg = _T("");
	if (clicky < 200) { attackimg = _T("进攻1.bmp|进攻2.bmp|进攻3.bmp"); }
	else if (clicky >= 200 && clicky < 300) { attackimg = _T("进攻4.bmp|进攻5.bmp|进攻6.bmp"); }
	else { attackimg = _T("进攻7.bmp|进攻8.bmp|进攻9.bmp"); }
	//字库
	sn->UseDict(0);
	int flag = 0;
	//点击->挑战
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(418, 49, 529, 92, _T("结突(副本内).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			logmsg.Format(_T("%d,%d"), clickx, clicky);
			CPoint pos = sn->RandomOffsetPos(clickx, clicky, 2, 5);
			if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) == -1) {
				Log(_T("找到可攻破结界[") + logmsg + _T("]\r\n"), game);
				sn->MoveClick(pos.x - 15, pos.y + 15);
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(clickx - 259, clicky + 120, clickx + 40, clicky + 224, attackimg, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("识别到进攻...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("点击进攻...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//退出位置 0, 0, 56, 58
		if ((flag == 0) && (findBackIconSite(sn, game, intX, intY) != -1)) {
			if (DelayPlus(game, sn, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x, posXY.y);
			Log(_T("开始退出...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(531, 303, 584, 333, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(posXY.x + 5, posXY.y + 5);
			Log(_T("确定退出...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			flag = 1;
		}
		if (sn->FindPic(271, 40, 423, 216, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(635, 495, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("退出本次突破...\r\n"), game);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(635, 495, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 300, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//退出条件  418,49,529,92,
		if (sn->FindPic(418, 49, 529, 92, _T("结突(副本内).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("退出成功...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//退四
int BeginTuPo::ExitFour(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//坐标定义
	CPoint startXY, endXY;
	CArray<CPoint, CPoint> rArrString;
	int counter = 4;
	int sum = GetGTPos(rArrString, sn, game);
	if (sum == 9) {
		unlockTeam(sn, game);
	}
	while (sum == 9 && counter) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (!isHaveTicket(sn, game)) {
			break;
		}
		ExitDo(rArrString.GetAt(0).x, rArrString.GetAt(0).y, sn, game);
		counter--;
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (counter <= 0) {
		lockTeam(sn, game);
	}
	return 1;
}
//开始
int BeginTuPo::StartTuPo(long hd, int round, snow *sn, Game *game) {
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
	//寻突破
	if (FindTuPo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//锁定阵容
	if (lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//循环开始
	//定义局部变量
	CArray<CPoint, CPoint> parray;
	CString count_str;
	int count = 0;
	//初始化可突破项
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (GetGTPos(parray, sn, game) != 0) {
			break;
		}
		else {
			//刷新
			Log(_T("检测刷新按钮(若刷新按钮在冷却中，则等待)...\r\n"), game);
			ReFresh(parray, sn, game);
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//判断是否有券    突破卷10:858,2,885,37
		int ticket = isHaveTicket(sn, game);
		if (ticket == 0) {
			count = round;
			break;
		}
		else if (ticket == EXIT_THREAD) {
			return EXIT_THREAD;
		}
		//开始突破
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮突破开始...\r\n"), game);
		count = StartToFinish(count, parray.GetAt(0).x, parray.GetAt(0).y, sn, game);
		parray.RemoveAt(0);
		if (parray.GetSize() == 0) {
			if (GetGTPos(parray, sn, game) == 0) {
				//刷新
				Log(_T("检测刷新按钮(若刷新按钮在冷却中，则等待)...\r\n"), game);
				ReFresh(parray, sn, game);
			}
		}
		count++;
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	}

	return 1;
}
//退四打九
int BeginTuPo::StartTuPoByExitFourAttackNine(long hd, int round, snow *sn, Game *game) {
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
	//寻突破
	if (FindTuPo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//锁定阵容
	if (lockTeam(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//循环开始
	//定义局部变量
	CArray<CPoint, CPoint> parray;
	CString count_str;
	int count = 0;
	//初始化可突破项
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (GetGTPos(parray, sn, game) != 0) {
			break;
		}
		else {
			//刷新
			Log(_T("检测刷新按钮(若刷新按钮在冷却中，则等待)...\r\n"), game);
			ReFresh(parray, sn, game);
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	Log(_T("检测是否需要退四...\r\n"), game);
	ExitFour(sn, game);
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//start
		//判断是否有券    突破卷10:858,2,885,37
		int ticket = isHaveTicket(sn, game);
		if (ticket == 0) {
			count = round;
			break;
		}
		else if (ticket == EXIT_THREAD) {
			return EXIT_THREAD;
		}
		//开始突破
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮突破开始...\r\n"), game);
		count = StartToFinish(count, parray.GetAt(0).x, parray.GetAt(0).y, sn, game);
		parray.RemoveAt(0);
		if (parray.GetSize() == 0) {
			if (GetGTPos(parray, sn, game) == 0) {
				//刷新
				Log(_T("检测刷新按钮(若刷新按钮在冷却中，则等待)...\r\n"), game);
				ReFresh(parray, sn, game);
			}
			//是否退四
			Log(_T("检测是否需要退四...\r\n"), game);
			ExitFour(sn, game);
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//返回庭院
int BeginTuPo::TupoReturnYard(snow *sn, Game *game) {
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
		if (sn->FindPic(861, 59, 948, 139, _T("叉1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(14, 17, 67, 71, _T("返回1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("成功返回庭院！\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//识别个人突破未突破选项
int BeginTuPo::GetGTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game) {
	rArrString.RemoveAll();
	if (sn == NULL)
	{
		return false;
	}

	CStringArray arrayList, postList, tempList;
	postList.RemoveAll();
	CString poscount = sn->FindPicEx(282, 92, 874, 418, _T("突破地方.bmp|突破地方(呱太).bmp"), _T("202020"), 0.95, 0);
	if (poscount.IsEmpty()) {
		return 0;
	}
	if (!poscount.IsEmpty()) {
		//提取坐标
		int len = sn->SplitString(poscount, _T("|"), arrayList, 0);
		for (int i = 0; i < len; i++) {
			int tempsize = sn->SplitString(arrayList.GetAt(i), _T(","), tempList, 0);
			for (int j = 0; j < tempsize; j++) {
				if (j % 3 != 0) {
					postList.Add(tempList.GetAt(j));
				}
			}
		}
	}
	//提取为CPoint类型
	int len = postList.GetSize();
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			rArrString.Add(CPoint(StrToInt(postList.GetAt(i)), StrToInt(postList.GetAt(i + 1))));
		}
	}
	//排序
	sn->sortPoints(rArrString);
	return (int)rArrString.GetSize();
}
//识别寮突未突破范围
int BeginTuPo::GetLTPos(CArray<CPoint, CPoint>& rArrString, snow *sn, Game *game) {
	rArrString.RemoveAll();
	if (sn == NULL)
	{
		return false;
	}

	CStringArray arrayList, postList, tempList;
	postList.RemoveAll();
	CString poscountL = sn->FindPicEx(527, 84, 564, 493, _T("寮突地方(左).bmp"), _T("151515"), 0.95, 0);
	CString poscountR = sn->FindPicEx(785, 96, 824, 493, _T("寮突地方(右).bmp"), _T("151515"), 0.95, 0);
	if (poscountL.IsEmpty() && poscountR.IsEmpty()) {
		return 0;
	}
	if (!poscountL.IsEmpty()) {
		//提取坐标
		int len = sn->SplitString(poscountL, _T("|"), arrayList, 0);
		for (int i = 0; i < len; i++) {
			int tempsize = sn->SplitString(arrayList.GetAt(i), _T(","), tempList, 0);
			for (int j = 0; j < tempsize; j++) {
				if (j % 3 != 0) {
					postList.Add(tempList.GetAt(j));
				}
			}
		}
	}
	if (!poscountR.IsEmpty()) {
		int len = sn->SplitString(poscountR, _T("|"), arrayList, 0);
		for (int i = 0; i < len; i++) {
			int tempsize = sn->SplitString(arrayList.GetAt(i), _T(","), tempList, 0);
			for (int j = 0; j < tempsize; j++) {
				if (j % 3 != 0) {
					postList.Add(tempList.GetAt(j));
				}
			}
		}
	}
	//提取为CPoint类型
	int len = postList.GetSize();
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			rArrString.Add(CPoint(StrToInt(postList.GetAt(i)), StrToInt(postList.GetAt(i + 1))));
		}
	}
	return (int)rArrString.GetSize();
}
//寮突
int BeginTuPo::TeamBreak(long hd, int coolingEvent, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	CArray<CPoint, CPoint> parray;
	int i, count;
	CString picName = _T("1次机会.bmp|2次机会.bmp|3次机会.bmp|4次机会.bmp|5次机会.bmp|6次机会.bmp");
	CString logmsg;
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
	//寻突破
	if (FindTuPo(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(902, 264, 950, 349, _T("寮突(未选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("选中寮突...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(145, 444, 176, 482, _T("寮突解锁.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((sn->FindPic(902, 264, 950, 349, _T("寮突(选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) && (sn->FindPic(145, 444, 176, 482, _T("寮突锁定.bmp|寮突(锁定2).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//字库
	sn->UseDict(3);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(195, 410, 247, 449, _T("0次机会.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (coolingEvent == 0) {
				Log(_T("次数用尽，等待冷却...\r\n"), game);
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(195, 410, 247, 449, picName, _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (DelayPlus(game, sn, 5000, 10000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			else {
				if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}
		if (sn->FindStrFast(151, 138, 236, 170, _T("已攻破"), _T("D7C95D-282B20"), 0.9, &intX, &intY) != -1) {
			Log(_T("已攻破，返回庭院...\r\n"), game);
			if (TupoReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			break;

		}
		//D7C95D-282B20 攻破
		if ((count = GetLTPos(parray, sn, game)) != 0) {
			for (i = 0; i < count; i++) {
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(195, 410, 247, 449, picName, _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						logmsg.Format(_T("%d,%d"), parray.GetAt(i).x, parray.GetAt(i).y);
						Log(_T("找到目标结界[") + logmsg + _T("]\r\n"), game);
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(parray.GetAt(i).x, parray.GetAt(i).y, 0, 5);
						sn->MoveClick(pos.x - 45, pos.y + 15);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					
					if (sn->FindStrFast(298, 91, 823, 491, _T("进攻"), _T("3E301D-3F301D"), 0.75, &intX, &intY) != -1) {
						Log(_T("识别到进攻...\r\n"), game);
						break;
					}
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (AttackToFinish(count, sn, game)) {
					break;
				}
			}
		}
		else {
			//模拟真实鼠标轨迹
			sn->EnableRealMouse(1, 20, 30);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->DragMouse(540, 420, 540, 380);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			//模拟真实鼠标轨迹
			sn->EnableRealMouse(3, 20, 30);
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
