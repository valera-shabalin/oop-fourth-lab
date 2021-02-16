#include <iostream>

#include "Fraction.h"

using namespace std;
using namespace fraction;

int main()
{
    setlocale(LC_CTYPE, "Rus");

    Fraction f1(5, 10);
    Fraction f2(6, 5);
    Fraction summ = f1 - f2;

    cout << summ << endl;

    return 0;
}
