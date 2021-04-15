
// MFCApplication6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"
#include <cmath>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication6Dlg dialog



CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication6Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, binary);
	DDX_Control(pDX, IDC_CHECK1, cb);
	DDX_Control(pDX, IDC_LIST1, output);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication6Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6Dlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication6Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication6Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication6Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication6Dlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CMFCApplication6Dlg message handlers

BOOL CMFCApplication6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication6Dlg::OnEnChangeEdit1()
{
	
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCApplication6Dlg::OnBnClickedButton1()
{	
// TODO: Add your control notification handler code here
	
	
		CString num, content;
	
		binary.GetWindowTextW(content);
		num.Format(_T("%d"), 1);

		content += num;

		binary.SetWindowTextW(content);
	
		
		
		
		
}


void CMFCApplication6Dlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication6Dlg::OnBnClickedButton4()
{
	CString num, content;
	
		binary.GetWindowTextW(content);
		num.Format(_T("%d"), 0);

		content += num;

		binary.SetWindowTextW(content);
	
	// TODO: Add your control notification handler code here
}


void CMFCApplication6Dlg::OnBnClickedButton3()
{
	CString num, content;
	binary.GetWindowTextW(content);
	num = " " ;
	content = num;

		binary.SetWindowTextW(content);
	// TODO: Add your control notification handler code here
}


void CMFCApplication6Dlg::OnBnClickedButton2()
{
	int maxSize = 0;
	CString  content,display,decimal;
	int num = 0;
	CDC *pDC = GetDC();// This class is necessary to get the length of the string  
	CSize cz;
	binary.GetWindowTextW(content);
int length = content.GetLength();
CString b_one = _T("1");

CString b_zero = _T("0");


bool legal = true;

		
		if (content.GetLength() < 2 )
		{
			display = _T(" Please insert minimum of 2 bits in the input box");
			output.AddString(display);
			legal = false;

			
		}

		else if (content.GetLength() > 32 )
		{
			display = _T(" Please insert minimum of 32 bits in the input box");
			output.AddString(display);
			legal = false;

		}



		else
	{			


if (content[0] == b_one)
{
			num += - (pow(2,content.GetLength()-1));
			legal = true;
}

	for (int i= 1; i < length; i++) 
{  
	

   if (content[i] == b_one)
   {
	   num += pow( 2,length-i-1);
	   legal = true;
	} 

   else if ( content[i] == b_zero)
   {
	   num += 0;
	   legal = true;
   }

   else 
   {
  display = _T(" You have entered an illegal character");
  output.AddString(display);
  legal = false;
  break;
			
   } 

	
}
		}
	
	if (legal){
	decimal.Format(_T("%d"), num); 

	display = _T("The number ") + content + _T(" is ") + decimal + _T(" in decimal.");
	output.AddString(display);
	}
	
		
	cz = pDC->GetTextExtent(display);
 if(cz.cx > maxSize)
	 maxSize = cz.cx;
output.SetHorizontalExtent(maxSize);
}

void CMFCApplication6Dlg::OnBnClickedCheck1()
{
if (cb.GetCheck()) 
{  
	binary.SetReadOnly(TRUE); 
 
 }  


else
{    
	binary.SetReadOnly(FALSE); 
 
 }
	// TODO: Add your control notification handler code here
}
