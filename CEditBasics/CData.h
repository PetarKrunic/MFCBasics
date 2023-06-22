#pragma once
#include "afxdialogex.h"


// CData dialog

class CData : public CDialog
{
	DECLARE_DYNAMIC(CData)

public:
	CData(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CData();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// Persons name
	CString m_name;
	int m_age;
	double m_height;
	int m_id;
	CString m_info;
	CString m_details;
	afx_msg void OnBnClickedPersonDetails();
};
