#pragma once
#include <vector>
#include <iostream>
#include "Fraction.h";

using namespace std;

class Matrix
{
	static int newIndex;
	const int index;
	int row, col;
	vector<Fraction> values;

	Matrix AddMatrix(const Matrix& matrix);
	Matrix SubtractMatrix(const Matrix& matrix);
	Matrix MultiplyMatrix(const Matrix& matrix);

public:
	Matrix();
	Matrix(int row, int col, vector<Fraction> values);
	~Matrix();

	int Index() const;
	int Row() const;
	int Col() const;
	vector<Fraction> Values() const;
	int LinearSize() const;

	void PrintMatrix();
	void AssignMatrixValue();
	void InputRowCol();


	Matrix operator+(const Matrix& matrix);
	Matrix operator-(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);
	Matrix operator*(const int& factor);
	Matrix operator=(const Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
};

