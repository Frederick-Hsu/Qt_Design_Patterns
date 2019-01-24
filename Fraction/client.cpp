/**************************************************************************************************
 * File name    : client.cpp
 * Description  : Implement the test cases here.
 * Creator      : Frederick Hsu
 * Creation date: Thu.  24 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include "client.h"
#include "structure.h"
#include "fraction.h"
#include "Complex.h"

#include <QTextStream>
#include <iostream>

void accessStruture(void)
{
    Fraction_t f1;
    f1.numer = 4;
    f1.denom = 5;
    f1.description = "four fifths";

    Fraction_t f2 = {2, 3, "two thirds"};

    printFraction(f1);
    f1.numer = f2.numer + 8;
    printFraction(f1);
    printFraction(f2);
}

void accessClassFraction(void)
{
    QTextStream cout(stdout);
    const int DASHES = 30;

    {
        int i;
        for (i = 0; i < DASHES; ++i)
        {
            cout << "=";
        }
        cout << endl;
    }

    // cout << "i = " << i << endl;
    Fraction f1, f2;
    f1.set(3, 4);
    f2.set(11, 12);
    // f2.m_Numerator = 12;
    cout << "The first fraction is : " << f1.toString() << endl;
    cout << "\nThe second fraction, expressed as double is : " << f2.toDouble() << endl;
}

void manipulateComplex(void)
{
    Complex C1;
    Complex C2(3.14);
    Complex C3(6.24, 10.98);
    std::cout << C1.toString() << "\t" << C2.toString() << "\t" << C3.toString() << std::endl;
}
