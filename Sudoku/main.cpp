#include "main.h"
#include "FSudokuGenerator.h"

int main()
{
	FSudoku Sudoku = FSudoku();

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
}