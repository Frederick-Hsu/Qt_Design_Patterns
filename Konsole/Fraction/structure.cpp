/**************************************************************************************************
 * File name    : structure.cpp
 * Description  : Implement the structure of Fraction.
 * Creator      : Frederick Hsu
 * Creation date: Mon.  21 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include "structure.h"

#include <iostream>

void printFraction(Fraction_t f)
{
    cout << f.numer << "/" << f.denom << endl;
    cout << " = " << f.description << endl;
}
