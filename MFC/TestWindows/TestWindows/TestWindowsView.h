
// TestWindowsView.h : interface of the CTestWindowsView class
//

#pragma once

#include "resource.h"
#include "afxwin.h"
#include "ddStatic.h"

class CTestWindowsView : public CFormView
{
protected: // create from serialization only
	CTestWindowsView();
	DECLARE_DYNCREATE(CTestWindowsView)

public:
	enum{ IDD = IDD_TESTWINDOWS_FORM };

// Attributes
public:
	CTestWindowsDoc* GetDocument() const;

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
	virtual ~CTestWindowsView();
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
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	ddStatic m_info1;
};

#ifndef _DEBUG  // debug version in TestWindowsView.cpp
inline CTestWindowsDoc* CTestWindowsView::GetDocument() const
   { return reinterpret_cast<CTestWindowsDoc*>(m_pDocument); }
#endif

