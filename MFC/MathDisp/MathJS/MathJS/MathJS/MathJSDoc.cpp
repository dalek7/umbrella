// MathJSDoc.cpp : implementation of the CMathJSDoc class
//

#include "stdafx.h"
#include "MathJS.h"

#include "MathJSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMathJSDoc

IMPLEMENT_DYNCREATE(CMathJSDoc, CDocument)

BEGIN_MESSAGE_MAP(CMathJSDoc, CDocument)
	//{{AFX_MSG_MAP(CMathJSDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMathJSDoc construction/destruction

CMathJSDoc::CMathJSDoc()
{
	// TODO: add one-time construction code here

}

CMathJSDoc::~CMathJSDoc()
{
}

BOOL CMathJSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMathJSDoc serialization

void CMathJSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMathJSDoc diagnostics

#ifdef _DEBUG
void CMathJSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMathJSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMathJSDoc commands
