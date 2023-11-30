// CGame_YeYuanHuo2.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_YeYuanHuo2.h"
#include "afxdialogex.h"
#include "CGame2.h"
#include "globalvar.h"
#include <vector>
#include<any>
// CGame_YeYuanHuo2 对话框
IMPLEMENT_DYNAMIC(CGame_YeYuanHuo2, CDialog)
CGame_YeYuanHuo2::CGame_YeYuanHuo2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YeYuanHuo_DLG, pParent)
{
}
CGame_YeYuanHuo2::~CGame_YeYuanHuo2()
{
}
void CGame_YeYuanHuo2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_YYH_ROUND, m_yeYuanHuo_round);
	DDX_Control(pDX, IDC_COMBO_YYH_LAYER, m_yeYuanHuo_layer);
}
BEGIN_MESSAGE_MAP(CGame_YeYuanHuo2, CDialog)
	ON_BN_CLICKED(IDC_BTN_YYH_ADDTOLIST, &CGame_YeYuanHuo2::OnBnClickedBtnYyh2Addtolist)
END_MESSAGE_MAP()
// CGame_YeYuanHuo2 消息处理程序
BOOL CGame_YeYuanHuo2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 6, fname2);
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
extern CGame2 *p;
void CGame_YeYuanHuo2::OnBnClickedBtnYyh2Addtolist()
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
