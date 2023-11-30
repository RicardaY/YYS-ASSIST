#include "pch.h"
#include "InDependentFunction.h"
#include "Resource.h"
#include "SuperKing.h"
#include "globalvar.h"
#define EXIT_THREAD -10
/*
		风起于青萍之末，浪成于微澜之间
*/
//百鬼夜行
int InDependentFunction::StartBaiGui(int round, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	Log(_T("独立功能--百鬼夜行\r\n"), game);
	if (sn->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)
	{
		Log(_T("请进入百鬼夜行页面...\r\n"), game);
		return 0;
	}
	Log(_T("默认1000张票，暂时不可更改...\r\n"), game);
	int count = 0;
	while (count < round) {
		//拒绝悬赏
		AutoRejectXS(sn, game);
		if (sn->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("进入百鬼夜行...\r\n"), game);
			sn->MoveClick(intX + 10, intY + 20);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}//416,3,553,59,
		if (sn->FindPic(416, 3, 553, 59, _T("百鬼夜行.bmp|百鬼夜行2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(442, 69, 521, 441, _T("百鬼押.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("押式神...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(477, 314, 1, 4);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(442, 69, 521, 441, _T("百鬼押.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(833, 427, 915, 481, _T("百鬼开始.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					CString count_str;
					count_str.Format(_T("%d"), count + 1);
					Log(_T("第")+count_str+_T("轮百鬼夜行开始...\r\n"), game);
					sn->MoveClick(intX + 10, intY + 5);
					if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (sn->FindPic(44, 473, 101, 514, _T("百鬼豆子.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->DragMouse(305, 496, 459, 496);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("开始撒豆...\r\n"), game);
			count++;
			while (1) {
				AutoRejectXS(sn, game);
				CPoint posx = sn->RandomOffsetPos(507, 295, -200, 200);
				CPoint posy = sn->RandomOffsetPos(507, 295, -5, 5);
				sn->MoveClick(posx.x, posy.y);
				int beanRes = sn->FindPic(34, 468, 134, 515, _T("正常0豆.bmp|冰冻0豆.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				int timeRes = sn->FindPic(448, 1, 508, 50,  _T("时间零.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				while ((beanRes != -1) || (timeRes != -1)) {
					if (sn->FindPic(72, 165, 117, 335, _T("百鬼契约书.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->MoveClick(intX + 10, intY + 5);
						if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(782, 412, 882, 496, _T("百鬼进入.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= round) {
		Log(_T("完成百鬼夜行...\r\n"), game);
	}
	return 1;
}
//地域鬼王打一只
int InDependentFunction::SelectWhichReginalKing(CPoint startXY, CPoint endXY, int kindCheck, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	sn->UseDict(4);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(821, 3, 883, 72, _T("筛选.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("选择筛选...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((kindCheck == (int)IDC_RADIO_HOT) && (sn->FindPic(890, 129, 926, 208, _T("热门(选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			Log(_T("热门...\r\n"), game);
			break;
		}else if ((kindCheck== (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("收藏(选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			Log(_T("收藏...\r\n"), game); 
			break;
		}
		if ((kindCheck== (int)IDC_RADIO_HOT) && (sn->FindPic(890, 129, 926, 208, _T("热门(未选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((kindCheck== (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("收藏(未选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, _T("地鬼挑战.bmp|地鬼挑战2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
		{
			Log(_T("挑战...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
		if (sn->FindPic(813, 372, 893, 425, _T("地鬼开始挑战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1){
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(385, 27, 437, 76, _T("地鬼普通.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("切换为普通模式...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 20);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(104, 198, 414, 244, _T("地鬼进度条.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("地域鬼王-普通难度...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(813, 372, 893, 425, _T("地鬼开始挑战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			while (sn->FindPic(224, 139, 292, 202, _T("地鬼1级.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)
			{
				//设置至一级
				if (sn->FindPic(104, 198, 414, 244, _T("地鬼进度条.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					if (intX > 112) {
						sn->EnableRealMouse(1, 20, 30);
						Log(_T("设置一级...\r\n"), game);
						if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(intX + 3, intY + 5, 112, intY + 5);
						if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(224, 139, 292, 202, _T("地鬼1级.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			sn->EnableRealMouse(3, 20, 30);
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(813, 372, 893, 425, _T("地鬼开始挑战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("开始挑战...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//消除弹出的白藏主提示(若有)
		if (sn->FindPic(263, 215, 366, 304, _T("小白.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("点击小白消除提示...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点准备
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findManualSite(sn, game, intX, intY) != -1) { //CAD5E4-34291A
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("切换为自动模式...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while(1){
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//胜利结算
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("结算成功...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(813, 372, 893, 425, _T("地鬼开始挑战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(813, 372, 893, 425, _T("地鬼开始挑战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("返回地域鬼王界面...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(907, 32);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(821, 3, 883, 72, _T("筛选.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			Log(_T("返回成功...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//地域鬼王
int InDependentFunction::StartReginalKing(long hd, int amount, int kindCheck, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(1);
	//定义局部变量
	long intX, intY;
	Log(_T("独立功能--地域鬼王\r\n"), game);
	//判断是否在庭院
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	while (1) {
		//自动拒绝悬赏  540,511,614,536,
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(540, 511, 690, 538, _T("地域"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("点击地域鬼王...\r\n"), game);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//契灵版地域鬼王位置
		if (sn->FindStrFast(465, 508, 537, 534, _T("地域"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 20);
			Log(_T("点击地域鬼王...\r\n"), game);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(821, 3, 883, 72, _T("筛选.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			break;
		}
		if ((kindCheck == (int)IDC_RADIO_HOT)&&(sn->FindPic(890, 129, 926, 208, _T("热门(选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)){break;}
		else if ((kindCheck == (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("收藏(选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) { break; }
		if ((kindCheck == (int)IDC_RADIO_HOT)&&(sn->FindPic(890, 129, 926, 208, _T("热门(未选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((kindCheck== (int)IDC_RADIO_COLLECT) && (sn->FindPic(890, 396, 925, 472, _T("收藏(未选中).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//打几只
	CPoint c_SXY(803, 162), c_EXY(871, 230);
	SelectWhichReginalKing(c_SXY, c_EXY, kindCheck, sn, game);
	if (amount == 0) {
		//返回庭院
		returnYard(sn, game);
		return 1;
	}
	c_SXY.y += 115, c_EXY.y += 115;
	SelectWhichReginalKing(c_SXY, c_EXY, kindCheck, sn, game);
	if (amount == 1) {
		//返回庭院
		returnYard(sn, game);
		return 1;
	}
	c_SXY.y += 115, c_EXY.y += 115;
	SelectWhichReginalKing(c_SXY, c_EXY, kindCheck, sn, game);
	if (amount == 2) {
		//返回庭院
		returnYard(sn, game);
	}
	return 1;
}
//自动剧情点怪---结算
int InDependentFunction::ClickMonsterToVictory(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	sn->UseDict(4);
	int closingflag = 0;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findManualSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("切换为自动模式...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 30, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (sn->FindPic(281, 68, 430, 218, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//自动剧情
int InDependentFunction::AutoPlot(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(4);
	//定义局部变量
	long intX, intY;
	int findFlag = 0;
	Log(_T("独立功能--自动剧情\r\n"), game);
	Log(_T("请进入剧情或者在庭院有剧情提示时开启...\r\n"), game);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(446, 41, 856, 368, _T("..."), _T("CDC2C3-323D3C"), 0.9, &intX, &intY) != -1)//CDC2C3-323D3C
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("进入剧情...\r\n"), game);
			findFlag = 0;
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(561, 368, 784, 444, _T("跳过.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("跳过剧情...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindPic(70, 19, 103, 42, _T("信息.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (sn->FindStrFast(1, 47, 955, 502, _T("..."), _T("CDC2C3-323D3C"), 0.9, &intX, &intY) != -1)//CDC2C3-323D3C
			{
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("开始对话...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				findFlag = 0;
			}
		}
		if (sn->FindPic(70, 19, 103, 42, _T("信息.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (sn->FindStrFast(1, 47, 955, 502, _T("..."), _T("C0B2B4-212526"), 0.9, &intX, &intY) != -1)//CDC2C3-323D3C
			{
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("开始对话...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				findFlag = 0;
			}
		}
		if (sn->FindStrFast(1, 47, 955, 502, _T("?"), _T("BCA9AA-2D2F2F"), 0.8, &intX, &intY) != -1) {//C7B1AE-2E3336
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("开始对话...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindStrFast(1, 47, 955, 502, _T("?"), _T("C7B1AE-2E3336"), 0.8, &intX, &intY) != -1) {//C7B1AE-2E3336
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("开始对话...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		//发现怪物
		if (sn->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("发现妖怪...\r\n"), game);
			if (ClickMonsterToVictory(sn, game) == 0) {
				Log(_T("因挑战失败停止...\r\n"), game);
				break;
			}
			findFlag = 0;
		}
		if (sn->FindPic(0, 47, 955, 502, _T("眼睛.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("进入幻境...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}//
		if (sn->FindPic(836, 9, 910, 83, _T("快进.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("快进中...\r\n"), game);
			if (DelayPlus(game, sn, 2000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindPic(811, 0, 958, 159, _T("怪物介绍.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (sn->FindPic(846, 2, 940, 37, _T("关闭.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("关闭...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			findFlag = 0;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		findFlag++;
		if (findFlag >= 10) {
			findFlag = 0;
			sn->MoveClick(813, 504);
			Log(_T("随机点击...\r\n"), game);
		}
	}
	return 1;
}
//自动斗技
int InDependentFunction::AutoPVP(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//设置字库
	sn->UseDict(0);
	//定义局部变量
	long intX, intY;
	Log(_T("独立功能--自动斗技\r\n"), game);
	Log(_T("开始前请进入斗技界面...\r\n"), game);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(843, 408, 955, 507, _T("战.bmp|战(保护).bmp|战(保护2).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("进入战斗...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint posXY = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(posXY.x, posXY.y);
			Log(_T("退出...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 303, 587, 332, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("确认退出...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {//
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			if (sn->FindStrFast(447, 412, 469, 434, _T("限"), _T("8D1F1D-250305"), 0.85, &intX, &intY) != -1) {//8D1F1D-250305
				CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("荣誉点已到上限...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(447, 412, 469, 434, _T("限"), _T("8D1F1D-250305"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("荣誉点已到上限...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//自动斗技(不退)
int InDependentFunction::AutoPVPToMingShi(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//使用字库
	sn->UseDict(4);
	Log(_T("独立功能--自动斗技\r\n"), game);
	Log(_T("开始前请进入斗技界面...\r\n"), game);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(843, 408, 955, 507, _T("战.bmp|战(保护).bmp|战(保护2).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("进入战斗...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 93, 68, 149, _T("自动上阵.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("自动上阵...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findManualSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("切换为自动模式...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			sn->UseDict(4);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(826, 493, 853, 522, _T("据"), _T("BCB2A2-43413E"), 0.9, &intX, &intY) != -1) {//战斗数据
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("拔得头筹...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(787, 409, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(248, 12, 450, 173, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("结算成功...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(428, 269, 472, 291, _T("段位"), _T("D0CBBA-282826"), 0.85, &intX, &intY) != -1) {//段位上升
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("段位上升...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(322, 180, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//新活动
int InDependentFunction::StartNewEvent(int round, int mode, int flag, int bossflag, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(6);
	//定义局部变量
	long intX, intY;
	Log(_T("开始前请进入") + activityName + _T("-") + activitySubName + _T("界面(并配置好队伍，自己锁定阵容)...\r\n"), game);
	if (mode)
		Log(_T("模式：使用体力挑战...\r\n"), game);
	else
		Log(_T("模式：使用") + TiLiName + _T("挑战...\r\n"),game);
	int count = 0;
	CString logmsg;
	int markflag = 0, markflag2 = 0;
	//判断是否开5倍buff   AEA99B-292C2A
	//if (mode == 1) {
	//	while (1) {
	//		//自动拒绝悬赏
	//		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//		else {
	//			if (sn->FindPic(650, 476, 691, 524, _T("活动5倍(未选).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
	//				if (DelayPlus(game, sn, 100, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	//				Log(_T("点击5倍...\r\n"), game);
	//				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
	//				sn->MoveClick(pos.x, intY);
	//				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//			}
	//			if (sn->FindPic(650, 476, 691, 524, _T("活动5倍(已选).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
	//				Log(_T("已选择5倍...\r\n"), game);
	//				break;
	//			}
	//		}
	//	}
	//}
	while (count < round) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (!mode&&sn->FindPic(510, 17, 573, 39, _T("活动0体.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count = round;
			Log(TiLiName + _T("用尽...\r\n"), game);
			break;
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//3C3336-3D3336
			if (sn->FindStrFast(838, 444, 915, 490, _T("活动挑战"), _T("3C3336-3D3336"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("点击挑战...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				logmsg.Format(_T("%d"), count + 1);
				Log(_T("第") + logmsg + _T("轮") + activitySubName + _T("开始...\r\n"), game);
				//使用字库
				sn->UseDict(6);
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//标记式神 107,142,215,408,   143,163,220,354,
			if (flag && !markflag && sn->FindPic(31, 143, 125, 373, _T("活动标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }//198,212,266,323,
				Log(_T("标记式神(左1)...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(78, 360, 1, 3);
				sn->MoveClick(78, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (flag && !markflag && sn->FindPic(31, 143, 125, 373, _T("活动标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("已标记我方式神...\r\n"), game);
				markflag = 1;
			}
			////标记boss
			//if (bossflag && !markflag2 && sn->FindPic(456, 30, 514, 89, _T("活动boss标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			//	Log(_T("已标记Boss...\r\n"), game);
			//	markflag2 = 1;
			//}
			//else if (bossflag && !markflag2 && sn->FindPic(456, 30, 514, 89, _T("活动boss标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
			//	if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//	Log(_T("标记Boss...\r\n"), game);
			//	CPoint pos = sn->RandomOffsetPos(480, 198, 1, 3);
			//	sn->MoveClick(480, pos.y);
			//	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			//}
			if (sn->FindPic(294, 84, 439, 204, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("战斗胜利...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(400, 490, 5, 10);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//
			if (sn->FindStrFast(412, 86, 540, 213, _T("得奖"), _T("BDAA6A-373A39"), 0.8, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("获得奖励...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("领取奖励...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(838, 444, 915, 490, _T("活动挑战"), _T("3C3336-3D3336"), 0.85, &intX, &intY) != -1) {
				markflag = 0;
				//markflag2 = 0;
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= round) {
		Log(_T("任务已完成。\r\n"), game);
	}
	return 1;
}

//自选功能
int InDependentFunction::DIYFunction(int ready, int clearing, int whitecard, int challenge, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	Log(_T("独立功能--自选功能\r\n"), game);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (ready) {
			if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击准备...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//胜利结算
		if (clearing) {
			if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("战斗结算中...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				Log(_T("结算成功...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(281, 68, 430, 218, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("挑战失败...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//抽白票
		if (whitecard) {
			if (sn->FindPic(291, 454, 358, 505, _T("厕纸.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("十连抽取...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(526, 468, 638, 508, _T("再次召唤.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("再次召唤...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(294, 3, 349, 36, _T("白票0.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				Log(_T("白票用尽...\r\n"), game);
				break;
			}
		}
		if (challenge) {
			//点挑战  
			if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|永生之海挑战.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//随机偏移坐标防检测
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("识别到挑战，点击挑战...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(824, 437, 902, 505, _T("挑战业原火.bmp|挑战御灵.bmp|单刷永生挑战.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("识别到挑战，点击挑战...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(833, 412, 906, 458, _T("秘闻挑战.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("识别到挑战，点击挑战...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}

//超鬼王
//1.检测是否有鬼王
int InDependentFunction::CheckSuperGhostKing(int count, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//设置字库
	sn->UseDict(6);
	//定义局部变量
	long intX, intY;
	int countflag = 0;
	//检测疲劳值
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((sn->FindPic(817, 413, 899, 488, _T("超鬼王战斗.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)||(sn->FindStrFast(851, 477, 933, 505, _T("御香巡行"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1)) {
			if (sn->FindPic(865, 4, 916, 36, _T("未满疲劳.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("疲劳值未满，可以挑战...\r\n"), game);
				break;
			}
			if (sn->FindPic(865, 4, 916, 36, _T("满疲劳.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("疲劳值已满，等待中(5分钟检测一次)...\r\n"), game);
				int i = 100;
				while (i > 0) {
					if (DelayPlus(game, sn, 3000, 3010) == EXIT_THREAD) { return EXIT_THREAD; }
					i--;
				}
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//检测超鬼王 如果发现: return 1, 未发现：点击发现
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(817, 413, 899, 488, _T("超鬼王战斗.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (sn->FindPic(821, 488, 862, 526, _T("疲劳小人.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("发现超鬼王...\r\n"), game);
				if (countflag == 1) {
					count++;
					CString count_str;
					count_str.Format(_T("%d"), count);
					Log(_T("开始搜索第") + count_str + _T("只超鬼王...\r\n"), game);
					countflag = 0;
				}
				break;
			}
		}
		if (sn->FindPic(84, 110, 144, 179, _T("无鬼王.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			//检测是否有票
			if ((sn->FindPic(672, 5, 744, 36, _T("超鬼王0票.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&(sn->FindPic(667, 6, 748, 35, _T("超鬼王10票.bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1)) {
				Log(_T("没有发现超鬼王的材料,正在结束任务...\r\n"), game);
				return EXIT_THREAD;
			}
			if (sn->FindStrFast(851, 477, 933, 505, _T("御香巡行"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1) {
				sn->MoveClick(intX + 40, intY - 20);
				Log(_T("点击御香巡行...\r\n"), game);
				if (DelayPlus(game, sn, 2500, 4500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return count;
}
//2.检测星级
int InDependentFunction::CheckSuperGhostKingStar(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int star = -1;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测几星超鬼王 return star   ssr--星级颜色 D0712B-2F4528  sp C13DC6-3C3B37
		if (sn->FindColor(131, 165, 135, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 5;
			break;
		}
		else if (sn->FindColor(123, 165, 127, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 4;
			break;
		}
		else if (sn->FindColor(116, 165, 120, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 3;
			break;
		}
		else if (sn->FindColor(108, 164, 112, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 2;
			break;
		}
		else if (sn->FindColor(100, 163, 105, 169, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 1;
			break;
		}
		else if (sn->FindColor(91, 163, 97, 170, _T("D1713B-2D4538|C13DC6-3C3B37"), 0.98, 0, &intX, &intY) != 0) {
			star = 0;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return star;
}
//  2-1 是否播报遇到高星鬼王并停止
int InDependentFunction::IsStopAndAlert(int star, int star_stop, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (star_stop != 0) {
		if (star_stop == 1) {
			//5,6 star
			if (star == 4) {
				Log(_T("已发现5星超鬼王...\r\n"), game);
				sn->Play(_T("5star.mp3")); 
				if (DelayPlus(game, sn, 5000, 6000) == EXIT_THREAD) { return EXIT_THREAD; }
				return EXIT_THREAD;
			}
			else if (star == 5) {
				Log(_T("已发现6星超鬼王...\r\n"), game);
				sn->Play(_T("6star.mp3")); 
				if (DelayPlus(game, sn, 5000, 6000) == EXIT_THREAD) { return EXIT_THREAD; }
				return EXIT_THREAD;
			}
		}
		else if (star_stop == 2) {
			//6 star
			if (star == 5) {
				Log(_T("已发现6星超鬼王...\r\n"), game);
				sn->Play(_T("6star.mp3")); 
				if (DelayPlus(game, sn, 5000, 6000) == EXIT_THREAD) { return EXIT_THREAD; }
				return EXIT_THREAD;
			}
		}
	}
	return 0;
}
//  2-2 公开高星鬼王
int InDependentFunction::OpenHignStarSuperGhostKing(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//设置字库
	sn->UseDict(6);
	long intX, intY;
	Log(_T("准备公开鬼王...\r\n"), game);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(298, 466, 364, 511, _T("集结.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("点击集结...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 413, 426, 453, _T("公开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("已找到公开...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(335, 413, 426, 453, _T("公开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 5);
			Log(_T("点击公开...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 303, 587, 332, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("确认公开...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(817, 413, 899, 488, _T("超鬼王战斗.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("已公开...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//		2-2-1 等待鬼王被击败
int InDependentFunction::WaitSuperGhostKingKilled(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//设置字库
	sn->UseDict(6);
	long intX, intY;
	Log(_T("鬼王已公开，等待被击败...\r\n"), game);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(851, 477, 933, 505, _T("御香巡行"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1) {
			Log(_T("鬼王已被击败...\r\n"), game);
			break;
		}
		if (sn->FindPic(84, 110, 144, 179, _T("无鬼王.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("鬼王已被击败...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//3.检测血量
int InDependentFunction::CheckSuperGhostKingBlood(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//检测血量 return blood  满血386
	long blood_count = 0;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((blood_count = sn->GetColorNum(75, 170, 155, 188, _T("EC4642-13422F"), 0.95)) > 0) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return blood_count;
}
//4.点击挑战(include 强追)
int InDependentFunction::ClickChallenge(int star, int blood, int strenghCheck, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//设置字库
	sn->UseDict(6);
	//定义局部变量
	long intX, intY,bldsim;
	double bloodrate = (double)blood / (double)386;
	if (sn->FindPic(821, 488, 862, 526, _T("疲劳小人.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
		//通过血量与星级判断是否开启强追
		if (bloodrate >= 0.95) { bldsim = 100; }
		else bldsim = (int)(bloodrate * 100);
		CString ghost_state;
		ghost_state.Format(_T("%d星%d%%血超鬼王"), star + 1, bldsim);
		Log(_T("已发现") + ghost_state + _T("\r\n"), game);
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (strenghCheck) {
			if (star > 3) {
				if (bloodrate >= 0.7) {
					if (sn->FindPic(675, 451, 703, 480, _T("普通_强力攻击(空).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x + 10, pos.y + 10);
						Log(_T("点击强力攻击...\r\n"), game);
						if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(675, 488, 706, 518, _T("普通_强力攻击(空).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
						Log(_T("已选择强力攻击...\r\n"), game);
						break;
					}
				}
			}
		}
		if (!strenghCheck||star<=3|| bloodrate < 0.7) {
			if (sn->FindPic(675, 488, 706, 518, _T("普通_强力攻击(空).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x + 10, pos.y + 10);
				Log(_T("点击普通攻击...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(675, 451, 703, 480, _T("普通_强力攻击(空).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("已选择普通攻击...\r\n"), game);
				break;
			}
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(817, 413, 899, 488, _T("超鬼王战斗.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x + 18, pos.y + 23);
			Log(_T("点击战斗...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//7B6F62-585752
		if (sn->FindStrFast(86, 484, 115, 537, _T("加|成"), _T("7B6F62-585752"), 0.85, &intX, &intY) != -1) {
			Log(_T("进入战斗界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击挑战
	return 0;
}
//5.更换阵容
//  5.1选组&队
int InDependentFunction::selectgroup(int group, int team, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	switch (group)
	{
	case 0: {
		while (1) {
			//自动拒绝悬赏 198
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(103, 189, 116, 212, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第一组...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(68, 198);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
		break;
	}
	case 1: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(101, 238, 118, 260, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第二组...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(71, 247);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 2: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(95, 283, 115, 305, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第三组...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 293);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 3: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(98, 334, 117, 355, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第四组...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 341);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 4: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(98, 384, 117, 401, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第五组...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 390);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 5: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(99, 431, 117, 445, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第六组...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 435);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 6: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(94, 479, 118, 492, _T("F5CD86-040D1C"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第七组...\r\n"), game);
				break;
			}
			if (sn->FindPic(94,479,118,492, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(74, 483);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	default:
		break;
	}
	switch (team)
	{
	case 0: {
		Log(_T("不预设但进入预设，未知错误...\r\n"), game);
		break;
	}
	case 1: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 174, 151, 187, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第一队...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 192);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 2: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 265, 153, 277, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第二队...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 282);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 3: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 355, 153, 368, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第三队...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 372);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	case 4: {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindColor(140, 446, 153, 460, _T("9B8DF8-304605"), 0.95, 0, &intX, &intY) != 0) {
				Log(_T("已选择第四队...\r\n"), game);
				break;
			}
			if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(346, 462);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		break;
	}
	default:
		break;
	}
	return 0;
}
//  5.2 点击预设
int InDependentFunction::ClickPreset(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	sn->UseDict(6);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(86, 484, 115, 537, _T("加|成"), _T("7B6F62-585752"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(45, 510, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("点击预设...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入预设界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//  5.3 开始换阵容
int InDependentFunction::ChangeStaff(int star, int blood, int group[], int team[], int bloodsel[], snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int goattack = 0, not_presetflag = 0;
	//通过血量与星级判断阵容
	//F5CD86-040D1C
	for (int i = 0; i < 4; i++) {
		if (bloodsel[i] == 0) { bloodsel[i] = 50; }
		else if (bloodsel[i] == 1) { bloodsel[i] = 60; }
		else if (bloodsel[i] == 2) { bloodsel[i] = 70; }
	}
	double bloodrate = (double)blood / 386.0;
	int bloodrateh = (int)(bloodrate * 100);
	if (star < 3) {
		if (bloodrateh >= bloodsel[0]) {
			if (team[0] == 0) {
				Log(_T("已选择不预设...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[0], team[0], sn, game);
			}
		}
		else {
			if (team[1] == 0) {
				Log(_T("已选择不预设...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[1], team[1], sn, game);
			}
		}
	}
	else if (star == 3) {
		if (bloodrateh >= bloodsel[1]) {
			if (team[2] == 0) {
				Log(_T("已选择不预设...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[2], team[2], sn, game);
			}
		}
		else {
			if (team[3] == 0) {
				Log(_T("已选择不预设...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[3], team[3], sn, game);
			}
		}
	}
	else if (star == 4) {
		if (bloodrateh >= bloodsel[2]) {
			if (team[4] == 0) {
				not_presetflag = 1;
				Log(_T("已选择不预设...\r\n"), game);
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[4], team[4], sn, game);
			}
		}
		else {
			if (team[5] == 0) {
				Log(_T("已选择不预设...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[5], team[5], sn, game);
			}
		}
	}
	else if (star == 5) {
		if (bloodrateh >= bloodsel[3]) {
			if (team[6] == 0) {
				Log(_T("已选择不预设...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[6], team[6], sn, game);
			}
		}
		else {
			if (team[7] == 0) {
				Log(_T("已选择不预设...\r\n"), game);
				not_presetflag = 1;
			}
			else {
				ClickPreset(sn, game);
				selectgroup(group[7], team[7], sn, game);
			}
		}
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			goattack = 1;
			Log(_T("点击出战...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((not_presetflag == 1) && (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("已在准备界面...\r\n"), game);
			not_presetflag = 0;
			break;
		}
		if ((goattack == 1) && (sn->FindPic(267, 480, 362, 514, _T("超鬼王出战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
			Log(_T("出战成功...\r\n"), game);
			goattack = 0;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//出战对应阵容
	return 0;
}
//6.准备-结算
int InDependentFunction::EnterSuperGhostKingSection(int flag_own, int flag_boss, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//设置字库
	sn->UseDict(6);
	//定义局部变量
	long intX, intY;
	int markflag = 0, markflag2 = 0;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//标记式神
		if (flag_own && !markflag && sn->FindPic(154, 197, 252, 274, _T("活动标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("标记式神(左1)...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(205, 312, 1, 3);
			sn->MoveClick(205, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (flag_own && !markflag && sn->FindPic(154, 197, 252, 274, _T("活动标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("已标记我方式神...\r\n"), game);
			markflag = 1;
		}//标记boss
		if (flag_boss && !markflag2 && sn->FindPic(421, 60, 525, 161, _T("活动boss标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("已标记Boss...\r\n"), game);
			markflag2 = 1;
		}
		else if (flag_boss && !markflag2 && sn->FindPic(421, 60, 525, 161, _T("活动boss标记.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("标记Boss...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(470, 210, 1, 10);
			sn->MoveClick(470, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(284, 57, 422, 174, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(295, 45, 430, 160, _T("超鬼王胜利.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("挑战成功...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(892, 412, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 4000, 4500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(817, 413, 899, 488, _T("超鬼王战斗.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(851, 477, 933, 505, _T("御香巡行"), _T("C9BAA0-32323D"), 0.82, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//7.开始超鬼王
int InDependentFunction::StartSuperGhostKing(int round, int strenghCheck, int group[], int team[], int bloodsel[], int flag_own, int flag_boss, int star_stop, int star_public, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	int count = 0, star, blood;
	Log(_T("开始前请配置好预设队伍并进入御隐香寻(超鬼王)界面...\r\n"), game);
	while (count < round) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//发现鬼王
		if((count = CheckSuperGhostKing(count, sn, game)) == EXIT_THREAD){ return EXIT_THREAD; }
		//识别星级
		if ((star = CheckSuperGhostKingStar(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
		//是否停止
		if(IsStopAndAlert(star, star_stop, sn, game) == EXIT_THREAD){ return EXIT_THREAD; }
		//是否公开
		if (star_public && star >= 4) {
			//公开
			if (OpenHignStarSuperGhostKing(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//等鬼王被击败或逃跑
			if (WaitSuperGhostKingKilled(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else {
			//识别血量
			if ((blood = CheckSuperGhostKingBlood(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//点击挑战
			if (ClickChallenge(star, blood, strenghCheck, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//更换阵容
			if (ChangeStaff(star, blood, group, team, bloodsel, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//准备->结算
			if (EnterSuperGhostKingSection(flag_own, flag_boss, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//秘闻
int InDependentFunction::StartMiWen(snow *sn, Game *game, int round) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int count = 0;
	CString logmsg;
	Log(_T("开始前请进入对应的式神界面(并确认配置好默认阵容)...\r\n"), game);
	Log(_T("默认10轮...\r\n"), game);
	while (count < 10) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//点挑战  
			if (sn->FindPic(833, 412, 906, 458, _T("秘闻挑战.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("识别到挑战，点击挑战...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				logmsg.Format(_T("%d"), count + 1);
				Log(_T("第") + logmsg + _T("轮挑战开始...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//准备
			if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击准备...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//胜利结算
			if (sn->FindPic(282, 25, 430, 140, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("战斗结算中...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("领取奖励...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//点挑战  
			if (sn->FindPic(833, 412, 906, 458, _T("秘闻挑战.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= 10) {
		Log(_T("秘闻挑战任务已完成。\r\n"), game);
	}
	return 1;
}
//灵染试炼
int InDependentFunction::StartLingRan(snow *sn, Game *game, int round) {
	if (sn == NULL)
	{
		return 0;
	}
	//字库
	sn->UseDict(6);
	//定义局部变量
	long intX, intY;
	int count = 0;
	CString logmsg;
	Log(_T("开始前请进入活动挑战界面(并锁定阵容)...\r\n"), game);
	Log(_T("默认50轮...\r\n"), game);
	while (count < round) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//点挑战  2E2D2E-2E2D2E
			if (sn->FindStrFast(849, 438, 931, 484, _T("灵染挑战"), _T("2E2D2E-2E2D2E"), 0.85, &intX, &intY) != -1) {
				Log(_T("识别到挑战，点击挑战...\r\n"), game);
				if (DelayPlus(game, sn, 200, 50) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 10, 20);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				logmsg.Format(_T("%d"), count + 1);
				Log(_T("第") + logmsg + _T("轮灵染试炼开始...\r\n"), game);
				//使用字库
				sn->UseDict(6);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//胜利结算
			if (sn->FindPic(280, 79, 447, 216, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("战斗结算中...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}//BDAA6A-373A39
			if (sn->FindStrFast(414, 166, 541, 209, _T("得奖"), _T("BDAA6A-373A39"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("领取奖励...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//点挑战  
			if (sn->FindStrFast(849, 438, 931, 484, _T("灵染挑战"), _T("2E2D2E-2E2D2E"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (count >= 50) {
		Log(_T("灵染试炼任务已完成。\r\n"), game);
	}
	return 1;
}
/*
					  .::::.
					 .::::::::.
					:::::::::::
				 ..:::::::::::'
			  '::::::::::::'
				.::::::::::
		   '::::::::::::::..
				..::::::::::::.
			  ``::::::::::::::::
			   ::::``:::::::::'        .:::.
			  ::::'   ':::::'       .::::::::.
			.::::'      ::::     .:::::::'::::.
		   .:::'       :::::  .:::::::::' ':::::.
		  .::'        :::::.:::::::::'      ':::::.
		 .::'         ::::::::::::::'         ``::::.
	 ...:::           ::::::::::::'              ``::.
	```` ':.          ':::::::::'                  ::::..
					   '.:::::'                    ':'````..
*/