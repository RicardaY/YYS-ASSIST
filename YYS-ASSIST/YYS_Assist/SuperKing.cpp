// SuperKing.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "SuperKing.h"
#include "afxdialogex.h"
#include "CGame1.h"


// SuperKing 对话框

IMPLEMENT_DYNAMIC(SuperKing, CDialog)

SuperKing::SuperKing(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SUPERKING, pParent)
{

}

SuperKing::~SuperKing()
{
}

void SuperKing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FL, flood1);
	DDX_Control(pDX, IDC_COMBO_FL2, flood2);
	DDX_Control(pDX, IDC_COMBO_FL3, flood3);
	DDX_Control(pDX, IDC_COMBO_FL4, flood4);
	DDX_Control(pDX, IDC_GROUP1, group1);
	DDX_Control(pDX, IDC_GROUP10, group2);
	DDX_Control(pDX, IDC_GROUP11, group3);
	DDX_Control(pDX, IDC_GROUP12, group4);
	DDX_Control(pDX, IDC_GROUP3, group5);
	DDX_Control(pDX, IDC_GROUP13, group6);
	DDX_Control(pDX, IDC_GROUP4, group7);
	DDX_Control(pDX, IDC_GROUP14, group8);
	DDX_Control(pDX, IDC_TEAM1, team1);
	DDX_Control(pDX, IDC_TEAM10, team2);
	DDX_Control(pDX, IDC_TEAM11, team3);
	DDX_Control(pDX, IDC_TEAM12, team4);
	DDX_Control(pDX, IDC_TEAM13, team5);
	DDX_Control(pDX, IDC_TEAM14, team6);
	DDX_Control(pDX, IDC_TEAM15, team7);
	DDX_Control(pDX, IDC_TEAM16, team8);
	DDX_Control(pDX, IDC_FLAG, m_flag);
	DDX_Control(pDX, IDC_BOSSFLAG, m_flag_boss);
	DDX_Control(pDX, IDC_FLAG2, m_strength);
	DDX_Control(pDX, IDC_ROUND, m_round);
	DDX_Control(pDX, IDC_STARAREA, m_star);
	DDX_Control(pDX, IDC_PUBLIC, m_public);
}


BEGIN_MESSAGE_MAP(SuperKing, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADDTOLIST, &SuperKing::OnBnClickedBtnAddtolist)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// SuperKing 消息处理程序


BOOL SuperKing::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_round.SetWindowTextW(_T("50"));
	flood1.SetCurSel(0);
	flood2.SetCurSel(0);
	flood3.SetCurSel(0);
	flood4.SetCurSel(0);
	group1.SetCurSel(0);
	group2.SetCurSel(0);
	group3.SetCurSel(0);
	group4.SetCurSel(0);
	group5.SetCurSel(0);
	group6.SetCurSel(0);
	group7.SetCurSel(0);
	group8.SetCurSel(0);
	team1.SetCurSel(0);
	team2.SetCurSel(0);
	team3.SetCurSel(0);
	team4.SetCurSel(0);
	team5.SetCurSel(0);
	team6.SetCurSel(0);
	team7.SetCurSel(0);
	team8.SetCurSel(0);
	m_star.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

extern CGame1 *p;
void SuperKing::OnBnClickedBtnAddtolist()
{
	//获取参数
	UpdateData(true);
	//打几只
	CString round_str;
	GetDlgItemText(IDC_ROUND, round_str);
	UpdateData(FALSE);
	//标记
	CString flag_str;
	int flag_int1 = m_flag.GetCheck();//标记索引
	int flag_int2 = m_flag_boss.GetCheck();//标记索引
	UpdateData(FALSE);
	flag_str.Format(_T("-%d-%d"), flag_int1, flag_int2);
	//1-3星血量、阵容
	CString OneToThree_str;
	int OneToThree_int1 = flood1.GetCurSel();
	int OneToThree_int2 = group1.GetCurSel();
	int OneToThree_int3 = team1.GetCurSel();
	int OneToThree_int4 = group2.GetCurSel();
	int OneToThree_int5 = team2.GetCurSel();
	UpdateData(FALSE);
	OneToThree_str.Format(_T("-%d-%d-%d-%d-%d"), OneToThree_int1, OneToThree_int2, OneToThree_int3, OneToThree_int4, OneToThree_int5);
	//4星血量、阵容
	CString Four_str;
	int Four_int1 = flood2.GetCurSel();
	int Four_int2 = group3.GetCurSel();
	int Four_int3 = team3.GetCurSel();
	int Four_int4 = group4.GetCurSel();
	int Four_int5 = team4.GetCurSel();
	UpdateData(FALSE);
	Four_str.Format(_T("-%d-%d-%d-%d-%d"), Four_int1, Four_int2, Four_int3, Four_int4, Four_int5);
	//5星血量、阵容
	CString Five_str;
	int Five_int1 = flood3.GetCurSel();
	int Five_int2 = group5.GetCurSel();
	int Five_int3 = team5.GetCurSel();
	int Five_int4 = group6.GetCurSel();
	int Five_int5 = team6.GetCurSel();
	UpdateData(FALSE);
	Five_str.Format(_T("-%d-%d-%d-%d-%d"), Five_int1, Five_int2, Five_int3, Five_int4, Five_int5);
	//6星血量、阵容
	CString Six_str;
	int Six_int1 = flood4.GetCurSel();
	int Six_int2 = group7.GetCurSel();
	int Six_int3 = team7.GetCurSel();
	int Six_int4 = group8.GetCurSel();
	int Six_int5 = team8.GetCurSel();
	UpdateData(FALSE);
	Six_str.Format(_T("-%d-%d-%d-%d-%d"), Six_int1, Six_int2, Six_int3, Six_int4, Six_int5);
	//强力追击
	CString strength_str;
	int strength_int = m_strength.GetCheck();
	UpdateData(FALSE);
	strength_str.Format(_T("-%d"), strength_int);
	//发现几星停止 5-6星公开
	CString star_stop_public_str;
	int star_stop_int = m_star.GetCurSel();
	int star_public_int = m_public.GetCheck();
	UpdateData(FALSE);
	star_stop_public_str.Format(_T("-%d-%d"), star_stop_int, star_public_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("超鬼王-" + round_str + flag_str + OneToThree_str + Four_str + Five_str + Six_str + strength_str + star_stop_public_str));
}


HBRUSH SuperKing::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_TIPS == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}
