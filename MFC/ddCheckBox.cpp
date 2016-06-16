// ddCheckBox.cpp : implementation file
//

#include "stdafx.h"
#include "ddCheckBox.h"


// ddCheckBox

IMPLEMENT_DYNAMIC(ddCheckBox, CButton)

ddCheckBox::ddCheckBox()
{

}

ddCheckBox::~ddCheckBox()
{
	m_font.DeleteObject();
}


BOOL ddCheckBox::Create( CString str,DWORD dw,CRect rect,CWnd *p,UINT n)
{

	DWORD dw_ = BS_AUTOCHECKBOX | dw;

	

	return CButton::Create( str, dw_,rect,p,n);//|ES_WANTRETURN|ES_MULTILINE|ES_AUTOVSCROLL
}


BEGIN_MESSAGE_MAP(ddCheckBox, CButton)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// ddCheckBox message handlers



UINT ddCheckBox::WhoAmI()
{
	return this->GetDlgCtrlID();
}

int ddCheckBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CButton::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_font.CreatePointFont( 90,"Tahoma");
	SetFont(&m_font);

	return 0;
}
