
// PolCounterView.h : interface of the CPolCounterView class
//

#pragma once


class CPolCounterView : public CView
{
protected: // create from serialization only
	CPolCounterView() noexcept;
	DECLARE_DYNCREATE(CPolCounterView)

// Attributes
public:
	CPolCounterDoc* GetDocument() const;

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
	virtual ~CPolCounterView();
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
	afx_msg void OnActionPoll();
private:
	int m_catCount{ 0 };
	int m_dogCount{ 0 };
};

#ifndef _DEBUG  // debug version in PolCounterView.cpp
inline CPolCounterDoc* CPolCounterView::GetDocument() const
   { return reinterpret_cast<CPolCounterDoc*>(m_pDocument); }
#endif

