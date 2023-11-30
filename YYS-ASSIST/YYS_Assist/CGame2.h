#pragma once
#include "Tabsheet.h"
#include "CGame_YuHun2.h"
#include "CGame_JueXing2.h"
#include "CGame_RiLunZhiYun2.h"
#include "CGame_YongShengZhiHai2.h"
#include "CGame_TanSuo2.h"
#include "CGame_DailyTask2.h"
#include "CGame_YeYuanHuo2.h"
#include "CGame_YuLing2.h"
#include "CGame_GeRenTuPo2.h"
#include "CGame_NewEvent2.h"
#include "CGame_Rest2.h"
#include "CGame_inDependentFunc2.h"
#include "CGame_RunLog2.h"
#include "CGame_ChangeEquip2.h"
#include "CGame_Timer2.h"
#include "CGame_Tip2.h"
#include "CGame_Global2.h"
#include "CDragStatic.h"
#include "SuperKing2.h"
#include "CGame_PushPlus2.h"
#include "Game.h"
// CGame2 对话框
class CGame2 : public CDialog, public Game
{
	DECLARE_DYNAMIC(CGame2)
public:
	CGame2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame2();
private:
	bool pause, start, stop;
	std::string fileName;
	//preset var
	CString countTemp;
	int tpmode, mode, layer, kind, diff, bonus, automaterial, speed, friendArea, selIndex, winReceive, material, bar, reward;
	int yhg, jxg, tsg, rlzyg, yszhg, ylg, yyhg, jjtpg, yqfyg;
	int yht, jxt, tst, rlzyt, yszht1, yszht2, ylt, yyht, jjtpt, yqfyt;
	int machine_select, length, global_relation, global_reject, aiexplore;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GAME };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	// game2 mode
	CTabSheet m_tab_game_mode;
	// 右侧Tab Control
	CTabSheet m_tab_right;
	//game2 all mode class
	CGame_YuHun2 yuhun;
	CGame_JueXing2 juexing;
	CGame_RiLunZhiYun2 riLunZhiYun;
	CGame_YongShengZhiHai2 yongShengZhiHai;
	CGame_TanSuo2 tanSuo;
	CGame_DailyTask2 dailyTask;
	CGame_YeYuanHuo2 yeYuanHuo;
	CGame_YuLing2 yuLing;
	CGame_GeRenTuPo2 geRenTuPo;
	CGame_NewEvent2 newEvent;
	CGame_Rest2 rest;
	CGame_inDependentFunc2 independent_func;
	CGame_RunLog2 runlog;
	CGame_ChangeEquip2 changeEquip;
	CGame_Timer2 timer;
	CGame_Tip2 tips;
	CGame_Global2 global;
	SuperKing2 superking;
	CGame_PushPlus2 pushplus;
	virtual BOOL OnInitDialog();
	// game2客户端类型
	CComboBox m_windowType;
	// 句柄还是窗口
	CComboBox m_win_or_handle;
	// 任务列表展示
	CListCtrl m_list_taskshow;
	//日志输出
	void log(CString logMsg) override;
	//线程状态
	void setThreadPauseState(bool state) override;
	bool getThreadPauseState() override;
	void setThreadStartState(bool state) override;
	bool getThreadStartState() override;
	void setThreadStopState(bool state) override;
	bool getThreadStopState() override;
	//初始化线程
	void initThread();
	void synchronization(bool &waitFlag1, bool &waitFlag2) override;
	//获取时间
	CString GetTime() override;
	//重置同步状态
	void reSetWaitFlag(bool &flag1, bool &flag2) override;
	//获取json文件名
	std::string getFileName() override;
	//保存预设
	int SaveToFile(std::string savePath) override;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	// 拖动的图片控件
	CDragStatic m_DragStatic;
	afx_msg void OnBnClickedBtnDeleteSelectTask2();
	afx_msg void OnBnClickedBtnClearTaskList2();
	afx_msg void OnBnClickedBtnStart2();
	afx_msg void OnBnClickedBtnSuspend2();
	afx_msg void OnBnClickedBtnStop2();
	// 句柄显示
	CStatic m_hadleText;
	afx_msg void OnBnClickedTaskup();
	afx_msg void OnBnClickedTaskdown();
	afx_msg void OnBnClickedBtnImport();
	afx_msg void OnBnClickedBtnExport();
	// 循环次数
	CEdit m_circle;
	afx_msg void OnBnClickedBtnUpdate();
	CStatic m_version;
	static UINT ThreadProc(LPVOID);
	static UINT ThreadProcSaveFile(LPVOID);
};
