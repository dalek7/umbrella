
#ifndef __File_Proc__
#define __File_Proc__

class FileProc
{
public:
	static void MakeFileNameWithDateTime(CString& rtn);
	static void MakeFileNameWithDateTimeWithExt(CString& rtn, CString extension);
	static CString CreateFolder(CString name,BOOL bRelativePath=FALSE);
	static CString GetPath(CString path);
	static CString GetNoExtName(CString fn);
	static CString GetFileName( CString path);


public:

	static void SaveToFiles(CString fn, float* arr, int narr, char* delimiter="\n");//LPCTSTR lpFmt,...
	static void SaveToFiles(CString fn, float* arr1, float* arr2, int narr, char* delimiterTab = "\t", char* delimiter="\n");
	static void SaveToFiles(CString fn, float* arr1, float* arr2, float* arr3, int narr, char* delimiterTab = "\t", char* delimiter="\n");
};

#endif