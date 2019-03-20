#ifndef INLINE_TEST_H
#define INLINE_TEST_H

    #include <iostream>

    #define BADABS(X)  (((X) > 0) ? (X) : -(X))
    #define BADSQR(X)   ( ((X)) * ((X)) )
    #define BADCUBE(X)  ( ((X)) * ((X)) * ((X)) )

    using namespace std;
    inline double square(double x)
    {
        return x * x;
    }

    template<typename T>
    inline T cube(T x)
    {
        return (x * x * x);
    }

    template<typename T> inline T abs(T n)
    {
        return ((n >= 0) ? n : -n);
    }

    void inlineTest(void);
#endif  /* INLINE_TEST_H */
