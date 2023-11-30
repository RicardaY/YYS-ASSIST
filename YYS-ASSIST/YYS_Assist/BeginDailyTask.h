#pragma once
#include "yys_function.h"
class BeginDailyTask :public yys_function
{
private:
	enum Scene { BATTLE = 1, MYSTERY, ORIGIN, SILENCE, ISLANDOFSTAR, BOSS };
	enum State { TREASURE = 1, ELITE };
	int extream;
	int softwind, origin_state, cruel;
public:
	//构造函数
	BeginDailyTask();
	//----妖气封印
	//选择层数
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//进入副本
	int EnterYaoQiFengYin(int condition, snow *sn, Game *game);
	//开始
	int StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, snow *sn, Game *game);
	//----六道之门----
	//计算时间差值
	CString GetElapsedTimeString(const CTime& startTime, const CTime& endTime);
	//1.1 寻找月之海
	int FindSeaOfMoon(snow *sn, Game *game);
	//1.2 开启月之海
	int OpenSeaOfMoon(snow *sn, Game *game);
	//1.3 随机点击并识别事件
	int RadomSelectAndCheckEvent(snow *sn, Game *game);
	//	1.3.1 鏖战
	int Battle(snow *sn, Game *game);
	//	1.3.2 神秘
	int Mystery(snow *sn, Game *game);
	//	1.3.3 混沌
	int Origin(snow *sn, Game *game);
	//	1.3.4 宁息
	int Silence(snow *sn, Game *game);
	//	1.3.5 星之屿
	int IslandOfStar(snow *sn, Game *game);
	//1.4 选buff
	//1.4.1 抽象出方法
	CPoint FindBuff(CString buffname, snow *sn, Game *game);
	//1.4.2 通用选buff
	int SelectBuff(snow *sn, Game *game);
	//1.4.3 鏖战选低级buff
	int BattleSelectBuff(snow *sn, Game *game);
	//1.5 迎战月读
	int ToWardsTsukuyomi(snow *sn, Game *game);
	//1.6 根据场景执行任务
	int AccordingSceneRun(int scene, snow *sn, Game *game);
	//2.0 开始任务
	int StartSixPathOfDoor(long hd, int round, snow *sn, Game *game);
	//六道之门返回庭院
	int SixPathOfDoorReturnYard(snow *sn, Game *game);
	//----六道之门(4柔风阵容)----
	//	1.3.12 鏖战
	int BattleOnlySoftWind(snow *sn, Game *game);
	//	1.3.22 神秘
	int MysteryOnlySoftWind(snow *sn, Game *game);
	//	1.3.32 混沌
	int OriginOnlySoftWind(snow *sn, Game *game);
	//	1.3.42 宁息
	int SilenceOnlySoftWind(snow *sn, Game *game);
	//	1.3.52 星之屿
	int IslandOfStarOnlySoftWind(int subsel, snow *sn, Game *game);
	//1.42 选buff
	//1.4.12 抽象出方法
	CPoint FindBuffOnlySoftWind(CString buffname, snow *sn, Game *game);
	//1.4.22 通用选buff
	int SelectBuffOnlySoftWind(snow *sn, Game *game);
	//1.4.32 鏖战选低级buff
	int BattleSelectBuffOnlySoftWind(snow *sn, Game *game);
	//1.52 迎战月读
	int ToWardsTsukuyomiOnlySoftWind(snow *sn, Game *game);
	//1.62 根据场景执行任务
	int AccordingSceneRunOnlySoftWind(int scene, int subsel, snow *sn, Game *game);
	//2.02 开始任务
	int StartSixPathOfDoorOnlySoftWind(long hd, int round, int subsel, snow *sn, Game *game);
	//----日常功能----
	//进入副本
	int EnterTaskFunc(long hd, int condition, CString picName, CString fontName, int mode_index, snow *sn, Game *game);
	int Experience(long hd, int round, int condition, snow *sn, Game *game);
	int GoldCoin(long hd, int round, int condition, snow *sn, Game *game);
	int RegressionChallenge(long hd, int round, int condition, snow *sn, Game *game);
	//契灵
	int Vestige(long hd, int round, snow *sn, int subsel, Game *game);
	//整合开始
	int StartAllDaily(long hd, int condition, int round, int headsel, int subsel, snow *sn, Game *game);
};

