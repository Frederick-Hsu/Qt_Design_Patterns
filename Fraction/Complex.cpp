/**************************************************************************************************
 * File name    : Complex.cpp
 * Description  : Implement the class Complex
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include "Complex.h"
#include <iostream>
#include <sstream>

Complex::Complex(double realPart, double imagPart) : m_Real(realPart), m_Imag(imagPart)
{
    cout << "Complex(" << m_Real << ", " << m_Imag << ")" << endl;
}

Complex::Complex(double realPart) : m_Real(realPart), m_Imag(0)
{
}

Complex::Complex() : m_Real(0.0), m_Imag(0.0)
{
}

string Complex::toString() const
{
    ostringstream strbuf;
    strbuf << "(" << m_Real << ", " << m_Imag << ")";
    return strbuf.str();
}
