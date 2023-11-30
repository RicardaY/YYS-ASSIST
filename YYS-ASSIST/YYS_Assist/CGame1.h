#pragma once
#include "CGame_YuHun1.h"
#include "Tabsheet.h"
#include "CGame_jueXing1.h"
#include "CGame_RiLunZhiYun1.h"
#include "CGame_YongShengZhiHai1.h"
#include "CGame_TanSuo1.h"
#include "CGame_DailyTask1.h"
#include "CGame_YeYuanHuo1.h"
#include "CGame_YuLing1.h"
#include "CGame_GeRenTuPo1.h"
#include "CGame_NewEvent1.h"
#include "CGame_Rest1.h"
#include "CGame_inDependentFunc1.h"
#include "CGame_RunLog1.h"
#include "CGame_ChangeEquip1.h"
#include "CGame_Timer1.h"
#include "CGame_Tip1.h"
#include "CGame_Global1.h"
#include "CDragStatic.h"
#include "SuperKing.h"
#include "CGame_FixTeamer.h"
#include "CGame_PushPlus1.h"
#include "Game.h"
// CGame1 对话框
class CGame1 : public CDialog, public Game
{
	DECLARE_DYNAMIC(CGame1)
public:
	CGame1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame1();
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
	// game1 mode
	CTabSheet m_tab_game_mode;
	// 右侧Tab Control
	CTabSheet m_tab_right;
	//game1 all mode class
	CGame_YuHun1 yuhun;
	CGame_JueXing1 juexing;
	CGame_RiLunZhiYun1 riLunZhiYun;
	CGame_YongShengZhiHai1 yongShengZhiHai;
	CGame_TanSuo1 tanSuo;
	CGame_DailyTask1 dailyTask;
	CGame_YeYuanHuo1 yeYuanHuo;
	CGame_YuLing1 yuLing;
	CGame_GeRenTuPo1 geRenTuPo;
	CGame_NewEvent1 newEvent;
	CGame_Rest1 rest;
	CGame_inDependentFunc1 dependent_func;
	CGame_RunLog1 runlog;
	CGame_ChangeEquip1 changeEquip;
	CGame_Timer1 timer;
	CGame_Tip1 tips;
	CGame_Global1 global;
	SuperKing superking;
	CGame_FixTeamer fixTeamer;
	CGame_PushPlus1 pushplus;
	virtual BOOL OnInitDialog();
	// game1客户端类型
	CComboBox m_windowType;
	// 句柄还是窗口
	CComboBox m_win_or_handle;
	// 显示任务
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
	afx_msg void OnBnClickedBtnDeleteSelectTask1();
	afx_msg void OnBnClickedBtnClearTaskList1();
	afx_msg void OnBnClickedBtnStart1();
	// 获得句柄
	CStatic m_hadleText;
	afx_msg void OnBnClickedBtnSuspend1();
	afx_msg void OnBnClickedBtnStop1();
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
