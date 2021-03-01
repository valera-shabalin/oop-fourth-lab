#include <iostream>

#include "Fraction.h"

using namespace std;
using namespace fraction;

int main()
{
    setlocale(LC_CTYPE, "Rus");

    Fraction x(-15, 3);
    Fraction y(12, 5);
    Fraction z = x + y;

    cout << "z = " << z;

    return 0;
}
