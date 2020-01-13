#include "Fraction.h"

Fraction::Fraction()
{
	baseNumerator = 0;
	baseDenominator = 1;
	gcdNumerator = baseNumerator;
	gcdDenominator = baseDenominator;
}

Fraction::Fraction(int numerator)
{
	baseNumerator = numerator;
	baseDenominator = 1;
	gcdNumerator = baseNumerator;
	gcdDenominator = baseDenominator;
}

Fraction::Fraction(int numerator, int denominator)
{
	int gcd = GreatestCommonDivisor(numerator, denominator);

	baseNumerator = numerator;
	baseDenominator = denominator;
	gcdNumerator = baseNumerator / gcd;
	gcdDenominator = baseDenominator / gcd;
}

Fraction::~Fraction()
{
}

int Fraction::Numerator()
{
	return gcdNumerator;
}

int Fraction::BaseNumerator()
{
	return baseNumerator;
}

void Fraction::Numerator(int numerator)
{
	baseDenominator = numerator;
}

int Fraction::Denominator()
{
	return gcdDenominator;
}

int Fraction::BaseDenominator()
{
	return baseDenominator;
}

void Fraction::Denominator(int denominator)
{
	baseDenominator = denominator;
}

int Fraction::GreatestCommonDivisor(int numerator, int denominator)
{
	if (numerator == 0)
		return denominator;
	else
		return GreatestCommonDivisor(denominator % numerator, numerator);
}

Fraction Fraction::operator+(const Fraction& fraction)
{
	Fraction temp = Fraction(this->gcdNumerator * fraction.gcdDenominator + fraction.gcdNumerator * this->gcdDenominator, this->gcdDenominator * fraction.gcdDenominator);

	return temp;
}

Fraction Fraction::operator+(const int& numerator)
{
	Fraction temp = Fraction(this->gcdNumerator + numerator * this->gcdDenominator, this->gcdDenominator);

	return temp;
}

Fraction Fraction::operator-(const Fraction& fraction)
{
	Fraction temp = Fraction(this->gcdNumerator * fraction.gcdDenominator - fraction.gcdNumerator * this->gcdDenominator, this->gcdDenominator * fraction.gcdDenominator);

	return temp;
}

Fraction Fraction::operator-(const int& numerator)
{
	Fraction temp = Fraction(this->gcdNumerator - numerator * this->gcdDenominator, this->gcdDenominator);

	return temp;
}

Fraction Fraction::operator*(const Fraction& fraction)
{
	Fraction temp = Fraction(this->gcdNumerator * fraction.gcdNumerator, this->gcdDenominator * fraction.gcdDenominator);

	return temp;
}

Fraction Fraction::operator*(const int& numerator)
{
	Fraction temp = Fraction(this->gcdNumerator * numerator, this->gcdDenominator);

	return temp;
}

Fraction Fraction::operator/(const Fraction& fraction)
{
	Fraction temp = Fraction(this->gcdNumerator * fraction.gcdDenominator, this->gcdDenominator * fraction.gcdNumerator);

	return temp;
}

Fraction Fraction::operator/(const int& numerator)
{
	Fraction temp = Fraction(this->gcdNumerator, this->gcdDenominator * numerator);

	return temp;
}

Fraction Fraction::operator=(const Fraction& fraction)
{
	if (this != &fraction)
	{
		this->baseNumerator = fraction.baseNumerator;
		this->baseDenominator = fraction.baseDenominator;
		this->gcdNumerator = fraction.gcdNumerator;
		this->gcdDenominator = fraction.gcdDenominator;
	}

	return *this;
}

Fraction Fraction::operator=(const int& numerator)
{
	this->baseNumerator = numerator;
	this->baseDenominator = 1;
	this->gcdNumerator = baseNumerator;
	this->gcdDenominator = baseDenominator;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
{
	if (fraction.gcdDenominator == 1 || fraction.gcdDenominator == -1)
	{
		os << fraction.gcdNumerator / fraction.gcdDenominator;
	}
	else if (fraction.gcdDenominator != 0)
	{
		if (fraction.gcdDenominator < 0 && fraction.gcdNumerator > 0 || fraction.gcdDenominator < 0 && fraction.gcdNumerator < 0)
			os << fraction.gcdNumerator * -1 << '/' << fraction.gcdDenominator * -1;
		else
			os << fraction.gcdNumerator << '/' << fraction.gcdDenominator;
	}
	else
		os << "Cannot divided by zero.";

	return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction)
{
	is >> fraction.baseNumerator >> fraction.baseDenominator;
	return is;
}
