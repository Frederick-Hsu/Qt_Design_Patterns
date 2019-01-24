/**************************************************************************************************
 * File name    : structure.h
 * Description  : Define a structure of Fraction.
 * Creator      : Frederick Hsu
 * Creation date: Mon.  21 Jan. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#ifndef STRUCTURE_H
#define STRUCTURE_H

    #include <string>

    using namespace std;

    typedef struct Fraction_t
    {
        int numer;
        int denom;
        string description;
    }
    Fraction_t,     *PtrFraction_t;

    void printFraction(Fraction_t f);

#endif  /* STRUCTURE_H */
