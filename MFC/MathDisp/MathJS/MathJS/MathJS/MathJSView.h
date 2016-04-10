// MathJSView.h : interface of the CMathJSView class
// written by Seung-Chan Kim @ KAIST
// December 12, 2011
// VS6 Project for testing MathJS script in the MFC environment.
// See screenshot?.png for details.
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATHJSVIEW_H__BA82D470_0826_4446_BFF5_CF26B401FC5C__INCLUDED_)
#define AFX_MATHJSVIEW_H__BA82D470_0826_4446_BFF5_CF26B401FC5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MathView.h"
#include "../lib/FileProc.h"

//http://robot.kaist.ac.kr/~kimsc/test/math2.html
class CMathJSView : public CFormView
{
protected: // create from serialization only
	CMathJSView();
	DECLARE_DYNCREATE(CMathJSView)

public:
	//{{AFX_DATA(CMathJSView)
	enum { IDD = IDD_MATHJS_FORM };
	CEdit	m_arg1;
	//}}AFX_DATA

// Attributes
public:
	CMathJSDoc* GetDocument();

	MathView *pMmathView;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMathJSView)
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
	virtual ~CMathJSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMathJSView)
	afx_msg void OnUpdateParam();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MathJSView.cpp
inline CMathJSDoc* CMathJSView::GetDocument()
   { return (CMathJSDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATHJSVIEW_H__BA82D470_0826_4446_BFF5_CF26B401FC5C__INCLUDED_)
