﻿// YYS_AssistDlg.h: 头文件
//
#pragma once
#include "TabSheet.h"
#include "CGame1.h"
#include "CGame2.h"
// CYYSAssistDlg 对话框
class CYYSAssistDlg : public CDialogEx
{
// 构造
public:
	CYYSAssistDlg(CWnd* pParent = nullptr);	// 标准构造函数
private:
	bool GetWorkDirectory(TCHAR szWorkDirectory[], WORD wBufferCount);
	int RegisterDmNew();
	CString m_strWorkPath;
	HINSTANCE m_hDMRegInstance;
	typedef long (CALLBACK* TypeSetDllPathW)(WCHAR* szPath, long mode);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YYS_MAIN_DLG };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
// 实现
protected:
	HICON m_hIcon;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// main tab
	CTabSheet m_tab_main;
	CGame1 game1;
	CGame2 game2;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//最小化托盘
	void toTray();//最小化到托盘
	void DeleteTray();//删除托盘图标
	afx_msg LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);//图标恢复
};
