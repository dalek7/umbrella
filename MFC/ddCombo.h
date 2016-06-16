#pragma once


// ddCombo

class ddCombo : public CComboBox
{
	DECLARE_DYNAMIC(ddCombo)

public:
	ddCombo();
	virtual ~ddCombo();

public:
	BOOL Create( DWORD dw,CRect rect,CWnd *p,UINT n);
	BOOL Create( CRect rect,CWnd *p,UINT n);

	BOOL CreateWithRegularSize(CPoint o, CWnd *p,UINT n);

	void SelectLastItem();
	UINT WhoAmI();



		
protected:
	CFont	m_font;

protected:
	DECLARE_MESSAGE_MAP()
	//{{AFX_MSG(ddEdit)
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);	

	//}}AFX_MSG
};


