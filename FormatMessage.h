#ifndef FormatMessage_H
#define FormatMessage_H

class CFormatMessage
{
public:
    CFormatMessage(DWORD dwMessageId, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT));
    CFormatMessage(const CFormatMessage& other);
    CFormatMessage(CFormatMessage&& other);
    ~CFormatMessage();
           
    void Clear();
    void Assign(DWORD dwMessageId, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT));
    void Assign(const CFormatMessage& other);
    DWORD MessageId() const { return m_dwMessageId; }
    LPCSTR MessageTextA() const { return _messageText<char>(); }
    LPCWSTR MessageTextW() const { return _messageText<WCHAR>(); }
    LPCTSTR MessageText() const { return _messageText<TCHAR>(); }
    DWORD LanguageId() const { return m_dwLanguageId; }
    operator DWORD() const { return m_dwMessageId; }
    operator LPCTSTR() const { return MessageText(); }
    CFormatMessage& operator= (DWORD dwMessageId) { Assign(dwMessageId); }
    CFormatMessage& operator= (const CFormatMessage& other);

protected:
    DWORD m_dwMessageId;
    DWORD m_dwLanguageId;
    LPSTR m_szMessageTextA;
    LPWSTR m_szMessageTextW;

    template <class T> T* _messageText() const { return nullptr; }
    template <> char* _messageText<char>() const { return m_szMessageTextA; }
    template <> WCHAR* _messageText<WCHAR>() const { return m_szMessageTextW; }

};

#endif
