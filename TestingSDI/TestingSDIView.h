
// TestingSDIView.h : interface of the CTestingSDIView class
//

#pragma once


class CTestingSDIView : public CView
{
protected: // create from serialization only
	CTestingSDIView() noexcept;
	DECLARE_DYNCREATE(CTestingSDIView)

// Attributes
public:
	CTestingSDIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTestingSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawDrawacircle();
private:
	bool m_drawCircle{true}; // if not circle than a rectangle
public:
	afx_msg void OnDrawDrawarectangle();
	afx_msg void OnUpdateDrawDrawacircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDrawDrawarectangle(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // debug version in TestingSDIView.cpp
inline CTestingSDIDoc* CTestingSDIView::GetDocument() const
   { return reinterpret_cast<CTestingSDIDoc*>(m_pDocument); }
#endif

