// CPollDlg.cpp : implementation file
//

#include "pch.h"
#include "PolCounter.h"
#include "afxdialogex.h"
#include "CPollDlg.h"


// CPollDlg dialog

IMPLEMENT_DYNAMIC(CPollDlg, CDialog)

CPollDlg::CPollDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_RADIO_BUTTON, pParent)
	, m_pollOptions(JOIN_POLL_LATER)
	, m_likesCatsDdogs(LIKES_CATS)
{

}

CPollDlg::~CPollDlg()
{
}

void CPollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_POLL_NO, m_pollOptions);
	DDX_Radio(pDX, IDC_RADIO_LIKES_CATS, m_likesCatsDdogs);
	DDX_Control(pDX, IDC_RADIO_LIKES_CATS, m_ctrlCats);
	DDX_Control(pDX, IDC_RADIO_LIKES_DOGS, m_ctrlDogs);
	DDX_Control(pDX, IDC_STATIC_CATS_DOGS, m_ctrlCatsDogs);
}


BEGIN_MESSAGE_MAP(CPollDlg, CDialog)
	ON_BN_CLICKED(IDC_RADIO_LATER, &CPollDlg::OnBnClickedRadioLater)
	ON_BN_CLICKED(IDC_RADIO_POLL_NO, &CPollDlg::OnBnClickedRadioPollNo)
	ON_BN_CLICKED(IDC_RADIO_POLL_YES, &CPollDlg::OnBnClickedRadioPollYes)
END_MESSAGE_MAP()



void CPollDlg :: ShowCatsDogsGroup(bool show)
{
	int cmdShow = show ? SW_SHOW : SW_HIDE;

	m_ctrlCatsDogs.ShowWindow(cmdShow);
	m_ctrlCats.ShowWindow(cmdShow);
	m_ctrlDogs.ShowWindow(cmdShow);
}


void CPollDlg::OnBnClickedRadioLater()
{
	ShowCatsDogsGroup(false);
}


void CPollDlg::OnBnClickedRadioPollNo()
{
	ShowCatsDogsGroup(false);
}


void CPollDlg::OnBnClickedRadioPollYes()
{
	ShowCatsDogsGroup(true);
}


BOOL CPollDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ShowCatsDogsGroup(m_pollOptions == JOIN_POLL_YES);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
