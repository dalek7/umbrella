/*
Module : ENUMSER.H
Purpose: Defines the interface for a single function to 
         enumerate the serial ports installed on a PC
Created: PJN / 02-11-1998
History: PJN / 23-02-1999 Now uses QueryDosDevice when running on NT.

Copyright (c) 1998 - 1999 by PJ Naughter.  
All rights reserved.

*/



#ifndef __ENUMSER_H__
#define __ENUMSER_H__
                      

#ifndef __AFXTEMPL_H__
#pragma message("EnumerateSerialPorts function requires afxtempl.h in your PCH")                                                                                
#endif


void EnumerateSerialPorts(CUIntArray& ports);



#endif //__ENUMSER_H__