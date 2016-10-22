#if !defined(AFX_CLIENTSOCKET_H__3C54D52B_FBE7_4608_88DC_C6EE7F01DFF8__INCLUDED_)
#define AFX_CLIENTSOCKET_H__3C54D52B_FBE7_4608_88DC_C6EE7F01DFF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



#include "Afxsock.h"
/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__3C54D52B_FBE7_4608_88DC_C6EE7F01DFF8__INCLUDED_)
