#pragma once
#include "Command.h"

class COptions
{
public:
	COptions(std::istream& in);
	virtual ~COptions(void);
	void ImportOptions(std::istream& in, std::vector<std::wstring>& optionVector);
	void ParseOptions(const std::vector<std::wstring>& optionVector, Command& cmd);
};

