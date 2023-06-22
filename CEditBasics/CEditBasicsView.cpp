
// CEditBasicsView.cpp : implementation of the CCEditBasicsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CEditBasics.h"
#endif

#include "CEditBasicsDoc.h"
#include "CEditBasicsView.h"
#include "CData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCEditBasicsView

IMPLEMENT_DYNCREATE(CCEditBasicsView, CView)

BEGIN_MESSAGE_MAP(CCEditBasicsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCEditBasicsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DIALOG_LAUNCHDIALOG, &CCEditBasicsView::OnDialogLaunchdialog)
END_MESSAGE_MAP()

// CCEditBasicsView construction/destruction

CCEditBasicsView::CCEditBasicsView() noexcept
{
	// TODO: add construction code here

}

CCEditBasicsView::~CCEditBasicsView()
{
}

BOOL CCEditBasicsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCEditBasicsView drawing

void CCEditBasicsView::OnDraw(CDC* pDC)
{
	CCEditBasicsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString strPrint;
	strPrint.Format(
		_T("Name: %s, Age: %d, Height: %.2f, ID: %d, Info: %s \r\n"), m_name, m_age, m_height, m_id, m_info);

	pDC->TextOutW(10, 10, strPrint);
}


// CCEditBasicsView printing


void CCEditBasicsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCEditBasicsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCEditBasicsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCEditBasicsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CCEditBasicsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCEditBasicsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCEditBasicsView diagnostics

#ifdef _DEBUG
void CCEditBasicsView::AssertValid() const
{
	CView::AssertValid();
}

void CCEditBasicsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCEditBasicsDoc* CCEditBasicsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCEditBasicsDoc)));
	return (CCEditBasicsDoc*)m_pDocument;
}
#endif //_DEBUG


// CCEditBasicsView message handlers





void CCEditBasicsView::OnDialogLaunchdialog()
{
	CData dlg;

	dlg.m_name = m_name;
	dlg.m_age = m_age;
	dlg.m_height = m_height;
	dlg.m_id = m_id;
	dlg.m_info = m_info;
		
	if(dlg.DoModal() == IDOK)
	{
		m_name = dlg.m_name;
		m_age = dlg.m_age;
		m_height = dlg.m_height;
		m_id = dlg.m_id;
		m_info = dlg.m_info;
	}
	
	Invalidate();
	UpdateWindow();
}
