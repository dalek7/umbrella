#include "stdafx.h"
#include "CommThread.h"

extern HWND hCommWnd;// 


void CQueue::Clear()
{
	m_iHead = m_iTail =0;
	memset(buff,0,BUFF_SIZE);
}
CQueue::CQueue()
{
	Clear();
}
int CQueue::GetSize()
{
	return (m_iHead - m_iTail + BUFF_SIZE) % BUFF_SIZE;
}
BOOL CQueue::PutByte(BYTE b)
{
	if(GetSize() == (BUFF_SIZE-1)) return FALSE;
	buff[m_iHead++] =b;
	m_iHead %= BUFF_SIZE;
	return TRUE;
}
BOOL CQueue::GetByte(BYTE *pb)
{
	if(GetSize() == 0) return FALSE;
	*pb = buff[m_iTail++];
	m_iTail %= BUFF_SIZE;
	return TRUE;
}
CCommThread::CCommThread()
{

	m_bConnected = FALSE;
	nID			= 0;

}

CCommThread::~CCommThread()
{

}



BOOL CCommThread::OpenPort(int num_Port, int num_IndexBaud, int num_IndexData, int num_IndexStop, int num_Parity)
{

	CString strPortName=byIndexComPort(num_Port);
	DWORD dwBaud=byIndexBaud(num_IndexBaud);
	BYTE byData=byIndexData(num_IndexData);
	BYTE byStop=byIndexStop(num_IndexStop);
	BYTE byParity=byIndexParity(num_Parity);

		COMMTIMEOUTS	timeouts;
		DCB				dcb;
		DWORD			dwThreadID;
		

		m_osRead.Offset = 0;
		m_osRead.OffsetHigh = 0;

		if ( !(m_osRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL)) ) 	
		{
			return FALSE;
		}
	

		m_osWrite.Offset = 0;
		m_osWrite.OffsetHigh = 0;
		if (! (m_osWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL)))
		{
			return FALSE;
		}
		
		m_sPortName = strPortName;
	
		m_hComm = CreateFile( m_sPortName, 
							  GENERIC_READ | GENERIC_WRITE, 0, NULL,
							  OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 
							  NULL);

	
		if (m_hComm == (HANDLE) -1)
		{
			AfxMessageBox("Fail to open port");
			return FALSE;
		}
	


	SetCommMask( m_hComm, EV_RXCHAR);	


	SetupComm( m_hComm, BUFF_SIZE, BUFF_SIZE);	


	PurgeComm( m_hComm,					
			   PURGE_TXABORT | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_RXCLEAR);

	timeouts.ReadIntervalTimeout = 0xFFFFFFFF;
	timeouts.ReadTotalTimeoutMultiplier = 0;
	timeouts.ReadTotalTimeoutConstant = 0;
	
	timeouts.WriteTotalTimeoutMultiplier = 2*CBR_9600 / dwBaud;
	timeouts.WriteTotalTimeoutConstant = 0;
	
	SetCommTimeouts( m_hComm, &timeouts);

	dcb.DCBlength = sizeof(DCB);


	GetCommState( m_hComm, &dcb);	
	

	dcb.BaudRate = dwBaud;
	

	//--> Data 8 Bit
	dcb.ByteSize = byData;

	//--> Noparity
	dcb.Parity = byParity;

	//--> 1 Stop Bit
	dcb.StopBits = byStop;


	if( !SetCommState( m_hComm, &dcb) )	
	{
		return FALSE;
	}

	m_bConnected = TRUE;
	m_hThreadWatchComm = CreateThread( NULL, 0, 
									   (LPTHREAD_START_ROUTINE)ThreadWatchComm, 
									   this, 0, &dwThreadID);

	if (! m_hThreadWatchComm)
	{
		ClosePort();
		return FALSE;
	}
	check = FALSE;

	return TRUE;
}
	
void CCommThread::ClosePort()
{
	m_bConnected = FALSE;


	SetCommMask( m_hComm, 0);
	

	PurgeComm( m_hComm,	PURGE_TXABORT | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_RXCLEAR);
	
	CloseHandle(m_hComm);
}


DWORD CCommThread::WriteComm(BYTE *pBuff, DWORD nToWrite)
{
	DWORD	dwWritten, dwError, dwErrorFlags;
	COMSTAT	comstat;


	if( !m_bConnected )		
	{
		return 0;
	}

	
	if( !WriteFile( m_hComm, pBuff, nToWrite, &dwWritten, &m_osWrite))
	{
		
		if (GetLastError() == ERROR_IO_PENDING)
		{
			
			while (! GetOverlappedResult( m_hComm, &m_osWrite, &dwWritten, TRUE))
			{
				dwError = GetLastError();
				if (dwError != ERROR_IO_INCOMPLETE)
				{
					ClearCommError( m_hComm, &dwErrorFlags, &comstat);
					break;
				}
			}
		}
		else
		{
			dwWritten = 0;
			ClearCommError( m_hComm, &dwErrorFlags, &comstat);
		}
	}

	return dwWritten;
}



DWORD CCommThread::ReadComm(BYTE *pBuff, DWORD nToRead)
{
	DWORD	dwRead,dwError, dwErrorFlags;
	COMSTAT comstat;

	
	ClearCommError( m_hComm, &dwErrorFlags, &comstat);


	dwRead = comstat.cbInQue;
	if(dwRead > 0)
	{

		

		if( !ReadFile( m_hComm, pBuff, nToRead, &dwRead, &m_osRead) )
		{
			
			if (GetLastError() == ERROR_IO_PENDING)
			{
				
				while (! GetOverlappedResult( m_hComm, &m_osRead, &dwRead, TRUE))
				{
					dwError = GetLastError();
					if (dwError != ERROR_IO_INCOMPLETE)
					{
						ClearCommError( m_hComm, &dwErrorFlags, &comstat);
						break;
					}
				}
			}
			else
			{
				dwRead = 0;
				ClearCommError( m_hComm, &dwErrorFlags, &comstat);
			}
		}
	}


	return dwRead;

}

int CCommThread::SendData(BYTE* data, int n)
{	
	BYTE *Send_buff;	// for send
	Send_buff=new BYTE[n];	
	
	for(int i=0;i<n;i++)
	{
		Send_buff[i]=data[i];
	}

	WriteComm(Send_buff, n);
	
	delete [] Send_buff;
	return n;
}


BYTE CCommThread::byCode2AsciiValue(char cData)
{
	//char to hex
	BYTE byAsciiValue;
	if( ( '0' <= cData ) && ( cData <='9' ) )
	{
		byAsciiValue = cData - '0';
	}
	else if( ( 'A' <= cData ) && ( cData <= 'F' ) )
	{
		byAsciiValue = (cData - 'A') + 10;
	}
	else if( ( 'a' <= cData ) && ( cData <= 'f' ) )
	{
		byAsciiValue = (cData - 'a') + 10;
	}
	else
	{
		byAsciiValue = 0;
	}
	return byAsciiValue;
}

CString CCommThread::byIndexComPort(int xPort)
{
	CString PortName;
	switch(xPort)
	{
		case 0:		PortName = "COM1"; 			break;
			
		case 1:		PortName = "COM2";			break;

		case 2:		PortName = "COM3"; 			break;
		
		case 3:		PortName = "COM4";			break;
			
		case 4:		PortName = "\\\\.\\COM5"; 	break;
			
		case 5:		PortName = "\\\\.\\COM6";	break;
			
		case 6:		PortName = "\\\\.\\COM7"; 	break;
			
		case 7:		PortName = "\\\\.\\COM8";	break;
		
		case 8:		PortName = "\\\\.\\COM9"; 	break;

		case 9:		PortName = "\\\\.\\COM10";	break;

		case 10:	PortName = "\\\\.\\COM11";	break;

		case 11:		PortName = "\\\\.\\COM12";	break;

		case 12:		PortName = "\\\\.\\COM13";	break;

		case 13:		PortName = "\\\\.\\COM14";	break;
			
		case 14:		PortName = "\\\\.\\COM15";	break;

		case 15:		PortName = "\\\\.\\COM16";	break;

		case 39:		PortName = "\\\\.\\COM40";	break;
	}
	return PortName;
}

DWORD CCommThread::byIndexBaud(int xBaud)
{
	DWORD dwBaud;
	switch(xBaud)
	{
		case 0:		dwBaud = CBR_4800;		break;
			
		case 1:		dwBaud = CBR_9600;		break;
	
		case 2:		dwBaud = CBR_14400;		break;
	
		case 3:		dwBaud = CBR_19200;		break;
	
		case 4:		dwBaud = CBR_38400;		break;
	
		case 5:		dwBaud = CBR_56000;		break;
	
		case 6:		dwBaud = CBR_57600;		break;
	
		case 7:		dwBaud = CBR_115200;	break;
	}

	return dwBaud;
}

BYTE CCommThread::byIndexData(int xData)
{
	BYTE byData;
	switch(xData)
	{
		case 0 :	byData = 5;			break;
	
		case 1 :	byData = 6;			break;
		
		case 2 :	byData = 7;			break;
		
		case 3 :	byData = 8;			break;
	}
	return byData;

}
BYTE CCommThread::byIndexStop(int xStop)
{
	BYTE byStop;
	if(xStop == 0)
	{
		byStop = ONESTOPBIT;
	}
	else
	{
		byStop = TWOSTOPBITS;
	}
	return byStop;


}
BYTE CCommThread::byIndexParity(int xParity)
{
	BYTE byParity;
	switch(xParity)
	{
	case 0 :	byParity = NOPARITY;	break;
	
	case 1 :	byParity = ODDPARITY;	break;
	
	case 2 :	byParity = EVENPARITY;	break;
	}

	return byParity;
}

void CCommThread::ProcessRcvData(BYTE *byBuf, int nSize)
{
	/*
    for(int i = 0; i < nSize; i++)
    {
		m_QueueRead.buff[i] = byBuf[i];
        //Ekg_Data.Add(byBuf[i]);
    }
 
    UINT uiMessagePort = (UINT)U_MSG_RECEIVE_COM1;

    ::SendMessage(g_hViewWnd, uiMessagePort, 0, (LPARAM)nSize);
	*/
}
 


DWORD	ThreadWatchComm(CCommThread* pComm)
{
   DWORD           dwEvent;
   OVERLAPPED      os;
   BOOL            bOk = TRUE;
   BYTE            buf[4096];      
   DWORD           dwRead;


   memset( &os, 0, sizeof(OVERLAPPED));
   

   if( !(os.hEvent = CreateEvent( NULL, TRUE, FALSE, NULL)) )
   {
		bOk = FALSE;
   }


   if( !SetCommMask( pComm->m_hComm, EV_RXCHAR) )
   {
	   bOk = FALSE;
   }


   if( !bOk )
   {
		AfxMessageBox("Error while creating ThreadWatchComm, " + pComm->m_sPortName);
		return FALSE;
   }
  
   while (pComm ->m_bConnected)
   {
 		dwEvent = 0;
	

        WaitCommEvent( pComm->m_hComm, &dwEvent, NULL);
	
	
		

        if ((dwEvent & EV_RXCHAR) == EV_RXCHAR)
        {

			do
			{
				dwRead = pComm->ReadComm( buf, 4096); 
				//pComm->ProcessRcvData(Buf, (int)dwRead);
				
				
				if(BUFF_SIZE - pComm->m_QueueRead.GetSize() > (int)dwRead)
				{
					for( WORD i = 0; i < dwRead; i++ )
					{
						pComm->m_QueueRead.PutByte(buf[i]);
						//pComm->m_QueueRead.buff[i] = buff[i];
					}
				}
				else
					AfxMessageBox("buff ful"); 
				
			}while(dwRead);

			::PostMessage(hCommWnd, WM_COMM_READ,pComm->nID, 0 );
		}
		Sleep(0);	
   }
   
	CloseHandle( os.hEvent);

	pComm->m_hThreadWatchComm = NULL;

	return TRUE;
}

