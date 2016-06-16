////////////////////////////////////////////////////////
// Seung-Chan Kim
// Since 2011

#ifndef TT_ROUTINES_H
#define TT_ROUTINES_H

#ifdef __cplusplus

// category based on http://docs.scipy.org/doc/numpy-1.10.0/reference/routines.html
namespace DD {

	template <typename T>
	inline void ShuffleArray(T* src, int sz)
	{
		for(int i=0; i<sz; i++)
		{
			int nPos    =  i + (rand() % (sz-i));    //Random remaining position
			T temp		= src[i]; 
			src[i]      = src[nPos]; 
			src[nPos]   = temp;
		}
	}


	template <typename T>
	inline void ShiftWithNew(T* arr, const T &n_val, int sz)
	{
		int i;
		for(i=0; i< sz-1; i++)
		{
			arr[sz-1-i] = arr[sz-2-i];
			
		}
		arr[0] = n_val;

	}



}


#endif /* __cplusplus */

#endif