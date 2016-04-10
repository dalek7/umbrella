#include "stdafx.h"
#include "vParser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

vErr	g_Err;

vErr::vErr()
{
	nLine	= 1;
}

vErr::~vErr()
{
	for (int i=0;i<GetCount();i++)
	{	
		ERRMSG *p = (ERRMSG*)Search(i);
		delete p;
	}

	CPTRList::RemoveAll();
}

void vErr::SetErr( int n,vString st)
{
	ERRMSG *pNew	= new ERRMSG;
	pNew->n		= n;
	strcpy( pNew->chErr,st.GetBuffer(st.GetLength()));

	AddTail(pNew);
}

void vErr::SetErr( int n,vString v,vString st)
{
	ERRMSG *pNew	= new ERRMSG;
	pNew->n		= n;

	st	= v+st;
	strcpy( pNew->chErr,st.GetBuffer(st.GetLength()));

	AddTail(pNew);
}

void vErr::SetErr( vString st )
{
	ERRMSG *pNew	= new ERRMSG;
	pNew->n		= -1;
	strcpy( pNew->chErr,st.GetBuffer(st.GetLength()));

	AddTail(pNew);
}

void vErr::SetErr( vString cmd,vString st)
{
	ERRMSG *pNew	= new ERRMSG;
	pNew->n		= -1;

	vString tmp;
	tmp.Format( "%s %s",(char*)cmd,(char*)st );
	strcpy( pNew->chErr,tmp.GetBuffer(tmp.GetLength()));
	AddTail(pNew);
}

vTag::vTag()
{
	st="";
	stParent="";
	stScript="";
	pParser	= NULL;
	pParent	= NULL;
	pObject = NULL;
}

vTag::~vTag()
{
	if ( pObject ) 
	{
		delete pObject;
		pObject = NULL;
	}
}

void vTag::Set(vString stName)
{
	st	= stName;
}

void vTag::Set(vString stName,UINT nID)
{
	st	= stName;
	vString tmp("id");
	arrArg.Add( tmp );

	tmp.Format( "\"%d\"",nID );
	arrSA.Add( tmp );
}

void vTag::Set(vString stName,UINT nID,vString stStart,vString stEnd)
{
	New(stName,nID);
	vString tmp("starttime");
	arrArg.Add(tmp);
	arrSA.Add(stStart);
	tmp	= "endtime";
	arrArg.Add(tmp);
	arrSA.Add(stEnd);
}

vTag *vTag::New(vString st)
{
	vTag *pNew	= Add(st);
	return pNew;
}

vTag *vTag::New(vString st,UINT nID)
{
	vTag *p	= New(st);
	p->Set(st,nID);
	return p;
}

vTag *vTag::New(vString st,UINT nID,vString stStart,vString stEnd)
{
	vTag *p	= New(st);
	p->Set(st,nID,stStart,stEnd);
	return p;
}

void vTag::AddScript(vString st)
{
	stScript = stScript + st +"\r\n";
}


vString vTag::GetFieldName(char *pComma)
{
	vString ret;
	vString stComma = pComma;
	vTag *p = this;
	while(p)
	{
		ret	= p->st+ret;
		if ( p->pParent )	ret	= stComma+ ret;
		p	= p->pParent;
	} 
	return ret;
}

vTag* vTag::Add(vString s)
{
	if ( st.IsEmpty())	
	{
		st	= s;
		return this;
	}
	else
	{
		vTag	*p	= new vTag;
		CPTRList::AddTail(p);
		p->pParent	= this;
		p->Add(s);
		return p;
	}
	return NULL;
}

// Call LinkInt(pTag) for inheritance copy.
vTag* vTag::Add(vTag *pTag)
{
	vTag *pNew = vTag::Add( pTag->st);

	// something is neglected.
	for (int i=0;i<pTag->arrArg.GetSize();i++)
		pNew->arrArg.Add(pTag->arrArg[i]);
	for (i=0;i<pTag->arrSI.GetSize();i++)
		pNew->arrSI.Add(pTag->arrSI[i]);
	for (i=0;i<pTag->arrSA.GetSize();i++)
		pNew->arrSA.Add(pTag->arrSA[i]);
	
	pNew->AddScript( pTag->stScript);

	//sub
	for (i=0;i<pTag->GetCount();i++)
	{
		vTag *pSub	= pTag->Search(i);
		pNew->Add(pSub);
	}

	return pNew;
}


int vTag::GetLevel()
{
	int n=0;
	vTag *p = this;
	while(p->pParent)
	{
		n++;
		p	= p->pParent;
	}
	return n;
}

void vTag::Save(vString& stExport)
{
	vString tmp("");
	vString tab("");

	// count level for tab
	int i;
	for (i=0;i<GetLevel();i++)
		tab	= tab+"\t";

	// start field
	if ( GetLevel()>0)	tmp.Format("%s<%s",(char*)tab,(char*)st);
	else				tmp.Format("<%s",(char*)st);

	// argument
	vString args("");
	for (i=0;i<arrArg.GetSize();i++)
	{
		vString tt;
		tt.Format(" %s=%s",(char*)arrArg[i],(char*)arrSA[i]);
		tmp	= tmp+tt;
	}

	tmp	= tmp+">\r\n";
	stExport = stExport +tmp;

	// data script
	vToken tok(stScript);
	tok.SetSeparator("\r\n");
	if ( !tab.IsEmpty() )
	for (i=0;i<tok.GetSize();i++)
	{
		vString temp;
		temp.Format("%s\t%s\r\n",(char*)tab,(char*)tok[i]);
		stExport = stExport +temp;
	}

	// sub tag
	for(i=0;i<GetCount();i++)
	{
		vTag *p		= (vTag*)CPTRList::Search(i);
		p->Save(stExport);
	}

	// complete field
	if ( GetLevel()>0)	tmp.Format("%s</%s>\r\n",(char*)tab,(char*)st);
	else				tmp.Format("</%s>\r\n",(char*)st);
	stExport = stExport + tmp;
}

vTag *vTag::Search( vString s,vTag *pStart)
{
	if ( st==s )
	if ( pStart==NULL )	return this;

	if ( pStart==this )	pStart	= NULL;

	for (int i=0;i<GetCount();i++)
	{
		vTag *p		= (vTag*)CPTRList::Search(i);
		vTag *pres	=  p->Search(s,pStart);
		if ( p==pStart )	pStart	= NULL;
		if ( pres )	return pres;
	}

	return NULL;
}

vTag *vTag::Search(int i)
{
	vTag *p = (vTag*)CPTRList::Search(i);
	return p;
}

void vTag::AddI( vTag* pTop,vString s)
{
	arrSI.Add(s);
}

void vTag::RemoveAll()
{
	if ( pParent)
	for (int i=0;i<pParent->GetCount();i++)
	if ( pParent->Search(i)==this)
	{
		pParent->RemoveAt(i);
		break;
	}

	st.Empty();
	stScript.Empty();
	stParent.Empty();
	pParent	= NULL;
	pParser	= NULL;

	arrI.RemoveAll();
	
	for (int i=0;i<arrSI.GetSize();i++)
		arrSI[i].Empty();
	arrSI.RemoveAll();

	for (i=0;i<arrArg.GetSize();i++)
		arrArg[i].Empty();
	arrArg.RemoveAll();
	arrA.RemoveAll();

	for (i=0;i<arrSA.GetSize();i++)
		arrSA[i].Empty();
	arrSA.RemoveAll();

	for (i=0;i<GetCount();i++)
	{
		vTag	*p	= (vTag*)Search(i);
		p->RemoveAll();
		delete p;
	}
	CPTRList::RemoveAll();
}

void vTag::ScriptProcess()
{
	vToken tok(stScript);
	tok.SetSeparator("\r\n");

	//for (int i=0;i<tok.GetSize();i++)
	//	LineProcess(tok[i]);
}

BOOL vTag::IsTypeOf(vString st)
{
	if ( st=="anything")	return TRUE;

	if ( this->st==st)	return TRUE;
	vTag *p	= pParser->tags.Search(this->stParent);
	if ( p==NULL )	return FALSE;
	return p->IsTypeOf(st);
}

void vTag::AddArg( char *pArg,char *pValue,BOOL bParenthesis)
{
	vString ret("");
	vString stP = "\"";
	vString stArg	= pArg;
	vString stValue	= pValue;

	// check if it exists,
	for (int i=0;i<arrArg.GetSize();i++)
	{
		vString st = arrArg[i];
		st.MakeLower();

		if ( st==stArg)
		{
			ret	= arrSA[i];
			if ( bParenthesis )	stValue	= stP+stValue+stP;
			arrSA[i]	= stValue;
			return ;
		}
	}

	// create new one.
	arrArg.Add(stArg);

	if ( bParenthesis )	stValue	= stP+stValue+stP;
	arrSA.Add(stValue);
}

vString vTag::SetArg( char *psz,char *parg,BOOL bParenthesis)
{
	vString ret("");
	vString stName = psz;
	vString stP	= "\"";
	vString arg	= parg;

	for (int i=0;i<arrArg.GetSize();i++)
	{
		vString st = arrArg[i];
		st.MakeLower();
		if ( st==stName)	
		{
			ret	= arrSA[i];
			if ( bParenthesis )	arg	= stP+arg+stP;
			arrSA[i]	= arg;
			return ret;
		}
	}

	AddArg(psz,parg,bParenthesis);

	return ret;
}

vString vTag::GetArg(char *psz,BOOL bRemoveParenthesis)
{
	vString ret("");
	if ( psz==NULL)	return ret;
	for (int i=0;i<arrArg.GetSize();i++)
	{
		vString st = arrArg[i];
		st.MakeLower();

		vString starg(psz);
		starg.MakeLower();

		if ( st==starg)	
		{
			if ( bRemoveParenthesis)
		    {
		        vToken tok(arrSA[i]);
				tok.Compress("\"");
				return tok.m_in;
		    }
			else return arrSA[i];
		}
	}
	return ret;
}

int vTag::GetArgi(char *psz)
{
  return atoi(GetArg(psz,TRUE));
}

float vTag::GetArgf(char *psz)
{
  return atof(GetArg(psz,TRUE));
}

//////////////////////////////////////////////////////////////////////////


//-------------------------------------------------------------------------------
vSS::vSS()
{
	bRepetitive	= FALSE;
}

vSS::~vSS()
{
	bRepetitive	= FALSE;
	Reset();
}

void vSS::Reset()
{
	for (int i=0;i<ss.GetSize();i++)
		ss[i].Empty();
	ss.RemoveAll();
}	

BOOL vSS::Push(vString s )
{
	for (int i=0;i<ss.GetSize();i++)
	if ( !bRepetitive )
	if ( ss[i]==s )	
	{
		g_Err.SetErr( g_Err.nLine, s,"is already defined");
		return FALSE;
	}

	ss.Add(s);
	return TRUE;
}

vString vSS::Pop()
{
	vString ret="";
	if ( ss.GetSize()<=0 )	return ret;
	
	ret	= ss[ss.GetSize()-1];
	ss.RemoveAt(ss.GetSize()-1);

	return ret;
}

vString vSS::Top()
{
	vString ret="";
	if ( ss.GetSize()<=0 )	return ret;
	
	ret	= ss[ss.GetSize()-1];
	return ret;
}


vParser::vParser()
{
	xf	='<';
	xs	='>';
	buf.Empty();

	tags.pParser	= this;	
	pRoot	= &tags;
	pCurrent= NULL;
}

vParser::~vParser()
{
	Clear();
}

BOOL vParser::Load( char *psz )
{
	vString tmp;
	if ( tmp.Open(psz)==FALSE)	return FALSE;

	Import(tmp);
	return TRUE;
}

void vParser::Import( vString st)
{
	buf	= st;
	Interpreting();
}

void vParser::Interpreting()
{
	PreInt();
	LinkInt(&tags);
	ScriptInt(&tags);
}

void vParser::PreInt()
{
	pRoot	= &tags;
	ss.Reset();
	g_Err.RemoveAll2();
	tags.RemoveAll();

	vToken tl(buf);
	tl.SetSeparator("\r\n",TRUE);

	pCurrent	= pRoot;
	pCurrent->st.Empty();

	for ( int i=0;i<tl.GetSize();i++)
	{
		g_Err.nLine	= i+1;

		// remove comment
		vString tmp=tl[i];
		int ns	= tmp.Find(";");
		if ( ns>=0)
		tmp	= tmp.Left(ns+1);

		vToken tok(tmp);

		// remove tab
		//tok.Compress("\t");	--> ^_^.. \t\t\t\t\t<aa\tb="3> 
		tok.SetSeparator(";");	// tok[1 or more] is neglected.
		if ( tok.GetSize()==0 )	continue;

		// is it 'tag'?
		vString stGen	= tok[0];
		tok.Set( stGen );
		//tok.FindNP("<>");
		char xfs[3]={0,};
		xfs[0]	= xf;
		xfs[1]	= xs;
		tok.FindNP(xfs,'"');

		for ( int j=0;j<tok.GetSize();j++)
		{
			vString tmp	= tok[j];

			if ( tmp[0]=='\t' || tmp[0]==' ')
			{
				for (int k=0;k<tmp.GetLength();k++)
				if ( tmp[k]!='\t' && tmp[k]!=' ')	break;

				vString tt;
				tt = tmp.Right(tmp.GetLength()-k);
				tmp	= tt;
			}

			if ( tmp.GetLength()==0)	continue;

			//if ( tmp[0]=='<' && tmp[1]=='>')	// tag
			if ( tmp[0]==xf && tmp[1]==xs)	// tag
			{
				vToken tt(tmp.Right(tmp.GetLength()-2));								

				// having argument
				tt.SetSeparator(" \t");	
				vString tag;
				tag = tt[0];

				// is it inherited?	 check only case of tag:parent
				vToken ti(tag);
				ti.SetSeparator(":");
				tag	= ti[0];

				if ( tag=="?xml")		break;
				if ( tag=="!DOCTYPE")	break;

				if ( tag[0]=='/')
				{
					vString tb = ss.Pop();
					tag	= tag.Right(tag.GetLength()-1);
					
					if ( tb!=tag )	
					{
						vString ttt;
						ttt.Format("%s는 </로 닫히지않음",buf.GetBuffer());
						//AfxMessageBox(ttt);
					}

					if ( pCurrent->pParent==NULL )	
						pCurrent	= NULL;
					else
					{
						pCurrent	= pCurrent->pParent->Search(pCurrent->stParent);
					}
				}
				else	
				{
					vString stParent	= ss.Top();
					ss.Push( tag );	// 에서 실패(이미 존재)하면 중지.
					pCurrent = pCurrent->Add((char*)tag);
					pCurrent->SetParent(stParent);

					for (int k=1;k<ti.GetSize();k++)	// connect inherited node;
					pCurrent->AddI(&tags,ti[k]);
				}				

				if ( tt.GetSize()>1)	// argument
				{
					int nn=0,n;			// if :aa is missing
					for ( n=1;n<tt.GetSize();n++)
					{
						tmp	= tt[n];
						if ( tmp[0]==':')	
						{
							ti.Add(tmp);
							nn	= n;
						}
					}

					vString args("");
					for ( n=nn+1;n<tt.GetSize();n++)
						args	= args + tt[n]+" ";

					// procedure for argument
					BOOL bStringBracket = FALSE;
					vToken targs(args);
					targs.SetSeparator(" ","\"=");
					
					// ",aa,"-->"aa"
					for (int m=0;m<targs.GetSize();m++)
					{
						vString stString="";

						int m2;
						if ( targs[m]=="\"")
						for (m2=m;m2<targs.GetSize();m2++)
						{
							stString = stString+targs[m2];	
							if ( stString!="\"")
							if ( targs[m2]=="\"")	break;
						}

						if ( stString.IsEmpty())	continue;

						for (int m3=0;m3<=m2-m;m3++)
							targs.RemoveAt(m);
						targs.InsertAt((char*)stString,m);
					}

					for (m=0;m<targs.GetSize();m++)
					if ( targs[m]=="=")	
						targs.RemoveAt(m--);
					else if ( targs[m]==" ")
						targs.RemoveAt(m--);
					
					// procedure for argument
					/* OLD version
					vToken targs(args);
					targs.SetSeparator(" =");

					// check "aaa bbb"
					for (int m=0;m<targs.GetSize();m++)
					{
						vString ss = targs[m];
						int np = 0;

						int n = ss.FindOneOf("\"");
						if ( n>=0)	
						{
							while(n>=0)
							{	
								np++;
								n = ss.Find('\"',n+1);
							}

							if ( np%2==1)
							{
								targs.InsertAt( targs[m]+vString(" ")+targs[m+1],m);
								targs.RemoveAt(m+1);
								targs.RemoveAt(m+1);
								m--;
							}
						}
					}
					*/


					vSS	ssarg;
					ssarg.Set( TRUE );
			
					vString v,a;
					for ( n=0;n<targs.GetSize();n++)
						ssarg.Push( targs[n] );
	
					v	= ssarg.Pop();
					while(!v.IsEmpty() )
					{
						a	= ssarg.Pop();
						if ( a.IsEmpty())	;// error "인자= 값이..필요함.."
						pCurrent->arrArg.Add( a );
						pCurrent->arrSA.Add(v);
						v	= ssarg.Pop();
					}
				}
			}
			else	// script
				pCurrent->stScript	= pCurrent->stScript + tmp + "\r\n";
		}
	}
}

void vParser::LinkInt(vTag *pTag)
{
	// link inheritance
	int i;
	for (i=0;i<pTag->arrSI.GetSize();i++)
	{
		vString buf	= pTag->arrSI[i];
		vTag *p	= (vTag*) tags.Search(buf);
		p->pParser	= this;
		pTag->arrI.Add(p);
	}

	// link argument
	for (i=0;i<pTag->arrArg.GetSize();i++)
	{
		vString buf	= pTag->arrSA[i];
		vTag *p	= (vTag*) tags.Search(buf);
		if ( p )
		{
			p->pParser	= this;
			pTag->arrA.Add(p);
		}
		else 
			g_Err.SetErr( buf,"is not defined");
	}

	for (i=0;i<pTag->GetCount();i++)
	{
		vTag *p = (vTag*) pTag->CPTRList::Search(i);
		p->pParser	= this;
		LinkInt(p);
	}
}

void vParser::ScriptInt(vTag *pTag)
{
	pTag->ScriptProcess();
	for (int i=0;i<pTag->GetCount();i++)
		ScriptInt(pTag->Search(i));
}

vString vParser::RunScript(vString st)
{
	vString ret("");
	vString stComma=",";
	vToken tok(st);
	tok.SetSeparator(",\r\n ");

	vTag *pCmd=NULL;

	while( pCmd= tags.Search(tok[0],pCmd))
	{
	  int i;
		// # of arg check
		if (pCmd->arrArg.GetSize()!=tok.GetSize()-1)	continue;

		// argument type check
		BOOL bTypeCheck	= TRUE;
		
		for (i=0;i<pCmd->arrArg.GetSize();i++)
		{
			vString fSA	= pCmd->arrSA[i];
			vTag *p	= NULL;
			p	= tags.Search(tok[i+1],p);
			if ( !p->IsTypeOf(fSA) )	
			{	
				bTypeCheck	= FALSE;
				break;
			}
		}
		if ( bTypeCheck==FALSE )	continue;

		// function processing
		vString buf;
		for (i=1;i<tok.GetSize();i++)
		{
			buf	= buf+tok[i];
			if ( i!=tok.GetSize()-1 )	buf+=stComma;
		}
		//ret	= pCmd->FuncProcess( buf );
		break;
	}

	//if ( pCmd==NULL )	g_Err.SetErr(tok[0]," is unknown tag or command");
	if (pCmd==NULL )	return st;

	return ret;
}

int vParser::GetSize()
{
	return pRoot->GetCount();
}

BOOL vParser::Save(vString st)
{
	vString tmp	= Export();
	FILE *fp	= fopen(st,"wt");	
	if ( fp==NULL)	return FALSE;
	fwrite( tmp,tmp.GetLength(),1,fp);
	fclose(fp);
	return TRUE;
}

vString vParser::Export()
{
	vString stret("<?xml version=\"1.0\" encoding=\"euc-kr\"?>\r\n");
	pRoot->Save(stret);
	return stret;
}

void vParser::Clear()
{
	ss.Reset();
	tags.RemoveAll();
	buf.Empty();
}

vTag* vParser::New(vString stName)
{
	Clear();
	return pRoot->Add(stName);
}

