#ifndef FormatMessage_H
#define FormatMessage_H

class CFormatMessage
{
public:
    CFormatMessage(DWORD dwError);
    CFormatMessage(const CFormatMessage& other);
    ~CFormatMessage();
           
    void Clear();
    void Assign(DWORD dwError);
    void Assign(const CFormatMessage& other);
    DWORD Error() const { return m_Error; }
    LPTSTR ErrorText() const { return m_ErrorText; }
    operator LPTSTR() const { return ErrorText(); }
    CFormatMessage& operator= (const CFormatMessage& other);

protected:
    DWORD m_Error;
    LPTSTR m_ErrorText;

};

#endif
