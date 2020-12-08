// DemoOCXCtrl.cpp : Implementation of the CDemoOCXCtrl ActiveX Control class.

#include "pch.h"
#include "framework.h"
#include "DemoOCX.h"
#include "DemoOCXCtrl.h"
#include "DemoOCXPropPage.h"
#include "afxdialogex.h"
#include "zlib.h"
#include <assert.h>

#define ZLIB_BUFFERSIZE		32768 // do not increase beyond 32768
#define CHUNK 16384

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CDemoOCXCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CDemoOCXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CDemoOCXCtrl, COleControl)
	DISP_FUNCTION_ID(CDemoOCXCtrl, "ImportImageList", dispidImportImageList, ImportImageList, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CDemoOCXCtrl, "ExportImageListToFile", dispidExportImageListToFile, ExportImageListToFile, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CDemoOCXCtrl, "EmptyImageList", dispidEmptyImageList, EmptyImageList, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CDemoOCXCtrl, "AddTestImages", dispidAddTestImages, AddTestImages, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CDemoOCXCtrl, COleControl)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CDemoOCXCtrl, 1)
	PROPPAGEID(CDemoOCXPropPage::guid)
END_PROPPAGEIDS(CDemoOCXCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CDemoOCXCtrl, "MFCACTIVEXCONTRO.DemoOCXCtrl.1",
	0x179ab540, 0x078d, 0x44cb, 0x97, 0x7e, 0xa7, 0x78, 0x97, 0x3a, 0x51, 0x61)

	// Type library ID and version

	IMPLEMENT_OLETYPELIB(CDemoOCXCtrl, _tlid, _wVerMajor, _wVerMinor)

	// Interface IDs

	const IID IID_DDemoOCX = { 0x69ef3342,0x2d67,0x42a0,{0x81,0xae,0x98,0x7c,0x13,0xc3,0xfc,0x9d} };
const IID IID_DDemoOCXEvents = { 0xf2e2076e,0x3db1,0x4ddd,{0x82,0x3f,0x02,0x6e,0x7c,0xa1,0x71,0x54} };

// Control type information

static const DWORD _dwDemoOCXOleMisc =
OLEMISC_ACTIVATEWHENVISIBLE |
OLEMISC_SETCLIENTSITEFIRST |
OLEMISC_INSIDEOUT |
OLEMISC_CANTLINKINSIDE |
OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CDemoOCXCtrl, IDS_DEMOOCX, _dwDemoOCXOleMisc)

// CDemoOCXCtrl::CDemoOCXCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CDemoOCXCtrl

BOOL CDemoOCXCtrl::CDemoOCXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegInsertable | afxRegApartmentThreading to afxRegInsertable.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_DEMOOCX,
			IDB_DEMOOCX,
			afxRegInsertable | afxRegApartmentThreading,
			_dwDemoOCXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CDemoOCXCtrl::CDemoOCXCtrl - Constructor

CDemoOCXCtrl::CDemoOCXCtrl()
{
	InitializeIIDs(&IID_DDemoOCX, &IID_DDemoOCXEvents);

	BOOL bResult = m_pImageList.Create(32, 32, ILC_COLOR8, 0, 1);
	if (bResult)
	{
		AddTestImages();
	}
	else
	{
		// how to handle error ??
	}
}

// CDemoOCXCtrl::~CDemoOCXCtrl - Destructor

CDemoOCXCtrl::~CDemoOCXCtrl()
{
	m_pImageList.DeleteImageList();
}

// CDemoOCXCtrl::OnDraw - Drawing function

void CDemoOCXCtrl::OnDraw(
	CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));

	int cx = 0, cy = 0;
	int nCount = m_pImageList.GetImageCount();
	::ImageList_GetIconSize(m_pImageList, &cx, &cy);

	//Draw the images of the image list on the DC.
	const int right_margin = 10;

	for (int dx = 50, i = 0; i < nCount; i++)
	{
		m_pImageList.DrawIndirect(pdc, i, CPoint(dx, 50), CSize(cx, cy), CPoint(0, 0));
		dx += cx + right_margin;
	}
}

// CDemoOCXCtrl::DoPropExchange - Persistence support

void CDemoOCXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


// CDemoOCXCtrl::OnResetState - Reset control to default state

void CDemoOCXCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CDemoOCXCtrl message handlers

int CDemoOCXCtrl::def(FILE* source, FILE* dest, int level)
{
	int ret, flush;
	unsigned have;
	z_stream strm;
	unsigned char in[CHUNK];
	unsigned char out[CHUNK];

	/* allocate deflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	ret = deflateInit(&strm, level);
	if (ret != Z_OK)
		return ret;

	/* compress until end of file */
	do {
		strm.avail_in = fread(in, 1, CHUNK, source);
		if (ferror(source)) {
			(void)deflateEnd(&strm);
			return Z_ERRNO;
		}
		flush = feof(source) ? Z_FINISH : Z_NO_FLUSH;
		strm.next_in = in;

		/* run deflate() on input until output buffer not full, finish
		   compression if all of source has been read in */
		do {
			strm.avail_out = CHUNK;
			strm.next_out = out;
			ret = deflate(&strm, flush);    /* no bad return value */
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
			have = CHUNK - strm.avail_out;
			if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
				(void)deflateEnd(&strm);
				return Z_ERRNO;
			}
		} while (strm.avail_out == 0);
		assert(strm.avail_in == 0);     /* all input will be used */

		/* done when last data in file processed */
	} while (flush != Z_FINISH);
	assert(ret == Z_STREAM_END);        /* stream will be complete */

	/* clean up and return */
	(void)deflateEnd(&strm);
	return Z_OK;
}

int CDemoOCXCtrl::inf(FILE* source, FILE* dest)
{
	int ret;
	unsigned have;
	z_stream strm;
	unsigned char in[CHUNK];
	unsigned char out[CHUNK];

	/* allocate inflate state */
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;
	ret = inflateInit(&strm);
	if (ret != Z_OK)
		return ret;

	/* decompress until deflate stream ends or end of file */
	do {
		strm.avail_in = fread(in, 1, CHUNK, source);
		if (ferror(source)) {
			(void)inflateEnd(&strm);
			return Z_ERRNO;
		}
		if (strm.avail_in == 0)
			break;
		strm.next_in = in;

		/* run inflate() on input until output buffer not full */
		do {
			strm.avail_out = CHUNK;
			strm.next_out = out;
			ret = inflate(&strm, Z_NO_FLUSH);
			assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
			switch (ret) {
			case Z_NEED_DICT:
				ret = Z_DATA_ERROR;     /* and fall through */
			case Z_DATA_ERROR:
			case Z_MEM_ERROR:
				(void)inflateEnd(&strm);
				return ret;
			}
			have = CHUNK - strm.avail_out;
			if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
				(void)inflateEnd(&strm);
				return Z_ERRNO;
			}
		} while (strm.avail_out == 0);

		/* done when inflate() says it's done */
	} while (ret != Z_STREAM_END);

	/* clean up and return */
	(void)inflateEnd(&strm);
	return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

void CDemoOCXCtrl::zerr(int ret)
{
	switch (ret) {
	case Z_ERRNO:
		::OutputDebugString(_T("I/O error\n"));
		break;
	case Z_STREAM_ERROR:
		::OutputDebugString(_T("invalid compression level\n"));
		break;
	case Z_DATA_ERROR:
		::OutputDebugString(_T("invalid or incomplete deflate data\n"));
		break;
	case Z_MEM_ERROR:
		::OutputDebugString(_T("out of memory\n"));
		break;
	case Z_VERSION_ERROR:
		::OutputDebugString(_T("zlib version mismatch!\n"));
	}
}


long CDemoOCXCtrl::ReadImagesFromCArchive(const BSTR& fullFilePath)
{
	CString temp{ fullFilePath };
	if (!PathRenameExtension(temp.GetBuffer(), _T(".tmp")))	// small code duplication, but I am in a hurry
		return -1;

	CFile pFile;
	CFileException ex;

	if (pFile.Open(temp.GetBuffer(), CFile::modeRead | CFile::shareDenyNone, &ex) == FALSE)
	{
		TCHAR szError[1024];
		ex.GetErrorMessage(szError, 1024);
		_tprintf_s(_T("\nReadImagesFromCArchive error: %1024s\n"), szError);
		::OutputDebugString(szError);
		return -2;
	}

	CArchive archive(&pFile, CArchive::load | CArchive::bNoFlushOnDelete);

	if (!m_pImageList.Read(&archive))
	{
		archive.Close();
		pFile.Close();
		return -3;
	}

	archive.Close();
	pFile.Close();
	return 0;
}

long CDemoOCXCtrl::ImportImageList(BSTR fullFilePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_pImageList.SetImageCount(0);

	this->Invalidate();
	this->UpdateWindow();

	CStringA importedFile{ fullFilePath };		// https://stackoverflow.com/a/859339	-> fopen uses char*
	CStringA decoded{ fullFilePath };			// https://stackoverflow.com/a/859339	-> fopen uses char*
	if (!PathRenameExtensionA(decoded.GetBuffer(), ".tmp"))	// create temp file in the same directory
		return -1;

	FILE* fInFile = NULL, * fOutFile = NULL;

	if ((fInFile = fopen(importedFile.GetBuffer(), "rb")) == NULL)
	{
		return -2;
	}

	if ((fOutFile = fopen(decoded.GetBuffer(), "wb")) == NULL)
	{
		fclose(fInFile);
		return -3;
	}

	// let us test with official example: https://zlib.net/zpipe.c
	long ret = inf(fInFile, fOutFile);
	fclose(fInFile);
	fclose(fOutFile);

	if (ret != Z_OK)
	{
		zerr(ret);
		DeleteFileA(decoded.GetBuffer());
		return -4;
	}

	ret = ReadImagesFromCArchive(fullFilePath);
	DeleteFileA(decoded.GetBuffer());

	this->Invalidate();
	this->UpdateWindow();

	return ret ? -5 : 0;
}


long CDemoOCXCtrl::CreateCArchive(const BSTR& fullFilePath)
{
	CString temp{ fullFilePath };

	if (!PathRenameExtension(temp.GetBuffer(), _T(".tmp")))		// small code duplication, but I am in a hurry
		return -1;

	CFile pFile;
	CFileException ex;

	if (pFile.Open(temp.GetBuffer(), CFile::modeWrite | CFile::modeCreate, &ex) == FALSE)
	{
		TCHAR szError[1024];
		ex.GetErrorMessage(szError, 1024);
		_tprintf_s(_T("\nCreateCArchive error: %1024s\n"), szError);
		::OutputDebugString(szError);
		return -2;
	}

	CArchive archive(&pFile, CArchive::store);
	if (FALSE == m_pImageList.Write(&archive))
	{
		TCHAR szError[1024];
		pFile.Close();
		archive.Close();
		return -3;
	}

	archive.Close();
	pFile.Close();
	return 0;
}

LONG CDemoOCXCtrl::ExportImageListToFile(BSTR fullFilePath)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	long ret = CreateCArchive(fullFilePath);
	if (ret != 0)
		return -1;

	FILE* fInFile = NULL, * fOutFile = NULL;

	CStringA tmp{ fullFilePath };				// https://stackoverflow.com/a/859339	-> fopen uses char*
	if (!PathRenameExtensionA(tmp.GetBuffer(), ".tmp"))
		return -2;

	if ((fInFile = fopen(tmp.GetBuffer(), "rb")) == NULL)
	{
		errno_t err;
		int i;
		err = _get_errno(&i);
		return -3;
	}

	CStringA encoded{ fullFilePath };			// https://stackoverflow.com/a/859339	-> fopen uses char*

	if ((fOutFile = fopen(encoded.GetBuffer(), "wb")) == NULL)
	{
		fclose(fInFile);
		DeleteFileA(tmp.GetBuffer());
		return -4;
	}

	// let us test with official example, since our modified code does not work: https://zlib.net/zpipe.c
	ret = def(fInFile, fOutFile, Z_BEST_COMPRESSION);

	if (ret != Z_OK)
	{
		zerr(ret);
	}

	fclose(fInFile);
	fclose(fOutFile);
	DeleteFileA(tmp.GetBuffer());

	return ret == Z_OK ? 0 : -5;
}


void CDemoOCXCtrl::EmptyImageList()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_pImageList.SetImageCount(0);
	this->Invalidate();
	this->UpdateWindow();
}


void CDemoOCXCtrl::AddTestImages()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	EmptyImageList();

	CBitmap CBmp;
	if (CBmp.LoadOEMBitmap(OBM_CHECKBOXES))
	{
		for (int i = 0; i < 3; ++i)
			m_pImageList.Add(&CBmp, RGB(255, 255, 255));
	}

	this->Invalidate();
	this->UpdateWindow();
}
