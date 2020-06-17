#include "pch.h"
#include "FormatMessage.h"

CFormatMessage::CFormatMessage(DWORD dwMessageId, DWORD dwLanguageId) :
    m_dwMessageId(ERROR_SUCCESS),
    m_dwLanguageId(0),
    m_szMessageTextA(nullptr),
    m_szMessageTextW(nullptr)
{
    Assign(dwMessageId, dwLanguageId);
}

CFormatMessage::CFormatMessage(const CFormatMessage& other) :
    m_dwMessageId(ERROR_SUCCESS),
    m_dwLanguageId(0),
    m_szMessageTextA(nullptr),
    m_szMessageTextW(nullptr)
{
    Assign(other);
}

CFormatMessage::CFormatMessage(CFormatMessage&& other) :
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

CFormatMessage::~CFormatMessage()
{
    Clear();
}
            
void CFormatMessage::Clear()
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

void CFormatMessage::Assign(DWORD dwMessageId, DWORD dwLanguageId)
{
    Clear();
    DWORD dwFlags = FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS;
    m_dwMessageId = dwMessageId;
    m_dwLanguageId = dwLanguageId;
    ::FormatMessageA(dwFlags, NULL, m_dwMessageId, m_dwLanguageId, (LPSTR)&m_szMessageTextA, 0, NULL);
    ::FormatMessageW(dwFlags, NULL, m_dwMessageId, m_dwLanguageId, (LPWSTR)&m_szMessageTextW, 0, NULL);
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
