#include <iostream>
#include <cmath>

#include "Fraction.h"

using namespace std;

namespace fraction
{
	size_t Fraction::_id = 0;
	bool Fraction::debug = false;

	/* ����������� */
	Fraction::Fraction(int _numenator, int _deminator) : id(++_id)
	{
		this->Set(_numenator, _deminator);

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

		this->Set(other.numenator, other.deminator);

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
		this->Set(this->numenator * multiplier, this->deminator * multiplier);

		return *this;
	}
	Fraction Fraction::operator*(int multiplier)
	{
		return *this *= multiplier;
	}

	/* ���������� �������� ������� ����� �� ����� ����� */
	Fraction& Fraction::operator/=(int divider)
	{
		this->Set(this->numenator / divider, this->deminator / divider);

		return *this;
	}
	Fraction Fraction::operator/(int divider)
	{
		return *this /= divider;
	}

	/* ���������� �������� ��������� */
	Fraction& Fraction::operator*=(const Fraction& other)
	{
		this->Set(this->numenator * other.numenator, this->deminator * other.deminator);

		return *this;
	}
	Fraction Fraction::operator*(const Fraction& other)
	{
		return Fraction(*this *= other);
	}

	/* ���������� �������� ������� */
	Fraction& Fraction::operator/=(const Fraction& other)
	{
		this->Set(this->numenator / other.numenator, this->deminator / other.deminator);

		return *this;
	}
	Fraction Fraction::operator/(const Fraction& other)
	{
		return Fraction(*this /= other);
	}

	/* ���������� �������� �������� */
	Fraction& Fraction::operator+=(const Fraction& other)
	{
		int multiple = this->FindMinMultiple(this->deminator, other.deminator);

		int other_numenator = other.numenator;
		int tmp = this->numenator;

		tmp *= multiple / this->deminator;
		tmp += other_numenator * multiple / other.deminator;

		this->Set(tmp, multiple);

		return *this;
	}
	Fraction Fraction::operator+(const Fraction& other)
	{
		return Fraction(*this += other);
	}

	/* ���������� �������� ��������� */
	Fraction& Fraction::operator-=(const Fraction& other)
	{
		int multiple = this->FindMinMultiple(this->deminator, other.deminator);

		int other_numenator = other.numenator;
		int tmp = this->numenator;

		tmp *= multiple / this->deminator;
		tmp -= other_numenator * multiple / other.deminator;

		this->Set(tmp, multiple);

		return *this;
	}
	Fraction Fraction::operator-(const Fraction& other)
	{
		return Fraction(*this -= other);
	}

	/* ���������� ��������� ������ � ����� */
	ostream& operator<< (std::ostream& out, const Fraction& fraction)
	{
		if (fraction.deminator == 1)
		{
			out << fraction.numenator;
			return out;
		}
		if (fraction.numenator == 0)
		{
			out << "0";
			return out;
		}

		out << fraction.numenator << "/" << fraction.deminator;
		return out;
	}

	/* ������� �������������� ������������ ����� */
	void Fraction::ShowCorrectFraction() const
	{
		if (abs(this->numenator) < abs(this->deminator))
		{
			cout << "����� ����������." << endl;
			return;
		}

		int integer = this->numenator / this->deminator;
		int numinator = this->numenator % this->deminator;

		cout << "����� �����: " << integer << endl;
		if (numinator != 0)
		{
			cout << "������� �����: " << numinator << "/" << this->deminator << endl;
		}

		return;
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
		int divider = this->FindMaxDivider(this->numenator, this->deminator);
		
		this->Set(this->numenator / divider, this->deminator / divider);

		return *this;
	}

	/* ������� */
	int Fraction::GetNumerator() const
	{
		return this->numenator;
	}
	int Fraction::GetDenominator() const
	{
		return this->deminator;
	}
	int Fraction::GetId() const
	{
		return this->id;
	}
	
	/* ������� */
	Fraction& Fraction::SetNumerator(int _numenator)
	{
		if (this->numenator == _numenator)
		{
			return *this;
		}

		this->numenator = _numenator;
		this->Reduction();

		return *this;
	}
	Fraction& Fraction::SetDenominator(int _deminator)
	{
		if (this->deminator == _deminator)
		{
			return *this;
		}

		if (_deminator == 0)
		{
			throw "You cannot use a zero as deminator";
		}

		this->deminator = _deminator;
		this->Reduction();

		return *this;
	}
	Fraction& Fraction::Set(int _numenator, int _deminator)
	{
		if (_deminator == 0)
		{
			throw "You cannot use a zero as deminator";
		}

		this->numenator = _numenator;
		this->deminator = _deminator;

		this->Reduction();

		return *this;
	}
}