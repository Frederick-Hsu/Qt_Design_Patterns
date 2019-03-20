#ifndef ELLIPSIS_H
#define ELLIPSIS_H

    #include <cstdarg>

    using namespace std;

    double mean(int n...);

    template<typename T>
    T sum(int n, const T& value1...)
    {
        T Gauss_sum = value1;
        va_list ap;
        va_start(ap, value1);
        for(int index = 1; index < n; ++index)
        {
            Gauss_sum += va_arg(ap, T);
        }
        va_end(ap);

        return Gauss_sum;
    }

    void testSum(void);

#endif  /* ELLIPSIS_H */
