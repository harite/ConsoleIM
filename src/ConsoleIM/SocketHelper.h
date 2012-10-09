#pragma once

class CSocketHelper
{
public:
	CSocketHelper(void);
	virtual ~CSocketHelper(void);

	static void Init();

	static void UnInit();
};
