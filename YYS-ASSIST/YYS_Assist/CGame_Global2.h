#pragma once


// CGame_Global2 对话框

class CGame_Global2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_Global2)

public:
	CGame_Global2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_Global2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLOBAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_relation;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRelatioin();
	CButton m_reject;
	afx_msg void OnBnClickedAutoreject();
};
