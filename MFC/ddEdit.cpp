// ddEdit.cpp : implementation file
//

#include "stdafx.h"

#include "ddEdit.h"


// ddEdit

IMPLEMENT_DYNAMIC(ddEdit, CEdit)

ddEdit::ddEdit()
{

	nInc = 1.0;
}

ddEdit::~ddEdit()
{
	m_font.DeleteObject();
}


BOOL ddEdit::Create( DWORD dw,CRect rect,CWnd *p,UINT n)
{
	return CEdit::Create( dw,rect,p,n);//|ES_WANTRETURN|ES_MULTILINE|ES_AUTOVSCROLL
}


CString ddEdit::GetBuffer()
{
	CString buf;
	this->GetWindowTextA(buf);
	return buf;
}


float ddEdit::GetValuef()
{
	CString buf;
	this->GetWindowTextA(buf);
	return atof(buf);
}

void ddEdit::SetValuef(float v)
{
	CString buf;
	buf.Format("%.2f", v);
	
	this->SetWindowTextA(buf);
}


void ddEdit::SetValued(int v)
{
	CString buf;
	buf.Format("%d", v);
	
	this->SetWindowTextA(buf);
}


int ddEdit::GetValued()
{
	CString buf;
	this->GetWindowTextA(buf);
	return atoi(buf);
}



int ddEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	int ret = CEdit::OnCreate(lpCreateStruct);

	m_font.CreatePointFont( 90,"Tahoma");
	SetFont(&m_font);
	
	return ret;
}



void ddEdit::dbg(LPCTSTR lpFmt,... )
{
	va_list	marker;
	va_start( marker,lpFmt );
	char text[1000]={0,};
	
	vsprintf( text,lpFmt,marker);
	va_end( marker );

	CString ret(text);

	this->SetWindowTextA(ret);
	
	//.AddString(ret);
	//m_listbox.SetCurSel(m_listbox.GetCount()-1);
}

void ddEdit::SetInc(float v)
{
	nInc = v;
}

BOOL ddEdit::PreTranslateMessage(MSG* pMsg) 
{

	if(pMsg->message==WM_KEYDOWN)
	{
		if(pMsg->wParam==VK_RETURN )
		{

			/*
			CString buf;
			this->GetWindowTextA(buf);
			this->SetWindowTextA(buf);
			*/
			return 1;
		}
		else if(pMsg->wParam==VK_UP)
		{
			CString buf;
			this->GetWindowTextA(buf);
			if(IsNumber(buf))
			{
				float v = this->GetValuef();
				v = v+nInc;
				this->SetValuef(v);
			}
		}
		else if(pMsg->wParam==VK_DOWN)
		{

			CString buf;
			this->GetWindowTextA(buf);
			if(IsNumber(buf))
			{
				float v = this->GetValuef();
				v = v-nInc;
				this->SetValuef(v);
			}
		}

	}

	
	
	return 0;

	//return CEdit::PreTranslateMessage(pMsg);
}



BOOL ddEdit::IsEmpty()
{
	CString buf;
	this->GetWindowTextA(buf);
	if(buf.GetLength() ==0)
		return TRUE;
	else
		return FALSE;

}


int ddEdit::IsNumber(CString buf)
{
	char *str = buf.GetBuffer(buf.GetLength());
	int withDecimal =0,isNegative=0 ,i=0;
	int len = strlen(str);

	for (i=0; i<len; i++)
	{
		if (!isdigit(str[i])) // if1
		{
			if (str[i] == '.')
			{
				if(withDecimal){
					return 0;
				}
				withDecimal =1;
			}
			else if (str[i] == '-')
			{
				if(isNegative){
					return 0;
				}

				if(i==0){
					isNegative = 1;
				}else{
					return 0;
				}

			}else{
				return 0;
			}
		} //end if1
	}// end for
	return 1;
}

BEGIN_MESSAGE_MAP(ddEdit, CEdit)
	ON_WM_CREATE()	
END_MESSAGE_MAP()



// ddEdit message handlers


