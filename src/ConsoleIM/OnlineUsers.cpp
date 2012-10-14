#include "stdafx.h"
#include "OnlineUsers.h"
#include "UserInfo.h"

COnlineUsers* COnlineUsers::m_pInstance = NULL;
COnlineUsers::COnlineUsers(void)
{
}

COnlineUsers::~COnlineUsers(void)
{
}

CUserInfo* COnlineUsers::GetUserByName(const std::wstring& strUserName) const
{
	std::map< std::wstring, CUserInfo* >::const_iterator it = m_OnlineUsers.find(strUserName);
	if (it != m_OnlineUsers.end())
	{
		return it->second;
	}
	else
	{
		return NULL;
	}
}

void COnlineUsers::AddUser( const std::wstring& strUserName, CUserInfo* pUserInfo )
{
	std::map< std::wstring, CUserInfo* >::iterator it = m_OnlineUsers.find(strUserName);
	assert(it == m_OnlineUsers.end());
	m_OnlineUsers[strUserName] = pUserInfo;
}

void COnlineUsers::RemoveUser( const std::wstring& strUserName )
{
	std::map< std::wstring, CUserInfo* >::iterator it = m_OnlineUsers.find(strUserName);
	assert(it != m_OnlineUsers.end());
	delete it->second;
	m_OnlineUsers.erase(it);
}

void COnlineUsers::GetUserList(std::vector<std::wstring>& vectorUsers)
{
	std::map<std::wstring, CUserInfo*>::iterator it = m_OnlineUsers.begin();
	for (; it != m_OnlineUsers.end(); it++)
	{
		vectorUsers.push_back(it->first);
	}
}

COnlineUsers* COnlineUsers::GetInstance()
{
	if (m_pInstance == NULL)
	{
		m_pInstance = new COnlineUsers;
	}
	return m_pInstance;
}


