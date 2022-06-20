#include "FSudokuGenerator.h"

std::default_random_engine FSudoku::RandomNumberGenerator;

FSudoku::FSudoku()
{
	Initialize();
}

FSudoku::~FSudoku()
{
}

void FSudoku::Initialize()
{
	MakeBox();
}

void FSudoku::MakeBox()
{
	for (size_t i = 0; i < TABLE_GRID_SIZE; i++)
	{
		if (i < 9)
			Box[i] = '0' + (i + 1);
		else
			// support for larger dimension Sudoku... skip 7 characters in between numbers (0-9) to get alphabet (A-Z)
			Box[i] = '0' + (i + 1 + 7);
	}
}

void FSudoku::ShuffleBox()
{
	size_t MaxIndex = TABLE_GRID_SIZE - 1;
	size_t RandomIndex = 0;
	char Temp = ' ';

	RandomNumberGenerator.seed((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<size_t> Distributor(0, MaxIndex);

	for (size_t i = 0; i < MaxIndex; i++)
	{
		RandomIndex = Distributor(RandomNumberGenerator);
		Temp = Box[RandomIndex];
		Box[RandomIndex] = Box[MaxIndex - i];
		Box[MaxIndex - i] = Temp;
	}
}

void FSudoku::FillBox(int StartIndex)
{
	ShuffleBox();

	for (size_t i = 0; i < BOX_GRID_SIZE; i++)
	{
		for (size_t j = 0; j < BOX_GRID_SIZE; j++)
		{
			Table[(int)i + BOX_GRID_SIZE * StartIndex][(int)j + BOX_GRID_SIZE * StartIndex] = Box[i * BOX_GRID_SIZE + j];
		}
	}
}

void FSudoku::FillDiagonal()
{
	for (size_t i = 0; i < BOX_GRID_SIZE; i++)
	{
		FillBox(i);
	}
}

bool FSudoku::FillTable(int Row, int Col)
{
	if (!hasBlankSpace())
	{
		return true;
	}

	if (Row < TABLE_GRID_SIZE - 1 && Col >= TABLE_GRID_SIZE)
	{
		Row++;
		Col = 0;
	}

	for (size_t k = 0; k < TABLE_GRID_SIZE; k++)
	{
		char num = Box[k];

		if (CanUseNumber(Row, Col, num))
		{
			Table[Row][Col] = num;
			Solution[Row][Col] = num;

			if (FillTable(Row, Col + 1))
				return true;

			Table[Row][Col] = '\0';
			Solution[Row][Col] = '\0';
		}
	}

	return false;
}

void FSudoku::RemoveNumbers(int Num)
{
	int Row, Col;

	while (Num > 0)
	{
		Row = GenerateNumber(0, TABLE_GRID_SIZE - 1);
		Col = GenerateNumber(0, TABLE_GRID_SIZE - 1);

		if (Table[Row][Col] != '\0')
		{
			Table[Row][Col] = '\0';
			Num--;
		}
	}
}

bool FSudoku::IsUniqueInRow(int Row, char Num)
{
	for (size_t i = 0; i < TABLE_GRID_SIZE; i++)
	{
		if (Table[Row][i] == Num)
			return false;
	}

	return true;
}

bool FSudoku::IsUniqueInCol(int Col, char Num)
{
	for (size_t i = 0; i < TABLE_GRID_SIZE; i++)
	{
		if (Table[i][Col] == Num)
			return false;
	}

	return true;
}

bool FSudoku::IsUniqueInBox(int Row, int Col, char Num)
{
	for (size_t i = 0; i < BOX_GRID_SIZE; i++)
	{
		for (size_t j = 0; j < BOX_GRID_SIZE; j++)
		{
			if (Table[i + Row][j + Col] == Num)
				return false;
		}
	}

	return true;
}

bool FSudoku::CanUseNumber(int Row, int Col, char Num)
{
	return
		IsUniqueInRow(Row, Num) &&
		IsUniqueInCol(Col, Num) &&
		IsUniqueInBox(Row - Row % BOX_GRID_SIZE, Col - Col % BOX_GRID_SIZE, Num);
}

bool FSudoku::hasBlankSpace()
{
	for (size_t i = 0; i < TABLE_GRID_SIZE; i++)
	{
		for (size_t j = 0; j < TABLE_GRID_SIZE; j++)
		{
			if (Table[i][j] == '\0')
				return true;
		}
	}

	return false;
}

int FSudoku::GenerateNumber(int Min, int Max)
{
	RandomNumberGenerator.seed((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<size_t> Distributor(Min, Max);
	return Distributor(RandomNumberGenerator);
}

void FSudoku::Reset()
{
	for (size_t i = 0; i < TABLE_GRID_SIZE; i++)
	{
		for (size_t j = 0; j < TABLE_GRID_SIZE; j++)
		{
			Table[i][j] = '\0';
		}
	}
}

void FSudoku::Generate(EMode Mode)
{
	Reset();
	ShuffleBox();
	FillTable(0, 0);

	int numberToRemove = TABLE_GRID_SIZE * TABLE_GRID_SIZE * (int)Mode / 100;

	RemoveNumbers(numberToRemove);
}

void FSudoku::PrintSudoku()
{
	PrintGrid(Table);
}

void FSudoku::PrintSolution()
{
	PrintGrid(Solution);
}

void FSudoku::PrintGrid(char CharArray[TABLE_GRID_SIZE][TABLE_GRID_SIZE])
{
	for (size_t i = 0; i < TABLE_GRID_SIZE; i++)
	{
		if (i != 0 && i % BOX_GRID_SIZE == 0)
		{
			for (size_t i = 0; i < TABLE_GRID_SIZE * 2 + 1; i++)
			{
				std::cout << "-";
			}

			std::cout << std::endl;
		}

		for (size_t j = 0; j < TABLE_GRID_SIZE; j++)
		{
			if (j % BOX_GRID_SIZE == 0)
				std::cout << "|";

			if (CharArray[i][j] == '\0')
				std::cout << " ";

			if (BOX_GRID_SIZE - j % BOX_GRID_SIZE == 1)
				std::cout << CharArray[i][j];
			else
				std::cout << CharArray[i][j] << ".";

			if (j == TABLE_GRID_SIZE - 1)
				std::cout << "|";
		}

		std::cout << std::endl;
	}
}