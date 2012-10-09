#pragma once
class CUserInfo;
class COnlineUsers
{
public:
	COnlineUsers(void);
	virtual ~COnlineUsers(void);

	CUserInfo* GetUserByName(const std::wstring& strUserName) const;
	void AddUser(const std::wstring& strUserName, CUserInfo* pUserInfo);
	void RemoveUser(const std::wstring& strUserName);
	void GetUserList(std::vector<std::wstring>& vectorUsers);

public:
	static COnlineUsers* GetInstance();

private:
	std::map< std::wstring, CUserInfo* > m_OnlineUsers;
	static COnlineUsers* m_pInstance;
};

