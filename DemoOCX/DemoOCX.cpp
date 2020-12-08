// DemoOCX.cpp : Implementation of CDemoOCXApp and DLL registration.

#include "pch.h"
#include "framework.h"
#include "DemoOCX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CDemoOCXApp theApp;

const GUID CDECL _tlid = {0x02d4cc0d,0x4702,0x4bad,{0x8c,0xf9,0x5f,0x87,0x64,0x8a,0x66,0x8d}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CDemoOCXApp::InitInstance - DLL initialization

BOOL CDemoOCXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CDemoOCXApp::ExitInstance - DLL termination

int CDemoOCXApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
