#pragma once
#include "snow.h"
#include "Game.h"
#define NOMAL 500
#define FAIL 404
#define DEFAULT 501
#define NULL_LIST -1
#define ERR_CODE -2

class yys_function
{
public:
	//提示
	int Tips(Game *game);
	//不在庭院提示信息
	int NotInYardTips(long hd, snow *sn, Game *game);
	//在庭院，未找到探索灯笼提示信息
	int InYardNoExploreLanternTips(Game *game);
	//读文件
	int ReadFile(CString filePath, int loff, CStringArray& ListArray);
	//写文件
	int WriteFile(CString filePath, int loff, CStringArray& ListArray);
	//编辑框结尾追加数据
	void Log(CString logMsg, Game *game);
	//随机延迟点击，防止游戏外挂检测
	int DelayPlus(Game *game, snow *sn, int minms = 1000, int maxms = 2500);
	//判断是否在庭院
	bool IsInYard(snow *sn, Game *game);
	//判断庭院是否展开
	bool IsShowYard(snow *sn, Game *game);
	//展开庭院
	int showYard(snow *sn, Game *game);
	//寻找探索灯笼并点击
	int FindExploreLanTernAndClick(snow *sn, Game *game);
	//点击组队
	int CombineTeamAction(snow *sn, Game *game);
	//获取当前位置
	long findCurrentSite(CPoint startXY, CPoint endXY, CString picFontLst, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode = _T("findstr"));
	//寻找返回图标位置
	long findBackIconSite(snow *sn, Game *game, long &intX, long &intY);
	//寻找手动图标位置
	long findManualSite(snow *sn, Game *game, long &intX, long &intY);
	//寻找目标位置并点击   targetTagFont: 探|color_format
	int findDestSite(CPoint startXY, CPoint endXY, CString picFontLst, long targetSite, CString tartgetPicFont, CString color_format, double sim, int dictId, snow *sn, Game *game, CString mode = _T("findstr"), CString targetTagFont = nullptr);
	//创建队伍
	int CreatTeamToInviteUpper(int mateType, snow *sn, Game *game);
	int CreatTeamToInviteLower(int mateType, snow *sn, Game *game);
	//组队关系
	int TeamRelation(bool &flag1, bool &flag2, snow *sn, Game *game);
	//好友是否进入队伍
	int IsEnterTeam(snow *sn, Game *game, int mateType, int triple);
	//邀请进入副本
	int InviteEnterEvent(snow *sn, Game *game);
	//接受邀请
	int ReceiveFriendInvite(snow *sn, Game *game);
	//进入副本
	int EnterEvent(snow *sn, Game *game, bool isReadyClick);
	//默认邀请好友
	int DefalutInvite(snow *sn, Game *game);
	//失败事件
	int FailEvent(snow *sn, Game *game);
	//自动开加成
	int auto_open_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game);
	//自动关加成
	int auto_close_jc(CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, snow *sn, Game *game);
	//自动拒绝悬赏封印
	int AutoRejectXS(snow *sn, Game *game);
	//返回庭院
	int returnYard(snow *sn, Game *game);
	//微信推送
	int PushPlus(CString token, int pushstate, CString tips, Game *game);
};
