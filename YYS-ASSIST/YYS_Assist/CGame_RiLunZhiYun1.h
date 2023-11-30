﻿#pragma once
// CGame_RiLunZhiYun1 对话框
class CGame_RiLunZhiYun1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_RiLunZhiYun1)
public:
	CGame_RiLunZhiYun1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_RiLunZhiYun1();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RiLunZhiYun_DLG };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	// 日轮之陨次数
	CEdit m_rlzy_round;
	// 日轮之陨层数
	CComboBox m_rlzy_layer;
	// 日轮之陨加成
	CComboBox m_rlzy_auto_bonus;
	// 邀请同/跨区好友
	CComboBox m_rlzy_prefer_friend;
	// victory continue invite
	CButton m_rlzy_win;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnRlzy1Addtolist();
	// 三人组队
	CButton m_triple_team;
};
