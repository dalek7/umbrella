// ddListBox.cpp : implementation file
//

#include "stdafx.h"

#include "ddListBox.h"


// ddListBox

IMPLEMENT_DYNAMIC(ddListBox, CListBox)

ddListBox::ddListBox()
{

}

ddListBox::~ddListBox()
{
}


void ddListBox::dbg(LPCTSTR lpFmt,... )
{
	va_list	marker;
	va_start( marker,lpFmt );
	char text[1000]={0,};
	
	vsprintf( text,lpFmt,marker);
	va_end( marker );

	CString ret(text);

	this->AddString(ret);
	//.AddString(ret);
	//m_listbox.SetCurSel(m_listbox.GetCount()-1);
}

void ddListBox::SelectLastItem()
{
	this->SetCurSel(this->GetCount()-1);
}

UINT ddListBox::WhoAmI()
{
	return this->GetDlgCtrlID();
}
BEGIN_MESSAGE_MAP(ddListBox, CListBox)
END_MESSAGE_MAP()



// ddListBox message handlers


