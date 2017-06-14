#include "stdafx.h"
#include "../task1/Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

std::pair<int, CRational> CRational::ToCompoundFraction()const
{
	int integer = static_cast<int>(ToDouble());
	int numerator = m_numerator - m_denominator * integer;

	return std::make_pair<int, CRational>(std::move(integer), CRational(numerator, m_denominator));
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble()const
{
	return m_numerator / m_denominator;
}

//1)Унарные + и -
CRational const CRational::operator-()const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+()const
{
	return *this;
}

//2)Бинарный +
CRational const operator +(CRational const &rational1, CRational const &rational2)
{
	return (CRational((rational1.GetNumerator() * rational2.GetDenominator())
		+ (rational2.GetNumerator() * rational1.GetDenominator()),
		rational1.GetDenominator() * rational2.GetDenominator()));
}

//3)Бинарный -
CRational const operator -(CRational const &rational1, CRational const &rational2)
{
	return rational1 + -rational2;
}

//4)+=
CRational &CRational::operator+=(CRational const &rValue)
{
	*this = *this + rValue;
	return *this;
}

//5)-=
CRational &CRational::operator-=(CRational const &rValue)
{
	*this = *this - rValue;
	return *this;
}

//6)*
CRational const operator *(CRational const &rational1, CRational const &rational2)
{
	return (CRational(rational1.GetNumerator() * rational2.GetNumerator()
		, rational1.GetDenominator() * rational2.GetDenominator()));
}

//7) /
CRational const operator /(CRational const &rational1, CRational const &rational2)
{
	return (CRational(rational1.GetNumerator() * rational2.GetDenominator()
		, rational1.GetDenominator() * rational2.GetNumerator()));
}

//8)*=
CRational & CRational::operator*=(CRational const & rValue)
{
	*this = *this * rValue;
	return *this;
}

//9)/=
CRational & CRational::operator/=(CRational const & rValue)
{
	*this = *this / rValue;
	return *this;
}

//10) == и !=
bool const operator ==(CRational const &rational1, CRational const &rational2)
{
	return (rational1.GetNumerator() == rational2.GetNumerator() 
		&& (rational1.GetDenominator() == rational2.GetDenominator()));
}

bool const operator !=(CRational const &rational1, CRational const &rational2)
{
	return !(rational1 == rational2);
}

//11) <, <=, >, >=
bool const operator <(CRational const &rational1, CRational const &rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() 
		< rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator <=(CRational const &rational1, CRational const &rational2)
{
	return (rational1 == rational2) || (rational1 < rational2);
}

bool const operator >(CRational const &rational1, CRational const &rational2)
{
	return !(rational1 <= rational2);
}

bool const operator >=(CRational const &rational1, CRational const &rational2)
{
	return (rational1 == rational2) || (rational1 > rational2);
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

//Общий знаменатель
unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}



