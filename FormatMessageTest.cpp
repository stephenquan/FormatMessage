#include "pch.h"
#include "FormatMessage.h"

void test(LPCTSTR testMessage, DWORD dwError, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))
{
    OutputDebugString(testMessage);
    OutputDebugString((LPTSTR)CFormatMessage(dwError, dwLanguageId));
    OutputDebugString(_T("\n"));
}

int main()
{
    test(_T("ERROR_SUCCESS (Default): "), ERROR_SUCCESS); // The operation completed successfully.
    test(_T("ERROR_SUCCESS (French Française): "), ERROR_SUCCESS, MAKELANGID(LANG_FRENCH, SUBLANG_DEFAULT)); // L’opération a réussi.
    test(_T("ERROR_SUCCESS (Japanese 日本語): "), ERROR_SUCCESS, MAKELANGID(LANG_JAPANESE, SUBLANG_DEFAULT)); // この操作を正しく終了しました。
    test(_T("ERROR_INVALID_FUNCTION: "), ERROR_INVALID_FUNCTION); // Incorrect function.
    test(_T("ERROR_FILE_NOT_FOUND: "), ERROR_FILE_NOT_FOUND); // The system cannot find the file specified.
    test(_T("ERROR_ACCESS_DENIED: "), ERROR_ACCESS_DENIED); // Access is denied.
    test(_T("ERROR_INVALID_HANDLE: "), ERROR_INVALID_HANDLE); // The handle is invalid.
    test(_T("ERROR_NOT_ENOUGH_MEMORY: "), ERROR_NOT_ENOUGH_MEMORY); // Not enough memory resources are available to process this command.
    test(_T("ERROR_OUTOFMEMORY: "), ERROR_OUTOFMEMORY); // Not enough memory resources are available to complete this operation.
    test(_T("ERROR_NOT_SUPPORTED: "), ERROR_NOT_SUPPORTED); // The request is not supported.
    return 0;
}
