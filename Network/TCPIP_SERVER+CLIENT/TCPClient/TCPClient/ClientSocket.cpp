// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "TCPClient.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "TCPClientDoc.h"
#include "TCPClientView.h"

extern CTCPClientView *pv;


/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{

	
	char ch[1000];
	int br=Receive(ch,1000);
	ch[br]='\0';


	pv->AddRecvData(ch);


	CSocket::OnReceive(nErrorCode);
}
