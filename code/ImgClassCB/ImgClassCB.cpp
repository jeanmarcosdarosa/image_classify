// ImgClassCB.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ImgClassCB.h"

#include "MainFrm.h"
#include "ImgClassCBDoc.h"
#include "ImgClassCBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImgClassCBApp

BEGIN_MESSAGE_MAP(CImgClassCBApp, CWinApp)
	//{{AFX_MSG_MAP(CImgClassCBApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_MENU_FeatureExtract, OnMENUFeatureExtract)
	ON_COMMAND(ID_MENU_Test, OnMENUTest)
	ON_COMMAND(ID_MENU_Train, OnMENUTrain)
	ON_COMMAND(ID_MENU_ViewResult, OnMENUViewResult)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgClassCBApp construction

CImgClassCBApp::CImgClassCBApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CImgClassCBApp object

CImgClassCBApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CImgClassCBApp initialization

BOOL CImgClassCBApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CImgClassCBDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CImgClassCBView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	SetDialogBkColor(RGB(220, 230, 240), RGB(10, 50, 70));
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnBtnEmail();
	afx_msg void OnBtnReadme();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_BTN_EMAIL, OnBtnEmail)
	ON_BN_CLICKED(IDC_BTN_README, OnBtnReadme)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CImgClassCBApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CImgClassCBApp message handlers

void CImgClassCBApp::OnMENUFeatureExtract() 
{
	// TODO: Add your command handler code here
	m_cFeatureExDlg.DoModal();
}

void CImgClassCBApp::OnMENUTrain() 
{
	// TODO: Add your command handler code here
	m_cTrainExDlg.DoModal();
	
}

void CImgClassCBApp::OnMENUTest() 
{
	// TODO: Add your command handler code here
	m_cTestExDlg.DoModal();
	
}

void CImgClassCBApp::OnMENUViewResult() 
{
	// TODO: Add your command handler code here
	m_cViewResultDlg.DoModal();
}


void CAboutDlg::OnBtnEmail() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(this->m_hWnd, "open", "mailto:leoyonn@gmail.com; liushoujun@icst.pku.edu.cn; zhongyuan@icst.pku.edu.cn","","", SW_SHOW );
}

void CAboutDlg::OnBtnReadme()
{
	ShellExecute(NULL, "open", "..\\doc\\ICCB_����˵���ĵ�.pdf","","", SW_SHOW );
}

void CAboutDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}


CMainFrame * GetMainFrame()
{
	return (CMainFrame *)AfxGetMainWnd();
}

CImgClassCBDoc* GetActDoc()
{
	return (CImgClassCBDoc *)GetMainFrame()->GetActiveDocument();
}

CImgClassCBView* GetActView()
{
	return (CImgClassCBView *)GetMainFrame()->GetActiveView();
}

CImgClassCBApp* GetMainApp()
{
	return (CImgClassCBApp *)AfxGetApp();
}