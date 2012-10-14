#include "stdafx.h"
#include "Thread.h"
#include <process.h>


CThread::CThread(void):
    m_hThread(INVALID_HANDLE_VALUE),
    m_nThreadId(0)
{
    m_hCancelEvent = ::CreateEvent(NULL, TRUE, FALSE, NULL);
}

CThread::~CThread(void)
{
    ::CloseHandle(m_hCancelEvent);
    if (m_hThread != INVALID_HANDLE_VALUE)
    {
        ::CloseHandle(m_hThread);
    }

}

void CThread::Start()
{
    if (m_hThread != INVALID_HANDLE_VALUE)
    {	
        DWORD dwRet = ::WaitForSingleObject(m_hThread, 0);
        if( dwRet != WAIT_OBJECT_0 )
        {
            throw std::logic_error( "last thread not stopped, now start another thread at one thread obj" ) ;
        }
        ::CloseHandle(m_hThread);
    }

    ::ResetEvent(m_hCancelEvent);

    m_hThread = (HANDLE)_beginthreadex(NULL, 0, &ThreadProc, this, 0, &m_nThreadId);

}

unsigned int __stdcall CThread::ThreadProc(LPVOID lParam)
{
    assert(lParam != NULL);
    CThread* pThread = (CThread*)lParam;
    pThread->Execute();
    return 0;
}


void CThread::Stop()
{
    SetEvent(m_hCancelEvent);
    if (m_hThread != INVALID_HANDLE_VALUE)
    {
        WaitForSingleObject(m_hThread, INFINITE);
    }
}
