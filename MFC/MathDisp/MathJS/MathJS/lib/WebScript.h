#ifndef __WEB_SCRIPT__
#define __WEB_SCRIPT__

#include <atlbase.h>
#include <Mshtml.h>
#include <afxhtml.h>

#include "vParser.h"

class CWebScript
{
public:
		CWebScript();
		~CWebScript();
public:
		BOOL SetWeb(CHtmlView *);
		BOOL Fire(CString stFunc,int);
		BOOL Fire(CString stFunc,int,CString,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,int,int,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,int,int,int,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CString strArg10,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CString strArg10,CString strArg11,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CString strArg10,CString strArg11,CString strArg12,CComVariant* pVarResult = NULL);
		BOOL Fire(CString stFunc,CStringArray& paramArray,CComVariant* pVarResult = NULL);
public:
		vParser	m_vp;
		void	Close();
protected:
		void	Load();
		CComPtr<IHTMLDocument2>	pDoc;
		BOOL GetJScript(CComPtr<IDispatch>&);
		BOOL GetJScripts(CComPtr<IHTMLElementCollection>&);
};


#endif