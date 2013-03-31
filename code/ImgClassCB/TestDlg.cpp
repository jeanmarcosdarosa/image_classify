// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImgClassCB.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog


CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
	m_szInFeatTest = _T("..\\data\\Test.txt");
	m_szOutFeatTest = _T("..\\data\\Test.txt.out");
	m_iFeatureType = 6;
	m_iClasserType = 0;
	//}}AFX_DATA_INIT
}


void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Text(pDX, IDC_EDT_INFeatTest, m_szInFeatTest);
	DDX_Text(pDX, IDC_EDT_OutFeatTest, m_szOutFeatTest);
	DDX_Radio(pDX, IDC_RAD_0, m_iFeatureType);
	DDX_Radio(pDX, IDC_RAD_11, m_iClasserType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_BN_CLICKED(IDC_BTN_InFeatTestBro, OnBTNInFeatTestBro)
	ON_BN_CLICKED(IDC_BTN_OutFeatTestBro, OnBTNOutFeatTestBro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

void CTestDlg::OnOK() 
{
	char szParam[256] = "";
	char szExe[256] = "";

	UpdateData(TRUE);
		
	//��������ִ�г���
	if(m_iClasserType == 0)
	{
		sprintf(szExe, "..\\bin\\svm-predict.exe");
		switch(m_iFeatureType)
		{
		case 0: sprintf(szParam, "..\\data\\EDH_Test.txt ..\\data\\EDH_Train.mdl ..\\data\\EDH_res.rrw");	break;
		case 1: sprintf(szParam, "..\\data\\CCH_Test.txt ..\\data\\CCH_Train.mdl ..\\data\\CCH_res.rrw");	break;
		case 2: sprintf(szParam, "..\\data\\GBR_Test.txt ..\\data\\GBR_Train.mdl ..\\data\\GBR_res.rrw");	break;
		case 3: sprintf(szParam, "..\\data\\ImEx_Test.txt ..\\data\\ImEx_Train.mdl ..\\data\\ImEx_res.rrw");break;
		case 4: sprintf(szParam, "..\\data\\ImEx_Test.txt ..\\data\\ImEx_Train.mdl ..\\data\\ImEx_res.rrw");break;
		case 5: sprintf(szParam, "..\\data\\GLCM_Test.txt ..\\data\\GLCM_Train.mdl ..\\data\\GLCM_res.rrw");break;
		case 6: sprintf(szParam, "..\\data\\GLCMX_Test.txt ..\\data\\GLCMX_Train.mdl ..\\data\\GLCMX_res.rrw");	break;
		case 7: sprintf(szParam, "..\\data\\SIFT_Test.txt ..\\data\\SIFT_Train.mdl ..\\data\\SIFT_res.rrw");	break;
		case 8: sprintf(szParam, "..\\data\\PCASIFT_Test.txt ..\\data\\PCASIFT_Train.mdl ..\\data\\PCASIFT_res.rrw");	break;
		case 9:
			sprintf(szExe, "..\\bin\\conbine.exe");
			sprintf(szParam, "..\\data\\EDH_Test.txt ..\\data\\EDH_Train.mdl ..\\data\\CCH_Test.txt ..\\data\\CCH_Train.mdl ..\\data\\GLCMX_Test.txt ..\\data\\GLCMX_Train.mdl ..\\data\\PCASIFT_Test.txt ..\\data\\PCASIFT_Train.mdl ..\\data\\Merge_res.rrw -k 8");
			MessageBox("��ǰ�汾Ϊ����ʵ��õ��Ϻ����ݣ�����ϵ������У�\n  �Ҷȹ�������ֿ�(GLCM*5)\n  ��Եֱ��ͼ(EDH)\n  ��ɫֱ��ͼ(CCH)\n  PCASIFT", 
						"��ܰ��ʾ", MB_OK | MB_ICONINFORMATION);
			break;
		}
	}
	else if(m_iClasserType == 1)
	{
		sprintf(szExe, "..\\bin\\knn.exe");
		switch(m_iFeatureType)
		{
		case 0:	sprintf(szParam, "..\\data\\EDH_Train.txt ..\\data\\EDH_Test.txt ..\\data\\EDH_res.rrw");		break;
		case 1:	sprintf(szParam, "..\\data\\CCH_Train.txt ..\\data\\CCH_Test.txt ..\\data\\CCH_res.rrw");		break;
		case 2:	sprintf(szParam, "..\\data\\GBR_Train.txt ..\\data\\GBR_Test.txt ..\\data\\GBR_res.rrw");		break;
		case 3:	sprintf(szParam, "..\\data\\IM_Train.txt ..\\data\\IM_Test.txt ..\\data\\IM_res.rrw");			break;
		case 4:	sprintf(szParam, "..\\data\\ImEx_Train.txt ..\\data\\ImEx_Test.txt ..\\data\\ImEx_res.rrw");		break;
		case 5:	sprintf(szParam, "..\\data\\GLCM_Train.txt ..\\data\\GLCM_Test.txt ..\\data\\GLCM_res.rrw");		break;
		case 6:	sprintf(szParam, "..\\data\\GLCMX_Train.txt ..\\data\\GLCMX_Test.txt ..\\data\\GLCMX_res.rrw");	break;
		case 7:	sprintf(szParam, "..\\data\\SIFT_Train.txt ..\\data\\SIFT_Test.txt ..\\data\\SIFT_res.rrw");		break;
		case 8:	sprintf(szParam, "..\\data\\PCASIFT_Train.txt ..\\data\\PCASIFT_Test.txt ..\\data\\PCASIFT_res.rrw");break;
			//case 9: sprintf(szParam, "-c 1 -g 0.00001 ..\\data\\Merge_Train.txt ..\\data\\Merge_Test.txt ..\\data\\Merge_res.rrw");		break;
		}
		if(m_iFeatureType == 9)
		{
			MessageBox("knnδ���й������ںϵĲ��֣����˵����μ��ĵ�", "��ܰ��ʾ", MB_OK | MB_ICONINFORMATION);
			return;
		}
	}
	ShellExecute(this->m_hWnd, "open", szExe, szParam, "", SW_SHOW );
}

void CTestDlg::OnBTNInFeatTestBro() 
{
	
	// TODO: Add your control notification handler code here
	CFileDialog dlgFile(TRUE, "Text Files(*.txt)|*.* ", "Train.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "Text Files(*.txt)|*.*||"); 
	const int c_cMaxFiles = 100; 
	const int c_cbBuffSize = (c_cMaxFiles * (MAX_PATH + 1)) + 1; 
	
	dlgFile.DoModal(); 
	m_szInFeatTest = dlgFile.GetPathName();
	UpdateData(FALSE);
}

void CTestDlg::OnBTNOutFeatTestBro() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlgFile(FALSE, "Text Files(*.txt)|*.* ", "Train.txt", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "Text Files(*.txt)|*.*"); 
	const int c_cMaxFiles = 100; 
	const int c_cbBuffSize = (c_cMaxFiles * (MAX_PATH + 1)) + 1; 
	
	dlgFile.DoModal(); 
	m_szOutFeatTest = dlgFile.GetPathName();
	UpdateData(FALSE);
	
}
