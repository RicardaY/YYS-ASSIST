#pragma once


// SuperKing2 对话框

class SuperKing2 : public CDialog
{
	DECLARE_DYNAMIC(SuperKing2)

public:
	SuperKing2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SuperKing2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUPERKING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox flood1;
	CComboBox flood2;
	CComboBox flood3;
	CComboBox flood4;
	CComboBox group1;
	CComboBox group2;
	CComboBox group3;
	CComboBox group4;
	CComboBox group5;
	CComboBox group6;
	CComboBox group7;
	CComboBox group8;
	CComboBox team1;
	CComboBox team2;
	CComboBox team3;
	CComboBox team4;
	CComboBox team5;
	CComboBox team6;
	CComboBox team7;
	CComboBox team8;
	afx_msg void OnBnClickedBtnAddtolist();
	CButton m_flag;
	CButton m_flag_boss;
	CButton m_strength;
	CEdit m_round;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CComboBox m_star;
	CButton m_public;
};
