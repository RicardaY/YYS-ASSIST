// YYS_AssistDlg.cpp: 实现文件
//
#include "pch.h"
#include "framework.h"
#include "YYS_Assist.h"
#include "YYS_AssistDlg.h"
#include "yys_function.h"
#include "afxdialogex.h"
#include "snow.h"

//最小化托盘
#define WM_SHOWTASK (WM_USER +1)
#define IDR_SHOW 11
#define IDR_OTHER 12
#define IDR_EXIT 13
#define CountArray(Array) (sizeof(Array)/sizeof(Array[0]))

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// 全局的dm对象
snow * g_sn = NULL;


int CYYSAssistDlg::RegisterDmNew() {
	// 初始化COM模型为mta
	CoInitializeEx(NULL, 0);
	TCHAR szDirectory[MAX_PATH] = TEXT("");
	GetWorkDirectory(szDirectory, CountArray(szDirectory));
	m_strWorkPath = szDirectory;
	m_hDMRegInstance = LoadLibrary(m_strWorkPath + _T("\\DmReg.dll"));
	if (m_hDMRegInstance == nullptr) {
		MessageBox(_T("无法加载DmReg.dll"),_T("注册组件加载失败"));
		return FALSE;
	}
	TypeSetDllPathW pfnSetDllPathW = (TypeSetDllPathW)GetProcAddress(m_hDMRegInstance, "SetDllPathW");
	if (pfnSetDllPathW == nullptr) {
		MessageBox(_T("无法获取SetDllPathW函数地址"), _T("函数地址获取失败"));
		return FALSE;
	}
	CString strDmPath = m_strWorkPath + _T("\\dm.dll");
	long iRet = pfnSetDllPathW((WCHAR*)strDmPath.GetString(), 0);

	g_sn = new snow;
	if (g_sn == NULL)
	{
		return -500;
	}
	// 收费注册
	long sn_ret = g_sn->Reg(_T(""), _T("")); //此处分别填写注册码和附加码
	if (sn_ret != 1)
	{
		delete g_sn;
		return sn_ret;
	}
	return sn_ret;
}
// CYYSAssistDlg 对话框
CYYSAssistDlg::CYYSAssistDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YYS_MAIN_DLG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_LOGO);
}
void CYYSAssistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MIAN, m_tab_main);
}
BEGIN_MESSAGE_MAP(CYYSAssistDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_MESSAGE(WM_SHOWTASK, OnShowTask)//消息映射
END_MESSAGE_MAP()
// CYYSAssistDlg 消息处理程序
BOOL CYYSAssistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// TODO: 在此添加额外的初始化代码
	m_tab_main.AddPage(_T("游戏一"),&game1,IDD_DIALOG_GAME);
	m_tab_main.AddPage(_T("游戏二"), &game2, IDD_DIALOG_GAME);
	m_tab_main.Show();

	//注册大漠
	int snRes = RegisterDmNew();
	CString strRes;
	strRes.Format(_T("%d"), snRes);
	if (snRes != 1) {
		if (snRes == -1) {
			MessageBox(_T("请检查网络连接！！！,错误码：" + strRes));
			return TRUE;
		}
		else if (snRes == -2) {
			MessageBox(_T("请检查是否以管理员身份运行！！！,错误码：" + strRes));
			return TRUE;
		}
		else if (snRes == 0) {
			MessageBox(_T("请检查防火墙设置！！！,错误码=" + strRes + "，点击确定查看解决方案引导"));
			MessageBox(_T("点击确定跳转至浏览器打开解决方案"));
			CString codePath = _T("https://jingyan.baidu.com/article/9faa7231e4a08c473c28cba5.html");
			ShellExecute(NULL, _T("open"), codePath, NULL, NULL, SW_SHOW);
			MessageBox(_T("照着前面设置完成之后，重新启动脚本。"));
			return TRUE;
		}
		else if (snRes == -500) {
			MessageBox(_T("创建对象失败，未知错误。错误码：" + strRes));
			return TRUE;
		}
	}
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
void CYYSAssistDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
	if (nID == SC_MINIMIZE) {
		toTray();
	}
}
// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CYYSAssistDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CYYSAssistDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
bool CYYSAssistDlg::GetWorkDirectory(TCHAR szWorkDirectory[], WORD wBufferCount) {
	//模块路径
	TCHAR szModulePath[MAX_PATH] = TEXT("");
	GetModuleFileName(AfxGetInstanceHandle(), szModulePath, CountArray(szModulePath));
	//分析文件
	for (INT i = lstrlen(szModulePath); i >= 0; i--) {
		if (szModulePath[i] == TEXT('\\') ){
			szModulePath[i] = 0;
				break;
		}
	}
	//设置结果
	ASSERT(szModulePath[0] != 0);
	lstrcpyn(szWorkDirectory, szModulePath, wBufferCount);
	return true;
}
void CYYSAssistDlg::toTray()//最小化到托盘
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDI_ICON_LOGO;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_LOGO));
	wcscpy_s(nid.szTip, _T("YYS ASSIST"));//信息提示条为“OA”
	Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标
	ShowWindow(SW_HIDE);//隐藏主窗口
}
LRESULT CYYSAssistDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{//wParam接收的是图标的ID，而lParam接收的是鼠标的行为
	if (wParam != IDI_ICON_LOGO) return true;
	switch (lParam)
	{
	case WM_LBUTTONUP://左键单击显示主界面
	{
		this->ShowWindow(SW_SHOW);
		this->SetActiveWindow();
		typedef void (WINAPI *PSWITCHTOTHISWINDOW) (HWND, BOOL);
		PSWITCHTOTHISWINDOW SwitchToThisWindow;
		HMODULE hUser32 = GetModuleHandle(_T("user32"));
		SwitchToThisWindow = (PSWITCHTOTHISWINDOW)GetProcAddress(hUser32, "SwitchToThisWindow");
		SwitchToThisWindow(m_hWnd, TRUE);
		DeleteTray();
	}break;
	case WM_RBUTTONUP://右击弹出菜单
	{
		LPPOINT lpoint = new tagPOINT;
		::GetCursorPos(lpoint);//得到鼠标位置
		CMenu menu;
		menu.CreatePopupMenu();
		menu.AppendMenu(MFT_STRING, IDR_SHOW, _T("打开主界面"));
		menu.AppendMenu(MFT_STRING, IDR_OTHER, _T("其他"));
		menu.AppendMenu(MFT_STRING, IDR_EXIT, _T("退出"));
		SetForegroundWindow();
		EnableMenuItem(menu, IDR_OTHER, MF_GRAYED);//"其他"菜单变灰
		//menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x,lpoint->y,this);//显示菜单
		int xx = TrackPopupMenu(menu, TPM_RETURNCMD, lpoint->x, lpoint->y, NULL, this->m_hWnd, NULL);//显示菜单并获取选项ID
		if (xx == IDR_SHOW)
		{
			this->ShowWindow(SW_SHOW);
			this->SetActiveWindow();
			typedef void (WINAPI *PSWITCHTOTHISWINDOW) (HWND, BOOL);
			PSWITCHTOTHISWINDOW SwitchToThisWindow;
			HMODULE hUser32 = GetModuleHandle(_T("user32"));
			SwitchToThisWindow = (PSWITCHTOTHISWINDOW)GetProcAddress(hUser32, "SwitchToThisWindow");
			SwitchToThisWindow(m_hWnd, TRUE);
			DeleteTray();
		}
		else if (xx == IDR_EXIT) { 
			DeleteTray();
			AfxGetMainWnd()->SendMessage(WM_CLOSE);
		}
		HMENU hmenu = menu.Detach();
		menu.DestroyMenu();
		delete lpoint;
	}break;
	case WM_LBUTTONDBLCLK:
	{
		//双击不处理
	}break;
	}
	return true;
}
void CYYSAssistDlg::DeleteTray()//销毁托盘图标
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDI_ICON_LOGO;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK;
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON_LOGO));
	wcscpy_s(nid.szTip, _T("YYS ASSIST"));
	Shell_NotifyIcon(NIM_DELETE, &nid);
}
/***
 * ░░░░░░░░░░░░░░░░░░░░░░░░▄░░
 * ░░░░░░░░░▐█░░░░░░░░░░░▄▀▒▌░
 * ░░░░░░░░▐▀▒█░░░░░░░░▄▀▒▒▒▐
 * ░░░░░░░▐▄▀▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐
 * ░░░░░▄▄▀▒░▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐
 * ░░░▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌
 * ░░▐▒▒▒▄▄▒▒▒▒░░░▒▒▒▒▒▒▒▀▄▒▒
 * ░░▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐
 * ░▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄
 * ░▌░▒▄██▄▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒
 * ▀▒▀▐▄█▄█▌▄░▀▒▒░░░░░░░░░░▒▒▒
 * 单身狗就这样默默地看着你，一句话也不说。
 */
HBRUSH CYYSAssistDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (IDC_TIPS == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}
