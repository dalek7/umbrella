
// TestWindowsView.cpp : implementation of the CTestWindowsView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestWindows.h"
#endif

#include "TestWindowsDoc.h"
#include "TestWindowsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestWindowsView

IMPLEMENT_DYNCREATE(CTestWindowsView, CFormView)

BEGIN_MESSAGE_MAP(CTestWindowsView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestWindowsView::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CTestWindowsView construction/destruction

CTestWindowsView::CTestWindowsView()
	: CFormView(CTestWindowsView::IDD)
{
	// TODO: add construction code here

}

CTestWindowsView::~CTestWindowsView()
{
}

void CTestWindowsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_info1);
}

BOOL CTestWindowsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTestWindowsView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_info1.dbg("Hello");
	SetTimer(0,500,NULL);
}

void CTestWindowsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestWindowsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestWindowsView diagnostics

#ifdef _DEBUG
void CTestWindowsView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTestWindowsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTestWindowsDoc* CTestWindowsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestWindowsDoc)));
	return (CTestWindowsDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestWindowsView message handlers


void CTestWindowsView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	



}
#include <string>

using namespace std;


string GetActiveWindowTitle()
{
	char wnd_title[256];
	HWND hwnd=GetForegroundWindow(); // get handle of currently active window
	GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
	return wnd_title;
}

string GetActiveApplicationName()
{
	char wnd_title[256];
	HWND hwnd=GetForegroundWindow(); // get handle of currently active window
	
	DWORD pid;

	GetWindowThreadProcessId(hwnd, &pid);
	
	HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);//open processusing PROCESS_ALL_ACCESS to get handle
	// if(hProcess!=NULL)


	//GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
	return wnd_title;
}

void CTestWindowsView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==0)
	{
		CWnd *p = GetForegroundWindow();
		if (!p->m_hWnd) 
		{
			return CFormView::OnTimer(nIDEvent);
		}
		std::string a = GetActiveWindowTitle();
		//p = GetActiveWindow();


		CStringA buf;
		//buf.Format("Process: %d", p);
		buf.Format("p->m_hWnd : %d, %s",p->m_hWnd, a.c_str());
		m_info1.dbg(buf);
		OutputDebugString(buf);


	}
	CFormView::OnTimer(nIDEvent);
}


void CTestWindowsView::OnDestroy()
{
	CFormView::OnDestroy();

	KillTimer(0);
	// TODO: Add your message handler code here
}
