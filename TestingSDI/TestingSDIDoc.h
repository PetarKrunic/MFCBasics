
// TestingSDIDoc.h : interface of the CTestingSDIDoc class
//


#pragma once


class CTestingSDIDoc : public CDocument
{
protected: // create from serialization only
	CTestingSDIDoc() noexcept;
	DECLARE_DYNCREATE(CTestingSDIDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	CString GetText() { return m_text; }
	virtual ~CTestingSDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnDrawSettext();
private:
	CString m_text;
};
