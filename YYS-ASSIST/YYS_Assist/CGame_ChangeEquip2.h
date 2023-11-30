﻿#pragma once
// CGame_ChangeEquip2 对话框
class CGame_ChangeEquip2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_ChangeEquip2)
public:
	CGame_ChangeEquip2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_ChangeEquip2();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGEEQUIP };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CComboBox m_yhg;
	CComboBox m_yht;
	CComboBox m_jxg;
	CComboBox m_jxt;
	CComboBox m_tsg;
	CComboBox m_tst;
	CComboBox m_rlzyg;
	CComboBox m_rlzyt;
	CComboBox m_yszhg;
	CComboBox m_yszht1;
	CComboBox m_yszht2;
	CComboBox m_ylg;
	CComboBox m_ylt;
	CComboBox m_yyhg;
	CComboBox m_yyht;
	CComboBox m_jjtpg;
	CComboBox m_jjtpt;
	CComboBox m_yqfyg;
	CComboBox m_yqfyt;
	CButton m_ispreset;
};
