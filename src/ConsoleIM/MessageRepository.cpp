#include "stdafx.h"
#include "MessageRepository.h"

CMessageRepository* CMessageRepository::m_sInstance = NULL;
CMessageRepository::CMessageRepository(void)
{
}


CMessageRepository::~CMessageRepository(void)
{
}

CMessageRepository* CMessageRepository::GetInstance()
{
    if (m_sInstance == NULL)
    {
        m_sInstance = new CMessageRepository;
    }
    return m_sInstance;
}
