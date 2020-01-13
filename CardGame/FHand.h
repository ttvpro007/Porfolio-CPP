#pragma once

#include <vector>
#include <algorithm>

#include "FCard.h"

class FHand
{
public:
	void AddCard(FCard);
	void RemoveCard(FCard);

	int GetBet() const;
	void SetBet(int);
	void ResetBet();

	void Clear();

	int Size() const;

	FCard operator[](const int&);
private:
	std::vector<FCard> Cards;
	int Bet = 0;
};