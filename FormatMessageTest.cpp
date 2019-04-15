#include "pch.h"
#include "FormatMessage.h"

#ifdef UNICODE
#define COUT std::wcout
#else
#define COUT std::cout
#endif

int main()
{
    COUT << _T("ERROR_SUCCESS: ") << (LPTSTR) CFormatMessage(ERROR_SUCCESS) << _T("\n");
    COUT << _T("ERROR_INVALID_FUNCTION: ") << (LPTSTR)CFormatMessage(ERROR_INVALID_FUNCTION) << _T("\n");
    COUT << _T("ERROR_FILE_NOT_FOUND: ") << (LPTSTR)CFormatMessage(ERROR_FILE_NOT_FOUND) << _T("\n");
    COUT << _T("ERROR_ACCESS_DENIED: ") << (LPTSTR)CFormatMessage(ERROR_ACCESS_DENIED) << _T("\n");
    COUT << _T("ERROR_INVALID_HANDLE: ") << (LPTSTR)CFormatMessage(ERROR_INVALID_HANDLE) << _T("\n");
    COUT << _T("ERROR_NOT_ENOUGH_MEMORY: ") << (LPTSTR)CFormatMessage(ERROR_NOT_ENOUGH_MEMORY) << _T("\n");
    COUT << _T("ERROR_OUTOFMEMORY: ") << (LPTSTR)CFormatMessage(ERROR_OUTOFMEMORY) << _T("\n");
    COUT << _T("ERROR_NOT_SUPPORTED: ") << (LPTSTR)CFormatMessage(ERROR_NOT_SUPPORTED) << _T("\n");

    // Outputs:
    //
    // ERROR_SUCCESS: The operation completed successfully.
    // ERROR_INVALID_FUNCTION : Incorrect function.
    // ERROR_FILE_NOT_FOUND : The system cannot find the file specified.
    // ERROR_ACCESS_DENIED : Access is denied.
    // ERROR_INVALID_HANDLE : The handle is invalid.
    // ERROR_NOT_ENOUGH_MEMORY : Not enough memory resources are available to process this command.
    // ERROR_OUTOFMEMORY : Not enough memory resources are available to complete this operation.
    // ERROR_NOT_SUPPORTED : The request is not supported.

    return 0;
}
