#include "pch.h"
#include "FormatMessage.h"

int main()
{
    std::wcout << L"ERROR_SUCCESS: " << (LPTSTR) CFormatMessage(ERROR_SUCCESS) << L"\n";
    std::wcout << L"ERROR_INVALID_FUNCTION: " << (LPTSTR)CFormatMessage(ERROR_INVALID_FUNCTION) << L"\n";
    std::wcout << L"ERROR_FILE_NOT_FOUND: " << (LPTSTR)CFormatMessage(ERROR_FILE_NOT_FOUND) << L"\n";
    std::wcout << L"ERROR_ACCESS_DENIED: " << (LPTSTR)CFormatMessage(ERROR_ACCESS_DENIED) << L"\n";
    std::wcout << L"ERROR_INVALID_HANDLE: " << (LPTSTR)CFormatMessage(ERROR_INVALID_HANDLE) << L"\n";
    std::wcout << L"ERROR_NOT_ENOUGH_MEMORY: " << (LPTSTR)CFormatMessage(ERROR_NOT_ENOUGH_MEMORY) << L"\n";
    std::wcout << L"ERROR_OUTOFMEMORY: " << (LPTSTR)CFormatMessage(ERROR_OUTOFMEMORY) << L"\n";
    std::wcout << L"ERROR_NOT_SUPPORTED: " << (LPTSTR)CFormatMessage(ERROR_NOT_SUPPORTED) << L"\n";

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
