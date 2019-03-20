#include "inline_test.h"

void inlineTest(void)
{
    cout << "Comparing inline and #define\n" << endl;
    double t = 30.0;
    int i = 8, j = 8, k = 8, n = 8;
    cout << "BADSQR(t+8) = " << BADSQR(t+8) << "\n"
         << "square(t+8) = " << square(t+8) << "\n"
         << "BADCUBE(++i) = " << BADCUBE(++i) << "\n"
         << "i = " << i << "\n"
         << "cube(++j) = " << cube<int>(++j) << "\n"
         << "j = " << j << "\n"
         << "BADABS(++k) = " << BADABS(++k) << "\n"
         << "k = " << k << "\n"
         << "abs(++n) = " << abs<int>(++n) << "\n"
         << "n = " << n << endl;
}
