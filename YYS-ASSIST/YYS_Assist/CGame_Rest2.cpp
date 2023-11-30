// CGame_Rest2.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_Rest2.h"
#include "afxdialogex.h"
#include "CGame2.h"
#include "globalvar.h"
#include <vector>
#include<any>

// CGame_Rest2 对话框
IMPLEMENT_DYNAMIC(CGame_Rest2, CDialog)
CGame_Rest2::CGame_Rest2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Rest_DLG, pParent)
{
}
CGame_Rest2::~CGame_Rest2()
{
}
void CGame_Rest2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_REST_TIME, m_rest_time);
}
BEGIN_MESSAGE_MAP(CGame_Rest2, CDialog)
	ON_BN_CLICKED(IDC_BTN_REST_ADDTOLIST, &CGame_Rest2::OnBnClickedBtnRest2Addtolist)
END_MESSAGE_MAP()
// CGame_Rest2 消息处理程序
BOOL CGame_Rest2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 9, fname2);
	if (preset && line.size() == 1) {
		m_rest_time.SetWindowTextW(sPreset->IntToStr(std::any_cast<int>(line[0])));
	}
	else {
		m_rest_time.SetWindowTextW(_T("10"));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
extern CGame2 *p;
void CGame_Rest2::OnBnClickedBtnRest2Addtolist()
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
