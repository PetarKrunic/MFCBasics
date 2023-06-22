// CData.cpp : implementation file
//

#include "pch.h"
#include "DlgLesson.h"
#include "afxdialogex.h"
#include "CData.h"


// CData dialog

IMPLEMENT_DYNAMIC(CData, CDialog)

CData::CData(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG, pParent)
{

}

CData::~CData()
{
}

void CData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_DRAW, m_staticDraw);
}


BEGIN_MESSAGE_MAP(CData, CDialog)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CData message handlers


void CData::OnMouseMove(UINT nFlags, CPoint point)
{
	m_staticDraw.red = point.x %256;
	m_staticDraw.green = point.y %256;

	m_staticDraw.point = point;

	m_staticDraw.reDraw();

	


	CDialog::OnMouseMove(nFlags, point);
}
