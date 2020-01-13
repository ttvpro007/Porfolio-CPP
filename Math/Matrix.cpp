#include "Matrix.h"

int Matrix::newIndex = 0;

Matrix::Matrix()
	: index(++newIndex), row(0), col(0)
{
	InputRowCol();

	AssignMatrixValue();
}

Matrix::Matrix(int row, int col, vector<Fraction> values)
	: index(++newIndex), row(row), col(col), values(values)
{
}

Matrix::~Matrix()
{
}

int Matrix::Index() const
{
	return index;
}

int Matrix::Row() const
{
	return row;
}

int Matrix::Col() const
{
	return col;
}

vector<Fraction> Matrix::Values() const
{
	return values;
}

int Matrix::LinearSize() const
{
	return values.size();
}

void Matrix::PrintMatrix()
{
	for (size_t i = 0, index = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << values[index] << "  ";
			index++;
		}
		cout << endl;
	}
}

void Matrix::AssignMatrixValue()
{
	int v;

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			do
			{
				cout << "Input the value of the " << j + 1 << " number of the " << i + 1 << " row of the matrix " << index << ": ";
				cin >> v;
				values.push_back(v);
			} while (cin.fail());
		}
	}
}

void Matrix::InputRowCol()
{
	do
	{
		cout << "Input number of row of matrix " << index << ": ";
		cin >> row;
	} while (row < 0 && cin.fail());

	do
	{
		cout << "Input number of column of matrix " << index << ": ";
		cin >> col;
	} while (col < 0 && cin.fail());
}

Matrix Matrix::AddMatrix(const Matrix& matrix)
{
	vector<Fraction> temp;

	if (row == matrix.row && col == matrix.col)
	{
		for (size_t i = 0; i < row * matrix.col; i++)
		{
			temp.push_back(values[i] + matrix.values[i]);
		}
	}
	else
	{
		cout << "Matrix 1 and Matrix 2 must have same row and column to complete adding operation." << endl;
	}

	return Matrix(row, col, temp);
}

Matrix Matrix::SubtractMatrix(const Matrix& matrix)
{
	vector<Fraction> temp;

	if (row == matrix.row && col == matrix.col)
	{
		for (size_t i = 0; i < row * matrix.col; i++)
		{
			temp.push_back(values[i] - matrix.values[i]);
		}
	}
	else
	{
		cout << "Matrix 1 and Matrix 2 must have same row and column to complete subtracting operation." << endl;
	}

	return Matrix(row, col, temp);
}

Matrix Matrix::MultiplyMatrix(const Matrix& matrix)
{
	vector<Fraction> temp;

	if (col == matrix.row)
	{
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < matrix.col; j++)
			{
				temp.push_back(values[i * col] * matrix.values[j] + values[i * col + 1] * matrix.values[j + (matrix.row - 1) * matrix.col]);
			}
		}
	}
	else
	{
		cout << "Matrix 1's colum must equal Matrix 2's row to complete multiplying operation." << endl;
	}

	return Matrix(row, matrix.col, temp);
}

Matrix Matrix::operator+(const Matrix& matrix)
{
	return this->AddMatrix(matrix);
}

Matrix Matrix::operator-(const Matrix& matrix)
{
	return this->SubtractMatrix(matrix);
}

Matrix Matrix::operator*(const Matrix& matrix)
{
	return this->MultiplyMatrix(matrix);
}

Matrix Matrix::operator=(const Matrix& matrix)
{
	if (this != &matrix)
	{
		row = matrix.row;
		col = matrix.col;
		values = matrix.values;
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	if (matrix.LinearSize() > 0)
	{
		for (size_t i = 0, index = 0; i < matrix.row; i++)
		{
			for (size_t j = 0; j < matrix.col; j++)
			{
				os << matrix.values[index] << "  ";
				index++;
			}
			os << endl;
		}
	}

	return os;
}