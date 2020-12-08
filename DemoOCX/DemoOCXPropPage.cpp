// DemoOCXPropPage.cpp : Implementation of the CDemoOCXPropPage property page class.

#include "pch.h"
#include "framework.h"
#include "DemoOCX.h"
#include "DemoOCXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CDemoOCXPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CDemoOCXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDemoOCXPropPage, "MFCACTIVEXCONT.DemoOCXPropPage.1",
	0x021b81f1,0x0245,0x43aa,0xbd,0x17,0x92,0xc3,0xec,0x59,0x20,0xf4)

// CDemoOCXPropPage::CDemoOCXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CDemoOCXPropPage

BOOL CDemoOCXPropPage::CDemoOCXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_DEMOOCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CDemoOCXPropPage::CDemoOCXPropPage - Constructor

CDemoOCXPropPage::CDemoOCXPropPage() :
	COlePropertyPage(IDD, IDS_DEMOOCX_PPG_CAPTION)
{
}

// CDemoOCXPropPage::DoDataExchange - Moves data between page and properties

void CDemoOCXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CDemoOCXPropPage message handlers
