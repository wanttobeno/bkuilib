// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "bkres/res.h"
#include "MainDlg.h"

#ifdef _DEBUG
#pragma comment(lib,"../Debug/tinyxml.lib")
#else
#pragma comment(lib,"../Release/tinyxml.lib")
#endif // _DEBUG

CMainDlg::CMainDlg():CBkDialogImpl<CMainDlg>(IDR_BK_MAIN_DIALOG) // 在这里加载界面框架
{
	// 以下 Load xx 的语句是必须的，否则皮肤将不能显示
	BkString::Load(IDR_BK_STRING_DEF); // 加载字符串
	BkFontPool::SetDefaultFont(BkString::Get(IDS_APP_FONT), -12); // 设置字体
	BkSkin::LoadSkins(IDR_BK_SKIN_DEF); // 加载皮肤
	BkStyle::LoadStyles(IDR_BK_STYLE_DEF); // 加载风格
}

CMainDlg::~CMainDlg()
{

}

void CMainDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	OutputDebugString(_T("鼠标弹起\n"));
}

void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	OutputDebugString(_T("鼠标按下\n"));
}


void CMainDlg::OnBkBtnMax()  
{  
	if (WS_MAXIMIZE == (GetStyle() & WS_MAXIMIZE))  
	{  
		SendMessage(WM_SYSCOMMAND, SC_RESTORE | HTCAPTION, 0);  
	}  
	else  
	{  
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE | HTCAPTION, 0);  
	}  
}  

void CMainDlg::OnBkBtnMin()  
{  
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE | HTCAPTION, 0);  
}  

void CMainDlg::OnBkBtnClose()  
{  
	DestroyWindow();  
}  

void CMainDlg::OnDestroy()
{
	OutputDebugStringA(__FUNCTION__);
	PostQuitMessage(0);  
}