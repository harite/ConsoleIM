#pragma once

class CUserInfo;
class CGoablInfo
{
public:
	CGoablInfo(void);
	virtual ~CGoablInfo(void);

	CUserInfo* GetCurrentUser();

public:
	static CGoablInfo* GetInstance();

private:
	CUserInfo* m_pCurrentUser;
	unsigned __int32 m_nIpAddress;
};

