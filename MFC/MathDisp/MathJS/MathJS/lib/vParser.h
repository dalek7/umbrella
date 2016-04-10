#ifndef __vParser__
#define __vParser__


/*
		vParser		
		Written by J.Yang.	wizardoz@kaist.ac.kr
*/

#include "PTRList.h"
#include "vString.h"
#include "vArray.h"
#include "vToken.h"

typedef struct {
					int		n;
					char	chErr[200];
} ERRMSG;


class vErr : public CPTRList
{
public:
		vErr();
		~vErr();
public:
		void	SetErr(int,vString);
		void	SetErr(int,vString,vString);
		void	SetErr(vString);
		void	SetErr(vString,vString);
		int		nLine;
};

class vParser;
class vTag	: public CPTRList
{
public:
		vTag();		
		~vTag();
public:
		// node
		vTag*	Add(vString);
		vTag*	Add(vTag*);
		void	AddI(vTag*,vString);
		vTag*	Search(vString,vTag *pStart=NULL);
		vTag*	Search(int);
		virtual	void RemoveAll();
		void	SetParent(vString s)	{ stParent	= s;}
		BOOL	IsTypeOf(vString);
		int		GetLevel();
		vString	GetFieldName(char *pComma=".");

		// remark node
		void	Set(vString stName,UINT nID,vString stStart,vString stEnd);
		void	Set(vString stName,UINT nID);
		void	Set(vString stName);
		vTag*	New(vString stName);
		vTag*	New(vString stName,UINT nID);
		vTag*	New(vString stName,UINT nID,vString stStart,vString stEnd);
		void	AddScript(vString);
		

public:
		// script
		void	ScriptProcess();
		void	LineProcess(vString);
		vString	FuncProcess(vString);
		int		IsCommand(vString);

		// io
		void	Save(vString& stExport);

public:
		vString	st;
		vString stParent;

		vArray<vTag*,vTag*>		arrI;	// inherited.
		vArray<vString,vString>	arrSI;	// inherited string

		vArray<vString,vString>	arrArg;	// argument string		ex) arg
		vArray<vTag*,vTag*>		arrA;	// argument type		ex) object link
		vArray<vString,vString>	arrSA;	// argument type string	ex) object, object:vessel 	
		vString	stScript;
		
		vTag					*pParent;
		vParser					*pParser;

		// argument		
		//void		AddArg(vString stArg,vString stValue,BOOL bParenthesis=TRUE);	//ex when bParen=TRUE, stArg="stValue"
		void		AddArg(char*,char*,BOOL bParenthesis=TRUE);	//ex when bParen=TRUE, stArg="stValue"
		vString		SetArg(char*,char*,BOOL bParenthesis=TRUE);
		vString		GetArg(char*,BOOL bRemoveParenthesis=TRUE);
		int         GetArgi(char*);
		float       GetArgf(char*);
		void		*pObject;
};

class vSS
{
public:
		vSS();
		~vSS();
public:
		BOOL	Push(vString);
		vString	Pop();
		void	Reset();
		vString	Top();
		void	Set(BOOL bRepeat)	{ bRepetitive	= bRepeat; }

protected:
		vArray	<vString,vString>	ss;
		BOOL	bRepetitive;
};

class vParser
{
public:
		vParser();
		~vParser();
public:
		vString	buf;
public:
		// romma io
		vTag*	New(vString);
		void	Clear();
		BOOL	Load(char*);	
		BOOL	Save(vString);
		void	Import(vString);
		vString	Export();
		
		vString	RunScript(vString);

		// parser sentences
		int		GetSize();

protected:
		void	Interpreting();		
		void	PreInt();
		void	LinkInt(vTag*);
		void	ScriptInt(vTag*);

public:	
		vTag	tags;
		vSS		ss;
		vTag	*pCurrent;
		vTag	*pRoot;
		char	xf,xs;
};

extern vErr	g_Err;


#endif
