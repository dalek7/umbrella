; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMathJSView
LastTemplate=CHtmlView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MathJS.h"
LastPage=0

ClassCount=6
Class1=CMathJSApp
Class2=CMathJSDoc
Class3=CMathJSView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=MathView
Resource3=IDD_MATHJS_FORM

[CLS:CMathJSApp]
Type=0
HeaderFile=MathJS.h
ImplementationFile=MathJS.cpp
Filter=N

[CLS:CMathJSDoc]
Type=0
HeaderFile=MathJSDoc.h
ImplementationFile=MathJSDoc.cpp
Filter=N

[CLS:CMathJSView]
Type=0
HeaderFile=MathJSView.h
ImplementationFile=MathJSView.cpp
Filter=D
LastObject=IDC_EDIT1
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=MathJS.cpp
ImplementationFile=MathJS.cpp
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

[DLG:IDD_MATHJS_FORM]
Type=1
Class=CMathJSView
ControlCount=2
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_EDIT1,edit,1350631552

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

[CLS:MathView]
Type=0
HeaderFile=MathView.h
ImplementationFile=MathView.cpp
BaseClass=CHtmlView
Filter=C
LastObject=MathView
VirtualFilter=7VWC

