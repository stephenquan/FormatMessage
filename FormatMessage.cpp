#include "pch.h"
#include "FormatMessage.h"

CFormatMessage::CFormatMessage(DWORD dwMessageId, DWORD dwLanguageId) :
    m_dwMessageId(ERROR_SUCCESS),
    m_dwLanguageId(0),
    m_szMessageText(NULL)
{
    Assign(dwMessageId, dwLanguageId);
}

CFormatMessage::CFormatMessage(const CFormatMessage& other) :
    m_dwMessageId(ERROR_SUCCESS),
    m_dwLanguageId(0),
    m_szMessageText(NULL)
{
    Assign(other);
}

CFormatMessage::CFormatMessage(CFormatMessage&& other) :
    m_dwMessageId(other.m_dwMessageId),
    m_dwLanguageId(other.m_dwLanguageId),
    m_szMessageText(other.m_szMessageText)
{
    other.m_dwMessageId = 0;
    other.m_dwLanguageId = 0;
    other.m_szMessageText = NULL;
}

CFormatMessage::~CFormatMessage()
{
    Clear();
}
            
void CFormatMessage::Clear()
{
    if (!m_szMessageText)
    {
        return;
    }
    LocalFree(m_szMessageText);
    m_szMessageText = NULL;
    m_dwMessageId = ERROR_SUCCESS;
}

void CFormatMessage::Assign(DWORD dwMessageId, DWORD dwLanguageId)
{
    Clear();
    m_dwMessageId = dwMessageId;
    m_dwLanguageId = dwLanguageId;
    ::FormatMessage(
        FORMAT_MESSAGE_FROM_SYSTEM
        | FORMAT_MESSAGE_ALLOCATE_BUFFER
        | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        m_dwMessageId,
        m_dwLanguageId,
        (LPTSTR)&m_szMessageText,
        0,
        NULL
    );
}

void CFormatMessage::Assign(const CFormatMessage& other)
{
    Assign(other.MessageId(), other.m_dwLanguageId);
}

CFormatMessage& CFormatMessage::operator= (const CFormatMessage& other)
{
    Assign(other);
    return *this;
}
