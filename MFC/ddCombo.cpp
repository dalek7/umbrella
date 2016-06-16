// ddCombo.cpp : implementation file
//

#include "stdafx.h"
#include "ddCombo.h"


// ddCombo

IMPLEMENT_DYNAMIC(ddCombo, CComboBox)

ddCombo::ddCombo()
{

}

ddCombo::~ddCombo()
{
	m_font.DeleteObject();
}



BOOL ddCombo::Create( CRect rect,CWnd *p,UINT n)
{
	return CComboBox::Create( WS_VISIBLE|WS_CHILD|CBS_DROPDOWN, rect,p,n);//|ES_WANTRETURN|ES_MULTILINE|ES_AUTOVSCROLL
}


BOOL ddCombo::Create( DWORD dw,CRect rect,CWnd *p,UINT n)
{
	return CComboBox::Create( dw|CBS_DROPDOWN,rect,p,n);//|ES_WANTRETURN|ES_MULTILINE|ES_AUTOVSCROLL
}


BOOL ddCombo::CreateWithRegularSize(CPoint o, CWnd *p,UINT n)
{
	CRect rect = CRect(0,0,75,100);

	return CComboBox::Create( WS_VISIBLE|WS_CHILD|CBS_DROPDOWN, rect+o,p,n);
}



BEGIN_MESSAGE_MAP(ddCombo, CComboBox)
	ON_WM_CREATE()	
END_MESSAGE_MAP()




int ddCombo::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	int ret = CComboBox::OnCreate(lpCreateStruct);

	m_font.CreatePointFont( 90,"Tahoma");
	SetFont(&m_font);
	
	return ret;
}



void ddCombo::SelectLastItem()
{
	this->SetCurSel(this->GetCount()-1);
}

UINT ddCombo::WhoAmI()
{
	return this->GetDlgCtrlID();
}
