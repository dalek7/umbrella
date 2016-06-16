// ddButton.cpp : implementation file
//

#include "stdafx.h"
#include "ddButton.h"


// ddButton

IMPLEMENT_DYNAMIC(ddButton, CButton)

ddButton::ddButton()
{

}

ddButton::~ddButton()
{
	m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(ddButton, CButton)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// ddButton message handlers


BOOL ddButton::Create(CString title, DWORD dw,CPoint o,CWnd *p,UINT n)
{
	CRect rc = CRect(0,0,50,30) +o;

	return CButton::Create(title, dw,rc,p,n);//|ES_WANTRETURN|ES_MULTILINE|ES_AUTOVSCROLL
}




BOOL ddButton::Create(CString title, DWORD dw,CRect rect,CWnd *p,UINT n)
{



	return CButton::Create(title, dw,rect,p,n);//|ES_WANTRETURN|ES_MULTILINE|ES_AUTOVSCROLL
}



int ddButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_font.CreatePointFont( 90,"Tahoma");
	SetFont(&m_font);

	return 0;
}
