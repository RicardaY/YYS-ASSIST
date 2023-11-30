#pragma once
// CGame_YaoQiFengYin1 对话框
class CGame_DailyTask1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_DailyTask1)
public:
	CGame_DailyTask1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_DailyTask1();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YaoQiFengYin_DLG };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	// 妖气封印次数
	CEdit m_yqfy_round;
	// 妖气封印种类
	CComboBox m_yqfy_kinds;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnYqfy1Addtolist();
	// 是否跟随房主退出队伍
	CButton m_condition;
	afx_msg void OnSelchangeComboYqfyKinds();
	CComboBox m_sub;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
