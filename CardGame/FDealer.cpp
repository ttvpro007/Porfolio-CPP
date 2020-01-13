#include "FDealer.h"

int FDealer::CurrentCard = 0;

FDealer::FDealer()
{
}

FDealer::~FDealer()
{
}

std::string FDealer::GetName()
{
	return Name;
}

void FDealer::Reset()
{
	CurrentCard = 0;
	Deck.Reset();
}

void FDealer::Shuffle()
{
	Deck.Shuffle();
}

FCard FDealer::Deal()
{
	FCard Card = Deck[CurrentCard];
	CurrentCard++;
	return Card;
}