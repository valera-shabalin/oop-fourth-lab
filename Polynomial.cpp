#include <iostream>

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
			this->mass = new double[this->deg]();
		}

		if (_mass != nullptr)
		{
			copy(_mass, _mass + _deg, this->mass);
		}

		if (debug)
		{
			cout << "Constructor 'Polynomial' with ID: " << this->id << endl;
		}
	}

	/* ����������� ����������� */
	Polynomial::Polynomial(const Polynomial& other)
	{
		*this = other;
	}

	/* �����������, ����������� ���������������� ������� */
	Polynomial::Polynomial(size_t _deg, double(*func)(size_t)) : Polynomial(_deg) {
		for (size_t i = 0; i < _deg; i++)
		{
			this->mass[i] = func(i);
		}		
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

		this->MakeNull();

		this->deg = other.deg;
		this->mass = new double[this->deg];

		for (size_t i = 0; i < this->deg; i++)
		{
			this->mass[i] = other.mass[i];
		}

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
