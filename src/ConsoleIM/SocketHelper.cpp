#include "StdAfx.h"
#include "Sockethelper.h"

CSocketHelper::CSocketHelper(void)
{
}

CSocketHelper::~CSocketHelper(void)
{
}

void CSocketHelper::Init()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return ;
	}

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 ) 
	{
		WSACleanup();
		return ; 
	}
	return ;
}

void CSocketHelper::UnInit()
{
	WSACleanup();
}
