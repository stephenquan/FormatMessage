#include "pch.h"
#include "FormatMessage.h"

CFormatMessage::CFormatMessage(DWORD dwError) :
    m_Error(ERROR_SUCCESS),
    m_ErrorText(NULL)
{
    Assign(dwError);
}

CFormatMessage::CFormatMessage(const CFormatMessage& other) :
    m_Error(ERROR_SUCCESS),
    m_ErrorText(NULL)
{
    Assign(other.Error());
}

CFormatMessage::~CFormatMessage()
{
    Clear();
}
            
void CFormatMessage::Clear()
{
    if (m_ErrorText != NULL)
    {
        LocalFree(m_ErrorText);
        m_ErrorText = NULL;
    }
    m_Error = ERROR_SUCCESS;
}

void CFormatMessage::Assign(DWORD dwError)
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

void CFormatMessage::Assign(const CFormatMessage& other)
{
    Assign(other.Error());
}

CFormatMessage& CFormatMessage::operator= (const CFormatMessage& other)
{
    Assign(other.Error());
    return *this;
}
