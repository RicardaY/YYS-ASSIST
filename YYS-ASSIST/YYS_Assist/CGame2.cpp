// CGame2.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "CGame2.h"
#include "involve.h"

#define EXIT_THREAD -10
CGame2 *p;

// CGame2 对话框
IMPLEMENT_DYNAMIC(CGame2, CDialog)
CGame2::CGame2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_GAME, pParent)
{
	p = this;
}
CGame2::~CGame2()
{
	
}
void CGame2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MODE, m_tab_game_mode);
	DDX_Control(pDX, IDC_WINDOW_TYPE, m_windowType);
	DDX_Control(pDX, IDC_COMBO_W_OR_H, m_win_or_handle);
	DDX_Control(pDX, IDC_LIST_SHOW_ADDTASK, m_list_taskshow);
	DDX_Control(pDX, IDC_TAB_RIGHT, m_tab_right);
	DDX_Control(pDX, IDC_DRAG_HANDLE, m_DragStatic);
	DDX_Control(pDX, IDC_GET_HD, m_hadleText);
	DDX_Control(pDX, IDC_CIRCLE, m_circle);
	DDX_Control(pDX, IDC_VERSION, m_version);
}
BEGIN_MESSAGE_MAP(CGame2, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_DELETE_SELECT_TASK, &CGame2::OnBnClickedBtnDeleteSelectTask2)
	ON_BN_CLICKED(IDC_BTN_CLEAR_TASK_LIST, &CGame2::OnBnClickedBtnClearTaskList2)
	ON_BN_CLICKED(IDC_BTN_START, &CGame2::OnBnClickedBtnStart2)
	ON_BN_CLICKED(IDC_BTN_SUSPEND, &CGame2::OnBnClickedBtnSuspend2)
	ON_BN_CLICKED(IDC_BTN_STOP, &CGame2::OnBnClickedBtnStop2)
	ON_BN_CLICKED(IDC_TASKUP, &CGame2::OnBnClickedTaskup)
	ON_BN_CLICKED(IDC_TASKDOWN, &CGame2::OnBnClickedTaskdown)
	ON_BN_CLICKED(IDC_BTN_IMPORT, &CGame2::OnBnClickedBtnImport)
	ON_BN_CLICKED(IDC_BTN_EXPORT, &CGame2::OnBnClickedBtnExport)
	ON_BN_CLICKED(IDC_BTN_UPDATE, &CGame2::OnBnClickedBtnUpdate)
END_MESSAGE_MAP()
// CGame2 消息处理程序
BOOL CGame2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	m_tab_game_mode.AddPage(_T("御魂"), &yuhun, IDD_YUHUN_DLG);
	m_tab_game_mode.AddPage(_T("觉醒"), &juexing, IDD_JueXing_DLG);
	m_tab_game_mode.AddPage(_T("日轮之陨"), &riLunZhiYun, IDD_RiLunZhiYun_DLG);
	m_tab_game_mode.AddPage(_T("永生之海"), &yongShengZhiHai, IDD_YongShengZhiHai_DLG);
	m_tab_game_mode.AddPage(_T("探索"), &tanSuo, IDD_TanSuo_DLG);
	m_tab_game_mode.AddPage(_T("日常"), &dailyTask, IDD_YaoQiFengYin_DLG);
	m_tab_game_mode.AddPage(_T("业原火"), &yeYuanHuo, IDD_YeYuanHuo_DLG);
	m_tab_game_mode.AddPage(_T("御灵"), &yuLing, IDD_YuLing_DLG);
	m_tab_game_mode.AddPage(_T("个突/寮突"), &geRenTuPo, IDD_GeRenTuPo_DLG);
	m_tab_game_mode.AddPage(_T("新活动"), &newEvent, IDD_NEW_EVENT_DLG);
	m_tab_game_mode.AddPage(_T("休息"), &rest, IDD_Rest_DLG);
	m_tab_game_mode.Show();
	m_tab_right.AddPage(_T("独立功能"), &independent_func, IDD_INDEPENDENT);
	m_tab_right.AddPage(_T("御魂预设"), &changeEquip, IDD_CHANGEEQUIP);
	m_tab_right.AddPage(_T("定时"), &timer, IDD_TIMER);
	m_tab_right.AddPage(_T("运行日志"), &runlog, IDD_RunLog);
	m_tab_right.AddPage(_T("全局"), &global, IDD_GLOBAL);
	m_tab_right.AddPage(_T("使用说明"), &tips, IDD_TIPS);
	m_tab_right.AddPage(_T("超鬼王"), &superking, IDD_SUPERKING);
	m_tab_right.AddPage(_T("微信推送"), &pushplus, IDD_PUSHPLUS);
	m_tab_right.Show();
	m_tab_right.SetCurSel(5);
	//初始化版本号
	m_version.SetWindowTextW(version);
	//初始化数据
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 12, fname2);
	if (preset &&  line.size() == 1) {
		m_windowType.SetCurSel(std::any_cast<int>(line[0]));
	}
	else {
		m_windowType.SetCurSel(1);
	}

	m_win_or_handle.SetCurSel(0);
	m_circle.SetWindowTextW(_T("1"));
	//高级列表默认值
	m_list_taskshow.InsertColumn(0, _T("↓任务列表按上往下执行[修改上面的设置必须重新添加]↓"), LVCFMT_LEFT, 550);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
//上移选中任务
void CGame2::OnBnClickedTaskup()
{
	//获取当前行号
	POSITION ps;
	int nCurrentItem;
	ps = m_list_taskshow.GetFirstSelectedItemPosition();
	if (ps == NULL) {
		return;
	}
	nCurrentItem = m_list_taskshow.GetNextSelectedItem(ps);
	//已经到最顶端则不上移
	if (nCurrentItem <= 0)
	{
		MessageBox(_T("已经移动到最顶端！"), NULL, MB_ICONINFORMATION);
		return;
	}
	//提取行所有信息
	int nColumnCount = m_list_taskshow.GetHeaderCtrl()->GetItemCount();
	CString strCurrentItem[30];	//给予更大的空间
	for (int i = 0; i <= nColumnCount; i++)
	{
		strCurrentItem[i] = m_list_taskshow.GetItemText(nCurrentItem, i);
	}
	//删除该行
	m_list_taskshow.DeleteItem(nCurrentItem);
	// 在nCurrentItem -1位置处插入上面所删列表项的各列
	int strNewItem = m_list_taskshow.InsertItem(nCurrentItem - 1, strCurrentItem[0]);
	for (int j = 1; j <= nColumnCount; j++)
	{
		m_list_taskshow.SetItemText(strNewItem, j, strCurrentItem[j]);
	}
	// 使得IndexInFieldList-1位置处项目高亮显示并获得焦点
	nCurrentItem--;
	m_list_taskshow.SetFocus();
	m_list_taskshow.SetItemState(nCurrentItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
}
//下移选中任务
void CGame2::OnBnClickedTaskdown()
{
	//获取当前行号
	POSITION ps;
	int nCurrentItem;
	ps = m_list_taskshow.GetFirstSelectedItemPosition();
	if (ps == NULL) {
		return;
	}
	nCurrentItem = m_list_taskshow.GetNextSelectedItem(ps);
	//已经到最顶端则不上移
	if (nCurrentItem >= m_list_taskshow.GetItemCount() - 1)
	{
		MessageBox(_T("已经移动到最底端！"), NULL, MB_ICONINFORMATION);
		return;
	}
	//提取行所有信息
	int nColumnCount = m_list_taskshow.GetHeaderCtrl()->GetItemCount();
	CString strCurrentItem[30];	//给予更大的空间
	for (int i = 0; i <= nColumnCount; i++)
	{
		strCurrentItem[i] = m_list_taskshow.GetItemText(nCurrentItem, i);
	}
	//删除该行
	m_list_taskshow.DeleteItem(nCurrentItem);
	// 在nCurrentItem +1位置处插入上面所删列表项的各列
	int strNewItem = m_list_taskshow.InsertItem(nCurrentItem + 1, strCurrentItem[0]);
	for (int j = 1; j <= nColumnCount; j++)
	{
		m_list_taskshow.SetItemText(strNewItem, j, strCurrentItem[j]);
	}
	// 使得IndexInFieldList+1位置处项目高亮显示并获得焦点
	nCurrentItem++;
	m_list_taskshow.SetFocus();
	m_list_taskshow.SetItemState(nCurrentItem, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
}
//删除选中任务
void CGame2::OnBnClickedBtnDeleteSelectTask2()
{
	POSITION pos = m_list_taskshow.GetFirstSelectedItemPosition();
	while (pos)
	{
		int nItem = m_list_taskshow.GetNextSelectedItem(pos);
		m_list_taskshow.DeleteItem(nItem);
	}
}
//清空任务列表
void CGame2::OnBnClickedBtnClearTaskList2()
{
	m_list_taskshow.DeleteAllItems();
}
UINT CGame2::ThreadProc(LPVOID lpParameter) {
	snow *sn = new snow;
	//设置字库
	sn->SetPath(g_path);
	sn->SetDict(0, _T("Yard.txt"));
	sn->SetDict(1, _T("Explore.txt"));
	sn->SetDict(2, _T("TeamUp.txt"));
	sn->SetDict(3, _T("SinglePlay.txt"));
	sn->SetDict(4, _T("CommonUsed.txt"));
	sn->SetDict(5, _T("SixDoor.txt"));
	sn->SetDict(6, _T("NewEvent.txt"));
	//模拟真实鼠标轨迹
	sn->EnableRealMouse(3, 20, 30);
	CGame2 *game2 = (CGame2*)lpParameter;
	CString m_handle;
	game2->m_hadleText.GetWindowTextW(m_handle);
	long handle = StrToInt(m_handle);
	long sn_band = 0;
	if (m_handle.IsEmpty())
	{
		::MessageBox(NULL, _T("请选择句柄！"), _T("提示"), 0);
		game2->setThreadStartState(false);
		game2->setThreadStopState(true);
		//解绑
		if (sn->IsBind(handle))
		{
			sn->UnBindWindow();
		}
		//释放资源
		if (sn != NULL)
		{
			delete sn;
			sn = NULL;
			
		}
		return 0;
	}	
	int simMachineType = game2->m_windowType.GetCurSel();
	//输出提示信息
	game2->log(_T("正在初始化...\r\n"));
	//雷电(最小化)
	if (simMachineType == 0) {
		sn_band = sn->BindWindowEx(handle, _T("dx.graphic.opengl"), _T("windows3"), _T("windows"), _T("dx.public.prevent.block"), 0);
	}
	//mumu(blue)/雷电
	else if (simMachineType == 1) {
		sn_band = sn->BindWindowEx(handle, _T("gdi"), _T("windows3"), _T("windows"), _T("dx.public.prevent.block"), 101);
	}//mumu(yellow)
	else if (simMachineType == 2) {
		sn_band = sn->BindWindowEx(handle, _T("dx.graphic.3d.10plus"), _T("windows3"), _T("windows"), _T("dx.public.prevent.block"), 0);
	}
	Sleep(666);
	game2->log(_T("初始化..\r\n"));
	Sleep(666);
	game2->log(_T("初始化完成\r\n"));
	Sleep(666);
	if (sn_band != 1)
	{
		long err = GetLastError();
		CString err_str;
		err_str.Format(_T("%d"), err);
		::MessageBox(NULL, _T("绑定窗口句柄失败，错误码：" + err_str), _T("提示"), 0);
		game2->setThreadStartState(false);
		game2->setThreadStopState(true);
		if (sn != NULL)
		{
			delete sn;
			sn = NULL;
			
		}
		return 0;
	}
	//定时启动
	int timingStart = game2->timer.m_tmstart.GetCheck();
	CString timingConstr;
	game2->timer.GetDlgItemText(IDC_GRTP_ROUND, timingConstr);
	int timingCon = StrToInt(timingConstr);
	if (timingStart) {
		int sleeptime = timingCon * 60;
		int i = 0;
		yys_function *waitfunc = new yys_function;
		game2->log(_T("定时启动开始，开始等待...\r\n"));
		while (i < sleeptime) {
			if (waitfunc->DelayPlus(game2, sn, 3000, 3002) == EXIT_THREAD) {
				game2->log(_T("线程已停止!\r\n"));
				if (waitfunc != nullptr) { delete waitfunc; waitfunc = nullptr; }
				game2->setThreadStopState(true);
				game2->setThreadStartState(false);
				
				return EXIT_THREAD;
			}
			i += 3;
		}
		game2->log(_T("定时时间到，开始启动任务!\r\n"));
		if (waitfunc != nullptr) { delete waitfunc; waitfunc = nullptr; }
	}
	//独立/定时功能遍历列表
	int amount = game2->independent_func.m_amount.GetCurSel();
	int nCount = game2->m_list_taskshow.GetItemCount();
	int baigui = game2->independent_func.m_baigui.GetCheck();
	int regionKing = game2->independent_func.m_king.GetCheck();
	int kindCheck = game2->independent_func.GetCheckedRadioButton(IDC_RADIO_HOT, IDC_RADIO_COLLECT);//选中的索引
	int plot = game2->independent_func.m_plot.GetCheck();
	int pvp = game2->independent_func.m_pvp.GetCheck();
	int pvp_type = game2->independent_func.m_pvptype.GetCurSel();
	int ready = game2->independent_func.m_ready.GetCheck();
	int clearing = game2->independent_func.m_clearing.GetCheck();
	int whitecard = game2->independent_func.m_whitecard.GetCheck();
	int challenge = game2->independent_func.m_challenge.GetCheck();
	int smallpve = game2->independent_func.m_small.GetCheck();
	int lingran = game2->independent_func.m_lingran.GetCheck();
	int dependFlag = baigui | regionKing | plot | pvp | ready | clearing | whitecard | challenge | smallpve | lingran;
	int adopt = game2->timer.m_adopt.GetCheck();
	if ((nCount == 0) && (dependFlag == 0))
	{
		::MessageBox(NULL, _T("任务列表未添加任何任务！"), _T("提示"), 0);
		game2->setThreadStartState(false);
		game2->setThreadStopState(true);
		//解绑
		if (sn->IsBind(handle))
		{
			sn->UnBindWindow();
		}
		//释放资源
		if (sn != NULL)
		{
			delete sn;
			sn = NULL;
			
		}
		return 0;
	}
	//输出提示信息
	yys_function *tips = new yys_function;
	tips->Tips(game2);
	delete tips;
	tips = nullptr;
	//独立功能开始
	if (dependFlag == 1) {
		InDependentFunction dependFunc;
		if (baigui == 1) {
			int threadRes = dependFunc.StartBaiGui(1000, sn, game2);
			//中途结束线程
			if (threadRes == EXIT_THREAD)
			{
				game2->log(_T("线程已停止!\r\n"));
				//解绑
				if (sn->IsBind(handle))
				{
					sn->UnBindWindow();
				}
				//释放资源
				if (sn != NULL)
				{
					delete sn;
					sn = NULL;
				}
				game2->setThreadStopState(true);
				game2->setThreadStartState(false);
				
				return EXIT_THREAD;
			}
		}
		else if (regionKing == 1) {
			int threadRes = dependFunc.StartReginalKing(handle, amount, kindCheck, sn, game2);
			//中途结束线程
			if (threadRes == EXIT_THREAD)
			{
				game2->log(_T("线程已停止!\r\n"));
				//解绑
				if (sn->IsBind(handle))
				{
					sn->UnBindWindow();
				}
				//释放资源
				if (sn != NULL)
				{
					delete sn;
					sn = NULL;
				}
				game2->setThreadStopState(true);
				game2->setThreadStartState(false);
				
				return EXIT_THREAD;
			}
		}
		else if (plot == 1) {
			int threadRes = dependFunc.AutoPlot(sn, game2);
			//中途结束线程
			if (threadRes == EXIT_THREAD)
			{
				game2->log(_T("线程已停止!\r\n"));
				//解绑
				if (sn->IsBind(handle))
				{
					sn->UnBindWindow();
				}
				//释放资源
				if (sn != NULL)
				{
					delete sn;
					sn = NULL;
				}
				game2->setThreadStopState(true);
				game2->setThreadStartState(false);
				return EXIT_THREAD;
				
			}
		}
		else if (pvp == 1) {
			int threadRes;
			if (pvp_type == 0) {
				threadRes = dependFunc.AutoPVP(sn, game2);
			}
			else if (pvp_type == 1) {
				threadRes = dependFunc.AutoPVPToMingShi(sn, game2);
			}
			//中途结束线程
			if (threadRes == EXIT_THREAD)
			{
				game2->log(_T("线程已停止!\r\n"));
				//解绑
				if (sn->IsBind(handle))
				{
					sn->UnBindWindow();
				}
				//释放资源
				if (sn != NULL)
				{
					delete sn;
					sn = NULL;
				}
				game2->setThreadStopState(true);
				game2->setThreadStartState(false);
				
				return EXIT_THREAD;
			}
		}
		else if (ready || clearing || whitecard || challenge) {
			int threadRes;
			threadRes = dependFunc.DIYFunction(ready, clearing, whitecard, challenge, sn, game2);
			//中途结束线程
			if (threadRes == EXIT_THREAD)
			{
				game2->log(_T("线程已停止!\r\n"));
				//解绑
				if (sn->IsBind(handle))
				{
					sn->UnBindWindow();
				}
				//释放资源
				if (sn != NULL)
				{
					delete sn;
					sn = NULL;
				}
				game2->setThreadStopState(true);
				
				game2->setThreadStartState(false);
				return EXIT_THREAD;
			}
		}
		else if (smallpve == 1) {
			int threadRes = dependFunc.StartMiWen(sn, game2);
			//中途结束线程
			if (threadRes == EXIT_THREAD)
			{
				game2->log(_T("线程已停止!\r\n"));
				//解绑
				if (sn->IsBind(handle))
				{
					sn->UnBindWindow();
				}
				//释放资源
				if (sn != NULL)
				{
					delete sn;
					sn = NULL;
				}
				game2->setThreadStopState(true);
				game2->setThreadStartState(false);
				
				return EXIT_THREAD;
			}
		}
		else if (lingran == 1) {
			int threadRes = dependFunc.StartLingRan(sn, game2);
			//中途结束线程
			if (threadRes == EXIT_THREAD)
			{
				game2->log(_T("线程已停止!\r\n"));
				//解绑
				if (sn->IsBind(handle))
				{
					sn->UnBindWindow();
				}
				//释放资源
				if (sn != NULL)
				{
					delete sn;
					sn = NULL;
				}
				game2->setThreadStopState(true);
				game2->setThreadStartState(false);

				return EXIT_THREAD;
			}
		}
	}
	//主功能
	CString get_item[20];
	for (int i = 0; i < nCount; i++) {
		get_item[i] = game2->m_list_taskshow.GetItemText(i, 0);
	}
	//拆分字符串
	CStringArray strResult[20];
	for (int i = 0; i < nCount; i++)
	{
		sn->SplitString(get_item[i], _T("-"), strResult[i], FALSE);
	}
	//开始任务
	CString circle_str;
	game2->m_circle.GetWindowTextW(circle_str);
	int circle = StrToInt(circle_str);
	for (int j = 0; j < circle; j++) {
		for (int i = 0; i < nCount; i++)
		{
			if (strResult[i].GetAt(0) == _T("探索")) {
				BeginExplore explore;
				CString round_str = strResult[i].GetAt(1);
				CString mode_str = strResult[i].GetAt(2);
				CString layer_str = strResult[i].GetAt(3);
				CString diff_str = strResult[i].GetAt(4);
				CString jc_str = strResult[i].GetAt(6);
				CString preferArea_str = strResult[i].GetAt(7);
				CString speed_str = strResult[i].GetAt(8);
				CString material_str = strResult[i].GetAt(9);
				CString materialKinds_str = strResult[i].GetAt(10);
				CString progressBar_str = strResult[i].GetAt(11);
				CString reward_str = strResult[i].GetAt(12);
				CString ai_str = strResult[i].GetAt(13);
				int round = StrToInt(round_str);
				int mode = StrToInt(mode_str);
				int layer = StrToInt(layer_str);
				int diff = StrToInt(diff_str);
				int preferArea = StrToInt(preferArea_str);
				int speed = StrToInt(speed_str);
				int material = StrToInt(material_str);
				int reward = StrToInt(reward_str);
				int ai = StrToInt(ai_str);
				//控制线程结束标志
				int threadRes;
				if (mode == 1) {
					//判断是否存在image_dir
					if ((preferArea == 3) || (preferArea == 4)) {
						if (!PathIsDirectory(_T("config\\imgGame12"))) {
							game2->log(_T("未检测到固定队友图片目录，请先使用右侧功能-->截图固定队友！\r\n"));
							game2->log(_T("线程已停止！\r\n"));
							//解绑
							if (sn->IsBind(handle))
							{
								sn->UnBindWindow();
							}
							//释放资源
							if (sn != NULL)
							{
								delete sn;
								sn = NULL;
							}
							game2->setThreadStopState(true);
							game2->setThreadStartState(false);
							
							return EXIT_THREAD;
						}
					}
				}
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_tsg.GetCurSel();
					int team = game2->changeEquip.m_tst.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, group, team, sn, game2);
				}
				if (mode == 0)
				{
					threadRes = explore.BeinvitedExplore(handle, round, jc_str, reward, mode, sn, game2);
				}
				else if (mode == 1)
				{
					threadRes = explore.inviteExplore(handle, round, layer, jc_str, preferArea, speed, reward, mode, material, progressBar_str, materialKinds_str, sn, game2);
				}
				else if (mode == 2)
				{
					if (ai == 0) {
						threadRes = explore.SingleExplore(handle, round, layer, diff, jc_str, speed, material, progressBar_str, materialKinds_str, reward, mode, sn, game2);
					}
					else if (ai == 1) {
						threadRes = explore.AIExplore(handle, round, layer, diff, jc_str, speed, material, progressBar_str, materialKinds_str, reward, mode, sn, game2);
					}
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止！\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("御魂")) {
				BeginYuhun yuhun;
				CString round_str = strResult[i].GetAt(1);
				CString layer_str = strResult[i].GetAt(2);
				CString jc_str = strResult[i].GetAt(3);
				CString mode_str = strResult[i].GetAt(4);
				CString mateType_str = strResult[i].GetAt(5);
				CString triple_str = strResult[i].GetAt(6);
				int round = StrToInt(round_str);
				int layer = StrToInt(layer_str);
				int mode = StrToInt(mode_str);
				int mateType = StrToInt(mateType_str);
				int triple = StrToInt(triple_str);
				//控制线程结束标志
				int threadRes;
				if (mode == (int)IDC_RADIO_YH_ASK) {
					//判断是否存在image_dir
					if ((mateType == 2) || (mateType == 3)) {
						if (!PathIsDirectory(_T("config\\imgGame12"))) {
							game2->log(_T("未检测到固定队友图片目录，请先使用右侧功能-->截图固定队友！\r\n"));
							game2->log(_T("线程已停止！\r\n"));
							//解绑
							if (sn->IsBind(handle))
							{
								sn->UnBindWindow();
							}
							//释放资源
							if (sn != NULL)
							{
								delete sn;
								sn = NULL;
							}
							game2->setThreadStopState(true);
							game2->setThreadStartState(false);
							
							return EXIT_THREAD;
						}
					}
				}
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_yhg.GetCurSel();
					int team = game2->changeEquip.m_yht.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, group, team, sn, game2);
				}
				if (mode == (int)IDC_RADIO_YH_ASK)
				{
					threadRes = yuhun.inviteYuhun(handle, round, layer, jc_str, mateType, triple, sn, game2);
				}
				else if (mode == (int)IDC_RADIO_YH_BEASKED)
				{
					threadRes = yuhun.BeinvitedYuhun(handle, round, jc_str, sn, game2);
				}
				else if (mode == (int)IDC_RADIO_YH_SINGLE)
				{
					threadRes = yuhun.SingleYuHun(handle, round, layer, jc_str, sn, game2);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止！\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("觉醒")) {
				BeginJueXing juexing;
				CString round_str = strResult[i].GetAt(1);
				CString mode_str = strResult[i].GetAt(2);
				CString layer_str = strResult[i].GetAt(3);
				CString jc_str = strResult[i].GetAt(4);
				CString monster_mode_str = strResult[i].GetAt(5);
				CString mateType_str = strResult[i].GetAt(6);
				CString triple_str = strResult[i].GetAt(7);
				int round = StrToInt(round_str);
				int mode = StrToInt(mode_str);
				int layer = StrToInt(layer_str);
				int monster_mode = StrToInt(monster_mode_str);
				int mateType = StrToInt(mateType_str);
				int triple = StrToInt(triple_str);
				//控制线程结束标志
				int threadRes;
				if (monster_mode == (int)IDC_RADIO_JX_ASK) {
					//判断是否存在image_dir
					if ((mateType == 2) || (mateType == 3)) {
						if (!PathIsDirectory(_T("config\\imgGame12"))) {
							game2->log(_T("未检测到固定队友图片目录，请先使用右侧功能-->截图固定队友！\r\n"));
							game2->log(_T("线程已停止！\r\n"));
							//解绑
							if (sn->IsBind(handle))
							{
								sn->UnBindWindow();
							}
							//释放资源
							if (sn != NULL)
							{
								delete sn;
								sn = NULL;
							}
							game2->setThreadStopState(true);
							game2->setThreadStartState(false);
							
							return EXIT_THREAD;
						}
					}
				}
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_jxg.GetCurSel();
					int team = game2->changeEquip.m_jxt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, group, team, sn, game2);
				}
				if (monster_mode == (int)IDC_RADIO_JX_ASK)
				{
					threadRes = juexing.inviteJueXing(handle, round, mode, layer, jc_str, mateType, triple, sn, game2);
				}
				else if (monster_mode == (int)IDC_RADIO_JX_BEASKED)
				{
					threadRes = juexing.BeinvitedJueXing(handle, round, jc_str, sn, game2);
				}
				else if (monster_mode == (int)IDC_RADIO_JX_SINGLE)
				{
					threadRes = juexing.SingleJueXing(handle, round, mode, layer, jc_str, sn, game2);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("日轮之陨")) {
				BeginRiLunZhiYun rilunzhiyun;
				CString round_str = strResult[i].GetAt(1);
				CString layer_str = strResult[i].GetAt(2);
				CString jc_str = strResult[i].GetAt(3);
				CString mode_str = strResult[i].GetAt(4);
				CString mateType_str = strResult[i].GetAt(5);
				CString triple_str = strResult[i].GetAt(6);
				int round = StrToInt(round_str);
				int layer = StrToInt(layer_str);
				int mode = StrToInt(mode_str);
				int mateType = StrToInt(mateType_str);
				int triple = StrToInt(triple_str);
				//控制线程结束标志
				int threadRes;
				if (mode == (int)IDC_RADIO_RLZY_ASK) {
					//判断是否存在image_dir
					if ((mateType == 2) || (mateType == 3)) {
						if (!PathIsDirectory(_T("config\\imgGame12"))) {
							game2->log(_T("未检测到固定队友图片目录，请先使用右侧功能-->截图固定队友！\r\n"));
							game2->log(_T("线程已停止！\r\n"));
							//解绑
							if (sn->IsBind(handle))
							{
								sn->UnBindWindow();
							}
							//释放资源
							if (sn != NULL)
							{
								delete sn;
								sn = NULL;
							}
							game2->setThreadStopState(true);
							game2->setThreadStartState(false);
							
							return EXIT_THREAD;
						}
					}
				}
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_rlzyg.GetCurSel();
					int team = game2->changeEquip.m_rlzyt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, group, team, sn, game2);
				}
				if (mode == (int)IDC_RADIO_RLZY_ASK)
				{
					threadRes = rilunzhiyun.inviteRiLunZhiYun(handle, round, layer, jc_str, mateType, triple, sn, game2);
				}
				else if (mode == (int)IDC_RADIO_RLZY_BEASKED)
				{
					threadRes = rilunzhiyun.BeinvitedRiLunZhiYun(handle, round, jc_str, sn, game2);
				}
				else if (mode == (int)IDC_RADIO_RLZY_SINGLE)
				{
					threadRes = rilunzhiyun.SingleRiLunZhiYun(handle, round, layer, jc_str, sn, game2);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("永生之海")) {
				BeginYongShengZhiHai yongshengzhihai;
				CString round_str = strResult[i].GetAt(1);
				CString layer_str = strResult[i].GetAt(2);
				CString jc_str = strResult[i].GetAt(3);
				CString mode_str = strResult[i].GetAt(4);
				CString mateType_str = strResult[i].GetAt(5);
				int round = StrToInt(round_str);
				int layer = StrToInt(layer_str);
				int mode = StrToInt(mode_str);
				int mateType = StrToInt(mateType_str);
				//控制线程结束标志
				int threadRes;
				if (mode == (int)IDC_RADIO_YSZH_ASK) {
					//判断是否存在image_dir
					if ((mateType == 2) || (mateType == 3)) {
						if (!PathIsDirectory(_T("config\\imgGame12"))) {
							game2->log(_T("未检测到固定队友图片目录，请先使用右侧功能-->截图固定队友！\r\n"));
							game2->log(_T("线程已停止！\r\n"));
							//解绑
							if (sn->IsBind(handle))
							{
								sn->UnBindWindow();
							}
							//释放资源
							if (sn != NULL)
							{
								delete sn;
								sn = NULL;
							}
							game2->setThreadStopState(true);
							game2->setThreadStartState(false);
							
							return EXIT_THREAD;
						}
					}
				}
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_yszhg.GetCurSel();
					int team1 = game2->changeEquip.m_yszht1.GetCurSel();
					int team2 = game2->changeEquip.m_yszht2.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHunDouble(handle, group, team1, team2, sn, game2);
				}
				if (mode == (int)IDC_RADIO_YSZH_ASK)
				{
					threadRes = yongshengzhihai.inviteYongShengZhiHai(handle, round, layer, jc_str, mateType, sn, game2);
				}
				else if (mode == (int)IDC_RADIO_YSZH_BEASKED)
				{
					threadRes = yongshengzhihai.BeinvitedYongShengZhiHai(handle, round, jc_str, sn, game2);
				}
				else if (mode == (int)IDC_RADIO_YSZH_SINGLE)
				{
					threadRes = yongshengzhihai.SingleYongShengZhiHai(handle, round, layer, jc_str, sn, game2);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("日常")) {
			BeginDailyTask dailyTask;
				CString round_str = strResult[i].GetAt(1);
				CString monster_kind_str = strResult[i].GetAt(2);
				CString subsel_str = strResult[i].GetAt(3);
				CString condition_str = strResult[i].GetAt(4);
				int round = StrToInt(round_str);
				int monster_kind = StrToInt(monster_kind_str);
				int subsel = StrToInt(subsel_str);
				int condition = StrToInt(condition_str);
				//控制线程结束标志
				int threadRes;
				//是否预设御魂
				if ((monster_kind == 0) && (game2->changeEquip.m_ispreset.GetCheck() == 1)) {
					int group = game2->changeEquip.m_yqfyg.GetCurSel();
					int team = game2->changeEquip.m_yqfyt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, group, team, sn, game2);
				}
				threadRes = dailyTask.StartAllDaily(handle, condition, round, monster_kind, subsel, sn, game2);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("业原火")) {
				BeginYeYuanHuo yeyuanhuo;
				CString round_str = strResult[i].GetAt(1);
				CString monster_kind_str = strResult[i].GetAt(2);
				int round = StrToInt(round_str);
				int monster_kind = StrToInt(monster_kind_str);
				//控制线程结束标志
				int threadRes;
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_yyhg.GetCurSel();
					int team = game2->changeEquip.m_yyht.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, group, team, sn, game2);
				}
				threadRes = yeyuanhuo.StartYeYuanHuo(handle, round, monster_kind, sn, game2);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("结界突破")) {
				BeginTuPo tupo;
				CString round_str = strResult[i].GetAt(1);
				CString tpmode_str = strResult[i].GetAt(2);
				CString mode_str = strResult[i].GetAt(3);
				CString wait_str = strResult[i].GetAt(4);
				int round = StrToInt(round_str);
				int tpmode = StrToInt(tpmode_str);
				int mode = StrToInt(mode_str);
				int wait = StrToInt(wait_str);
				//控制线程结束标志
				int threadRes;
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_jjtpg.GetCurSel();
					int team = game2->changeEquip.m_jjtpt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle, group, team, sn, game2);
				}
				if (tpmode == 0) {
					if (mode == 0) {
						threadRes = tupo.StartTuPo(handle, round, sn, game2);
					}
					else if (mode == 1) {
						threadRes = tupo.StartTuPoByExitFourAttackNine(handle, round, sn, game2);
					}
				}
				else if (tpmode == 1) {
					threadRes = tupo.TeamBreak(handle, wait, sn, game2);
				}
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("御灵")) {
				BeginYuLing yuling;
				CString round_str = strResult[i].GetAt(1);
				CString monster_kind_str = strResult[i].GetAt(2);
				CString layer_str = strResult[i].GetAt(3);
				int round = StrToInt(round_str);
				int monster_kind = StrToInt(monster_kind_str);
				int layer = StrToInt(layer_str);
				//控制线程结束标志
				int threadRes;
				//是否预设御魂
				if (game2->changeEquip.m_ispreset.GetCheck() == 1) {
					int group = game2->changeEquip.m_ylg.GetCurSel();
					int team = game2->changeEquip.m_ylt.GetCurSel();
					BeginChangeYuHun changeYuHun;
					changeYuHun.StartChangeYuHun(handle,group, team,  sn, game2);
				}
				threadRes = yuling.StartYuLing(handle, round, monster_kind, layer, sn, game2);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("休息")) {
				BeginRest rest;
				CString minite_str = strResult[i].GetAt(1);
				//定时功能
				int adoptkind = game2->timer.m_kind.GetCurSel();
				int adoptstar = game2->timer.m_star.GetCurSel();
				int adoptarea = game2->timer.m_area.GetCurSel();
				int minite = StrToInt(minite_str);
				//控制线程结束标志
				int threadRes;
				threadRes = rest.StartRest(handle, minite, adopt, adoptkind, adoptstar, adoptarea, sn, game2);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("新活动")) {
				InDependentFunction dependFunc;
				CString round_str = strResult[i].GetAt(1);
				int round = StrToInt(round_str);
				CString mode_str = strResult[i].GetAt(2);
				int mode = StrToInt(mode_str);
				CString flag_str = strResult[i].GetAt(3);
				int flag = StrToInt(flag_str);
				CString bossflag_str = strResult[i].GetAt(4);
				int bossflag = StrToInt(bossflag_str);
				//控制线程结束标志
				int threadRes;
				threadRes = dependFunc.StartNewEvent(round, mode, flag, bossflag, sn, game2);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
			else if (strResult[i].GetAt(0) == _T("超鬼王")) {
				InDependentFunction superghostking;
				CString group_str[8], team_str[8], blood_str[4];
				CString round_str = strResult[i].GetAt(1);//次数
				CString flag_own_str = strResult[i].GetAt(2);//标记式神
				CString flag_boss_str = strResult[i].GetAt(3);//标记boss
				//1-3
				blood_str[0] = strResult[i].GetAt(4);
				group_str[0] = strResult[i].GetAt(5);
				team_str[0] = strResult[i].GetAt(6);
				group_str[1] = strResult[i].GetAt(7);
				team_str[1] = strResult[i].GetAt(8);
				//4
				blood_str[1] = strResult[i].GetAt(9);
				group_str[2] = strResult[i].GetAt(10);
				team_str[2] = strResult[i].GetAt(11);
				group_str[3] = strResult[i].GetAt(12);
				team_str[3] = strResult[i].GetAt(13);
				//5
				blood_str[2] = strResult[i].GetAt(14);
				group_str[4] = strResult[i].GetAt(15);
				team_str[4] = strResult[i].GetAt(16);
				group_str[5] = strResult[i].GetAt(17);
				team_str[5] = strResult[i].GetAt(18);
				//6
				blood_str[3] = strResult[i].GetAt(19);
				group_str[6] = strResult[i].GetAt(20);
				team_str[6] = strResult[i].GetAt(21);
				group_str[7] = strResult[i].GetAt(22);
				team_str[7] = strResult[i].GetAt(23);
				//强力攻击
				CString strenghCheck_str = strResult[i].GetAt(24);
				CString star_stop_str = strResult[i].GetAt(25);//停止并播报
				CString star_public_str = strResult[i].GetAt(26);//是否公开
				//转换为int
				int round = StrToInt(round_str);
				int flag_own = StrToInt(flag_own_str);
				int flag_boss = StrToInt(flag_boss_str);
				int strenghCheck = StrToInt(strenghCheck_str);
				int star_stop = StrToInt(star_stop_str);
				int star_public = StrToInt(star_public_str);
				int i, group[8], team[8], blood[4];
				for (i = 0; i < 8; i++) {
					if (i < 4) {
						blood[i] = StrToInt(blood_str[i]);
					}
					group[i] = StrToInt(group_str[i]);
					team[i] = StrToInt(team_str[i]);
				}
				//开始超鬼王
				int threadRes;
				threadRes = superghostking.StartSuperGhostKing(round, strenghCheck, group, team, blood, flag_own, flag_boss, star_stop, star_public, sn, game2);
				//中途结束线程
				if (threadRes == EXIT_THREAD)
				{
					game2->log(_T("线程已停止!\r\n"));
					//解绑
					if (sn->IsBind(handle))
					{
						sn->UnBindWindow();
					}
					//释放资源
					if (sn != NULL)
					{
						delete sn;
						sn = NULL;
					}
					game2->setThreadStopState(true);
					game2->setThreadStartState(false);
					
					return EXIT_THREAD;
				}
			}
		}
	}
	//解绑
	if (sn->IsBind(handle))
	{
		sn->UnBindWindow();
	}
	//释放资源
	if (sn != NULL)
	{
		delete sn;
		sn = NULL;
	}

	game2->log(_T("助手执行完毕!\r\n"));
	//微信推送
	int pushstate = game2->pushplus.m_push.GetCheck();
	CString token;
	game2->pushplus.GetDlgItemText(IDC_EDIT_TOKEN, token);
	yys_function yys;
	yys.PushPlus(token, pushstate, _T("Game2"), game2);
	game2->setThreadStopState(true);
	game2->setThreadStartState(false);
	
	return 1;
}
UINT CGame2::ThreadProcSaveFile(LPVOID lpParameter) {
	CGame2 *game2 = (CGame2*)lpParameter;
	SavePreSet preset;
	preset.SaveToFile(game2, game2->getFileName());
	return 0;
}
void CGame2::OnBnClickedBtnStart2()
{
	//显示日志
	m_tab_right.SetCurSel(3);
	runlog.m_runLog.SetWindowTextW(_T(""));
	//获取时间
	SYSTEMTIME p;
	GetLocalTime(&p);
	int hour = p.wHour;
	if (hour >= 0 && hour < 6) {
		CString TimeFormat;
		TimeFormat.Format(_T("现在是北京时间[%02d:%02d:%02d]"), p.wHour, p.wMinute, p.wSecond);
		MessageBox(TimeFormat + _T("，此时间段使用脚本极易收信，不建议[0点-6点]期间使用脚本，若执意挂机，点击确定忽略此提醒并继续执行脚本。"), _T("来自鬼使黑的信"));
	}
	else if (hour == 23) {
		CString TimeFormat;
		TimeFormat.Format(_T("现在是北京时间[%02d:%02d:%02d]"), p.wHour, p.wMinute, p.wSecond);
		MessageBox(TimeFormat + _T("，此时间段挂机建议不要超过0点，[0点-6点]期间使用脚本,收信几率极大，若执意挂机，点击确定忽略此提醒并继续执行脚本。"), _T("来自鬼使黑的信"));
	}
	//开启一个线程
	if (!getThreadStartState()) {
		initThread();
		AfxBeginThread(ThreadProc, this);
		AfxBeginThread(ThreadProcSaveFile, this);
	}
	else {
		MessageBox(_T("请勿重复启动！"));
	}
}
void CGame2::OnBnClickedBtnSuspend2()
{
	setThreadPauseState(!getThreadPauseState());
	if (getThreadPauseState())
	{
		if (!getThreadStartState()) {
			log(_T("线程状态为停止，无需挂起！\r\n"));
			return;
		}
		log(_T("正在挂起线程...\r\n"));
		setThreadPauseState(true);
	}
	else {
		if (!getThreadStartState()) {
			log(_T("线程状态为停止，无需恢复！\r\n"));
			return;
		}
		log(_T("正在恢复线程...\r\n"));
		setThreadPauseState(false);
	}
}
void CGame2::OnBnClickedBtnStop2()
{
	if (getThreadStopState()) {
		log(_T("线程未开启，无需停止！\r\n"));
		return;
	}
	log(_T("正在停止线程...\r\n"));
	setThreadStopState(true);
	reSetWaitFlag(waitFlag1, waitFlag2);
	reSetWaitFlag(exbonus1, exbonus2);
	reSetWaitFlag(exteamer1, exteamer2);
}
//导入
void CGame2::OnBnClickedBtnImport()
{
	//单选；
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt||"));
	if (fileDlg.DoModal() == IDOK) {
		CString filePath = fileDlg.GetPathName();
		yys_function yysFunc;
		CStringArray taskList;
		int listSize = yysFunc.ReadFile(filePath, 0, taskList);
		for (int i = 0; i < listSize; i++) {
			m_list_taskshow.InsertItem(m_list_taskshow.GetItemCount(), taskList.GetAt(i));
		}
	}
}
//导出
void CGame2::OnBnClickedBtnExport()
{
	//单选；
	CFileDialog fileDlg(FALSE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("文本文档(*.txt)|*.txt||"));
	if (fileDlg.DoModal() == IDOK) {
		CStringArray taskList;
		CString filePath = fileDlg.GetPathName();
		int listSize = m_list_taskshow.GetItemCount();
		for (int i = 0; i < listSize; i++) {
			taskList.Add(m_list_taskshow.GetItemText(i, 0));
		}
		yys_function yysFunc;
		int writeRes = yysFunc.WriteFile(filePath, 0, taskList);
		if (writeRes == NULL_LIST) {
			MessageBox(_T("任务列表为空！！！"));
		}
		else if (writeRes == ERR_CODE) {
			MessageBox(_T("未知异常，写入失败，请重试！！！"));
		}
	}
}
HBRUSH CGame2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (IDC_HANDLE_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS3 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS4 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}

void CGame2::OnBnClickedBtnUpdate()
{
	MessageBox(_T("蓝奏云密码: 1234"),_T("密码是1234"));
	CString codePath = _T("https://ricarda.lanzoul.com/b01vrrs1g");
	ShellExecute(NULL, _T("open"), codePath, NULL, NULL, SW_SHOW);
}
void CGame2::log(CString logMsg) {
	runlog.m_runLog.SetSel(0, 0, FALSE);
	runlog.m_runLog.ReplaceSel(GetTime() + logMsg, FALSE);
}
void CGame2::setThreadPauseState(bool state) {
	pause = state;
}
bool CGame2::getThreadPauseState() {
	return pause;
}
void CGame2::setThreadStartState(bool state) {
	start = state;
}
bool CGame2::getThreadStartState() {
	return start;
}
void CGame2::setThreadStopState(bool state) {
	stop = state;
}
bool CGame2::getThreadStopState() {
	return stop;
}
void CGame2::initThread() {
	pause = false;
	start = true;
	stop = false;
}

void CGame2::synchronization(bool &waitFlag1, bool &waitFlag2) {
	int relation = global.m_relation.GetCheck();
	if (relation) {
		//通知事件1
		waitFlag1 = false;
		//等待事件2
		while (waitFlag2) {
			if (getThreadPauseState() || getThreadStopState()) {
				break;
			}
			Sleep(2000);
		}
	}
}
//获取当前时间
CString CGame2::GetTime() {
	//windows API获取时间
	SYSTEMTIME p;
	GetLocalTime(&p);
	CString timeDate;
	timeDate.Format(_T("[%02d:%02d:%02d] "), p.wHour, p.wMinute, p.wSecond);
	return timeDate;
}
//重置同步状态
void CGame2::reSetWaitFlag(bool &flag1, bool &flag2) {
	int relation = global.m_relation.GetCheck();
	if (relation) {
		flag2 = true;
	}
}
std::string CGame2::getFileName() {
	fileName = fname2;
	return fileName;
}
//保存预设
int CGame2::SaveToFile(std::string savePath) {
	std::vector<std::vector<std::any>> mixedall;

	//御魂
	yuhun.m_yuhun_round.GetWindowTextW(countTemp);//次数
	layer = yuhun.m_yuhun_layer.GetCurSel();//层数
	bonus = yuhun.m_yuhun_auto_bonus.GetCurSel();//加成
	friendArea = yuhun.m_yuhun_prefer_friend.GetCurSel();//同跨区好友
	selIndex = yuhun.GetCheckedRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK);//选中的索引
	winReceive = yuhun.m_yuhun_win.GetCheck();//胜利自动接受邀请
	std::vector<std::any> mixedHun = { "御魂", StrToInt(countTemp), layer, bonus, friendArea, selIndex, winReceive };
	mixedall.push_back(mixedHun);

	//觉醒
	juexing.m_jueXing_round.GetWindowTextW(countTemp);//次数
	kind = juexing.m_jueXing_mode.GetCurSel();//麒麟种类
	layer = juexing.m_jueXing_layer.GetCurSel();//层数
	bonus = juexing.m_jueXing_auto_bonus.GetCurSel();//加成
	friendArea = juexing.m_jueXing_prefer_friend.GetCurSel();//同跨区好友
	selIndex = juexing.GetCheckedRadioButton(IDC_RADIO_JX_SINGLE, IDC_RADIO_JX_ASK);//选中的索引
	winReceive = juexing.m_jueXing_win.GetCheck();//胜利自动接受邀请
	std::vector<std::any> mixedXing = { "觉醒", StrToInt(countTemp), kind, layer, bonus, friendArea, selIndex, winReceive };
	mixedall.push_back(mixedXing);

	//日轮之陨
	riLunZhiYun.m_rlzy_round.GetWindowTextW(countTemp);//次数
	layer = riLunZhiYun.m_rlzy_layer.GetCurSel();//层数
	bonus = riLunZhiYun.m_rlzy_auto_bonus.GetCurSel();//加成
	friendArea = riLunZhiYun.m_rlzy_prefer_friend.GetCurSel();//同跨区好友
	selIndex = riLunZhiYun.GetCheckedRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_ASK);//选中的索引
	winReceive = riLunZhiYun.m_rlzy_win.GetCheck();//胜利自动接受邀请
	std::vector<std::any> mixedYun = { "日轮之陨", StrToInt(countTemp), layer, bonus, friendArea, selIndex, winReceive };
	mixedall.push_back(mixedYun);

	//永生之海
	yongShengZhiHai.m_yszh_round.GetWindowTextW(countTemp);//次数
	layer = yongShengZhiHai.m_yszh_layer.GetCurSel();//层数
	bonus = yongShengZhiHai.m_yszh_auto_bonus.GetCurSel();//加成
	friendArea = yongShengZhiHai.m_yszh_prefer_friend.GetCurSel();//同跨区好友
	selIndex = yongShengZhiHai.GetCheckedRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_ASK);//选中的索引
	std::vector<std::any> mixedHai = { "永生之海", StrToInt(countTemp), layer, bonus, friendArea, selIndex };
	mixedall.push_back(mixedHai);

	//探索
	tanSuo.m_tansuo_round.GetWindowTextW(countTemp);//次数
	mode = tanSuo.m_tansuo_mode.GetCurSel();//组队模式(队长/队员/单刷)
	layer = tanSuo.m_tansuo_layer.GetCurSel();//层数
	diff = tanSuo.m_tansuo_diff.GetCurSel();//难度
	kind = tanSuo.m_tansuo_monster.GetCurSel();//怪物类型(经验/金币/物品)
	bonus = tanSuo.m_tansuo_auto_bonus.GetCurSel();//加成
	automaterial = tanSuo.m_material.GetCheck();//自动狗粮
	speed = tanSuo.m_speed.GetCheck();//快速模式
	friendArea = tanSuo.m_tansuo_prefer_friend.GetCurSel();//同跨区好友
	material = tanSuo.m_materialkinds.GetCurSel();//狗粮类型(N/素材)
	bar = tanSuo.m_progressbar.GetCurSel();//狗粮进度条范围
	reward = tanSuo.m_reward.GetCheck();//拾取宝箱
	aiexplore = tanSuo.m_aiexplore.GetCheck();//智能探索
	std::vector<std::any> mixedExplore = { "探索", StrToInt(countTemp), mode, layer, diff, kind, bonus, automaterial, speed, friendArea, material, bar, reward, aiexplore };
	mixedall.push_back(mixedExplore);
	//日常
	dailyTask.m_yqfy_round.GetWindowTextW(countTemp);//次数
	kind = dailyTask.m_yqfy_kinds.GetCurSel();//妖气封印种类
	std::vector<std::any> mixedDaily = { "日常", StrToInt(countTemp), kind };
	mixedall.push_back(mixedDaily);
	//业原火
	yeYuanHuo.m_yeYuanHuo_round.GetWindowTextW(countTemp);//次数
	kind = yeYuanHuo.m_yeYuanHuo_layer.GetCurSel();//业原火种类
	std::vector<std::any> mixedFire = { "业原火", StrToInt(countTemp), kind };
	mixedall.push_back(mixedFire);
	//御灵
	yuLing.m_yuLing_round.GetWindowTextW(countTemp);//次数
	kind = yuLing.m_yuLing_mode.GetCurSel();//御灵种类
	layer = yuLing.m_yuLing_layer.GetCurSel();//层数
	std::vector<std::any> mixedLing = { "御灵", StrToInt(countTemp), kind, layer };
	mixedall.push_back(mixedLing);
	//个人突破
	geRenTuPo.m_grtp_round.GetWindowTextW(countTemp);//次数
	tpmode = geRenTuPo.m_lt_or_gt.GetCurSel();//寮突/个突
	mode = geRenTuPo.m_mode.GetCurSel();//突破模式
	kind = geRenTuPo.m_wait.GetCurSel();//冷却
	std::vector<std::any> mixedTP = { "个人突破", StrToInt(countTemp), tpmode, mode, kind };
	mixedall.push_back(mixedTP);
	//休息
	rest.m_rest_time.GetWindowTextW(countTemp);//休息时间
	std::vector<std::any> mixedRest = { "休息", StrToInt(countTemp) };
	mixedall.push_back(mixedRest);
	//御魂预设
	yhg = changeEquip.m_yhg.GetCurSel();
	jxg = changeEquip.m_jxg.GetCurSel();
	tsg = changeEquip.m_tsg.GetCurSel();
	rlzyg = changeEquip.m_rlzyg.GetCurSel();
	yszhg = changeEquip.m_yszhg.GetCurSel();
	ylg = changeEquip.m_ylg.GetCurSel();
	yyhg = changeEquip.m_yyhg.GetCurSel();
	jjtpg = changeEquip.m_jjtpg.GetCurSel();
	yqfyg = changeEquip.m_yqfyg.GetCurSel();
	std::vector<std::any> mixedPregp = { "御魂组预设", yhg, jxg, tsg, rlzyg, yszhg, ylg, yyhg, jjtpg, yqfyg };
	mixedall.push_back(mixedPregp);

	yht = changeEquip.m_yht.GetCurSel();
	jxt = changeEquip.m_jxt.GetCurSel();
	tst = changeEquip.m_tst.GetCurSel();
	rlzyt = changeEquip.m_rlzyt.GetCurSel();
	yszht1 = changeEquip.m_yszht1.GetCurSel();
	yszht2 = changeEquip.m_yszht2.GetCurSel();
	ylt = changeEquip.m_ylt.GetCurSel();
	yyht = changeEquip.m_yyht.GetCurSel();
	jjtpt = changeEquip.m_jjtpt.GetCurSel();
	yqfyt = changeEquip.m_yqfyt.GetCurSel();
	std::vector<std::any> mixedPretm = { "御魂队预设", yht, jxt, tst, rlzyt, yszht1, yszht2,  ylt, yyht, jjtpt, yqfyt };
	mixedall.push_back(mixedPretm);
	//模拟器类型
	machine_select = m_windowType.GetCurSel();
	std::vector<std::any> mixedEngintype = { "模拟器类型", machine_select };
	mixedall.push_back(mixedEngintype);
	//全局功能
	global_relation = global.m_relation.GetCheck();
	global_reject = global.m_reject.GetCheck();
	std::vector<std::any> mixedGlob = { "全局功能", global_relation, global_reject };
	mixedall.push_back(mixedGlob);
	snow *sn = new snow;
	sn->WriteJson(mixedall, savePath);
	if (sn != nullptr) {
		delete sn;
		sn = nullptr;
	}
	return 1;
}