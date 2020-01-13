#pragma once

#include <iostream>
#include <string>

#include "FGeneralStatusEnum.h"

class FBanker
{
public:
	FBanker();
	~FBanker();

	std::string GetName();

	int GetCredit() const;
	void SetCredit(int);

private:
	std::string Name { "Milburn Pennybags" };
	int Credit = 0;
};

