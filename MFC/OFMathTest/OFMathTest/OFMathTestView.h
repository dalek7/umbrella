
// 2014/05/21
// Seung-Chan Kim at TCL, KAIST
// Using ofMath in a regular MFC application
// OFMathTestView.h : interface of the COFMathTestView class

#pragma once

#include "resource.h"
#include "../lib/ofVectorMath.h"




class COFMathTestView : public CFormView
{
protected: // create from serialization only
	COFMathTestView();
	DECLARE_DYNCREATE(COFMathTestView)

public:
	enum{ IDD = IDD_OFMATHTEST_FORM };

// Attributes
public:
	COFMathTestDoc* GetDocument() const;

// Operations
public:
	

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~COFMathTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OFMathTestView.cpp
inline COFMathTestDoc* COFMathTestView::GetDocument() const
   { return reinterpret_cast<COFMathTestDoc*>(m_pDocument); }
#endif

