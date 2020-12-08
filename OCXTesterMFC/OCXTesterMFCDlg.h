
// OCXTesterMFCDlg.h : header file
//

#pragma once
#include "CMyStatusBar.h"
#include "COCX.h"


// COCXTesterMFCDlg dialog
class COCXTesterMFCDlg : public CDialogEx
{
// Construction
public:
	COCXTesterMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OCXTESTERMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CMyStatusBar statusBar;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnCbnSelendokCombo1();

private:
	int choice;
public:
	CEdit m_ErrorLog;
	CButton m_UseCArchive;
	CButton m_UseZLib;
	CComboBox m_ComboBox;
	COCX m_OCX;
};
