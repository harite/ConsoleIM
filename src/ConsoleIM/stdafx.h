// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#include <WinSock2.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include "assert.h"

#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>

// TODO: reference additional headers your program requires here

enum UserState
{
	STATE_Unknow,
	STATE_Nomal,
	STATE_Out,
	STATE_Quit
};
