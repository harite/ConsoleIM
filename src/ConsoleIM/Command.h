#pragma once
class CUserInfo;
class Command
{
public:
	virtual ~Command(void);
	virtual bool Execute() = 0;
	virtual std::string GetErrorInfo() = 0;
	
protected:
	Command();
};

class LoginCommand : public Command
{
public:
	LoginCommand(CUserInfo* ,std::wstring);
	~LoginCommand();

private:
	CUserInfo* m_pCurrentUser;
	std::wstring m_strUserName;
};

class SetStateCommond : public Command
{
public:
	SetStateCommond(CUserInfo* pCurrentUser, UserState state);
	~SetStateCommond();

private:
	CUserInfo* m_pCurrentUser;
	UserState m_eState;
};

class LogoutCommand : public Command
{
public:
	LogoutCommand(CUserInfo* pCurrentUser);
	~LogoutCommand();

private:
	CUserInfo* m_pCurrentUser;
};

class ShowUsersCommand : public Command
{
public:
	ShowUsersCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser);
	~ShowUsersCommand();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
};

class SendMessageCommand : public Command
{
public:
	SendMessageCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser);
	~SendMessageCommand();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
};

class CMessageRepository;
class ShowMessageHistoryCommand : public Command
{
public:
	ShowMessageHistoryCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser, CMessageRepository* pMsgRepository);
	~ShowMessageHistoryCommand();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
	CMessageRepository* m_pMsgRespository;
};

class ReceiveMessageCommand : public Command
{
public:
	ReceiveMessageCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser, CMessageRepository* pMsgRepository);
	~ReceiveMessageCommand();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
	CMessageRepository* m_pMsgRespository;
};

class HeartBeatCommand : public Command
{
public:
	HeartBeatCommand(CUserInfo* pCurrentUser);
	~HeartBeatCommand();

private:
	CUserInfo* m_pCurrentUser;
};

class RequestOnlineMessageCommand : public Command
{
public:
	RequestOnlineMessageCommand(CUserInfo* pCurrentUser);
	~RequestOnlineMessageCommand();

private:
	CUserInfo* m_pCurrentUser;
};

class ResponseOnlineMessageCommand : public Command
{
public:
	ResponseOnlineMessageCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser);
	~ResponseOnlineMessageCommand();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
};
