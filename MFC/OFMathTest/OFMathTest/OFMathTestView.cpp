
// OFMathTestView.cpp : implementation of the COFMathTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OFMathTest.h"
#endif

#include "OFMathTestDoc.h"
#include "OFMathTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COFMathTestView

IMPLEMENT_DYNCREATE(COFMathTestView, CFormView)

BEGIN_MESSAGE_MAP(COFMathTestView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// COFMathTestView construction/destruction

COFMathTestView::COFMathTestView()
	: CFormView(COFMathTestView::IDD)
{
	// TODO: add construction code here

}

COFMathTestView::~COFMathTestView()
{
}

void COFMathTestView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL COFMathTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void COFMathTestView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();




	ofVec3f v1;
	v1.x = 1;
	v1.y = 1;
	v1.z = 1;

}

void COFMathTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COFMathTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COFMathTestView diagnostics

#ifdef _DEBUG
void COFMathTestView::AssertValid() const
{
	CFormView::AssertValid();
}

void COFMathTestView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

COFMathTestDoc* COFMathTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COFMathTestDoc)));
	return (COFMathTestDoc*)m_pDocument;
}
#endif //_DEBUG


// COFMathTestView message handlers
