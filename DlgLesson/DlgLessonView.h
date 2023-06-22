
// DlgLessonView.h : interface of the CDlgLessonView class
//

#pragma once


class CDlgLessonView : public CView
{
protected: // create from serialization only
	CDlgLessonView() noexcept;
	DECLARE_DYNCREATE(CDlgLessonView)

// Attributes
public:
	CDlgLessonDoc* GetDocument() const;

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
	virtual ~CDlgLessonView();
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
	afx_msg void OnDialogLaunchdialog();
};

#ifndef _DEBUG  // debug version in DlgLessonView.cpp
inline CDlgLessonDoc* CDlgLessonView::GetDocument() const
   { return reinterpret_cast<CDlgLessonDoc*>(m_pDocument); }
#endif

