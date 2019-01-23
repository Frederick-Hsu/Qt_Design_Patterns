/**************************************************************************************************
 * File name    : fraction.h
 * Description  : Define the class Fraction
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef FRACTION_H
#define FRACTION_H

    class QString;

    class Fraction
    {
    public:
        void set(int numerator, int denominator);
        double toDouble() const;
        QString toString() const;
    private:
        int m_Numerator;
        int m_Denominator;
    };

#endif  /* FRACTION_H */
