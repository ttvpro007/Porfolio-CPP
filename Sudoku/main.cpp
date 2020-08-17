#include "cstdio"
#include "main.h"
#include "FSudokuGenerator.h"

int main()
{
	std::string Answer = "";
	char ynAnswer = ' ';
	bool isRunning = true;

	FSudoku Sudoku = FSudoku();

	while (isRunning)
	{
		Sudoku.Generate(EMode::EASY);
		std::cout << "Mode: SNOW FLAKE" << std::endl;
		Sudoku.PrintSudoku();
		std::cout << "\nSolution:\n";
		Sudoku.PrintSolution();
		std::cout << std::endl;

		Sudoku.Generate(EMode::NORMAL);
		std::cout << "Mode: SO-SO" << std::endl;
		Sudoku.PrintSudoku();
		std::cout << "\nSolution:\n";
		Sudoku.PrintSolution();
		std::cout << std::endl;

		Sudoku.Generate(EMode::HARD);
		std::cout << "Mode: IMPOSSIBRUUU" << std::endl;
		Sudoku.PrintSudoku();
		std::cout << "\nSolution:\n";
		Sudoku.PrintSolution();
		std::cout << std::endl;

		do
		{
			std::cout << "Generate More? [y/n] ";
			std::cin >> Answer;
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