// CGame_ChangeEquip2.cpp: 实现文件
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_ChangeEquip2.h"
#include "afxdialogex.h"
#include "globalvar.h"
#include <vector>
#include<any>
#include "afxdialogex.h"

// CGame_ChangeEquip2 对话框

IMPLEMENT_DYNAMIC(CGame_ChangeEquip2, CDialog)
CGame_ChangeEquip2::CGame_ChangeEquip2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHANGEEQUIP, pParent)
{
}
CGame_ChangeEquip2::~CGame_ChangeEquip2()
{
}
void CGame_ChangeEquip2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GROUP1, m_yhg);
	DDX_Control(pDX, IDC_TEAM1, m_yht);
	DDX_Control(pDX, IDC_GROUP2, m_jxg);
	DDX_Control(pDX, IDC_TEAM2, m_jxt);
	DDX_Control(pDX, IDC_GROUP3, m_tsg);
	DDX_Control(pDX, IDC_TEAM3, m_tst);
	DDX_Control(pDX, IDC_GROUP4, m_rlzyg);
	DDX_Control(pDX, IDC_TEAM4, m_rlzyt);
	DDX_Control(pDX, IDC_GROUP5, m_yszhg);
	DDX_Control(pDX, IDC_TEAM5, m_yszht1);
	DDX_Control(pDX, IDC_TEAM51, m_yszht2);
	DDX_Control(pDX, IDC_GROUP6, m_ylg);
	DDX_Control(pDX, IDC_TEAM6, m_ylt);
	DDX_Control(pDX, IDC_GROUP7, m_yyhg);
	DDX_Control(pDX, IDC_TEAM7, m_yyht);
	DDX_Control(pDX, IDC_GROUP8, m_jjtpg);
	DDX_Control(pDX, IDC_TEAM8, m_jjtpt);
	DDX_Control(pDX, IDC_GROUP9, m_yqfyg);
	DDX_Control(pDX, IDC_TEAM9, m_yqfyt);
	DDX_Control(pDX, IDC_ISCHANGE, m_ispreset);
}
BEGIN_MESSAGE_MAP(CGame_ChangeEquip2, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()
// CGame_ChangeEquip2 消息处理程序
BOOL CGame_ChangeEquip2::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
	std::vector<std::any> lineg;
	std::vector<std::any> linet;
	int preset1 = sPreset->ReadLine(lineg, 10, fname2);
	int preset2 = sPreset->ReadLine(linet, 11, fname2);
	if ((preset1&preset2) && (lineg.size() == 9) && (linet.size() == 10)) {
		//御魂组
		m_yhg.SetCurSel(std::any_cast<int>(lineg[0]));
		m_jxg.SetCurSel(std::any_cast<int>(lineg[1]));
		m_tsg.SetCurSel(std::any_cast<int>(lineg[2]));
		m_rlzyg.SetCurSel(std::any_cast<int>(lineg[3]));
		m_yszhg.SetCurSel(std::any_cast<int>(lineg[4]));
		m_ylg.SetCurSel(std::any_cast<int>(lineg[5]));
		m_yyhg.SetCurSel(std::any_cast<int>(lineg[6]));
		m_jjtpg.SetCurSel(std::any_cast<int>(lineg[7]));
		m_yqfyg.SetCurSel(std::any_cast<int>(lineg[8]));
		//御魂队伍
		m_yht.SetCurSel(std::any_cast<int>(linet[0]));
		m_jxt.SetCurSel(std::any_cast<int>(linet[1]));
		m_tst.SetCurSel(std::any_cast<int>(linet[2]));
		m_rlzyt.SetCurSel(std::any_cast<int>(linet[3]));
		m_yszht1.SetCurSel(std::any_cast<int>(linet[4]));
		m_yszht2.SetCurSel(std::any_cast<int>(linet[5]));
		m_ylt.SetCurSel(std::any_cast<int>(linet[6]));
		m_yyht.SetCurSel(std::any_cast<int>(linet[7]));
		m_jjtpt.SetCurSel(std::any_cast<int>(linet[8]));
		m_yqfyt.SetCurSel(std::any_cast<int>(linet[9]));
	}
	else {
		//御魂组
		m_yhg.SetCurSel(0);
		m_jxg.SetCurSel(0);
		m_tsg.SetCurSel(0);
		m_rlzyg.SetCurSel(0);
		m_yszhg.SetCurSel(0);
		m_ylg.SetCurSel(0);
		m_yyhg.SetCurSel(0);
		m_jjtpg.SetCurSel(0);
		m_yqfyg.SetCurSel(0);
		//御魂队伍
		m_yht.SetCurSel(0);
		m_jxt.SetCurSel(0);
		m_tst.SetCurSel(0);
		m_rlzyt.SetCurSel(0);
		m_yszht1.SetCurSel(0);
		m_yszht2.SetCurSel(0);
		m_ylt.SetCurSel(0);
		m_yyht.SetCurSel(0);
		m_jjtpt.SetCurSel(0);
		m_yqfyt.SetCurSel(0);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
HBRUSH CGame_ChangeEquip2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
	}
	return hbr;
}