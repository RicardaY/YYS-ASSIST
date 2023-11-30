// CGame_DailyTask1.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_DailyTask1.h"
#include "afxdialogex.h"
#include "CGame1.h"
#include "globalvar.h"
#include <vector>
#include<any>

// CGame_DailyTask1 对话框
IMPLEMENT_DYNAMIC(CGame_DailyTask1, CDialog)
CGame_DailyTask1::CGame_DailyTask1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YaoQiFengYin_DLG, pParent)
{
}
CGame_DailyTask1::~CGame_DailyTask1()
{
}
void CGame_DailyTask1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YQFY_ROUND, m_yqfy_round);
	DDX_Control(pDX, IDC_COMBO_YQFY_KINDS, m_yqfy_kinds);
	DDX_Control(pDX, IDC_CONDITION, m_condition);
	DDX_Control(pDX, IDC_COMBO_SUB, m_sub);
}
BEGIN_MESSAGE_MAP(CGame_DailyTask1, CDialog)
	ON_BN_CLICKED(IDC_BTN_YQFY_ADDTOLIST, &CGame_DailyTask1::OnBnClickedBtnYqfy1Addtolist)
	ON_CBN_SELCHANGE(IDC_COMBO_YQFY_KINDS, &CGame_DailyTask1::OnSelchangeComboYqfyKinds)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
// CGame_DailyTask1 消息处理程序
BOOL CGame_DailyTask1::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 5, fname1);
	if (preset && line.size() == 2) {
		m_yqfy_round.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
		m_yqfy_kinds.SetCurSel(std::any_cast<int>(line[1]));
		m_sub.ResetContent();
		switch (std::any_cast<int>(line[1]))
		{
		case 0: {
			m_sub.InsertString(0, _T("跳跳哥哥")); 
			m_sub.InsertString(1, _T("椒图"));
			m_sub.InsertString(2, _T("骨女"));
			m_sub.InsertString(3, _T("恶鬼"));
			m_sub.InsertString(4, _T("二口女"));
			m_sub.InsertString(5, _T("海坊主"));
			m_sub.InsertString(6, _T("鬼使黑"));
			m_sub.InsertString(7, _T("小松丸"));
			m_sub.InsertString(8, _T("日和坊"));
			m_sub.SetCurSel(0);
			break;
		}
		case 1: {
			m_sub.InsertString(0, _T("椒图(沧浪版)"));
			m_sub.InsertString(1, _T("椒图(溅射/顺势版)"));
			m_sub.InsertString(2, _T("椒图(顺势版)"));
			m_sub.SetCurSel(0);
			break;
		}
		case 2: {
			m_sub.InsertString(0, _T("经验妖怪"));
			m_sub.InsertString(1, _T("金币妖怪"));
			m_sub.InsertString(2, _T("回归挑战"));
			m_sub.SetCurSel(0);
			break;
		}
		case 3: {
			m_sub.InsertString(0, _T("探查+契灵"));
			m_sub.InsertString(1, _T("探查"));
			m_sub.InsertString(2, _T("契灵"));
			m_sub.SetCurSel(0);
			break;
		}
		default:
			break;
		}
	}
	else {
		m_yqfy_round.SetWindowTextW(_T("0"));
		m_yqfy_kinds.SetCurSel(1);
		m_sub.ResetContent();
		m_sub.InsertString(0, _T("椒图(沧浪版)"));
		m_sub.InsertString(1, _T("椒图(溅射/顺势版)"));
		m_sub.InsertString(2, _T("椒图(顺势版)"));
		m_sub.SetCurSel(0);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame1 *p;
void CGame_DailyTask1::OnBnClickedBtnYqfy1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YQFY_ROUND, round_str);
	UpdateData(FALSE);
	//怪物种类
	CString mode_str;
	int mode_int = m_yqfy_kinds.GetCurSel();//模式索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	//sub_sel
	CString sub_str;
	int sub_int = m_sub.GetCurSel();//模式索引
	UpdateData(FALSE);
	sub_str.Format(_T("-%d"), sub_int);
	//是否跟随房主退队
	CString condition_str;
	int condition = m_condition.GetCheck();
	UpdateData(FALSE);
	condition_str.Format(_T("-%d"), condition);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("日常-" + round_str + mode_str + sub_str +condition_str));
}


void CGame_DailyTask1::OnSelchangeComboYqfyKinds()
{
	int nSel = m_yqfy_kinds.GetCurSel();
	m_sub.ResetContent();
	switch (nSel)
	{
	case 0: {
		m_sub.InsertString(0,_T("跳跳哥哥")); //跳跳哥哥;椒图;骨女;恶鬼;二口女;海坊主;鬼使黑;小松丸;日和坊;
		m_sub.InsertString(1,_T("椒图")); 
		m_sub.InsertString(2,_T("骨女")); 
		m_sub.InsertString(3,_T("恶鬼")); 
		m_sub.InsertString(4,_T("二口女")); 
		m_sub.InsertString(5,_T("海坊主")); 
		m_sub.InsertString(6,_T("鬼使黑")); 
		m_sub.InsertString(7,_T("小松丸")); 
		m_sub.InsertString(8,_T("日和坊")); 
		m_sub.SetCurSel(0);
		break;
	}
	case 1: {
		m_sub.InsertString(0, _T("椒图(沧浪版)"));
		m_sub.InsertString(1, _T("椒图(溅射/顺势版)"));
		m_sub.InsertString(2, _T("椒图(顺势版)"));
		m_sub.SetCurSel(0);
		break; 
	}
	case 2: {
		m_sub.InsertString(0, _T("经验妖怪"));
		m_sub.InsertString(1, _T("金币妖怪"));
		m_sub.InsertString(2, _T("回归挑战"));
		m_sub.SetCurSel(0);
		break; 
	}
	case 3: {
		m_sub.InsertString(0, _T("探查+契灵"));
		m_sub.InsertString(1, _T("探查"));
		m_sub.InsertString(2, _T("契灵"));
		m_sub.SetCurSel(0);
		break;
	}
	default:
		break;
	}
}


HBRUSH CGame_DailyTask1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->SetBkMode(OPAQUE);
	}
	return hbr;
}
