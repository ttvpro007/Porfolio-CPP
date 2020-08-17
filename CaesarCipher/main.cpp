#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "FCaesarCipher.h"

int main()
{
    bool isRunning = true;
    std::string Answer = "";
    char ynAnswer = ' ';

    while (isRunning)
    {
        std::cout << "Enter Text: ";
        std::getline(std::cin, Answer);

        std::cout << "\nProcedurally Shifting Code\n";
        std::cout << "[DECRYPTION] Caesar Code -> Alphabet:\n";

        int Shift = SIZE;

        for (size_t i = 0; i < Shift; i++)
        {
            std::cout << "[SHIFT RIGHT " << i << "]: " << CaesarCipher::Decrypt(i, true, Answer) << std::endl;
        }

        std::cout << std::endl;

        for (size_t i = 0; i < Shift; i++)
        {
            std::cout << "[SHIFT LEFT  " << i << "]: " << CaesarCipher::Decrypt(i, false, Answer) << std::endl;

        }

        std::cout << "\nProcedurally Shifting Code\n";
        std::cout << "[ENCRYPTION] Alphabet -> Caesar Code:\n";

        for (size_t i = 0; i < Shift; i++)
        {
            std::cout << "[SHIFT RIGHT " << i << "]: " << CaesarCipher::Encrypt(i, true, Answer) << std::endl;
        }

        std::cout << std::endl;

        for (size_t i = 0; i < Shift; i++)
        {
            std::cout << "[SHIFT LEFT  " << i << "]: " << CaesarCipher::Encrypt(i, false, Answer) << std::endl;
        }

        do
        {
            std::cout << "\nConvert Other Text? [y/n] ";
            std::getline(std::cin, Answer);
            ynAnswer = tolower(Answer[0]);
        } while (ynAnswer != 'y' && ynAnswer != 'n');

        if (ynAnswer == 'n')
        {
            isRunning = false;
        }
        else
        {
            system("cls");
        }
    }
}