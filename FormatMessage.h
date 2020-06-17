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
    LPTSTR MessageText() const { return m_szMessageText; }
    DWORD LanguageId() const { return m_dwLanguageId; }
    operator DWORD() const { return m_dwMessageId; }
    operator LPTSTR() const { return MessageText(); }
    operator LPCTSTR() const { return MessageText(); }
    CFormatMessage& operator= (DWORD dwMessageId) { Assign(dwMessageId); }
    CFormatMessage& operator= (const CFormatMessage& other);

protected:
    DWORD m_dwMessageId;
    DWORD m_dwLanguageId;
    LPTSTR m_szMessageText;

};

#endif
