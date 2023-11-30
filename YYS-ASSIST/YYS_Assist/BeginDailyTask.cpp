#include "pch.h"
#include "BeginDailyTask.h"

#define EXIT_THREAD -10
BeginDailyTask::BeginDailyTask() {
	softwind = 1;
	origin_state = 0;
	cruel = 0;
}
//----������ӡ----
//ѡ��	���۶�Լȡ�������������
int BeginDailyTask::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	
	//��ȡĿ��λ��
	CString bmp_font = _T("�������.bmp|��ͼ.bmp|��Ů.bmp|����.bmp|����Ů.bmp|������.bmp|��ʹ��.bmp|С����.bmp|�պͷ�.bmp");
	CString color_format = _T("424243-434243");
	double sim = 0.75;
	int dictId = 2;
	//start ѡ���
	Log(_T("ѡ��������ӡ����...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�������.bmp|�������(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ͼ.bmp|��ͼ(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��Ů.bmp|��Ů(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("����.bmp|����(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("����Ů.bmp|����Ů(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("������.bmp|������(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʹ��.bmp|��ʹ��(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("С����.bmp|С����(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�պͷ�.bmp|�պͷ�(ѡ��).bmp"), _T("202020"), sim, dictId, sn, game, _T("findpic")))
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
	//����ֲ�����
	long intX, intY;
	sn->UseDict(0);
	int closingflag = 0;
	//�Զ�ƥ��
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//������
		if (sn->FindStrFast(264, 488, 377, 523, _T("���"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("������...\r\n"), game);
			if (DelayPlus(game, sn, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
		}
		//����Զ�ƥ��
		if (sn->FindPic(517, 443, 665, 495, _T("�Զ�ƥ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�Ŷ���...\r\n"), game);
		}
		//���Լ���Ϊ����������ս
		if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (condition==0) {
				Log(_T("�Լ���Ϊ�����������ս...\r\n"), game);
				//���ƫ����������
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (condition == 1) {
				Log(_T("��Ϊ�����������˳�����ͥԺ...\r\n"), game);
				if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}
		//��׼��
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//ʤ������
		if (sn->FindPic(286, 34, 438, 169, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 429, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(388, 372, 567, 456, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			closingflag = 1;
		}
		if ((closingflag == 1) && (sn->FindPic(388, 372, 567, 456, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
			Log(_T("����ɹ�...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ʼ����
int BeginDailyTask::StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//�˳��߳�
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��������ӡ
	//��ȡĿ��λ��
	CString fontLst = _T("����|ҵ��|��ת|ˮ��|����|����|����|����|����|����|���|����|ʯ��|���|����|�ع�");
	CString color_format = _T("454039-46413A");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//�ҵ�������ӡ�����
	findDestSite(startXY, endXY, fontLst, 8, _T("����"), color_format, 0.8, 2, sn, game, _T("findstr"), _T("ӡ|CFC8B8-292B28"));
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(monsterKind, startXY, endXY, sn, game);
	if (resultLayer == 0) {
		Log(_T("δ�ҵ�Ŀ��!!!\r\n"), game);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//����������ӡ����
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("��������ӡ��ʼ...\r\n"), game);
		if(EnterYaoQiFengYin(condition, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//----����֮��----
//����ʱ���ֵ
CString BeginDailyTask::GetElapsedTimeString(const CTime& startTime, const CTime& endTime)
{
	CTimeSpan elapsedTime = endTime - startTime;

	int minutes = elapsedTime.GetMinutes();
	int seconds = elapsedTime.GetSeconds();

	CString elapsedTimeString;
	elapsedTimeString.Format(_T("[%02d �� %02d ��]."), minutes, seconds);

	return elapsedTimeString;
}
//Ѱ����֮��
int BeginDailyTask::FindSeaOfMoon(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(1);
	//����ֲ�����
	long intX, intY;
	Log(_T("Ѱ������֮��...\r\n"), game);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���ͻ�� 174,512,245,538��
		if (sn->FindStrFast(690, 513, 763, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("�ҵ�����֮��...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���������λ��
		if (sn->FindStrFast(614, 514, 689, 534, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("�ҵ�����֮��...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(62, 11, 173, 46, _T("����֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ɹ���������֮��...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	sn->UseDict(5);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		
		if (sn->FindStrFast(256, 114, 285, 201, _T("��֮��"), _T("CDCCC1-32333E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("�ҵ���֮��...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ɹ�������֮��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.2 ������֮��
int BeginDailyTask::OpenSeaOfMoon(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	//����ֲ�����
	long intX, intY;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(844, 435, 912, 505, _T("��֮������.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("������֮��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPicSim(844, 424, 935, 508, _T("��֮��ȷ��.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("ȷ������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPicSim(853, 425, 920, 503, _T("��֮������60t.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("ȷ������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(539, 309, 599, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("ȷ������60��...\r\n"), game);
			sn->MoveClick(intX + 10, intY + 13);
			if (DelayPlus(game, sn, 1800, 2500) == EXIT_THREAD) { return EXIT_THREAD; };
		}
		if (sn->FindPicSim(828, 16, 897, 55, _T("������֮��.bmp"), _T("202020"), 85, 0, &intX, &intY) != -1) {
			Log(_T("����...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 6);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(523, 301, 591, 332, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("ȷ����������...\r\n"), game);
			sn->MoveClick(intX + 10, intY + 10);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(188, 243, 762, 286, _T("��籧ů"), _T("B3AEA7-464640"), 0.8, &intX, &intY) != -1) {//A7A19B-4F5049
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(188, 243, 762, 286, _T("��籧ů"), _T("B3AEA7-464640"), 0.8, &intX, &intY) != -1) {
			if (sn->FindStrFast(intX - 60, 430, intX + 100, 465, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {//CAC7B5-2E2C2B
				Log(_T("ѡ����籧ů...\r\n"), game);
				sn->MoveClick(intX + 10, intY + 10);
				if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CString str;
			str.Format(_T("%d"), softwind);
			Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.3 ��������ʶ���¼� 193,296   495,330    761,270
int BeginDailyTask::RadomSelectAndCheckEvent(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	Log(_T("���ѡȡ�ؿ���...\r\n"), game);
	//����ֲ�����
	long intX, intY;
	Scene scene;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

		if (sn->FindStrFast(8, 143, 941, 463, _T("ս|��|��|��|��|��"), _T("E4DBBC-172021"), 0.8, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(827, 0, 888, 47, _T("�����ͼ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�����ͼ���������...\r\n"), game);
			if (sn->FindPic(0, 0, 48, 54, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}

		}
		//4A3821-4B3921
		if (sn->FindStrFast(543, 311, 595, 339, _T("����"), _T("4A3821-4B3921"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(506, 226, 548, 247, _T("�ٻ�"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 311, 417, 337, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȡ���ٻ�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(69, 12, 131, 48, _T("��ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������ս֮��...\r\n"), game);
			scene = BATTLE;
			break;
		}
		//����
		if (sn->FindPic(69, 13, 129, 45, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������֮��...\r\n"), game);
			scene = MYSTERY;
			break;
		}
		//����
		if (sn->FindPic(62, 10, 132, 48, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�������֮��...\r\n"), game);
			scene = ORIGIN;
			break;
		}

		//��Ϣ  
		if (sn->FindPic(64, 13, 133, 44, _T("��Ϣ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������Ϣ֮��...\r\n"), game);
			scene = SILENCE;
			break;
		}
		//��֮�� 
		if (sn->FindPic(68, 10, 152, 45, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������֮��...\r\n"), game);
			scene = ISLANDOFSTAR;
			break;
		}
		//�¶� 
		if (sn->FindPic(68, 11, 173, 48, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������������...\r\n"), game);
			scene = BOSS;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return scene;
}
//	1.3.1 ��ս
int BeginDailyTask::Battle(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;

	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.����Ҳ༼�ܹ�[635,255]
		if (sn->FindPic(69, 12, 131, 48, _T("��ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPicSim(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) == -1) {
				Log(_T("����Ҳ༼�ܹ�...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(635, 255, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPicSim(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��������
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.����Ҳ༼�ܹ�[635,255]
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//�����ս -- ս��--����
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("�����ս...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//2.ѡ����
	//2.1 ����Ƿ���Ҫˢ��
	CPoint ishaveAddState = FindBuff(_T("�ӳ�"), sn, game);
	if (ishaveAddState.x != 0) {
		BattleSelectBuff(sn, game);
	}
	else {
		SelectBuff(sn, game);
	}
	return 0;
}
//	1.3.2 ����
int BeginDailyTask::Mystery(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int imitationorchange = 0;
	//ʹ���ֿ�
	sn->UseDict(5);
	//�жϷ��컹��ת��
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(875, 458, 940, 528, _T("����(��).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("����--����...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(623, 136, 636, 153, _T("5"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 2;
				Log(_T("���5����������...\r\n"), game);
				break;
			}
			/*else if (sn->FindStrFast(623, 136, 636, 153, _T("5"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) == -1) {
				imitationorchange = 1;
				break;
			}*/
			else if (sn->FindStrFast(623, 136, 636, 153, _T("1|2|3|4"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 1;
				Log(_T("��粻��5�������Է���...\r\n"), game);
				break;
			}
		}
		else if (sn->FindPicSim(723, 485, 782, 526, _T("ת��(��).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			imitationorchange = 2;
			Log(_T("����--ת��...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (imitationorchange == 2) {
		//�˳�
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(69, 13, 129, 45, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("�˳�����֮��...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȷ���뿪...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ص���֮��\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��⵽��������\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (imitationorchange == 1) {
		//����
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

			if (sn->FindPicSim(619, 130, 681, 191, _T("�������.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPicSim(187, 57, 256, 122, _T("���(����).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("�ѵ�����...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPicSim(874, 459, 943, 525, _T("����(��).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȷ������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(433, 99, 527, 153, _T("��|��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//434,99,525,155, D4C78C-2B3649
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("����ɹ�...\r\n"), game);
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ص���֮��\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��⵽��������\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 0;
}
//	1.3.3 ����
int BeginDailyTask::Origin(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	//����ֲ�����
	long intX, intY;
	State scene_state;
	//�жϱ���orս��
	if (sn->FindPic(457, 196, 492, 294, _T("���˱�ϻ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		scene_state = TREASURE;
		origin_state = TREASURE;
	}
	else if (sn->FindStrFast(452, 145, 491, 190, _T("��|Ӣ"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {//DFD8CC-202733
		scene_state = ELITE;
	}
	//1.1����--��ȡ/���죿
	if (scene_state == TREASURE) {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(457, 196, 492, 294, _T("���˱�ϻ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("������˱�ϻ...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(846, 436, 924, 518, _T("�������˱�ϻ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("������˱�ϻ...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(398, 91, 526, 149, _T("��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ص���֮��\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��⵽��������\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	if (scene_state == ELITE) {
		//1.2ս��--����
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.����Ҳ༼�ܹ�[635,255]
			if (sn->FindStrFast(452, 145, 491, 190, _T("��|Ӣ"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {
				Log(_T("�����Ӣ��...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��������
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.����Ҳ༼�ܹ�[635,255]
			if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//����ս
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�����ս...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//2.ѡ����
		SelectBuff(sn, game);
	}
	return 0;
}
//	1.3.4 ��Ϣ
int BeginDailyTask::Silence(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//ʹ���ֿ�
	sn->UseDict(5);
	//�˳�
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(877, 434, 941, 497, _T("�뿪��Ϣ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�뿪��Ϣ֮��...\r\n"), game);
			if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(506, 226, 548, 247, _T("�ٻ�"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 311, 417, 337, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȡ���ٻ�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("ȷ���뿪...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ص���֮��\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��⵽��������\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//	1.3.5 ��֮��
int BeginDailyTask::IslandOfStar(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	//����ֲ�����
	long intX, intY;
	int refresh = 0;
	CPoint buffLoc_xy;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(537, 173, 564, 203, _T("Σ"), _T("C9BBBC-364443"), 0.85, &intX, &intY) != -1) {//C9BBBC-364443
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("��⵽��֮��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��������
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.����Ҳ༼�ܹ�[635,255]
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����ս
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�����ս...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			Log(_T("����ɹ�...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//2. ѡ����2/1
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		buffLoc_xy = FindBuff(_T("��������|��֮��"), sn, game);
		if (buffLoc_xy.x != 0) {//�ҵ���������--ѡ��
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("ѡ������or����\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				refresh = 0;
			}
		}
		else {//δ�ҵ���������--ˢ��
			if (sn->FindPic(818, 3, 950, 50, _T("������0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("û��������...\r\n"), game);
				refresh = 3;
			}
			if (sn->FindPic(468, 7, 509, 39, _T("buff2_1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
					//��������ˢ��  
					Log(_T("ˢ��buff\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x + 5, pos.y + 8);
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh++;
				}
			}
		}
		//ˢ������δ�ҵ�
		if ((refresh >= 3) || (sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��(��).bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)) {
			buffLoc_xy = FindBuff(_T("��������"), sn, game);
			//ѡ���´�֮��
			if (sn->FindPic(462, 8, 516, 39, _T("buff2_1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (buffLoc_xy.x == 0 && sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("ѡ��[�´�֮��]\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh = 0;
				}
			}
		}
		if (sn->FindStrFast(511, 298, 601, 335, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("ȷ��ˢ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(468, 7, 509, 39, _T("buff2_2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//  ѡ����2/2
	SelectBuff(sn, game);
	return 0;

}
//1.4 ѡbuff
//1.4.1 ���������
CPoint BeginDailyTask::FindBuff(CString buffname, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	long intX, intY;
	CString findname = _T("��籧ů|������Ű|��������|ϸ�껯��");
	CString defendandScroll = _T("��������|��֮��");
	CPoint bufflocXY(0, 0);
	int i = 5, buffcode = -1;
	while (i > 0) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((buffcode = sn->FindStrFast(110, 246, 212, 285, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("�ҵ�[") + buffname + _T("]\r\n"), game);
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Mid(5, 4) + _T("]\r\n"), game);
					break;
				}
				case 2: {
					Log(_T("�ҵ�[") + buffname.Mid(10, 4) + _T("]\r\n"), game);
					break;
				}
				case 3: {
					Log(_T("�ҵ�[") + buffname.Right(4) + _T("]\r\n"), game);
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
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Right(3) + _T("]\r\n"), game);
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
				Log(_T("�ҵ�[") + buffname + _T("]\r\n"), game);
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Mid(5, 4) + _T("]\r\n"), game);
					break;
				}
				case 2: {
					Log(_T("�ҵ�[") + buffname.Mid(10, 4) + _T("]\r\n"), game);
					break;
				}
				case 3: {
					Log(_T("�ҵ�[") + buffname.Right(4) + _T("]\r\n"), game);
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
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Right(3) + _T("]\r\n"), game);
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
				Log(_T("�ҵ�[") + buffname + _T("]\r\n"), game);
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Mid(5, 4) + _T("]\r\n"), game);
					break;
				}
				case 2: {
					Log(_T("�ҵ�[") + buffname.Mid(10, 4) + _T("]\r\n"), game);
					break;
				}
				case 3: {
					Log(_T("�ҵ�[") + buffname.Right(4) + _T("]\r\n"), game);
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
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Right(3) + _T("]\r\n"), game);
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
//1.4.2 ͨ��ѡbuff
int BeginDailyTask::SelectBuff(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	int refresh = 0, buff_res = -1;
	//----------��ͼ-----------
	//���ȼ�����籧ů>������Ű>��������>ϸ�껯��>�´�֮��(�ָ�5%Ѫ��)
	// -- ѡ���ܲ��� --
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����
		buffLoc_xy = FindBuff(_T("��籧ů"), sn, game);
		//�ҵ����--ѡ�����
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("ѡ����\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
				refresh = 0;
			}
		}//δ�ҵ����
		else {
			if (softwind < 3) {//���<3�� -- ˢ��
				if (sn->FindPic(818, 3, 950, 50, _T("������0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
					refresh = 3;
				}
				if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
					//��������ˢ��
					Log(_T("ˢ��buff\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x + 5, pos.y + 8);
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh++;
				}
			}
			else if (softwind >= 3) {//���>3�� -- ������ �ҵ���ѡ��  
				buffLoc_xy = FindBuff(_T("��籧ů|������Ű|��������|ϸ�껯��"), sn, game);
				if (buffLoc_xy.x != 0) {
					if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("ѡ����\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						refresh = 0;
					}
				}
				else {//�Ҳ�����ˢ��
					if (sn->FindPic(818, 3, 950, 50, _T("������0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
						refresh = 3;
					}
					if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
						//��������ˢ��
						Log(_T("ˢ��buff\r\n"), game);
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x + 5, pos.y + 8);
						refresh++;
						if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
			}
		}
		//ˢ������δ�ҵ�
		if ((refresh >= 3) || (sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��(��).bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)) {
			buffLoc_xy = FindBuff(_T("��籧ů|������Ű|��������|ϸ�껯��"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ѡ����\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh = 0;
				}
			}
			//ѡ���´�֮��
			else if (buffLoc_xy.x == 0 && sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				Log(_T("ѡ��[�´�֮��]\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				refresh = 0;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(511, 298, 601, 335, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("ȷ��ˢ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (sn->FindStrFast(398, 91, 526, 149, _T("��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//D4C78C-2B3649  441,90,527,150,
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ص���֮��\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��⵽��������\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.4.3 ��սѡ�ͼ�buff
int BeginDailyTask::BattleSelectBuff(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	//----------��ͼ-----------
	//���ȼ�����籧ů>������Ű>��������>ϸ�껯��>�´�֮��(�ָ�5%Ѫ��)
	// -- ѡ���ܲ��� --
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����
		buffLoc_xy = FindBuff(_T("��籧ů"), sn, game);
		//�ҵ����--ѡ�����
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("ѡ����\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
			}
		}//δ�ҵ����
		else {
			//--������(include softwind)
			buffLoc_xy = FindBuff(_T("��籧ů|������Ű|��������|ϸ�껯��"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ѡ����\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}//δ�ҵ�����--recover blood
			else {
				//ѡ���´�֮��
				if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("ѡ��[�´�֮��]\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (sn->FindStrFast(398, 91, 526, 149, _T("��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ص���֮��\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��⵽��������\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.5 ӭս�¶�
int BeginDailyTask::ToWardsTsukuyomi(snow *sn, Game *game) {
	//
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int ispack = 0, defentusexy = 0, defentusexx = 0, fireScrollxy = 0, fireScrollxx = 0;
	CString violence, finerain, demonpower;
	violence = _T("���ܱ�Ű12_31_32_33.bmp|���ܱ�Ű13_14_34.bmp|���ܱ�Ű21.bmp|���ܱ�Ű22.bmp|���ܱ�Ű23_24.bmp");
	finerain = _T("����ϸ��12_13_14_31_32_33_34.bmp|����ϸ��21_22_23_24.bmp");
	demonpower = _T("��������12.bmp|��������13.bmp|��������14_33.bmp|��������21.bmp|��������22.bmp|��������23.bmp|��������24.bmp|��������31_32.bmp|��������34.bmp");

	//ʹ���ֿ�
	sn->UseDict(5);
	//�ж��Ƿ�ս������
	if (origin_state == TREASURE) {
		//��ս
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; } //BDB6A8-31323E
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPicSim(635, 463, 685, 518, _T("��ս.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("�����ս...\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindPicSim(61, 9, 139, 53, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("�ѽ��뱸ս����...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���뼼��װ�����
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(752, 331, 803, 377, _T("��buff.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("����װ��...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(64, 10, 177, 51, _T("����װ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("�ѽ��뼼��װ�����...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��������
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(523, 471, 571, 520, _T("����.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("��������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(528, 303, 587, 332, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//ȷ������
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(528, 303, 587, 332, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȷ������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(64, 10, 177, 51, _T("����װ��.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				Log(_T("���óɹ�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//װ�似�� ��籧ů
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
				if (sn->FindPicSim(604, 53, 927, 311, _T("�������.bmp|�������2.bmp"), _T("202020"), 85, 0, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("װ����籧ů...\r\n"), game);
					if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȷ��װ��...\r\n"), game);
				ispack = 1;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
				if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
				ispack = 0;
				break;
			}
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//������Ű
		if (sn->FindPic(604, 53, 927, 311, violence, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
					if (sn->FindPicSim(604, 53, 927, 311, violence, _T("202020"), 85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("װ��������Ű...\r\n"), game);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ȷ��װ��...\r\n"), game);
					ispack = 1;
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
					if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
					ispack = 0;
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		else { Log(_T("δ����������Ű...\r\n"), game); }
		//ϸ�껯��
		if (sn->FindPic(604, 53, 927, 311, finerain, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
					if (sn->FindPicSim(604, 53, 927, 311, finerain, _T("202020"), 85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("װ��ϸ�껯��...\r\n"), game);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ȷ��װ��...\r\n"), game);
					ispack = 1;
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
					if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
					ispack = 0;
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		else { Log(_T("δ����ϸ�껯��...\r\n"), game); }
		//��������
		if (sn->FindPic(604, 53, 927, 311, demonpower, _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1) {
					if (sn->FindPicSim(604, 53, 927, 311, demonpower, _T("202020"), 85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("װ����������...\r\n"), game);
						if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ȷ��װ��...\r\n"), game);
					ispack = 1;
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if ((ispack == 1) && (sn->FindStrFast(313, 440, 371, 474, _T("װ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) == -1)) {
					if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
					ispack = 0;
					break;
				}
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		else { Log(_T("δ������������...\r\n"), game); }
		//������������
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(64, 10, 177, 51, _T("����װ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("���ر�ս����...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindPicSim(61, 9, 139, 53, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("������������...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ɹ�������������...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		origin_state = 0;
	}
	//��ս�¶�
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(844, 427, 928, 511, _T("�¶���ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("��ս�¶�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		/*if (sn->FindPic(851, 6, 928, 35, _T("�����¶�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}*/
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//������
		if (sn->FindPic(240, 0, 302, 57, _T("���¶�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (defentusexy < 1 && sn->FindPic(719, 69, 862, 130, _T("��������.bmp|��������2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("ʹ�ù�������...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				defentusexy++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (fireScrollxy < 1 && sn->FindPic(723, 73, 850, 125, _T("��֮��.bmp|��֮��2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("ʹ�û�֮��...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				fireScrollxy++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(240, 0, 302, 57, _T("Ů�¶�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (defentusexx < 1 && sn->FindPic(719, 69, 862, 130, _T("��������.bmp|��������2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("ʹ�ù�������...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				defentusexx++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (fireScrollxx < 1 && sn->FindPic(719, 69, 862, 130, _T("��֮��.bmp|��֮��2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("ʹ�û�֮��...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				fireScrollxx++;
				if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//������������  433C34-433C34
		if (sn->FindStrFast(439, 260, 477, 281, _T("����"), _T("433C34-433C34"), 0.85, &intX, &intY) != -1) {
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(407, 256, 463, 284, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("��������...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(405, 253, 437, 286, _T("��������(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(405, 253, 437, 286, _T("��������(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 312, 416, 337, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȡ������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//��սʧ��
		if (sn->FindStrFast(519, 311, 571, 337, _T("����"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("��սʧ�ܣ�����ǰ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(529, 305, 583, 329, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			Log(_T("ȷ������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(510, 318, 588, 350, _T("ʹ��"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("ȷ��ʹ��1������͸�...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(411, 93, 539, 170, _T("�ý�"), _T("C8BA87-373844"), 0.85, &intX, &intY) != -1) {//C8BA87-373844
			Log(_T("��ý���...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(438, 88, 535, 129, _T("�ȼ�����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ȼ�����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(467, 95, 579, 149, _T("���ܽ���.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���ܽ���...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(422, 466, 515, 511, _T("ǰ���鿴.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������һ����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(488, 463, 538, 507, _T("ǰ���鿴(��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������һ����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(812, 440, 876, 517, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPic(71, 92, 218, 214, _T("��֮��_��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("������֣���\r\n"), game);
				extream++;	//��¼������
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(71, 92, 218, 214, _T("��֮��_��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("������֣���\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			Log(_T("������һ����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(649, 150, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(844, 435, 912, 505, _T("��֮������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�ɹ����س�ʼ����...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.6 ���ݳ���ִ������
int BeginDailyTask::AccordingSceneRun(int scene, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//��ս֮��
	if (scene == BATTLE) {
		if (Battle(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����
	if (scene == MYSTERY) {
		if (Mystery(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����
	if (scene == ORIGIN) {
		if (Origin(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��Ϣ  
	if (scene == SILENCE) {
		if (Silence(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��֮�� 
	if (scene == ISLANDOFSTAR) {
		if (IslandOfStar(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//�¶� 
	if (scene == BOSS) {
		if (ToWardsTsukuyomi(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return scene;
}
//2.0 ��ʼ���� ��������
int BeginDailyTask::StartSixPathOfDoor(long hd, int round, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	int scene;
	Log(_T("��ʼǰ����ͥԺ��������...\r\n"), game);
	Log(_T("��ʼǰ��ȷ�����ú�����...\r\n"), game);
	Log(_T("��ʼǰ��ȷ����ѡ��ͼ...\r\n"), game);
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//1.Ѱ
	if (FindSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	CString count_str;
	int scene_res = -1;
	extream = 0;
	while (count < round) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("����֮��̽��...\r\n"), game);
		//��ʼʱ��
		CTime startTime = CTime::GetCurrentTime();
		//��ʼ������¼
		softwind = 1;
		//2.������֮��
		if (OpenSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//3.���ѡ�񳡾�
			if ((scene = RadomSelectAndCheckEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//4.���ݳ���ִ������
			if ((scene_res = AccordingSceneRun(scene, sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//�˳�����
			if (scene_res == BOSS) {
				scene_res = -1;
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		count_str.Format(_T("%d"), count);
		Log(_T("�ѽ���") + count_str + _T("����֮��̽��\r\n"), game);
		count_str.Format(_T("%d"), extream);
		Log(_T("��������ּ�") + count_str + _T("��\r\n"), game);
		//����ʱ��
		CTime endTime = CTime::GetCurrentTime();
		//��ʱ
		CString elapsedTimeString = GetElapsedTimeString(startTime, endTime);
		Log(_T("���ֺ�ʱ") + elapsedTimeString + _T("\r\n"), game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����ͥԺ
	if (count >= round) {
		SixPathOfDoorReturnYard(sn, game);
	}

	return 0;
}
//����֮�ŷ���ͥԺ
int BeginDailyTask::SixPathOfDoorReturnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(0);
	//����ֲ�����
	long intX, intY;
	//��ʼ����
	Log(_T("��������ɣ����ڷ���ͥԺ...\r\n"), game);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(0, 0, 48, 54, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(16, 9, 60, 49, _T("���鷵��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(15, 13, 73, 72, _T("����1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//760, 83, 814, 135,
		if (sn->FindPic(9, 18, 61, 76, _T("����5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 1, 65, 59, _T("����4.bmp|����8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 5, intY + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�ɹ�����ͥԺ��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//----����֮��(4�������)----
//	1.3.12 ��ս
int BeginDailyTask::BattleOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.����Ҳ༼�ܹ�[635,255]
		if (sn->FindPic(69, 12, 131, 48, _T("��ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPicSim(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) == -1) {
				Log(_T("����Ҳ༼�ܹ�...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(635, 255, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPicSim(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��������
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//1.����Ҳ༼�ܹ�[635,255]
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//�����ս -- ս��--����
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("�����ս...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//2.ѡ����
	//2.1 ����Ƿ���Ҫˢ��
	CPoint ishaveAddState = FindBuffOnlySoftWind(_T("�ӳ�"), sn, game);
	if (ishaveAddState.x != 0) {
		BattleSelectBuffOnlySoftWind(sn, game);
	}
	else {
		SelectBuffOnlySoftWind(sn, game);
	}
	return 0;
}
//	1.3.22 ����
int BeginDailyTask::MysteryOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int imitationorchange = 0;
	//ʹ���ֿ�
	sn->UseDict(5);
	//�жϷ��컹��ת��
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPicSim(875, 458, 940, 528, _T("����(��).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			Log(_T("����--����...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(623, 136, 636, 153, _T("5"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 2;
				Log(_T("���5����������...\r\n"), game);
				break;
			}
			else if (sn->FindStrFast(623, 136, 636, 153, _T("1|2|3|4"), _T("D7CEBA-282C2B"), 0.8, &intX, &intY) != -1) {
				imitationorchange = 1;
				Log(_T("��粻��5�������Է���...\r\n"), game);
				break;
			}
		}
		else if (sn->FindPicSim(723, 485, 782, 526, _T("ת��(��).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
			imitationorchange = 2;
			Log(_T("����--ת��...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if (imitationorchange == 2) {
		//�˳�
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(69, 13, 129, 45, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindPic(0, 0, 48, 54, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("�˳�����֮��...\r\n"), game);
					if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȷ���뿪...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ص���֮��\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��⵽��������\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (imitationorchange == 1) {
		//����
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }

			if (sn->FindPicSim(619, 130, 681, 191, _T("�������.bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPicSim(187, 57, 256, 122, _T("���(����).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("�ѵ�����...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPicSim(874, 459, 943, 525, _T("����(��).bmp"), _T("202020"), 90, 0, &intX, &intY) != -1) {
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȷ������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(433, 99, 527, 153, _T("��|��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//434,99,525,155, D4C78C-2B3649
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("����ɹ�...\r\n"), game);
				softwind++;
				CString str;
				str.Format(_T("%d"), softwind);
				Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ص���֮��\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��⵽��������\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 0;
}
//	1.3.32 ����
int BeginDailyTask::OriginOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	//����ֲ�����
	long intX, intY;
	State scene_state;
	//�жϱ���orս��
	if (sn->FindPic(457, 196, 492, 294, _T("���˱�ϻ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
		scene_state = TREASURE;
	}
	else if (sn->FindStrFast(452, 145, 491, 190, _T("��|Ӣ"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {//DFD8CC-202733
		scene_state = ELITE;
	}
	//1.1����--��ȡ/���죿
	if (scene_state == TREASURE) {
		//�˳�
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(877, 451, 931, 504, _T("�뿪����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("�뿪����֮��...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(506, 226, 548, 247, _T("�ٻ�"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
				if (sn->FindStrFast(367, 311, 417, 337, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ȡ���ٻ�...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(intX, intY);
				Log(_T("ȷ���뿪...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ص���֮��\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��⵽��������\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	if (scene_state == ELITE) {
		//1.2ս��--����
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.����Ҳ༼�ܹ�[635,255]
			if (sn->FindStrFast(452, 145, 491, 190, _T("��|Ӣ"), _T("DFD8CC-202733"), 0.8, &intX, &intY) != -1) {
				Log(_T("�����Ӣ��...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��������
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//1.����Ҳ༼�ܹ�[635,255]
			if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//����ս
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�����ս...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//2.ѡ����
		SelectBuffOnlySoftWind(sn, game);
	}
	return 0;
}
//	1.3.42 ��Ϣ
int BeginDailyTask::SilenceOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//ʹ���ֿ�
	sn->UseDict(5);
	//�˳�
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(877, 434, 941, 497, _T("�뿪��Ϣ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("�뿪��Ϣ֮��...\r\n"), game);
			if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(506, 226, 548, 247, _T("�ٻ�"), _T("4D453B-4D453C"), 0.85, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 311, 417, 337, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȡ���ٻ�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("ȷ���뿪...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ص���֮��\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��⵽��������\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//	1.3.52 ��֮��
int BeginDailyTask::IslandOfStarOnlySoftWind(int subsel, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	//����ֲ�����
	long intX, intY;

	
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(537, 173, 564, 203, _T("Σ"), _T("C9BBBC-364443"), 0.85, &intX, &intY) != -1) {//C9BBBC-364443
			if (subsel != 2) {
				if (softwind < 3) {
					CPoint pos = sn->RandomOffsetPos(322, 233, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("��粻��3����ѡ����ͨ��...\r\n"), game);
				}
				else if (softwind >= 3) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("�����ڵ���3����ѡ����֮��...\r\n"), game);
				}
			}
			else {
				CPoint pos = sn->RandomOffsetPos(322, 233, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("������֮�ӣ�ѡ����ͨ��...\r\n"), game);
			}
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��������
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//��������
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 3);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(710, 494, 751, 533, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����ս
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(848, 433, 931, 516, _T("��֮����ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�����ս...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
			Log(_T("����ɹ�...\r\n"), game);
			break;
		}
		if (sn->FindStrFast(398, 91, 526, 149, _T("��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
			Log(_T("����ɹ�...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ս��--����
	if (softwind >= 3 && subsel != 2) {
		//ѡ����2/1
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//ˢ������δ�ҵ�
				//ѡ���´�֮��
			if (sn->FindPic(462, 8, 516, 39, _T("buff2_1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("ѡ��[�´�֮��]\r\n"), game);
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
		//ѡ����2/2
		SelectBuffOnlySoftWind(sn, game);
	}
	else {
		//ս��--����
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindStrFast(398, 91, 526, 149, _T("��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�ص���֮��\r\n"), game);
				break;
			}
			if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��⵽��������\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 0;

}
//1.42 ѡbuff
//1.4.12 ���������
CPoint BeginDailyTask::FindBuffOnlySoftWind(CString buffname, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	long intX, intY;
	CString findname = _T("��籧ů|������Ű");
	CPoint bufflocXY(0, 0);
	int i = 5, buffcode = -1;
	while (i > 0) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((buffcode = sn->FindStrFast(110, 246, 212, 285, buffname, _T("B3AEA7-464640"), 0.8, &intX, &intY)) != -1) {
			bufflocXY.x = intX;
			bufflocXY.y = intY;
			if (buffname.GetLength() == 4) {
				Log(_T("�ҵ�[") + buffname + _T("]\r\n"), game);
				if(buffname==_T("��籧ů")){
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
				}
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Right(4) + _T("]\r\n"), game);
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
				Log(_T("�ҵ�[") + buffname + __T("]\r\n"), game);
				if (buffname == _T("��籧ů")) { 
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
				}
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Right(4) + _T("]\r\n"), game);
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
				Log(_T("�ҵ�[") + buffname + _T("]\r\n"), game);
				if (buffname == _T("��籧ů")) {
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
				}
			}
			else if (buffname == findname) {
				switch (buffcode)
				{
				case 0: {
					Log(_T("�ҵ�[") + buffname.Left(4) + _T("]\r\n"), game);
					softwind++;
					CString str;
					str.Format(_T("%d"), softwind);
					Log(_T("��ǰ��籧ů[Lv") + str + _T("]\r\n"), game);
					break;
				}
				case 1: {
					Log(_T("�ҵ�[") + buffname.Right(4) + _T("]\r\n"), game);
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
//1.4.22 ͨ��ѡbuff
int BeginDailyTask::SelectBuffOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	int refresh = 0, buff_res = -1;
	//----------��ͼ-----------
	//���ȼ�����籧ů>������Ű>�´�֮��(�ָ�5%Ѫ��)
	// -- ѡ���ܲ��� --
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����
		buffLoc_xy = FindBuffOnlySoftWind(_T("��籧ů"), sn, game);
		//�ҵ����--ѡ�����
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("ѡ����\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				refresh = 0;
			}
		}
		//δ�ҵ����
		else {
			//���<4�� -- ˢ��
			if (softwind < 4) {
				if (sn->FindPic(818, 3, 950, 50, _T("������0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1) {
					refresh = 3;
				}
				if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
					//��������ˢ��
					Log(_T("ˢ��buff\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x + 5, pos.y + 8);
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh++;
				}
			}
			//���>4�� -- ������ �ҵ���ѡ��  
			else if (softwind >= 4) {
				buffLoc_xy = FindBuffOnlySoftWind(_T("��籧ů|������Ű"), sn, game);
				//�ҵ���ѡ��
				if (buffLoc_xy.x != 0) {
					if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("ѡ����\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						refresh = 0;
					}
				}
				//�Ҳ�����ˢ��
				else {
					//��Ű>2 �� ��������ˢ��
					if ((cruel>=2) || (sn->FindPic(818, 3, 950, 50, _T("������0.bmp"), _T("101010"), 0.85, 0, &intX, &intY) != -1)) {
						refresh = 3;
					}
					if (refresh < 3 && sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��.bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1) {
						//��������ˢ��
						Log(_T("ˢ��buff\r\n"), game);
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
						sn->MoveClick(pos.x + 5, pos.y + 8);
						refresh++;
						if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					}
				}
			}
		}
		//ˢ������δ�ҵ�
		if ((refresh >= 3) || (sn->FindPic(877, 454, 945, 512, _T("��֮��ˢ��(��).bmp"), _T("101010"), 0.9, 0, &intX, &intY) != -1)) {
			buffLoc_xy = FindBuffOnlySoftWind(_T("��籧ů|������Ű"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ѡ����\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					refresh = 0;
				}
			}
			//ѡ���´�֮��
			else if (buffLoc_xy.x == 0 && sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				Log(_T("ѡ��[�´�֮��]\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				refresh = 0;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindStrFast(511, 298, 601, 335, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 10, intY + 10);
			Log(_T("ȷ��ˢ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		if (sn->FindStrFast(398, 91, 526, 149, _T("��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {//D4C78C-2B3649  441,90,527,150,
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ص���֮��\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��⵽��������\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.4.32 ��սѡ�ͼ�buff
int BeginDailyTask::BattleSelectBuffOnlySoftWind(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(5);
	CPoint buffLoc_xy;
	long intX, intY;
	//----------��ͼ-----------
	//���ȼ�����籧ů>������Ű>�´�֮��(�ָ�5%Ѫ��)
	// -- ѡ���ܲ��� --
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����
		buffLoc_xy = FindBuffOnlySoftWind(_T("��籧ů"), sn, game);
		//�ҵ����--ѡ�����
		if (buffLoc_xy.x != 0) {
			if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				Log(_T("ѡ����\r\n"), game);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}//δ�ҵ����
		else {
			//--������(include softwind)
			buffLoc_xy = FindBuffOnlySoftWind(_T("��籧ů|������Ű"), sn, game);
			if (buffLoc_xy.x != 0) {
				if (sn->FindStrFast(buffLoc_xy.x - 40, 433, buffLoc_xy.x + 100, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("ѡ����\r\n"), game);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}//δ�ҵ�����--recover blood
			else {
				//ѡ���´�֮��
				if (sn->FindStrFast(769, 433, 866, 467, _T("ѡ��"), _T("CAC7B5-2E2C2B"), 0.85, &intX, &intY) != -1) {
					Log(_T("ѡ��[�´�֮��]\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (sn->FindStrFast(398, 91, 526, 149, _T("��"), _T("D4C78C-2B3649"), 0.8, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(70, 8, 152, 46, _T("��֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ص���֮��\r\n"), game);
			break;
		}
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��⵽��������\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.5 ӭս�¶�
int BeginDailyTask::ToWardsTsukuyomiOnlySoftWind(snow *sn, Game *game) {
	//
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//ʹ���ֿ�
	sn->UseDict(5);
	//�ж��Ƿ���ս 
	if (softwind < 4) {
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(0, 0, 48, 54, _T("��֮������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(540, 253, 580, 294, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		while (1) {
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(540, 253, 580, 294, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("��������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(537, 306, 601, 343, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				Log(_T("ȷ������...\r\n"), game);
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindStrFast(510, 318, 588, 350, _T("ʹ��"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
				break;
			}
			if (sn->FindStrFast(411, 93, 539, 170, _T("�ý�"), _T("C8BA87-373844"), 0.85, &intX, &intY) != -1) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	//��ս�¶�
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(58, 9, 175, 50, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(844, 427, 928, 511, _T("�¶���ս.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("��ս�¶�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		/*if (sn->FindPic(851, 6, 928, 35, _T("�����¶�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 5);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}*/
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 20, 30) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//������������  433C34-433C34
		if (sn->FindStrFast(439, 260, 477, 281, _T("����"), _T("433C34-433C34"), 0.85, &intX, &intY) != -1) {
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(407, 256, 463, 284, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
					sn->MoveClick(pos.x, pos.y);
					Log(_T("��������...\r\n"), game);
					if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(405, 253, 437, 286, _T("��������(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(405, 253, 437, 286, _T("��������(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindStrFast(367, 312, 416, 337, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("ȡ������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//��սʧ��
		if (sn->FindStrFast(519, 311, 571, 337, _T("����"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("��սʧ�ܣ�����ǰ��...\r\n"), game);
			softwind = 0;
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(529, 305, 583, 329, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			Log(_T("ȷ������...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (softwind > 3 && sn->FindStrFast(510, 318, 588, 350, _T("ʹ��"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("ȷ��ʹ��1������͸�...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (softwind <= 3 && sn->FindStrFast(390, 316, 444, 349, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.9, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			Log(_T("δ��ս����ʹ������͸�...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(411, 93, 539, 170, _T("�ý�"), _T("C8BA87-373844"), 0.85, &intX, &intY) != -1) {//C8BA87-373844
			Log(_T("��ý���...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(438, 88, 535, 129, _T("�ȼ�����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ȼ�����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(467, 95, 579, 149, _T("���ܽ���.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���ܽ���...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(846, 445, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(422, 466, 515, 511, _T("ǰ���鿴.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������һ����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(488, 463, 538, 507, _T("ǰ���鿴(��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("������һ����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(513, 102, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(812, 440, 876, 517, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (sn->FindPic(71, 92, 218, 214, _T("��֮��_��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("������֣���\r\n"), game);
				extream++;	//��¼������
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (sn->FindPic(71, 92, 218, 214, _T("��֮��_��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("������֣���\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			Log(_T("������һ����...\r\n"), game);
			CPoint pos = sn->RandomOffsetPos(649, 150, 5, 10);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(844, 435, 912, 505, _T("��֮������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�ɹ����س�ʼ����...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
//1.62 ���ݳ���ִ������
int BeginDailyTask::AccordingSceneRunOnlySoftWind(int scene, int subsel,  snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//��ս֮��
	if (scene == BATTLE) {
		if (BattleOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����
	if (scene == MYSTERY) {
		if (MysteryOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����
	if (scene == ORIGIN) {
		if (OriginOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��Ϣ  
	if (scene == SILENCE) {
		if (SilenceOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//��֮�� 
	if (scene == ISLANDOFSTAR) {
		if (IslandOfStarOnlySoftWind(subsel, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//�¶� 
	if (scene == BOSS) {
		if (ToWardsTsukuyomiOnlySoftWind(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return scene;
}
//2.02 ��ʼ���� ��������
int BeginDailyTask::StartSixPathOfDoorOnlySoftWind(long hd, int round, int subsel, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	int scene;
	Log(_T("��ʼǰ����ͥԺ��������...\r\n"), game);
	Log(_T("��ʼǰ��ȷ�����ú�����...\r\n"), game);
	Log(_T("��ʼǰ��ȷ����ѡ��ͼ...\r\n"), game);
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	//1.Ѱ
	if (FindSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	CString count_str;
	int scene_res = -1;
	extream = 0;
	while (count < round) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("����֮��̽��...\r\n"), game);
		//��ʼʱ��
		CTime startTime = CTime::GetCurrentTime();
		//��ʼ������¼
		softwind = 1;
		cruel = 0;
		//2.������֮��
		if (OpenSeaOfMoon(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			//3.���ѡ�񳡾�
			if ((scene = RadomSelectAndCheckEvent(sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//4.���ݳ���ִ������
			if ((scene_res = AccordingSceneRunOnlySoftWind(scene, subsel, sn, game)) == EXIT_THREAD) { return EXIT_THREAD; }
			//�˳�����
			if (scene_res == BOSS) {
				scene_res = -1;
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		count_str.Format(_T("%d"), count);
		Log(_T("�ѽ���") + count_str + _T("����֮��̽��\r\n"), game);
		count_str.Format(_T("%d"), extream);
		Log(_T("��������ּ�") + count_str + _T("��\r\n"), game);
		//����ʱ��
		CTime endTime = CTime::GetCurrentTime();
		//��ʱ
		CString elapsedTimeString = GetElapsedTimeString(startTime, endTime);
		Log(_T("���ֺ�ʱ") + elapsedTimeString + _T("\r\n"), game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����ͥԺ
	if (count >= round) {
		SixPathOfDoorReturnYard(sn, game);
	}

	return 0;
}

//----�ճ�����----
int BeginDailyTask::EnterTaskFunc(long hd, int condition, CString picName, CString fontName, int mode_index, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	sn->UseDict(0);
	int closingflag = 0;
	//��ȡĿ��λ��
	CString fontLst = _T("����|ҵ��|��ת|ˮ��|����|����|����|����|����|����|���|����|ʯ��|���|����|�ع�");
	CString color_format = _T("454039-46413A");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//�˳��߳�
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��subsel
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(307, 98, 425, 130, picName, _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("��ѡ��")+ fontName +_T("����...\r\n"), game);
			break;
		}
		//�������/�������/����...
		findDestSite(startXY, endXY, fontLst, mode_index, fontName, color_format, 0.8, 2, sn, game);
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����Զ�ƥ��
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//����Զ�ƥ��
		if (sn->FindPic(517, 443, 665, 495, _T("�Զ�ƥ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX, intY);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�Զ�ƥ��...\r\n"), game);
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�Ŷ���...\r\n"), game);
			break;
		}
		if (sn->FindPic(60, 5, 183, 61, _T("Эս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�ѽ���...\r\n"), game);
			break;
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//׼������ս������
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����ս
		if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (condition == 0) {
				Log(_T("�Լ���Ϊ�����������ս...\r\n"), game);
				//���ƫ����������
				CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
				if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (condition == 1) {
				Log(_T("��Ϊ�����������˳�����ͥԺ...\r\n"), game);
				if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				return 0;
			}
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			break;
		}
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//����ս������
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//��׼��
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("���׼��...\r\n"), game);
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//ʤ������
		if (sn->FindPic(277, 31, 373, 111, _T("��������ʤ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
			sn->MoveClick(pos.x, pos.y);
			closingflag = 1;
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if ((closingflag == 1) && (sn->FindPic(277, 31, 373, 111, _T("��������ʤ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1)) {
			Log(_T("����ɹ�...\r\n"), game);
			closingflag = 0;
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��������
int BeginDailyTask::Experience(long hd, int round, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("��ʼ��������...\r\n"), game);
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���뾭�����ָ���
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�־������ֿ�ʼ...\r\n"), game);
		int res = EnterTaskFunc(hd, condition, _T("��������.bmp"), _T("����"), 9, sn, game);
		if (res == EXIT_THREAD) { return EXIT_THREAD; }
		else if (res = 0) {
			count = round;
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//�������
int BeginDailyTask::GoldCoin(long hd, int round, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("��ʼ�������...\r\n"), game);
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���뾭�����ָ���
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�ֽ�����ֿ�ʼ...\r\n"), game);
		int res = EnterTaskFunc(hd, condition, _T("�������.bmp"), _T("���"), 10, sn, game);
		if (res == EXIT_THREAD) { return EXIT_THREAD; }
		else if (res = 0) {
			count = round;
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//�ع���ս
int BeginDailyTask::RegressionChallenge(long hd, int round, int condition, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("��ʼ�ع���ս...\r\n"), game);
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���뾭�����ָ���
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("�ֻع���ս��ʼ...\r\n"), game);
		int res = EnterTaskFunc(hd, condition, _T("�ع���ս.bmp"), _T("�ع�"), 15, sn, game);
		if (res == EXIT_THREAD) { return EXIT_THREAD; }
		else if (res = 0) {
			count = round;
			break;
		}
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (returnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//����
int BeginDailyTask::Vestige(long hd, int round, snow *sn, int subsel, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	Log(_T("��ʼǰ����ͥԺ��������...\r\n"), game);
	Log(_T("��ʼǰ�Լ���֤��������...\r\n"), game);
	//��Ĺ��  C8B052-03050C
	//����  ABCAA5-120419
	//С��  A03104-030904
	//����  F2E8CB-030205

	//����ֲ�����
	long intX, intY;
	CString logmsg;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	Log(_T("Ѱ������֮������...\r\n"), game);
	//ʹ���ֿ�
	sn->UseDict(1);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//���������λ��
		if (sn->FindStrFast(687, 504, 764, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(intX + 20, intY - 20);
			Log(_T("�ҵ�����֮��...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(57, 10, 191, 51, _T("����֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			Log(_T("�ɹ���������֮��...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	int count = 0, ck_flag = 0, findQl, isfindQl;
	while (count < round) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//3s
		if (subsel != 1) {
			Log(_T("��ʼ����Ƿ�������(3s)...\r\n"), game);
			findQl = 6;
			isfindQl = false;
			//��ս  D6CDBF-282727
			while (findQl > 0) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(18, 282, 831, 430, _T("����"), _T("F2E8CB-030205"), 0.85, &intX, &intY) != -1) {
					Log(_T("�ҵ��������...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("����"), _T("F2E8CB-030205"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("׼����ս����...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("����_��ս"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
							break;
						}
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					isfindQl = true;
				}
				else if (sn->FindStrFast(18, 282, 831, 430, _T("С��"), _T("A03104-030904"), 0.85, &intX, &intY) != -1) {
					Log(_T("�ҵ�����С��...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("С��"), _T("A03104-030904"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("׼����ս����...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("����_��ս"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
							break;
						}
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					isfindQl = true;
				}
				else if (sn->FindStrFast(18, 282, 831, 430, _T("����"), _T("ABCAA5-120419"), 0.85, &intX, &intY) != -1) {
					Log(_T("�ҵ��������...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("����"), _T("ABCAA5-120419"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("׼����ս����...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("����_��ս"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
							break;
						}
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					isfindQl = true;
				}
				else if (sn->FindStrFast(18, 282, 831, 430, _T("��Ĺ��"), _T("C8B052-03050C"), 0.85, &intX, &intY) != -1) {
					Log(_T("�ҵ�������Ĺ��...\r\n"), game);
					while (1) {
						if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(18, 282, 831, 430, _T("��Ĺ��"), _T("C8B052-03050C"), 0.85, &intX, &intY) != -1) {
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							sn->MoveClick(intX + 5, intY + 10);
							Log(_T("׼����ս����...\r\n"), game);
							if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						}
						if (sn->FindStrFast(864, 441, 922, 479, _T("����_��ս"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
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
			Log(_T("������...\r\n"), game);
			//end
			if (isfindQl) {
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindStrFast(864, 441, 922, 479, _T("����_��ս"), _T("D6CDBF-282727"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("�����ս...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					//�ɹ� BCA469-292A20 
					if (sn->FindStrFast(640, 27, 682, 51, _T("����"), _T("BCA469-292A20"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("��������չʾ����...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					//CEC290-313C4D  483,149,617,219,
					if (sn->FindStrFast(483, 149, 617, 219, _T("�ɹ�"), _T("CEC290-313C4D"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("�����ɹ�...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
						CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
						if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
						Log(_T("��ȡ����...\r\n"), game);
						sn->MoveClick(pos.x, pos.y);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindStrFast(856, 433, 922, 477, _T("̽|��"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 1000, 1100) == EXIT_THREAD) { return EXIT_THREAD; }
						if (sn->FindStrFast(856, 433, 922, 477, _T("̽|��"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {
							break;
						}
					}
					if (DelayPlus(game, sn, 500, 502) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		//̽��
		if (subsel != 2) {
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				//6E4745-252E2C
				if (sn->FindStrFast(856, 433, 922, 477, _T("̽|��"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					if (ck_flag == 0) {
						Log(_T("���̽��...\r\n"), game);
						ck_flag = 1;
					}
					CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 2200, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (findBackIconSite(sn, game, intX, intY) != -1) {
					logmsg.Format(_T("%d"), count + 1);
					Log(_T("��") + logmsg + _T("��̽�鿪ʼ...\r\n"), game);
					sn->UseDict(1);
					ck_flag = 0;
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(294, 84, 439, 204, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					Log(_T("ս��ʤ��...\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(400, 490, 5, 10);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					CPoint pos = sn->RandomOffsetPos(540, 520, 5, 10);
					if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
					Log(_T("��ȡ����...\r\n"), game);
					sn->MoveClick(pos.x, pos.y);
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (sn->FindStrFast(856, 433, 922, 477, _T("̽|��"), _T("4F4B47-4F4C47"), 0.85, &intX, &intY) != -1) {

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
//���Ͽ�ʼ(����+����+�ճ�)
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