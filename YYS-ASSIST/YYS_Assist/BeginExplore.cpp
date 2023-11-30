#include "pch.h"
#include "BeginExplore.h"
#include "globalvar.h"

#define EXIT_THREAD -10

int BeginExplore::isExplore(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int i = 3;
	long intX, intY;
	while (i > 0)
	{
		//�Զ��ܾ�����
		/**
		 *        ɽ���꣬��ˮΪ�ߣ�������������ѩ����غ�,�˸��������
		 */
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(749, 81, 823, 142, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 2, pos.y + 2);
			if (DelayPlus(game, sn, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		i--;
		if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ѡ��
int BeginExplore::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_font = _T("��һ��.bmp|�ڶ���.bmp|������.bmp|������.bmp|������.bmp|������.bmp|������.bmp|�ڰ���.bmp|�ھ���.bmp|��ʮ��.bmp|��ʮһ��.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|�ڶ�ʮ��.bmp|�ڶ�ʮһ��.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp");
	double sim = 0.75;
	//start ѡ��� 4D463D-4D473E
	Log(_T("ѡ��ָ���ؿ�...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��һ��.bmp|��һ��(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ���.bmp|�ڶ���(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("������.bmp|������(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("������.bmp|������(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("������.bmp|������(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("������.bmp|������(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("������.bmp|�ڰ���(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڰ���.bmp|�ڰ���(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ھ���.bmp|�ھ���(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ��.bmp|��ʮ��(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮһ��.bmp|��ʮһ��(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 11: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 12: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 13: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 14: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 15: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 16: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 17: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 18: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 19: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ��.bmp|�ڶ�ʮ��(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 20: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮһ��.bmp|�ڶ�ʮһ��(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 21: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 22: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 23: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 24: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 25: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 26: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 27: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//��ˢѡ��
int BeginExplore::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(1);
	//�Զ��ܾ�����
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_font = _T("1.bmp|2.bmp|3.bmp|4.bmp|5.bmp|6.bmp|7.bmp|8.bmp|9.bmp|10.bmp|11.bmp|12.bmp|13.bmp|14.bmp|15.bmp|16.bmp|17.bmp|18.bmp|19.bmp|20.bmp|21.bmp|22.bmp|23.bmp|24.bmp|25.bmp|26.bmp|27.bmp|28.bmp");
	CString bmp_pic2 = _T("1-1.bmp|2-1.bmp|3-1.bmp|4-1.bmp|5-1.bmp|6-1.bmp|7-1.bmp|8-1.bmp|9-1.bmp|10-1.bmp|11-1.bmp|12-1.bmp|13-1.bmp|14-1.bmp|15-1.bmp|16-1.bmp|17-1.bmp|18-1.bmp|19-1.bmp|20-1.bmp|21-1.bmp|22-1.bmp|23-1.bmp|24-1.bmp|25-1.bmp|26-1.bmp|27-1.bmp|28-1.bmp");
	double sim = 0.75;
	//start ѡ���
	Log(_T("ѡ��ָ���ؿ�...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("1.bmp|1-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("1.bmp|1-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("2.bmp|2-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("2.bmp|2-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("3.bmp|3-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("3.bmp|3-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("4.bmp|4-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("4.bmp|4-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("5.bmp|5-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("5.bmp|5-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("6.bmp|6-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("6.bmp|6-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("7.bmp|7-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("7.bmp|7-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("8.bmp|8-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("8.bmp|8-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("9.bmp|8-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("9.bmp|8-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("10.bmp|10-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("10.bmp|10-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("11.bmp|11-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("11.bmp|11-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 11: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("12.bmp|12-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("12.bmp|12-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 12: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("13.bmp|13-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("13.bmp|13-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 13: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("14.bmp|14-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("14.bmp|14-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 14: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("15.bmp|15-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("15.bmp|15-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 15: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("16.bmp|16-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("16.bmp|16-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 16: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("17.bmp|17-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("17.bmp|17-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 17: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("18.bmp|18-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("18.bmp|18-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 18: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("19.bmp|19-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("19.bmp|19-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 19: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("20.bmp|20-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("20.bmp|20-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 20: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("21.bmp|21-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("21.bmp|21-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 21: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("22.bmp|22-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("22.bmp|22-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 22: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("23.bmp|23-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("23.bmp|23-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 23: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("24.bmp|24-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("24.bmp|24-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 24: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("25.bmp|25-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("25.bmp|25-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 25: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("26.bmp|26-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("26.bmp|26-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 26: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("27.bmp|27-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("27.bmp|27-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 27: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("28.bmp|28-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")) || findDestSite(startXY, endXY, bmp_pic2, layer, _T("28.bmp|28-1.bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	while (1) {
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(682, 390, 734, 418, _T("̽��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1){
			Log(_T("��ѡ��...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//ѡ���Ѷ�
int BeginExplore::ChooseDiff(int diff, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ѡ���Ѷ�
	long intX, intY;
	sn->UseDict(1);
	//��ͨ(δѡ��) 221,142,283,199,   ����(δѡ��)  320,142,386,201,
	Log(_T("��ʼѡ���Ѷ�...\r\n"), game);
	if (diff)
	{
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(221, 142, 283, 199, _T("��ͨ(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("��ѡ�������Ѷ�...\r\n"), game);
				break;
			}
			else if (sn->FindPic(320, 142, 386, 201, _T("����(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("ѡ�������Ѷ�...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 12, pos.y);
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (!diff)
	{
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(320, 142, 386, 201, _T("����(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("��ѡ����ͨ�Ѷ�...\r\n"), game);
				break;
			}
			else if (sn->FindStrFast(682, 390, 734, 418, _T("̽��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(458, 392, 514, 420, _T("���"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1) {
					Log(_T("��ѡ����ͨ�Ѷ�...\r\n"), game);
					break;
				}
			}
			if (sn->FindPic(221, 142, 283, 199, _T("��ͨ(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("ѡ����ͨ�Ѷ�...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x + 12, pos.y);
				if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
int BeginExplore::clickExplore(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(1);
	CString monster = _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp");
	Log(_T("Ѱ��̽����ť...\r\n"), game);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(682, 390, 734, 418, _T("̽��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
		{
			//���
			Log(_T("����̽������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			break;
		}
		else if (sn->FindPic(9, 30, 957, 446, monster, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
int BeginExplore::autoRotate(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int rotateres = GetAutoRoTateState(sn, game);
	if (rotateres == 1) {
		return 1;
	}
	else if (rotateres == 0) {
		CPoint pos = sn->RandomOffsetPos(100, 505, 0, 5);
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		sn->MoveClick(pos.x, pos.y);
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}
int BeginExplore::findCommonMonster(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(0);
	long intX, intY;
	long findRes;
	int i = 15;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = sn->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (speed == 0) {
			if (DelayPlus(game, sn, 180, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (speed == 1) {
			if (DelayPlus(game, sn, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		i--;
	}
	if (findRes == -1) { return 0; }
	if(IsChangeMaterial(sn, material,mode, game) == 0)
	{
		int closingflag = 0, closingflag2 = 0;
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//���
				Log(_T("�ҵ���ͨ��...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("���׼��...\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY);
					sn->MoveClick(pos.x, pos.y);
				}
			}
			if (sn->FindPic(233, 30, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("ս��������...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				closingflag2 = 1;
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				closingflag = 1;
			}
			if ((closingflag == 1) && (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
				Log(_T("����ɹ�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if ((closingflag2 && (!closingflag)) && (sn->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
			{
				Log(_T("����ɹ�...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		return 1;
	}
	else {
		AutoReplaceMaterial(progressBar, materialKinds, sn, game);
	}
	return 0;
}
int BeginExplore::findBossMonster(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�����ֿ�
	sn->UseDict(0);
	long intX, intY;
	long findRes;
	int i = 10;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = sn->FindPic(9, 30, 957, 446, _T("monster_boss.bmp|monster_boss1.bmp|monster_boss2.bmp|monster_boss3.bmp"), _T("202020"), 0.8, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (speed == 0) {
			if (DelayPlus(game, sn, 180, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (speed == 1) {
			if (DelayPlus(game, sn, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		i--;
	}
	if (findRes == -1) { return 0; }
	if (IsChangeMaterial(sn, material, mode, game) == 0)
	{
		int closingflag = 0,closingflag2 = 0;
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(9, 30, 957, 446, _T("monster_boss.bmp|monster_boss1.bmp|monster_boss2.bmp|monster_boss3.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//���
				Log(_T("����Boss...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("���׼��...\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY);
					sn->MoveClick(pos.x, pos.y);
				}
			}
			if (sn->FindPic(233, 30, 536, 253, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("ս��������...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				closingflag2 = 1;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				closingflag = 1;
			}
			if ((closingflag == 1) && (sn->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
				Log(_T("����ɹ�...\r\n"), game);
				break;
			}
			if ((closingflag2 && (!closingflag))&&(sn->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
			{
				Log(_T("����ɹ�...\r\n"), game);
				break;
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		return 1;
	}
	else {
		AutoReplaceMaterial(progressBar, materialKinds, sn, game);
	}
	return 0;
}
//��������---�������
int BeginExplore::InnerCreatTeamToInviteUpper(int preferArea, snow *sn, Game *game) {
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
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 2);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(630, 429, 685, 458, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
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
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
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
			sn->MoveClick(pos.x + 5, pos.y + 2);
			Log(_T("����...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(788, 159, 846, 221, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1){//̽����
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
int BeginExplore::InnerCreatTeamToInviteLower(int preferArea, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(2);
	//�������
	while (1)
	{
		if (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1) {
			if (sn->FindPic(788, 159, 846, 221, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)//̽����
			{
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 6, pos.y + 5);
				Log(_T("��������б�...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(353, 61, 434, 109, _T("̽������(ѡ��).bmp|̽������(δѡ��).bmp"), _T("151515"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//������ѻ����
	while (1)
	{
		if ((preferArea == 0) || (preferArea == 3))
		{
			if (sn->FindPic(353, 61, 434, 109, _T("̽������(δѡ��).bmp"), _T("151515"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("ѡ��ͬ������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 15, pos.y + 5);
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(353, 61, 434, 109, _T("̽������(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
		}
		else if ((preferArea == 1) || (preferArea == 4))
		{
			if (sn->FindPic(440, 68, 516, 103, _T("̽������(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("ѡ���������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 15, pos.y + 5);
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(440, 68, 516, 103, _T("̽������(ѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
		}
		else if (preferArea == 2) {
			Log(_T("�̶����ѣ����ֶ�ѡ����ѣ�������룡\r\n"), game);
			if (DelayPlus(game, sn, 800, 802) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("���������...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 400, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if ((preferArea == 0) || (preferArea == 1)) {
		//�ж��Ƿ�Ϊ�̶����ѣ��������룬�����˳�
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
				sn->MoveClick(pos.x + 5, pos.y + 2);
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (preferArea == 2) {
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
	if ((preferArea == 3) || (preferArea == 4)) {
		//�ж��Ƿ�Ϊ�̶����ѣ��������룬�����˳�
		int combineClock = 0;
		while (1)
		{
			if (sn->SetPath(_T("config\\imgGame12")) && sn->FindPic(319, 138, 692, 316, sn->MatchPicName(_T("teamer?.bmp")), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 25, pos.y + 8);
				if (preferArea == 3) {
					Log(_T("ѡ���б���ͬ���̶�����...\r\n"), game);
				}
				else if (preferArea == 4) {
					Log(_T("ѡ���б��п����̶�����...\r\n"), game);
				}
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
		//���������Ӻ��ѣ�����ͥԺ
		if (combineClock == -100)
		{
			Log(_T("�б���û�й̶����ѣ������Ƿ��ȡ������ͼ...\r\n"), game);
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
				sn->MoveClick(pos.x + 5, pos.y + 2);
				Log(_T("�������...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("��ս.bmp|��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("����"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}

int BeginExplore::EnterExplore(int speed, int material, int mode, CString progressBar, CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�߶���־
	int moveFlag = -5;
	//���븱��
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		int resultBoss = findBossMonster(speed, material, mode, progressBar, materialKinds, sn, game);
		if (resultBoss == 0)
		{
			int resultCommon = findCommonMonster(speed, material, mode, progressBar, materialKinds, sn, game);
			if ((resultCommon == 0) && (moveFlag < 0)) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint posx = sn->RandomOffsetPos(865, 126, 5, 10);
				CPoint posy = sn->RandomOffsetPos(84, 126, 5, 10);
				sn->DragMouse(posx.x, posx.y, posy.x, posx.y);
				moveFlag++;
				if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if ((resultCommon == 0) && (moveFlag >= 0) && (moveFlag < 6)) {
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint posx = sn->RandomOffsetPos(865, 126, 5, 10);
				CPoint posy = sn->RandomOffsetPos(84, 126, 5, 10);
				sn->DragMouse(posy.x, posx.y, posx.x, posx.y);
				moveFlag++;
				if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if ((resultCommon == 0) && (moveFlag >= 5)) {
				moveFlag = -5;
			}
			else if (resultCommon == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (resultBoss == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultBoss == 1) { break; }
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
int BeginExplore::ExitExploreEvent(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�ж��Ƿ���̽���ؿ���
		if (sn->FindPic(0, 0, 960, 540, _T("����.bmp|����һ.bmp|������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (sn->FindPic(8, 15, 73, 80, _T("����1.bmp|����5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 6);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("�˳�̽��...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//ʹ���ֿ�
		sn->UseDict(0);
		if (sn->FindStrFast(523, 286, 640, 317, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 8, 12);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("ȷ���˳�...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindPic(74, 164, 136, 219, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			break;
		}
		//���ֿ�
		sn->UseDict(1);
		if (sn->FindStrFast(108, 504, 188, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(462, 392, 735, 417, _T("���|̽��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}

//��ཱ���¼�
int BeginExplore::GetReward(int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(1);
	long intX, intY;
	if (mode != 2) {
		Log(_T("����Ƿ����Эս����...\r\n"), game);
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(60, 5, 183, 61, _T("Эս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("�ѽ���Эս����...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	if (sn->FindPic(0, 79, 114, 121, _T("����¼�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1){//0,378,111,427  ����¼�(��)
		Log(_T("�������Ƿ��б���...\r\n"), game);
		int i = 2,movefalg = 0, flag = 0;
		while (i > 0) {
			if (sn->FindPic(0, 78, 96, 455, _T("����.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(0, 78, 96, 455, _T("����.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
						Log(_T("��ȡ���ֱ���...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 2, pos.y + 2);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("��ȡ�ɹ�...\r\n"), game);
						flag = 1;
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindStrFast(108, 504, 188, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
						break;
					}
					if (flag&&(sn->FindPic(60, 5, 183, 61, _T("Эս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						flag = 0;
						break;
					}
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			else {
				if ((movefalg == 0) && (sn->FindPic(0, 378, 111, 427, _T("����¼�(��).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)) {
					sn->DragMouse(85, 313, 85, 188);
					if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					movefalg = -1;
				}	
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			i--;
		}
	}
	return 1;
}
//��ȡ�Զ��ֻ�״̬
int BeginExplore::GetAutoRoTateState(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	CString picname = _T("�Զ��ֻ�0.bmp|�Զ��ֻ�1.bmp|�Զ��ֻ�2.bmp|�Զ��ֻ�3.bmp|�Զ��ֻ�4.bmp|�Զ��ֻ�5.bmp|�Զ��ֻ�6.bmp|�Զ��ֻ�7.bmp|�Զ��ֻ�8.bmp|�Զ��ֻ�9.bmp|�Զ��ֻ�10.bmp|�Զ��ֻ�11.bmp|�Զ��ֻ�12.bmp|�Զ��ֻ�13.bmp|�Զ��ֻ�14.bmp|�Զ��ֻ�15.bmp|�Զ��ֻ�16.bmp|�Զ��ֻ�17.bmp|�Զ��ֻ�18.bmp|�Զ��ֻ�19.bmp|");
	int i = 20;
	while (i > 0) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(86, 493, 107, 515, picname, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			return 1;
		}
		if (DelayPlus(game, sn, 70, 75) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//�ж��Ƿ���Ҫ������
int BeginExplore::IsChangeMaterial(snow *sn, int material, int mode, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int rotateres = GetAutoRoTateState(sn, game);
	if (mode==2 && material == 1 && rotateres == 0) {
		Log(_T("�򲹳�ս����������...\r\n"), game);
		return 1;
	}else if(rotateres == EXIT_THREAD){ return EXIT_THREAD; }
	return 0;
}
//ѡ����ֹ���
int BeginExplore::WhatMaterialToSelect(CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	if (materialKinds == _T("0")) {
		if (sn->FindPic(103, 220, 151, 270, _T("N��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (materialKinds == _T("1")) {
		if (sn->FindPic(25, 211, 73, 257, _T("�ز�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (materialKinds == _T("2")) {
		if (sn->FindPic(180, 265, 215, 300, _T("R��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//����������ѡ��
int BeginExplore::SelectProgressBar(CString progress, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->EnableRealMouse(1, 20, 30);
	long intX, intY;
	Log(_T("ѡ�����...\r\n"), game);
	if (progress == _T("0")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 42, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("1")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 72, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("2")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 102, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("3")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 132, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("4")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 162, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("5")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 192, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("6")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 222, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("7")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 252, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("8")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 282, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("9")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 312, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("10")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 342, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("11")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 372, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("12")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 402, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("13")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 432, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("14")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 462, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("15")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 492, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("16")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 522, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("17")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 552, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("18")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 582, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("19")) {
		if (sn->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 612, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	sn->EnableRealMouse(3, 20, 30);
	return 1;
}
//�Զ�������
int BeginExplore::AutoReplaceMaterial(CString progressBar, CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int allFlag = 0;
	sn->UseDict(1);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("��ʼ�Զ�������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 7, pos.y + 12);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(352, 78, 466, 122, _T("�򲹳�ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((allFlag == 0) && (sn->FindPic(352, 78, 466, 122, _T("�򲹳�ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			Log(_T("ѡ�������ʽ��...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 245, pos.y + 112);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 245, pos.y + 112);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			allFlag = 1;
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(19, 467, 76, 513, _T("ȫ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			long clickX = intX, clickY = intY;
			if (sn->FindPic(103, 220, 151, 270, _T("N��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				Log(_T("ѡ��������...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(clickX, clickY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if ((sn->FindPic(103, 220, 151, 270, _T("N��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(25, 211, 73, 257, _T("�ز�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(180, 265, 215, 300, _T("R��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		WhatMaterialToSelect(materialKinds, sn, game);
		//27,466,73,509,
		if ((sn->FindPic(27, 466, 73, 509, _T("N��(��ѡ).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(27, 466, 73, 509, _T("�ز�(��ѡ).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(27, 466, 73, 509, _T("R��(��ѡ).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	SelectProgressBar(progressBar, sn, game);
	long startX, startY, beginX = 81;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((beginX < 647) && (sn->FindStrFast(beginX, 359, 863, 430, _T("��ս"), _T("B38859-473D2A"), 0.85, &intX, &intY) != -1)) { //B38859-473D2A
			startX = intX, startY = intY;
			if (sn->FindStrFast(intX - 63, intY + 40, intX - 20, intY + 70, _T("��"), _T("AA9A99-273637"), 0.85, &intX, &intY) == -1) {
				Log(_T("�����ս�б�...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(startX, startY);
				sn->MoveTo(pos.x + 5, pos.y + 3);
				Sleep(200);
				sn->LeftDown();
				Sleep(2500);
				sn->LeftUp();
			}
			beginX = startX + 40;
			CString str;
			str.Format(_T("���[ %d, 359, 863, 430]����\r\n"), beginX);
			Log(str, game);
		}
		else if (beginX >= 647) {
			//AA9A99-273637
			if (sn->FindStrFast(656, 366, 855, 425, _T("��ս"), _T("B38859-473D2A"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
				//ģ����ʵ���켣
				sn->EnableRealMouse(1, 60, 30);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				Log(_T("��ҳ...\r\n"), game);
				sn->DragMouse(pos.x - 50, pos.y + 50, pos.x - 550, pos.y + 50);
				beginX = 81;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(772, 79, 873, 122, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("��ս�б�����...\r\n"), game);
			//ģ����ʵ���켣
			sn->EnableRealMouse(3, 20, 30);
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(822, 289, 910, 371, _T("����ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ȷ���򲹳�ս...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 2, pos.y + 2);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("�ѷ��ظ���...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	int rotateres = GetAutoRoTateState(sn, game);
	if (rotateres == 1) {
		Log(_T("�ѻָ��Զ��ֻ�...\r\n"), game);
	}
	else if (rotateres == EXIT_THREAD) { return EXIT_THREAD; }
	else if (rotateres == 0) {	
		Log(_T("���ڻָ��Զ��ֻ�...\r\n"), game);
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (GetAutoRoTateState(sn, game) == 0) {
				CPoint pos = sn->RandomOffsetPos(100, 505);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (GetAutoRoTateState(sn, game) == 1) {
				Log(_T("�ѻָ��Զ��ֻ�...\r\n"), game);
				break;
			}
		}
		
	}
	return 1;
}
//ͨ��ͥԺ�ж��Ƿ������---������ֹͣ�¼�
int BeginExplore::IsOutExploreByYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->UseDict(0);
	//start findFunc
	long intX, intY;
	if (sn->FindStrFast(264, 488, 377, 523, _T("���"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1 || sn->FindStrFast(361, 482, 469, 522, _T("��|��|�"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1)
	{
		return 1;
	}
	return 0;
}
//��ӽ��븱��
int BeginExplore::receiveEnterExplore(int count, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->UseDict(0);
	long intX, intY;
	int is_enter_scene = 0;
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		/*if (count == 0)
		{
			if (sn->FindPic(27, 518, 67, 540, _T("����.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1)
			{
				Log(_T("����Զ��ֻ�״̬...\r\n"), game);
				if (autoRotate(hd, sn, game, index) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("�Զ��ֻ��ѿ���\r\n"), game);
			}
		}*/
		//��׼��
		if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1){
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("���׼��...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
			}
		}
		//ʤ������
		if (sn->FindPic(286, 34, 438, 169, _T("ʤ��.bmp|ʤ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("ս��������...\r\n"), game);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(388, 372, 567, 456, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("����ɹ�...\r\n"), game);
			is_enter_scene = 1;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(0, 0, 960, 540, _T("����.bmp|����һ.bmp|������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (ExitExploreEvent(sn, game) == EXIT_THREAD) {return EXIT_THREAD;}
		}
		if (sn->FindPic(74, 164, 136, 219, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�ɹ�����ͥԺ��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��������
int BeginExplore::ReceiveInvite(int count, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�ȴ���������
	CombineWaitRelation(exteamer1, exteamer2, sn, game);
	long intX, intY;
	CString count_str;
	count_str.Format(_T("%d"), count + 1);
	Log(_T("�ȴ���������...\r\n"), game);
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(74, 164, 136, 219, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count_str.Format(_T("%d"), count + 1);
			Log(_T("��������...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 7);
			Log(_T("��") + count_str + _T("��̽����ʼ...\r\n"), game);
			count++;
			if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (collectbox) {//�Զ�����
				GetReward(mode, sn, game);
				CombineWaitRelation(exbonus1, exbonus2, sn, game);
			}
		}
		if (sn->FindPic(60, 5, 183, 61, _T("Эս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("�������...\r\n"), game);
			break;
		}
		if (sn->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("����̽��...\r\n"), game);
			game->reSetWaitFlag(exbonus1, exbonus2);
			game->reSetWaitFlag(exteamer1, exteamer2);
			break;
		}
		if (findBackIconSite(sn, game, intX, intY) != -1) {
			game->reSetWaitFlag(exbonus1, exbonus2);
			game->reSetWaitFlag(exteamer1, exteamer2);
			break;
		}
		if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return count;
}
//�����ѽ���������ս 
int BeginExplore::IsEnterTeamRepeat(int preferArea, int count, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->UseDict(0);
	long intX, intY;
	int timerRecord = 0;
	//�ȴ����ѳ�̽��
	CombineWaitRelation(exteamer1, exteamer2, sn, game);
	//�������Ƿ�������
	Log(_T("�ȴ����Ѽ������...\r\n"), game);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 20, 25);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//����ս
		if (sn->FindPic(874, 436, 953, 518, _T("��ս.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			Log(_T("�����Ѽ������...\r\n"), game);
			if (collectbox) {//�Զ�����
				GetReward(mode, sn, game);
				CombineWaitRelation(exbonus1, exbonus2, sn, game);
			}
			//���ƫ����������
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("����̽��...\r\n"), game);
			game->reSetWaitFlag(exbonus1, exbonus2);
			game->reSetWaitFlag(exteamer1, exteamer2);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		timerRecord++;
		if (timerRecord >= 20) {
			if (sn->FindPic(874, 436, 953, 518, _T("��ս(δ����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				Log(_T("����δ���룬�����������...\r\n"), game);
				if (InnerCreatTeamToInviteLower(preferArea, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			timerRecord = 0;
		}
	}
	return 1;
}
//����ȴ��¼�
int BeginExplore::CombineWaitRelation(bool &flag1, bool &flag2, snow *sn, Game *game) {
	//���������ӹ�ϵ
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	game->synchronization(flag1, flag2);
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	return 1;
}
//̽����ˢ
int BeginExplore::SingleExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(1);
	long intX, intY;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }

	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//ѡ���½ڲ����
		CPoint startXY, endXY;
		startXY.x = 777, startXY.y = 131;
		endXY.x = 952, endXY.y = 508;
		//�жϿ�ʼǰ�Ƿ����½ڵ㿪״̬
		if (sn->FindStrFast(108, 504, 188, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (collectbox) { 
				Log(_T("׼�����...\r\n"), game);
				if (GetReward(mode, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("������...\r\n"), game);
			}
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(462, 392, 735, 417, _T("���|̽��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (SingleChooseLayer(layer, startXY, endXY, sn, game) == 1) {
					break; 
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//ѡ���Ѷ�
		if (count == 0)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			if (ChooseDiff(diff, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else {
			//���̽����ť
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�Զ��ֻ�
		if (count == 0)
		{
			Log(_T("����Զ��ֻ�״̬...\r\n"), game);
			if (autoRotate(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�Զ��ֻ��ѿ���\r\n"), game);
		}
		//���븱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("��̽����ʼ...\r\n"), game);
		if (EnterExplore(speed, material, mode, progressBar, materialKinds, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//��ȡ��������
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//���ܵ�ˢ
int BeginExplore::AIExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//ʹ���ֿ�
	sn->UseDict(1);
	long intX, intY;
	Log(_T("------���ܵ�ˢģʽ------\r\n"), game);
	Log(_T("ͻ��ȯ���Զ����������б��ڵ���һ������\r\n"), game);
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	//������ѡ���������
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//ѡ���½ڲ����
		CPoint startXY, endXY;
		startXY.x = 777, startXY.y = 131;
		endXY.x = 952, endXY.y = 508;
		//�жϿ�ʼǰ�Ƿ����½ڵ㿪״̬
		if (sn->FindStrFast(108, 504, 188, 538, _T("����"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (collectbox) { GetReward(mode, sn, game); }
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(462, 392, 735, 417, _T("���|̽��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (SingleChooseLayer(layer, startXY, endXY, sn, game) == 1) {
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//ѡ���Ѷ�
		if (count == 0)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			//�ж��Ƿ���ͻ�� ACA799-333734
			if (sn->FindStrFast(706, 12, 730, 30, _T("30"), _T("ACA799-333734"), 0.85, &intX, &intY) != -1)
			{
				Log(_T("ͻ�ƾ�����...\r\n"), game);
				count = round;
				break;
			}
			if (ChooseDiff(diff, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else {
			//�ж��Ƿ���ͻ�� ACA799-333734
			if (sn->FindStrFast(706, 12, 730, 30, _T("30"), _T("ACA799-333734"), 0.85, &intX, &intY) != -1)
			{
				Log(_T("ͻ�ƾ�����...\r\n"), game);
				count = round;
				break;
			}
			//���̽����ť
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�Զ��ֻ�
		if (count == 0)
		{
			Log(_T("�Զ��ֻ�...\r\n"), game);
			if (autoRotate(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�Զ��ֻ��ѿ���\r\n"), game);
		}
		//���븱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("��̽����ʼ...\r\n"), game);
		if (EnterExplore(speed, material, mode, progressBar, materialKinds, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//��ȡ��������
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//����������
int BeginExplore::inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, int collectbox, int mode, int material, CString progressBar, CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�Ⱥ����¼�
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��̽��
	//��ȡ��ǰλ��ѡ��  3D3833-3E3933
	CString fontLst = _T("����|ҵ��|��ת|ˮ��|����|����|����|����|����|����|���|����|ʯ��|���|����|�ع�");
	CString color_format = _T("454039-46413A");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//�ҵ�̽�������
	findDestSite(startXY, endXY, fontLst, 0, _T("����"), color_format, 0.8, 2, sn, game, _T("findstr"), _T("̽|CFC8B8-292B28"));
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	if (ChooseLayer(layer, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������--�������
	if (InnerCreatTeamToInviteUpper(preferArea, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int CreatRes = InnerCreatTeamToInviteLower(preferArea, sn, game);
	if (CreatRes == 0) {
		Log(_T("��������ʧ��!!!\r\n"), game);
		//δ�ҵ�������ѣ�����ͥԺ��رռӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (DelayPlus(game, sn, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����Ѽ�����鲢����ս
		if (IsEnterTeamRepeat(preferArea, count, collectbox, mode, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ֻ�
		if (count == 0)
		{
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("����Զ��ֻ�״̬...\r\n"), game);
			if (autoRotate(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("�Զ��ֻ��ѿ���...\r\n"), game);
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//����̽������
		//���븱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("��") + count_str + _T("��̽����ʼ...\r\n"), game);
		if (EnterExplore(speed, material, mode, progressBar, materialKinds, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//��ȡ��������
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ӽ�������
int BeginExplore::BeinvitedExplore(long hd, int round, CString jc, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//�Ⱥ����¼�
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(sn, game))
	{
		NotInYardTips(hd, sn, game);
		return 0;
	}
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 269, startXY.y = 25;
	endXY.x = 331, endXY.y = 68;
	if (auto_open_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		//��������
		if (ReceiveInvite(count, collectbox, mode, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 2000, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
		//����̽������
		if (receiveEnterExplore(count, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("��������ɣ������˳�����ͥԺ...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("̽��"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//����ͥԺ
int BeginExplore::ExploreReturnYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//�ֿ�
	sn->UseDict(0);
	//��ʼ����
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(760, 83, 814, 135, _T("��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(364, 309, 416, 338, _T("ȡ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(15, 13, 73, 72, _T("����1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//760, 83, 814, 135,
		if (sn->FindPic(9, 18, 61, 76, _T("����5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(555, 292, 608, 316, _T("ȷ��"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("ȷ��"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 1, 65, 59, _T("����4.bmp|����8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("�ӳ�"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("�ɹ�����ͥԺ��\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
