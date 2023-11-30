#pragma once
#include "obj.h"

// CGame_FixTeamer 对话框

class CGame_FixTeamer : public CDialog
{
	DECLARE_DYNAMIC(CGame_FixTeamer)

public:
	CGame_FixTeamer(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_FixTeamer();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIXTEAMER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_picImage1;
	CStatic m_picImage2;
	CStatic m_picImage3;
	CStatic m_picImage4;
	CStatic m_picImage5;
	CStatic m_picImage6;
	afx_msg void OnBnClickedBtnAdd();
	virtual BOOL OnInitDialog();
	CComboBox m_teamerpos;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
