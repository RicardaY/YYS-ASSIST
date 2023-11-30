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
	//���캯��
	BeginDailyTask();
	//----������ӡ
	//ѡ�����
	int ChooseLayer(int layer, CPoint startXY, CPoint endXY, snow *sn, Game *game);
	//���븱��
	int EnterYaoQiFengYin(int condition, snow *sn, Game *game);
	//��ʼ
	int StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, snow *sn, Game *game);
	//----����֮��----
	//����ʱ���ֵ
	CString GetElapsedTimeString(const CTime& startTime, const CTime& endTime);
	//1.1 Ѱ����֮��
	int FindSeaOfMoon(snow *sn, Game *game);
	//1.2 ������֮��
	int OpenSeaOfMoon(snow *sn, Game *game);
	//1.3 ��������ʶ���¼�
	int RadomSelectAndCheckEvent(snow *sn, Game *game);
	//	1.3.1 ��ս
	int Battle(snow *sn, Game *game);
	//	1.3.2 ����
	int Mystery(snow *sn, Game *game);
	//	1.3.3 ����
	int Origin(snow *sn, Game *game);
	//	1.3.4 ��Ϣ
	int Silence(snow *sn, Game *game);
	//	1.3.5 ��֮��
	int IslandOfStar(snow *sn, Game *game);
	//1.4 ѡbuff
	//1.4.1 ���������
	CPoint FindBuff(CString buffname, snow *sn, Game *game);
	//1.4.2 ͨ��ѡbuff
	int SelectBuff(snow *sn, Game *game);
	//1.4.3 ��սѡ�ͼ�buff
	int BattleSelectBuff(snow *sn, Game *game);
	//1.5 ӭս�¶�
	int ToWardsTsukuyomi(snow *sn, Game *game);
	//1.6 ���ݳ���ִ������
	int AccordingSceneRun(int scene, snow *sn, Game *game);
	//2.0 ��ʼ����
	int StartSixPathOfDoor(long hd, int round, snow *sn, Game *game);
	//����֮�ŷ���ͥԺ
	int SixPathOfDoorReturnYard(snow *sn, Game *game);
	//----����֮��(4�������)----
	//	1.3.12 ��ս
	int BattleOnlySoftWind(snow *sn, Game *game);
	//	1.3.22 ����
	int MysteryOnlySoftWind(snow *sn, Game *game);
	//	1.3.32 ����
	int OriginOnlySoftWind(snow *sn, Game *game);
	//	1.3.42 ��Ϣ
	int SilenceOnlySoftWind(snow *sn, Game *game);
	//	1.3.52 ��֮��
	int IslandOfStarOnlySoftWind(int subsel, snow *sn, Game *game);
	//1.42 ѡbuff
	//1.4.12 ���������
	CPoint FindBuffOnlySoftWind(CString buffname, snow *sn, Game *game);
	//1.4.22 ͨ��ѡbuff
	int SelectBuffOnlySoftWind(snow *sn, Game *game);
	//1.4.32 ��սѡ�ͼ�buff
	int BattleSelectBuffOnlySoftWind(snow *sn, Game *game);
	//1.52 ӭս�¶�
	int ToWardsTsukuyomiOnlySoftWind(snow *sn, Game *game);
	//1.62 ���ݳ���ִ������
	int AccordingSceneRunOnlySoftWind(int scene, int subsel, snow *sn, Game *game);
	//2.02 ��ʼ����
	int StartSixPathOfDoorOnlySoftWind(long hd, int round, int subsel, snow *sn, Game *game);
	//----�ճ�����----
	//���븱��
	int EnterTaskFunc(long hd, int condition, CString picName, CString fontName, int mode_index, snow *sn, Game *game);
	int Experience(long hd, int round, int condition, snow *sn, Game *game);
	int GoldCoin(long hd, int round, int condition, snow *sn, Game *game);
	int RegressionChallenge(long hd, int round, int condition, snow *sn, Game *game);
	//����
	int Vestige(long hd, int round, snow *sn, int subsel, Game *game);
	//���Ͽ�ʼ
	int StartAllDaily(long hd, int condition, int round, int headsel, int subsel, snow *sn, Game *game);
};

