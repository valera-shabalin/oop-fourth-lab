#include <iostream>

#include "Polynomial.h"

using namespace std;

namespace polynomial
{
	size_t Polynomial::_id = 0;
	bool Polynomial::debug = false;

	/* Конструктор */
	Polynomial::Polynomial(size_t _deg, double* _mass) : id(++_id), deg(_deg)
	{
		this->mass = nullptr;

		if (this->deg != 0)
		{
			this->mass = new double[this->deg];
			for (size_t i = 0; i < this->deg; i++)
			{
				this->mass[i] = _mass[i];
			}
		}

		if (debug)
		{
			cout << "Constructor 'Polynomial' with ID: " << this->id << endl;
		}
	}

	/* Конструктор копирования */
	Polynomial::Polynomial(const Polynomial& other)
	{
		*this = other;
	}

	/* Оператор копирования = */
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

		this->ClearData();

		this->deg = other.deg;
		this->mass = new double[this->deg];

		for (size_t i = 0; i < this->deg; i++)
		{
			this->mass[i] = other.mass[i];
		}

		return *this;
	}

	/* Очистить полином */
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

	/* Деструктор */
	Polynomial::~Polynomial()
	{
		this->ClearData();

		if (debug)
		{
			cout << "Destructor 'Polynomial' with ID: " << this->id << endl;
		}
	}
}
