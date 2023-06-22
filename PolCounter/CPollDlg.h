#pragma once
#include "afxdialogex.h"



const int JOIN_POLL_NO{ 0 };
const int JOIN_POLL_LATER{ 1 };
const int JOIN_POLL_YES{ 2 };

const int LIKES_CATS{ 0 };
const int LIKES_DOGS{ 1 };



// CPollDlg dialog

class CPollDlg : public CDialog
{
	DECLARE_DYNAMIC(CPollDlg)

public:
	CPollDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPollDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RADIO_BUTTON };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	void ShowCatsDogsGroup(bool show);

public:
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadioLater();
	int m_pollOptions;
	int m_likesCatsDdogs;
	afx_msg void OnBnClickedRadioPollNo();
	afx_msg void OnBnClickedRadioPollYes();
	CButton m_ctrlCats;
	CButton m_ctrlDogs;
	CStatic m_ctrlCatsDogs;
	virtual BOOL OnInitDialog();
};
