#include "FCard.h"

FCard::FCard()
{
}

FCard::FCard(std::string Rank, std::string Suit, int Value)
{
	this->Rank = Rank;
	this->Suit = Suit;
	this->Value = Value;
}

FCard::~FCard()
{
}

void FCard::SetSuit(std::string Suit)
{
	this->Suit = Suit;
}

void FCard::SetRank(std::string Rank)
{
	this->Rank = Rank;
}

void FCard::SetValue(int Value)
{
	this->Value = Value;
}

std::string FCard::GetSuit()
{
	return Suit;
}

std::string FCard::GetRank()
{
	return Rank;
}

int FCard::GetValue()
{
	return Value;
}

bool FCard::operator==(const FCard& Rhs)
{
	return Suit == Rhs.Suit && Rank == Rhs.Rank && Value == Rhs.Value;
}

std::ostream& operator<<(std::ostream& os, const FCard& Card)
{
	os << Card.Rank;
	os << " of " << Card.Suit;

	return os;
}