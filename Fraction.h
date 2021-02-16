#ifndef FRACTION_H
#define FRACTION_H

namespace fraction
{
	class Fraction
	{
	private:
		size_t static _id;
		bool static debug;

		int x, y;
		size_t id;
	public:
		/* Конструкторы и деструктор */
		Fraction(int _x = 1, int _y = 1);
		Fraction(const Fraction& other);
		~Fraction();

		/* Перезрузка операции умножения дроби на целое число */
		Fraction& operator*=(int multiplier);
		Fraction operator*(int multiplier);

		/* Перезрузка операции деления дроби на целое число */
		Fraction& operator/=(int divider);
		Fraction operator/(int divider);

		/* Перегрузка операции умножения */
		Fraction& operator*=(const Fraction& other);
		Fraction operator*(const Fraction& other);

		/* Перегрузка операции деления */
		Fraction& operator/=(const Fraction& other);
		Fraction operator/(const Fraction& other);

		/* Перегрузка операции сложения */
		Fraction& operator+=(const Fraction& other);
		Fraction operator+(const Fraction& other);

		/* Перегрузка операции вычитания */
		Fraction& operator-=(const Fraction& other);
		Fraction operator-(const Fraction& other);

		/* Перегрузка операторов копирования и перемещения */
		const Fraction& operator=(const Fraction& other);

		/* Перегрузка оператора вывода в поток */
		friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);

		/* Функции поиска общих делителей */
		int FindMaxDivider(int n, int m) const;
		
		/* Функция для поиска знаменателя */
		int FindMinMultiple(int n, int m) const;

		/* Сокращение дроби */
		Fraction& Reduction();

		/* Геттеры */
		int GetNumerator() const;
		int GetDenominator() const;
		int GetId() const;
	};
}

#endif FRACTION_H

