/**************************************************************************************************
 * File name    : fraction.cpp
 * Description  : Implement the class Fraction
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include "fraction.h"
#include <QString>
#include <QTextStream>

int Fraction::s_assigns = 0;
int Fraction::s_copies = 0;
int Fraction::s_constructors = 0;
int Fraction::s_destructors = 0;

Fraction::Fraction() : m_Numerator(0),
                       m_Denominator(1)     /* denominator cannot be allowed to set 0. */
{
    ++s_constructors;
}

Fraction::Fraction(int numerator) : m_Numerator(numerator), m_Denominator(1)
{
    ++s_constructors;
}

Fraction::Fraction(int numerator, int denominator) : m_Numerator(numerator),
                                                     m_Denominator(denominator)
{
    if (denominator == 0)
    {
        m_Denominator = 1;
    }
    ++s_constructors;
}

Fraction::~Fraction()
{
    --s_destructors;
}

Fraction::Fraction(const Fraction& other) : m_Numerator(other.m_Numerator),
                                            m_Denominator(other.m_Denominator)
{
    ++s_copies;
}

Fraction& Fraction::operator=(const Fraction &other)
{
    if (this != &other)
    {
        m_Numerator = other.m_Numerator;
        m_Denominator = other.m_Denominator;
        ++s_assigns;
    }
    return *this;
}

#if defined (NON_CONST_ARGUMENT)
    Fraction Fraction::add(Fraction fract)
    {
        int numerator, denominator;
        numerator = m_Numerator * fract.m_Denominator + m_Denominator * fract.m_Numerator;
        denominator = m_Denominator * fract.m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::subtract(Fraction fract)
    {
        int numerator, denominator;
        numerator = m_Numerator * fract.m_Denominator - m_Denominator * fract.m_Numerator;
        denominator = m_Denominator * fract.m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::multiply(Fraction fract)
    {
        int numerator, denominator;
        numerator = m_Numerator * fract.m_Numerator;
        denominator = m_Denominator * fract.m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::times(const Fraction &fract)
    {
        int numerator, denominator;
        numerator = m_Numerator * fract.m_Numerator;
        denominator = m_Denominator * m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::divide(Fraction fract)
    {
        int numerator, denominator;
        numerator = m_Numerator * fract.m_Denominator;
        denominator = m_Denominator * fract.m_Numerator;
        return Fraction(numerator, denominator);
    }
#else
    Fraction Fraction::add(const Fraction& other)
    {
        int numerator, denominator;
        numerator = m_Numerator * other.m_Denominator + m_Denominator * other.m_Numerator;
        denominator = m_Denominator * other.m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::subtract(const Fraction& other)
    {
        int numerator, denominator;
        numerator = m_Numerator * other.m_Denominator - m_Denominator * other.m_Numerator;
        denominator = m_Denominator * other.m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::multiply(const Fraction& other)
    {
        int numerator, denominator;
        numerator = m_Numerator * other.m_Numerator;
        denominator = m_Denominator * other.m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::divide(const Fraction& other)
    {
        int numerator, denominator;
        numerator = m_Numerator * other.m_Denominator;
        denominator = m_Denominator * other.m_Numerator;
        return Fraction(numerator, denominator);
    }

    Fraction Fraction::times(const Fraction& other)
    {
        int numerator, denominator;
        numerator = m_Numerator * other.m_Numerator;
        denominator = m_Denominator * other.m_Denominator;
        return Fraction(numerator, denominator);
    }

    Fraction& Fraction::operator+(const Fraction& frac)
    {
        m_Numerator = m_Numerator * frac.m_Denominator + m_Denominator * frac.m_Denominator;
        m_Denominator = m_Denominator * frac.m_Denominator;
        return *this;
    }

    Fraction& Fraction::operator+(int num)
    {
        m_Numerator = m_Numerator + num * m_Denominator;
        return *this;
    }

    Fraction& Fraction::operator-(const Fraction& frac)
    {
        m_Numerator = m_Numerator * frac.m_Denominator - m_Denominator * frac.m_Numerator;
        m_Denominator = m_Denominator * frac.m_Denominator;
        return *this;
    }

    Fraction& Fraction::operator-(int num)
    {
        m_Numerator = m_Numerator - m_Denominator * num;
        return *this;
    }

    Fraction& Fraction::operator*(const Fraction& frac)
    {
        m_Numerator = m_Numerator * frac.m_Numerator;
        m_Denominator = m_Denominator * frac.m_Denominator;
        return *this;
    }

    Fraction& Fraction::operator*(int num)
    {
        m_Numerator *= num;
        return *this;
    }

    Fraction& Fraction::operator/(const Fraction& frac)
    {
        m_Numerator = m_Numerator * frac.m_Denominator;
        m_Denominator = m_Denominator * frac.m_Numerator;
        return *this;
    }

    Fraction& Fraction::operator/(int num)
    {
        m_Denominator = m_Denominator * num;
        return *this;
    }

    bool Fraction::operator>=(const Fraction& frac)
    {
        int numerator = m_Numerator * frac.m_Denominator - m_Denominator * frac.m_Numerator;
        int denominator = m_Denominator * frac.m_Denominator;
        double value = (numerator * 1.00) / (denominator * 1.00);
        if (value >= 0.00)
            return true;
        else
            return false;
    }

    bool Fraction::operator<(const Fraction& frac)
    {
        int numerator = m_Numerator * frac.m_Denominator - m_Denominator * frac.m_Numerator;
        int denominator = m_Denominator * frac.m_Denominator;
        double value = (numerator * 1.00) / (denominator * 1.00);
        if (value < 0.00)
            return true;
        else
            return false;
    }
#endif

void Fraction::set(int numerator, int denominator)
{
    m_Numerator = numerator;
    if (denominator == 0)
    {
        m_Denominator = 1;
    }
    else
    {
        m_Denominator = denominator;
    }
}

double Fraction::toDouble() const
{
    return (1.0 * m_Numerator / m_Denominator);
}

QString Fraction::toString() const
{
    return QString("%1/%2").arg(m_Numerator).arg(m_Denominator);
}

QString Fraction::report()
{
    return QString("[assigns : %1,    copies : %2    constructors : %3    destructors : %4]").arg(s_assigns)
                                                                                             .arg(s_copies)
                                                                                             .arg(s_constructors)
                                                                                             .arg(s_destructors);
}

Fraction operator+(const Fraction& frac1, const Fraction& frac2)
{
    int numerator = frac1.m_Numerator * frac2.m_Denominator + frac1.m_Denominator * frac2.m_Numerator;
    int denominator = frac1.m_Denominator * frac2.m_Denominator;
    return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2)
{
    int numerator = frac1.m_Numerator * frac2.m_Denominator - frac1.m_Denominator * frac2.m_Numerator;
    int denominator = frac1.m_Denominator * frac2.m_Denominator;
    return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
    int numerator = frac1.m_Numerator * frac2.m_Numerator;
    int denominator = frac1.m_Denominator * frac2.m_Denominator;
    return Fraction(numerator, denominator);
}

Fraction operator/(const Fraction& frac1, const Fraction& frac2)
{
    int numerator = frac1.m_Numerator * frac2.m_Denominator;
    int denominator = frac1.m_Denominator * frac2.m_Numerator;
    return Fraction(numerator, denominator);
}

Fraction operator+(const Fraction& frac, int num)
{
    int numerator = frac.m_Numerator + num * frac.m_Denominator;
    int denominator = frac.m_Denominator;
    return Fraction(numerator, denominator);
}

Fraction operator+(int num, const Fraction& frac)
{
    return (frac + num);
}

Fraction operator-(const Fraction& frac, int num)
{
    int numerator = frac.m_Numerator - num * frac.m_Denominator;
    int denominator = frac.m_Denominator;
    return Fraction(numerator, denominator);
}

Fraction operator-(int num, const Fraction& frac)
{
    int numerator = num * frac.m_Denominator - frac.m_Numerator;
    int denominator = frac.m_Denominator;
    return Fraction(numerator, denominator);
}

Fraction operator*(const Fraction& frac, int num)
{
    int numerator = frac.m_Numerator * num;
    int denominator = frac.m_Denominator;
    return Fraction(numerator, denominator);
}

Fraction operator*(int num, const Fraction& frac)
{
    return (frac * num);
}

Fraction operator/(const Fraction& frac, int num)
{
    int numerator = frac.m_Numerator;
    int denominator = frac.m_Denominator * num;
    return Fraction(numerator, denominator);
}

Fraction operator/(int num, const Fraction& frac)
{
    int numerator = num * frac.m_Denominator;
    int denominator = frac.m_Numerator;
    return Fraction(numerator, denominator);
}

bool operator>=(const Fraction& frac1, const Fraction& frac2)
{
    int numerator = frac1.m_Numerator * frac2.m_Denominator - frac1.m_Denominator * frac2.m_Numerator;
    int denominator = frac1.m_Denominator * frac2.m_Denominator;

    double value = (numerator * 1.00) / (denominator * 1.00);
    if  (value >= 0.00)
        return true;
    else
        return false;
}

bool operator<(const Fraction& frac1, const Fraction& frac2)
{
    return (!(frac1 >= frac2));
}

void verifyHowCopyAssignContructorWork(void)
{
    QTextStream cout(stdout);

    Fraction twoThirds(2, 3);
    Fraction threeQuarters(3, 4);
    Fraction acopy(twoThirds);
    Fraction assign = threeQuarters;

    cout << "after declarations - " << Fraction::report() << endl;
    assign = twoThirds;
    cout << "\nbefore multiply - " << Fraction::report() << endl;
    assign = twoThirds.multiply(threeQuarters);
    cout << "\nafter multiply - " << Fraction::report() << endl;
}

void verifyHowConversionConstructorWorks(void)
{
    QTextStream qout(stdout);
    Fraction frac(8);
    Fraction frac2 = 5;
    frac = 9;
    frac = (Fraction)7;
    frac = Fraction(6);
    frac = static_cast<Fraction>(6);
    frac = frac2.times(19);
    qout << Fraction::report() << endl;
}
