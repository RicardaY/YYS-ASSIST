// CGame_FixTeamer.cpp: 实现文件
//
#pragma once
#include "pch.h"
#include "YYS_Assist.h"
#include "CGame_FixTeamer.h"
#include "afxdialogex.h"
#include "CGame1.h"
#include "snow.h"


// CGame_FixTeamer 对话框
IMPLEMENT_DYNAMIC(CGame_FixTeamer, CDialog)

CGame_FixTeamer::CGame_FixTeamer(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_FIXTEAMER, pParent)
{

}

CGame_FixTeamer::~CGame_FixTeamer()
{
}

void CGame_FixTeamer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_IMG, m_picImage1);
	DDX_Control(pDX, IDC_STATIC_IMG2, m_picImage2);
	DDX_Control(pDX, IDC_STATIC_IMG3, m_picImage3);
	DDX_Control(pDX, IDC_STATIC_IMG4, m_picImage4);
	DDX_Control(pDX, IDC_STATIC_IMG5, m_picImage5);
	DDX_Control(pDX, IDC_STATIC_IMG6, m_picImage6);
	DDX_Control(pDX, IDC_COMBO_TEAMERPOS, m_teamerpos);
}


BEGIN_MESSAGE_MAP(CGame_FixTeamer, CDialog)
	ON_BN_CLICKED(IDC_BTN_ADD, &CGame_FixTeamer::OnBnClickedBtnAdd)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CGame_FixTeamer 消息处理程序


BOOL CGame_FixTeamer::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HBITMAP hbitmap;
	m_teamerpos.SetCurSel(0);
	//初始化变量数组
	CStatic *m_picImage[6];
	m_picImage[0] = &m_picImage1;
	m_picImage[1] = &m_picImage2;
	m_picImage[2] = &m_picImage3;
	m_picImage[3] = &m_picImage4;
	m_picImage[4] = &m_picImage5;
	m_picImage[5] = &m_picImage6;
	//PathFileExists()
	//判断是否存在image_dir
	if (!PathIsDirectory(_T("config\\imgGame12"))) {
		CString image_dir = _T("resource\\init.bmp");
		hbitmap = (HBITMAP)::LoadImage(NULL, image_dir, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		for (int i = 0; i < 6; i++) {
			m_picImage[i]->SetBitmap(hbitmap);
		}
	}
	else {
		CString num_index;
		for (int i = 0; i < 6; i++) {
			num_index.Format(_T("%d"), i + 1);
			if (PathFileExists(_T("config\\imgGame12\\teamer") + num_index + _T(".bmp"))) {
				CString image_dir = _T("config\\imgGame12\\teamer") + num_index + _T(".bmp");
				hbitmap = (HBITMAP)::LoadImage(NULL, image_dir, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
				m_picImage[i]->SetBitmap(hbitmap);
			}
			else {
				CString image_dir = _T("resource\\init.bmp");
				hbitmap = (HBITMAP)::LoadImage(NULL, image_dir, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
				m_picImage[i]->SetBitmap(hbitmap);
			}
		}
	}
	if (hbitmap != nullptr) { hbitmap = nullptr; DeleteObject(hbitmap); }
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
void CGame_FixTeamer::OnBnClickedBtnAdd()
{	
	
	snow *sn = new snow;
	HBITMAP hbitmap;
	extern CGame1 *p;
	CString m_handle;
	//获取句柄，后台截取
	p->m_hadleText.GetWindowTextW(m_handle);
	long handle = StrToInt(m_handle);
	long sn_band = 0;
	if (m_handle.IsEmpty())
	{
		::MessageBox(NULL, _T("请选择句柄！"), _T("提示"), 0);
		//解绑
		if (sn->IsBind(handle))
		{
			sn->UnBindWindow();
		}
		//释放资源
		if (sn != nullptr)
		{
			delete sn;
			sn = nullptr;
		}
		return;
	}
	//判断句柄
	int simMachineType = p->m_windowType.GetCurSel();
	//雷电
	if (simMachineType == 0) {
		sn_band = sn->BindWindowEx(handle, _T("dx.graphic.opengl"), _T("windows3"), _T("windows"), _T("dx.public.prevent.block"), 0);
	}
	//mumu
	else if (simMachineType == 1) {
		sn_band = sn->BindWindowEx(handle, _T("gdi"), _T("windows3"), _T("windows"), _T("dx.public.prevent.block"), 0);
	}
	else if (simMachineType == 2) {
		sn_band = sn->BindWindowEx(handle, _T("dx.graphic.3d.10plus"), _T("windows3"), _T("windows"), _T("dx.public.prevent.block"), 0);
	}
	//判断是否绑定成功
	if (sn_band != 1)
	{
		long err = GetLastError();
		CString err_str;
		err_str.Format(_T("%d"), err);
		::MessageBox(NULL, _T("绑定窗口句柄失败，错误码：" + err_str), _T("提示"), 0);
		if (sn != nullptr)
		{
			delete sn;
			sn = nullptr;
		}
		return;
	}
	//创建保存游戏数据的文件夹
	CString path = _T("config\\imgGame12");
	if (!PathIsDirectory(path))
	{
		CreateDirectory(path, NULL);
	}
	//截图 //337,148,397,166,宽高(60,18)
	switch (m_teamerpos.GetCurSel())
	{
	case 0: {sn->Capture(337, 148, 397, 166, _T("config\\imgGame12\\teamer1.bmp")); break; }
	case 1:{sn->Capture(556, 148, 616, 166, _T("config\\imgGame12\\teamer2.bmp")); break; }
	case 2:{sn->Capture(337, 220, 397, 238, _T("config\\imgGame12\\teamer3.bmp")); break; }
	case 3:{sn->Capture(556, 220, 616, 238, _T("config\\imgGame12\\teamer4.bmp")); break; }
	case 4:{sn->Capture(337, 292, 397, 310, _T("config\\imgGame12\\teamer5.bmp")); break; }
	case 5:{sn->Capture(556, 292, 616, 310, _T("config\\imgGame12\\teamer6.bmp")); break; }
	default:
		break;
	}
	if (sn != nullptr) {
		delete sn;
		sn = nullptr;
	}
	//读取并显示图像
	//初始化变量数组
	CStatic *m_picImage[6];
	m_picImage[0] = &m_picImage1;
	m_picImage[1] = &m_picImage2;
	m_picImage[2] = &m_picImage3;
	m_picImage[3] = &m_picImage4;
	m_picImage[4] = &m_picImage5;
	m_picImage[5] = &m_picImage6;
	CString num_index;
	for (int i = 0; i < 6; i++) {
		num_index.Format(_T("%d"), i + 1);
		if (PathFileExists(_T("config\\imgGame12\\teamer") + num_index + _T(".bmp"))) {
			CString image_dir = _T("config\\imgGame12\\teamer") + num_index + _T(".bmp");
			hbitmap = (HBITMAP)::LoadImage(NULL, image_dir, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
			m_picImage[i]->SetBitmap(hbitmap);
		}
		else {
			CString image_dir = _T("resource\\init.bmp");
			hbitmap = (HBITMAP)::LoadImage(NULL, image_dir, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_DEFAULTSIZE | LR_LOADFROMFILE);
			m_picImage[i]->SetBitmap(hbitmap);
		}
	}
	if (hbitmap != nullptr) { hbitmap = nullptr; DeleteObject(hbitmap); }
}

HBRUSH CGame_FixTeamer::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		pDC->SetTextColor(RGB(0, 0, 255));//设置文本颜色为蓝色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
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
		pDC->SetTextColor(RGB(228, 6, 163));//设置文本颜色
		pDC->SetBkMode(OPAQUE);//设置文本背景模式为透明
	}
	return hbr;
}
