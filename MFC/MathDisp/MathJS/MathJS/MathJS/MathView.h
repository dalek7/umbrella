#if !defined(AFX_MATHVIEW_H__EB11ADA8_011E_456C_8DE9_34983A5A6BE9__INCLUDED_)
#define AFX_MATHVIEW_H__EB11ADA8_011E_456C_8DE9_34983A5A6BE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MathView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MathView html view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif
#include <afxhtml.h>


#include "../lib/webscript.h"

class MathView : public CHtmlView
{
public:
	MathView();           // protected constructor used by dynamic creation
	virtual ~MathView();
	DECLARE_DYNCREATE(MathView)

// html Data
public:
	//{{AFX_DATA(MathView)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

	CWebScript m_js;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MathView)
	public:
	virtual void OnDownloadComplete();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(MathView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATHVIEW_H__EB11ADA8_011E_456C_8DE9_34983A5A6BE9__INCLUDED_)
