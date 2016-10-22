// CMDEdit.cpp : implementation file
//

#include "stdafx.h"
#include "CMDEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCMDEdit
#define MAXBUF	2000

CCMDEdit::CCMDEdit()
{
	col	= 1;
	row	= 1;
	nHistory= 0;
	nHistoryView	= 0;

	bAutoReset	= FALSE;
}


CCMDEdit::~CCMDEdit()
{
	m_font.DeleteObject();
}


BEGIN_MESSAGE_MAP(CCMDEdit, CRichEditCtrl)
	//{{AFX_MSG_MAP(CCMDEdit)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()	
	ON_WM_LBUTTONDOWN()
	ON_WM_SETFOCUS()	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCMDEdit message handlers


CString CCMDEdit::RetHistory( int n)
{
	if ( n>=MAXHISTORY )	n=0;
	if ( n<0)
	{
		n = MAXHISTORY-1;
		nHistoryView	= n;
		while(history[n].IsEmpty())
		{
			n--;
			nHistoryView	= n;
			if ( n<0)	break;
		}		
	}

	if ( n<0 )	return CString("");
	return history[ n ];
}

void CCMDEdit::InHistory( CString it )
{
	if ( !it.IsEmpty())
	{
		it.Remove('\n');
		history[nHistory].Empty();
		history[nHistory++]=	it;
		if ( nHistory>=MAXHISTORY)	nHistory	= 0;
	}
}

int CCMDEdit::LineWidth(int n)
{
	char buf[MAXBUF]={0,};
	GetLine(n,buf,MAXBUF);
	
	return strlen(buf)+1;
}

void CCMDEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	int n = LineIndex(-1);
	n = LineFromChar(n)+1;
	if ( n!=row )
	{
		CString stb;
		GetWindowText(stb);
		SetSel(stb.GetLength(),stb.GetLength());
	}

	BOOL	b= TRUE;
	char buf[MAXBUF]={0,};

	switch( nChar ){
	case VK_RETURN		:	if ( GetLine(row-1,buf,MAXBUF )==0) buf[0] = 0;								
							stCurrent	= CString(buf).Left(col-1);
							row++;	
							col	= 1;								
							InHistory( stCurrent);	
							break;
	
	case 8				:	col--;
							if ( col<=0)	
							{
								col	= 1;
								b	= FALSE;
							}
							break;
								
	default:				col++;
							nHistoryView	= nHistory;		
							break;
	}


	if ( b )
		CRichEditCtrl::OnChar(nChar, nRepCnt, nFlags);

	CString st;
	st.Format( "%d,%d",row,col );	
	if ( m_static.GetSafeHwnd())	m_static.SetWindowText(st);
}

void CCMDEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	BOOL	b= TRUE;
	UINT	width	= LineWidth(row-1);
	CString buf;
	CString hbuf;
	
	switch( nChar ){
	case 8				:	if ( col==1 )	b	= FALSE;
							break;
	case VK_LEFT		:	col--;
							if ( col<=0)	
							{
								col	= 1;
								b	= FALSE;
							}
							break;
	case VK_RIGHT		:	col++;
							if	( width<col )
								col	= width;
							break;

	case VK_UP			:	GetWindowText(buf);
							hbuf	= RetHistory(--nHistoryView);							
							col	= hbuf.GetLength()+1;
							SetSel( buf.ReverseFind('\n')+1,buf.GetLength() );
							ReplaceSel( hbuf );
							b	= FALSE;
							break;

	case VK_END			:	col	= width;
							break;							
							
	case VK_HOME		:	col	= 1;
							break;
						
	}

	if (b)	
	CRichEditCtrl::OnKeyDown(nChar, nRepCnt, nFlags);

	CString st;
	st.Format( "%d,%d",row,col );	
	if ( m_static.GetSafeHwnd() )	m_static.SetWindowText(st);
}

int CCMDEdit::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	int ret = CRichEditCtrl::OnCreate(lpCreateStruct);

	// TODO: Add your specialized creation code here
	m_static.Create( "",WS_CHILD|WS_VISIBLE,CRect(0,180,200,200),this,-1);
	m_static.ShowWindow(SW_HIDE);	

	m_font.CreatePointFont( 90,"Tahoma");
	SetFont(&m_font);
	
	return ret;
}


void CCMDEdit::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CRichEditCtrl::OnLButtonDown(nFlags,point);	
}


void CCMDEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CRichEditCtrl::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here	CEdit
}

void CCMDEdit::PutLine(LPCTSTR lpFmt,...)
{
	va_list	marker;
	va_start( marker,lpFmt );
	char text[1000]={0,};
	
	wvsprintf( text,lpFmt,marker);
	va_end( marker );
	
	CCMDEdit::PutLine(CString(text));
}

void CCMDEdit::PutLine( CString it ,BOOL bReturn)
{
	CString buf;
	int		nEOL	= 0;
	int i,j;
	BYTE	*pBuf	= (BYTE*) it.operator LPCTSTR();
	BYTE	old		= 0;

	// purify
	for (  i=0,j;i<it.GetLength();i++)
	{
		if ( old=='\n' && pBuf[i]=='\r')
		{
			pBuf[i]='\r';
			pBuf[i]='\n';
		}
	}

	// count eol w/o line feed.
	old	= 0;
	for ( i=0;i<it.GetLength();i++)
	{
		if ( old!='\r' && pBuf[i]=='\n' )	nEOL++;	
		old	= pBuf[i];
	}
	
	// reallocate the buf with line feed ch.
	buf.GetBuffer( it.GetLength()+nEOL+2 );
	BYTE	*pTarget= (BYTE*) buf.operator LPCTSTR();

	// copy
	old	= 0;
	for ( i=0,j=0;i<it.GetLength();i++)
	{
		if ( old!='\r' && pBuf[i]=='\n' )	
		{
			pTarget[j++]	= '\r';
			pTarget[j++]	= '\n';
		}
		else	pTarget[j++]	= pBuf[i];
		old	= pBuf[i];
	}

	if ( bReturn)
	{
		pTarget[j++]	= '\r';
		pTarget[j++]	= '\n';
	}
	pTarget[j] = 0;

	nEOL	= 0;
	for ( i=0;i<it.GetLength();i++)
		if ( pBuf[i]=='\n' )	nEOL++;

	ReplaceSel( buf );
	row+=nEOL;

	if (bReturn)	row++,col=1;
	else			col+=strlen(buf);

	stInput	= it;

	if (bAutoReset)
	{
		/*
		if ( row> nAutoReset )
		{
			col	= row	= 1;
			SetWindowText("");
		}
		*/

		if ( row>=nAutoReset )
		{
			CString buf;
			GetWindowText(buf);

			for(int i=0;i<buf.GetLength();i++)
			{
				char ch = buf[i];
				if ( ch ==10 )
				{
					buf	= buf.Right( buf.GetLength()-i-1);
					SetWindowText( buf);	
					row	= nAutoReset-1;
					SetSel( buf.GetLength(),buf.GetLength());
					break;
				}
			}	
		}
	}


}

void CCMDEdit::PutBlock( CString it )
{
	CString buf;
	int		nEOL	= 0;
	int i, j;
	BYTE	*pBuf	= (BYTE*) it.operator LPCTSTR();
	BYTE	old		= 0;

	// purify
	for (  i=0,j;i<it.GetLength();i++)
	{
		if ( old=='\n' && pBuf[i]=='\r')
		{
			pBuf[i]='\r';
			pBuf[i]='\n';
		}
	}

	// count eol w/o line feed.
	old	= 0;
	for ( i=0;i<it.GetLength();i++)
	{
		if ( old!='\r' && pBuf[i]=='\n' )	nEOL++;	
		old	= pBuf[i];
	}
	
	// reallocate the buf with line feed ch.
	buf.GetBuffer( it.GetLength()+nEOL );
	BYTE	*pTarget= (BYTE*) buf.operator LPCTSTR();

	// copy
	old	= 0;
	for ( i=0,j=0;i<it.GetLength();i++)
	{
		if ( old!='\r' && pBuf[i]=='\n' )	
		{
			pTarget[j++]	= '\r';
			pTarget[j++]	= '\n';
		}
		else	pTarget[j++]	= pBuf[i];
		old	= pBuf[i];
	}

	nEOL	= 0;
	for ( i=0;i<it.GetLength();i++)
		if ( pBuf[i]=='\n' )	nEOL++;

	ReplaceSel( buf );
	col+=it.GetLength(); 
	if ( nEOL>0 )	SendMessage( WM_CHAR,13,0);
	

	stInput	= it;
}

BOOL CCMDEdit::Create( DWORD dw,CRect rect,CWnd *p,UINT n)
{
	return CRichEditCtrl::Create( dw|ES_WANTRETURN|ES_MULTILINE|ES_AUTOVSCROLL,rect,p,n);
}

void CCMDEdit::SetReset(int n)
{
	bAutoReset	= TRUE;
	nAutoReset	= n;
}

void CCMDEdit::Return()
{
	this->SendMessage( WM_CHAR,13,0);
}

void CCMDEdit::Reset()
{
	col	= 1;
	row	= 1;
	SetWindowText(CString(""));
	SetSel(-1,-1);
}

int logfont2charfont( LONG lfHeight,CWnd *pWnd )
{
	CClientDC	dc(pWnd);
	int twipy  = MulDiv( -lfHeight,72*20,GetDeviceCaps(dc,LOGPIXELSY ) );

	return twipy;
}	


void CCMDEdit::ChangeCF( CString stFont, int nY )
{
	CHARRANGE	ch;
	GetSel( ch );
	
	CHARFORMAT	cf; 
	GetSelectionCharFormat(cf);
	
	strcpy( cf.szFaceName,stFont );
	cf.yHeight	= logfont2charfont(-nY,this);
	SetWordCharFormat(cf);
	
}

void CCMDEdit::ChangeCF( CString stFont)
{
	CHARRANGE	ch;
	GetSel( ch );
	
	CHARFORMAT	cf; 
	GetSelectionCharFormat(cf);
	
	strcpy( cf.szFaceName,stFont );
	SetWordCharFormat(cf);
}