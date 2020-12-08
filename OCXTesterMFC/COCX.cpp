// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated
// by Microsoft Visual C++, your modifications will be overwritten.

#include "pch.h"
#include "COCX.h"

/////////////////////////////////////////////////////////////////////////////
// COCX

IMPLEMENT_DYNCREATE(COCX, CWnd)

/////////////////////////////////////////////////////////////////////////////
// COCX Properties

/////////////////////////////////////////////////////////////////////////////
// COCX Operations

LONG COCX::ImportImageList(BSTR fullFilePath)
{
	long result;
	static BYTE parms[] = VTS_BSTR;
	InvokeHelper(0x01, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fullFilePath);
	return result;
}

LONG COCX::ExportImageListToFile(BSTR fullFilePath)
{
	long result; 
	static BYTE parms[] = VTS_BSTR;
	InvokeHelper(0x02, DISPATCH_METHOD, VT_I4, (void*)&result, parms, fullFilePath);
	return result;
}

void COCX::EmptyImageList()
{
	InvokeHelper(0x03, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void COCX::AddTestImages()
{
	InvokeHelper(0x04, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
