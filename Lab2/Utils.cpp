#include "Utils.h"

void addTabs(std::string& code)
{
	code = "\t" + code;

	for (int i = 0; i < code.size(); i++)
		if (code[i] == '\n')
		{
			code.insert(i + 1, "\t");
			i++;
		}

	int i = code.size() - 1;
	while (i > -1 && code[i] == '\t')
	{
		code.resize(code.size() - 1);
		i--;
	}

	return;
}