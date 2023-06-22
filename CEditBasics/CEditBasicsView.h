
// CEditBasicsView.h : interface of the CCEditBasicsView class
//

#pragma once


class CCEditBasicsView : public CView
{
protected: // create from serialization only
	CCEditBasicsView() noexcept;
	DECLARE_DYNCREATE(CCEditBasicsView)

// Attributes
public:
	CCEditBasicsDoc* GetDocument() const;

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
	virtual ~CCEditBasicsView();
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
private:
	CString m_name;
	int m_age{0};
	double m_height{0.0};
	int m_id{0};
	CString m_info;
};

#ifndef _DEBUG  // debug version in CEditBasicsView.cpp
inline CCEditBasicsDoc* CCEditBasicsView::GetDocument() const
   { return reinterpret_cast<CCEditBasicsDoc*>(m_pDocument); }
#endif

