/**************************************************************************************************
 * File name    : Complex.h
 * Description  : Define a new class Complex
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 * 
 **************************************************************************************************/


#ifndef COMPLEX_H
#define COMPLEX_H

    #include <string>

    using namespace std;

    class Complex
    {
    public:
        Complex(double realPart, double imagPart);
        Complex(double realPart);
        Complex();

        string toString() const;
    private:
        double m_Real;
        double m_Imag;
    };

#endif  /* COMPLEX_H */