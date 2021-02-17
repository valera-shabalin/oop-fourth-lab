#include <iostream>

#include "Fraction.h"

using namespace std;
using namespace fraction;

int main()
{
    setlocale(LC_CTYPE, "Rus");

    Fraction f1(1, 1);

    cout << f1 << endl;

    return 0;
}
