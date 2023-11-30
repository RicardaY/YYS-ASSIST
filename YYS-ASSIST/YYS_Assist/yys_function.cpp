#pragma once
#include "pch.h"
#include "yys_function.h"
#include "CGame_Global1.h"
#include<random>
#include<ctime>
#include<iomanip>
#include<afxinet.h>
#include "globalvar.h"


#define EXIT_THREAD -10
extern CGame_Global1 *global1;


int yys_function::Tips(Game *game) {
	Log(_T("  2.需关闭帧率显示\r\n"), game);
	Log(_T("  1.需使用简约/凛霜寒雪/春缕含青/祥夜幽芳战斗主题\r\n"), game);
	Log(_T("  ****小提示****\r\n"), game);
	return 0;
}

int yys_function::NotInYardTips(long hd, snow *sn, Game *game) {
	long hd_width, hd_height;
	CString clientSize;
	int ret = sn->GetClientSize(hd, &hd_width, &hd_height);
	if (ret != 0) {
		clientSize.Format(_T("%d * %d"), hd_width, hd_height);
		Log(_T("当前模拟器分辨率：") + clientSize + _T("\r\n"), game);
		if ((hd_width != 960) || (hd_height != 540)) {
			Log(_T("请将模拟器调整至正确分辨率，然后重启模拟器！\r\n"), game);
			Log(_T("若手动更改了大小，请重启模拟器再试！\r\n"), game);
			Log(_T("模拟器分辨率不是960*540，打开模拟器后请勿手动缩放模拟器窗口大小！\r\n"), game);
			return 0;
		}
	}
	Log(_T("5.win7需要桌面右键-个性化-双击windows经典!\r\n"), game);
	Log(_T("4.检查是否使用壁纸引擎!若使用，请关闭引擎后重启电脑！！！\r\n"), game);
	Log(_T("3.模拟器窗口不可手动缩放\r\n"), game);
	Log(_T("2.请确保庭院皮肤为默认/织梦莲庭/琼夜淬光之一\r\n"), game);
	Log(_T("1.请确保模拟器分辨率 960*540 160dpi\r\n"), game);
	Log(_T("未找到庭院界面，可能原因：\r\n"), game);
	return 1;
}
int yys_function::InYardNoExploreLanternTips(Game *game) {
	Log(_T("4.win7需要桌面右键-个性化-双击windows经典!\r\n"), game);
	Log(_T("3.检查是否使用壁纸引擎!若使用，请关闭引擎后重启电脑(必须重启)！！！\r\n"), game);
	Log(_T("2.检查式神委派是否领取!!!\r\n"), game);
	Log(_T("1.检查庭院皮肤为默认/织梦莲庭/琼夜淬光之一!!!\r\n"), game);
	Log(_T("在庭院界面，但未找到探索灯笼!!!\r\n"), game);
	return 1;
}
//读文件
int yys_function::ReadFile(CString filePath, int loff, CStringArray& ListArray)
{
	ListArray.RemoveAll();
	if (!PathFileExists(filePath))
	{
		return 0;
	}
	//解决乱码
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	CStdioFile file;
	if (!file.Open(filePath, CFile::modeRead))
	{
		MessageBox(NULL, _T("读取文件失败!!!"), _T(""), 0);
		return 0;
	}
	file.Seek(loff, 0);
	CString strValue = _T("");
	while (file.ReadString(strValue))
	{
		ListArray.Add(strValue);
	}
	file.Close();
	//释放资源
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return (int)ListArray.GetSize();
}
//写文件
int yys_function::WriteFile(CString filePath, int loff, CStringArray& ListArray)
{
	//解决乱码
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	CStdioFile file;
	int listSize = ListArray.GetSize();
	if (listSize == 0) {
		//释放资源
		setlocale(LC_CTYPE, old_locale);
		free(old_locale);
		return NULL_LIST;
	}
	if (!file.Open(filePath, CFile::modeWrite | CFile::modeCreate))
	{
		//释放资源
		setlocale(LC_CTYPE, old_locale);
		free(old_locale);
		return ERR_CODE;
	}
	file.Seek(loff, 0);
	for (int i = 0; i < listSize; i++) {
		file.WriteString(ListArray.GetAt(i) + _T("\n"));
	}
	file.Close();
	ListArray.RemoveAll();
	//释放资源
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return 1;
}

//编辑框开头追加数据
void yys_function::Log(CString logMsg, Game *game) {
	game->log(logMsg);
	return;
}
//随机延迟点击，防止游戏外挂检测
int yys_function::DelayPlus(Game *game, snow *sn, int minms, int maxms) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->Delays(minms, maxms);
	//暂停
	if (game->getThreadPauseState())
	{
		Log(_T("线程已挂起，恢复时需回到暂停时的界面！\r\n"), game);
		if (sn != NULL)
		{
			sn->EnableBind(5);
		}
		while (1)
		{
			sn->delay(3000);
			if (!game->getThreadPauseState())
			{
				Log(_T("线程已恢复\r\n"), game);
				if (sn != NULL)
				{
					sn->EnableBind(1);
				}
				break;
			}//暂停时退出
			if (game->getThreadStopState())
			{
				break;
			}
		}
	}//停止
	if (game->getThreadStopState()) {
		game->setThreadStartState(false);
		return EXIT_THREAD;
	}
	return 1;
}
//判断是否在庭院 true:在 false:不在
bool yys_function::IsInYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return false;
	}
	sn->UseDict(0);
	//start findFunc
	long intX, intY;
	bool isFind = false;
	int i = 20;
	while (i > 0)
	{
		//找探索灯笼   离庭 5C3812-17150A   琼夜淬光  2A373F-141112
		if ((sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1) || (sn->FindStrFast(230, 40, 850, 200, _T("探|索"), _T("1D1D0C-1E1D0C"), 0.85, &intX, &intY) != -1) || (sn->FindStrFast(230, 40, 850, 200, _T("探|索"), _T("493B22-493C23"), 0.85, &intX, &intY) != -1) || (sn->FindStrFast(230, 40, 850, 200, _T("探|索"), _T("25323C-120E10"), 0.8, &intX, &intY) != -1))
		{
			isFind = 1;
			Log(_T("已在庭院界面...\r\n"), game);
			break;
		}
		DelayPlus(game, sn, 200, 250);
		i--;
	}
	return isFind;
}
//判断庭院是否展开 true:展开 false:关闭
bool yys_function::IsShowYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return false;
	}
	sn->UseDict(0);
	//start findFunc
	long intX, intY;
	bool findRet = false;
	int i = 10;
	while (i > 0)
	{
		if (sn->FindStrFast(264, 488, 377, 523, _T("组队"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1 || sn->FindStrFast(361, 482, 469, 522, _T("阴|阳|寮"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1)
		{
			findRet = true;
			Log(_T("庭院已展开...\r\n"), game);
			break;
		}
		DelayPlus(game, sn, 100, 150);
		i--;
	}
	return findRet;
}
//展开庭院
int yys_function::showYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (!IsShowYard(sn, game))
	{
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("展开庭院...\r\n"), game);
		sn->MoveToEx(901, 468, 14, 43);
		sn->delay(1000);
		sn->LeftClick();
		return 1;
	}
	return 0;
}
//寻找探索灯笼并点击
int yys_function::FindExploreLanTernAndClick(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->UseDict(0);
	//start findFunc
	long intX, intY;
	int delayflag = 0;
	Log(_T("寻找探索灯笼...\r\n"), game);
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找探索灯笼1B1703-1C1803

		if (sn->FindStrFast(230, 40, 850, 200, _T("探|索"), _T("1D1D0C-1E1D0C"), 0.85, &intX, &intY) != -1)
		{
			Log(_T("找到探索灯笼\r\n"), game);
			//点击
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 15);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (sn->FindStrFast(230, 40, 850, 200, _T("探|索"), _T("493B22-493C23"), 0.85, &intX, &intY) != -1)
		{
			Log(_T("找到探索灯笼\r\n"), game);
			//点击
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 15);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (sn->FindStrFast(230, 40, 850, 200, _T("探|索"), _T("2F363F-181112"), 0.8, &intX, &intY) != -1)//琼夜淬光
		{
			Log(_T("找到探索灯笼\r\n"), game);
			//点击
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 15);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(108, 504, 188, 538, _T("御|魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			Log(_T("已进入探索界面...\r\n"), game);
			break;
		}
		else if (sn->FindStrFast(9, 506, 130, 538, _T("觉|醒"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			Log(_T("已进入探索界面...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		delayflag++;
		if (delayflag > 40) {
			return 0;
		}
	}
	return 1;
}
//点击组队
int yys_function::CombineTeamAction(snow *sn, Game *game) {
	//点击组队
	if (sn == NULL)
	{
		return false;
	}
	//组队、阴阳寮  C1B7AE-232827
	sn->UseDict(0);
	long intX, intY;
	bool findret = false;
	int i = 10;
	while (i > 0)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找组队
		if (sn->FindStrFast(264, 488, 377, 523, _T("组队"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) !=-1)
		{
			Log(_T("点击组队...\r\n"), game);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 3);
			if (DelayPlus(game, sn, 200, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			findret = true;
			break;
		}
		if (DelayPlus(game, sn, 200, 250) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return findret;
}
//获取当前位置
long yys_function::findCurrentSite(CPoint startXY, CPoint endXY, CString picFontLst, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode) {
	if (sn == nullptr) {
		return 0;
	}
	//使用字库
	sn->UseDict(dictId);
	long intX, intY, currentSite = 0;

	int i = 20;
	while (i > 0) {
		if (mode == _T("findstr") && (currentSite = sn->FindStrFast(startXY.x, startXY.y, endXY.x, endXY.y, picFontLst, color_format, sim, &intX, &intY)) != -1) {
			break;
		}
		else if (mode == _T("findpic") && (currentSite = sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, picFontLst, color_format, sim, 0, &intX, &intY)) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return currentSite;
}
//寻找返回图标位置
long yys_function::findBackIconSite(snow *sn, Game *game, long &intX , long &intY) {
	if (sn == NULL)
	{
		return false;
	}
	//字库
	sn->UseDict(0);
	if (sn->FindStrFast(0, 0, 56, 58, _T("返回"), _T("B39A7E-2B261D"), 0.85, &intX, &intY) != -1) {
		return 0;
	}
	else if (sn->FindStrFast(0, 0, 56, 58, _T("返回(冰雪)"), _T("A1BFD6-393329"), 0.85, &intX, &intY) != -1) {
		return 0;
	}//D7C59A-282F3E  春缕含青
	else if (sn->FindStrFast(0, 0, 56, 58, _T("返回(春缕)"), _T("D7C59A-282F3E"), 0.85, &intX, &intY) != -1) {
		return 0;
	}//B2B2DC-424223 祥夜幽芳
	else if (sn->FindStrFast(0, 0, 56, 58, _T("返回(祥夜)"), _T("B2B2DC-424223"), 0.85, &intX, &intY) != -1) {
		return 0;
	}
	
	return -1;
}
//寻找手动图标位置
long yys_function::findManualSite(snow *sn, Game *game, long &intX, long &intY) {
	if (sn == NULL)
	{
		return false;
	}
	//字库
	sn->UseDict(4);
	if (sn->FindStrFast(9, 452, 77, 532, _T("手动"), _T("C7A184-292928"), 0.8, &intX, &intY) != -1) {
		return 0;
	}
	else if (sn->FindStrFast(9, 452, 77, 532, _T("手动"), _T("CAD5E4-34291A"), 0.85, &intX, &intY) != -1) {
		return 0;
	}// C2BAA3-3C403F
	else if (sn->FindStrFast(9, 452, 77, 532, _T("手动"), _T("C2BAA3-3C403F"), 0.85, &intX, &intY) != -1) {
		return 0;
	}// CDC9D0-31311C
	else if (sn->FindStrFast(9, 452, 77, 532, _T("手动"), _T("CDC9D0-31311C"), 0.85, &intX, &intY) != -1) {
		return 0;
	}
	return -1;
}
//寻找目标位置并点击---不触发停止
int yys_function::findDestSite(CPoint startXY, CPoint endXY, CString picFontLst, long targetSite, CString tartgetPicFont, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode, CString targetTagFont) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库  //433E38-443F38
	sn->UseDict(dictId);
	long intX, intY;
	//区域
	int startx = (startXY.x + endXY.x) / 2;
	int starty = startXY.y + (int)((endXY.y - startXY.y)*0.25), endy = startXY.y + (int)((endXY.y - startXY.y)*0.75);
	//标题符合直接return
	if (!targetTagFont.IsEmpty() && sn->FindStrFast(295, 87, 586, 137, targetTagFont.Left(1), targetTagFont.Mid(2), 0.85, &intX, &intY) != -1) {
		return 1;
	}
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找目前所在位置
		long currentSite = findCurrentSite(startXY, endXY, picFontLst, color_format, sim, dictId, sn, game, mode);
		if (currentSite == -1) {
			return 0;
		}
		//下移
		if (targetSite <= currentSite){
			if (mode == _T("findstr") && sn->FindStrFast(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, &intX, &intY) != -1){
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//模拟真实鼠标轨迹
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else if (mode == _T("findpic") && sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, 0, &intX, &intY) != -1) {
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//模拟真实鼠标轨迹
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else{
				//模拟真实鼠标轨迹
				sn->EnableRealMouse(1, 20, 30);
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(startx, 0);
				sn->DragMouse(pos.x, starty, pos.x, endy);
				DelayPlus(game, sn, 500, 800);
			}
		}//上移
		else if (targetSite > currentSite){
			if (mode == _T("findstr") && sn->FindStrFast(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, &intX, &intY) != -1){
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//模拟真实鼠标轨迹
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else if (mode == _T("findpic") && sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, 0, &intX, &intY) != -1) {
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//模拟真实鼠标轨迹
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else{
				//模拟真实鼠标轨迹
				sn->EnableRealMouse(1, 20, 30);
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(startx, 0);
				sn->DragMouse(pos.x, endy, pos.x, starty);
				DelayPlus(game, sn, 500, 800);
			}
		}
		DelayPlus(game, sn, 500, 800);
	}
	return 0;
}
//创建队伍---点击邀请
int yys_function::CreatTeamToInviteUpper(int mateType, snow *sn, Game *game) {
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
		if (sn->FindStrFast(754, 457, 805, 484, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y);
			Log(_T("创建队伍...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(630, 429, 685, 458, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//设置公开权限
	while (1)
	{
		if (sn->FindPic(555, 361, 592, 398, _T("不公开(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			Log(_T("选择权限不公开...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
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
		if (sn->FindStrFast(630, 429, 685, 458, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y);
			Log(_T("创建...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(449, 159, 517, 219, _T("加.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
int yys_function::CreatTeamToInviteLower(int mateType, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(2);
	//邀请好友
	while (1)
	{
		if (sn->FindPic(449, 159, 517, 219, _T("加.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 6, pos.y + 5);
			Log(_T("进入好友列表...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((mateType == 0) && (sn->FindPic(345, 68, 403, 104, _T("最近(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y + 5);
			Log(_T("选择最近组队好友...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
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
			if (sn->FindPic(404, 119, 483, 157, _T("最近组队.bmp|最近组队2.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x - 55, pos.y + 35);
				Log(_T("选中列表中第一位最近组队好友...\r\n"), game);
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
			if (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y);
				Log(_T("点击邀请...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (mateType == 1) {
		while (1)
		{
			if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
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
			if ((sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
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
			if ((sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}

//组队关系
int yys_function::TeamRelation(bool &flag1, bool &flag2, snow *sn, Game *game) {
	//如果开启组队关系
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	game->synchronization(flag1, flag2);
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	return 1;
}
//检测好友进入队伍点挑战 
int yys_function::IsEnterTeam(snow *sn, Game *game, int mateType, int triple) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	if (triple == 0) {
		int timeRecord = 0;
		//检查好友是否进入队伍
		Log(_T("等待好友加入队伍...\r\n"), game);
		while (1)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//点挑战
			if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
			{
				//随机偏移坐标防检测
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("好友已加入队伍...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				break;
			}
			Sleep(1500);
			timeRecord++;
			if (sn->FindPic(874, 436, 953, 518, _T("挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
			{
				if (timeRecord >= 12) {
					Log(_T("好友未加入，重新邀请好友...\r\n"), game);
					if(CreatTeamToInviteLower(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					timeRecord = 0;
				}
			}
		}
	}
	else {
		Log(_T("注：此为三人组队模式，必须满三人才会开始...\r\n"), game);
		while (1)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//点挑战
			if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
			{
				long cx = intX, cy = intY;
				if ((sn->FindPic(781, 152, 851, 221, _T("加.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)&&(sn->FindPic(449, 159, 517, 219, _T("加.bmp"), _T("101010"), 0.9, 0, &intX, &intY) == -1)) {
					//随机偏移坐标防检测
					CPoint pos = sn->RandomOffsetPos(cx, cy, 5, 10);
					if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
					Log(_T("好友已加入队伍...\r\n"), game);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//队长进入副本事件
int yys_function::InviteEnterEvent(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int stateCode;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点准备
		if (readyFlag && (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("点击准备...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//胜利结算
		if (sn->FindPic(286, 34, 438, 169, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 20, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp|魂(氪金).bmp|魂底(氪金).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("结算成功...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}//298,41,408,147, 
		//失败结算
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("挑战失败...\r\n"), game);
			stateCode = FAIL;
			break;
		}
		if (sn->FindPic(401, 251, 555, 289, _T("默认邀请队友.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			stateCode = DEFAULT;
			break;
		}
		if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp|永生之海挑战.bmp|永生之海挑战(灰).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			stateCode = NOMAL;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return stateCode;
}
//接受邀请
int yys_function::ReceiveFriendInvite(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int isReadyClick = 0;
	//开始
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//接受默认邀请
		if (sn->FindPic(139, 153, 223, 224, _T("接受默认邀请.bmp|接受默认邀请2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("接受默认邀请...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 8);
			isReadyClick = 0;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}//接受普通邀请
		else if (sn->FindPic(74, 164, 136, 219, _T("接受邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			int temp_x = intX, temp_y = intY;
			Sleep(1500);
			if (sn->FindPic(139, 153, 223, 224, _T("接受默认邀请.bmp|接受默认邀请2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("接受默认邀请...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				isReadyClick = 0;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else {
				Log(_T("接受普通邀请...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(temp_x, temp_y, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				isReadyClick = 1;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}//832, 393, 941, 536,
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (sn->FindPic(60, 5, 183, 61, _T("协战队伍.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return isReadyClick;
}
//进入副本
int yys_function::EnterEvent(snow *sn, Game *game, bool isReadyClick) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(4);
	//定义局部变量
	long intX, intY;
	int isReturnAsExitCondition = 0;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (isReadyClick && (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("点击准备...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 20, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp|魂(氪金).bmp|魂底(氪金).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			isReturnAsExitCondition = 1;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("挑战失败...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			isReturnAsExitCondition = 2;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((isReturnAsExitCondition == 1) && (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp|魂(氪金).bmp|魂底(氪金).bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
			Log(_T("结算成功...\r\n"), game);
			if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("等待好友邀请...\r\n"), game);
			break;
		}
		if ((isReturnAsExitCondition == 2) && (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) == -1)) {
			break;
		}
		/*if (sn->FindPic(74, 164, 136, 219, _T("接受邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("结算成功...\r\n"), game);
			if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("等待好友邀请...\r\n"), game);
			break;
		}*/
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//默认邀请好友
int yys_function::DefalutInvite(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(4);
	long intX, intY;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//默认邀请
		if (sn->FindPic(401, 251, 555, 289, _T("默认邀请队友.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("默认邀请好友...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 8);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(401, 251, 555, 289, _T("默认邀请队友(选).bmp|默认邀请队友(选)2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//点击确定  4D3A21-4E3B22
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("确定邀请...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 8);
			if (DelayPlus(game, sn, 1800, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp|永生之海挑战.bmp|永生之海挑战(灰).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//失败事件
int yys_function::FailEvent(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(4);
	long intX, intY;
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			Log(_T("失败继续邀请好友...\r\n"), game);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			readyFlag = TRUE;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp|永生之海挑战.bmp|永生之海挑战(灰).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//自动开加成
int yys_function::auto_open_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	//字库
	sn->UseDict(0);
	//模拟真实鼠标轨迹
	sn->EnableRealMouse(1, 20, 30);
	//是否选择自动开关加成
	//御魂
	if (jc_category == _T("御魂"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("正在打开加成...\r\n"), game);
			//点击加成灯笼
			int yh_move = 0;
			while (1)
			{
				//自动拒绝悬赏 79614C-4D3F33
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(446, 95, 569, 390, _T("御|魂"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					Log(_T("找到御魂加成位置...\r\n"), game);
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("打开御魂加成...\r\n"), game);
						//打开御魂加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("加成已打开，关闭加成界面...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (yh_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						yh_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((yh_move >= 2) && (yh_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						yh_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						yh_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//觉醒
	else if (jc_category == _T("觉醒"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("正在打开加成...\r\n"), game);
			int jx_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(446, 95, 569, 390, _T("觉"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					Log(_T("找到觉醒加成位置...\r\n"), game);
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("打开觉醒加成...\r\n"), game);
						//打开加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("加成已打开，关闭加成界面...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jx_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jx_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jx_move >= 2) && (jx_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jx_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jx_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//探索
	else if (jc_category == _T("探索"))
	{
		//4B4744-4C4744
		//开关全部经验
		if (jc_index == _T("1"))
		{
			Log(_T("正在打开加成...\r\n"), game);
			//点击加成
			int jy_move = 0;
			bool jy100Flag = false, jy50Flag = false;
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					Log(_T("已在加成界面...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏 403B37-403C38
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("打开50%经验加成...\r\n"), game);
						//打开加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy50Flag = true;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%经验加成已打开...\r\n"), game);
						jy50Flag = true;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("打开100%经验加成...\r\n"), game);
						//打开加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy100Flag = true;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%经验加成已打开...\r\n"), game);
						jy100Flag = true;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//若都打开则关闭加成弹窗
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (jy50Flag && jy100Flag) {
					Log(_T("加成已全部打开，关闭加成界面...\r\n"), game);
					//关闭加成框
					if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					Log(_T("加成打开失败，请留意...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//开启金币
		else if (jc_index == _T("2"))
		{
			Log(_T("正在打开加成...\r\n"), game);
			Log(_T("金币加成功能暂未实现，请手动打开加成后再开启脚本...\r\n"), game);
			//暂不实现此功能
			return 1;
		}
		//开启50%经验
		else if (jc_index == _T("3"))
		{
			Log(_T("正在打开加成...\r\n"), game);
			int jy_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					Log(_T("已在加成界面...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("打开50%经验加成...\r\n"), game);
						//打开加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 111, tmpy - 8, tmpx + 226, tmpy + 30, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%经验加成已打开...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(128, 364);
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//开启100%经验
		else if (jc_index == _T("4"))
		{
			int jy_move = 0;
			Log(_T("正在打开加成...\r\n"), game);
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("打开100%经验加成...\r\n"), game);
						//打开加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%经验加成已打开...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
	}
	//模拟真实鼠标轨迹
	sn->EnableRealMouse(3, 20, 30);
	return 1;
}
//自动关加成
int yys_function::auto_close_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	//字库
	sn->UseDict(0);
	//模拟真实鼠标轨迹
	sn->EnableRealMouse(1, 20, 30);
	//是否选择自动开关加成
	//御魂
	if (jc_category == _T("御魂"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("正在关闭加成...\r\n"), game);
			//点击加成灯笼
			int yh_move = 0;
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(446, 95, 569, 390, _T("御|魂"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("关闭御魂加成...\r\n"), game);
						//关闭御魂加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("加成已关闭，关闭加成界面...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (yh_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						yh_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((yh_move >= 2) && (yh_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						yh_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						yh_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//觉醒
	else if (jc_category == _T("觉醒"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("正在关闭加成...\r\n"), game);
			int jx_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

				if (sn->FindStrFast(446, 95, 569, 390, _T("觉"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("关闭觉醒加成...\r\n"), game);
						//关闭加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("加成已关闭，关闭加成界面...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jx_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jx_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jx_move >= 2) && (jx_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jx_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jx_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//探索
	else if (jc_category == _T("探索"))
	{
		//4B4744-4C4744
		//开关全部经验
		if (jc_index == _T("1"))
		{
			Log(_T("正在关闭加成...\r\n"), game);
			//点击加成
			int jy_move = 0;
			bool jy100Flag = true, jy50Flag = true;
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("关闭50%经验加成...\r\n"), game);
						//关闭加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy50Flag = false;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%经验加成已关闭...\r\n"), game);
						jy50Flag = false;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("关闭100%经验加成...\r\n"), game);
						//关闭加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy100Flag = false;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%经验加成已关闭...\r\n"), game);
						jy100Flag = false;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//若都打开则关闭加成弹窗
			while (1) {
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if ((!jy50Flag) && (!jy100Flag)) {
					Log(_T("加成已全部关闭，关闭加成界面...\r\n"), game);
					//关闭加成框
					if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					Log(_T("加成关闭失败，请留意...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//关闭金币
		else if (jc_index == _T("2"))
		{
			Log(_T("正在关闭加成...\r\n"), game);
			Log(_T("金币加成功能暂未实现，请手动关闭金币加成...\r\n"), game);
			//暂不实现此功能
			return 1;
		}
		//关闭50%经验
		else if (jc_index == _T("3"))
		{
			Log(_T("正在关闭加成...\r\n"), game);
			int jy_move = 0;
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("关闭50%经验加成...\r\n"), game);
						//关闭加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%经验加成已关闭...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//关闭100%经验
		else if (jc_index == _T("4"))
		{
			int jy_move = 0;
			Log(_T("正在关闭加成...\r\n"), game);
			//点击加成
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("点击加成灯笼...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("已在加成界面...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//判断加成状态
			while (1)
			{
				//自动拒绝悬赏
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%加成
				if (sn->FindStr(446, 95, 569, 390, _T("经10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成打开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("关闭100%经验加成...\r\n"), game);
						//关闭加成
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("加成未开.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%经验加成已关闭...\r\n"), game);
						//关闭加成框
						if (sn->FindPic(237, 358, 388, 423, _T("加成标志.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
							sn->MoveClick(pos.x, pos.y);
							if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 316, 430, 213);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						sn->DragMouse(430, 213, 430, 316);
						jy_move++;
						if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
	}
	//模拟真实鼠标轨迹
	sn->EnableRealMouse(3, 20, 30);
	return 1;
}
//自动拒绝悬赏封印
int yys_function::AutoRejectXS(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int flag = 0;
	int is_reject_xs = global1->m_reject.GetCheck();
	//拒绝悬赏封印
	if (is_reject_xs&&sn->FindPic(380, 109, 422, 151, _T("协.bmp|享.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		Log(_T("检测到悬赏...\r\n"), game);
		while (1) {
			if (sn->FindPic(614, 361, 668, 416, _T("拒绝.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("拒绝悬赏...\r\n"), game);
				if (DelayPlus(game, sn, 300, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				flag = 1;
				if (DelayPlus(game, sn, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((flag == 1) && (sn->FindPic(380, 109, 422, 151, _T("协.bmp|享.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (!is_reject_xs&&sn->FindPic(380, 109, 422, 151, _T("协.bmp|享.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		Log(_T("检测到悬赏...\r\n"), game);
		while (1) {
			if (sn->FindPic(616, 293, 663, 331, _T("接受.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("接受悬赏...\r\n"), game);
				if (DelayPlus(game, sn, 300, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				flag = 1;
				if (DelayPlus(game, sn, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((flag == 1) && (sn->FindPic(380, 109, 422, 151, _T("协.bmp|享.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//返回庭院
int yys_function::returnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//字库
	sn->UseDict(0);
	long intX, intY;
	long exitRes1, exitRes2;
	while (true)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//找红叉叉
		exitRes1 = sn->FindPic(735, 29, 968, 175, _T("叉.bmp|叉1.bmp|叉2.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if (exitRes1 != -1)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//找返回
		exitRes1 = sn->FindPic(0, 0, 217, 107, _T("返回1.bmp|返回2.bmp|返回3.bmp|返回4.bmp|返回5.bmp|返回6.bmp|返回7.bmp|返回8.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if (exitRes1 != -1)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//创建队伍退出 case3：退出邀请面板
		exitRes1 = sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY);
		exitRes2 = sn->FindStrFast(354, 420, 400, 443, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//探索退出
		exitRes1 = sn->FindStrFast(348, 289, 408, 316, _T("取消"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY); //探索取消
		exitRes2 = sn->FindStrFast(558, 292, 608, 316, _T("确认"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//创建队伍退出 case1：取消创建队伍
		exitRes1 = sn->FindStrFast(630, 429, 685, 458, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY);
		exitRes2 = sn->FindStrFast(278, 430, 326, 455, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//创建队伍退出 case2：退出组队面板
		if (sn->FindStrFast(542, 308, 594, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(298, 41, 408, 147, _T("失败.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 303, 587, 332, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("成功返回庭院！\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//微信推送
int yys_function::PushPlus(CString token, int pushstate, CString tips, Game *game) {
	if (pushstate) {
		try {
			CInternetSession session;
			CString url = _T("http://www.pushplus.plus/send?token=") + token + _T("&title=Notice:YYS ASSIST&content=")+ tips +_T(":Task Completed Successfully!");
			CHttpFile *pfile = (CHttpFile*)session.OpenURL(url);
			CString response, strLine;
			if (pfile != nullptr) {
				while (pfile->ReadString(strLine)) {
					response += strLine;
				}
				pfile->Close();
				delete pfile;
			}
			if (!response.IsEmpty()) {
				Log(_T("微信消息推送成功！\r\n"), game);
			}
		}
		catch (CInternetException *e) {
			e->Delete();
		}
	}
	return 0;
}