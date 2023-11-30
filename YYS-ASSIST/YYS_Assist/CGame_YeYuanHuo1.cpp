// CGame_YeYuanHuo1.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YeYuanHuo1.h"
#include "afxdialogex.h"
#include "CGame1.h"
#include "globalvar.h"
#include <vector>
#include<any>

// CGame_YeYuanHuo1 对话框
IMPLEMENT_DYNAMIC(CGame_YeYuanHuo1, CDialog)
CGame_YeYuanHuo1::CGame_YeYuanHuo1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YeYuanHuo_DLG, pParent)
{
}
CGame_YeYuanHuo1::~CGame_YeYuanHuo1()
{
}
void CGame_YeYuanHuo1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YYH_ROUND, m_yeYuanHuo_round);
	DDX_Control(pDX, IDC_COMBO_YYH_LAYER, m_yeYuanHuo_layer);
}
BEGIN_MESSAGE_MAP(CGame_YeYuanHuo1, CDialog)
	ON_BN_CLICKED(IDC_BTN_YYH_ADDTOLIST, &CGame_YeYuanHuo1::OnBnClickedBtnYyh1Addtolist)
END_MESSAGE_MAP()
// CGame_YeYuanHuo1 消息处理程序
BOOL CGame_YeYuanHuo1::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 6, fname1);
	if (preset && line.size() == 2) {
		m_yeYuanHuo_round.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
		m_yeYuanHuo_layer.SetCurSel(std::any_cast<int>(line[1]));
	}
	else {
		m_yeYuanHuo_round.SetWindowTextW(_T("0"));
		m_yeYuanHuo_layer.SetCurSel(2);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame1 *p;
void CGame_YeYuanHuo1::OnBnClickedBtnYyh1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_YYH_ROUND, round_str);
	UpdateData(FALSE);
	//怪物种类
	CString mode_str;
	int mode_int = m_yeYuanHuo_layer.GetCurSel();//模式索引
	UpdateData(FALSE);
	mode_str.Format(_T("-%d"), mode_int);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("业原火-" + round_str + mode_str));
}
