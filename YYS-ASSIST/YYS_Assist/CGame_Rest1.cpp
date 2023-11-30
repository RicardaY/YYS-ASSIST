// CGame_Rest1.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_Rest1.h"
#include "afxdialogex.h"
#include "CGame1.h"
#include "globalvar.h"
#include <vector>
#include<any>
// CGame_Rest1 对话框
IMPLEMENT_DYNAMIC(CGame_Rest1, CDialog)
CGame_Rest1::CGame_Rest1(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Rest_DLG, pParent)
{
}
CGame_Rest1::~CGame_Rest1()
{
}
void CGame_Rest1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_REST_TIME, m_rest_time);
}
BEGIN_MESSAGE_MAP(CGame_Rest1, CDialog)
	ON_BN_CLICKED(IDC_BTN_REST_ADDTOLIST, &CGame_Rest1::OnBnClickedBtnRest1Addtolist)
END_MESSAGE_MAP()
// CGame_Rest1 消息处理程序
BOOL CGame_Rest1::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 9, fname1);
	if (preset && line.size() == 1) {
		m_rest_time.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
	}
	else {
		m_rest_time.SetWindowTextW(_T("10"));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame1 *p;
void CGame_Rest1::OnBnClickedBtnRest1Addtolist()
{
	//获取参数
	UpdateData(true);
	//次数
	CString round_str;
	GetDlgItemText(IDC_REST_TIME, round_str);
	UpdateData(FALSE);
	//点击添加任务到列表
	p->m_list_taskshow.InsertItem(p->m_list_taskshow.GetItemCount(), _T("休息-" + round_str));
}
