#pragma once
// CGame_inDependentFunc2 对话框
class CGame_inDependentFunc2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_inDependentFunc2)
public:
	CGame_inDependentFunc2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_inDependentFunc2();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INDEPENDENT };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_baigui;
	CButton m_king;
	CComboBox m_amount;
	virtual BOOL OnInitDialog();
	CButton m_plot;
	CButton m_pvp;
	CComboBox m_pvptype;
	CButton m_ready;
	CButton m_clearing;
	CButton m_whitecard;
	CButton m_challenge;
	CButton m_small;
	CButton m_lingran;
};
