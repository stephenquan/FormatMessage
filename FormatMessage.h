#ifndef FormatMessage_H
#define FormatMessage_H

class CFormatMessage
{
public:
    CFormatMessage(DWORD dwMessageId, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)) :
        m_dwMessageId(ERROR_SUCCESS),
        m_dwLanguageId(0),
        m_szMessageTextA(nullptr),
        m_szMessageTextW(nullptr)
    {
        Assign(dwMessageId, dwLanguageId);
    }

    CFormatMessage(const CFormatMessage& other) :
        m_dwMessageId(ERROR_SUCCESS),
        m_dwLanguageId(0),
        m_szMessageTextA(nullptr),
        m_szMessageTextW(nullptr)
    {
        Assign(other);
    }

    CFormatMessage(CFormatMessage&& other) :
        m_dwMessageId(other.m_dwMessageId),
        m_dwLanguageId(other.m_dwLanguageId),
        m_szMessageTextA(other.m_szMessageTextA),
        m_szMessageTextW(other.m_szMessageTextW)
    {
        other.m_dwMessageId = 0;
        other.m_dwLanguageId = 0;
        other.m_szMessageTextA = nullptr;
        other.m_szMessageTextW = nullptr;
    }

    ~CFormatMessage() { Clear(); }
           
    void Clear()
    {
        if (m_szMessageTextA)
        {
            LocalFree(m_szMessageTextA);
            m_szMessageTextA = nullptr;
        }

        if (m_szMessageTextW)
        {
            LocalFree(m_szMessageTextW);
            m_szMessageTextW = nullptr;
        }

        m_dwMessageId = ERROR_SUCCESS;
    }

    void Assign(DWORD dwMessageId, DWORD dwLanguageId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))
    {
        Clear();
        DWORD dwFlags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS;
        m_dwMessageId = dwMessageId;
        m_dwLanguageId = dwLanguageId;
        FormatMessageA(dwFlags, NULL, m_dwMessageId, m_dwLanguageId, (LPSTR)&m_szMessageTextA, 0, NULL);
        FormatMessageW(dwFlags, NULL, m_dwMessageId, m_dwLanguageId, (LPWSTR)&m_szMessageTextW, 0, NULL);
    }

    void Assign(const CFormatMessage& other) { Assign(other.MessageId(), other.LanguageId()); }
    DWORD MessageId() const { return m_dwMessageId; }
    LPCSTR MessageTextA() const { return _messageText<char>(); }
    LPCWSTR MessageTextW() const { return _messageText<WCHAR>(); }
    LPCTSTR MessageText() const { return _messageText<TCHAR>(); }
    DWORD LanguageId() const { return m_dwLanguageId; }
    operator DWORD() const { return m_dwMessageId; }
    operator LPCTSTR() const { return MessageText(); }
    CFormatMessage& operator= (DWORD dwMessageId) { Assign(dwMessageId); return *this;  }
    CFormatMessage& operator= (const CFormatMessage& other) { Assign(other); return *this; }

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
