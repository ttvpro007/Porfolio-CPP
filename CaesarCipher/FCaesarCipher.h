#pragma once

#include <string>
#include <vector>

#define ALPHABET {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}
#define SIZE 26
#define CODE_SPACE -1

static class CaesarCipher
{
public:
	static std::string Encrypt(int, bool, std::string);
	static std::string Decrypt(int, bool, std::string);

private:
	static std::vector<int> GetIndexList(char*, std::string);
	static std::vector<int> GetIndexList(char*, int, bool, std::string);

	static bool CheckSpecialCharacters(char);

private:
	static char AlphabetLetters[SIZE];
	static int Code;
};

