#pragma once

#include "FDeck.h"

class FDealer
{
public:
	FDealer();
	~FDealer();

	std::string GetName();

	void Reset();
	void Shuffle();
	FCard Deal();

private:
	std::string Name { "Jack Napier" };
	static int CurrentCard;
	FDeck Deck;
};

