#pragma once

class CUserInfo;
class CMessage
{
public:
	CMessage(CUserInfo* pSender, CUserInfo* pReceiver, std::wstring strMsg);
	virtual ~CMessage(void);
	bool IsMessageWithSomeone(CUserInfo* pSomeone);
private:
	CUserInfo* m_pSender;
	CUserInfo* m_pReceiver;
	std::wstring m_strMessage;
};

class CMessageRepository
{
public:
	CMessageRepository(void);
	virtual ~CMessageRepository(void);

public:
	static CMessageRepository* GetInstance();
private:
    static CMessageRepository* m_sInstance;
};

