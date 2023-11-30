#pragma once
// CGame_YongShengZhiHai2 对话框
class CGame_YongShengZhiHai2 : public CDialog
{
	DECLARE_DYNAMIC(CGame_YongShengZhiHai2)
public:
	CGame_YongShengZhiHai2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGame_YongShengZhiHai2();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YongShengZhiHai_DLG };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
public:
	// 次数
	CEdit m_yszh_round;
	// 层数
	CComboBox m_yszh_layer;
	// 加成
	CComboBox m_yszh_auto_bonus;
	// 邀请同/跨区好友
	CComboBox m_yszh_prefer_friend;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnYszh2Addtolist();
};
