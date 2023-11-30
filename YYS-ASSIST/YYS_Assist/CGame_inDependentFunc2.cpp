// CGame_inDependentFunc2.cpp: 实现文件
//
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_inDependentFunc2.h"
#include "afxdialogex.h"
// CGame_inDependentFunc2 对话框

IMPLEMENT_DYNAMIC(CGame_inDependentFunc2, CDialog)
CGame_inDependentFunc2::CGame_inDependentFunc2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_INDEPENDENT, pParent)
{
}
CGame_inDependentFunc2::~CGame_inDependentFunc2()
{
}
void CGame_inDependentFunc2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BAIGUI, m_baigui);
	DDX_Control(pDX, IDC_REGION, m_king);
	DDX_Control(pDX, IDC_COMBO_RGMOUNT, m_amount);
	DDX_Control(pDX, IDC_PLOT, m_plot);
	DDX_Control(pDX, IDC_PVP, m_pvp);
	DDX_Control(pDX, IDC_COMBO_PVPTYPE, m_pvptype);
	DDX_Control(pDX, IDC_READY, m_ready);
	DDX_Control(pDX, IDC_CLEAN, m_clearing);
	DDX_Control(pDX, IDC_GETCARD, m_whitecard);
	DDX_Control(pDX, IDC_CHALLENGE, m_challenge);
	DDX_Control(pDX, IDC_SMALLPVE, m_small);
	DDX_Control(pDX, IDC_LQ, m_lingran);
}
BEGIN_MESSAGE_MAP(CGame_inDependentFunc2, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
// CGame_inDependentFunc2 消息处理程序
HBRUSH CGame_inDependentFunc2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (IDC_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}
BOOL CGame_inDependentFunc2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	m_amount.SetCurSel(0);
	m_pvptype.SetCurSel(0);
	//radio default select
	CheckRadioButton(IDC_RADIO_HOT, IDC_RADIO_COLLECT, IDC_RADIO_HOT);
	//the door of six path
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
