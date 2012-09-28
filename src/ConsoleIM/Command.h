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

class CLoginCommand : public Command
{
public:
	CLoginCommand(CUserInfo* ,std::wstring);
	~CLoginCommand();

	virtual bool Execute();
	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
	std::wstring m_strUserName;
};

class CSetStateCommond : public Command
{
public:
	CSetStateCommond(CUserInfo* pCurrentUser, UserState state);
	~CSetStateCommond();

private:
	CUserInfo* m_pCurrentUser;
	UserState m_eState;
};

class CLogoutCommand : public Command
{
public:
	CLogoutCommand(CUserInfo* pCurrentUser);
	~CLogoutCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
};

class CShowUsersCommand : public Command
{
public:
	CShowUsersCommand(CUserInfo* pCurrentUser);
	~CShowUsersCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
};

class CSendMessageCommand : public Command
{
public:
	CSendMessageCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser, const std::wstring& strMsg);
	~CSendMessageCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
	std::wstring m_strMsg;
};

class CMessageRepository;
class CShowMessageHistoryCommand : public Command
{
public:
	CShowMessageHistoryCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser, CMessageRepository* pMsgRepository);
	~CShowMessageHistoryCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
	CMessageRepository* m_pMsgRespository;
};

class CReceiveMessageCommand : public Command
{
public:
	CReceiveMessageCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser, CMessageRepository* pMsgRepository);
	~CReceiveMessageCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
	CMessageRepository* m_pMsgRespository;
};

class CHeartBeatCommand : public Command
{
public:
	CHeartBeatCommand(CUserInfo* pCurrentUser);
	~CHeartBeatCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
};

class CRequestOnlineMessageCommand : public Command
{
public:
	CRequestOnlineMessageCommand(CUserInfo* pCurrentUser);
	~CRequestOnlineMessageCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
};

class CResponseOnlineMessageCommand : public Command
{
public:
	CResponseOnlineMessageCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser);
	~CResponseOnlineMessageCommand();

	virtual bool Execute();

	virtual std::string GetErrorInfo();

private:
	CUserInfo* m_pCurrentUser;
	CUserInfo* m_pOtherUser;
};
