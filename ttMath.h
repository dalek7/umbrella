/*
 *  ttMath.h
 *  Created by Seung-Chan Kim on 6/28/11.
 *  Copyright 2011 Disney Research, Pittsburgh. All rights reserved.
 */

#ifndef TT_MATH2_H
#define TT_MATH2_H

#ifdef __cplusplus


namespace DD {

template <typename T>
inline void GetAvg(const T* arr, const int szarr, T& vavg)
{
	int i;
	T vsum= (T) 0;
	
	for(i=0; i< szarr; i++)
	{
		vsum += arr[i];

	}

	vsum = vsum / (float) szarr;	// check !

	vavg = vsum;

}

template <typename T>
inline void GetVariance(const T* arr, const int szarr, T& vvariance)
{
	
	T vavg;
	GetAvg<T>(arr, szarr,vavg);
	
	T tempsum = (T) 0;

	int i;
	for(i=0; i< szarr; i++)
	{
		T temp = (vavg - arr[i]) *  (vavg - arr[i]) ;
		tempsum = tempsum + temp;

	}
	tempsum = tempsum / (float) szarr;

	vvariance = tempsum;
}


template <typename T>
inline void GetMax(const T* arr, const int szarr, T& vmax, int& arrID)
{
	int i;
	T vtmp=-99999;
	int idtmp = -1;
	for(i=0; i< szarr; i++)
	{

		if(arr[i] >vtmp)
		{
			vtmp = arr[i];
			idtmp = i;
		}
	}

	vmax = vtmp;
	arrID = idtmp;
}


template <typename T>
inline void GetMin(const T* arr, const int szarr, T& vmin, int& arrID)
{
	int i;
	T vtmp=99999;
	int idtmp = -1;
	for(i=0; i< sz; i++)
	{

		if(arr[i] <vtmp)
		{
			vtmp = arr[i];
			idtmp = i;
		}
	}

	vmin = vtmp;
	arrID = idtmp;
}

// added 2013/2/16 @CHAUD 1186

template <typename T>
inline T Clamp(const T &val, const T &MIN, const T &MAX)
{
    if (val < MIN) return MIN;
    if (val > MAX) return MAX;
    return val;
}

template <typename T>
inline T Round(const T &val)
{
    return floor(val + 0.5);
}

template <typename T>
inline T AbsValue(const T &val)
{
    if (val < 0) return -val;
    return val;
}


template <typename T>
inline bool IsEqual(const T &v0, const T &v1, const T epsilon = 1E-9)
{
    return (AbsValue(v0 - v1) <= epsilon);
}

#endif /* __cplusplus */


}
#endif