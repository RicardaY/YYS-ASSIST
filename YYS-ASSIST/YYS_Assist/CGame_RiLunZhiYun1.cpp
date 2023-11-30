// CGame_RiLunZhiYun1.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_RiLunZhiYun1.h"
#include "afxdialogex.h"
#include "CGame1.h"
#include "globalvar.h"
#include <vector>
#include<any>

// CGame_RiLunZhiYun1 对话框
IMPLEMENT_DYNAMIC(CGame_RiLunZhiYun1, CDialog)
CGame_RiLunZhiYun1::CGame_RiLunZhiYun1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RiLunZhiYun_DLG, pParent)
{
}
CGame_RiLunZhiYun1::~CGame_RiLunZhiYun1()
{
}
void CGame_RiLunZhiYun1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RLZY_ROUND, m_rlzy_round);
	DDX_Control(pDX, IDC_COMBO_RLZY_LAYER, m_rlzy_layer);
	DDX_Control(pDX, IDC_COMBO_RLZY_AUTO_BONUS, m_rlzy_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_RLZY_PREFER_FRIEND, m_rlzy_prefer_friend);
	DDX_Control(pDX, IDC_VICTORY_RLZY, m_rlzy_win);
	DDX_Control(pDX, IDC_TRIPLE, m_triple_team);
}
BEGIN_MESSAGE_MAP(CGame_RiLunZhiYun1, CDialog)
	ON_BN_CLICKED(IDC_BTN_RLZY_ADDTOLIST, &CGame_RiLunZhiYun1::OnBnClickedBtnRlzy1Addtolist)
END_MESSAGE_MAP()
// CGame_RiLunZhiYun1 消息处理程序
BOOL CGame_RiLunZhiYun1::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 2, fname1);
	if (preset && line.size() == 6) {
		m_rlzy_round.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
		m_rlzy_layer.SetCurSel(std::any_cast<int>(line[1]));
		m_rlzy_auto_bonus.SetCurSel(std::any_cast<int>(line[2]));
		m_rlzy_prefer_friend.SetCurSel(std::any_cast<int>(line[3]));
		//radio default select
		CheckRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_ASK, std::any_cast<int>(line[4]));
		//check box default select
		m_rlzy_win.SetCheck(std::any_cast<int>(line[5]));
	}
	else {
		m_rlzy_round.SetWindowTextW(_T("50"));
		m_rlzy_layer.SetCurSel(2);
		m_rlzy_auto_bonus.SetCurSel(0);
		m_rlzy_prefer_friend.SetCurSel(0);
		//radio default select
		CheckRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_BEASKED, IDC_RADIO_RLZY_BEASKED);
		//check box default select
		m_rlzy_win.SetCheck(TRUE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame1 *p;
void CGame_RiLunZhiYun1::OnBnClickedBtnRlzy1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_RLZY_ROUND, round_str);
	UpdateData(FALSE);
	//层数
	CString layer_str;
	int layer_int = m_rlzy_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_rlzy_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_RLZY_SINGLE, IDC_RADIO_RLZY_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//邀请同区/跨区/固定好友
	CString mateType_str;
	int mateType_int = m_rlzy_prefer_friend.GetCurSel();//同区/固定好友
	UpdateData(FALSE);
	mateType_str.Format(_T("-%d"), mateType_int);
	//三人组队
	CString triple_str;
	int triple = m_triple_team.GetCheck();//三人组队
	UpdateData(FALSE);
	triple_str.Format(_T("-%d"), triple);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("日轮之陨-" + round_str + layer_str + jiacheng_str + zudui_str + mateType_str + triple_str));
}
