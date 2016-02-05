// PopWnd.cpp : implementation file
//

#include "stdafx.h"
#include "PopWnd.h"


// PopWnd

IMPLEMENT_DYNAMIC(PopWnd, CWnd)

PopWnd::PopWnd()
{
	w_ = 1024;
	h_ = 768;

	o_ = CPoint(0,0);

	bEnableDraggingWnd =TRUE;

}

PopWnd::~PopWnd()
{
	
}


BEGIN_MESSAGE_MAP(PopWnd, CWnd)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()



void PopWnd::Create(int width, int height, CPoint offset, COLORREF bgColor)
{
	LPCSTR strClass = AfxRegisterWndClass(CS_DBLCLKS,
                                     ::LoadCursor(NULL,IDC_ARROW),
                                     (HBRUSH)GetStockObject(WHITE_BRUSH));//AfxGetApp()->LoadIcon(IDR_MAINFRAME)
	
	CREATESTRUCT	cs={0,};
	CPoint sz;
	
	o_ = offset;
	w_ = width;
	h_ = height;

	bgColor_	= bgColor;

	OutputDebugString("void PopWnd::Create() ");


	CreateEx( WS_EX_APPWINDOW , strClass,NULL, 
			  WS_POPUP| WS_VISIBLE|WS_SYSMENU,//|WS_CAPTION ,
			  o_.x,o_.y,w_,h_, NULL, 0, &cs);	
	
	mFont.CreatePointFont(80, _T("MS Shell Dlg"));
	
	SetWindowPos(this,  o_.x,o_.y,w_,h_, SWP_NOSIZE|SWP_NOMOVE);
	
}


void PopWnd::MoveWindowPosAbs(int x, int y)
{

	o_.x = x;
	o_.y = y;
 
	MoveWindow(o_.x,o_.y,w_,h_);
}

void PopWnd::MoveWindowPos(int dx, int dy)
{

	o_.x += dx;
	o_.y += dy;
 
	MoveWindow(o_.x,o_.y,w_,h_);

}

void PopWnd::SetAlwaysTop(BOOL bTop)
{

	if(bTop)
		SetWindowPos(&wndTopMost,  o_.x,o_.y,w_,h_, SWP_NOSIZE|SWP_NOMOVE);

	else
		SetWindowPos(this,  o_.x,o_.y,w_,h_, SWP_NOSIZE|SWP_NOMOVE);

}
// PopWnd message handlers


void PopWnd::OnDestroy()
{
	CWnd::OnDestroy();

	if(mFont.m_hObject)
		mFont.DeleteObject();

	OnDestroyWnd();

	OutputDebugString("void PopWnd::OnDestroy()");

}

int PopWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	OnInit();

	return 0;
}

BOOL PopWnd::OnEraseBkgnd(CDC* pDC)
{
	
	CBrush brush;
	brush.CreateSolidBrush(bgColor_ );// 

	pDC->FillRect(CRect(0,0,w_,h_) , &brush);  
	brush.DeleteObject();

	OnDraw2(pDC);

	return 0;
	//return CWnd::OnEraseBkgnd(pDC);
}
void PopWnd::EnableDragging(BOOL b)
{
	bEnableDraggingWnd = b;
}
void PopWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(bEnableDraggingWnd)
	PostMessage(	WM_NCLBUTTONDOWN, HTCAPTION, 
					MAKELPARAM( point.x, point.y));


	CWnd::OnLButtonDown(nFlags, point);
}

void PopWnd::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
	{
		Run();
	}
	CWnd::OnTimer(nIDEvent);
}
