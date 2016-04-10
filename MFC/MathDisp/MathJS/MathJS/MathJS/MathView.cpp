// MathView.cpp : implementation file
//

#include "stdafx.h"
#include "MathJS.h"
#include "MathView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MathView

IMPLEMENT_DYNCREATE(MathView, CHtmlView)

MathView::MathView()
{
	//{{AFX_DATA_INIT(MathView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

MathView::~MathView()
{
}

void MathView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MathView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MathView, CHtmlView)
	//{{AFX_MSG_MAP(MathView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MathView diagnostics

#ifdef _DEBUG
void MathView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void MathView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// MathView message handlers

void MathView::OnDownloadComplete() 
{
	// TODO: Add your specialized code here and/or call the base class
	

	m_js.SetWeb(this);


	CHtmlView::OnDownloadComplete();
}
