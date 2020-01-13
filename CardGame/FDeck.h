#pragma once

#include <string>
#include <vector>
#include <random>
#include <chrono>
#include "FCard.h"

class FDeck
{
public:
	FDeck();
	~FDeck();

	int Size() const;

	void Reset();

	std::vector<FCard> Create52CardsDeck();
	void Shuffle();
	static FDeck Shuffle(FDeck);

	// operator overloading
	FCard &operator[](const int&);

private:
	static std::default_random_engine RandomNumberGenerator;

	std::vector<FCard> Cards;
};