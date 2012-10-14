// ConsoleIM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CommandProcesser.h"
#include "Command.h"

void WelecomeMessage()
{
    std::cout << "Hello, welcom use consoleIM." << std::endl;
    std::cout << "These are commands for this tool:" << std::endl;
    std::cout << "1. "  << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    CCommandProcesser* pProcesser = new CCommandProcesser;
    pProcesser->Initialize();
    CSetStateCommond* pCommand = new CSetStateCommond(NULL, STATE_Quit);
    pProcesser->InsertCommand(pCommand);
    pProcesser->InsertCommand(pCommand);
    pProcesser->InsertCommand(pCommand);
    pProcesser->UnInitialize();
    delete pProcesser;
    pProcesser = NULL;
    int i = 0;
    WelecomeMessage();
    std::cin >> i;

	return 0;
}