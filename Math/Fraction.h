#pragma once
#include <iostream>

class Fraction
{
	int baseNumerator, baseDenominator, gcdNumerator, gcdDenominator;

public:
	Fraction();
	Fraction(int numerator);
	Fraction(int numerator, int denominator);
	~Fraction();

	int Numerator();
	int BaseNumerator();
	void Numerator(int numerator);
	int Denominator();
	int BaseDenominator();
	void Denominator(int denominator);
	int GreatestCommonDivisor(int numerator, int denominator);

	Fraction operator+(const Fraction& fraction);
	Fraction operator+(const int& numerator);
	Fraction operator-(const Fraction& fraction);
	Fraction operator-(const int& numerator);
	Fraction operator*(const Fraction& fraction);
	Fraction operator*(const int& numerator);
	Fraction operator/(const Fraction& fraction);
	Fraction operator/(const int& numerator);
	Fraction operator=(const Fraction& fraction);
	Fraction operator=(const int& numerator);
	friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
	friend std::istream& operator>>(std::istream& is, Fraction& fraction);
};

