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

		/* ��������� ������ ������������ */
		Polynomial& Correct();
	public:
		/* ������������ � ���������� */
		Polynomial(size_t _deg = 0, double* _mass = nullptr);
		Polynomial(const Polynomial& other);
		Polynomial(size_t _deg, double(*func)(size_t));
		Polynomial(Polynomial&& other) noexcept;
		~Polynomial();

		/* ���������� ��������� ����������� */
		const Polynomial& operator=(const Polynomial& other);
		Polynomial& operator=(Polynomial&& other) noexcept;

		/* ���������� �������� �������� */
		Polynomial& operator+=(const Polynomial& other);
		Polynomial operator+(const Polynomial& other);

		/* ���������� �������� ��������� */
		Polynomial& operator-=(const Polynomial& other);
		Polynomial operator-(const Polynomial& other);

		/* ���������� �������� ��������� */
		Polynomial& operator*=(const Polynomial& other);
		Polynomial operator*(const Polynomial& other);

		/* ���������� �������� ��������� �� ����� */
		Polynomial& operator*=(double k);
		Polynomial operator*(double k);

		/* ���������� �������� ������� */
		Polynomial operator/(const Polynomial& other);

		/* ���������� ��������� () */
		double operator()(int x) const;

		/* �������� ������� */
		void MakeNull();

		/* ���������� ��������� ������ */
		friend std::ostream& operator<< (std::ostream& out, const Polynomial& polynomial);

		/* ������� */
		size_t GetId() const;
		size_t GetDeg() const;
		int GetValue(size_t deg) const;
	};
}

#endif POLYNOMIAL_H

