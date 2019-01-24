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
        Fraction();     /* no argument constructor */
        /* explicit */ Fraction(int numerator);        /* conversion constructor */
        Fraction(int numerator, int denominator);   /* normal full arguments constructor */
        Fraction(const Fraction& other);            /* copy constructor */
        ~Fraction();        /* destructor */
        Fraction& operator=(const Fraction& other);     /* copy assignment constructor */

        Fraction add(Fraction fract);
        Fraction subtract(Fraction fract);
        Fraction multiply(Fraction fract);
        Fraction times(const Fraction& fract);
        Fraction divide(Fraction fract);
        static QString report();
    public:
        void set(int numerator, int denominator);
        double toDouble() const;
        QString toString() const;
    private:
        int m_Numerator;
        int m_Denominator;

        static int s_assigns;
        static int s_copies;
        static int s_constructors;
        static int s_destructors;
    };

    void verifyHowCopyAssignContructorWork(void);
    void verifyHowConversionConstructorWorks(void);

#endif  /* FRACTION_H */
