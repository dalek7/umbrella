#include "stdafx.h"
#include "WebScript.h"


CWebScript::CWebScript()
{
	pDoc	= NULL;
	m_vp.Clear();
}

CWebScript::~CWebScript()
{
	Close();
}

BOOL CWebScript::SetWeb(CHtmlView *pView)
{
	if ( pDoc )	return false;
	LPDISPATCH pdisp = pView->GetHtmlDocument();

	HRESULT hr = pdisp->QueryInterface(IID_IHTMLDocument2,(void**)&pDoc);

	if	(FAILED(hr))	return FALSE;

	Load();
	pdisp->Release();
	return true;
}

void CWebScript::Close()
{
	m_vp.Clear();
	pDoc	= NULL;
}

BOOL CWebScript::GetJScript(CComPtr<IDispatch>& spDisp)
{
	HRESULT hr = pDoc->get_Script(&spDisp);
	ATLASSERT(SUCCEEDED(hr));
	return SUCCEEDED(hr);
}

BOOL CWebScript::GetJScripts(CComPtr<IHTMLElementCollection>& spColl)
{
	HRESULT hr = pDoc->get_scripts(&spColl);
	ATLASSERT(SUCCEEDED(hr));
	return SUCCEEDED(hr);
}

BOOL CWebScript::Fire(CString stFunc,CComVariant* pVarResult)
{
	CStringArray paramArray;
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	paramArray.Add(strArg6);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	paramArray.Add(strArg6);
	paramArray.Add(strArg7);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	paramArray.Add(strArg6);
	paramArray.Add(strArg7);
	paramArray.Add(strArg8);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	paramArray.Add(strArg6);
	paramArray.Add(strArg7);
	paramArray.Add(strArg8);
	paramArray.Add(strArg9);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CString strArg10,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	paramArray.Add(strArg6);
	paramArray.Add(strArg7);
	paramArray.Add(strArg8);
	paramArray.Add(strArg9);
	paramArray.Add(strArg10);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CString strArg10,CString strArg11,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	paramArray.Add(strArg6);
	paramArray.Add(strArg7);
	paramArray.Add(strArg8);
	paramArray.Add(strArg9);
	paramArray.Add(strArg10);
	paramArray.Add(strArg11);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,CString strArg1,CString strArg2,CString strArg3,CString strArg4,CString strArg5,CString strArg6,CString strArg7,CString strArg8,CString strArg9,CString strArg10,CString strArg11,CString strArg12,CComVariant* pVarResult)
{
	CStringArray paramArray;
	paramArray.Add(strArg1);
	paramArray.Add(strArg2);
	paramArray.Add(strArg3);
	paramArray.Add(strArg4);
	paramArray.Add(strArg5);
	paramArray.Add(strArg6);
	paramArray.Add(strArg7);
	paramArray.Add(strArg8);
	paramArray.Add(strArg9);
	paramArray.Add(strArg10);
	paramArray.Add(strArg11);
	paramArray.Add(strArg12);
	return Fire(stFunc,paramArray,pVarResult);
}

BOOL CWebScript::Fire(CString stFunc,int f,int s,int t,CComVariant* pVarResult)
{
	CComPtr<IDispatch> spScript;
	if(!GetJScript(spScript))
		return false;
	
	CComBSTR bstrMember(stFunc);
	DISPID dispid = NULL;
	HRESULT hr = spScript->GetIDsOfNames(IID_NULL,&bstrMember,1,
											LOCALE_SYSTEM_DEFAULT,&dispid);
	if(FAILED(hr))
		return false;

	int arraySize = 3;

	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);
	dispparams.cArgs = 3;
	dispparams.rgvarg = new VARIANT[3];
	dispparams.rgvarg[0].intVal	= t; 
	dispparams.rgvarg[1].intVal	= s; 
	dispparams.rgvarg[2].intVal	= f; 
	dispparams.rgvarg[0].vt	= VT_INT;
	dispparams.rgvarg[1].vt	= VT_INT;
	dispparams.rgvarg[2].vt	= VT_INT;
	dispparams.cNamedArgs = 0;

	EXCEPINFO excepInfo;
	memset(&excepInfo, 0, sizeof excepInfo);
   	CComVariant vaResult;
	UINT nArgErr = (UINT)-1;  // initialize to invalid arg
         
	hr = spScript->Invoke(dispid,IID_NULL,0,
							DISPATCH_METHOD,&dispparams,&vaResult,&excepInfo,&nArgErr);

	delete [] dispparams.rgvarg;
	if(FAILED(hr))
		return false;
	
	if(pVarResult)
		*pVarResult = vaResult;

	return true;
}

BOOL CWebScript::Fire(CString stFunc,int f,int s,CComVariant* pVarResult)
{
	CComPtr<IDispatch> spScript;
	if(!GetJScript(spScript))
		return false;
	
	CComBSTR bstrMember(stFunc);
	DISPID dispid = NULL;
	HRESULT hr = spScript->GetIDsOfNames(IID_NULL,&bstrMember,1,
											LOCALE_SYSTEM_DEFAULT,&dispid);
	if(FAILED(hr))
		return false;

	int arraySize = 2;

	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);
	dispparams.cArgs = 2;
	dispparams.rgvarg = new VARIANT[2];
	dispparams.rgvarg[0].intVal	= s; 
	dispparams.rgvarg[1].intVal	= f; 
	dispparams.rgvarg[0].vt	= VT_INT;
	dispparams.rgvarg[1].vt	= VT_INT;
	dispparams.cNamedArgs = 0;

	EXCEPINFO excepInfo;
	memset(&excepInfo, 0, sizeof excepInfo);
   	CComVariant vaResult;
	UINT nArgErr = (UINT)-1;  // initialize to invalid arg
         
	hr = spScript->Invoke(dispid,IID_NULL,0,
							DISPATCH_METHOD,&dispparams,&vaResult,&excepInfo,&nArgErr);

	delete [] dispparams.rgvarg;
	if(FAILED(hr))
		return false;
	
	if(pVarResult)
		*pVarResult = vaResult;

	return true;
}


BOOL CWebScript::Fire(CString stFunc,int f,CString starg,CComVariant* pVarResult)
{
	CComPtr<IDispatch> spScript;
	if(!GetJScript(spScript))
		return false;
	
	CComBSTR bstrMember(stFunc);
	DISPID dispid = NULL;
	HRESULT hr = spScript->GetIDsOfNames(IID_NULL,&bstrMember,1,
											LOCALE_SYSTEM_DEFAULT,&dispid);
	if(FAILED(hr))
		return false;

	int arraySize = 2;

	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);
	dispparams.cArgs = 2;
	dispparams.rgvarg = new VARIANT[2];
	CComBSTR bstr = starg;
	bstr.CopyTo( &dispparams.rgvarg[0].bstrVal );
	dispparams.rgvarg[1].intVal	= f; 
	dispparams.rgvarg[0].vt	= VT_BSTR;
	dispparams.rgvarg[1].vt	= VT_INT;
	dispparams.cNamedArgs = 0;

	EXCEPINFO excepInfo;
	memset(&excepInfo, 0, sizeof excepInfo);
   	CComVariant vaResult;
	UINT nArgErr = (UINT)-1;  // initialize to invalid arg
         
	hr = spScript->Invoke(dispid,IID_NULL,0,
							DISPATCH_METHOD,&dispparams,&vaResult,&excepInfo,&nArgErr);

	delete [] dispparams.rgvarg;
	if(FAILED(hr))
		return false;
	
	if(pVarResult)
		*pVarResult = vaResult;

	return true;
}

BOOL CWebScript::Fire( CString stFunc,int n)
{
	CComPtr<IDispatch> spScript;
	if(!GetJScript(spScript))
		return false;
	
	CComBSTR bstrMember(stFunc);
	DISPID dispid = NULL;
	HRESULT hr = spScript->GetIDsOfNames(IID_NULL,&bstrMember,1,
											LOCALE_SYSTEM_DEFAULT,&dispid);
	if (FAILED(hr))	return false;

	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);
	dispparams.cArgs = 1;
	dispparams.rgvarg = new VARIANT;
	dispparams.rgvarg->intVal	= n;
	dispparams.rgvarg->vt		= VT_INT;
	dispparams.cNamedArgs = 0;

	EXCEPINFO excepInfo;
	memset(&excepInfo, 0, sizeof excepInfo);
   	CComVariant vaResult;
	UINT nArgErr = (UINT)-1;  // initialize to invalid arg
         
	hr = spScript->Invoke(dispid,IID_NULL,0,
							DISPATCH_METHOD,&dispparams,&vaResult,&excepInfo,&nArgErr);

	delete [] dispparams.rgvarg;
	if(FAILED(hr))
		return false;
	
	return true;
}

BOOL CWebScript::Fire(CString stFunc, CStringArray& paramArray,CComVariant* pVarResult)
{
	CComPtr<IDispatch> spScript;
	if(!GetJScript(spScript))
		return false;
	
	CComBSTR bstrMember(stFunc);
	DISPID dispid = NULL;
	HRESULT hr = spScript->GetIDsOfNames(IID_NULL,&bstrMember,1,
											LOCALE_SYSTEM_DEFAULT,&dispid);
	if(FAILED(hr))
		return false;

	int arraySize = paramArray.GetSize();

	DISPPARAMS dispparams;
	memset(&dispparams, 0, sizeof dispparams);
	dispparams.cArgs = arraySize;
	dispparams.rgvarg = new VARIANT[dispparams.cArgs];
	
	for( int i = 0; i < arraySize; i++)
	{
		CComBSTR bstr = paramArray.GetAt(arraySize - 1 - i); // back reading
		bstr.CopyTo(&dispparams.rgvarg[i].bstrVal);
		dispparams.rgvarg[i].vt = VT_BSTR;
	}
	dispparams.cNamedArgs = 0;

	EXCEPINFO excepInfo;
	memset(&excepInfo, 0, sizeof excepInfo);
   	CComVariant vaResult;
	UINT nArgErr = (UINT)-1;  // initialize to invalid arg
         
	hr = spScript->Invoke(dispid,IID_NULL,0,
							DISPATCH_METHOD,&dispparams,&vaResult,&excepInfo,&nArgErr);

	delete [] dispparams.rgvarg;
	if(FAILED(hr))
		return false;
	
	if(pVarResult)
		*pVarResult = vaResult;

	return true;
}

void CWebScript::Load()
{
	m_vp.Clear();
	m_vp.pRoot->New("JScript");

	CComPtr<IHTMLElementCollection> spScripts;
	if(!GetJScripts(spScripts))
		return;

	long count = 0;
	HRESULT hr = spScripts->get_length(&count);
	ATLASSERT(SUCCEEDED(hr));
	
	long idx = -1;
	while(count--)
	{
		idx++;
		
		CComPtr<IDispatch> spDispatch;
		CComVariant name(idx),index(idx);
		hr = spScripts->item(name,index,(IDispatch**)&spDispatch);
		ATLASSERT(SUCCEEDED(hr));
		if(FAILED(hr))
			continue;


		CComPtr<IHTMLScriptElement> spScriptObj;
		hr = spDispatch->QueryInterface(IID_IHTMLScriptElement,(void**)&spScriptObj);
		ATLASSERT(SUCCEEDED(hr));
		if(FAILED(hr))
			continue;

		CComBSTR bstr;
		hr = spScriptObj->get_text(&bstr);
		ATLASSERT(SUCCEEDED(hr));

		CString strText(bstr);
		CString stScript;
		vToken tok(strText);
		tok.SetSeparator("\r\n");

		vTag *pCur;
		int n=0;
		for (int i=0;i<tok.GetSize();i++)
		{
			vToken tk(tok[i]);
			tk.SetSeparator(" \t");

			BOOL bFunction=FALSE;
			for (int j=0;j<tk.GetSize();j++)
			if ( tk[j]=="function")
			{
				stScript.Empty();
				vString tmp = tk[j+1];

				vToken tkTag(tmp);
				tkTag.SetSeparator("()");

				pCur	= m_vp.pRoot->Add((char*)tkTag[0]);	//
				tmp	= tok[i];	//
				pCur->AddScript(tmp);	//
				bFunction	= TRUE;
			}
			
			if (!bFunction)	pCur->AddScript(tok[i]);	//
		}

	}

	/*
	for (int i=0;i<3;i++)
	{
		vTag *p	= m_vp.pRoot->Search(i);
		CString st = p->stScript;
	}
	*/
}
