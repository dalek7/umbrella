#pragma once


// ddButton
 
class ddButton : public CButton
{
	DECLARE_DYNAMIC(ddButton)

public:
	ddButton();
	virtual ~ddButton();


public:
	BOOL Create(CString title, DWORD dw,CRect rect,CWnd *p,UINT n=65535);
	BOOL Create(CString title, DWORD dw,CPoint o,CWnd *p,UINT n=65535);

private:
	CFont	m_font;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


