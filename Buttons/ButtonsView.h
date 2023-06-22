
// ButtonsView.h : interface of the CButtonsView class
//

#pragma once

constexpr UINT IDC_BUTTON1 {101};

class CButtonsView : public CView
{
protected: // create from serialization only
	CButtonsView() noexcept;
	DECLARE_DYNCREATE(CButtonsView)

// Attributes
public:
	CButtonsDoc* GetDocument() const;

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
	virtual ~CButtonsView();
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
	afx_msg void OnButton1Clicked();
	DECLARE_MESSAGE_MAP()
private:
	CButton m_button;
	bool m_redBackColor{ false };
	bool m_followMouse{ false };
	void MoveButton(CPoint point, bool buttonCoord = false);
	friend LRESULT CALLBACK ButtonProcedure(HWND hWnd, UINT uMsg, WPARAM wParam,
		LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);
	
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnButtonMove();
};

#ifndef _DEBUG  // debug version in ButtonsView.cpp
inline CButtonsDoc* CButtonsView::GetDocument() const
   { return reinterpret_cast<CButtonsDoc*>(m_pDocument); }
#endif

