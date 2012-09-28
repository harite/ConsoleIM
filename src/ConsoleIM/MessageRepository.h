#pragma once
class CMessageRepository
{
public:
	CMessageRepository(void);
	virtual ~CMessageRepository(void);

public:
	static CMessageRepository* GetInstance();
};

