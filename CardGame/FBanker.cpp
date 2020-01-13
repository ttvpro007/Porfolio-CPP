#include "FBanker.h"

FBanker::FBanker()
{
}

FBanker::~FBanker()
{
}

std::string FBanker::GetName()
{
	return Name;
}

int FBanker::GetCredit() const
{
	return Credit;
}

void FBanker::SetCredit(int Amount)
{
	Credit = Amount;
}