#pragma once
#include "Thread.h"

enum EProcesserStatus
{
    EPS_Idle,
    EPS_Busy
};

class Command;
class CCommandProcesser : public CThread
{
public:
    CCommandProcesser(void);
    virtual ~CCommandProcesser(void);

    void Initialize();
    void UnInitialize();

    void InsertCommand(Command* pCommand);

    virtual void Execute();

private:
    std::list<Command*> m_CommandList;
    EProcesserStatus m_eStatus;
};



