#ifndef FormatMessage_H
#define FormatMessage_H

class CFormatMessage
{
public:
    CFormatMessage(DWORD dwError) :
        m_Error(ERROR_SUCCESS),
        m_ErrorText(NULL)
    {
        Assign(dwError);
    }

    CFormatMessage(const CFormatMessage& other) :
        m_Error(ERROR_SUCCESS),
        m_ErrorText(NULL)
    {
        Assign(other.Error());
    }

    ~CFormatMessage()
    {
        Clear();
    }
            
    void Clear()
    {
        if (m_ErrorText != NULL)
        {
            LocalFree(m_ErrorText);
            m_ErrorText = NULL;
        }
        m_Error = ERROR_SUCCESS;
    }

    void Assign(DWORD dwError)
    {
        Clear();
        m_Error = dwError;
        ::FormatMessage(
            FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            m_Error,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPTSTR)&m_ErrorText,
            0,
            NULL
        );
    }

    void Assign(const CFormatMessage& other)
    {
        Assign(other.Error());
    }

    DWORD Error() const { return m_Error; }
    LPTSTR ErrorText() const { return m_ErrorText; }
    operator LPTSTR() const { return ErrorText(); }
    CFormatMessage& operator= (const CFormatMessage& other)
    {
        Assign(other.Error());
        return *this;
    }

protected:
    DWORD m_Error;
    LPTSTR m_ErrorText;

};

#endif
