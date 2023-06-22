
// PolCounterView.cpp : implementation of the CPolCounterView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "PolCounter.h"
#endif

#include "PolCounterDoc.h"
#include "PolCounterView.h"
#include "CPollDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPolCounterView

IMPLEMENT_DYNCREATE(CPolCounterView, CView)

BEGIN_MESSAGE_MAP(CPolCounterView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPolCounterView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_ACTION_POLL, &CPolCounterView::OnActionPoll)
END_MESSAGE_MAP()

// CPolCounterView construction/destruction

CPolCounterView::CPolCounterView() noexcept
{
	// TODO: add construction code here

}

CPolCounterView::~CPolCounterView()
{
}

BOOL CPolCounterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPolCounterView drawing

void CPolCounterView::OnDraw(CDC* pDC)
{
	CPolCounterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CString strText;
	strText = (_T("Poll results so far: "));
	pDC->TextOutW(10, 20, strText);
	strText.Format(_T("Cats: %d, Dogs: %d"), m_catCount, m_dogCount);
	pDC->TextOutW(10, 50, strText);
}


// CPolCounterView printing


void CPolCounterView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPolCounterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPolCounterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPolCounterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPolCounterView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPolCounterView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPolCounterView diagnostics

#ifdef _DEBUG
void CPolCounterView::AssertValid() const
{
	CView::AssertValid();
}

void CPolCounterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPolCounterDoc* CPolCounterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolCounterDoc)));
	return (CPolCounterDoc*)m_pDocument;
}
#endif //_DEBUG


// CPolCounterView message handlers


void CPolCounterView::OnActionPoll()
{
	CPollDlg dlgPoll;


	if (dlgPoll.DoModal() == IDOK) 
	{
		if (dlgPoll.m_pollOptions == JOIN_POLL_YES)
		{
			if (dlgPoll.m_likesCatsDdogs == LIKES_CATS)
			{
				++m_catCount;
			}
			else
			{
				++m_dogCount;
			}
			Invalidate();
			UpdateWindow();

		}

	}
}
