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
		/* ������������ � ���������� */
		Fraction(int x = 0, int y = 0);
		Fraction(const Fraction& other);
		~Fraction();

		/* ���������� �������� ��������� ����� �� ����� ����� */
		Fraction& operator*=(int multiplier);
		Fraction operator*(int multiplier);

		/* ���������� �������� ��������� */
		Fraction& operator*=(const Fraction& other);
		Fraction operator*(const Fraction& other);

		/* ���������� �������� ������� */
		Fraction& operator/=(const Fraction& other);
		Fraction operator/(const Fraction& other);

		/* ���������� �������� �������� */
		Fraction& operator+=(const Fraction& other);
		Fraction operator+(const Fraction& other);

		/* ���������� �������� ��������� */
		Fraction& operator-=(const Fraction& other);
		Fraction operator-(const Fraction& other);

		/* ���������� ���������� ����������� � ����������� */
		const Fraction& operator=(const Fraction& other);

		/* ���������� ��������� ������ � ����� */
		friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);

		/* ������� ������ ����� ��������� */
		int FindMaxDivider(int n, int m) const;
		
		/* ������� ��� ������ ����������� */
		int FindMinMultiple(int n, int m) const;

		/* ���������� ����� */
		Fraction& Reduction();

		/* ������� */
		int GetNumerator() const;
		int GetDenominator() const;
	};
}

#endif FRACTION_H

