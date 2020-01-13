#include "FBlackJack.h"

FBlackJack::FBlackJack()
{
	Banker.SetCredit(1000);
	Reset();
}

FBlackJack::~FBlackJack()
{
}

void FBlackJack::Initiate(int CardToDeal)
{
	for (size_t i = 0; i < (size_t)CardToDeal; i++)
	{
		PlayerHand1.AddCard(Dealer.Deal());
		DealerHand.AddCard(Dealer.Deal());
	}
}

void FBlackJack::Initiate(FHand &Hand, int CardToDeal)
{
	for (size_t i = 0; i < (size_t)CardToDeal; i++)
	{
		Hand.AddCard(Dealer.Deal());
	}
}

void FBlackJack::ShowFund() const
{
	std::cout << "Fund: " << Banker.GetCredit() << " $imoleon\n\n";
}

void FBlackJack::SetBet(FHand &Hand)
{
	Hand.SetBet(FQuestionAsker::AskNumberWithRangeQuestion(Banker.GetName(), "What is your bet? ", 0, Banker.GetCredit()));
	Banker.SetCredit(Banker.GetCredit() - Hand.GetBet());
}

void FBlackJack::Play(bool Debug)
{
	if (Debug)
	{
		ShowFund();
		SetBet(PlayerHand1);

		//PlayerHand1.AddCard(FCard("2", "SPADE", 2));
		//PlayerHand1.AddCard(FCard("J", "DIAMOND", 10));
		//PlayerHand1.AddCard(FCard("J", "HEART", 10));
		//PlayerHand1.AddCard(FCard("A", "DIAMOND", 11));
		//PlayerHand1.AddCard(FCard("A", "CLUB", 11));
		PlayerHand1.AddCard(FCard("A", "HEART", 11));
		PlayerHand1.AddCard(FCard("A", "SPADE", 11));
		ShowHand(PlayerHand1);
		std::cout << "Rating: " << GetHandRating(PlayerHand1) << "\n";
		return;
	}

	do
	{
		if (Banker.GetCredit() <= 0)
		{
			if (FQuestionAsker::AskYesNoQuestion(Banker.GetName(), "You have used all your fund.Do you want to get more fund ? "))
			{
				Banker.SetCredit(FQuestionAsker::AskNumberWithRangeQuestion(Banker.GetName(), "How much fun do you want to add? ", 1, 10000));
			}
			else
			{
				goto endgame;
			}
		}

		Reset();
		GameLoop();

	} while (FQuestionAsker::AskYesNoQuestion(Dealer.GetName(), "Do you want to play again? "));

endgame:
	std::cout << Dealer.GetName() << " & " << Banker.GetName() << ": ";
	std::cout << "See you again!";
}

void FBlackJack::Reset()
{
	system("cls");
	Dealer.Reset();
	Dealer.Shuffle();
	PlayerHand1.Clear();
	PlayerHand2.Clear();
	PlayerHand1.ResetBet();
	PlayerHand2.ResetBet();
	DealerHand.Clear();
}

void FBlackJack::GameLoop()
{
	ShowFund();
	SetBet(PlayerHand1);

	Initiate(2);
	Show2HandsCardsAndRatings(false);

	EGameStatus GameStatus = EGameStatus::Invalid_Status;

	while (IsPlayingConditions())
	{
		// TODO Check if splitting and as if want to hit for each hand
		if (FQuestionAsker::AskYesNoQuestion(Dealer.GetName(), "Do you want to hit? "))
		{
			PlayerHand1.AddCard(Dealer.Deal());
		}
		else
		{
			break;
		}

		Show2HandsCardsAndRatings(false);
	}

	DealerLogic();

	GameStatus = CheckGameStatus(PlayerHand1);
	CalculateFund(GameStatus, PlayerHand1);
	PrintGameSummary(GameStatus);
}

void FBlackJack::ShowHand(FHand Hand) const
{
	for (size_t i = 0; i < (size_t)Hand.Size(); i++)
	{
		std::cout << Hand[i];
		std::cout << std::endl;
	}
}

void FBlackJack::ShowDealerHand(bool Final)
{
	int CardsToShow = (Final) ? DealerHand.Size() : 2;

	for (size_t i = 0; i < (size_t)CardsToShow; i++)
	{
		std::cout << DealerHand[i];
		std::cout << std::endl;
	}
}

void FBlackJack::Show2HandsCardsAndRatings(bool Final)
{
	system("cls");
	std::cout << "Dealer's hand:\n";
	ShowDealerHand(Final);
	std::cout << "Rating: " << GetHandRating(DealerHand);
	std::cout << "\n\n";
	std::cout << "Your hand:\n";
	ShowHand(PlayerHand1);
	std::cout << "Rating: " << GetHandRating(PlayerHand1);
	std::cout << "\n\n";
}

void FBlackJack::Show3HandsCardsAndRatings(bool Final)
{
	system("cls");
	std::cout << "Dealer's hand:\n";
	ShowDealerHand(Final);
	std::cout << "Rating: " << GetHandRating(DealerHand);
	std::cout << "\n\n";
	std::cout << "First Hand:\n";
	ShowHand(PlayerHand1);
	std::cout << "Rating: " << GetHandRating(PlayerHand1);
	std::cout << "\n\n";
	std::cout << "Second hand:\n";
	ShowHand(PlayerHand2);
	std::cout << "Rating: " << GetHandRating(PlayerHand1);
	std::cout << "\n\n";
}

void FBlackJack::SplitPair(FHand &Hand1, FHand &Hand2)
{
	Hand2.AddCard(Hand1[1]);
	Hand1.RemoveCard(Hand1[1]);
}

void FBlackJack::PrintGameSummary(EGameStatus GameStatus)
{
	Show2HandsCardsAndRatings(true);

	switch (GameStatus)
	{
	case EGameStatus::Invalid_Status:
		std::cout << "Status INVALID...\n\n";
		break;
	case EGameStatus::Win:
		std::cout << "You WON!\n\n";
		break;
	case EGameStatus::Draw:
		std::cout << "DRAW!\n\n";
		break;
	case EGameStatus::Lose:
		std::cout << "You LOST!\n\n";
		break;
	default:
		break;
	}

	ShowFund();
}

void FBlackJack::CalculateFund(EGameStatus GameStatus, FHand Hand)
{
	int Credit = Banker.GetCredit();
	int Bet = Hand.GetBet();

	switch (GameStatus)
	{
	case EGameStatus::Invalid_Status:
		break;
	case EGameStatus::Win:
		Banker.SetCredit(Credit + Bet * 2);
		break;
	case EGameStatus::Draw:
		Banker.SetCredit(Credit + Bet);
		break;
	case EGameStatus::Lose:
		break;
	default:
		break;
	}

	//Credit = Banker.GetCredit();
}

void FBlackJack::DealerLogic()
{
	if (GetHandRating(PlayerHand1) < 21)
	{
		while (GetHandRating(DealerHand) < 16)
		{
			DealerHand.AddCard(Dealer.Deal());
		}
	}
}

int FBlackJack::GetBaseHandRating(FHand Hand) const
{
	int Rating = 0;

	for (size_t i = 0; i < (size_t)Hand.Size(); i++)
	{
		Rating += Hand[i].GetValue();
	}

	return Rating;
}

int FBlackJack::GetHandRating(FHand Hand) const
{
	int Rating = GetBaseHandRating(Hand);

	int Aces = AceCount(Hand);
	if (Aces > 1) Rating -= 10 * (Aces - 1);
	if (Rating > 21) Rating = GetBaseHandRating(Hand) - 10 * Aces;

	return Rating;
}

int FBlackJack::AceCount(FHand Hand) const
{
	int Count = 0;

	for (size_t i = 0; i < (size_t)Hand.Size(); i++)
	{
		if (Hand[i].GetRank() == "A") Count++;
	}

	return Count;
}

bool FBlackJack::HasPair(FHand Hand) const
{
	int Increment = 0;

	for (size_t i = 0; i < (size_t)Hand.Size(); i++)
	{
		if (Hand[Increment] == Hand[i]) return true;

		if (Increment < Hand.Size() - 1) Increment++;
	}

	return false;
}

bool FBlackJack::IsSplitConditions(FHand Hand) const
{
	return 
		HasPair(Hand) && 
		Banker.GetCredit() > 0 &&
		Hand.Size() == 2;
}

bool FBlackJack::IsHandFull(FHand Hand) const
{
	return Hand.Size() >= MAX_HAND_SIZE;
}

bool FBlackJack::IsPlayingConditions()
{
	return
		!IsHandFull(PlayerHand1) &&
		GetHandRating(PlayerHand1) < 21 &&
		GetHandRating(DealerHand) < 21;
}

bool FBlackJack::IsWinConditions(int PlayerRating, int DealerRating) const
{
	return (PlayerRating < 21 && DealerRating > 21) || (PlayerRating > DealerRating&& PlayerRating < 21) || (PlayerRating == 21 && DealerRating != 21);
}

bool FBlackJack::IsDrawConditions(int PlayerRating, int DealerRating) const
{
	return (PlayerRating > 21 && DealerRating > 21) || PlayerRating == DealerRating;
}

bool FBlackJack::IsLoseConditions(int PlayerRating, int DealerRating) const
{
	return (PlayerRating > 21 && DealerRating < 21) || (PlayerRating < DealerRating && DealerRating < 21) || (DealerRating == 21 && PlayerRating != 21);
}

EGameStatus FBlackJack::CheckGameStatus(FHand Hand) const
{
	int PlayerRating = GetHandRating(Hand);
	int DealerRating = GetHandRating(DealerHand);

	if (IsLoseConditions(PlayerRating, DealerRating))
	{
		return EGameStatus::Lose;
	}
	else if (IsDrawConditions(PlayerRating, DealerRating))
	{
		return EGameStatus::Draw;
	}
	else if (IsWinConditions(PlayerRating, DealerRating))
	{
		return EGameStatus::Win;
	}
	else
	{
		return EGameStatus::Invalid_Status;
	}
}