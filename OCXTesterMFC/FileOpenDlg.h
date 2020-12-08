#pragma once

#include <shlobj.h>
#include <atlbase.h>
#include <string>

namespace FileDialog
{
	class COpenFileDialog
	{
	private:
		CComPtr<IFileOpenDialog> pFileOpen;

	public:
		COpenFileDialog();
		COpenFileDialog(const COpenFileDialog&) = delete;
		COpenFileDialog(COpenFileDialog&&) = delete;
		COpenFileDialog& operator=(const COpenFileDialog&) = delete;
		COpenFileDialog& operator=(COpenFileDialog&&) = delete;

		~COpenFileDialog() = default;

		void SetOptions(FILEOPENDIALOGOPTIONS fos);
		void SetFileTypes(const COMDLG_FILTERSPEC* fileTypes, UINT array_size);
		void SetTitle(LPCWSTR title);
		void SetFolder(PCWSTR folder);
		void SetDefaultFolder(PCWSTR folder);
		void SetFileTypeIndex(UINT iFileType);
		int DoModal(HWND owner = nullptr);
		std::wstring GetFullPath();
		UINT GetFileTypeIndex();
		void GetOptions(FILEOPENDIALOGOPTIONS* pfos);
	};
}