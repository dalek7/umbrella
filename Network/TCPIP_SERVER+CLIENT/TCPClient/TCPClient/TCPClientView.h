// TCPClientView.h : interface of the CTCPClientView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPCLIENTVIEW_H__15B4AE3B_0067_4823_AA85_FE2E2C24DE6A__INCLUDED_)
#define AFX_TCPCLIENTVIEW_H__15B4AE3B_0067_4823_AA85_FE2E2C24DE6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../lib/ddEdit.h"
#include "../lib/CMDEdit.h"
#include "ClientSocket.h"


class CTCPClientView : public CFormView
{
protected: // create from serialization only
	CTCPClientView();
	DECLARE_DYNCREATE(CTCPClientView)

public:
	//{{AFX_DATA(CTCPClientView)
	enum { IDD = IDD_TCPCLIENT_FORM };
	CButton	m_btn_connect;
	CButton	m_btn_send;
	CCMDEdit	m_disp;
	ddEdit	m_text2send;
	ddEdit	m_port;
	ddEdit	m_addr;
	//}}AFX_DATA

// Attributes
public:
	CTCPClientDoc* GetDocument();


	CClientSocket m_client;

	void AddRecvData(char*);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPClientView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTCPClientView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTCPClientView)
	afx_msg void OnSend();
	afx_msg void OnConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TCPClientView.cpp
inline CTCPClientDoc* CTCPClientView::GetDocument()
   { return (CTCPClientDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPCLIENTVIEW_H__15B4AE3B_0067_4823_AA85_FE2E2C24DE6A__INCLUDED_)
