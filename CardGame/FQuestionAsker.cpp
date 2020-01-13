#include "FQuestionAsker.h"

FQuestionAsker::FQuestionAsker()
{
}

FQuestionAsker::~FQuestionAsker()
{
}

bool FQuestionAsker::AskYesNoQuestion(std::string Name, std::string Question)
{
	std::string YNFormat{ "[y/n]" };
	EYesNoAnswerStatus AnswerStatus = EYesNoAnswerStatus::Invalid_Status;
	std::string Answer = "";

	do
	{
		std::cout << Name << ": ";
		std::cout << Question;
		std::cout << YNFormat << " ";
		std::cin >> Answer;

		// Get Status
		AnswerStatus = CheckYesNoAnswerStatus(Answer);
		// Give Warning if Error
		YesNoErrorWarning(Name, AnswerStatus);

	} while (AnswerStatus != EYesNoAnswerStatus::OK);

	return std::tolower(Answer[0]) == 'y';
}

EYesNoAnswerStatus FQuestionAsker::CheckYesNoAnswerStatus(std::string Answer)
{
	if (!IsYesNo(Answer))
	{
		return EYesNoAnswerStatus::Not_Yes_No;
	}
	else
	{
		return EYesNoAnswerStatus::OK;
	}
}

void FQuestionAsker::YesNoErrorWarning(std::string Name, EYesNoAnswerStatus AnswerStatus)
{
	switch (AnswerStatus)
	{
	case EYesNoAnswerStatus::Invalid_Status:
		std::cout << Name << ": ";
		std::cout << "Status INVALID...\n\n";
		break;
	case EYesNoAnswerStatus::OK:
		std::cout << Name << ": ";
		std::cout << "OK!\n\n";
		break;
	case EYesNoAnswerStatus::Not_Yes_No:
		std::cout << Name << ": ";
		std::cout << "You have entered answer with wrong format, please enter [y] or [n].\n\n";
		break;
	default:
		std::cout << Name << ": ";
		std::cout << "Status DEFAULT...\n\n";
		break;
	}
}

int FQuestionAsker::AskNumberWithRangeQuestion(std::string Name, std::string Question, int Min, int Max)
{
	std::string NumFormat { "[" + std::to_string(Min) + " to " + std::to_string(Max) + "]" };
	ENumberWithRangeStatus AnswerStatus = ENumberWithRangeStatus::Invalid_Status;
	std::string Answer = "";

	do
	{
		std::cout << Name << ": ";
		std::cout << Question;
		std::cout << NumFormat << " ";
		std::cin >> Answer;

		// Get Status
		AnswerStatus = CheckNumberWithRangeAnswerStatus(Answer, Min, Max);
		// Give Warning if Error
		NumberWithRangeErrorWarning(Name, AnswerStatus, Min, Max);

	} while (AnswerStatus != ENumberWithRangeStatus::OK);

	return FMath::StringToInt(Answer);
}

ENumberWithRangeStatus FQuestionAsker::CheckNumberWithRangeAnswerStatus(std::string Answer, int Min, int Max)
{
	int IBet = FMath::StringToInt(Answer);

	if (IBet == -1)
	{
		return ENumberWithRangeStatus::Not_Number;
	}
	else if (IBet < Min || IBet > Max)
	{
		return ENumberWithRangeStatus::Not_In_Range;
	}
	else
	{
		return ENumberWithRangeStatus::OK;
	}
}

void FQuestionAsker::NumberWithRangeErrorWarning(std::string Name, ENumberWithRangeStatus AnswerStatus, int Min, int Max)
{
	switch (AnswerStatus)
	{
	case ENumberWithRangeStatus::Invalid_Status:
		std::cout << Name << ": ";
		std::cout << "Status INVALID...\n\n";
		break;
	case ENumberWithRangeStatus::OK:
		std::cout << Name << ": ";
		std::cout << "OK!\n\n";
		break;
	case ENumberWithRangeStatus::Not_In_Range:
		std::cout << Name << ": ";
		std::cout << "You have entered answer that is not in range. Range [" << Min << " to " << Max << "].\n\n";
		break;
	case ENumberWithRangeStatus::Not_Number:
		std::cout << Name << ": ";
		std::cout << "You have entered answer with wrong format, please enter number only.\n\n";
		break;
	default:
		std::cout << Name << ": ";
		std::cout << "Status DEFAULT...\n\n";
		break;
	}
}

bool FQuestionAsker::IsYesNo(std::string Answer)
{
	return std::tolower(Answer[0]) == 'y' || std::tolower(Answer[0]) == 'n';
}