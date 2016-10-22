// TCPClientView.cpp : implementation of the CTCPClientView class
//

#include "stdafx.h"
#include "TCPClient.h"

#include "TCPClientDoc.h"
#include "TCPClientView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CTCPClientView *pv;
/////////////////////////////////////////////////////////////////////////////
// CTCPClientView

IMPLEMENT_DYNCREATE(CTCPClientView, CFormView)

BEGIN_MESSAGE_MAP(CTCPClientView, CFormView)
	//{{AFX_MSG_MAP(CTCPClientView)
	ON_BN_CLICKED(IDC_BUTTON1, OnSend)
	ON_BN_CLICKED(IDC_BUTTON2, OnConnect)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPClientView construction/destruction

CTCPClientView::CTCPClientView()
	: CFormView(CTCPClientView::IDD)
{
	//{{AFX_DATA_INIT(CTCPClientView)
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CTCPClientView::~CTCPClientView()
{
}

void CTCPClientView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPClientView)
	DDX_Control(pDX, IDC_BUTTON2, m_btn_connect);
	DDX_Control(pDX, IDC_BUTTON1, m_btn_send);
	DDX_Control(pDX, IDC_EDIT1, m_disp);
	DDX_Control(pDX, IDC_EDIT2, m_text2send);
	DDX_Control(pDX, IDC_EDIT4, m_port);
	DDX_Control(pDX, IDC_EDIT3, m_addr);
	//}}AFX_DATA_MAP
}

BOOL CTCPClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTCPClientView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	pv = this;

	m_addr.SetWindowText("127.0.0.1");
	m_port.SetWindowText("10000");

	m_btn_send.EnableWindow(FALSE);

}

/////////////////////////////////////////////////////////////////////////////
// CTCPClientView printing

BOOL CTCPClientView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTCPClientView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTCPClientView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTCPClientView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CTCPClientView diagnostics

#ifdef _DEBUG
void CTCPClientView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTCPClientView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTCPClientDoc* CTCPClientView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTCPClientDoc)));
	return (CTCPClientDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTCPClientView message handlers

void CTCPClientView::AddRecvData(char* p)
{
	CString buf;
	buf.Format("%s", p);

	m_disp.PutLine(buf);

}

void CTCPClientView::OnSend() 
{
	
	CString buf = m_text2send.GetBuffer();

	m_client.Send(buf,buf.GetLength());


	
}

void CTCPClientView::OnConnect() 
{
	
	if( AfxSocketInit() == FALSE)
	{ 
		AfxMessageBox("Failed to Initialize Sockets"); 
		return; 
	}

	if(m_client.Create()==FALSE)
	{
		MessageBox("Failed to Create Socket");
		return;

	}

	int port = m_port.GetValued();
	CString ipaddr = m_addr.GetBuffer();

	
	if(m_client.Connect(ipaddr,port)==FALSE)
	{
		MessageBox("Failed to Connect");
		return;

	}
	else
	{
		m_btn_connect.EnableWindow(FALSE);
		m_btn_send.EnableWindow(TRUE);
	}

	

	
	
}
