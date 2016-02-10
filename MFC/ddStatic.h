#pragma once


/////////////
/* example
ddStatic m_info1;
m_info1.Create("Hello !", WS_VISIBLE|WS_CHILD, CRect(0,0,100,50)+CPoint(20,20),this,0,200);
*/
/////////////

class ddStatic : public CStatic
{
	DECLARE_DYNAMIC(ddStatic)

public:
	ddStatic();
	virtual ~ddStatic();

	BOOL Create(CString str, DWORD dw,CRect rect,CWnd *p,UINT n, int fontSize = 90);

public:
	void	dbg(LPCTSTR,...);
	BOOL	IsIn(CPoint);
	BOOL	IsIn();
	void	GetCursorPtInObjCoord(CPoint*);
	void	SetFontSize(int sz);
	

public:
	void	SetAsPad(int ms=100);
	void	GetPos(CPoint*);
	int		GetWidth();
	int		GetHeight();
	CPoint	GetOrigin();

public:
	void SetValuef(float v);
	void SetValued(int v);

private:
	void    SetPos();
	int		tcnt;
	CPoint  gpt;
	CFont	m_font;
	int		sz_font;

protected:
	DECLARE_MESSAGE_MAP()
public:

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


