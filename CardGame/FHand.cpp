#include "FHand.h"

void FHand::AddCard(FCard Card)
{
	Cards.push_back(Card);
}

void FHand::RemoveCard(FCard Card)
{
	Cards.erase(std::remove(Cards.begin(), Cards.end(), Card), Cards.end());
}

int FHand::GetBet() const
{
	return Bet;
}

void FHand::SetBet(int Bet)
{
	this->Bet = Bet;
}

void FHand::ResetBet()
{
	Bet = 0;
}

void FHand::Clear()
{
	Cards.clear();
}

int FHand::Size() const
{
	return Cards.size();
}

FCard FHand::operator[](const int &Index)
{
	return Cards[Index];
}