// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "bkres/winres.h"

class CMainDlg 
	: public CBkDialogImpl<CMainDlg>
	, public CWHRoundRectFrameHelper<CMainDlg>
{
public:
	CMainDlg();
	~CMainDlg();
  void OnLButtonUp(UINT nFlags, CPoint point);
   void OnLButtonDown(UINT nFlags, CPoint point);

   void OnBkBtnMax();
   void OnBkBtnMin();
   void OnBkBtnClose();

   void OnDestroy(); 

public:

	BK_NOTIFY_MAP(IDC_RICHVIEW_WIN)
		// 控件消息
		BK_NOTIFY_ID_COMMAND(IDC_BTN_SYS_CLOSE, OnBkBtnClose)  
		BK_NOTIFY_ID_COMMAND(IDC_BTN_SYS_MAX,OnBkBtnMax)
		BK_NOTIFY_ID_COMMAND(IDC_BTN_SYS_MIN,OnBkBtnMin);

	BK_NOTIFY_MAP_END()

	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_BK_NOTIFY(IDC_RICHVIEW_WIN)
		CHAIN_MSG_MAP(CBkDialogImpl<CMainDlg>)
		CHAIN_MSG_MAP(CWHRoundRectFrameHelper<CMainDlg>)
		// 自定义处理一些系统消息
		MSG_WM_DESTROY(OnDestroy) 
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

};

extern CAppModule _Module;