#ifndef FRACTION_H
#define FRACTION_H

namespace fraction
{
	class Fraction
	{
	private:
		size_t static _id;
		bool static debug;

		int numenator, deminator;
		size_t id;
	public:
		/* Конструкторы и деструктор */
		Fraction(int _numenator = 0, int _deminator = 1);
		Fraction(const Fraction& other);
		~Fraction();

		/* Перегрузка оператора копирования */
		const Fraction& operator=(const Fraction& other);

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

		/* Перегрузка оператора вывода в поток */
		friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);

		/* Функция преобразования неправильной дроби */
		void ShowCorrectFraction() const;

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

		/* Сеттеры */
		Fraction& SetNumerator(int _numenator);
		Fraction& SetDenominator(int _deminator);
		Fraction& Set(int _numenator, int _deminator);
	};
}

#endif FRACTION_H

