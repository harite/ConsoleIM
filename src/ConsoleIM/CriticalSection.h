#pragma once

class CCriticalSection	
{
public:
    CCriticalSection(CRITICAL_SECTION& cs)
    {
        m_cs = cs;
        ::EnterCriticalSection(&cs);
    }
    ~CCriticalSection()
    {
        ::LeaveCriticalSection(&m_cs);
    }

private:
    CRITICAL_SECTION m_cs;
};
