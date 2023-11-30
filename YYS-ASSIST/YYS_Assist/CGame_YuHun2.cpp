// CGame_YuHun2.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YuHun2.h"
#include "afxdialogex.h"
#include "CGame2.h"
#include "globalvar.h"
#include <vector>
#include<any>
// CGame_YuHun2 对话框
IMPLEMENT_DYNAMIC(CGame_YuHun2, CDialog)
CGame_YuHun2::CGame_YuHun2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YUHUN_DLG, pParent)
{
}
CGame_YuHun2::~CGame_YuHun2()
{
}
void CGame_YuHun2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YH_ROUND, m_yuhun_round);
	DDX_Control(pDX, IDC_COMBO_YH_LAYER, m_yuhun_layer);
	DDX_Control(pDX, IDC_COMBO_YH_AUTO_BONUS, m_yuhun_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_YH_PREFER_FRIENG, m_yuhun_prefer_friend);
	DDX_Control(pDX, IDC_CHECK_YH_VICTORY, m_yuhun_win);
	DDX_Control(pDX, IDC_TRIPLE, m_triple_team);
}
BEGIN_MESSAGE_MAP(CGame_YuHun2, CDialog)
	ON_BN_CLICKED(IDC_BTN_YH_ADDTOLIST, &CGame_YuHun2::OnBnClickedBtnYh2Addtolist)
END_MESSAGE_MAP()
// CGame_YuHun2 消息处理程序
BOOL CGame_YuHun2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 0, fname2);
	if (preset && line.size() == 6) {
		m_yuhun_round.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
		m_yuhun_layer.SetCurSel(std::any_cast<int>(line[1]));
		m_yuhun_auto_bonus.SetCurSel(std::any_cast<int>(line[2]));
		m_yuhun_prefer_friend.SetCurSel(std::any_cast<int>(line[3]));
		//radio default select
		CheckRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK, std::any_cast<int>(line[4]));
		//check box default select
		m_yuhun_win.SetCheck(std::any_cast<int>(line[5]));
	}
	else {
		m_yuhun_round.SetWindowTextW(_T("0"));
		m_yuhun_layer.SetCurSel(10);
		m_yuhun_auto_bonus.SetCurSel(1);
		m_yuhun_prefer_friend.SetCurSel(0);
		//radio default select
		CheckRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK, IDC_RADIO_YH_BEASKED);
		//check box default select
		m_yuhun_win.SetCheck(TRUE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame2 *p;
void CGame_YuHun2::OnBnClickedBtnYh2Addtolist()
{
	//获取参数
	UpdateData(true);
	//御魂次数
	CString round_str;
	GetDlgItemText(IDC_YH_ROUND, round_str);
	UpdateData(FALSE);
	//御魂层数
	CString layer_str;
	int layer_int = m_yuhun_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_yuhun_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_YH_SINGLE, IDC_RADIO_YH_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//邀请同区/跨区/固定好友
	CString mateType_str;
	int mateType_int = m_yuhun_prefer_friend.GetCurSel();//同区/固定好友
	UpdateData(FALSE);
	mateType_str.Format(_T("-%d"), mateType_int);
	//三人组队
	CString triple_str;
	int triple = m_triple_team.GetCheck();//三人组队
	UpdateData(FALSE);
	triple_str.Format(_T("-%d"), triple);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("御魂-" + round_str + layer_str + jiacheng_str + zudui_str + mateType_str + triple_str));
}
