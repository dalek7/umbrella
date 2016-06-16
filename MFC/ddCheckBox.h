#pragma once


// ddCheckBox

class ddCheckBox : public CButton
{
	DECLARE_DYNAMIC(ddCheckBox)

public:
	ddCheckBox();
	virtual ~ddCheckBox();


	BOOL Create(CString str, DWORD dw,CRect rect,CWnd *p,UINT n);
	
public:
	UINT WhoAmI();


protected:
	CFont	m_font;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


