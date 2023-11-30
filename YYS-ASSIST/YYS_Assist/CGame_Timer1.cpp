// CGame_Timer1.cpp: 实现文件
//
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_Timer1.h"
#include "afxdialogex.h"
// CGame_Timer1 对话框

IMPLEMENT_DYNAMIC(CGame_Timer1, CDialog)
CGame_Timer1::CGame_Timer1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TIMER, pParent)
{

}
CGame_Timer1::~CGame_Timer1()
{
}
void CGame_Timer1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADOPT, m_adopt);
	DDX_Control(pDX, IDC_COMBO_ADOPTKIND, m_kind);
	DDX_Control(pDX, IDC_COMBO_ADOPTSTAR, m_star);
	DDX_Control(pDX, IDC_COMBO_AREA, m_area);
	DDX_Control(pDX, IDC_ADOPT2, m_tmstart);
	DDX_Control(pDX, IDC_GRTP_ROUND, m_timecon);
}
BEGIN_MESSAGE_MAP(CGame_Timer1, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
// CGame_Timer1 消息处理程序
BOOL CGame_Timer1::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	m_kind.SetCurSel(0);
	m_star.SetCurSel(0);
	m_area.SetCurSel(0);
	m_timecon.SetWindowTextW(_T("0"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CGame_Timer1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS3 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	return hbr;
}
