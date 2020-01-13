#pragma once

#include <string>
#include <vector>
#include <iostream>

#define SUITS std::vector<std::string>{"HEART", "DIAMOND", "CLUB", "SPADE"}
#define RANKS std::vector<std::string>{"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}

class FCard
{
public:

	FCard();
	FCard(std::string, std::string, int);
	~FCard();

	void SetSuit(std::string);
	void SetRank(std::string);
	void SetValue(int);

	std::string GetSuit();
	std::string GetRank();
	int GetValue();

	bool operator==(const FCard&);
	friend std::ostream& operator<< (std::ostream&, const FCard&);

private:
	std::string Suit = "";
	std::string Rank = "";
	int Value = 0;
};