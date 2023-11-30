#pragma once
// CGame_Timer2 对话框
class CGame_Timer2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_Timer2)
public:
	CGame_Timer2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_Timer2();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMER };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CButton m_adopt;
	CComboBox m_kind;
	CComboBox m_star;
	CComboBox m_area;
	CButton m_tmstart;
	CEdit m_timecon;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
