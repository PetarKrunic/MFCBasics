
// SliderCtrlView.cpp : implementation of the CSliderCtrlView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SliderCtrl.h"
#endif

#include "SliderCtrlDoc.h"
#include "SliderCtrlView.h"
#include "SliderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSliderCtrlView

IMPLEMENT_DYNCREATE(CSliderCtrlView, CView)

BEGIN_MESSAGE_MAP(CSliderCtrlView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSliderCtrlView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DIALOG_LAUNCHDIALOG, &CSliderCtrlView::OnDialogLaunchdialog)
END_MESSAGE_MAP()

// CSliderCtrlView construction/destruction

CSliderCtrlView::CSliderCtrlView() noexcept
{
	// TODO: add construction code here

}

CSliderCtrlView::~CSliderCtrlView()
{
}

BOOL CSliderCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSliderCtrlView drawing

void CSliderCtrlView::OnDraw(CDC* pDC)
{
	CSliderCtrlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rectWindow;
	GetClientRect(&rectWindow);


	auto color{ RGB(red, green, blue) };

	CBrush brush(color);

	pDC -> FillRect(&rectWindow, &brush);

}


// CSliderCtrlView printing


void CSliderCtrlView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSliderCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSliderCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSliderCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSliderCtrlView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSliderCtrlView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSliderCtrlView diagnostics

#ifdef _DEBUG
void CSliderCtrlView::AssertValid() const
{
	CView::AssertValid();
}

void CSliderCtrlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSliderCtrlDoc* CSliderCtrlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSliderCtrlDoc)));
	return (CSliderCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CSliderCtrlView message handlers


void CSliderCtrlView::OnDialogLaunchdialog()
{
	SliderDlg dlg;

	dlg.red = red;
	dlg.green = green;
	dlg.blue = blue;

	if(dlg.DoModal() == IDOK)
	{
		red = dlg.red;
		green = dlg.green;
		blue = dlg.blue;
		Invalidate();
		UpdateWindow();
	}
}
