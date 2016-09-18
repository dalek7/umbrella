
가져온곳 : http://dslweb.nwnexus.com/~ast/dload/guicon.htm


add this to some point
:

	#ifdef _DEBUG
	RedirectIOToConsole();
	#endif




void CEigenTestView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	#ifdef _DEBUG
	RedirectIOToConsole();
	#endif


}


아래처럼 사용


std::cout << m << std::endl;	



MFC VS 2008에서

#include "guicon.h"


#include<iostream>
#include<string>
using namespace std;
#include<io.h>

