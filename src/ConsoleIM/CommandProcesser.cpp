#include "stdafx.h"
#include "CommandProcesser.h"
#include "Command.h"


CCommandProcesser::CCommandProcesser(void):
    m_eStatus(EPS_Idle)
{
}


CCommandProcesser::~CCommandProcesser(void)
{
}


void CCommandProcesser::Initialize()
{
    Start();
}

void CCommandProcesser::UnInitialize()
{
    std::cout << m_CommandList.size() << std::endl;
    Stop();
    //std::cout << m_CommandList.size() << std::endl;
}

void CCommandProcesser::Execute()
{
    do 
    {
        if (m_eStatus == EPS_Idle)
        {
            if (m_CommandList.size() != 0)
            {
                Command* pCommand = m_CommandList.front();
                m_CommandList.pop_front();
                m_eStatus = EPS_Busy;
                pCommand->Execute();
                m_eStatus = EPS_Idle;
            }
        }   
    } while (WAIT_OBJECT_0 != WaitForSingleObject(m_hCancelEvent, 0));

}

void CCommandProcesser::InsertCommand(Command* pCommand)
{
    assert(pCommand != NULL);
    m_CommandList.push_back(pCommand);
}
