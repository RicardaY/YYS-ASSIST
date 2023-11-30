#pragma once


// CGame_Tip2 对话框

class CGame_Tip2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_Tip2)

public:
	CGame_Tip2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_Tip2();

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
