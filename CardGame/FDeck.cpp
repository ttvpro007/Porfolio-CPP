#include "FDeck.h"

FDeck::FDeck()
{
	Reset();
}

FDeck::~FDeck()
{
}

int FDeck::Size() const
{
	return Cards.size();
}

void FDeck::Reset()
{
	Cards = Create52CardsDeck();
}

std::default_random_engine FDeck::RandomNumberGenerator;

std::vector<FCard> FDeck::Create52CardsDeck()
{
	std::vector<FCard> Cards;
	FCard Card;

	for (size_t i = 0; i < SUITS.size(); i++)
	{
		for (size_t j = 0; j < RANKS.size(); j++)
		{
			Card.SetSuit(SUITS[i]);
			Card.SetRank(RANKS[j]);

			(j == 0) ? Card.SetValue(j + 11) : 
			(j < 10) ? Card.SetValue(j + 1) : Card.SetValue(10);

			Cards.push_back(Card);
		}
	}

	return Cards;
}

void FDeck::Shuffle()
{
	RandomNumberGenerator.seed((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<size_t> Distributor(0, Cards.size() - 1);
	size_t DeckSize = Cards.size() - 1;
	size_t MaxIndex = DeckSize;
	size_t RandomIndex = 0;
	FCard TempCard;

	for (size_t i = 0; i < DeckSize; i++)
	{
		RandomIndex = Distributor(RandomNumberGenerator);
		TempCard = Cards[RandomIndex];
		Cards[RandomIndex] = Cards[MaxIndex];
		Cards[MaxIndex] = TempCard;
		MaxIndex--;
	}
}

FDeck FDeck::Shuffle(FDeck Deck)
{
	Deck.Shuffle();
	return Deck;
}

FCard &FDeck::operator[](const int &Index)
{
	return Cards[Index];
}
