
// TestingSDIDoc.cpp : implementation of the CTestingSDIDoc class
//

#include "pch.h"
#include "framework.h"
#include "CSetTextDlg.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestingSDI.h"
#endif

#include "TestingSDIDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestingSDIDoc

IMPLEMENT_DYNCREATE(CTestingSDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestingSDIDoc, CDocument)
	ON_COMMAND(ID_DRAW_SETTEXT, &CTestingSDIDoc::OnDrawSettext)
END_MESSAGE_MAP()


// CTestingSDIDoc construction/destruction

CTestingSDIDoc::CTestingSDIDoc() noexcept
{
	// TODO: add one-time construction code here

}

CTestingSDIDoc::~CTestingSDIDoc()
{
}

BOOL CTestingSDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_text.Empty();

	return TRUE;
}




// CTestingSDIDoc serialization

void CTestingSDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_text;
		SetModifiedFlag(FALSE);
	}
	else
	{
		ar >> m_text;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTestingSDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CTestingSDIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTestingSDIDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTestingSDIDoc diagnostics

#ifdef _DEBUG
void CTestingSDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestingSDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTestingSDIDoc commands


void CTestingSDIDoc::OnDrawSettext()
{
	CSetTextDlg dlgSetText;
	dlgSetText.m_text = m_text;

	if (dlgSetText.DoModal() == IDOK) 
	{
		m_text = dlgSetText.m_text;
		UpdateAllViews(NULL);
		SetModifiedFlag(TRUE);
	}
}
