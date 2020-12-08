
// I have right-clicked on this file -> Properties -> Configuration Properties -> C/C++ -> Precompiled headers -> Not using precompiled headers

#include <comdef.h>
#include "FileOpenDlg.h"

using namespace FileDialog;

inline void throw_if_fail(HRESULT hr)
{
	if (FAILED(hr))
	{
		throw _com_error(hr);
	}
}

COpenFileDialog::COpenFileDialog()
{
	throw_if_fail(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen)));
}

void COpenFileDialog::SetOptions(FILEOPENDIALOGOPTIONS fos)
{
	DWORD dwOptions;
	throw_if_fail(pFileOpen->GetOptions(&dwOptions));
	dwOptions |= fos;
	throw_if_fail(pFileOpen->SetOptions(dwOptions));
}

void COpenFileDialog::SetFileTypes(const COMDLG_FILTERSPEC* fileTypes, UINT array_size)
{
	throw_if_fail(pFileOpen->SetFileTypes(array_size, fileTypes));
}

void COpenFileDialog::SetTitle(LPCWSTR title)
{
	throw_if_fail(pFileOpen->SetTitle(title));
}

void COpenFileDialog::SetFolder(PCWSTR folder)
{
	CComPtr<IShellItem> pItem{};
	throw_if_fail(SHCreateItemFromParsingName(folder, 0, IID_IShellItem, reinterpret_cast<void**>(&pItem)));
	throw_if_fail(pFileOpen->SetFolder(pItem));
}

void COpenFileDialog::SetDefaultFolder(PCWSTR folder)
{
	CComPtr<IShellItem> pItem{};
	throw_if_fail(SHCreateItemFromParsingName(folder, 0, IID_IShellItem, reinterpret_cast<void**>(&pItem)));
	throw_if_fail(pFileOpen->SetDefaultFolder(pItem));
}

void COpenFileDialog::SetFileTypeIndex(UINT iFileType)
{
	throw_if_fail(pFileOpen->SetFileTypeIndex(iFileType));
}

int COpenFileDialog::DoModal(HWND owner)
{
	HRESULT hr = pFileOpen->Show(owner);

	if (S_OK == hr)
	{
		return IDOK;
	}

	if (hr == HRESULT_FROM_WIN32(ERROR_CANCELLED))
	{
		return IDCANCEL;
	}

	throw _com_error(hr);
}

std::wstring COpenFileDialog::GetFullPath()
{
	CComPtr<IShellItem> pItem{};
	throw_if_fail(pFileOpen->GetResult(&pItem));
	CComHeapPtr<WCHAR> pszFilePath{};
	throw_if_fail(pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath));
	return std::wstring(pszFilePath);
}

UINT COpenFileDialog::GetFileTypeIndex()
{
	UINT i = 0;
	throw_if_fail(pFileOpen->GetFileTypeIndex(&i));
	return i;
}

void COpenFileDialog::GetOptions(FILEOPENDIALOGOPTIONS* pfos)
{
	throw_if_fail(pFileOpen->GetOptions(pfos));
}