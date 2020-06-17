#include "pch.h"
#include "FormatMessage.h"

class CDebugOutput
{
public:
    CDebugOutput& operator << (LPCWSTR text)
    {
        OutputDebugStringW(text);
        char textA[1024] = { };
        WideCharToMultiByte(CP_UTF8, 0, text, wcslen(text) + 1, textA, 1024, NULL, NULL);
        wprintf(L"%S", textA);
        return *this;
    }

    CDebugOutput& operator << (LPCSTR text)
    {
        OutputDebugStringA(text);
        printf("%s", text);
        return *this;
    }

    CDebugOutput& operator << (DWORD value)
    {
        WCHAR text[256];
        wsprintf(text, L"%d", value);
        return operator << (text);
    }

    CDebugOutput& operator << (const CFormatMessage& formatMessage)
    {
        return operator << (formatMessage.MessageText());
    }

};

CDebugOutput debugOutput;

void test(LPCWSTR testMessage, DWORD dwMessageId, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))
{
    debugOutput << "Test: " << testMessage << "\n";
    debugOutput << "MessageId: " << dwMessageId << "\n";
    debugOutput << "MessageText: " << CFormatMessage(dwMessageId, dwLanguageId).MessageText() << "\n";
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    test(L"ERROR_SUCCESS (Default)", ERROR_SUCCESS); // The operation completed successfully.
    test(L"ERROR_SUCCESS (French Française)", ERROR_SUCCESS, MAKELANGID(LANG_FRENCH, SUBLANG_DEFAULT)); // L’opération a réussi.
    test(L"ERROR_SUCCESS (Japanese 日本語)", ERROR_SUCCESS, MAKELANGID(LANG_JAPANESE, SUBLANG_DEFAULT)); // この操作を正しく終了しました。
    test(L"ERROR_INVALID_FUNCTION", ERROR_INVALID_FUNCTION); // Incorrect function.
    test(L"ERROR_FILE_NOT_FOUND", ERROR_FILE_NOT_FOUND); // The system cannot find the file specified.
    test(L"ERROR_ACCESS_DENIED", ERROR_ACCESS_DENIED); // Access is denied.
    test(L"ERROR_INVALID_HANDLE", ERROR_INVALID_HANDLE); // The handle is invalid.
    test(L"ERROR_NOT_ENOUGH_MEMORY", ERROR_NOT_ENOUGH_MEMORY); // Not enough memory resources are available to process this command.
    test(L"ERROR_OUTOFMEMORY", ERROR_OUTOFMEMORY); // Not enough memory resources are available to complete this operation.
    test(L"ERROR_NOT_SUPPORTED", ERROR_NOT_SUPPORTED); // The request is not supported.
    return 0;
}
