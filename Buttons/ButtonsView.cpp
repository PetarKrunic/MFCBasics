
// ButtonsView.cpp : implementation of the CButtonsView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Buttons.h"
#endif

#include "ButtonsDoc.h"
#include "ButtonsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonsView

IMPLEMENT_DYNCREATE(CButtonsView, CView)

BEGIN_MESSAGE_MAP(CButtonsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CButtonsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1Clicked)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BUTTON_MOVE, &CButtonsView::OnButtonMove)
END_MESSAGE_MAP()

// CButtonsView construction/destruction

CButtonsView::CButtonsView() noexcept
{
	// TODO: add construction code here

}

CButtonsView::~CButtonsView()
{
}

BOOL CButtonsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CButtonsView drawing

void CButtonsView::OnDraw(CDC* pDC)
{
	CButtonsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rectClient;
	GetClientRect(rectClient);
	if (m_redBackColor == true) {
		pDC->FillSolidRect(rectClient, RGB(255, 0, 0));
	}
}


// CButtonsView printing


void CButtonsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CButtonsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CButtonsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CButtonsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CButtonsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CButtonsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CButtonsView diagnostics

#ifdef _DEBUG
void CButtonsView::AssertValid() const
{
	CView::AssertValid();
}

void CButtonsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButtonsDoc* CButtonsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonsDoc)));
	return (CButtonsDoc*)m_pDocument;
}
#endif //_DEBUG


LRESULT CALLBACK ButtonProcedure(HWND hWnd, UINT uMsg, WPARAM wParam,
	LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)

{
	CButtonsView* view = reinterpret_cast<CButtonsView*>(dwRefData);
	switch (uMsg)
	{
	case WM_MOUSEMOVE:

		view->MoveButton(CPoint{ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) }, true);
		return TRUE;
		// Other cases...
	}
	return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}


int CButtonsView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_button.Create(_T("To red!"),BS_PUSHBUTTON, CRect(300, 100, 380, 150), this, IDC_BUTTON1);
	SetWindowSubclass(m_button, ButtonProcedure, 0, reinterpret_cast<DWORD_PTR>(this));

	m_button.ShowWindow(SW_SHOW);

	return 0;
}

void CButtonsView :: OnButton1Clicked() 
{
	if (m_followMouse) 
	{
		m_followMouse = false;
	}
	else
	{

		m_redBackColor = !m_redBackColor;
		if (m_redBackColor)
		{
			m_button.SetWindowTextW(L"To white");
		}
		else
		{
			m_button.SetWindowTextW(L"To red");
		}
		Invalidate();
		UpdateWindow();
	}
}


void CButtonsView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_followMouse)
	{
		MoveButton(point);
	}
	CView::OnMouseMove(nFlags, point);
	
}

void CButtonsView::MoveButton(CPoint central, bool buttonCoord) 
{
	if(!m_followMouse)
	{
		return;
	}

	CRect rectButton;
	m_button.GetWindowRect(rectButton);
	ScreenToClient(rectButton);
	if (buttonCoord) 
	{
		central += rectButton.TopLeft();
	}
	m_button.MoveWindow(central.x - rectButton.Width()/2, central.y - rectButton.Height()/2,
		rectButton.Width(), rectButton.Height());

}


void CButtonsView::OnButtonMove()
{
	m_followMouse = true;

	
}
