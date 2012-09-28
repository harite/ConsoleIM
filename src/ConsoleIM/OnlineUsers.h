#pragma once
class CUserInfo;
class COnlineUsers
{
public:
	COnlineUsers(void);
	virtual ~COnlineUsers(void);

	CUserInfo* GetUserByName(const std::wstring strUserName) const;

public:
	static COnlineUsers* GetInstance();

private:
	std::map< std::wstring, CUserInfo* > m_OnlineUsers;
};

