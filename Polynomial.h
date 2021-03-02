#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

namespace polynomial
{
	class Polynomial
	{
	private:
		size_t static _id;
		bool static debug;

		size_t id, deg;
		double* mass;

	public:
		/* Конструкторы и деструктор */
		Polynomial(size_t _deg = 0, double* _mass = nullptr);
		Polynomial(const Polynomial& other);
		Polynomial(size_t _deg, double(*func)(size_t));
		Polynomial(Polynomial&& other);
		~Polynomial();

		/* Перегрузка оператора копирования */
		const Polynomial& operator=(const Polynomial& other);
		Polynomial& operator=(Polynomial&& other);

		/* Перегрузка операции сложения */
		Polynomial& operator+=(const Polynomial& other);
		Polynomial operator+(const Polynomial& other);

		/* Перегрузка операции вычитания */
		Polynomial& operator-=(const Polynomial& other);
		Polynomial operator-(const Polynomial& other);

		/* Перегрузка операции вычитания */
		Polynomial& operator*=(const Polynomial& other);
		Polynomial operator*(const Polynomial& other);

		/* Перегрузка операции умножения на число */
		Polynomial& operator*=(double k);
		Polynomial operator*(double k);

		/* Очистить полином */
		void MakeNull();

		/* Перегрузка оператора вывода */
		friend std::ostream& operator<< (std::ostream& out, const Polynomial& polynomial);

		/* Геттеры */
		size_t GetId() const;
		size_t GetDeg() const;
	};
}

#endif POLYNOMIAL_H

