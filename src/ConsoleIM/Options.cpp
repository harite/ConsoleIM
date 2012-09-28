#include "stdafx.h"
#include "Options.h"
#include "Command.h"
#include "GoablInfo.h"
#include "OnlineUsers.h"
#include "MessageRepository.h"

COptions::COptions(void)
{
}


COptions::~COptions(void)
{
}

void COptions::ImportOptions(std::wistream& in, std::vector<std::wstring>& optionVector)
{
	wchar_t ch;
	std::wstring currentToken;
	while (in)
	{
		currentToken = L"";
		do 
		{
			in.get(ch);
			if (in.eof() || ch == L' ' || ch == L'\t' || ch == L'' || ch == L'\n')
			{
				break;
			}
			else
			{
				currentToken.append(1, ch);
			}

		} while (in);
		if (currentToken.length() != 0)
		{
			optionVector.push_back(currentToken);
		}
	}
}

void COptions::ParseOptions(const std::vector<std::wstring>& optionVector, 
							Command** ppCommand)
{
	ASSERT(ppCommand == NULL && *ppCommand == NULL);
	std::vector<std::wstring>::iterator option = optionVector.begin();
	std::wstring arg = *option;

	CUserInfo* pCurrentUser = CGoablInfo::GetInstance()->GetCurrentUser();
	if (IsOption(arg, L"login"))
	{
		++option;
		*ppCommand = new CLoginCommand(pCurrentUser, *option);
	}
	else if (IsOption(arg, L"set"))
	{
		++option;
		//todo
	}
	else if (IsOption(arg, L"quit"))
	{
		*ppCommand = new CLogoutCommand(pCurrentUser);
	}
	else if (IsOption(arg, L"users"))
	{
		*ppCommand = new CShowUsersCommand(pCurrentUser);
	}
	else if (IsOption(arg, L"msg"))
	{
		++option;
		CUserInfo* pOtherUser = COnlineUsers::GetInstance()->GetUserByName(*option);
		++option;
		*ppCommand = new CSendMessageCommand(pCurrentUser, pOtherUser, *option);
	}
	else if (IsOption(arg, L"show"))
	{
		++option;
		CUserInfo* pOtherUser = COnlineUsers::GetInstance()->GetUserByName(*option);
		*ppCommand = new CShowMessageHistoryCommand(pCurrentUser, pOtherUser, CMessageRepository::GetInstance());
	}

}

bool COptions::IsOption(const std::wstring& arg, const wchar_t* op)
{
	return arg.compare(op) == 0;
}
