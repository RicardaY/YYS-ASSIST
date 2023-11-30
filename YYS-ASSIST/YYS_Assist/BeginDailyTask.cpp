#include "pch.h"
#include "BeginDailyTask.h"

#define EXIT_THREAD -10
BeginDailyTask::BeginDailyTask() {
	softwind = 1;
	origin_state = 0;
	cruel = 0;
}
//----妖气封印----
//选层	博观而约取，厚积而薄发。
int BeginDailyTask::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	
	//获取目标位置
	CString bmp_font = _T("跳跳哥哥.bmp|椒图.bmp|骨女.bmp|饿鬼.bmp|二口女.bmp|海坊主.bmp|鬼使黑.bmp|小松丸.bmp|日和坊.bmp");
	CString color_format = _T("424243-434243");
	double sim = 0.75;
	int dictId = 2;
	//start 选择层
	Log(_T("选择妖气封印妖怪...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("跳跳哥哥.bmp|跳跳哥哥(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("椒图.bmp|椒图(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("骨女.bmp|骨女(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("饿鬼.bmp|饿鬼(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("二口女.bmp|二口女(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("海坊主.bmp|海坊主(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("鬼使黑.bmp|鬼使黑(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("小松丸.bmp|小松丸(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("日和坊.bmp|日和坊(选中).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
int BeginDailyTask::EnterYaoQiFengYin(int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	sn->UseDict(0);
	int closingflag = 0;
	//自动匹配
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点击组队
		if (sn->FindStrFast(264, 488, 377, 523, _T("组队"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("点击组队...\r\n"), game);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
		}
		//点击自动匹配
		if (sn->FindPic(517, 443, 665, 495, _T("自动匹配.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("排队中...\r\n"), game);
		}
		//若自己成为房主，点挑战
		if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (condition==0) {
				Log(_T("自己成为房主，点击挑战...\r\n"), game);
				//随机偏移坐标防检测
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (condition == 1) {
				Log(_T("成为房主，正在退出返回庭院...\r\n"), game);
				if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}
		//点准备
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//胜利结算
		if (sn->FindPic(286, 34, 438, 169, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(388, 372, 567, 456, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(388, 372, 567, 456, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//开始妖气
int BeginDailyTask::StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//判断是否在庭院
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//退出线程
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("很抱歉，未找到组队按钮...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择妖气封印
	//获取目标位置
	CString fontLst = _T("困难|业火|风转|水灵|天雷|御魂|日轮|永生|妖气|经验|金币|年兽|石距|结界|对弈|回归");
	CString color_format = _T("454039-46413A");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//找到妖气封印并点击
	findDestSite(startXY, endXY, fontLst, 8, _T("妖气"), color_format, 0.8, 2, sn, game, _T("findstr"), _T("印|CFC8B8-292B28"));
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(monsterKind, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("未找到目标!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入妖气封印副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮妖气封印开始...\r\n"), game);
		if(EnterYaoQiFengYin(condition, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
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
//----六道之门----
//计算时间差值
CString BeginDailyTask::GetElapsedTimeString(const CTime& startTime, const CTime& endTime)
{
	CTimeSpan elapsedTime = endTime - startTime;

	int minutes = elapsedTime.GetMinutes();
	int seconds = elapsedTime.GetSeconds();

	CString elapsedTimeString;
	elapsedTimeString.Format(_T("[%02d 分 %02d 秒]."), minutes, seconds);

	return elapsedTimeString;
}
//寻找月之海
int BeginDailyTask::FindSeaOfMoon(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(1);
	//定义局部变量
	long intX, intY;
	Log(_T("寻找六道之门...\r\n"), game);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//结界突破 174,512,245,538，
		if (sn->FindStrFast(690, 513, 763, 538, _T("六道"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("找到六道之门...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//契灵版六道位置
		if (sn->FindStrFast(614, 514, 689, 534, _T("六道"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("找到六道之门...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(62, 11, 173, 46, _T("六道之门.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("成功进入六道之门...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	sn->UseDict(5);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		
		if (sn->FindStrFast(256, 114, 285, 201, _T("月之海"), _T("CDCCC1-32333E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("找到月之海...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("成功进入月之海\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.2 开启月之海
int BeginDailyTask::OpenSeaOfMoon(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	//定义局部变量
	long intX, intY;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(844, 435, 912, 505, _T("月之海开启.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("开启月之海...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPicSim(844, 424, 935, 508, _T("月之海确定.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("确定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPicSim(853, 425, 920, 503, _T("月之海开启60t.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("确定开启...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(539, 309, 599, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("确定消耗60体...\r\n"), game);
			sn->MoveClick(intX + 10, intY + 13);
			if (DelayPlus(game, sn, 1800, 2500) == EXIT_THREAD) { return EXIT_THREAD; };
		}
		if (sn->FindPicSim(828, 16, 897, 55, _T("跳过月之海.bmp"), _T("202020"), 85, 0, &intX, &intY) != -1) {
			Log(_T("跳过...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 6);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(523, 301, 591, 332, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("确认跳过剧情...\r\n"), game);
			sn->MoveClick(intX + 10, intY + 10);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(188, 243, 762, 286, _T("柔风抱暖"), _T("B3AEA7-464640"), 0.8, &intX, &intY) != -1) {//A7A19B-4F5049
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(188, 243, 762, 286, _T("柔风抱暖"), _T("B3AEA7-464640"), 0.8, &intX, &intY) != -1) {
			if (sn->FindStrFast(intX - 60, 430, intX + 100, 465, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {//CAC7B5-2E2C2B
				Log(_T("选择柔风抱暖...\r\n"), game);
				sn->MoveClick(intX + 10, intY + 10);
				if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CString str;
			str.Format(_T("%d"), softwind);
			Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.3 随机点击并识别事件 193,296   495,330    761,270
int BeginDailyTask::RadomSelectAndCheckEvent(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	Log(_T("随机选取关卡中...\r\n"), game);
	//定义局部变量
	long intX, intY;
	Scene scene;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

		if (sn->FindStrFast(8, 143, 941, 463, _T("战|星|神|秘|宁|混"), _T("E4DBBC-172021"), 0.8, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(827, 0, 888, 47, _T("误入地图.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("误入地图，点击返回...\r\n"), game);
			if (sn->FindPic(0, 0, 48, 54, _T("月之海返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击返回...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}

		}
		//4A3821-4B3921
		if (sn->FindStrFast(543, 311, 595, 339, _T("进入"), _T("4A3821-4B3921"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(506, 226, 548, 247, _T("召唤"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 311, 417, 337, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("取消召唤...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(69, 12, 131, 48, _T("鏖战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入鏖战之屿...\r\n"), game);
			scene = BATTLE;
			break;
		}
		//神秘
		if (sn->FindPic(69, 13, 129, 45, _T("神秘.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入神秘之屿...\r\n"), game);
			scene = MYSTERY;
			break;
		}
		//混沌
		if (sn->FindPic(62, 10, 132, 48, _T("混沌.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入混沌之屿...\r\n"), game);
			scene = ORIGIN;
			break;
		}

		//宁息  
		if (sn->FindPic(64, 13, 133, 44, _T("宁息.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入宁息之屿...\r\n"), game);
			scene = SILENCE;
			break;
		}
		//星之屿 
		if (sn->FindPic(68, 10, 152, 45, _T("星之屿.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入星之屿...\r\n"), game);
			scene = ISLANDOFSTAR;
			break;
		}
		//月读 
		if (sn->FindPic(68, 11, 173, 48, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("发现月晓星征...\r\n"), game);
			scene = BOSS;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return scene;
}
//	1.3.1 鏖战
int BeginDailyTask::Battle(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;

	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.点击右侧技能怪[635,255]
		if (sn->FindPic(69, 12, 131, 48, _T("鏖战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPicSim(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 90, 0, &intX, &intY) == -1) {
				Log(_T("点击右侧技能怪...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(635, 255, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPicSim(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//锁定阵容
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.点击右侧技能怪[635,255]
		if (sn->FindPic(710, 494, 751, 533, _T("月之海解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("月之海锁定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击挑战 -- 战斗--结算
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("点击挑战...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//2.选技能
	//2.1 检测是否需要刷新
	CPoint ishaveAddState = FindBuff(_T("加成"), sn, game);
	if (ishaveAddState.x != 0) {
		BattleSelectBuff(sn, game);
	}
	else {
		SelectBuff(sn, game);
	}
	return 0;
}
//	1.3.2 神秘
int BeginDailyTask::Mystery(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int imitationorchange = 0;
	//使用字库
	sn->UseDict(5);
	//判断仿造还是转换
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(875, 458, 940, 528, _T("仿造(暗).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("神秘--仿造...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(623, 136, 636, 153, _T("5"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 2;
				Log(_T("柔风5级，不仿造...\r\n"), game);
				break;
			}
			/*else if (sn->FindStrFast(623, 136, 636, 153, _T("5"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) == -1) {
				imitationorchange = 1;
				break;
			}*/
			else if (sn->FindStrFast(623, 136, 636, 153, _T("1|2|3|4"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 1;
				Log(_T("柔风不满5级，可以仿造...\r\n"), game);
				break;
			}
		}
		else if (sn->FindPicSim(723, 485, 782, 526, _T("转换(暗).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			imitationorchange = 2;
			Log(_T("神秘--转换...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (imitationorchange == 2) {
		//退出
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(69, 13, 129, 45, _T("神秘.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("月之海返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("退出神秘之屿...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("确定离开...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("回到月之海\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("检测到月晓星征\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (imitationorchange == 1) {
		//仿造
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

			if (sn->FindPicSim(619, 130, 681, 191, _T("仿造柔风.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("点击柔风...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPicSim(187, 57, 256, 122, _T("柔风(弹出).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("已点击柔风...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPicSim(874, 459, 943, 525, _T("仿造(明).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("点击仿造...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("确定仿造...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(433, 99, 527, 153, _T("造|成"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//434,99,525,155, D4C78C-2B3649
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("仿造成功...\r\n"), game);
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("回到月之海\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("检测到月晓星征\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 0;
}
//	1.3.3 混沌
int BeginDailyTask::Origin(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	//定义局部变量
	long intX, intY;
	State scene_state;
	//判断宝箱or战斗
	if (sn->FindPic(457, 196, 492, 294, _T("幸运宝匣.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		scene_state = TREASURE;
		origin_state = TREASURE;
	}
	else if (sn->FindStrFast(452, 145, 491, 190, _T("精|英"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {//DFD8CC-202733
		scene_state = ELITE;
	}
	//1.1宝箱--领取/不领？
	if (scene_state == TREASURE) {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(457, 196, 492, 294, _T("幸运宝匣.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击幸运宝匣...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(846, 436, 924, 518, _T("开启幸运宝匣.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击幸运宝匣...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(398, 91, 526, 149, _T("获奖"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("回到月之海\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("检测到月晓星征\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	if (scene_state == ELITE) {
		//1.2战斗--进入
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.点击右侧技能怪[635,255]
			if (sn->FindStrFast(452, 145, 491, 190, _T("精|英"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {
				Log(_T("点击精英怪...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//锁定阵容
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.点击右侧技能怪[635,255]
			if (sn->FindPic(710, 494, 751, 533, _T("月之海解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("锁定阵容...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(710, 494, 751, 533, _T("月之海锁定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点挑战
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击挑战...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//2.选技能
		SelectBuff(sn, game);
	}
	return 0;
}
//	1.3.4 宁息
int BeginDailyTask::Silence(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//使用字库
	sn->UseDict(5);
	//退出
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(877, 434, 941, 497, _T("离开宁息.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("离开宁息之屿...\r\n"), game);
			if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(506, 226, 548, 247, _T("召唤"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 311, 417, 337, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("取消召唤...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("确定离开...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("回到月之海\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("检测到月晓星征\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//	1.3.5 星之屿
int BeginDailyTask::IslandOfStar(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	//定义局部变量
	long intX, intY;
	int refresh = 0;
	CPoint buffLoc_xy;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(537, 173, 564, 203, _T("危"), _T("C9BBBC-364443"), 0.85, &intX, &intY) != -1) {//C9BBBC-364443
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("检测到星之子...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//锁定阵容
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.点击右侧技能怪[635,255]
		if (sn->FindPic(710, 494, 751, 533, _T("月之海解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("月之海锁定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点挑战
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击挑战...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//2. 选技能2/1
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		buffLoc_xy = FindBuff(_T("攻击御守|火之卷"), sn, game);
		if (buffLoc_xy.x != 0) {//找到攻击御守--选择
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("选择御守or卷轴\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				refresh = 0;
			}
		}
		else {//未找到攻击御守--刷新
			if (sn->FindPic(818, 3, 950, 50, _T("万相铃0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("没有万相铃...\r\n"), game);
				refresh = 3;
			}
			if (sn->FindPic(468, 7, 509, 39, _T("buff2_1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("月之海刷新.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
					//用万相铃刷新  
					Log(_T("刷新buff\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x + 5, pos.y + 8);
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh++;
				}
			}
		}
		//刷新完仍未找到
		if ((refresh >= 3) || (sn->FindPic(877, 454, 945, 512, _T("月之海刷新(尽).bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)) {
			buffLoc_xy = FindBuff(_T("攻击御守"), sn, game);
			//选择月赐之福
			if (sn->FindPic(462, 8, 516, 39, _T("buff2_1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (buffLoc_xy.x == 0 && sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("选择[月赐之福]\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh = 0;
				}
			}
		}
		if (sn->FindStrFast(511, 298, 601, 335, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("确认刷新...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(468, 7, 509, 39, _T("buff2_2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//  选技能2/2
	SelectBuff(sn, game);
	return 0;

}
//1.4 选buff
//1.4.1 抽象出方法
CPoint BeginDailyTask::FindBuff(CString buffname, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	long intX, intY;
	CString findname = _T("柔风抱暖|六道暴虐|妖力化身|细雨化屏");
	CString defendandScroll = _T("攻击御守|火之卷");
	CPoint bufflocXY(0, 0);
	int i = 5, buffcode = -1;
	while (i > 0) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((buffcode = sn->FindStrFast(110, 246, 212, 285, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("找到[") + buffname + _T("]\r\n"), game);
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Mid(5, 4) + _T("]\r\n"), game);
					break;
				}
				case 2: {
					Log(_T("找到[") + buffname.Mid(10, 4) + _T("]\r\n"), game);
					break;
				}
				case 3: {
					Log(_T("找到[") + buffname.Right(4) + _T("]\r\n"), game);
					break;
				}
				default:
					break;
				}
			}
			else if (buffname == defendandScroll) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Right(3) + _T("]\r\n"), game);
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		else if ((buffcode = sn->FindStrFast(315, 246, 418, 284, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("找到[") + buffname + _T("]\r\n"), game);
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Mid(5, 4) + _T("]\r\n"), game);
					break;
				}
				case 2: {
					Log(_T("找到[") + buffname.Mid(10, 4) + _T("]\r\n"), game);
					break;
				}
				case 3: {
					Log(_T("找到[") + buffname.Right(4) + _T("]\r\n"), game);
					break;
				}
				default:
					break;
				}
			}
			else if (buffname == defendandScroll) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Right(3) + _T("]\r\n"), game);
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		else if ((buffcode = sn->FindStrFast(515, 246, 626, 282, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("找到[") + buffname + _T("]\r\n"), game);
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Mid(5, 4) + _T("]\r\n"), game);
					break;
				}
				case 2: {
					Log(_T("找到[") + buffname.Mid(10, 4) + _T("]\r\n"), game);
					break;
				}
				case 3: {
					Log(_T("找到[") + buffname.Right(4) + _T("]\r\n"), game);
					break;
				}
				default:
					break;
				}
			}
			else if (buffname == defendandScroll) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Right(3) + _T("]\r\n"), game);
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return bufflocXY;
}
//1.4.2 通用选buff
int BeginDailyTask::SelectBuff(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	int refresh = 0, buff_res = -1;
	//----------椒图-----------
	//优先级：柔风抱暖>六道暴虐>妖力化身>细雨化屏>月赐之福(恢复5%血量)
	// -- 选技能测试 --
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找柔风
		buffLoc_xy = FindBuff(_T("柔风抱暖"), sn, game);
		//找到柔风--选择柔风
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("选择技能\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
				refresh = 0;
			}
		}//未找到柔风
		else {
			if (softwind < 3) {//柔风<3级 -- 刷新
				if (sn->FindPic(818, 3, 950, 50, _T("万相铃0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
					refresh = 3;
				}
				if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("月之海刷新.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
					//用万相铃刷新
					Log(_T("刷新buff\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x + 5, pos.y + 8);
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh++;
				}
			}
			else if (softwind >= 3) {//柔风>3级 -- 找所有 找到：选择  
				buffLoc_xy = FindBuff(_T("柔风抱暖|六道暴虐|妖力化身|细雨化屏"), sn, game);
				if (buffLoc_xy.x != 0) {
					if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("选择技能\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						refresh = 0;
					}
				}
				else {//找不到：刷新
					if (sn->FindPic(818, 3, 950, 50, _T("万相铃0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
						refresh = 3;
					}
					if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("月之海刷新.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
						//用万相铃刷新
						Log(_T("刷新buff\r\n"), game);
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x + 5, pos.y + 8);
						refresh++;
						if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
			}
		}
		//刷新完仍未找到
		if ((refresh >= 3) || (sn->FindPic(877, 454, 945, 512, _T("月之海刷新(尽).bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)) {
			buffLoc_xy = FindBuff(_T("柔风抱暖|六道暴虐|妖力化身|细雨化屏"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("选择技能\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh = 0;
				}
			}
			//选择月赐之福
			else if (buffLoc_xy.x == 0 && sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				Log(_T("选择[月赐之福]\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				refresh = 0;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(511, 298, 601, 335, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("确认刷新...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (sn->FindStrFast(398, 91, 526, 149, _T("获奖"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//D4C78C-2B3649  441,90,527,150,
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("回到月之海\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("检测到月晓星征\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.4.3 鏖战选低级buff
int BeginDailyTask::BattleSelectBuff(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	//----------椒图-----------
	//优先级：柔风抱暖>六道暴虐>妖力化身>细雨化屏>月赐之福(恢复5%血量)
	// -- 选技能测试 --
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找柔风
		buffLoc_xy = FindBuff(_T("柔风抱暖"), sn, game);
		//找到柔风--选择柔风
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("选择技能\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
			}
		}//未找到柔风
		else {
			//--找其他(include softwind)
			buffLoc_xy = FindBuff(_T("柔风抱暖|六道暴虐|妖力化身|细雨化屏"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("选择技能\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}//未找到其他--recover blood
			else {
				//选择月赐之福
				if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("选择[月赐之福]\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (sn->FindStrFast(398, 91, 526, 149, _T("获奖"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("回到月之海\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("检测到月晓星征\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.5 迎战月读
int BeginDailyTask::ToWardsTsukuyomi(snow *sn, Game *game) {
	//
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int ispack = 0, defentusexy = 0, defentusexx = 0, fireScrollxy = 0, fireScrollxx = 0;
	CString violence, finerain, demonpower;
	violence = _T("技能暴虐12_31_32_33.bmp|技能暴虐13_14_34.bmp|技能暴虐21.bmp|技能暴虐22.bmp|技能暴虐23_24.bmp");
	finerain = _T("技能细雨12_13_14_31_32_33_34.bmp|技能细雨21_22_23_24.bmp");
	demonpower = _T("技能妖力12.bmp|技能妖力13.bmp|技能妖力14_33.bmp|技能妖力21.bmp|技能妖力22.bmp|技能妖力23.bmp|技能妖力24.bmp|技能妖力31_32.bmp|技能妖力34.bmp");

	//使用字库
	sn->UseDict(5);
	//判断是否备战换技能
	if (origin_state == TREASURE) {
		//备战
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; } //BDB6A8-31323E
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPicSim(635, 463, 685, 518, _T("备战.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("点击备战...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindPicSim(61, 9, 139, 53, _T("月之海备战.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("已进入备战界面...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//进入技能装配界面
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(752, 331, 803, 377, _T("换buff.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("技能装配...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(64, 10, 177, 51, _T("技能装配.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("已进入技能装配界面...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//技能重置
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(523, 471, 571, 520, _T("重置.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("技能重置...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(528, 303, 587, 332, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//确认重置
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(528, 303, 587, 332, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("确认重置...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(64, 10, 177, 51, _T("技能装配.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("重置成功...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//装配技能 柔风抱暖
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
				if (sn->FindPicSim(604, 53, 927, 311, _T("技能柔风.bmp|技能柔风2.bmp"), _T("202020"), 85, 0, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("装入柔风抱暖...\r\n"), game);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("确认装备...\r\n"), game);
				ispack = 1;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
				ispack = 0;
				break;
			}
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//六道暴虐
		if (sn->FindPic(604, 53, 927, 311, violence, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
					if (sn->FindPicSim(604, 53, 927, 311, violence, _T("202020"), 85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("装入六道暴虐...\r\n"), game);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("确认装备...\r\n"), game);
					ispack = 1;
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
					if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
					ispack = 0;
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		else { Log(_T("未发现六道暴虐...\r\n"), game); }
		//细雨化屏
		if (sn->FindPic(604, 53, 927, 311, finerain, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
					if (sn->FindPicSim(604, 53, 927, 311, finerain, _T("202020"), 85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("装入细雨化屏...\r\n"), game);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("确认装备...\r\n"), game);
					ispack = 1;
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
					if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
					ispack = 0;
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		else { Log(_T("未发现细雨化屏...\r\n"), game); }
		//妖力化身
		if (sn->FindPic(604, 53, 927, 311, demonpower, _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
					if (sn->FindPicSim(604, 53, 927, 311, demonpower, _T("202020"), 85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("装入妖力化身...\r\n"), game);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("确认装备...\r\n"), game);
					ispack = 1;
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("装备"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
					if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
					ispack = 0;
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		else { Log(_T("未发现妖力化身...\r\n"), game); }
		//返回月晓星征
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(64, 10, 177, 51, _T("技能装配.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("月之海返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("返回备战界面...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindPicSim(61, 9, 139, 53, _T("月之海备战.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("月之海返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("返回月晓星征...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("成功返回月晓星征...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		origin_state = 0;
	}
	//挑战月读
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(844, 427, 928, 511, _T("月读挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("挑战月读...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		/*if (sn->FindPic(851, 6, 928, 35, _T("跳过月读.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("跳过...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}*/
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//开御守
		if (sn->FindPic(240, 0, 302, 57, _T("男月读.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (defentusexy < 1 && sn->FindPic(719, 69, 862, 130, _T("攻击御守.bmp|攻击御守2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("使用攻击御守...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				defentusexy++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (fireScrollxy < 1 && sn->FindPic(723, 73, 850, 125, _T("火之卷.bmp|火之卷2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("使用火之卷...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				fireScrollxy++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(240, 0, 302, 57, _T("女月读.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (defentusexx < 1 && sn->FindPic(719, 69, 862, 130, _T("攻击御守.bmp|攻击御守2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("使用攻击御守...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				defentusexx++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (fireScrollxx < 1 && sn->FindPic(719, 69, 862, 130, _T("火之卷.bmp|火之卷2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("使用火之卷...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				fireScrollxx++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//不购买万象祈福  433C34-433C34
		if (sn->FindStrFast(439, 260, 477, 281, _T("不再"), _T("433C34-433C34"), 0.85, &intX, &intY) != -1) {
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(407, 256, 463, 284, _T("不再提醒.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("不再提醒...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(405, 253, 437, 286, _T("不再提醒(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(405, 253, 437, 286, _T("不再提醒(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 312, 416, 337, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("取消购买...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//挑战失败
		if (sn->FindStrFast(519, 311, 571, 337, _T("放弃"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("挑战失败，放弃前行...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(529, 305, 583, 329, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			Log(_T("确定放弃...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(510, 318, 588, 350, _T("使用"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("确定使用1个万相赐福...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(411, 93, 539, 170, _T("得奖"), _T("C8BA87-373844"), 0.85, &intX, &intY) != -1) {//C8BA87-373844
			Log(_T("获得奖励...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(438, 88, 535, 129, _T("等级提升.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("等级提升...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(467, 95, 579, 149, _T("技能解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("技能解锁...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(422, 466, 515, 511, _T("前往查看.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入下一界面...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(488, 463, 538, 507, _T("前往查看(右).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入下一界面...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(812, 440, 876, 517, _T("分享.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPic(71, 92, 218, 214, _T("月之海_极.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("获得评分：极\r\n"), game);
				extream++;	//记录极次数
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(71, 92, 218, 214, _T("月之海_特.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("获得评分：特\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			Log(_T("进入下一界面...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(649, 150, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(844, 435, 912, 505, _T("月之海开启.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("成功返回初始界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.6 根据场景执行任务
int BeginDailyTask::AccordingSceneRun(int scene, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//鏖战之屿
	if (scene == BATTLE) {
		if (Battle(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//神秘
	if (scene == MYSTERY) {
		if (Mystery(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//混沌
	if (scene == ORIGIN) {
		if (Origin(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//宁息  
	if (scene == SILENCE) {
		if (Silence(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//星之屿 
	if (scene == ISLANDOFSTAR) {
		if (IslandOfStar(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//月读 
	if (scene == BOSS) {
		if (ToWardsTsukuyomi(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return scene;
}
//2.0 开始任务 正常阵容
int BeginDailyTask::StartSixPathOfDoor(long hd, int round, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	int scene;
	Log(_T("开始前请在庭院界面启动...\r\n"), game);
	Log(_T("开始前请确保配置好阵容...\r\n"), game);
	Log(_T("开始前请确保已选择椒图...\r\n"), game);
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
	//1.寻
	if (FindSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	CString count_str;
	int scene_res = -1;
	extream = 0;
	while (count < round) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮月之海探索...\r\n"), game);
		//开始时间
		CTime startTime = CTime::GetCurrentTime();
		//初始化柔风记录
		softwind = 1;
		//2.开启月之海
		if (OpenSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//3.随机选择场景
			if ((scene = RadomSelectAndCheckEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//4.根据场景执行任务
			if ((scene_res = AccordingSceneRun(scene, sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//退出条件
			if (scene_res == BOSS) {
				scene_res = -1;
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		count_str.Format(_T("%d"), count);
		Log(_T("已进行") + count_str + _T("轮月之海探索\r\n"), game);
		count_str.Format(_T("%d"), extream);
		Log(_T("共获得评分极") + count_str + _T("次\r\n"), game);
		//结束时间
		CTime endTime = CTime::GetCurrentTime();
		//耗时
		CString elapsedTimeString = GetElapsedTimeString(startTime, endTime);
		Log(_T("本局耗时") + elapsedTimeString + _T("\r\n"), game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//返回庭院
	if (count >= round) {
		SixPathOfDoorReturnYard(sn, game);
	}

	return 0;
}
//六道之门返回庭院
int BeginDailyTask::SixPathOfDoorReturnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(0);
	//定义局部变量
	long intX, intY;
	//开始返回
	Log(_T("任务已完成，正在返回庭院...\r\n"), game);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(0, 0, 48, 54, _T("月之海返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击返回...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(16, 9, 60, 49, _T("契灵返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(15, 13, 73, 72, _T("返回1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//760, 83, 814, 135,
		if (sn->FindPic(9, 18, 61, 76, _T("返回5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 1, 65, 59, _T("返回4.bmp|返回8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("成功返回庭院！\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//----六道之门(4柔风阵容)----
//	1.3.12 鏖战
int BeginDailyTask::BattleOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.点击右侧技能怪[635,255]
		if (sn->FindPic(69, 12, 131, 48, _T("鏖战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPicSim(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 90, 0, &intX, &intY) == -1) {
				Log(_T("点击右侧技能怪...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(635, 255, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPicSim(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//锁定阵容
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.点击右侧技能怪[635,255]
		if (sn->FindPic(710, 494, 751, 533, _T("月之海解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("月之海锁定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击挑战 -- 战斗--结算
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("点击挑战...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//2.选技能
	//2.1 检测是否需要刷新
	CPoint ishaveAddState = FindBuffOnlySoftWind(_T("加成"), sn, game);
	if (ishaveAddState.x != 0) {
		BattleSelectBuffOnlySoftWind(sn, game);
	}
	else {
		SelectBuffOnlySoftWind(sn, game);
	}
	return 0;
}
//	1.3.22 神秘
int BeginDailyTask::MysteryOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	int imitationorchange = 0;
	//使用字库
	sn->UseDict(5);
	//判断仿造还是转换
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(875, 458, 940, 528, _T("仿造(暗).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("神秘--仿造...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(623, 136, 636, 153, _T("5"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 2;
				Log(_T("柔风5级，不仿造...\r\n"), game);
				break;
			}
			else if (sn->FindStrFast(623, 136, 636, 153, _T("1|2|3|4"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 1;
				Log(_T("柔风不满5级，可以仿造...\r\n"), game);
				break;
			}
		}
		else if (sn->FindPicSim(723, 485, 782, 526, _T("转换(暗).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			imitationorchange = 2;
			Log(_T("神秘--转换...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (imitationorchange == 2) {
		//退出
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(69, 13, 129, 45, _T("神秘.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("月之海返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("退出神秘之屿...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("确定离开...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("回到月之海\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("检测到月晓星征\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (imitationorchange == 1) {
		//仿造
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

			if (sn->FindPicSim(619, 130, 681, 191, _T("仿造柔风.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("点击柔风...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPicSim(187, 57, 256, 122, _T("柔风(弹出).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("已点击柔风...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPicSim(874, 459, 943, 525, _T("仿造(明).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("点击仿造...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("确定仿造...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(433, 99, 527, 153, _T("造|成"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//434,99,525,155, D4C78C-2B3649
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("仿造成功...\r\n"), game);
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("回到月之海\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("检测到月晓星征\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 0;
}
//	1.3.32 混沌
int BeginDailyTask::OriginOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	//定义局部变量
	long intX, intY;
	State scene_state;
	//判断宝箱or战斗
	if (sn->FindPic(457, 196, 492, 294, _T("幸运宝匣.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		scene_state = TREASURE;
	}
	else if (sn->FindStrFast(452, 145, 491, 190, _T("精|英"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {//DFD8CC-202733
		scene_state = ELITE;
	}
	//1.1宝箱--领取/不领？
	if (scene_state == TREASURE) {
		//退出
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(877, 451, 931, 504, _T("离开混沌.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("离开混沌之屿...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(506, 226, 548, 247, _T("召唤"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
				if (sn->FindStrFast(367, 311, 417, 337, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("取消召唤...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX, intY);
				Log(_T("确定离开...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("回到月之海\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("检测到月晓星征\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	if (scene_state == ELITE) {
		//1.2战斗--进入
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.点击右侧技能怪[635,255]
			if (sn->FindStrFast(452, 145, 491, 190, _T("精|英"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {
				Log(_T("点击精英怪...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//锁定阵容
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.点击右侧技能怪[635,255]
			if (sn->FindPic(710, 494, 751, 533, _T("月之海解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("锁定阵容...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(710, 494, 751, 533, _T("月之海锁定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点挑战
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击挑战...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//2.选技能
		SelectBuffOnlySoftWind(sn, game);
	}
	return 0;
}
//	1.3.42 宁息
int BeginDailyTask::SilenceOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//使用字库
	sn->UseDict(5);
	//退出
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(877, 434, 941, 497, _T("离开宁息.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("离开宁息之屿...\r\n"), game);
			if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(506, 226, 548, 247, _T("召唤"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 311, 417, 337, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("取消召唤...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("确定离开...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("回到月之海\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("检测到月晓星征\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//	1.3.52 星之屿
int BeginDailyTask::IslandOfStarOnlySoftWind(int subsel, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	//定义局部变量
	long intX, intY;

	
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(537, 173, 564, 203, _T("危"), _T("C9BBBC-364443"), 0.85, &intX, &intY) != -1) {//C9BBBC-364443
			if (subsel != 2) {
				if (softwind < 3) {
					CPoint pos = sn->RandomOffsetPos(322, 233, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("柔风不足3级，选择普通怪...\r\n"), game);
				}
				else if (softwind >= 3) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("柔风大于等于3级，选择星之子...\r\n"), game);
				}
			}
			else {
				CPoint pos = sn->RandomOffsetPos(322, 233, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("不打星之子，选择普通怪...\r\n"), game);
			}
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//锁定阵容
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//锁定阵容
		if (sn->FindPic(710, 494, 751, 533, _T("月之海解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("锁定阵容...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("月之海锁定.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点挑战
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(848, 433, 931, 516, _T("月之海挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击挑战...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (sn->FindStrFast(398, 91, 526, 149, _T("获奖"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
			Log(_T("结算成功...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//战斗--结算
	if (softwind >= 3 && subsel != 2) {
		//选技能2/1
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//刷新完仍未找到
				//选择月赐之福
			if (sn->FindPic(462, 8, 516, 39, _T("buff2_1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("选择[月赐之福]\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindPic(468, 7, 509, 39, _T("buff2_2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//选技能2/2
		SelectBuffOnlySoftWind(sn, game);
	}
	else {
		//战斗--结算
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(398, 91, 526, 149, _T("获奖"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("回到月之海\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("检测到月晓星征\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 0;

}
//1.42 选buff
//1.4.12 抽象出方法
CPoint BeginDailyTask::FindBuffOnlySoftWind(CString buffname, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	long intX, intY;
	CString findname = _T("柔风抱暖|六道暴虐");
	CPoint bufflocXY(0, 0);
	int i = 5, buffcode = -1;
	while (i > 0) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((buffcode = sn->FindStrFast(110, 246, 212, 285, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("找到[") + buffname + _T("]\r\n"), game);
				if(buffname==_T("柔风抱暖")){
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
				}
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Right(4) + _T("]\r\n"), game);
					cruel++;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		else if ((buffcode = sn->FindStrFast(315, 246, 418, 284, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("找到[") + buffname + __T("]\r\n"), game);
				if (buffname == _T("柔风抱暖")) { 
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
				}
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Right(4) + _T("]\r\n"), game);
					cruel++;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		else if ((buffcode = sn->FindStrFast(515, 246, 626, 282, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("找到[") + buffname + _T("]\r\n"), game);
				if (buffname == _T("柔风抱暖")) {
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
				}
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("找到[") + buffname.Left(4) + _T("]\r\n"), game);
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("当前柔风抱暖[Lv") + str + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("找到[") + buffname.Right(4) + _T("]\r\n"), game);
					cruel++;
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		if (DelayPlus(game, sn, 50, 100) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return bufflocXY;
}
//1.4.22 通用选buff
int BeginDailyTask::SelectBuffOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	int refresh = 0, buff_res = -1;
	//----------椒图-----------
	//优先级：柔风抱暖>六道暴虐>月赐之福(恢复5%血量)
	// -- 选技能测试 --
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找柔风
		buffLoc_xy = FindBuffOnlySoftWind(_T("柔风抱暖"), sn, game);
		//找到柔风--选择柔风
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("选择技能\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				refresh = 0;
			}
		}
		//未找到柔风
		else {
			//柔风<4级 -- 刷新
			if (softwind < 4) {
				if (sn->FindPic(818, 3, 950, 50, _T("万相铃0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
					refresh = 3;
				}
				if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("月之海刷新.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
					//用万相铃刷新
					Log(_T("刷新buff\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x + 5, pos.y + 8);
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh++;
				}
			}
			//柔风>4级 -- 找所有 找到：选择  
			else if (softwind >= 4) {
				buffLoc_xy = FindBuffOnlySoftWind(_T("柔风抱暖|六道暴虐"), sn, game);
				//找到：选择
				if (buffLoc_xy.x != 0) {
					if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("选择技能\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						refresh = 0;
					}
				}
				//找不到：刷新
				else {
					//暴虐>2 或 无铃铛不刷新
					if ((cruel>=2) || (sn->FindPic(818, 3, 950, 50, _T("万相铃0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1)) {
						refresh = 3;
					}
					if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("月之海刷新.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
						//用万相铃刷新
						Log(_T("刷新buff\r\n"), game);
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x + 5, pos.y + 8);
						refresh++;
						if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
			}
		}
		//刷新完仍未找到
		if ((refresh >= 3) || (sn->FindPic(877, 454, 945, 512, _T("月之海刷新(尽).bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)) {
			buffLoc_xy = FindBuffOnlySoftWind(_T("柔风抱暖|六道暴虐"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("选择技能\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh = 0;
				}
			}
			//选择月赐之福
			else if (buffLoc_xy.x == 0 && sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				Log(_T("选择[月赐之福]\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				refresh = 0;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(511, 298, 601, 335, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("确认刷新...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (sn->FindStrFast(398, 91, 526, 149, _T("获奖"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//D4C78C-2B3649  441,90,527,150,
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("回到月之海\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("检测到月晓星征\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.4.32 鏖战选低级buff
int BeginDailyTask::BattleSelectBuffOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	//----------椒图-----------
	//优先级：柔风抱暖>六道暴虐>月赐之福(恢复5%血量)
	// -- 选技能测试 --
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找柔风
		buffLoc_xy = FindBuffOnlySoftWind(_T("柔风抱暖"), sn, game);
		//找到柔风--选择柔风
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("选择技能\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}//未找到柔风
		else {
			//--找其他(include softwind)
			buffLoc_xy = FindBuffOnlySoftWind(_T("柔风抱暖|六道暴虐"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("选择技能\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}//未找到其他--recover blood
			else {
				//选择月赐之福
				if (sn->FindStrFast(769, 433, 866, 467, _T("选择"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("选择[月赐之福]\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (sn->FindStrFast(398, 91, 526, 149, _T("获奖"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("月之海.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("回到月之海\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("检测到月晓星征\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.5 迎战月读
int BeginDailyTask::ToWardsTsukuyomiOnlySoftWind(snow *sn, Game *game) {
	//
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	//使用字库
	sn->UseDict(5);
	//判断是否挑战 
	if (softwind < 4) {
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(0, 0, 48, 54, _T("月之海返回.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击返回...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(540, 253, 580, 294, _T("放弃试炼.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(540, 253, 580, 294, _T("放弃试炼.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("放弃试炼...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(537, 306, 601, 343, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				Log(_T("确定放弃...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(510, 318, 588, 350, _T("使用"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (sn->FindStrFast(411, 93, 539, 170, _T("得奖"), _T("C8BA87-373844"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	//挑战月读
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(58, 9, 175, 50, _T("月晓星征.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(844, 427, 928, 511, _T("月读挑战.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("挑战月读...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		/*if (sn->FindPic(851, 6, 928, 35, _T("跳过月读.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("跳过...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}*/
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//不购买万象祈福  433C34-433C34
		if (sn->FindStrFast(439, 260, 477, 281, _T("不再"), _T("433C34-433C34"), 0.85, &intX, &intY) != -1) {
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(407, 256, 463, 284, _T("不再提醒.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("不再提醒...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(405, 253, 437, 286, _T("不再提醒(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(405, 253, 437, 286, _T("不再提醒(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 312, 416, 337, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("取消购买...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//挑战失败
		if (sn->FindStrFast(519, 311, 571, 337, _T("放弃"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("挑战失败，放弃前行...\r\n"), game);
			softwind = 0;
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(529, 305, 583, 329, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			Log(_T("确定放弃...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (softwind > 3 && sn->FindStrFast(510, 318, 588, 350, _T("使用"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("确定使用1个万相赐福...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (softwind <= 3 && sn->FindStrFast(390, 316, 444, 349, _T("取消"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("未挑战，不使用万相赐福...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(411, 93, 539, 170, _T("得奖"), _T("C8BA87-373844"), 0.85, &intX, &intY) != -1) {//C8BA87-373844
			Log(_T("获得奖励...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(438, 88, 535, 129, _T("等级提升.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("等级提升...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(467, 95, 579, 149, _T("技能解锁.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("技能解锁...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(422, 466, 515, 511, _T("前往查看.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入下一界面...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(488, 463, 538, 507, _T("前往查看(右).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("进入下一界面...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(812, 440, 876, 517, _T("分享.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPic(71, 92, 218, 214, _T("月之海_极.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("获得评分：极\r\n"), game);
				extream++;	//记录极次数
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(71, 92, 218, 214, _T("月之海_特.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("获得评分：特\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			Log(_T("进入下一界面...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(649, 150, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(844, 435, 912, 505, _T("月之海开启.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("成功返回初始界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.62 根据场景执行任务
int BeginDailyTask::AccordingSceneRunOnlySoftWind(int scene, int subsel,  snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//鏖战之屿
	if (scene == BATTLE) {
		if (BattleOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//神秘
	if (scene == MYSTERY) {
		if (MysteryOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//混沌
	if (scene == ORIGIN) {
		if (OriginOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//宁息  
	if (scene == SILENCE) {
		if (SilenceOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//星之屿 
	if (scene == ISLANDOFSTAR) {
		if (IslandOfStarOnlySoftWind(subsel, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//月读 
	if (scene == BOSS) {
		if (ToWardsTsukuyomiOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return scene;
}
//2.02 开始任务 正常阵容
int BeginDailyTask::StartSixPathOfDoorOnlySoftWind(long hd, int round, int subsel, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	int scene;
	Log(_T("开始前请在庭院界面启动...\r\n"), game);
	Log(_T("开始前请确保配置好阵容...\r\n"), game);
	Log(_T("开始前请确保已选择椒图...\r\n"), game);
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
	//1.寻
	if (FindSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	CString count_str;
	int scene_res = -1;
	extream = 0;
	while (count < round) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮月之海探索...\r\n"), game);
		//开始时间
		CTime startTime = CTime::GetCurrentTime();
		//初始化柔风记录
		softwind = 1;
		cruel = 0;
		//2.开启月之海
		if (OpenSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//3.随机选择场景
			if ((scene = RadomSelectAndCheckEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//4.根据场景执行任务
			if ((scene_res = AccordingSceneRunOnlySoftWind(scene, subsel, sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//退出条件
			if (scene_res == BOSS) {
				scene_res = -1;
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		count_str.Format(_T("%d"), count);
		Log(_T("已进行") + count_str + _T("轮月之海探索\r\n"), game);
		count_str.Format(_T("%d"), extream);
		Log(_T("共获得评分极") + count_str + _T("次\r\n"), game);
		//结束时间
		CTime endTime = CTime::GetCurrentTime();
		//耗时
		CString elapsedTimeString = GetElapsedTimeString(startTime, endTime);
		Log(_T("本局耗时") + elapsedTimeString + _T("\r\n"), game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//返回庭院
	if (count >= round) {
		SixPathOfDoorReturnYard(sn, game);
	}

	return 0;
}

//----日常功能----
int BeginDailyTask::EnterTaskFunc(long hd, int condition, CString picName, CString fontName, int mode_index, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//定义局部变量
	long intX, intY;
	sn->UseDict(0);
	int closingflag = 0;
	//获取目标位置
	CString fontLst = _T("困难|业火|风转|水灵|天雷|御魂|日轮|永生|妖气|经验|金币|年兽|石距|结界|对弈|回归");
	CString color_format = _T("454039-46413A");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//判断是否在庭院
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//退出线程
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("很抱歉，未找到组队按钮...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//找subsel
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(307, 98, 425, 130, picName, _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("已选择")+ fontName +_T("副本...\r\n"), game);
			break;
		}
		//点击经验/金币妖怪/妖气...
		findDestSite(startXY, endXY, fontLst, mode_index, fontName, color_format, 0.8, 2, sn, game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击自动匹配
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点击自动匹配
		if (sn->FindPic(517, 443, 665, 495, _T("自动匹配.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("自动匹配...\r\n"), game);
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("排队中...\r\n"), game);
			break;
		}
		if (sn->FindPic(60, 5, 183, 61, _T("协战队伍.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("已进队...\r\n"), game);
			break;
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//准备进入战斗界面
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点击挑战
		if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (condition == 0) {
				Log(_T("自己成为房主，点击挑战...\r\n"), game);
				//随机偏移坐标防检测
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (condition == 1) {
				Log(_T("成为房主，正在退出返回庭院...\r\n"), game);
				if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				return 0;
			}
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//进入战斗界面
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点准备
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//胜利结算
		if (sn->FindPic(277, 31, 373, 111, _T("经验妖怪胜利.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			closingflag = 1;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((closingflag == 1) && (sn->FindPic(277, 31, 373, 111, _T("经验妖怪胜利.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
			Log(_T("结算成功...\r\n"), game);
			closingflag = 0;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//经验妖怪
int BeginDailyTask::Experience(long hd, int round, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("开始经验妖怪...\r\n"), game);
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入经验妖怪副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮经验妖怪开始...\r\n"), game);
		int res = EnterTaskFunc(hd, condition, _T("经验妖怪.bmp"), _T("经验"), 9, sn, game);
		if (res == EXIT_THREAD) { return EXIT_THREAD; }
		else if (res = 0) {
			count = round;
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
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
//金币妖怪
int BeginDailyTask::GoldCoin(long hd, int round, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("开始金币妖怪...\r\n"), game);
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入经验妖怪副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮金币妖怪开始...\r\n"), game);
		int res = EnterTaskFunc(hd, condition, _T("金币妖怪.bmp"), _T("金币"), 10, sn, game);
		if (res == EXIT_THREAD) { return EXIT_THREAD; }
		else if (res = 0) {
			count = round;
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
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
//回归挑战
int BeginDailyTask::RegressionChallenge(long hd, int round, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("开始回归挑战...\r\n"), game);
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入经验妖怪副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮回归挑战开始...\r\n"), game);
		int res = EnterTaskFunc(hd, condition, _T("回归挑战.bmp"), _T("回归"), 15, sn, game);
		if (res == EXIT_THREAD) { return EXIT_THREAD; }
		else if (res = 0) {
			count = round;
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
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
//契灵
int BeginDailyTask::Vestige(long hd, int round, snow *sn, int subsel, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("开始前请在庭院界面启动...\r\n"), game);
	Log(_T("开始前自己保证阵容锁定...\r\n"), game);
	//镇墓兽  C8B052-03050C
	//火灵  ABCAA5-120419
	//小黑  A03104-030904
	//茨球  F2E8CB-030205

	//定义局部变量
	long intX, intY;
	CString logmsg;
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
	Log(_T("寻找契灵之境副本...\r\n"), game);
	//使用字库
	sn->UseDict(1);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//契灵版六道位置
		if (sn->FindStrFast(687, 504, 764, 538, _T("契灵"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("找到契灵之境...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(57, 10, 191, 51, _T("契灵之境.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("成功进入契灵之境...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	int count = 0, ck_flag = 0, findQl, isfindQl;
	while (count < round) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//3s
		if (subsel != 1) {
			Log(_T("开始检测是否发现契灵(3s)...\r\n"), game);
			findQl = 6;
			isfindQl = false;
			//挑战  D6CDBF-282727
			while (findQl > 0) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(18, 282, 831, 430, _T("茨球"), _T("F2E8CB-030205"), 0.85, &intX, &intY) != -1) {
					Log(_T("找到契灵茨球...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("茨球"), _T("F2E8CB-030205"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("准备挑战契灵...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("契灵_挑战"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
							break;
						}
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					isfindQl = true;
				}
				else if (sn->FindStrFast(18, 282, 831, 430, _T("小黑"), _T("A03104-030904"), 0.85, &intX, &intY) != -1) {
					Log(_T("找到契灵小黑...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("小黑"), _T("A03104-030904"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("准备挑战契灵...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("契灵_挑战"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
							break;
						}
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					isfindQl = true;
				}
				else if (sn->FindStrFast(18, 282, 831, 430, _T("火灵"), _T("ABCAA5-120419"), 0.85, &intX, &intY) != -1) {
					Log(_T("找到契灵火灵...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("火灵"), _T("ABCAA5-120419"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("准备挑战契灵...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("契灵_挑战"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
							break;
						}
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					isfindQl = true;
				}
				else if (sn->FindStrFast(18, 282, 831, 430, _T("镇墓兽"), _T("C8B052-03050C"), 0.85, &intX, &intY) != -1) {
					Log(_T("找到契灵镇墓兽...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("镇墓兽"), _T("C8B052-03050C"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("准备挑战契灵...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("契灵_挑战"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
							break;
						}
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					isfindQl = true;
				}
				if (DelayPlus(game, sn, 500, 502) == EXIT_THREAD) { return EXIT_THREAD; }
				if (isfindQl) {
					break;
				}
				findQl--;
			}
			Log(_T("检测完成...\r\n"), game);
			//end
			if (isfindQl) {
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindStrFast(864, 441, 922, 479, _T("契灵_挑战"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("点击挑战...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					//成功 BCA469-292A20 
					if (sn->FindStrFast(640, 27, 682, 51, _T("技能"), _T("BCA469-292A20"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("结契契灵展示界面...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					//CEC290-313C4D  483,149,617,219,
					if (sn->FindStrFast(483, 149, 617, 219, _T("成功"), _T("CEC290-313C4D"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("结契成功...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
						if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
						Log(_T("领取奖励...\r\n"), game);
						sn->MoveClick(pos.x, pos.y);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindStrFast(856, 433, 922, 477, _T("探|查"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 1000, 1100) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(856, 433, 922, 477, _T("探|查"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {
							break;
						}
					}
					if (DelayPlus(game, sn, 500, 502) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		//探查
		if (subsel != 2) {
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//6E4745-252E2C
				if (sn->FindStrFast(856, 433, 922, 477, _T("探|查"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					if (ck_flag == 0) {
						Log(_T("点击探查...\r\n"), game);
						ck_flag = 1;
					}
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 2200, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (findBackIconSite(sn, game, intX, intY) != -1) {
					logmsg.Format(_T("%d"), count + 1);
					Log(_T("第") + logmsg + _T("轮探查开始...\r\n"), game);
					sn->UseDict(1);
					ck_flag = 0;
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(294, 84, 439, 204, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					Log(_T("战斗胜利...\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(400, 490, 5, 10);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
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
				if (sn->FindStrFast(856, 433, 922, 477, _T("探|查"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {

					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			count++;
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	if (count >= round) {
		SixPathOfDoorReturnYard(sn, game);
	}
	return 1;
}
//整合开始(妖气+六道+日常)
int BeginDailyTask::StartAllDaily(long hd, int condition, int round, int headsel, int subsel, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	switch (headsel)
	{
	case 0: {
		if(StartYaoQiFengYin(hd, round, subsel, condition, sn, game)== EXIT_THREAD) { return EXIT_THREAD; }
		break;
	}
	case 1: {
		switch (subsel)
		{
		case 0: {
			if (StartSixPathOfDoor(hd, round, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		case 1: {
			if (StartSixPathOfDoorOnlySoftWind(hd, round, subsel, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		case 2: {
			if (StartSixPathOfDoorOnlySoftWind(hd, round, subsel, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		default:
			break;
		}
		break;
	}
	case 2: {
		if (subsel == 0) {
			if (Experience(hd, round, condition, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (subsel == 1) {
			if (GoldCoin(hd, round, condition, sn, game) == EXIT_THREAD) {return EXIT_THREAD; }
		}
		else if (subsel == 2) {
			if (RegressionChallenge(hd, round, condition, sn, game) == EXIT_THREAD) {return EXIT_THREAD; }
		}
		break; 
	}
	case 3: {
		if (Vestige(hd, round, sn, subsel, game) == EXIT_THREAD) { return EXIT_THREAD; }
		break;
	}
	default:
		break;
	}
	return 1;
}