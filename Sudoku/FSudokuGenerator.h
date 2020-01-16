#pragma once
#include <iostream>
#include <random>
#include <chrono>

#define BOX_GRID_SIZE 3
#define TABLE_GRID_SIZE BOX_GRID_SIZE * BOX_GRID_SIZE
#define EASY_MODE 30
#define NORM_MODE 45
#define HARD_MODE 60

enum class EMode
{
	EASY,
	NORMAL,
	HARD
};

class FSudoku
{
public:
	FSudoku();
	~FSudoku();

private:
	char Solution[TABLE_GRID_SIZE][TABLE_GRID_SIZE] = {};
	char Table[TABLE_GRID_SIZE][TABLE_GRID_SIZE] = {};
	char Box[TABLE_GRID_SIZE] = {};

	static std::default_random_engine RandomNumberGenerator;

private:
	void Initialize();
	void MakeBox();
	void ShuffleBox();
	void FillBox(int);
	void FillDiagonal();
	bool FillTable(int, int);
	void RemoveNumbers(int);

	bool IsUniqueInRow(int, char);
	bool IsUniqueInCol(int, char);
	bool IsUniqueInBox(int, int, char);
	bool CanUseNumber(int, int, char);
	bool hasBlankSpace();
	int GenerateNumber(int, int);

	void Reset();

public:
	void Generate(EMode);
	void PrintSudoku();
	void PrintSolution();
};

