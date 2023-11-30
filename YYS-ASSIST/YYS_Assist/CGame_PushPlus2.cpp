// CGame_PushPlus2.cpp: 实现文件
//

#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_PushPlus2.h"
#include "afxdialogex.h"
#include "yys_function.h"
#include "CGame_PushPlus1.h"
#include "CGame2.h"
#include"globalvar.h"
extern CGame2 *p;

// CGame_PushPlus2 对话框
CGame_PushPlus2 *pushplus_2;
extern CGame_PushPlus1 *pushplus_1;
IMPLEMENT_DYNAMIC(CGame_PushPlus2, CDialog)

CGame_PushPlus2::CGame_PushPlus2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PUSHPLUS, pParent)
{
	pushplus_2 = this;
}

CGame_PushPlus2::~CGame_PushPlus2()
{
}

void CGame_PushPlus2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_WECHATPUSH, m_push);
	DDX_Control(pDX, IDC_EDIT_TOKEN, m_token);
}


BEGIN_MESSAGE_MAP(CGame_PushPlus2, CDialog)
	ON_BN_CLICKED(IDC_BTN_TESTPUSH, &CGame_PushPlus2::OnBnClickedBtnTestpush)
	ON_STN_CLICKED(IDC_TIPS10, &CGame_PushPlus2::OnStnClickedTips10)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_PushPlus2 消息处理程序
void CGame_PushPlus2::OnBnClickedBtnTestpush()
{
	yys_function func;
	CString token;
	GetDlgItemText(IDC_EDIT_TOKEN, token);
	func.PushPlus(token, 1, _T("Game2"), p);
	//存储Token到本地
	std::string  tokenstr((CW2A)token.GetString());
	std::vector<std::vector<std::any>> input;
	std::vector<std::any> subinput;
	subinput.push_back("token");
	subinput.push_back(tokenstr);
	input.push_back(subinput);
	g_sn->WriteJson(input, stoken);
	pushplus_1->m_token.SetWindowTextW(token);
	p->m_tab_right.SetCurSel(3);
}
extern CStringArray TokenList;
BOOL CGame_PushPlus2::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	std::vector<std::any> line;
	int preset = sPreset->ReadLine(line, 0, stoken);
	if (preset && line.size() == 1) {
		m_token.SetWindowTextW((CString)std::any_cast<std::string>(line[0]).c_str());
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
void CGame_PushPlus2::OnStnClickedTips10()
{
	ShellExecute(NULL, _T("open"), _T("http://www.sakurayys.xyz"), NULL, NULL, SW_SHOW);
}


HBRUSH CGame_PushPlus2::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
	if (IDC_TIPS10 == pWnd->GetDlgCtrlID())//判断发出消息的空间是否是该静态文本框
	{
		pDC->SetTextColor(RGB(0, 212, 21));//设置文本颜色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
		pDC->SetBkColor(RGB(255, 255, 255));//设置文本背景颜色
	}
	return hbr;
}
