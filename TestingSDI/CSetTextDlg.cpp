// CSetTextDlg.cpp : implementation file
//

#include "pch.h"
#include "TestingSDI.h"
#include "afxdialogex.h"
#include "CSetTextDlg.h"


// CSetTextDlg dialog

IMPLEMENT_DYNAMIC(CSetTextDlg, CDialog)

CSetTextDlg::CSetTextDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SET_TEXT, pParent)
	, m_text(_T(""))
{

}

CSetTextDlg::~CSetTextDlg()
{
}

void CSetTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_text);
}


BEGIN_MESSAGE_MAP(CSetTextDlg, CDialog)
END_MESSAGE_MAP()


// CSetTextDlg message handlers
