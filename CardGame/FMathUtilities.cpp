#include "FMathUtilities.h"

int FMath::StringToInt(const std::string &String)
{
	char* pEnd = nullptr;
	int Integer = (int)std::strtol(String.c_str(), &pEnd, 10);

	if (*pEnd)
	{
		// conversion fail
		return -1;
	}
	else
	{
		// conversion success
		return Integer;
	}
}
