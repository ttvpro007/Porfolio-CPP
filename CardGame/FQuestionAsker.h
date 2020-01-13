#pragma once

#include <iostream>
#include <string>

#include "FMathUtilities.h"
#include "FGeneralStatusEnum.h"

static class FQuestionAsker
{
public:
	FQuestionAsker();
	~FQuestionAsker();

	static bool AskYesNoQuestion(std::string, std::string);

	static int AskNumberWithRangeQuestion(std::string, std::string, int, int);

private:
	static EYesNoAnswerStatus CheckYesNoAnswerStatus(std::string);
	static void YesNoErrorWarning(std::string, EYesNoAnswerStatus);

	static ENumberWithRangeStatus CheckNumberWithRangeAnswerStatus(std::string, int, int);
	static void NumberWithRangeErrorWarning(std::string, ENumberWithRangeStatus, int, int);

	static bool IsYesNo(std::string);
};

