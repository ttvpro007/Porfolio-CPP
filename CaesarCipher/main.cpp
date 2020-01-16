#include <iostream>
#include <string>
#include <vector>
#include "FCaesarCipher.h"

int main()
{
    std::string Answer = "";
    std::cout << "Enter Text: ";
    std::getline(std::cin, Answer);

    std::cout << "\nProcedurally Shifting Code\n";
    std::cout << "[DECRYPTION] Caesar Code -> Alphabet:\n";

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "[SHIFT RIGHT " << i << "]: " << CaesarCipher::Decrypt(i, true, Answer) << std::endl;
    }

    std::cout << std::endl;

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "[SHIFT LEFT  " << i << "]: " << CaesarCipher::Decrypt(i, false, Answer) << std::endl;

    }

    std::cout << "\nProcedurally Shifting Code\n";
    std::cout << "[ENCRYPTION] Alphabet -> Caesar Code:\n";

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "[SHIFT RIGHT " << i << "]: " << CaesarCipher::Encrypt(i, true, Answer) << std::endl;
    }

    std::cout << std::endl;

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "[SHIFT LEFT  " << i << "]: " << CaesarCipher::Encrypt(i, false, Answer) << std::endl;
    }
}