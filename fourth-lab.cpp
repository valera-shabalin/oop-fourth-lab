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



    return 0;
}
