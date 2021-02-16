#include <iostream>
#include <cmath>

#include "Fraction.h"

using namespace std;

namespace fraction
{
	size_t Fraction::_id = 0;
	bool Fraction::debug = true;

	/* ����������� */
	Fraction::Fraction(int _x, int _y) : x(_x), y(_y), id(++_id)
	{
		if (debug)
		{
			cout << "Constructor 'Fraction' with ID: " << this->id << endl;
		}
	}

	/* ����������� ����������� */
	Fraction::Fraction(const Fraction& other) : Fraction()
	{
		*this = other;
	}

	/* �������� ����������� = */
	const Fraction& Fraction::operator=(const Fraction& other)
	{
		if (debug)
		{
			cout << "Copy constructor 'Fraction': " << this->id << " <= " << other.id << endl;
		}

		if (this == &other)
		{
			return *this;
		}

		this->x = other.x;
		this->y = other.y;

		return *this;
	}

	/* ���������� */
	Fraction::~Fraction()
	{
		if (debug)
		{
			cout << "Destructor 'Fraction' with ID: " << this->id << endl;
		}
	}

	/* ���������� �������� ��������� ����� �� ����� ����� */
	Fraction& Fraction::operator*=(int multiplier)
	{
		this->x *= multiplier;
		this->y *= multiplier;

		return *this;
	}
	Fraction Fraction::operator*(int multiplier)
	{
		return *this *= multiplier;
	}

	/* ���������� �������� ��������� */
	Fraction& Fraction::operator*=(const Fraction& other)
	{
		this->x *= other.x;
		this->y *= other.y;

		return *this;
	}
	Fraction Fraction::operator*(const Fraction& other)
	{
		return Fraction(*this *= other);
	}

	/* ���������� �������� ������� */
	Fraction& Fraction::operator/=(const Fraction& other)
	{
		this->x /= other.x;
		this->y /= other.y;

		return *this;
	}
	Fraction Fraction::operator/(const Fraction& other)
	{
		return Fraction(*this /= other);
	}

	/* ���������� �������� �������� */
	Fraction& Fraction::operator+=(const Fraction& other)
	{
		int multiple = this->FindMinMultiple(this->y, other.y);
		int x = other.x;

		if (this->y > other.y)
		{
			x *= multiple / other.y;
		}
		else
		{
			*this *= multiple / this->y;
		}
		this->x += x;

		this->Reduction();

		return *this;
	}
	Fraction Fraction::operator+(const Fraction& other)
	{
		return Fraction(*this += other);
	}

	/* ���������� �������� ��������� */
	Fraction& Fraction::operator-=(const Fraction& other)
	{
		int multiple = this->FindMinMultiple(this->y, other.y);
		int x = other.x;

		if (this->y > other.y)
		{
			x *= multiple / other.y;
		}
		else
		{
			*this *= multiple / this->y;
		}
		this->x -= x;

		this->Reduction();

		return *this;
	}
	Fraction Fraction::operator-(const Fraction& other)
	{
		return Fraction(*this -= other);
	}

	/* ���������� ��������� ������ � ����� */
	ostream& operator<< (std::ostream& out, const Fraction& fraction)
	{
		if (fraction.y == 1)
		{
			out << fraction.x;
			return out;
		}
		out << fraction.x << "/" << fraction.y;
		return out;
	}

	/* ������� ������ ������ �������� */
	int Fraction::FindMaxDivider(int n, int m) const
	{
		int divider;

		n = abs(n);
		m = abs(m);

		if (n == m)  return n;

		int diff = n - m;

		if (diff < 0)
		{
			diff = -diff;
			divider = this->FindMaxDivider(n, diff);
		}
		else
		{
			divider = FindMaxDivider(m, diff);
		}

		return divider;
	}

	/* ������� ��� ������ ����������� */
	int Fraction::FindMinMultiple(int n, int m) const
	{
		return abs(n) * (abs(m) / this->FindMaxDivider(n, m));
	}

	/* ���������� ����� */
	Fraction& Fraction::Reduction()
	{
		int divider = this->FindMaxDivider(this->x, this->y);
		
		this->x /= divider;
		this->y /= divider;

		return *this;
	}

	/* ������� */
	int Fraction::GetNumerator() const
	{
		return this->x;
	}
	int Fraction::GetDenominator() const
	{
		return this->y;
	}
}