#include <iostream>
#include <cmath>

#include "Polynomial.h"

using namespace std;

namespace polynomial
{
	size_t Polynomial::_id = 0;
	bool Polynomial::debug = false;

	/* ����������� */
	Polynomial::Polynomial(size_t _deg, double* _mass) : id(++_id), deg(_deg)
	{
		this->mass = nullptr;

		if (this->deg != 0)
		{
			this->mass = new double[this->deg + 1]();
		}

		if (_mass != nullptr)
		{
			copy(_mass, _mass + this->deg + 1, this->mass);
		}

		if (debug)
		{
			cout << "Constructor 'Polynomial' with ID: " << this->id << endl;
		}
	}

	/* �����������, ����������� ���������������� ������� */
	Polynomial::Polynomial(size_t _deg, double(*func)(size_t)) : Polynomial(_deg) {
		for (size_t i = 0; i < this->deg + 1; i++)
		{
			this->mass[i] = func(i);
		}		
	}

	/* ����������� ����������� */
	Polynomial::Polynomial(const Polynomial& other)
	{
		*this = other;
	}

	/* �������� ����������� = */
	const Polynomial& Polynomial::operator=(const Polynomial& other)
	{
		if (debug)
		{
			cout << "Copy constructor 'Polynomial': " << this->id << " <= " << other.id << endl;
		}

		if (this == &other)
		{
			return *this;
		}

		if (this->deg != other.deg)
		{
			this->MakeNull();
			this->deg = other.deg;
			this->mass = new double[this->deg + 1];
		}

		copy(other.mass, other.mass + other.deg + 1, this->mass);

		return *this;
	}

	/* ����������� ����������� */
	Polynomial::Polynomial(Polynomial&& other) noexcept : Polynomial() {
		*this = move(other);
	}

	/* �������� ����������� */
	Polynomial& Polynomial::operator=(Polynomial&& other) noexcept
	{
		if (debug)
		{
			cout << "Copy constructor 'Polynomial': " << this->id << " <= " << other.id << endl;
		}

		if (this == &other)
		{
			return *this;
		}

		this->MakeNull();

		swap(this->mass, other.mass);
		swap(this->deg, other.deg);

		return *this;
	}

	/* ���������� */
	Polynomial::~Polynomial()
	{
		this->MakeNull();

		if (debug)
		{
			cout << "Destructor 'Polynomial' with ID: " << this->id << endl;
		}
	}

	/* ���������� �������� �������� */
	Polynomial& Polynomial::operator+=(const Polynomial& other)
	{
		if (this->deg > other.deg)
		{
			for (size_t i = 0; i < other.deg + 1; i++)
			{
				this->mass[i] += other.mass[i];
			}
		}
		else 
		{
			Polynomial result(other.deg);

			for (size_t i = 0; i < other.deg + 1; i++)
			{
				result.mass[i] = this->mass[i] + other.mass[i];
			}

			*this = move(result);
		}

		this->Correct();

		return *this;
	}
	Polynomial Polynomial::operator+(const Polynomial& other)
	{
		return Polynomial(*this) += other;
	}

	/* ���������� �������� ��������� */
	Polynomial& Polynomial::operator-=(const Polynomial& other)
	{
		if (this->deg > other.deg)
		{
			for (size_t i = 0; i < other.deg + 1; i++)
			{
				this->mass[i] -= other.mass[i];
			}
		}
		else
		{
			Polynomial result(other.deg);

			for (size_t i = 0; i < other.deg + 1; i++)
			{
				result.mass[i] = this->mass[i] - other.mass[i];
			}

			*this = move(result);
		}

		this->Correct();

		return *this;
	}
	Polynomial Polynomial::operator-(const Polynomial& other)
	{
		return Polynomial(*this) -= other;
	}

	/* ���������� �������� ��������� */
	Polynomial& Polynomial::operator*=(const Polynomial& other)
	{
		Polynomial result(this->deg + other.deg);

		for (size_t i = 0; i < this->deg + 1; i++)
		{
			for (size_t j = 0; j < other.deg + 1; j++)
			{
				result.mass[i + j] += this->mass[i] * other.mass[j];
			}
		}

		this->Correct();

		*this = move(result);

		return *this;
	}
	Polynomial Polynomial::operator*(const Polynomial& other)
	{
		return Polynomial(*this) *= other;
	}

	/* ���������� �������� ��������� �� ����� */
	Polynomial& Polynomial::operator*=(double k)
	{
		for (size_t i = 0; i < this->deg + 1; i++)
		{
			this->mass[i] *= k;
		}

		this->Correct();

		return *this;
	}
	Polynomial Polynomial::operator*(double k)
	{
		return Polynomial(*this) *= k;
	}

	/* ���������� �������� ������� */
	Polynomial Polynomial::operator/(const Polynomial& other)
	{
		Polynomial tmp = *this;

		int rdeg = tmp.deg - other.deg + 1;

		Polynomial res(rdeg);

		for (size_t i = 0; i < rdeg; i++)
		{
			res.mass[rdeg - i - 1] = tmp.mass[tmp.deg - i - 1] / other.mass[other.deg - 1];

			for (int j = 0; j < other.deg; j++)
			{
				tmp.mass[tmp.deg - j - i - 1] -= other.mass[other.deg - j - 1] * res.mass[rdeg - i - 1];
			}
		}

		this->Correct();

		if (tmp.deg != 0) {
			cout << "!!! ������� ������� �� ������� " << tmp << endl;
		}

		return res;
	}

	/* ���������� ��������� () */
	double Polynomial::operator()(int x) const
	{
		int result = this->mass[0];

		for (size_t i = 1; i < this->deg + 1; i++)
		{
			result += this->mass[i] * pow(x, i);
		}

		return result;
	}

	/* �������� ������� */
	void Polynomial::MakeNull()
	{
		if (this->mass == nullptr)
		{
			delete[] this->mass;
			this->mass = nullptr;
		}

		this->deg = 0;

		return;
	}

	/* ������������� ������� �������� */
	Polynomial& Polynomial::Correct() {
		if (this->mass[this->deg] == 0) {
			do {
				this->deg--;
			} while (this->deg && this->mass[this->deg] == 0);
		}

		return *this;
	}

	/* ���������� ��������� ������ */
	ostream& operator<< (ostream& out, const Polynomial& polynomial)
	{
		out << polynomial.mass[0];

		for (size_t i = 1; i < polynomial.deg + 1; i++)
		{
			if (polynomial.mass[i] < 0)
			{
				out << " + (" << polynomial.mass[i] << "x^" << i << ")";
			}
			else
			{
				out << " + " << polynomial.mass[i] << "x^" << i;
			}
		}
		out << endl;

		return out;
	}

	/* ������� */
	size_t Polynomial::GetId() const
	{
		return this->id;
	}
	size_t Polynomial::GetDeg() const
	{
		return this->deg;
	}
	int Polynomial::GetValue(size_t _deg) const
	{
		if (_deg > this->deg || _deg < 0)
		{
			return -1;
		}

		return this->mass[_deg];
	}
}
