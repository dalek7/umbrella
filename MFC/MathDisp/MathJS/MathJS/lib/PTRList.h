#ifndef __PTR_LIST__
#define __PTR_LIST__


/////////////////////////////////////////////////////////////////////////////////////
//
//    CPTRList : pointer list.
//               it will be used for visual C/C++ and GCC at LINUX
//
//	  by J.Y.Yang 2002.6.1	
/////////////////////////////////////////////////////////////////////////////////////

typedef struct _PTR_BLK
				{	
					_PTR_BLK	*pNext;
					_PTR_BLK	*pPrev;
					void		*pData;
				} PTR_BLK;

#define LPPTR_BLK	PTR_BLK*
				
class CPTRList
{
public:
		CPTRList();
		~CPTRList();
public:
		
		void	RemoveAll(BOOL bSelfDestoy=FALSE);
		void	RemoveAll2();	// remove all like CPtrList of visual c++; ==RemoveAll(TRUE);
		void*	GetHead();
		void*	GetTail();
		void	AddTail(void*);
		void	AddHead(void*);
		void	AddTail(char*);	// for string
		void	AddHead(char*);

		void	RemoveAt(int n,BOOL bSelfDestroy=FALSE);	// don't remove pData.
		void	RemoveAt2(int n);	
		void*	GetAt( int n=-1);
		void*	Search( int n=-1);
		void	InsertBefore( int , void *);
		void	InsertBefore( void *);
		void	InsertAfter( int , void *);
		void	InsertAfter( void *);
		int		GetCount();
		BOOL	IsEmpty();
		void*	operator[](int);
		int		FindData(void*);
		void*	Prev(int n=1);
		void*	Next(int n=1);

		void	Load(char *,int);
		void	Save(char *,int);

protected:
		PTR_BLK		*pTop;
		PTR_BLK		*pEnd;
		PTR_BLK		*pCur;
		int			nCurrent;
		int			nMax;
};

class CRectList	: public CPTRList
{
public:
		CRectList();
		~CRectList();
		virtual		void	Add(CRect&);
		virtual		CRect	Search(int);
};

#endif
