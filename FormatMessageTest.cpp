// FormatMessageTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
	return 0;
}
