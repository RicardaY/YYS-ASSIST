// CGame_Tip2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_Tip2.h"
#include "afxdialogex.h"


// CGame_Tip2 对话框

IMPLEMENT_DYNAMIC(CGame_Tip2, CDialog)

CGame_Tip2::CGame_Tip2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TIPS, pParent)
{

}

CGame_Tip2::~CGame_Tip2()
{
}

void CGame_Tip2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGame_Tip2, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_Tip2 消息处理程序


HBRUSH CGame_Tip2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	if (IDC_TIPS1 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS2 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS3 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS4 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS5 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS6 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS7 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 0, 0));//设置文本颜色为红色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS8 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 255, 0));//设置文本颜色为绿色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS9 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 255, 0));//设置文本颜色为绿色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
		//hbr = CreateSolidBrush(RGB(0,0,0));//控件的背景色
	}
	if (IDC_TIPS10 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS11 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(255, 140, 0));//
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS12 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(170, 55, 251));//
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS13 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(170, 55, 251));//
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS14 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(170, 55, 251));//
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS15 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(170, 55, 251));//
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	if (IDC_TIPS16 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(170, 55, 251));//
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}
