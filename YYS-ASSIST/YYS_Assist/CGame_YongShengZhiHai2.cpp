// CGame_YongShengZhiHai2.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YongShengZhiHai2.h"
#include "afxdialogex.h"
#include "CGame2.h"
#include "globalvar.h"
#include <vector>
#include<any>
// CGame_YongShengZhiHai2 对话框
IMPLEMENT_DYNAMIC(CGame_YongShengZhiHai2, CDialog)
CGame_YongShengZhiHai2::CGame_YongShengZhiHai2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YongShengZhiHai_DLG, pParent)
{
}
CGame_YongShengZhiHai2::~CGame_YongShengZhiHai2()
{
}
void CGame_YongShengZhiHai2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YSZH_ROUND, m_yszh_round);
	DDX_Control(pDX, IDC_COMBO_YSZH_LAYER, m_yszh_layer);
	DDX_Control(pDX, IDC_COMBO_YSZH_AUTO_BONUS, m_yszh_auto_bonus);
	DDX_Control(pDX, IDC_COMBO_YSZH_PREFER_FRIEND, m_yszh_prefer_friend);
}
BEGIN_MESSAGE_MAP(CGame_YongShengZhiHai2, CDialog)
	ON_BN_CLICKED(IDC_BTN_YSZH_ADDTOLIST, &CGame_YongShengZhiHai2::OnBnClickedBtnYszh2Addtolist)
END_MESSAGE_MAP()
// CGame_YongShengZhiHai2 消息处理程序
BOOL CGame_YongShengZhiHai2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 3, fname2);
	if (preset && line.size() == 5) {
		m_yszh_round.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
		m_yszh_layer.SetCurSel(std::any_cast<int>(line[1]));
		m_yszh_auto_bonus.SetCurSel(std::any_cast<int>(line[2]));
		m_yszh_prefer_friend.SetCurSel(std::any_cast<int>(line[3]));
		//radio default select
		CheckRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_ASK, std::any_cast<int>(line[4]));
	}
	else {
		m_yszh_round.SetWindowTextW(_T("30"));
		m_yszh_layer.SetCurSel(3);
		m_yszh_auto_bonus.SetCurSel(0);
		m_yszh_prefer_friend.SetCurSel(0);
		//radio default select
		CheckRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_BEASKED, IDC_RADIO_YSZH_BEASKED);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame2 *p;
void CGame_YongShengZhiHai2::OnBnClickedBtnYszh2Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YSZH_ROUND, round_str);
	UpdateData(FALSE);
	//层数
	CString layer_str;
	int layer_int = m_yszh_layer.GetCurSel();//层数索引
	UpdateData(FALSE);
	layer_str.Format(_T("-%d"), layer_int);
	//加成
	CString jiacheng_str;
	int jiacheng_int = m_yszh_auto_bonus.GetCurSel();//加成索引
	UpdateData(FALSE);
	jiacheng_str.Format(_T("-%d"), jiacheng_int);
	//组队模式
	CString zudui_str;
	int zudui_int = GetCheckedRadioButton(IDC_RADIO_YSZH_SINGLE, IDC_RADIO_YSZH_ASK);//选中的索引
	UpdateData(FALSE);
	zudui_str.Format(_T("-%d"), zudui_int);
	//邀请同区/跨区/固定好友
	CString mateType_str;
	int mateType_int = m_yszh_prefer_friend.GetCurSel();//同区/固定好友
	UpdateData(FALSE);
	mateType_str.Format(_T("-%d"), mateType_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("永生之海-" + round_str + layer_str + jiacheng_str + zudui_str + mateType_str));
}
