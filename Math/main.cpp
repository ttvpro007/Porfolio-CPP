#include <iostream>
#include <vector>
#include "Fraction.h"
#include "Matrix.h"
#include "Algebra.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void mainFractionImplementation()
{
	Fraction fraction = Fraction(2, 4);
	Fraction fraction2 = Fraction(4, 4);

	cout << "Fraction 1: " << fraction << endl;
	cout << "Fraction 2: " << fraction2 << endl;
	
	cout << "Fraction 1 + Fraction 2: " << fraction + fraction2 << endl;
	cout << "Fraction 1 - Fraction 2: " << fraction - fraction2 << endl;
	cout << "Fraction 1 * Fraction 2: " << fraction * fraction2 << endl;
	cout << "Fraction 1 / Fraction 2: " << fraction / fraction2 << endl;

	cout << "Fraction 1 + 2: " << fraction + 2 << endl;
	cout << "Fraction 1 - 2: " << fraction - 2 << endl;
	cout << "Fraction 1 * 2: " << fraction * 2 << endl;
	cout << "Fraction 1 / 2: " << fraction / 2 << endl;

	cout << "Fraction 1: " << fraction << endl;
}

void mainMatrixImplementation()
{
	vector<Fraction> values1 = { 1, 4, 3,
								7, -6, -2};
	Matrix mTest1 = Matrix();
	Matrix mTest2 = Matrix(2, 3, values1);

	cout << "Matrix " << mTest1.Index() << " = " << endl;
	mTest1.PrintMatrix();
	cout << "Matrix " << mTest2.Index() << " = " << endl;
	mTest2.PrintMatrix();

	cout << "Matrix " << mTest1.Index() << " + Matrix " << mTest2.Index() << " = " << endl;
	cout << mTest1 + mTest2;

	cout << "Matrix " << mTest1.Index() << " - Matrix " << mTest2.Index() << " = " << endl;
	cout << mTest1 - mTest2;

	cout << "Matrix " << mTest1.Index() << " * Matrix " << mTest2.Index() << " = " << endl;
	cout << mTest1 * mTest2;

	cout << "Matrix " << mTest2.Index() << " + Matrix " << mTest1.Index() << " = " << endl;
	cout << mTest2 + mTest1;

	cout << "Matrix " << mTest2.Index() << " - Matrix " << mTest1.Index() << " = " << endl;
	cout << mTest2 - mTest1;

	cout << "Matrix " << mTest2.Index() << " * Matrix " << mTest1.Index() << " = " << endl;
	cout << mTest2 * mTest1;
}



void mainAlgebra()
{
	vector<int> values = {};

	cout << "Finding Prime Number" << endl;
	cout << "Enter range min (inclusive): ";
	int min;
	cin >> min;
	cout << "Enter range max (inclusive): ";
	int max;
	cin >> max;

	for (size_t i = min; i < max + 1; i++)
	{
		if (Algebra::IsPrime(i)) values.push_back(i);
	}

	cout << "There are " << values.size() << " prime number(s) between " << min << " and " << max << endl;
	cout << "The prime number(s) within the range:\n";

	for (size_t i = 0; i < values.size(); i++)
	{
		cout << values[i] << endl;
	}
}

void mainTest()
{
	while (true)
	{
		cout << "Input level of detail:";
		int lod;
		cin >> lod;

		int msf = 1;
		for (size_t i = 0; i < 4 - lod; i++)
		{
			msf *= 2;
		}
		cout << "Mesh simplicication factor: " << msf << endl;

		msf = 1;
		for (size_t i = 0; i <= 4; i++)
		{
			cout << "Mesh simplicication factor at level of detail = " << 4 - i << ": " << msf << endl;
			msf *= 2;
		}
	}
}

void main()
{
	int count = 0;

	for (size_t i = 1; i <= 200; i++)
	{
		//if (i % 2 == 0 && i % 3 == 0)
		if (Algebra::IsDivisible(i, 3))
		{
			cout << i << endl;
			count++;
		}
	}

	cout << "Total: " << count << endl;
}