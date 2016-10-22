// TCPClientDoc.cpp : implementation of the CTCPClientDoc class
//

#include "stdafx.h"
#include "TCPClient.h"

#include "TCPClientDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDoc

IMPLEMENT_DYNCREATE(CTCPClientDoc, CDocument)

BEGIN_MESSAGE_MAP(CTCPClientDoc, CDocument)
	//{{AFX_MSG_MAP(CTCPClientDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDoc construction/destruction

CTCPClientDoc::CTCPClientDoc()
{
	// TODO: add one-time construction code here

}

CTCPClientDoc::~CTCPClientDoc()
{
}

BOOL CTCPClientDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTCPClientDoc serialization

void CTCPClientDoc::Serialize(CArchive& ar)
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
// CTCPClientDoc diagnostics

#ifdef _DEBUG
void CTCPClientDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTCPClientDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDoc commands
