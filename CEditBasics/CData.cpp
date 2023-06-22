// CData.cpp : implementation file
//

#include "pch.h"
#include "CEditBasics.h"
#include "afxdialogex.h"
#include "CData.h"




// CData dialog

IMPLEMENT_DYNAMIC(CData, CDialog)

CData::CData(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG, pParent)
	, m_name(_T(""))
	, m_age(0)
	, m_height(0)
	, m_id(0)
	, m_info(_T(""))
	, m_details(_T(""))
{

}

CData::~CData()
{
}

void CData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDV_MinMaxInt(pDX, m_age, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_HEIGHT, m_height);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_PERSON_INFO, m_info);
	DDX_Text(pDX, IDC_EDIT_DETAILS, m_details);
}


BEGIN_MESSAGE_MAP(CData, CDialog)
	ON_BN_CLICKED(IDC_PERSON_DETAILS, &CData::OnBnClickedPersonDetails)
END_MESSAGE_MAP()


// CData message handlers


void CData::OnBnClickedPersonDetails()
{
	UpdateData(TRUE);
	m_details.Format(
		_T("Name: %s, Age: %d, Height: %.2f, \r\n"
			"It is nice to learn to program using MFC.\r\n"
			"It is nice to learn to program using MFC.\r\n"
			"It is nice to learn.\r\n"
			"It is nice to learn to program using MFC.\r\n"
			"It is.\r\n"
			"It is nice to learn to program.\r\n"
			"It is nice to learn to program using MFC."), m_name, m_age, m_height);
		
		//, m_profitMonth1, m_profitMonth2, m_profitMonth3);
	UpdateData(FALSE);
}
