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
		/* ������������ � ���������� */
		Fraction(int _numenator = 0, int _deminator = 1);
		Fraction(const Fraction& other);
		~Fraction();

		/* ���������� ��������� ����������� */
		const Fraction& operator=(const Fraction& other);

		/* ���������� �������� ��������� ����� �� ����� ����� */
		Fraction& operator*=(int multiplier);
		Fraction operator*(int multiplier);

		/* ���������� �������� ������� ����� �� ����� ����� */
		Fraction& operator/=(int divider);
		Fraction operator/(int divider);

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

		/* ���������� ��������� ������ � ����� */
		friend std::ostream& operator<< (std::ostream& out, const Fraction& fraction);

		/* ������� �������������� ������������ ����� */
		void ShowCorrectFraction() const;

		/* ������� ������ ����� ��������� */
		int FindMaxDivider(int n, int m) const;
		
		/* ������� ��� ������ ����������� */
		int FindMinMultiple(int n, int m) const;

		/* ���������� ����� */
		Fraction& Reduction();

		/* ������� */
		int GetNumerator() const;
		int GetDenominator() const;
		int GetId() const;

		/* ������� */
		Fraction& SetNumerator(int _numenator);
		Fraction& SetDenominator(int _deminator);
		Fraction& Set(int _numenator, int _deminator);
	};
}

#endif FRACTION_H

