// CMyStatusBar.cpp : implementation file
//

#include "pch.h"
#include "OCXTesterMFC.h"
#include "CMyStatusBar.h"


// CMyStatusBar

IMPLEMENT_DYNAMIC(CMyStatusBar, CStatusBar)

CMyStatusBar::CMyStatusBar()
{

}

CMyStatusBar::~CMyStatusBar()
{
}


BEGIN_MESSAGE_MAP(CMyStatusBar, CStatusBar)
END_MESSAGE_MAP()



// CMyStatusBar message handlers




BOOL CMyStatusBar::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
    if (cs.style & SBARS_SIZEGRIP)
    {
        cs.style -= SBARS_SIZEGRIP;
    }

    return CStatusBar::PreCreateWindow(cs);
}
