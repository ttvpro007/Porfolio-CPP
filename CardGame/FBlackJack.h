#pragma once

#include "FDealer.h"
#include "FHand.h"
#include "FBanker.h"
#include "FQuestionAsker.h"

#define MAX_HAND_SIZE 5;

enum class EGameStatus
{
	Invalid_Status,
	Win,
	Draw,
	Lose
};

class FBlackJack
{
public:
	FBlackJack();
	~FBlackJack();

	void Initiate(int);
	void Initiate(FHand&, int);

	void ShowFund() const;
	void SetBet(FHand&);

	void Play(bool);
	void Reset();
	void GameLoop();

	void ShowHand(FHand) const;
	void ShowDealerHand(bool);
	void Show2HandsCardsAndRatings(bool);
	void Show3HandsCardsAndRatings(bool);
	void SplitPair(FHand&, FHand&);
	void PrintGameSummary(EGameStatus);
	void CalculateFund(EGameStatus, FHand);

	void DealerLogic();

	int GetBaseHandRating(FHand) const;
	int GetHandRating(FHand) const;

	int AceCount(FHand) const;
	bool HasPair(FHand) const;
	bool IsSplitConditions(FHand) const;
	bool IsHandFull(FHand) const;
	bool IsPlayingConditions();
	bool IsWinConditions(int, int) const;
	bool IsDrawConditions(int, int) const;
	bool IsLoseConditions(int, int) const;
	EGameStatus CheckGameStatus(FHand) const;

private:
	FHand PlayerHand1;
	FHand PlayerHand2;
	FHand DealerHand;
	FDealer Dealer;
	FBanker Banker;
};

