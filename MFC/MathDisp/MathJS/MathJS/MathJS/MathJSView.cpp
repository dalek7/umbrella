// MathJSView.cpp : implementation of the CMathJSView class
//

#include "stdafx.h"
#include "MathJS.h"

#include "MathJSDoc.h"
#include "MathJSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMathJSView

IMPLEMENT_DYNCREATE(CMathJSView, CFormView)

BEGIN_MESSAGE_MAP(CMathJSView, CFormView)
	//{{AFX_MSG_MAP(CMathJSView)
	ON_BN_CLICKED(IDC_BUTTON1, OnUpdateParam)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMathJSView construction/destruction

CMathJSView::CMathJSView()
	: CFormView(CMathJSView::IDD)
{
	//{{AFX_DATA_INIT(CMathJSView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CMathJSView::~CMathJSView()
{
}

void CMathJSView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMathJSView)
	DDX_Control(pDX, IDC_EDIT1, m_arg1);
	//}}AFX_DATA_MAP
}

BOOL CMathJSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMathJSView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


	pMmathView = new MathView;
	pMmathView->Create(NULL, "dd", WS_CHILD|WS_VISIBLE|WS_BORDER, CRect(0,0,400,600), this, 0);
	//pMmathView->Navigate2(_T("http://robot.kaist.ac.kr/~kimsc/test/math2.html"),NULL,NULL);

	//pMmathView->Navigate2(_T("file://C:/work/2011/MathJS/_html/test2.html"),NULL,NULL);

	TCHAR buffer[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, buffer);
	CString buf(buffer);
	buf.Replace("\\", "/");
	
	buf = FileProc::GetPath(buf);
	buf = "file://"+buf+"/_html/test2.html";
	pMmathView->Navigate2(_T(buf),NULL,NULL);


	//pMmathView->Navigate2(_T("file://E:/Study/2011/Projects/MathDIsp/MathJS/MathJS/_html/test2.html"),NULL,NULL);

	
	

	m_arg1.SetWindowText("10");


}

/////////////////////////////////////////////////////////////////////////////
// CMathJSView printing

BOOL CMathJSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMathJSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMathJSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMathJSView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMathJSView diagnostics

#ifdef _DEBUG
void CMathJSView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMathJSView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMathJSDoc* CMathJSView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMathJSDoc)));
	return (CMathJSDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMathJSView message handlers

void CMathJSView::OnUpdateParam() 
{

	CString tmp, buf;
	m_arg1.GetWindowText(tmp);	
	

	//\sqrt{3x-1}+(1+x)^2
	buf.Format("\\sqrt{3x-%s}+(1+x)^2", tmp);
	
	
	pMmathView->m_js.Fire("UpdateMath", buf);

}
