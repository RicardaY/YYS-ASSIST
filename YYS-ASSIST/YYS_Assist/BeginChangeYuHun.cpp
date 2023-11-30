#include "pch.h"
#include "BeginChangeYuHun.h"
#define EXIT_THREAD -10
//莫愁前路无知己，天下谁人不识君。
//选择分组
int BeginChangeYuHun::SelectGroup(CPoint clickXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	if (sn->FindPic(540, 56, 647, 105, _T("队伍预设.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		AutoRejectXS(sn, game);
		if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		CPoint posx = sn->RandomOffsetPos(clickXY.x, clickXY.y, -20, 20);
		CPoint posy = sn->RandomOffsetPos(clickXY.x, clickXY.y, -10, 10);
		sn->MoveClick(posx.x, posy.y);
		if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		sn->MoveClick(posx.x, posy.y);
		if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//预设御魂  
int BeginChangeYuHun::StartChangeYuHun(long hd, int group, int team, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (team == 0) {
		return 0;
	}
	//设置字库
	sn->UseDict(0);
	long intX, intY;
	CPoint clickXY;
	CString team_str;
	team_str.Format(_T("更换%d.bmp"), team);
	Log(_T("正在更换御魂预设...\r\n"), game);
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
	//点击式神录  830,490,887,515,
	Log(_T("点击式神录...\r\n"), game);
	while (1) {
		AutoRejectXS(sn, game);
		if (sn->FindStrFast(819, 480, 889, 511, _T("式|神|录"), _T("C0B7AD-242828"), 0.8, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY - 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击预设
	Log(_T("点击预设...\r\n"), game);
	while (1) {
		AutoRejectXS(sn, game);
		if (sn->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(540, 56, 647, 105, _T("队伍预设.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击分组group
	Log(_T("选择预设分组...\r\n"), game);
	switch (group)
	{
	case 0: {//877，87
		clickXY.x = 877, clickXY.y = 87;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 1: {
		clickXY.x = 877, clickXY.y = 140;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 2: {
		clickXY.x = 877, clickXY.y = 194;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 3: {
		clickXY.x = 877, clickXY.y = 246;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 4: {
		clickXY.x = 877, clickXY.y = 300;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 5: {
		clickXY.x = 877, clickXY.y = 352;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 6: {
		clickXY.x = 877, clickXY.y = 404;
		SelectGroup(clickXY, sn, game);
		break;
	}
	default:
		break;
	}
	//点击队伍team
	Log(_T("选择预设队伍...\r\n"), game);
	int y1, y2;
	switch (team)
	{
	case 1: {
		y1 = 107, y2 = 141;
		break;
	}
	case 2: {
		y1 = 222, y2 = 253;
		break;
	}
	case 3: {
		y1 = 334, y2 = 367;
		break;
	}
	case 4: {
		y1 = 447, y2 = 470;
		break;
	}
	default:
		break;
	}
	int i = 3;
	while (i>0) {
		AutoRejectXS(sn, game);
		if (sn->FindPic(724, y1, 757, y2, team_str, _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//退出式神录  是否庭院界面？return:继续判断
	Log(_T("预设完成，退出式神录...\r\n"), game);
	while (1) {
		AutoRejectXS(sn, game);
		if (sn->FindPic(12, 1, 55, 40, _T("返回8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsInYard(sn, game)) {
			break;
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//预设两组御魂
int BeginChangeYuHun::StartChangeYuHunDouble(long hd, int group, int team1, int team2, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//设置字库
	sn->UseDict(0);
	if ((team1 == 0) && (team2 == 0)) {
		return 0;
	}
	long intX, intY;
	CPoint clickXY;
	CString team1_str, team2_str;
	team1_str.Format(_T("更换%d.bmp"), team1);
	team2_str.Format(_T("更换%d.bmp"), team2);
	Log(_T("正在更换御魂预设...\r\n"), game);
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
	//点击式神录
	Log(_T("点击式神录...\r\n"), game);
	while (1) {
		AutoRejectXS(sn, game);
		if (sn->FindStrFast(819, 480, 889, 511, _T("式|神|录"), _T("C0B7AD-242828"), 0.8, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击预设
	Log(_T("点击预设...\r\n"), game);
	while (1) {
		AutoRejectXS(sn, game);
		if (sn->FindPic(242, 49, 326, 97, _T("预设.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(540, 56, 647, 105, _T("队伍预设.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击分组group
	Log(_T("选择预设分组...\r\n"), game);
	switch (group)
	{
	case 0: {//877，87
		clickXY.x = 877, clickXY.y = 87;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 1: {
		clickXY.x = 877, clickXY.y = 140;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 2: {
		clickXY.x = 877, clickXY.y = 194;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 3: {
		clickXY.x = 877, clickXY.y = 246;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 4: {
		clickXY.x = 877, clickXY.y = 300;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 5: {
		clickXY.x = 877, clickXY.y = 352;
		SelectGroup(clickXY, sn, game);
		break;
	}
	case 6: {
		clickXY.x = 877, clickXY.y = 404;
		SelectGroup(clickXY, sn, game);
		break;
	}
	default:
		break;
	}
	//点击队伍team
	Log(_T("选择预设队伍...\r\n"), game);
	int y1, y2, y21, y22;
	switch (team1)
	{
	case 1: {
		y1 = 107, y2 = 141;
		break;
	}
	case 2: {
		y1 = 222, y2 = 253;
		break;
	}
	case 3: {
		y1 = 334, y2 = 367;
		break;
	}
	case 4: {
		y1 = 447, y2 = 470;
		break;
	}
	default:
		break;
	}
	switch (team2)
	{
	case 1: {
		y21 = 107, y22 = 141;
		break;
	}
	case 2: {
		y21 = 222, y22 = 253;
		break;
	}
	case 3: {
		y21 = 334, y22 = 367;
		break;
	}
	case 4: {
		y21 = 447, y22 = 470;
		break;
	}
	default:
		break;
	}
	int i = 3;
	int teamFlag1 = 0, teamFlag2 = 0;
	if (!team1) {
		teamFlag1++;
	}
	if (!team2) {
		teamFlag1++;
	}
	while (i > 0) {
		AutoRejectXS(sn, game);
		if (team1&&sn->FindPic(722, y1, 765, y2, team1_str, _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			teamFlag1++;
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (team2&&sn->FindPic(722, y21, 765, y22, team2_str, _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			teamFlag2++;
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			if ((teamFlag1 == 1)&&(teamFlag2 == 1)) {
				break;
			}
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//退出式神录  是否庭院界面？return:继续判断
	Log(_T("预设完成，退出式神录...\r\n"), game);
	while (1) {
		AutoRejectXS(sn, game);
		if (sn->FindPic(12, 1, 55, 40, _T("返回8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsInYard(sn, game)) {
			break;
		}
		if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
