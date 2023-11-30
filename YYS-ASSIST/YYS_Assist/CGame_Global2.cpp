// CGame_Global2.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_Global2.h"
#include "CGame_Global1.h"
#include "afxdialogex.h"
#include "globalvar.h"
#include <vector>
#include<any>

CGame_Global2 *global2;
extern CGame_Global1 *global1;
// CGame_Global2 对话框

IMPLEMENT_DYNAMIC(CGame_Global2, CDialog)

CGame_Global2::CGame_Global2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_GLOBAL, pParent)
{
	global2 = this;
}

CGame_Global2::~CGame_Global2()
{
}

void CGame_Global2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RELATION, m_relation);
	DDX_Control(pDX, IDC_AUTOREJECT, m_reject);
}


BEGIN_MESSAGE_MAP(CGame_Global2, CDialog)
	ON_BN_CLICKED(IDC_RELATION, &CGame_Global2::OnBnClickedRelatioin)
	ON_BN_CLICKED(IDC_AUTOREJECT, &CGame_Global2::OnBnClickedAutoreject)
END_MESSAGE_MAP()


// CGame_Global2 消息处理程序


BOOL CGame_Global2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 13, fname2);
	if (preset && (line.size() == 2)) {
		m_relation.SetCheck(std::any_cast<int>(line[0]));
		m_reject.SetCheck(std::any_cast<int>(line[1]));
	}
	else {
		m_relation.SetCheck(0);
		m_reject.SetCheck(1);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
void CGame_Global2::OnBnClickedRelatioin()
{
	global1->m_relation.SetCheck(m_relation.GetCheck());
	UpdateData(FALSE);
}
void CGame_Global2::OnBnClickedAutoreject()
{
	global1->m_reject.SetCheck(m_reject.GetCheck());
	UpdateData(FALSE);
}

