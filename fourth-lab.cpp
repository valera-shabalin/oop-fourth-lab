#include <iostream>

#include "Fraction.h"
#include "Polynomial.h"

using namespace std;
using namespace fraction;
using namespace polynomial;

int rand_int(int min, int max) {
    return min + rand() % (max - min);
}

double rand_double(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

int main()
{
    setlocale(LC_CTYPE, "Rus");

    auto func1 = [](size_t deg)->double { return rand_int(-10, 10); };
    auto func2 = [](size_t deg)->double { return rand_int(10, 20); };

    Polynomial x(2, func1), y(3, func2);
    Polynomial z = x * y;

    cout << x << "result(5) = " << x(5);

    return 0;
}
