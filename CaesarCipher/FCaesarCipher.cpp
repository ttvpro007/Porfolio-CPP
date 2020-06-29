#include "FCaesarCipher.h"

char CaesarCipher::AlphabetLetters[SIZE] = ALPHABET;
//int CaesarCipher::Code = 999;

std::string CaesarCipher::Encrypt(int Shift, bool bIsCipherShiftRight, std::string Answer)
{
    std::string Result = "";
    std::vector<int> IndexList = GetIndexList(AlphabetLetters, Answer);

    for (auto i : IndexList)
    {
        if (i != CODE_SPACE)
            Result.push_back(AlphabetLetters[(bIsCipherShiftRight ? (int)i + Shift : (int)i - Shift + SIZE) % SIZE]);
        else
            Result.push_back(' ');
    }

    return Result;
}

std::string CaesarCipher::Decrypt(int Shift, bool bIsCipherShiftRight, std::string Answer)
{
    std::string Result = "";
    std::vector<int> IndexList = GetIndexList(AlphabetLetters, Shift, bIsCipherShiftRight, Answer);

    for (auto i : IndexList)
    {
        if (i != CODE_SPACE)
            Result.push_back(AlphabetLetters[i]);
        else
            Result.push_back(' ');
    }

    return Result;
}

std::vector<int> CaesarCipher::GetIndexList(char *CharArray, std::string Answer)
{
    std::vector<int> Result = {};

    for (auto AChar : Answer)
    {
        if (AChar == ' ')
        {
            Result.push_back(CODE_SPACE);
            continue;
        }

        for (size_t i = 0; i < SIZE; i++)
        {
            if (std::toupper(AChar) == CharArray[i])
                Result.push_back((int)i);
        }
    }

    return Result;
}

std::vector<int> CaesarCipher::GetIndexList(char* CharArray, int Shift, bool bIsCipherShiftRight, std::string Answer)
{
    std::vector<int> Result = {};

    for (auto AChar : Answer)
    {
        if (AChar == ' ')
        {
            Result.push_back(CODE_SPACE);
            continue;
        }

        for (size_t i = 0; i < SIZE; i++)
        {
            if (std::toupper(AChar) == CharArray[(bIsCipherShiftRight ? (int)i - Shift + SIZE : (int)i + Shift) % SIZE])
                Result.push_back((int)i);
        }
    }

    return Result;
}

bool CaesarCipher::CheckSpecialCharacters(char)
{
    return false;
}