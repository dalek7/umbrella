#if !defined(AFX_CMDEDIT_H__47CBC7A7_D479_11D3_98D3_004F4E014CDD__INCLUDED_)
#define AFX_CMDEDIT_H__47CBC7A7_D479_11D3_98D3_004F4E014CDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMDEdit.h : header file
//


#if !defined (__CMDEDIT__)
#define __CMDEDIT__

#define MAXHISTORY	5
/////////////////////////////////////////////////////////////////////////////
// CCMDEdit window
#ifdef _WIN32_WCE
class CCMDEdit : public CEdit
#else
class CCMDEdit : public CRichEditCtrl
#endif
{
// Construction
public:
	CCMDEdit();
	
	//
	//queue
	CString history[MAXHISTORY];
	int		nHistory;
	int		nHistoryView;
	CString	RetHistory(int);
	void	InHistory(CString );
	void	PutLine( CString ,BOOL bReturn=TRUE);
	void	PutLine( LPCTSTR lpFmt,... );
	void	PutBlock( CString );
	CString stCurrent;
	void	ChangeCF(CString stFont,int nY);
	void	ChangeCF(CString stFont);

	UINT	col,row;
	int		LineWidth( int );
	void	SetReset(int);
	void	Reset();

	CStatic	m_static;
	CString stInput;

	CFont	m_font;

// Attributes
public:
	BOOL	bAutoReset;
	int		nAutoReset;

// Operations
public:

	virtual BOOL Create( DWORD,CRect,CWnd*,UINT);
	void	Return();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMDEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCMDEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCMDEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);	
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point); 

	DECLARE_MESSAGE_MAP()
};

#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDEDIT_H__47CBC7A7_D479_11D3_98D3_004F4E014CDD__INCLUDED_)


