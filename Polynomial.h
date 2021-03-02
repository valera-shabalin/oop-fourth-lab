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
		/* ������������ � ���������� */
		Polynomial(size_t _deg = 0, double* _mass = nullptr);
		Polynomial(const Polynomial& other);
		Polynomial(size_t _deg, double(*func)(size_t));
		~Polynomial();

		/* ���������� ��������� ����������� */
		const Polynomial& operator=(const Polynomial& other);

		/* �������� ������� */
		void MakeNull();

		/* ������� */
		size_t GetId() const;
		size_t GetDeg() const;
	};
}

#endif POLYNOMIAL_H

