
// TestingSDIView.cpp : implementation of the CTestingSDIView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestingSDI.h"
#endif

#include "TestingSDIDoc.h"
#include "TestingSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestingSDIView

IMPLEMENT_DYNCREATE(CTestingSDIView, CView)

BEGIN_MESSAGE_MAP(CTestingSDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestingSDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DRAW_DRAWACIRCLE, &CTestingSDIView::OnDrawDrawacircle)
	ON_COMMAND(ID_DRAW_DRAWARECTANGLE, &CTestingSDIView::OnDrawDrawarectangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAWACIRCLE, &CTestingSDIView::OnUpdateDrawDrawacircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_DRAWARECTANGLE, &CTestingSDIView::OnUpdateDrawDrawarectangle)
END_MESSAGE_MAP()

// CTestingSDIView construction/destruction

CTestingSDIView::CTestingSDIView() noexcept
{
	// TODO: add construction code here

}

CTestingSDIView::~CTestingSDIView()
{
}

BOOL CTestingSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestingSDIView drawing

void CTestingSDIView::OnDraw(CDC* pDC)
{
	CTestingSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	/*pDC->Rectangle(10, 20, 600, 400);
	pDC->TextOutW(100, 50, _T("Hello there!"));
	pDC->MoveTo(40, 200);
	pDC->LineTo(400, 300);
	pDC->Ellipse(400, 400, 800, 500);*/
	if (m_drawCircle) {
		pDC->Ellipse(100, 100, 300, 300);
	}
	else {
		pDC->Rectangle(100, 100, 400, 200);
	}

	pDC -> TextOutW(100, 400, pDoc->GetText());
	
}


// CTestingSDIView printing


void CTestingSDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestingSDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestingSDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestingSDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestingSDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestingSDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestingSDIView diagnostics

#ifdef _DEBUG
void CTestingSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CTestingSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestingSDIDoc* CTestingSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestingSDIDoc)));
	return (CTestingSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestingSDIView message handlers


void CTestingSDIView::OnDrawDrawacircle()
{
	m_drawCircle = true;
	Invalidate();
	UpdateWindow();
}


void CTestingSDIView::OnDrawDrawarectangle()
{
	m_drawCircle = false;
	Invalidate();
	UpdateWindow();
}


void CTestingSDIView::OnUpdateDrawDrawacircle(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!m_drawCircle);
}


void CTestingSDIView::OnUpdateDrawDrawarectangle(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_drawCircle);
}
