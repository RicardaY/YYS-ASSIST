﻿#pragma once
// CGame_JueXing2 对话框
class CGame_JueXing2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_JueXing2)
public:
	CGame_JueXing2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_JueXing2();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JueXing_DLG };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	// 觉醒次数
	CEdit m_jueXing_round;
	// 觉醒模式
	CComboBox m_jueXing_mode;
	// 觉醒层数
	CComboBox m_jueXing_layer;
	// 觉醒加成
	CComboBox m_jueXing_auto_bonus;
	// 邀请同/跨区好友
	CComboBox m_jueXing_prefer_friend;
	// 胜利邀请好友
	CButton m_jueXing_win;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnJx2Addtolist();
	// 三人组队
	CButton m_triple_team;
};
