#ifndef FormatMessage_H
#define FormatMessage_H

class CFormatMessage
{
public:
    CFormatMessage(DWORD dwError, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT));
    CFormatMessage(const CFormatMessage& other);
    ~CFormatMessage();
           
    void Clear();
    void Assign(DWORD dwError, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT));
    void Assign(const CFormatMessage& other);
    DWORD Error() const { return m_Error; }
    LPTSTR ErrorText() const { return m_ErrorText; }
    DWORD LanguageId() const { return m_LanguageId; }
    operator DWORD() const { return m_Error; }
    operator LPTSTR() const { return ErrorText(); }
    operator LPCTSTR() const { return ErrorText(); }
    CFormatMessage& operator= (DWORD dwError) { Assign(dwError); }
    CFormatMessage& operator= (const CFormatMessage& other);

protected:
    DWORD m_Error;
    DWORD m_LanguageId;
    LPTSTR m_ErrorText;

};

#endif
