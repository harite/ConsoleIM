#pragma once
#include "Command.h"

class COptions
{
public:
	COptions(void);
	virtual ~COptions(void);
	void ImportOptions(std::wistream& in, std::vector<std::wstring>& optionVector);
	void ParseOptions(const std::vector<std::wstring>& optionVector, Command** ppCommand);

private:
	bool IsOption(const std::wstring& arg, const wchar_t* op);
};

