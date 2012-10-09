#include "stdafx.h"
#include "GoablInfo.h"

CGoablInfo* CGoablInfo::m_pInstance = NULL;
CGoablInfo::CGoablInfo(void)
{
}


CGoablInfo::~CGoablInfo(void)
{
}

CGoablInfo* CGoablInfo::GetInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new CGoablInfo;
	}
	return m_pInstance;
}

CUserInfo* CGoablInfo::GetCurrentUser()
{
    return m_pCurrentUser;
}
