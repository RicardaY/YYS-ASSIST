// CGame_JueXing1.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_JueXing1.h"
#include "afxdialogex.h"
#include "CGame1.h"
#include "globalvar.h"
#include <vector>
#include<any>

// CGame_JueXing1 对话框
IMPLEMENT_DYNAMIC(CGame_JueXing1, CDialog)
CGame_JueXing1::CGame_JueXing1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_JueXing_DLG, pParent)
{
}
CGame_JueXing1::~CGame_JueXing1()
{
}
void CGame_JueXing1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_JX_ROUND, m_jueXing_round);
	DDX_Control(pDX, IDC_COMBO_JX_MODE, m_jueXing_mode);
	DDX_Control(pDX, IDC_COMBO_JX_LAYER, m_jueXing_layer);
	DDX_Control(pDX, IDC_COMBO_JX_AUTO_BONUS, m_jueXing_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_JX_PREFER_FRIEND, m_jueXing_prefer_friend);
	DDX_Control(pDX, IDC_CHECK_JX_VICTORY, m_jueXing_win);
	DDX_Control(pDX, IDC_TRIPLE, m_triple_team);
}
BEGIN_MESSAGE_MAP(CGame_JueXing1, CDialog)
	ON_BN_CLICKED(IDC_BTN_JX_ADDTOLIST, &CGame_JueXing1::OnBnClickedBtnJx1Addtolist)
END_MESSAGE_MAP()
// CGame_JueXing1 消息处理程序
BOOL CGame_JueXing1::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 1, fname1);
	if (preset && line.size() == 7) {
		m_jueXing_round.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
		m_jueXing_mode.SetCurSel(std::any_cast<int>(line[1]));
		m_jueXing_layer.SetCurSel(std::any_cast<int>(line[2]));
		m_jueXing_auto_bonus.SetCurSel(std::any_cast<int>(line[3]));
		m_jueXing_prefer_friend.SetCurSel(std::any_cast<int>(line[4]));
		CheckRadioButton(IDC_RADIO_JX_SINGLE, IDC_RADIO_JX_ASK, std::any_cast<int>(line[5]));
		m_jueXing_win.SetCheck(std::any_cast<int>(line[6]));
	}
	else {
		m_jueXing_round.SetWindowTextW(_T("0"));
		m_jueXing_mode.SetCurSel(0);
		m_jueXing_layer.SetCurSel(9);
		m_jueXing_auto_bonus.SetCurSel(1);
		m_jueXing_prefer_friend.SetCurSel(0);
		//radio default select
		CheckRadioButton(IDC_RADIO_JX_SINGLE, IDC_RADIO_JX_ASK, IDC_RADIO_JX_BEASKED);
		//check box default select
		m_jueXing_win.SetCheck(TRUE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame1 *p;
void CGame_JueXing1::OnBnClickedBtnJx1Addtolist()
{
	//获取参数
	UpdateData(true);
	//觉醒次数
	CString round_str;
	GetDlgItemText(IDC_JX_ROUND, round_str);
	UpdateData(FALSE);
	//觉醒模式
	CString mode_str;
	int mode_int = m_jueXing_mode.GetCurSel();//模式索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	//觉醒层数
	CString layer_str;
	int layer_int = m_jueXing_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_jueXing_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_JX_SINGLE, IDC_RADIO_JX_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//邀请同区/跨区/固定好友
	CString mateType_str;
	int mateType_int = m_jueXing_prefer_friend.GetCurSel();//同区/固定好友
	UpdateData(FALSE);
	mateType_str.Format(_T("-%d"), mateType_int);
	//三人组队
	CString triple_str;
	int triple = m_triple_team.GetCheck();//三人组队
	UpdateData(FALSE);
	triple_str.Format(_T("-%d"), triple);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("觉醒-" + round_str + mode_str + layer_str + jiacheng_str + zudui_str + mateType_str + triple_str));
}
