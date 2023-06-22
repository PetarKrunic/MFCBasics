
// SliderCtrlView.h : interface of the CSliderCtrlView class
//

#pragma once


class CSliderCtrlView : public CView
{
protected: // create from serialization only
	CSliderCtrlView() noexcept;
	DECLARE_DYNCREATE(CSliderCtrlView)

// Attributes
public:
	CSliderCtrlDoc* GetDocument() const;

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
	virtual ~CSliderCtrlView();
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
	int red{ 255 }, green{ 255 }, blue{ 255 };
};

#ifndef _DEBUG  // debug version in SliderCtrlView.cpp
inline CSliderCtrlDoc* CSliderCtrlView::GetDocument() const
   { return reinterpret_cast<CSliderCtrlDoc*>(m_pDocument); }
#endif

