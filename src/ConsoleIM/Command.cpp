#include "stdafx.h"
#include "Command.h"
#include "UserInfo.h"

Command::Command(void)
{
}


Command::~Command(void)
{
}

CLoginCommand::CLoginCommand( CUserInfo* pCurrentUser, std::wstring strUsername)
:m_pCurrentUser(pCurrentUser),
m_strUserName(strUsername)
{

}

bool CLoginCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CLoginCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CSetStateCommond::CSetStateCommond( CUserInfo* pCurrentUser, UserState state )
:m_pCurrentUser(pCurrentUser),
m_eState(state)
{

}

bool CSetStateCommond::Execute()
{
    throw std::exception("The method or operation is not implemented.");
}

std::string CSetStateCommond::GetErrorInfo()
{
    throw std::exception("The method or operation is not implemented.");
}

CLogoutCommand::CLogoutCommand( CUserInfo* pCurrentUser )
:m_pCurrentUser(pCurrentUser)
{

}

bool CLogoutCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CLogoutCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CShowUsersCommand::CShowUsersCommand( CUserInfo* pCurrentUser )
:m_pCurrentUser(pCurrentUser)
{

}

bool CShowUsersCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CShowUsersCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CSendMessageCommand::CSendMessageCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser, const std::wstring& strMsg)
:m_pCurrentUser(pCurrentUser),
m_pOtherUser(pOtherUser),
m_strMsg(strMsg)
{
    
}

bool CSendMessageCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CSendMessageCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CShowMessageHistoryCommand::CShowMessageHistoryCommand(CUserInfo* pCurrentUser, CUserInfo* pOtherUser, CMessageRepository* pMsgRepository)
:m_pCurrentUser(pCurrentUser),
m_pOtherUser(pOtherUser),
m_pMsgRespository(pMsgRepository)
{

}

bool CShowMessageHistoryCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CShowMessageHistoryCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CReceiveMessageCommand::CReceiveMessageCommand( CUserInfo* pCurrentUser, CUserInfo* pOtherUser, CMessageRepository* pMsgRepository )
:m_pCurrentUser(pCurrentUser),
m_pOtherUser(pOtherUser),
m_pMsgRespository(pMsgRepository)
{

}
bool CReceiveMessageCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CReceiveMessageCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CHeartBeatCommand::CHeartBeatCommand( CUserInfo* pCurrentUser )
:m_pCurrentUser(pCurrentUser)
{

}

bool CHeartBeatCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CHeartBeatCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CRequestOnlineMessageCommand::CRequestOnlineMessageCommand( CUserInfo* pCurrentUser )
:m_pCurrentUser(pCurrentUser)
{

}
bool CRequestOnlineMessageCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CRequestOnlineMessageCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}

CResponseOnlineMessageCommand::CResponseOnlineMessageCommand( CUserInfo* pCurrentUser, CUserInfo* pOtherUser )
:m_pCurrentUser(pCurrentUser),
m_pOtherUser(pOtherUser)
{
    
}

bool CResponseOnlineMessageCommand::Execute()
{
	throw std::exception("The method or operation is not implemented.");
}

std::string CResponseOnlineMessageCommand::GetErrorInfo()
{
	throw std::exception("The method or operation is not implemented.");
}