

#define WM_COMM_READ (WM_USER +1)
#define BUFF_SIZE			4096

class CQueue
{
public:
	BYTE buff[BUFF_SIZE];
	int m_iHead, m_iTail;
	CQueue();
	void Clear();
	int GetSize();
	BOOL PutByte(BYTE b);
	BOOL GetByte(BYTE *pb);
};

class	CCommThread
{
public:

	CCommThread();
	~CCommThread();

	BOOL        check;
	HANDLE		m_hComm;				
	CString		m_sPortName;			
	BOOL		m_bConnected;			
	OVERLAPPED	m_osRead, m_osWrite;	
	HANDLE		m_hThreadWatchComm;		
	WORD		m_wPortID;				
	CQueue      m_QueueRead;			

	void ProcessRcvData(BYTE *byBuf, int nSize);
	BOOL	OpenPort(int num_Port, int num_IndexBaud, int num_IndexData, int num_IndexStop, int num_Parity);
	void	ClosePort();				
	DWORD	WriteComm(BYTE *pBuff, DWORD nToWrite);

	int SendData(BYTE* data, int n);

	BYTE byCode2AsciiValue(char cData);
	CString byIndexComPort(int xPort);
	DWORD byIndexBaud(int xBaud);
	BYTE byIndexData(int xData);
	BYTE byIndexStop(int xStop);
	BYTE byIndexParity(int xParity);



	DWORD	ReadComm(BYTE *pBuff, DWORD nToRead);


	int		nID;	//20130403 Seung-Chan Kim
	void SetID(int n)
	{	nID = n;}

};


DWORD	ThreadWatchComm(CCommThread* pComm);

