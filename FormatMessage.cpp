#include "pch.h"
#include "FormatMessage.h"

CFormatMessage::CFormatMessage(DWORD dwError, DWORD dwLanguageId) :
    m_Error(ERROR_SUCCESS),
    m_ErrorText(NULL)
{
    Assign(dwError, dwLanguageId);
}

CFormatMessage::CFormatMessage(const CFormatMessage& other) :
    m_Error(ERROR_SUCCESS),
    m_ErrorText(NULL)
{
    Assign(other);
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

void CFormatMessage::Assign(DWORD dwError, DWORD dwLanguageId)
{
    Clear();
    m_Error = dwError;
    m_LanguageId = dwLanguageId;
    ::FormatMessage(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        m_Error,
        m_LanguageId,
        (LPTSTR)&m_ErrorText,
        0,
        NULL
    );
}

void CFormatMessage::Assign(const CFormatMessage& other)
{
    Assign(other.Error(), other.m_LanguageId);
}

CFormatMessage& CFormatMessage::operator= (const CFormatMessage& other)
{
    Assign(other);
    return *this;
}
