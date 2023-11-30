#pragma once


// CGame_Tip1 对话框

class CGame_Tip1 : public CDialog
{
	DECLARE_DYNAMIC(CGame_Tip1)

public:
	CGame_Tip1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_Tip1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIPS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
