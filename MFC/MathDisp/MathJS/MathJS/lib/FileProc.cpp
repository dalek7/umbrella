#include "stdafx.h"
#include "FileProc.h"

void FileProc::MakeFileNameWithDateTime(CString& rtn)
{
	char dateStr[9];
	char timeStr[9];

	_strdate( dateStr); //mm/dd/yy
	_strtime(timeStr);
	CString tmp;
	tmp.Format("%s_%s",dateStr, timeStr);
	tmp.Replace(":", "");
	tmp.Replace("/", "");

	rtn = tmp;
}

void FileProc::MakeFileNameWithDateTimeWithExt(CString& rtn, CString ext)
{
	CString tmp;
	MakeFileNameWithDateTime(tmp);
	rtn = tmp+"."+ext;
}


CString FileProc::GetNoExtName(CString fn)
{
	char *buf;
	CString path = fn;
	buf	= path.GetBuffer( path.GetLength() );//(char*)path.operator LPCTSTR();
	int a	= path.Find("*.*");
	if ( a>=0)	
	{
		path	= path.Left( path.GetLength()-a);
		return path;
	}

	int s = path.Find('.');
	while(1)
	{
		int t = path.Find('.',s+1);
		if ( t<0 )	break;
		else		s	= t;
	}


	buf[ s ]	= 0;
	CString ret;
	ret	= buf;	
	return ret;
}

CString FileProc::GetFileName( CString path)
{
	CString ret;
	int max=0;
	int i=0;
	char *buf = path.GetBuffer( path.GetLength() );
	
	while(1)
	{
		if ( buf[i]==0)	break;
		if ( buf[i]=='\\' || buf[i]=='/')	max	=i+1;
		i++;
	}

	ret	= &buf[max];
	/*
	int dot = ret.Find('.');
	while(1)
	{
		int t = path.Find('.',dot+1);
		if ( t<0 )	break;
		else		dot	= t;
	}

	if ( dot>=0 )	
	ret	= ret.Left( dot );
	*/
	return ret;
}


CString FileProc::CreateFolder(CString name, BOOL bRelativePath)
{
	CString sub_folder;
	if(bRelativePath)
	{
		sub_folder = name+"/";
	}
	else
	{
		char buffer[MAX_PATH];
		GetModuleFileName( NULL, buffer, MAX_PATH );

		OutputDebugString(buffer);
		CString loc = GetPath(buffer);
		sub_folder = loc+"/"+name+"/";
	}
	
     if(CreateDirectory( sub_folder, NULL )==ERROR_ALREADY_EXISTS)
     {
          OutputDebugString("Output folder already exists.");
     }
     else
          OutputDebugString("Output folder has been created !!");


	 OutputDebugString(sub_folder);
     return sub_folder;
}



CString FileProc::GetPath( CString path)
{
	CString ret;

	int max=0;
	int i=0;
	char *buf = path.GetBuffer( path.GetLength() );
	
	while(1)
	{
		if ( buf[i]==0)	break;
		if ( buf[i]=='\\' || buf[i]=='/')	max	=i;
		i++;
	}

	ret	= buf;
	ret	= ret.Left(max);

	return ret;
}


void FileProc::SaveToFiles(CString fn, float* arr, int narr, char* delimiter)
{

	FILE *fp;

	char *cfn = fn.GetBuffer( fn.GetLength() );
	fp = fopen(cfn, "w");

	for(int i=0; i<narr; i++)
	{
		if(i<narr-1)
			fprintf(fp, "%f%s", arr[i], delimiter);
		else
			fprintf(fp, "%f", arr[i]);
		
	}

	fclose(fp);
}



void FileProc::SaveToFiles(CString fn, float* arr1, float* arr2, int narr, char* delimiterTab, char* delimiter)
{

	FILE *fp;

	char *cfn = fn.GetBuffer( fn.GetLength() );
	fp = fopen(cfn, "w");

	for(int i=0; i<narr; i++)
	{
		if(i<narr-1)
			fprintf(fp, "%f%s%f%s", arr1[i],delimiterTab, arr2[i],  delimiter);
		else
			fprintf(fp, "%f%s%f", arr1[i],delimiterTab, arr2[i]);
		
	}

	fclose(fp);
}


void FileProc::SaveToFiles(CString fn, float* arr1, float* arr2, float* arr3, int narr, char* delimiterTab, char* delimiter)
{

	FILE *fp;

	char *cfn = fn.GetBuffer( fn.GetLength() );
	fp = fopen(cfn, "w");

	for(int i=0; i<narr; i++)
	{
		if(i<narr-1)
			fprintf(fp, "%f%s%f%s%f%s", arr1[i],delimiterTab, arr2[i], delimiterTab, arr3[i], delimiter);
		else
			fprintf(fp, "%f%s%f%s%f", arr1[i],delimiterTab, arr2[i],delimiterTab, arr3[i]);
		
	}

	fclose(fp);
}

