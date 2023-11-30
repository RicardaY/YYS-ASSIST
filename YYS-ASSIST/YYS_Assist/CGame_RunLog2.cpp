// CGame_RunLog2.cpp: 实现文件
//
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_RunLog2.h"
#include "afxdialogex.h"
// CGame_RunLog2 对话框
IMPLEMENT_DYNAMIC(CGame_RunLog2, CDialog)
CGame_RunLog2::CGame_RunLog2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RunLog, pParent)
{
}
CGame_RunLog2::~CGame_RunLog2()
{
}
void CGame_RunLog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RUN_LOG, m_runLog);
}
BEGIN_MESSAGE_MAP(CGame_RunLog2, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
// CGame_RunLog2 消息处理程序
BOOL CGame_RunLog2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	m_runLog.SetLimitText(0);
	m_font.CreatePointFont(75, _T("微软雅黑"));
	m_runLog.SetFont(&m_font);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CGame_RunLog2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (IDC_RUN_LOG == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(32, 178, 170));//设置文本颜色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}
