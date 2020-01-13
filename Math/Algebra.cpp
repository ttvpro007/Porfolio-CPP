#include "Algebra.h"

bool Algebra::IsPrime(int num)
{
	if (num == 0) return false;

	for (size_t i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

bool Algebra::IsDivisible(int base, int target)
{
	return base % target == 0;
}
