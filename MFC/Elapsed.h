#ifndef __ELAPSED_TIME__
#define __ELAPSED_TIME__

typedef __int64 LONG_TIMER;

class CElapsed
{
  private :
    int Initialized;
      __int64 Frequency;
      __int64 BeginTime;

  public :
    CElapsed();
    BOOL Begin();		// start timing
    double End();		// stop timing and get elapsed time in seconds
    BOOL Available();	// returns true if the perf counter is available
    __int64 GetFreq();  // return perf counter frequency as large int
    __int64 GetNSClock();
	LONG_TIMER GetPentiumRegisterTickCount(void);
};

#endif

/*
It is very easy to use this class. Here is an example : 

CElapsed Timer;
Timer.Begin();

DoTestOperation();

double elapsed = Timer.End();
*/

/*
 __int64 GetNSClock()
{
	__int64 rslt;
	__asm	{
	__emit 0x0f	// RDTSC - read time-stamp counter		__emit 0x31
	mov dword ptr [rslt],eax
	mov dword ptr [rslt+4],edx
		}
	return ( rslt );
}


typedef __int64 LONG_TIMER;

LONG_TIMER GetPentiumRegisterTickCount(void)
{
  auto LONG_TIMER Tick = 0;
  
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

*/