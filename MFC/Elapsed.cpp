#include "stdafx.h"
#include "elapsed.h"


CElapsed::CElapsed()
{
	// get the frequency of the counter
	Initialized = QueryPerformanceFrequency( (LARGE_INTEGER *)&Frequency );
	BeginTime	= 0;
}

BOOL CElapsed::Begin()    // start timing
{
	if( ! Initialized )	return 0;   
	// error - couldn't get frequency

    // get the starting counter value
	return QueryPerformanceCounter( (LARGE_INTEGER *)&BeginTime );
}

double CElapsed::End()
{
	if( ! Initialized )	return 0.0; // error - couldn't get frequency

	// get the ending counter value
    __int64 endtime;
    QueryPerformanceCounter( (LARGE_INTEGER *)&endtime );

    // determine the elapsed counts
    __int64 elapsed = endtime - BeginTime;

    // convert counts to time in seconds and return it
    return (double)elapsed / (double)Frequency;
}

BOOL CElapsed::Available()  // returns true if the perf counter is available
{ 
	return Initialized; 
}

__int64 CElapsed::GetFreq() // return perf counter frequency as large int
{ 
	return Frequency; 
}

#ifndef _WIN32_WCE
__int64 CElapsed::GetNSClock()
{
	__int64 rslt;
	__asm	{
				__emit 0x0f	// RDTSC - read time-stamp counter		__emit 0x31
				mov dword ptr [rslt],eax
				mov dword ptr [rslt+4],edx
			}
	return ( rslt );
}

LONG_TIMER CElapsed::GetPentiumRegisterTickCount(void)
{
	 LONG_TIMER Tick = 0;
  
	_asm
	{
			push eax
			push edx
			__emit 0fh
			__emit 031h
			mov dword ptr [Tick],   eax
			mov dword ptr [Tick+4], edx
			pop edx
			pop eax
	}

	return Tick;
}

#endif