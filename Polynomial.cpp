#include <iostream>

#include "Polynomial.h"

using namespace std;

namespace polynomial
{
	size_t Polynomial::_id = 0;
	bool Polynomial::debug = false;

	/* ����������� */
	Polynomial::Polynomial(size_t _deg, double* _mass) : id(++_id), deg(_deg), length(++_deg)
	{
		this->mass = nullptr;

		if (this->deg != 0)
		{
			this->mass = new double[this->length]();
		}

		if (_mass != nullptr)
		{
			copy(_mass, _mass + this->length, this->mass);
		}

		if (debug)
		{
			cout << "Constructor 'Polynomial' with ID: " << this->id << endl;
		}
	}

	/* �����������, ����������� ���������������� ������� */
	Polynomial::Polynomial(size_t _deg, double(*func)(size_t)) : Polynomial(_deg) {
		for (size_t i = 0; i < this->length; i++)
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
			this->length = other.length;
			this->mass = new double[this->length];
		}

		copy(other.mass, other.mass + other.length, this->mass);

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
		swap(this->length, other.length);

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
			for (size_t i = 0; i < other.length; i++)
			{
				this->mass[i] += other.mass[i];
			}
		}
		else 
		{
			Polynomial result(other.deg);

			for (size_t i = 0; i < other.length; i++)
			{
				result.mass[i] = this->mass[i] + other.mass[i];
			}

			*this = move(result);
		}

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
			for (size_t i = 0; i < other.length; i++)
			{
				this->mass[i] -= other.mass[i];
			}
		}
		else
		{
			Polynomial result(other.deg);

			for (size_t i = 0; i < other.length; i++)
			{
				result.mass[i] = this->mass[i] - other.mass[i];
			}

			*this = move(result);
		}

		return *this;
	}
	Polynomial Polynomial::operator-(const Polynomial& other)
	{
		return Polynomial(*this) -= other;
	}

	/* ���������� �������� ��������� */
	Polynomial& Polynomial::operator*=(const Polynomial& other)
	{
		Polynomial result(this->deg * other.deg);

		for (size_t i = 0; i < this->length; i++)
		{
			for (size_t j = 0; j < other.length; j++)
			{
				result.mass[i + j] = this->mass[i] * other.mass[j];
			}
		}

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
		for (size_t i = 0; i < this->length; i++)
		{
			this->mass[i] *= k;
		}

		return *this;
	}
	Polynomial Polynomial::operator*(double k)
	{
		return Polynomial(*this) *= k;
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

	/* ���������� ��������� ������ */
	ostream& operator<< (ostream& out, const Polynomial& polynomial)
	{
		out << polynomial.mass[0];

		for (size_t i = 1; i < polynomial.length; i++)
		{
			out << " + " << polynomial.mass[i] << "x^" << i;
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
}
