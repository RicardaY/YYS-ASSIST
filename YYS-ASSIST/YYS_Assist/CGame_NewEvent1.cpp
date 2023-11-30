// CGame_NewEvent1.cpp: 实现文件
//
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_NewEvent1.h"
#include "afxdialogex.h"
#include "CGame1.h"
#include "globalvar.h"

// CGame_NewEvent1 对话框
IMPLEMENT_DYNAMIC(CGame_NewEvent1, CDialog)
CGame_NewEvent1::CGame_NewEvent1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NEW_EVENT_DLG, pParent)
{
}
CGame_NewEvent1::~CGame_NewEvent1()
{
}
void CGame_NewEvent1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NE_ROUND, m_round);
	DDX_Control(pDX, IDC_FLAG, m_flag);
	DDX_Control(pDX, IDC_BOSSFLAG, m_bossflag);
	DDX_Control(pDX, IDC_COMBOTZ, m_mode);
	DDX_Control(pDX, IDC_TIPS1, m_lastname);
	DDX_Control(pDX, IDC_TIPS2, m_firstname);
	DDX_Control(pDX, IDC_TIPS3, m_content);
}
BEGIN_MESSAGE_MAP(CGame_NewEvent1, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADDTOLIST, &CGame_NewEvent1::OnBnClickedBtnAddtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
// CGame_NewEvent1 消息处理程序
BOOL CGame_NewEvent1::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	m_round.SetWindowTextW(_T("50"));
	m_mode.SetCurSel(0);
	m_lastname.SetWindowTextW(activityName + _T("活动"));
	m_firstname.SetWindowTextW(_T("次") + activitySubName);
	m_content.SetWindowTextW(_T("注：开始前需在") + activitySubName + _T("界面，保持阵容锁定。"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame1 *p;
void CGame_NewEvent1::OnBnClickedBtnAddtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_NE_ROUND, round_str);
	UpdateData(FALSE);
	//模式
	CString mode_str;
	int mode = m_mode.GetCurSel();
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode);
	//标记
	CString flag_str;
	int flag = m_flag.GetCheck();//标记式神
	UpdateData(FALSE);
	flag_str.Format(_T("-%d"), flag);
	//标记
	CString bossflag_str;
	int bossflag = m_bossflag.GetCheck();//标记boss
	UpdateData(FALSE);
	bossflag_str.Format(_T("-%d"), bossflag);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("新活动-" + round_str + mode_str + flag_str + bossflag_str));
}
HBRUSH CGame_NewEvent1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (IDC_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->SetBkMode(OPAQUE);
	}
	if (IDC_TIPS2 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->SetBkMode(OPAQUE);
	}
	if (IDC_TIPS3 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkMode(OPAQUE);
	}
	return hbr;
}
