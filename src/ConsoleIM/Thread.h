#pragma once
class CThread
{
public:
    CThread(void);
    virtual ~CThread(void);

protected:
    void Start();
    void Stop();
    virtual void Execute() = 0;

    //todo
    //DWORD WaitFor(int milliseconds);
    //void Termiate();
    //bool IsBusy();


private:
    static unsigned int __stdcall ThreadProc(LPVOID pData);

protected:
    HANDLE m_hCancelEvent;
    HANDLE m_hThread;
    unsigned  m_nThreadId;

};

