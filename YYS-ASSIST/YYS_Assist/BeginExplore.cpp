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
		//自动拒绝悬赏
		/**
		 *        山无陵，江水为竭，冬雷震震，夏雨雪。天地合,乃敢与君绝。
		 */
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(749, 81, 823, 142, _T("叉.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
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
//选层
int BeginExplore::ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_font = _T("第一章.bmp|第二章.bmp|第三章.bmp|第四章.bmp|第五章.bmp|第六章.bmp|第七章.bmp|第八章.bmp|第九章.bmp|第十章.bmp|第十一章.bmp|第十二章.bmp|第十三章.bmp|第十四章.bmp|第十五章.bmp|第十六章.bmp|第十七章.bmp|第十八章.bmp|第十九章.bmp|第二十章.bmp|第二十一章.bmp|第二十二章.bmp|第二十三章.bmp|第二十四章.bmp|第二十五章.bmp|第二十六章.bmp|第二十七章.bmp|第二十八章.bmp");
	double sim = 0.75;
	//start 选择层 4D463D-4D473E
	Log(_T("选择指定关卡...\r\n"), game);
	switch (layer)
	{
	case 0: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第一章.bmp|第一章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二章.bmp|第二章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第三章.bmp|第三章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第四章.bmp|第四章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第五章.bmp|第五章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第六章.bmp|第六章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第七章.bmp|第八章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第八章.bmp|第八章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第九章.bmp|第九章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十章.bmp|第十章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十一章.bmp|第十一章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 11: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十二章.bmp|第十二章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 12: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十三章.bmp|第十三章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 13: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十四章.bmp|第十四章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 14: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十五章.bmp|第十五章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 15: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十六章.bmp|第十六章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 16: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十七章.bmp|第十七章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 17: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十八章.bmp|第十八章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 18: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第十九章.bmp|第十九章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 19: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十章.bmp|第二十章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 20: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十一章.bmp|第二十一章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 21: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十二章.bmp|第二十二章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 22: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十三章.bmp|第二十三章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 23: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十四章.bmp|第二十四章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 24: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十五章.bmp|第二十五章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 25: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十六章.bmp|第二十六章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 26: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十七章.bmp|第二十七章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	case 27: {
		if (findDestSite(startXY, endXY, bmp_font, layer, _T("第二十八章.bmp|第二十八章(选中).bmp"), _T("202020"), sim, 1, sn, game, _T("findpic")))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//单刷选层
int BeginExplore::SingleChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	sn->UseDict(1);
	//自动拒绝悬赏
	if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//获取目标位置
	CString bmp_font = _T("1.bmp|2.bmp|3.bmp|4.bmp|5.bmp|6.bmp|7.bmp|8.bmp|9.bmp|10.bmp|11.bmp|12.bmp|13.bmp|14.bmp|15.bmp|16.bmp|17.bmp|18.bmp|19.bmp|20.bmp|21.bmp|22.bmp|23.bmp|24.bmp|25.bmp|26.bmp|27.bmp|28.bmp");
	CString bmp_pic2 = _T("1-1.bmp|2-1.bmp|3-1.bmp|4-1.bmp|5-1.bmp|6-1.bmp|7-1.bmp|8-1.bmp|9-1.bmp|10-1.bmp|11-1.bmp|12-1.bmp|13-1.bmp|14-1.bmp|15-1.bmp|16-1.bmp|17-1.bmp|18-1.bmp|19-1.bmp|20-1.bmp|21-1.bmp|22-1.bmp|23-1.bmp|24-1.bmp|25-1.bmp|26-1.bmp|27-1.bmp|28-1.bmp");
	double sim = 0.75;
	//start 选择层
	Log(_T("选择指定关卡...\r\n"), game);
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
		if (sn->FindStrFast(682, 390, 734, 418, _T("探索"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1){
			Log(_T("已选择...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//选择难度
int BeginExplore::ChooseDiff(int diff, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//选择难度
	long intX, intY;
	sn->UseDict(1);
	//普通(未选中) 221,142,283,199,   困难(未选中)  320,142,386,201,
	Log(_T("开始选择难度...\r\n"), game);
	if (diff)
	{
		while (1)
		{
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(221, 142, 283, 199, _T("普通(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("已选择困难难度...\r\n"), game);
				break;
			}
			else if (sn->FindPic(320, 142, 386, 201, _T("困难(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("选择困难难度...\r\n"), game);
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
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(320, 142, 386, 201, _T("困难(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("已选择普通难度...\r\n"), game);
				break;
			}
			else if (sn->FindStrFast(682, 390, 734, 418, _T("探索"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(458, 392, 514, 420, _T("组队"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1) {
					Log(_T("已选择普通难度...\r\n"), game);
					break;
				}
			}
			if (sn->FindPic(221, 142, 283, 199, _T("普通(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("选择普通难度...\r\n"), game);
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
	Log(_T("寻找探索按钮...\r\n"), game);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(682, 390, 734, 418, _T("探索"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1)
		{
			//点击
			Log(_T("进入探索副本...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
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
	//设置字库
	sn->UseDict(0);
	long intX, intY;
	long findRes;
	int i = 15;
	while (i > 0)
	{
		//自动拒绝悬赏
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
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//点击
				Log(_T("找到普通怪...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("点击准备...\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY);
					sn->MoveClick(pos.x, pos.y);
				}
			}
			if (sn->FindPic(233, 30, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("战斗结算中...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				closingflag2 = 1;
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				closingflag = 1;
			}
			if ((closingflag == 1) && (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
				Log(_T("结算成功...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if ((closingflag2 && (!closingflag)) && (sn->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
			{
				Log(_T("结算成功...\r\n"), game);
				if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
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
	//设置字库
	sn->UseDict(0);
	long intX, intY;
	long findRes;
	int i = 10;
	while (i > 0)
	{
		//自动拒绝悬赏
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
			//自动拒绝悬赏
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(9, 30, 957, 446, _T("monster_boss.bmp|monster_boss1.bmp|monster_boss2.bmp|monster_boss3.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//点击
				Log(_T("发现Boss...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 1500, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
					Log(_T("点击准备...\r\n"), game);
					CPoint pos = sn->RandomOffsetPos(intX, intY);
					sn->MoveClick(pos.x, pos.y);
				}
			}
			if (sn->FindPic(233, 30, 536, 253, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				Log(_T("战斗结算中...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				closingflag2 = 1;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				closingflag = 1;
			}
			if ((closingflag == 1) && (sn->FindPic(372, 352, 588, 480, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)) {
				Log(_T("结算成功...\r\n"), game);
				break;
			}
			if ((closingflag2 && (!closingflag))&&(sn->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
			{
				Log(_T("结算成功...\r\n"), game);
				break;
			}
			if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
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
//创建队伍---点击邀请
int BeginExplore::InnerCreatTeamToInviteUpper(int preferArea, snow *sn, Game *game) {
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
			Log(_T("创建队伍...\r\n"), game);
			if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 2);
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(630, 429, 685, 458, _T("创建"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
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
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
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
			sn->MoveClick(pos.x + 5, pos.y + 2);
			Log(_T("创建...\r\n"), game);
			if (DelayPlus(game, sn, 1200, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(788, 159, 846, 221, _T("加.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1){//探索加
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
	//邀请好友
	while (1)
	{
		if (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1) {
			if (sn->FindPic(788, 159, 846, 221, _T("加.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)//探索加
			{
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 6, pos.y + 5);
				Log(_T("进入好友列表...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(353, 61, 434, 109, _T("探索好友(选中).bmp|探索好友(未选中).bmp"), _T("151515"), 0.85, 0, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//点击好友或跨区
	while (1)
	{
		if ((preferArea == 0) || (preferArea == 3))
		{
			if (sn->FindPic(353, 61, 434, 109, _T("探索好友(未选中).bmp"), _T("151515"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("选择同区好友...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 15, pos.y + 5);
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(353, 61, 434, 109, _T("探索好友(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
		}
		else if ((preferArea == 1) || (preferArea == 4))
		{
			if (sn->FindPic(440, 68, 516, 103, _T("探索跨区(未选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				Log(_T("选择跨区好友...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 15, pos.y + 5);
				if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (sn->FindPic(440, 68, 516, 103, _T("探索跨区(选中).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				break;
			}
		}
		else if (preferArea == 2) {
			Log(_T("固定好友：请手动选择好友，点击邀请！\r\n"), game);
			if (DelayPlus(game, sn, 800, 802) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("检测邀请中...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 400, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	if ((preferArea == 0) || (preferArea == 1)) {
		//判断是否为固定队友，是则邀请，否则退出
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
				sn->MoveClick(pos.x + 5, pos.y + 2);
				Log(_T("点击邀请...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
				break;
			}
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (preferArea == 2) {
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
	if ((preferArea == 3) || (preferArea == 4)) {
		//判断是否为固定队友，是则邀请，否则退出
		int combineClock = 0;
		while (1)
		{
			if (sn->SetPath(_T("config\\imgGame12")) && sn->FindPic(319, 138, 692, 316, sn->MatchPicName(_T("teamer?.bmp")), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
				sn->MoveClick(pos.x + 25, pos.y + 8);
				if (preferArea == 3) {
					Log(_T("选中列表中同区固定好友...\r\n"), game);
				}
				else if (preferArea == 4) {
					Log(_T("选中列表中跨区固定好友...\r\n"), game);
				}
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
		//不是最近组队好友，返回庭院
		if (combineClock == -100)
		{
			Log(_T("列表内没有固定好友，请检查是否截取过好友图...\r\n"), game);
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
				sn->MoveClick(pos.x + 5, pos.y + 2);
				Log(_T("点击邀请...\r\n"), game);
				if (DelayPlus(game, sn, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if ((sn->FindPic(874, 436, 953, 518, _T("挑战.bmp|挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (sn->FindStrFast(557, 418, 607, 449, _T("邀请"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) == -1)) {
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
	//走动标志
	int moveFlag = -5;
	//进入副本
	while (1)
	{
		//自动拒绝悬赏
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
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//判断是否在探索关卡内
		if (sn->FindPic(0, 0, 960, 540, _T("奖励.bmp|奖励一.bmp|奖励二.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (sn->FindPic(8, 15, 73, 80, _T("返回1.bmp|返回5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(intX, intY, 2, 6);
				sn->MoveClick(pos.x, pos.y);
				Log(_T("退出探索...\r\n"), game);
				if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//使用字库
		sn->UseDict(0);
		if (sn->FindStrFast(523, 286, 640, 317, _T("确认"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 8, 12);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("确认退出...\r\n"), game);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindPic(74, 164, 136, 219, _T("接受邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			break;
		}
		//换字库
		sn->UseDict(1);
		if (sn->FindStrFast(108, 504, 188, 538, _T("御魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(462, 392, 735, 417, _T("组队|探索"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			break;
		}
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 0;
}

//左侧奖励事件
int BeginExplore::GetReward(int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(1);
	long intX, intY;
	if (mode != 2) {
		Log(_T("检测是否进入协战队伍...\r\n"), game);
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(60, 5, 183, 61, _T("协战队伍.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("已进入协战队伍...\r\n"), game);
				break;
			}
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	if (sn->FindPic(0, 79, 114, 121, _T("左侧事件.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1){//0,378,111,427  左侧事件(底)
		Log(_T("检测左侧是否有宝箱...\r\n"), game);
		int i = 2,movefalg = 0, flag = 0;
		while (i > 0) {
			if (sn->FindPic(0, 78, 96, 455, _T("宝箱.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(0, 78, 96, 455, _T("宝箱.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1) {
						Log(_T("领取发现宝箱...\r\n"), game);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
						sn->MoveClick(pos.x + 2, pos.y + 2);
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				while (1) {
					if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
					if (sn->FindPic(335, 256, 616, 497, _T("魂.bmp|魂(底部).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
						sn->MoveClick(pos.x, pos.y);
						Log(_T("领取成功...\r\n"), game);
						flag = 1;
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (sn->FindStrFast(108, 504, 188, 538, _T("御魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
						break;
					}
					if (flag&&(sn->FindPic(60, 5, 183, 61, _T("协战队伍.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
						if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						flag = 0;
						break;
					}
					if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
			else {
				if ((movefalg == 0) && (sn->FindPic(0, 378, 111, 427, _T("左侧事件(底).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)) {
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
//获取自动轮换状态
int BeginExplore::GetAutoRoTateState(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	CString picname = _T("自动轮换0.bmp|自动轮换1.bmp|自动轮换2.bmp|自动轮换3.bmp|自动轮换4.bmp|自动轮换5.bmp|自动轮换6.bmp|自动轮换7.bmp|自动轮换8.bmp|自动轮换9.bmp|自动轮换10.bmp|自动轮换11.bmp|自动轮换12.bmp|自动轮换13.bmp|自动轮换14.bmp|自动轮换15.bmp|自动轮换16.bmp|自动轮换17.bmp|自动轮换18.bmp|自动轮换19.bmp|");
	int i = 20;
	while (i > 0) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(86, 493, 107, 515, picname, _T("202020"), 0.8, 0, &intX, &intY) != -1) {
			return 1;
		}
		if (DelayPlus(game, sn, 70, 75) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//判断是否需要换狗粮
int BeginExplore::IsChangeMaterial(snow *sn, int material, int mode, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	int rotateres = GetAutoRoTateState(sn, game);
	if (mode==2 && material == 1 && rotateres == 0) {
		Log(_T("候补出战狗粮已用完...\r\n"), game);
		return 1;
	}else if(rotateres == EXIT_THREAD){ return EXIT_THREAD; }
	return 0;
}
//选择何种狗粮
int BeginExplore::WhatMaterialToSelect(CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	if (materialKinds == _T("0")) {
		if (sn->FindPic(103, 220, 151, 270, _T("N卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (materialKinds == _T("1")) {
		if (sn->FindPic(25, 211, 73, 257, _T("素材.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (materialKinds == _T("2")) {
		if (sn->FindPic(180, 265, 215, 300, _T("R卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//狗粮进度条选择
int BeginExplore::SelectProgressBar(CString progress, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->EnableRealMouse(1, 20, 30);
	long intX, intY;
	Log(_T("选择进度...\r\n"), game);
	if (progress == _T("0")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 42, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("1")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 72, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("2")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 102, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("3")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 132, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("4")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 162, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("5")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 192, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("6")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 222, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("7")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 252, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("8")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 282, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("9")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 312, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("10")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 342, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("11")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 372, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("12")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 402, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("13")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 432, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("14")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 462, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("15")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 492, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("16")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 522, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("17")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 552, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("18")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 582, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("19")) {
		if (sn->FindPic(80, 506, 739, 539, _T("进度条.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->DragMouse(pos.x + 12, pos.y, pos.x + 612, pos.y);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	sn->EnableRealMouse(3, 20, 30);
	return 1;
}
//自动换狗粮
int BeginExplore::AutoReplaceMaterial(CString progressBar, CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	long intX, intY;
	int allFlag = 0;
	sn->UseDict(1);
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("开始自动换狗粮...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 7, pos.y + 12);
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(352, 78, 466, 122, _T("候补出战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((allFlag == 0) && (sn->FindPic(352, 78, 466, 122, _T("候补出战.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			Log(_T("选择置入候补式神...\r\n"), game);
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
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(19, 467, 76, 513, _T("全部.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			long clickX = intX, clickY = intY;
			if (sn->FindPic(103, 220, 151, 270, _T("N卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				Log(_T("选择狗粮类型...\r\n"), game);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = sn->RandomOffsetPos(clickX, clickY);
				sn->MoveClick(pos.x + 5, pos.y + 5);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if ((sn->FindPic(103, 220, 151, 270, _T("N卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(25, 211, 73, 257, _T("素材.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(180, 265, 215, 300, _T("R卡.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		WhatMaterialToSelect(materialKinds, sn, game);
		//27,466,73,509,
		if ((sn->FindPic(27, 466, 73, 509, _T("N卡(已选).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(27, 466, 73, 509, _T("素材(已选).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) || (sn->FindPic(27, 466, 73, 509, _T("R卡(已选).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	SelectProgressBar(progressBar, sn, game);
	long startX, startY, beginX = 81;
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((beginX < 647) && (sn->FindStrFast(beginX, 359, 863, 430, _T("出战"), _T("B38859-473D2A"), 0.85, &intX, &intY) != -1)) { //B38859-473D2A
			startX = intX, startY = intY;
			if (sn->FindStrFast(intX - 63, intY + 40, intX - 20, intY + 70, _T("补"), _T("AA9A99-273637"), 0.85, &intX, &intY) == -1) {
				Log(_T("加入出战列表...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(startX, startY);
				sn->MoveTo(pos.x + 5, pos.y + 3);
				Sleep(200);
				sn->LeftDown();
				Sleep(2500);
				sn->LeftUp();
			}
			beginX = startX + 40;
			CString str;
			str.Format(_T("检测[ %d, 359, 863, 430]区域\r\n"), beginX);
			Log(str, game);
		}
		else if (beginX >= 647) {
			//AA9A99-273637
			if (sn->FindStrFast(656, 366, 855, 425, _T("出战"), _T("B38859-473D2A"), 0.85, &intX, &intY) != -1) {
				if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
				//模拟真实鼠标轨迹
				sn->EnableRealMouse(1, 60, 30);
				CPoint pos = sn->RandomOffsetPos(intX, intY);
				Log(_T("翻页...\r\n"), game);
				sn->DragMouse(pos.x - 50, pos.y + 50, pos.x - 550, pos.y + 50);
				beginX = 81;
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (sn->FindPic(772, 79, 873, 122, _T("满狗粮.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("出战列表已满...\r\n"), game);
			//模拟真实鼠标轨迹
			sn->EnableRealMouse(3, 20, 30);
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	while (1) {
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(822, 289, 910, 371, _T("狗粮确定.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("确定候补出战...\r\n"), game);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY);
			sn->MoveClick(pos.x + 2, pos.y + 2);
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("已返回副本...\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	int rotateres = GetAutoRoTateState(sn, game);
	if (rotateres == 1) {
		Log(_T("已恢复自动轮换...\r\n"), game);
	}
	else if (rotateres == EXIT_THREAD) { return EXIT_THREAD; }
	else if (rotateres == 0) {	
		Log(_T("正在恢复自动轮换...\r\n"), game);
		while (1) {
			if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (GetAutoRoTateState(sn, game) == 0) {
				CPoint pos = sn->RandomOffsetPos(100, 505);
				sn->MoveClick(pos.x, pos.y);
				if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (GetAutoRoTateState(sn, game) == 1) {
				Log(_T("已恢复自动轮换...\r\n"), game);
				break;
			}
		}
		
	}
	return 1;
}
//通过庭院判断是否出副本---不触发停止事件
int BeginExplore::IsOutExploreByYard(snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->UseDict(0);
	//start findFunc
	long intX, intY;
	if (sn->FindStrFast(264, 488, 377, 523, _T("组队"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1 || sn->FindStrFast(361, 482, 469, 522, _T("阴|阳|寮"), _T("CCC4BA-181B1B"), 0.8, &intX, &intY) != -1)
	{
		return 1;
	}
	return 0;
}
//组队进入副本
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
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		/*if (count == 0)
		{
			if (sn->FindPic(27, 518, 67, 540, _T("设置.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1)
			{
				Log(_T("检查自动轮换状态...\r\n"), game);
				if (autoRotate(hd, sn, game, index) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("自动轮换已开启\r\n"), game);
			}
		}*/
		//点准备
		if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1){
			if (DelayPlus(game, sn, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			if (sn->FindPic(832, 393, 941, 536, _T("准备.bmp|准备2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				Log(_T("点击准备...\r\n"), game);
				CPoint pos = sn->RandomOffsetPos(intX, intY, 1, 5);
				sn->MoveClick(pos.x, pos.y);
			}
		}
		//胜利结算
		if (sn->FindPic(286, 34, 438, 169, _T("胜利.bmp|胜利1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("战斗结算中...\r\n"), game);
			if (DelayPlus(game, sn, 10, 20) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(388, 372, 567, 456, _T("魂.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(798, 436, 5, 10);
			sn->MoveClick(pos.x, pos.y);
			Log(_T("结算成功...\r\n"), game);
			is_enter_scene = 1;
			if (DelayPlus(game, sn, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(0, 0, 960, 540, _T("奖励.bmp|奖励一.bmp|奖励二.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (ExitExploreEvent(sn, game) == EXIT_THREAD) {return EXIT_THREAD;}
		}
		if (sn->FindPic(74, 164, 136, 219, _T("接受邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (sn->FindStrFast(269, 25, 331, 68, _T("加成"), _T("907C5A-4C4846"), 0.8, &intX, &intY) != -1)
		{
			Log(_T("成功返回庭院！\r\n"), game);
			break;
		}
		if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//接受邀请
int BeginExplore::ReceiveInvite(int count, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//等待好友邀请
	CombineWaitRelation(exteamer1, exteamer2, sn, game);
	long intX, intY;
	CString count_str;
	count_str.Format(_T("%d"), count + 1);
	Log(_T("等待好友邀请...\r\n"), game);
	while (1)
	{
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindPic(74, 164, 136, 219, _T("接受邀请.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count_str.Format(_T("%d"), count + 1);
			Log(_T("接受邀请...\r\n"), game);
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 7);
			Log(_T("第") + count_str + _T("轮探索开始...\r\n"), game);
			count++;
			if (DelayPlus(game, sn, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (collectbox) {//自动捡宝箱
				GetReward(mode, sn, game);
				CombineWaitRelation(exbonus1, exbonus2, sn, game);
			}
		}
		if (sn->FindPic(60, 5, 183, 61, _T("协战队伍.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			Log(_T("进入队伍...\r\n"), game);
			break;
		}
		if (sn->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("进入探索...\r\n"), game);
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
//检测好友进入队伍点挑战 
int BeginExplore::IsEnterTeamRepeat(int preferArea, int count, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	sn->UseDict(0);
	long intX, intY;
	int timerRecord = 0;
	//等待好友出探索
	CombineWaitRelation(exteamer1, exteamer2, sn, game);
	//检查好友是否进入队伍
	Log(_T("等待好友加入队伍...\r\n"), game);
	while (1)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 20, 25);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//点挑战
		if (sn->FindPic(874, 436, 953, 518, _T("挑战.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			Log(_T("好友已加入队伍...\r\n"), game);
			if (collectbox) {//自动捡宝箱
				GetReward(mode, sn, game);
				CombineWaitRelation(exbonus1, exbonus2, sn, game);
			}
			//随机偏移坐标防检测
			CPoint pos = sn->RandomOffsetPos(intX, intY, 5, 10);
			if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(21, 468, 73, 537, _T("扇子纸人.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			Log(_T("进入探索...\r\n"), game);
			game->reSetWaitFlag(exbonus1, exbonus2);
			game->reSetWaitFlag(exteamer1, exteamer2);
			break;
		}
		if (DelayPlus(game, sn, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		timerRecord++;
		if (timerRecord >= 20) {
			if (sn->FindPic(874, 436, 953, 518, _T("挑战(未进队).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				Log(_T("好友未加入，重新邀请好友...\r\n"), game);
				if (InnerCreatTeamToInviteLower(preferArea, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			timerRecord = 0;
		}
	}
	return 1;
}
//互相等待事件
int BeginExplore::CombineWaitRelation(bool &flag1, bool &flag2, snow *sn, Game *game) {
	//如果开启组队关系
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	game->synchronization(flag1, flag2);
	if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	return 1;
}
//探索单刷
int BeginExplore::SingleExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(1);
	long intX, intY;
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
	if (auto_open_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
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
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//选择章节并点击
		CPoint startXY, endXY;
		startXY.x = 777, startXY.y = 131;
		endXY.x = 952, endXY.y = 508;
		//判断开始前是否在章节点开状态
		if (sn->FindStrFast(108, 504, 188, 538, _T("御魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (collectbox) { 
				Log(_T("准备检测...\r\n"), game);
				if (GetReward(mode, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				Log(_T("检测完毕...\r\n"), game);
			}
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(462, 392, 735, 417, _T("组队|探索"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (SingleChooseLayer(layer, startXY, endXY, sn, game) == 1) {
					break; 
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//选择难度
		if (count == 0)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			if (ChooseDiff(diff, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else {
			//点击探索按钮
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//自动轮换
		if (count == 0)
		{
			Log(_T("检查自动轮换状态...\r\n"), game);
			if (autoRotate(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("自动轮换已开启\r\n"), game);
		}
		//进入副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮探索开始...\r\n"), game);
		if (EnterExplore(speed, material, mode, progressBar, materialKinds, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//领取奖励宝箱
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//智能单刷
int BeginExplore::AIExplore(long hd, int round, int layer, int diff, CString jc, int speed, int material, CString progressBar, CString materialKinds, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//使用字库
	sn->UseDict(1);
	long intX, intY;
	Log(_T("------智能单刷模式------\r\n"), game);
	Log(_T("突破券满自动进行任务列表内的下一个任务\r\n"), game);
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
	if (auto_open_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	//寻找探索灯笼并点击
	int result = FindExploreLanTernAndClick(sn, game);
	if (result == 0) {
		InYardNoExploreLanternTips(game);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
	//保持在选择层数界面
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//选择章节并点击
		CPoint startXY, endXY;
		startXY.x = 777, startXY.y = 131;
		endXY.x = 952, endXY.y = 508;
		//判断开始前是否在章节点开状态
		if (sn->FindStrFast(108, 504, 188, 538, _T("御魂"), _T("C9C3B2-2F302E"), 0.85, &intX, &intY) != -1) {
			if (collectbox) { GetReward(mode, sn, game); }
			while (1) {
				if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
				if (sn->FindStrFast(462, 392, 735, 417, _T("组队|探索"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
					break;
				}
				if (SingleChooseLayer(layer, startXY, endXY, sn, game) == 1) {
					break;
				}
				if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		//选择难度
		if (count == 0)
		{
			if (DelayPlus(game, sn, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			//判断是否满突破 ACA799-333734
			if (sn->FindStrFast(706, 12, 730, 30, _T("30"), _T("ACA799-333734"), 0.85, &intX, &intY) != -1)
			{
				Log(_T("突破卷已满...\r\n"), game);
				count = round;
				break;
			}
			if (ChooseDiff(diff, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			if (DelayPlus(game, sn, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else {
			//判断是否满突破 ACA799-333734
			if (sn->FindStrFast(706, 12, 730, 30, _T("30"), _T("ACA799-333734"), 0.85, &intX, &intY) != -1)
			{
				Log(_T("突破卷已满...\r\n"), game);
				count = round;
				break;
			}
			//点击探索按钮
			if (clickExplore(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//自动轮换
		if (count == 0)
		{
			Log(_T("自动轮换...\r\n"), game);
			if (autoRotate(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("自动轮换已开启\r\n"), game);
		}
		//进入副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮探索开始...\r\n"), game);
		if (EnterExplore(speed, material, mode, progressBar, materialKinds, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//领取奖励宝箱
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//组队邀请好友
int BeginExplore::inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, int collectbox, int mode, int material, CString progressBar, CString materialKinds, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//等好友事件
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
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
	if (auto_open_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//判断庭院是否展开,若未展开使之展开
	if (showYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//点击组队
	int resultCombine = CombineTeamAction(sn, game);
	if (resultCombine == 0) {
		Log(_T("很抱歉，未找到组队按钮...\r\n"), game);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选择探索
	//获取当前位置选项  3D3833-3E3933
	CString fontLst = _T("困难|业火|风转|水灵|天雷|御魂|日轮|永生|妖气|经验|金币|年兽|石距|结界|对弈|回归");
	CString color_format = _T("454039-46413A");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;
	//找到探索并点击
	findDestSite(startXY, endXY, fontLst, 0, _T("困难"), color_format, 0.8, 2, sn, game, _T("findstr"), _T("探|CFC8B8-292B28"));
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//选层
	//选择层并点击
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	if (ChooseLayer(layer, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//创建队伍--点击邀请
	if (InnerCreatTeamToInviteUpper(preferArea, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	int CreatRes = InnerCreatTeamToInviteLower(preferArea, sn, game);
	if (CreatRes == 0) {
		Log(_T("创建队伍失败!!!\r\n"), game);
		//未找到最近好友，返回庭院后关闭加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (DelayPlus(game, sn, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//检测好友加入队伍并点挑战
		if (IsEnterTeamRepeat(preferArea, count, collectbox, mode, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动轮换
		if (count == 0)
		{
			if (DelayPlus(game, sn, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("检查自动轮换状态...\r\n"), game);
			if (autoRotate(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
			Log(_T("自动轮换已开启...\r\n"), game);
		}
		if (DelayPlus(game, sn, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入探索副本
		//进入副本
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		Log(_T("第") + count_str + _T("轮探索开始...\r\n"), game);
		if (EnterExplore(speed, material, mode, progressBar, materialKinds, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//领取奖励宝箱
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		if (DelayPlus(game, sn, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//组队接受邀请
int BeginExplore::BeinvitedExplore(long hd, int round, CString jc, int collectbox, int mode, snow *sn, Game *game) {
	if (sn == NULL)
	{
		return 0;
	}
	//等好友事件
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	TeamRelation(waitFlag1, waitFlag2, sn, game);
	if (DelayPlus(game, sn, 50, 200) == EXIT_THREAD) { return EXIT_THREAD; }
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
	if (auto_open_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
	//开始循环
	int count = 0;
	while (count < round)
	{
		//自动拒绝悬赏
		if (AutoRejectXS(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		//接受邀请
		if (ReceiveInvite(count, collectbox, mode, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 2000, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
		//进入探索副本
		if (receiveEnterExplore(count, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//刷完退出
	if (count >= round)
	{
		game->reSetWaitFlag(waitFlag1, waitFlag2);
		if (ExitExploreEvent(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		Log(_T("任务已完成，正在退出返回庭院...\r\n"), game);
		if (ExploreReturnYard(sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		//自动关加成
		startXY.x = 269, startXY.y = 25;
		endXY.x = 331, endXY.y = 68;
		if (auto_close_jc(_T("探索"), jc, startXY, endXY, sn, game) == EXIT_THREAD) { return EXIT_THREAD; }
		if (DelayPlus(game, sn, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//返回庭院
int BeginExplore::ExploreReturnYard(snow *sn, Game *game) {
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
		if (sn->FindPic(760, 83, 814, 135, _T("叉.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(364, 309, 416, 338, _T("取消"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(15, 13, 73, 72, _T("返回1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//760, 83, 814, 135,
		if (sn->FindPic(9, 18, 61, 76, _T("返回5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(555, 292, 608, 316, _T("确认"), _T("3C2E1C-3C2E1D"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindStrFast(541, 310, 596, 339, _T("确定"), _T("4D3A21-4E3B22"), 0.85, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x + 5, pos.y + 5);
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (sn->FindPic(9, 1, 65, 59, _T("返回4.bmp|返回8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (DelayPlus(game, sn, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = sn->RandomOffsetPos(intX, intY, 0, 5);
			sn->MoveClick(pos.x, pos.y);
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
