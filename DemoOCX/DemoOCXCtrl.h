#pragma once

// DemoOCXCtrl.h : Declaration of the CDemoOCXCtrl ActiveX Control class.


// CDemoOCXCtrl : See DemoOCXCtrl.cpp for implementation.

class CDemoOCXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CDemoOCXCtrl)

	// Constructor
public:
	CDemoOCXCtrl();

	// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

	// Implementation
protected:
	~CDemoOCXCtrl();

	DECLARE_OLECREATE_EX(CDemoOCXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CDemoOCXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CDemoOCXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CDemoOCXCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

	// Dispatch maps
	DECLARE_DISPATCH_MAP()

	// Event maps
	DECLARE_EVENT_MAP()

	// Dispatch and event IDs
public:
	enum {
		dispidAddTestImages = 4L,
		dispidEmptyImageList = 3L,
		dispidExportImageListToFile = 2L,
		dispidImportImageList = 1L,
	};

private:
	CImageList m_pImageList;

	//******************* original ZLIB code from here: https://zlib.net/zpipe.c ********************/
	/* Compress from file source to file dest until EOF on source.
	def() returns Z_OK on success, Z_MEM_ERROR if memory could not be
	allocated for processing, Z_STREAM_ERROR if an invalid compression
	level is supplied, Z_VERSION_ERROR if the version of zlib.h and the
	version of the library linked do not match, or Z_ERRNO if there is
	an error reading or writing the files. */
	int def(FILE* source, FILE* dest, int level);

	/* Decompress from file source to file dest until stream ends or EOF.
	inf() returns Z_OK on success, Z_MEM_ERROR if memory could not be
	allocated for processing, Z_DATA_ERROR if the deflate data is
	invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
	the version of the library linked do not match, or Z_ERRNO if there
	is an error reading or writing the files. */
	int inf(FILE* source, FILE* dest);

	/* report a zlib or i/o error */
	void zerr(int ret);

	long CreateCArchive(const BSTR& fullFilePath);
	long ReadImagesFromCArchive(const BSTR& fullFilePath);

public:
	LONG ImportImageList(BSTR fullFilePath);
	LONG ExportImageListToFile(BSTR fullFilePath);
	void EmptyImageList();
	void AddTestImages();
};

