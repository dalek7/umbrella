#pragma once

// PopWnd
// Base Window for Popup Window
// 

const COLORREF CLOUDBLUE = RGB(128, 184, 223);
const COLORREF WHITE = RGB(255, 255, 255);
const COLORREF BLACK = RGB(1, 1, 1);
const COLORREF DKGRAY = RGB(128, 128, 128);
const COLORREF LTGRAY = RGB(192, 192, 192);
const COLORREF YELLOW = RGB(255, 255, 0);
const COLORREF DKYELLOW = RGB(128, 128, 0);
const COLORREF RED = RGB(255, 0, 0);
const COLORREF DKRED = RGB(128, 0, 0);
const COLORREF BLUE = RGB(0, 0, 255);
const COLORREF DKBLUE = RGB(0, 0, 128);
const COLORREF CYAN = RGB(0, 255, 255);
const COLORREF DKCYAN = RGB(0, 128, 128);
const COLORREF GREEN = RGB(0, 255, 0);
const COLORREF DKGREEN = RGB(0, 128, 0);
const COLORREF MAGENTA = RGB(255, 0, 255);
const COLORREF DKMAGENTA = RGB(128, 0, 128);


class PopWnd : public CWnd
{
	DECLARE_DYNAMIC(PopWnd)

public:
	PopWnd();
	virtual ~PopWnd();

private:
	BOOL bEnableDraggingWnd;

public:
	void Create(int width=1024, int height=768, CPoint offet=CPoint(0,0), COLORREF bgColor= RGB(0,0,0));
	virtual void OnInit(){}
	virtual void OnDestroyWnd(){}
	virtual void OnDraw2(CDC* pDC){}
	virtual void Run(){}
	
	int w_, h_;
	CPoint o_;	//offset
	COLORREF bgColor_;	
	int GetWidth(){return w_;}
	int GetHeight(){return h_;}
	CPoint GetOffset(){return o_;}
	
	void MoveWindowPos(int dx, int dy);
	void MoveWindowPosAbs(int x, int y);
	void EnableDragging(BOOL b=TRUE);

	CFont	mFont;

	void SetAlwaysTop(BOOL bTop=TRUE);

	



protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};


