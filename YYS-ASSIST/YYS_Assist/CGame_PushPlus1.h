#pragma once


// CGame_PushPlus1 对话框

class CGame_PushPlus1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_PushPlus1)

public:
	CGame_PushPlus1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_PushPlus1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PUSHPLUS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_push;
	CEdit m_token;
	afx_msg void OnBnClickedBtnTestpush();
	virtual BOOL OnInitDialog();
	afx_msg void OnStnClickedTips10();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
