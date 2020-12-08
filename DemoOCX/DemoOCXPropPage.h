#pragma once

// DemoOCXPropPage.h : Declaration of the CDemoOCXPropPage property page class.


// CDemoOCXPropPage : See DemoOCXPropPage.cpp for implementation.

class CDemoOCXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CDemoOCXPropPage)
	DECLARE_OLECREATE_EX(CDemoOCXPropPage)

// Constructor
public:
	CDemoOCXPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_DEMOOCX };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

