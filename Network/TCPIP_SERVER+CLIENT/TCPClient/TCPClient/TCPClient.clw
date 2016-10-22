; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CClientSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TCPClient.h"
LastPage=0

ClassCount=6
Class1=CTCPClientApp
Class2=CTCPClientDoc
Class3=CTCPClientView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CClientSocket
Resource3=IDD_TCPCLIENT_FORM

[CLS:CTCPClientApp]
Type=0
HeaderFile=TCPClient.h
ImplementationFile=TCPClient.cpp
Filter=N

[CLS:CTCPClientDoc]
Type=0
HeaderFile=TCPClientDoc.h
ImplementationFile=TCPClientDoc.cpp
Filter=N

[CLS:CTCPClientView]
Type=0
HeaderFile=TCPClientView.h
ImplementationFile=TCPClientView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_BUTTON1


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=TCPClient.cpp
ImplementationFile=TCPClient.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_TCPCLIENT_FORM]
Type=1
Class=CTCPClientView
ControlCount=8
Control1=IDC_EDIT1,edit,1350633604
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_EDIT3,edit,1350631552
Control5=IDC_BUTTON2,button,1342242816
Control6=IDC_STATIC,button,1342177287
Control7=IDC_EDIT4,edit,1350631552
Control8=IDC_STATIC,static,1342308353

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CClientSocket

