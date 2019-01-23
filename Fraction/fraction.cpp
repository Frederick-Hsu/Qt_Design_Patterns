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

void Fraction::set(int numerator, int denominator)
{
    m_Numerator = numerator;
    m_Denominator = denominator;
}

double Fraction::toDouble() const
{
    return (1.0 * m_Numerator / m_Denominator);
}

QString Fraction::toString() const
{
    return QString("%1/%2").arg(m_Numerator).arg(m_Denominator);
}
