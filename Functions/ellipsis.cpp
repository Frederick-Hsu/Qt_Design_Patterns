#include "ellipsis.h"
#include <iostream>

double mean(int n...)
{
    va_list ap;
    double sum = 0.00;
    int count = n;

    va_start(ap, n);
    for (int i = 0; i < count; ++i)
    {
        sum += va_arg(ap, double);
    }
    va_end(ap);

    return (sum / count);
}

void testSum(void)
{
    int first = 1;
    int sumValue = sum<int>(5, first, 2, 3, 4, 5);
    cout << "The sum value of integer series is : " << sumValue << endl;

    double dFirst = 1.00;
    cout << "The sum value of double series is : "
         << sum<double>(8, dFirst, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0) << endl;
}
