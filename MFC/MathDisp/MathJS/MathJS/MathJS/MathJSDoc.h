// MathJSDoc.h : interface of the CMathJSDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATHJSDOC_H__D31DA13B_91C0_4102_8614_2D25ED6B5F3B__INCLUDED_)
#define AFX_MATHJSDOC_H__D31DA13B_91C0_4102_8614_2D25ED6B5F3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMathJSDoc : public CDocument
{
protected: // create from serialization only
	CMathJSDoc();
	DECLARE_DYNCREATE(CMathJSDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMathJSDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMathJSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMathJSDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATHJSDOC_H__D31DA13B_91C0_4102_8614_2D25ED6B5F3B__INCLUDED_)
