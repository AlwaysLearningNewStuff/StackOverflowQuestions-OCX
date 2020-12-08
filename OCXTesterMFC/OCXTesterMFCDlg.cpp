
// OCXTesterMFCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OCXTesterMFC.h"
#include "OCXTesterMFCDlg.h"
#include "afxdialogex.h"
#include "FileOpenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COCXTesterMFCDlg dialog

static UINT BASED_CODE indicators[] =
{
	ID_STATUSBAR_INDICATOR
};

COCXTesterMFCDlg::COCXTesterMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OCXTESTERMFC_DIALOG, pParent)
{
	choice = -1;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COCXTesterMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ErrorLog);
	DDX_Control(pDX, IDC_COMBO1, m_ComboBox);
	DDX_Control(pDX, IDC_DEMOOCXCTRL1, m_OCX);
}

BEGIN_MESSAGE_MAP(COCXTesterMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &COCXTesterMFCDlg::OnBnClickedOk)
	ON_CBN_SELENDOK(IDC_COMBO1, &COCXTesterMFCDlg::OnCbnSelendokCombo1)
END_MESSAGE_MAP()


// COCXTesterMFCDlg message handlers

BOOL COCXTesterMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	statusBar.CreateEx(this);
	statusBar.SetIndicators(indicators, 1);
	statusBar.SetPaneInfo(0, ID_STATUSBAR_INDICATOR, SBPS_STRETCH, 0);
	//This is where we actually draw it on the screen
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, ID_STATUSBAR_INDICATOR);

	m_ComboBox.AddString(_T("Add test image"));
	m_ComboBox.AddString(_T("Import image list"));
	m_ComboBox.AddString(_T("Export image list"));
	m_ComboBox.AddString(_T("Delete all images"));
	m_ComboBox.SetCurSel(0);

	choice = 0;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COCXTesterMFCDlg::OnPaint()
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
HCURSOR COCXTesterMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COCXTesterMFCDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	switch (choice)
	{
	case 0:
		m_OCX.AddTestImages();
		break;
	case 1:
	{
		COMDLG_FILTERSPEC fileTypes[] = {
			{L"ZLIB",	L"*.zlib"},
			{L"All Files", L"*.*" }
		};

		FileDialog::COpenFileDialog ofd;

		ofd.SetFileTypes(fileTypes, _countof(fileTypes));
		ofd.SetOptions(FOS_FILEMUSTEXIST);

		int i = ofd.DoModal(GetSafeOwner()->GetSafeHwnd());

		if (i == IDOK)
		{
			CString cs;
			cs.Format(_T("File path: %s"), ofd.GetFullPath().c_str());
			statusBar.SetPaneText(0, cs.GetBuffer());
			cs.Format(_T("%s"), ofd.GetFullPath().c_str());
			m_OCX.ImportImageList(cs.GetBuffer());
			m_ErrorLog.SetWindowText(_T("Success"));
		}
		else
		{
			m_ErrorLog.SetWindowText(_T("User canceled dialog"));
		}
	}
	break;
	case 2:
	{
		HRESULT hr;
		CComPtr<IFileSaveDialog> pDlg;
		COMDLG_FILTERSPEC aFileTypes[] = {
			{ L"ZLIB", L"*.zlib" },
			{ L"All files", L"*.*" }
		};

		// Create the file-save dialog COM object.
		hr = pDlg.CoCreateInstance(__uuidof(FileSaveDialog));

		if (FAILED(hr))
			return;

		// Set the dialog's caption text, file types, Save button label,
		// default file name, and default extension.
		// NOTE: Error handling omitted here for clarity.
		pDlg->SetFileTypes(_countof(aFileTypes), aFileTypes);
		pDlg->SetFileName(L"exported_imagelist.zlib");
		pDlg->SetDefaultExtension(L"zlib");

		// Show the dialog.
		hr = pDlg->Show(AfxGetMainWnd()->GetSafeHwnd());

		// If the user chose a file, save the user's data to that file.
		if (SUCCEEDED(hr))
		{
			CComPtr<IShellItem> pItem;

			hr = pDlg->GetResult(&pItem);

			if (SUCCEEDED(hr))
			{
				LPOLESTR pwsz = NULL;

				hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pwsz);

				if (SUCCEEDED(hr))
				{
					m_OCX.ExportImageListToFile(pwsz);
					CString cs;
					cs.Format(_T("File path: %s"), pwsz);
					statusBar.SetPaneText(0, cs.GetBuffer());
					CoTaskMemFree(pwsz);
				}
			}
		}
	}
	break;
	case 3:
		m_OCX.EmptyImageList();
		break;
	default:
		break;
	}
}

void COCXTesterMFCDlg::OnCbnSelendokCombo1()
{
	// TODO: Add your control notification handler code here
	choice = m_ComboBox.GetCurSel();
}
