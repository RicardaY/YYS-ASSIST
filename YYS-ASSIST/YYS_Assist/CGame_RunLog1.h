#pragma once
// CGame_RunLog1 对话框
class CGame_RunLog1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_RunLog1)
public:
	CGame_RunLog1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_RunLog1();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RunLog };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_runLog;
	virtual BOOL OnInitDialog();
	CFont m_font;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
