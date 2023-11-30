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
	Log(_T("  2.��ر�֡����ʾ\r\n"), game);
	Log(_T("  1.��ʹ�ü�Լ/��˪��ѩ/���ƺ���/��ҹ�ķ�ս������\r\n"), game);
	Log(_T("  ****С��ʾ****\r\n"), game);
	return 0;
}

int yys_function::NotInYardTips(long hd, snow *sn, Game *game) {
	long hd_width, hd_height;
	CString clientSize;
	int ret = sn->GetClientSize(hd, &hd_width, &hd_height);
	if (ret != 0) {
		clientSize.Format(_T("%d * %d"), hd_width, hd_height);
		Log(_T("��ǰģ�����ֱ��ʣ�") + clientSize + _T("\r\n"), game);
		if ((hd_width != 960) || (hd_height != 540)) {
			Log(_T("�뽫ģ������������ȷ�ֱ��ʣ�Ȼ������ģ������\r\n"), game);
			Log(_T("���ֶ������˴�С��������ģ�������ԣ�\r\n"), game);
			Log(_T("ģ�����ֱ��ʲ���960*540����ģ�����������ֶ�����ģ�������ڴ�С��\r\n"), game);
			return 0;
		}
	}
	Log(_T("5.win7��Ҫ�����Ҽ�-���Ի�-˫��windows����!\r\n"), game);
	Log(_T("4.����Ƿ�ʹ�ñ�ֽ����!��ʹ�ã���ر�������������ԣ�����\r\n"), game);
	Log(_T("3.ģ�������ڲ����ֶ�����\r\n"), game);
	Log(_T("2.��ȷ��ͥԺƤ��ΪĬ��/֯����ͥ/��ҹ���֮һ\r\n"), game);
	Log(_T("1.��ȷ��ģ�����ֱ��� 960*540 160dpi\r\n"), game);
	Log(_T("δ�ҵ�ͥԺ���棬����ԭ��\r\n"), game);
	return 1;
}
int yys_function::InYardNoExploreLanternTips(Game *game) {
	Log(_T("4.win7��Ҫ�����Ҽ�-���Ի�-˫��windows����!\r\n"), game);
	Log(_T("3.����Ƿ�ʹ�ñ�ֽ����!��ʹ�ã���ر��������������(��������)������\r\n"), game);
	Log(_T("2.���ʽ��ί���Ƿ���ȡ!!!\r\n"), game);
	Log(_T("1.���ͥԺƤ��ΪĬ��/֯����ͥ/��ҹ���֮һ!!!\r\n"), game);
	Log(_T("��ͥԺ���棬��δ�ҵ�̽������!!!\r\n"), game);
	return 1;
}
//���ļ�
int yys_function::ReadFile(CString filePath, int loff, CStringArray& ListArray)
{
	ListArray.RemoveAll();
	if (!PathFileExists(filePath))
	{
		return 0;
	}
	//�������
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	CStdioFile file;
	if (!file.Open(filePath, CFile::modeRead))
	{
		MessageBox(NULL, _T("��ȡ�ļ�ʧ��!!!"), _T(""), 0);
		return 0;
	}
	file.Seek(loff, 0);
	CString strValue = _T("");
	while (file.ReadString(strValue))
	{
		ListArray.Add(strValue);
	}
	file.Close();
	//�ͷ���Դ
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return (int)ListArray.GetSize();
}
//д�ļ�
int yys_function::WriteFile(CString filePath, int loff, CStringArray& ListArray)
{
	//�������
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	CStdioFile file;
	int listSize = ListArray.GetSize();
	if (listSize == 0) {
		//�ͷ���Դ
		setlocale(LC_CTYPE, old_locale);
		free(old_locale);
		return NULL_LIST;
	}
	if (!file.Open(filePath, CFile::modeWrite | CFile::modeCreate))
	{
		//�ͷ���Դ
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
	//�ͷ���Դ
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return 1;
}

//�༭��ͷ׷������
void yys_function::Log(CString logMsg, Game *game) {
	game->log(logMsg);
	return;
}
//����ӳٵ������ֹ��Ϸ��Ҽ��
int yys_function::DelayPlus(Game *game, snow *sn, int minms, int maxms) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->Delays(minms, maxms);
	//��ͣ
	if (game->getThreadPauseState())
	{
		Log(_T("�߳��ѹ��𣬻ָ�ʱ��ص���ͣʱ�Ľ��棡\r\n"), game);
		if (sn != NULL)
		{
			sn->EnableBind(5);
		}
		while (1)
		{
			sn->delay(3000);
			if (!game->getThreadPauseState())
			{
				Log(_T("�߳��ѻָ�\r\n"), game);
				if (sn != NULL)
				{
					sn->EnableBind(1);
				}
				break;
			}//��ͣʱ�˳�
			if (game->getThreadStopState())
			{
				break;
			}
		}
	}//ֹͣ
	if (game->getThreadStopState()) {
		game->setThreadStartState(false);
		return EXIT_THREAD;
	}
	return 1;
}
//�ж��Ƿ���ͥԺ true:�� false:����
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
		//��̽������   ��ͥ 5C3812-17150A   ��ҹ���  2A373F-141112
		if ((sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1) || (sn->FindStrFast(230, 40, 850, 200, _T("̽|��"), _T("1D1D0C-1E1D0C"), 0.85, &intX, &intY) != -1) || (sn->FindStrFast(230, 40, 850, 200, _T("̽|��"), _T("493B22-493C23"), 0.85, &intX, &intY) != -1) || (sn->FindStrFast(230, 40, 850, 200, _T("̽|��"), _T("25323C-120E10"), 0.8, &intX, &intY) != -1))
		{
			isFind = 1;
			Log(_T("����ͥԺ����...\r\n"), game);
			break;
		}
		DelayPlus(game, sn, 200, 250);
		i--;
	}
	return isFind;
}
//�ж�ͥԺ�Ƿ�չ�� true:չ�� false:�ر�
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
		if (sn->FindStrFast(264, 488, 377, 523, _T("���"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1 || sn->FindStrFast(361, 482, 469, 522, _T("��|��|�"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1)
		{
			findRet = true;
			Log(_T("ͥԺ��չ��...\r\n"), game);
			break;
		}
		DelayPlus(game, sn, 100, 150);
		i--;
	}
	return findRet;
}
//չ��ͥԺ
int yys_function::showYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (!IsShowYard(sn, game))
	{
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("չ��ͥԺ...\r\n"), game);
		sn->MoveToEx(901, 468, 14, 43);
		sn->delay(1000);
		sn->LeftClick();
		return 1;
	}
	return 0;
}
//Ѱ��̽�����������
int yys_function::FindExploreLanTernAndClick(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->UseDict(0);
	//start findFunc
	long intX, intY;
	int delayflag = 0;
	Log(_T("Ѱ��̽������...\r\n"), game);
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//��̽������1B1703-1C1803

		if (sn->FindStrFast(230, 40, 850, 200, _T("̽|��"), _T("1D1D0C-1E1D0C"), 0.85, &intX, &intY) != -1)
		{
			Log(_T("�ҵ�̽������\r\n"), game);
			//���
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 15);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (sn->FindStrFast(230, 40, 850, 200, _T("̽|��"), _T("493B22-493C23"), 0.85, &intX, &intY) != -1)
		{
			Log(_T("�ҵ�̽������\r\n"), game);
			//���
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 15);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (sn->FindStrFast(230, 40, 850, 200, _T("̽|��"), _T("2F363F-181112"), 0.8, &intX, &intY) != -1)//��ҹ���
		{
			Log(_T("�ҵ�̽������\r\n"), game);
			//���
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 15);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(108, 504, 188, 538, _T("��|��"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			Log(_T("�ѽ���̽������...\r\n"), game);
			break;
		}
		else if (sn->FindStrFast(9, 506, 130, 538, _T("��|��"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			Log(_T("�ѽ���̽������...\r\n"), game);
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
//������
int yys_function::CombineTeamAction(snow *sn, Game *game) {
	//������
	if (sn == NULL)
	{
		return false;
	}
	//��ӡ������  C1B7AE-232827
	sn->UseDict(0);
	long intX, intY;
	bool findret = false;
	int i = 10;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����
		if (sn->FindStrFast(264, 488, 377, 523, _T("���"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) !=-1)
		{
			Log(_T("������...\r\n"), game);
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
//��ȡ��ǰλ��
long yys_function::findCurrentSite(CPoint startXY, CPoint endXY, CString picFontLst, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode) {
	if (sn == nullptr) {
		return 0;
	}
	//ʹ���ֿ�
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
//Ѱ�ҷ���ͼ��λ��
long yys_function::findBackIconSite(snow *sn, Game *game, long &intX , long &intY) {
	if (sn == NULL)
	{
		return false;
	}
	//�ֿ�
	sn->UseDict(0);
	if (sn->FindStrFast(0, 0, 56, 58, _T("����"), _T("B39A7E-2B261D"), 0.85, &intX, &intY) != -1) {
		return 0;
	}
	else if (sn->FindStrFast(0, 0, 56, 58, _T("����(��ѩ)"), _T("A1BFD6-393329"), 0.85, &intX, &intY) != -1) {
		return 0;
	}//D7C59A-282F3E  ���ƺ���
	else if (sn->FindStrFast(0, 0, 56, 58, _T("����(����)"), _T("D7C59A-282F3E"), 0.85, &intX, &intY) != -1) {
		return 0;
	}//B2B2DC-424223 ��ҹ�ķ�
	else if (sn->FindStrFast(0, 0, 56, 58, _T("����(��ҹ)"), _T("B2B2DC-424223"), 0.85, &intX, &intY) != -1) {
		return 0;
	}
	
	return -1;
}
//Ѱ���ֶ�ͼ��λ��
long yys_function::findManualSite(snow *sn, Game *game, long &intX, long &intY) {
	if (sn == NULL)
	{
		return false;
	}
	//�ֿ�
	sn->UseDict(4);
	if (sn->FindStrFast(9, 452, 77, 532, _T("�ֶ�"), _T("C7A184-292928"), 0.8, &intX, &intY) != -1) {
		return 0;
	}
	else if (sn->FindStrFast(9, 452, 77, 532, _T("�ֶ�"), _T("CAD5E4-34291A"), 0.85, &intX, &intY) != -1) {
		return 0;
	}// C2BAA3-3C403F
	else if (sn->FindStrFast(9, 452, 77, 532, _T("�ֶ�"), _T("C2BAA3-3C403F"), 0.85, &intX, &intY) != -1) {
		return 0;
	}// CDC9D0-31311C
	else if (sn->FindStrFast(9, 452, 77, 532, _T("�ֶ�"), _T("CDC9D0-31311C"), 0.85, &intX, &intY) != -1) {
		return 0;
	}
	return -1;
}
//Ѱ��Ŀ��λ�ò����---������ֹͣ
int yys_function::findDestSite(CPoint startXY, CPoint endXY, CString picFontLst, long targetSite, CString tartgetPicFont, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode, CString targetTagFont) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�  //433E38-443F38
	sn->UseDict(dictId);
	long intX, intY;
	//����
	int startx = (startXY.x + endXY.x) / 2;
	int starty = startXY.y + (int)((endXY.y - startXY.y)*0.25), endy = startXY.y + (int)((endXY.y - startXY.y)*0.75);
	//�������ֱ��return
	if (!targetTagFont.IsEmpty() && sn->FindStrFast(295, 87, 586, 137, targetTagFont.Left(1), targetTagFont.Mid(2), 0.85, &intX, &intY) != -1) {
		return 1;
	}
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//��Ŀǰ����λ��
		long currentSite = findCurrentSite(startXY, endXY, picFontLst, color_format, sim, dictId, sn, game, mode);
		if (currentSite == -1) {
			return 0;
		}
		//����
		if (targetSite <= currentSite){
			if (mode == _T("findstr") && sn->FindStrFast(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, &intX, &intY) != -1){
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//ģ����ʵ���켣
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else if (mode == _T("findpic") && sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, 0, &intX, &intY) != -1) {
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//ģ����ʵ���켣
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else{
				//ģ����ʵ���켣
				sn->EnableRealMouse(1, 20, 30);
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(startx, 0);
				sn->DragMouse(pos.x, starty, pos.x, endy);
				DelayPlus(game, sn, 500, 800);
			}
		}//����
		else if (targetSite > currentSite){
			if (mode == _T("findstr") && sn->FindStrFast(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, &intX, &intY) != -1){
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//ģ����ʵ���켣
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else if (mode == _T("findpic") && sn->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, tartgetPicFont, color_format, sim, 0, &intX, &intY) != -1) {
				DelayPlus(game, sn, 500, 800);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				DelayPlus(game, sn, 500, 800);
				//ģ����ʵ���켣
				sn->EnableRealMouse(3, 20, 30);
				return 1;
			}
			else{
				//ģ����ʵ���켣
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
//��������---�������
int yys_function::CreatTeamToInviteUpper(int mateType, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(2);
	//�����������
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(754, 457, 805, 484, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y);
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(630, 429, 685, 458, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//���ù���Ȩ��
	while (1)
	{
		if (sn->FindPic(555, 361, 592, 398, _T("������(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			Log(_T("ѡ��Ȩ�޲�����...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//557,365,591,398,
		if (sn->FindPic(557, 365, 591, 398, _T("������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//�������
	while (1)
	{
		if (sn->FindStrFast(630, 429, 685, 458, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y);
			Log(_T("����...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(449, 159, 517, 219, _T("��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
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
	//�������
	while (1)
	{
		if (sn->FindPic(449, 159, 517, 219, _T("��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 6, pos.y + 5);
			Log(_T("��������б�...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((mateType == 0) && (sn->FindPic(345, 68, 403, 104, _T("���(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y + 5);
			Log(_T("ѡ�������Ӻ���...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((mateType == 2) && (sn->FindPic(258, 68, 313, 106, _T("����(δѡ��).bmp"), _T("151515"), 0.85, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y + 5);
			Log(_T("ѡ��ͬ������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((mateType == 3) && (sn->FindPic(520, 72, 572, 101, _T("����(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 15, pos.y + 5);
			Log(_T("ѡ���������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((mateType == 0) && (sn->FindPic(345, 68, 403, 104, _T("���.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			break;
		}
		else if ((mateType == 1) && (sn->FindPic(345, 68, 403, 104, _T("���.bmp|���(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("�̶����ѣ����ֶ�ѡ����ѣ�������룡\r\n"), game);
			if (DelayPlus(game, sn, 800, 802) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("���������...\r\n"), game);
			break;
		}
		else if ((mateType == 2) && (sn->FindPic(258, 68, 313, 106, _T("����(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			break;
		}
		else if ((mateType == 3) && (sn->FindPic(520, 72, 572, 101, _T("����(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (mateType == 0) {
		//�ж��Ƿ�Ϊ�����ӣ��������룬�����˳�
		int combineClock = 0;
		while (1)
		{
			if (sn->FindPic(404, 119, 483, 157, _T("������.bmp|������2.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x - 55, pos.y + 35);
				Log(_T("ѡ���б��е�һλ�����Ӻ���...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(404, 119, 483, 157, _T("������(ѡ��).bmp|������(ѡ��)2.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			combineClock++;
			if (combineClock >= 10) {
				combineClock = -100;
				break;
			}
		}
		//���������Ӻ��ѣ�����ͥԺ
		if (combineClock == -100)
		{
			Log(_T("�б��һλû�������ӱ�ʶ�����ֶ�����һ��...\r\n"), game);
			Log(_T("����ͥԺ��...\r\n"), game);
			if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		//�������
		while (1)
		{
			if (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y);
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (mateType == 1) {
		while (1)
		{
			if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				if (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1) {
					Log(_T("�ָ��Զ�����������ֶ�����...\r\n"), game);
					break;
				}
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (mateType == 2) {
		//�ж��Ƿ�Ϊͬ���̶����ѣ��������룬�����˳�
		int combineClock = 0;
		while (1)
		{
			if (sn->SetPath(_T("config\\imgGame12")) && sn->FindPic(319, 138, 692, 316, sn->MatchPicName(_T("teamer?.bmp")), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 25, pos.y + 8);
				Log(_T("ѡ���б���ͬ���̶�����...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->SetPath(g_path) && sn->FindPic(419, 118, 701, 312, _T("����(ѡ��).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			combineClock++;
			if (combineClock >= 10) {
				combineClock = -100;
				break;
			}
		}
		//δ�ҵ�ͬ���̶�����
		if (combineClock == -100)
		{
			Log(_T("�б���û��ͬ���̶����ѣ������Ƿ��ȡ������ͼ...\r\n"), game);
			Log(_T("����ͥԺ��...\r\n"), game);
			if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		//�������
		while (1)
		{
			if (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y);
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (mateType == 3) {
		//�ж��Ƿ�Ϊ�����̶����ѣ��������룬�����˳�
		int combineClock = 0;
		while (1)
		{
			if (sn->SetPath(_T("config\\imgGame12")) && sn->FindPic(319, 138, 692, 316, sn->MatchPicName(_T("teamer?.bmp")), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 25, pos.y + 8);
				Log(_T("ѡ���б��п����̶�����...\r\n"), game);
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->SetPath(g_path) && sn->FindPic(419, 118, 701, 312, _T("����(ѡ��).bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			combineClock++;
			if (combineClock >= 10) {
				combineClock = -100;
				break;
			}
		}
		//δ�ҵ�ͬ���̶�����
		if (combineClock == -100)
		{
			Log(_T("�б���û�п����̶����ѣ������Ƿ��ȡ������ͼ...\r\n"), game);
			Log(_T("����ͥԺ��...\r\n"), game);
			if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		//�������
		while (1)
		{
			if (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y);
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}

//��ӹ�ϵ
int yys_function::TeamRelation(bool &flag1, bool &flag2, snow *sn, Game *game) {
	//���������ӹ�ϵ
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	game->synchronization(flag1, flag2);
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	return 1;
}
//�����ѽ���������ս 
int yys_function::IsEnterTeam(snow *sn, Game *game, int mateType, int triple) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	if (triple == 0) {
		int timeRecord = 0;
		//�������Ƿ�������
		Log(_T("�ȴ����Ѽ������...\r\n"), game);
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//����ս
			if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
			{
				//���ƫ����������
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("�����Ѽ������...\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (findBackIconSite(sn, game, intX, intY) != -1) {
				break;
			}
			Sleep(1500);
			timeRecord++;
			if (sn->FindPic(874, 436, 953, 518, _T("��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
			{
				if (timeRecord >= 12) {
					Log(_T("����δ���룬�����������...\r\n"), game);
					if(CreatTeamToInviteLower(mateType, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					timeRecord = 0;
				}
			}
		}
	}
	else {
		Log(_T("ע����Ϊ�������ģʽ�����������˲ŻῪʼ...\r\n"), game);
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//����ս
			if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
			{
				long cx = intX, cy = intY;
				if ((sn->FindPic(781, 152, 851, 221, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)&&(sn->FindPic(449, 159, 517, 219, _T("��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) == -1)) {
					//���ƫ����������
					CPoint pos = sn->RandomOffsetPos(cx, cy, 5, 10);
					if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
					Log(_T("�����Ѽ������...\r\n"), game);
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
//�ӳ����븱���¼�
int yys_function::InviteEnterEvent(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int stateCode;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//��׼��
		if (readyFlag && (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//ʤ������
		if (sn->FindPic(286, 34, 438, 169, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 20, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp|��(봽�).bmp|���(봽�).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����ɹ�...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}//298,41,408,147, 
		//ʧ�ܽ���
		if (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			Log(_T("��սʧ��...\r\n"), game);
			stateCode = FAIL;
			break;
		}
		if (sn->FindPic(401, 251, 555, 289, _T("Ĭ���������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			stateCode = DEFAULT;
			break;
		}
		if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp|����֮����ս.bmp|����֮����ս(��).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			stateCode = NOMAL;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return stateCode;
}
//��������
int yys_function::ReceiveFriendInvite(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int isReadyClick = 0;
	//��ʼ
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//����Ĭ������
		if (sn->FindPic(139, 153, 223, 224, _T("����Ĭ������.bmp|����Ĭ������2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("����Ĭ������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 8);
			isReadyClick = 0;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}//������ͨ����
		else if (sn->FindPic(74, 164, 136, 219, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			int temp_x = intX, temp_y = intY;
			Sleep(1500);
			if (sn->FindPic(139, 153, 223, 224, _T("����Ĭ������.bmp|����Ĭ������2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("����Ĭ������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				isReadyClick = 0;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else {
				Log(_T("������ͨ����...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(temp_x, temp_y, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				isReadyClick = 1;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}//832, 393, 941, 536,
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (sn->FindPic(60, 5, 183, 61, _T("Эս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return isReadyClick;
}
//���븱��
int yys_function::EnterEvent(snow *sn, Game *game, bool isReadyClick) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(4);
	//����ֲ�����
	long intX, intY;
	int isReturnAsExitCondition = 0;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (isReadyClick && (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)) {
			Log(_T("���׼��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 3);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(233, 40, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 20, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp|��(봽�).bmp|���(봽�).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			isReturnAsExitCondition = 1;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("��սʧ��...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			isReturnAsExitCondition = 2;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((isReturnAsExitCondition == 1) && (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp|��(봽�).bmp|���(봽�).bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
			Log(_T("����ɹ�...\r\n"), game);
			if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�ȴ���������...\r\n"), game);
			break;
		}
		if ((isReturnAsExitCondition == 2) && (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) == -1)) {
			break;
		}
		/*if (sn->FindPic(74, 164, 136, 219, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("����ɹ�...\r\n"), game);
			if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�ȴ���������...\r\n"), game);
			break;
		}*/
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//Ĭ���������
int yys_function::DefalutInvite(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(4);
	long intX, intY;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//Ĭ������
		if (sn->FindPic(401, 251, 555, 289, _T("Ĭ���������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("Ĭ���������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 8);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(401, 251, 555, 289, _T("Ĭ���������(ѡ).bmp|Ĭ���������(ѡ)2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���ȷ��  4D3A21-4E3B22
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("ȷ������...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 8);
			if (DelayPlus(game, sn, 1800, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
		}
		if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp|����֮����ս.bmp|����֮����ս(��).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ʧ���¼�
int yys_function::FailEvent(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(4);
	long intX, intY;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			Log(_T("ʧ�ܼ����������...\r\n"), game);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			readyFlag = TRUE;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp|����֮����ս.bmp|����֮����ս(��).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//�Զ����ӳ�
int yys_function::auto_open_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	//�ֿ�
	sn->UseDict(0);
	//ģ����ʵ���켣
	sn->EnableRealMouse(1, 20, 30);
	//�Ƿ�ѡ���Զ����ؼӳ�
	//����
	if (jc_category == _T("����"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("���ڴ򿪼ӳ�...\r\n"), game);
			//����ӳɵ���
			int yh_move = 0;
			while (1)
			{
				//�Զ��ܾ����� 79614C-4D3F33
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(446, 95, 569, 390, _T("��|��"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					Log(_T("�ҵ�����ӳ�λ��...\r\n"), game);
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("������ӳ�...\r\n"), game);
						//������ӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ӳ��Ѵ򿪣��رռӳɽ���...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
	//����
	else if (jc_category == _T("����"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("���ڴ򿪼ӳ�...\r\n"), game);
			int jx_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(446, 95, 569, 390, _T("��"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					Log(_T("�ҵ����Ѽӳ�λ��...\r\n"), game);
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�򿪾��Ѽӳ�...\r\n"), game);
						//�򿪼ӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ӳ��Ѵ򿪣��رռӳɽ���...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
	//̽��
	else if (jc_category == _T("̽��"))
	{
		//4B4744-4C4744
		//����ȫ������
		if (jc_index == _T("1"))
		{
			Log(_T("���ڴ򿪼ӳ�...\r\n"), game);
			//����ӳ�
			int jy_move = 0;
			bool jy100Flag = false, jy50Flag = false;
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					Log(_T("���ڼӳɽ���...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ����� 403B37-403C38
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("��50%����ӳ�...\r\n"), game);
						//�򿪼ӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy50Flag = true;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%����ӳ��Ѵ�...\r\n"), game);
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
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("��100%����ӳ�...\r\n"), game);
						//�򿪼ӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy100Flag = true;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%����ӳ��Ѵ�...\r\n"), game);
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
			//��������رռӳɵ���
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (jy50Flag && jy100Flag) {
					Log(_T("�ӳ���ȫ���򿪣��رռӳɽ���...\r\n"), game);
					//�رռӳɿ�
					if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					Log(_T("�ӳɴ�ʧ�ܣ�������...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//�������
		else if (jc_index == _T("2"))
		{
			Log(_T("���ڴ򿪼ӳ�...\r\n"), game);
			Log(_T("��Ҽӳɹ�����δʵ�֣����ֶ��򿪼ӳɺ��ٿ����ű�...\r\n"), game);
			//�ݲ�ʵ�ִ˹���
			return 1;
		}
		//����50%����
		else if (jc_index == _T("3"))
		{
			Log(_T("���ڴ򿪼ӳ�...\r\n"), game);
			int jy_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					Log(_T("���ڼӳɽ���...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("��50%����ӳ�...\r\n"), game);
						//�򿪼ӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 111, tmpy - 8, tmpx + 226, tmpy + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%����ӳ��Ѵ�...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
		//����100%����
		else if (jc_index == _T("4"))
		{
			int jy_move = 0;
			Log(_T("���ڴ򿪼ӳ�...\r\n"), game);
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("��100%����ӳ�...\r\n"), game);
						//�򿪼ӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%����ӳ��Ѵ�...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
	//ģ����ʵ���켣
	sn->EnableRealMouse(3, 20, 30);
	return 1;
}
//�Զ��ؼӳ�
int yys_function::auto_close_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	//�ֿ�
	sn->UseDict(0);
	//ģ����ʵ���켣
	sn->EnableRealMouse(1, 20, 30);
	//�Ƿ�ѡ���Զ����ؼӳ�
	//����
	if (jc_category == _T("����"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("���ڹرռӳ�...\r\n"), game);
			//����ӳɵ���
			int yh_move = 0;
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(446, 95, 569, 390, _T("��|��"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ر�����ӳ�...\r\n"), game);
						//�ر�����ӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 62, tmpy - 11, tmpx + 175, tmpy + 35, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ӳ��ѹرգ��رռӳɽ���...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
	//����
	else if (jc_category == _T("����"))
	{
		if (jc_index == _T("1"))
		{
			Log(_T("���ڹرռӳ�...\r\n"), game);
			int jx_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

				if (sn->FindStrFast(446, 95, 569, 390, _T("��"), _T("4B4742-4B4742"), 0.85, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�رվ��Ѽӳ�...\r\n"), game);
						//�رռӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 80, tmpy - 11, tmpx + 170, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ӳ��ѹرգ��رռӳɽ���...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
	//̽��
	else if (jc_category == _T("̽��"))
	{
		//4B4744-4C4744
		//����ȫ������
		if (jc_index == _T("1"))
		{
			Log(_T("���ڹرռӳ�...\r\n"), game);
			//����ӳ�
			int jy_move = 0;
			bool jy100Flag = true, jy50Flag = true;
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ر�50%����ӳ�...\r\n"), game);
						//�رռӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy50Flag = false;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%����ӳ��ѹر�...\r\n"), game);
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
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ر�100%����ӳ�...\r\n"), game);
						//�رռӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						jy100Flag = false;
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%����ӳ��ѹر�...\r\n"), game);
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
			//��������رռӳɵ���
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if ((!jy50Flag) && (!jy100Flag)) {
					Log(_T("�ӳ���ȫ���رգ��رռӳɽ���...\r\n"), game);
					//�رռӳɿ�
					if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(128, 364, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					Log(_T("�ӳɹر�ʧ�ܣ�������...\r\n"), game);
					break;
				}
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//�رս��
		else if (jc_index == _T("2"))
		{
			Log(_T("���ڹرռӳ�...\r\n"), game);
			Log(_T("��Ҽӳɹ�����δʵ�֣����ֶ��رս�Ҽӳ�...\r\n"), game);
			//�ݲ�ʵ�ִ˹���
			return 1;
		}
		//�ر�50%����
		else if (jc_index == _T("3"))
		{
			Log(_T("���ڹرռӳ�...\r\n"), game);
			int jy_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��50"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ر�50%����ӳ�...\r\n"), game);
						//�رռӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("50%����ӳ��ѹر�...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
		//�ر�100%����
		else if (jc_index == _T("4"))
		{
			int jy_move = 0;
			Log(_T("���ڹرռӳ�...\r\n"), game);
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
				{
					Log(_T("����ӳɵ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x + 5, pos.y + 5);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					Log(_T("���ڼӳɽ���...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (sn->FindStr(446, 95, 569, 390, _T("��10"), _T("4B4742-4B4742"), 0.8, &intX, &intY) != -1)
				{
					long tmpx = intX, tmpy = intY;
					if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("�ر�100%����ӳ�...\r\n"), game);
						//�رռӳ�
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 5, pos.y + 5);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (sn->FindPic(tmpx + 110, tmpy - 11, tmpx + 210, tmpy + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						Log(_T("100%����ӳ��ѹر�...\r\n"), game);
						//�رռӳɿ�
						if (sn->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
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
	//ģ����ʵ���켣
	sn->EnableRealMouse(3, 20, 30);
	return 1;
}
//�Զ��ܾ����ͷ�ӡ
int yys_function::AutoRejectXS(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int flag = 0;
	int is_reject_xs = global1->m_reject.GetCheck();
	//�ܾ����ͷ�ӡ
	if (is_reject_xs&&sn->FindPic(380, 109, 422, 151, _T("Э.bmp|��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		Log(_T("��⵽����...\r\n"), game);
		while (1) {
			if (sn->FindPic(614, 361, 668, 416, _T("�ܾ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ܾ�����...\r\n"), game);
				if (DelayPlus(game, sn, 300, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				flag = 1;
				if (DelayPlus(game, sn, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((flag == 1) && (sn->FindPic(380, 109, 422, 151, _T("Э.bmp|��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (!is_reject_xs&&sn->FindPic(380, 109, 422, 151, _T("Э.bmp|��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		Log(_T("��⵽����...\r\n"), game);
		while (1) {
			if (sn->FindPic(616, 293, 663, 331, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��������...\r\n"), game);
				if (DelayPlus(game, sn, 300, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 5, pos.y + 8);
				flag = 1;
				if (DelayPlus(game, sn, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((flag == 1) && (sn->FindPic(380, 109, 422, 151, _T("Э.bmp|��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//����ͥԺ
int yys_function::returnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�ֿ�
	sn->UseDict(0);
	long intX, intY;
	long exitRes1, exitRes2;
	while (true)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Һ���
		exitRes1 = sn->FindPic(735, 29, 968, 175, _T("��.bmp|��1.bmp|��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if (exitRes1 != -1)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�ҷ���
		exitRes1 = sn->FindPic(0, 0, 217, 107, _T("����1.bmp|����2.bmp|����3.bmp|����4.bmp|����5.bmp|����6.bmp|����7.bmp|����8.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
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
		//���������˳� case3���˳��������
		exitRes1 = sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY);
		exitRes2 = sn->FindStrFast(354, 420, 400, 443, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//̽���˳�
		exitRes1 = sn->FindStrFast(348, 289, 408, 316, _T("ȡ��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY); //̽��ȡ��
		exitRes2 = sn->FindStrFast(558, 292, 608, 316, _T("ȷ��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���������˳� case1��ȡ����������
		exitRes1 = sn->FindStrFast(630, 429, 685, 458, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY);
		exitRes2 = sn->FindStrFast(278, 430, 326, 455, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���������˳� case2���˳�������
		if (sn->FindStrFast(542, 308, 594, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(298, 41, 408, 147, _T("ʧ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(528, 303, 587, 332, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�ɹ�����ͥԺ��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//΢������
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
				Log(_T("΢����Ϣ���ͳɹ���\r\n"), game);
			}
		}
		catch (CInternetException *e) {
			e->Delete();
		}
	}
	return 0;
}